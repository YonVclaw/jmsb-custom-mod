"""Turn a work/dump_factions.sqf RPT run into work/faction_dump.json.

THE STEP THAT NEVER EXISTED. Seven generators read work/factions.json and
nothing in this repo writes it; work/orbat_dump.sqf ends by telling you to run
`python work/extract_orbat.py`, which is not a file and never was. Both in-game
dumps wrote to the RPT and stopped there.

EAST, WEST AND INDEPENDENT ONLY, and no property dumps - the SQF does that
filtering, this reads what it wrote:

    FACTION;cls;side;displayName
    UNIT;cls;faction;side;scope;parent;vehicleClass;displayName
    GROUP;gid;side;faction;category;cls;name
    GMAN;gid;i;vehicle;rank
    FNOCLASS;faction

    python tools/extract_factions.py                  # newest RPT, default out
    python tools/extract_factions.py --rpt X.rpt
    python tools/extract_factions.py --out work/f.json
"""
import os, io, re, sys, json, glob, argparse

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = os.path.join(ROOT, "work", "faction_dump.json")

BEGIN = ">>>> FACTION DUMP BEGIN <<<<"
END = ">>>> FACTION DUMP END <<<<"

SIDE = {-1: "(no class)", 0: "East", 1: "West", 2: "Independent",
        3: "Civilian", 4: "Empty", 7: "Logic"}

# Arma stamps every RPT line with a wall clock. The markers are what we cut on,
# so the stamp has to come off first or nothing matches.
GROUP_SIDES = ("west", "east", "indep", "guer", "guerrilla", "independent")

STAMP = re.compile(r"^\s*\d{1,2}:\d{2}:\d{2}(?:\.\d+)?\s+")


def newest_rpt():
    """The most recently written Arma 3 RPT, or None."""
    base = os.environ.get("LOCALAPPDATA")
    if not base:
        return None
    hits = glob.glob(os.path.join(base, "Arma 3", "Arma3_x64_*.rpt"))
    if not hits:
        # A profile can be configured to write the plain-name log instead.
        hits = glob.glob(os.path.join(base, "Arma 3", "*.rpt"))
    return max(hits, key=os.path.getmtime) if hits else None


def num(tok):
    try:
        return int(float(tok))
    except ValueError:
        return -1


def parse(lines):
    factions, units, groups, noclass = {}, {}, {}, []

    for raw in lines:
        line = STAMP.sub("", raw.rstrip("\r\n"))

        if line.startswith("FACTION;"):
            # FACTION;cls;side;displayName
            p = line.split(";", 3)
            if len(p) < 4:
                continue
            factions[p[1]] = {
                "side": num(p[2]),
                "sideName": SIDE.get(num(p[2]), "?"),
                "name": p[3],
                "units": [],
                "groups": [],
            }

        elif line.startswith("UNIT;"):
            # UNIT;cls;faction;side;scope;parent;vehicleClass;displayName
            p = line.split(";", 7)
            if len(p) < 8:
                continue
            units[p[1]] = {
                "faction": p[2], "side": num(p[3]), "scope": num(p[4]),
                "parent": p[5], "vehicleClass": p[6], "name": p[7],
            }

        elif line.startswith("GROUP;"):
            # GROUP;gid;side;faction;category;cls;name
            p = line.split(";", 6)
            if len(p) < 7:
                continue
            # THE SAME ALLOWLIST THE SQF APPLIES, repeated here so a dump taken
            # before that fix still reads correctly. CfgGroups' "Empty" side is
            # building compositions, not order of battle.
            if p[2].lower() not in GROUP_SIDES:
                continue
            groups[p[1]] = {
                "side": p[2], "faction": p[3], "category": p[4],
                "cls": p[5], "name": p[6], "men": [],
            }

        elif line.startswith("GMAN;"):
            # GMAN;gid;i;vehicle;rank
            p = line.split(";", 4)
            if len(p) < 5:
                continue
            g = groups.get(p[1])
            if g is None:
                continue
            g["men"].append({"i": num(p[2]), "vehicle": p[3], "rank": p[4]})

        elif line.startswith("FNOCLASS;"):
            noclass.append(line.split(";", 1)[1])

    return factions, units, groups, noclass


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--rpt")
    ap.add_argument("--out", default=OUT)
    args = ap.parse_args()

    rpt = args.rpt or newest_rpt()
    if not rpt or not os.path.exists(rpt):
        print("no RPT found. Run work/dump_factions.sqf in the debug console")
        print("first, or pass --rpt <path>.")
        return 2

    text = io.open(rpt, encoding="utf-8", errors="replace").read()

    # THE LAST RUN, NOT THE FIRST. An RPT accumulates across sessions and the
    # dump is meant to be re-run; parsing from the top would hand back whatever
    # the config looked like several mod changes ago.
    if BEGIN not in text:
        print("%s holds no dump - looked for the BEGIN marker." % rpt)
        print("Paste work/dump_factions.sqf into the debug console and Exec.")
        return 2
    block = text[text.rfind(BEGIN):]
    if END in block:
        block = block[:block.find(END)]
    else:
        print("!! no END marker - the dump was cut short, parsing what is there")

    factions, units, groups, noclass = parse(block.splitlines())

    if not (factions or units or groups):
        print("!! markers present but nothing parsed - nothing written")
        return 1

    # CROSS-LINK, CASE-INSENSITIVELY. Config is case-insensitive and mods spell
    # a faction whichever way they like - EF_B_MJTF_Des in one file and
    # ef_b_mjtf_des in the next are the same faction, and matching on exact
    # case is how a roster comes back empty.
    low = dict((k.lower(), k) for k in factions)
    lost_u = lost_g = 0

    for cls, u in units.items():
        k = low.get(u["faction"].lower())
        if k:
            factions[k]["units"].append(cls)
        else:
            lost_u += 1

    for gid, g in groups.items():
        k = low.get(g["faction"].lower())
        if k:
            factions[k]["groups"].append(gid)
        else:
            lost_g += 1

    for f in factions.values():
        f["units"].sort()
        f["groups"].sort(key=lambda x: int(x) if x.isdigit() else 0)

    # A FACTION THAT FIELDS NOTHING IS NOT A FACTION. The 11 that showed up
    # with an empty roster existed only because CfgGroups' "Empty" side was
    # being read as order of battle; with that gone they field nothing at all.
    empty = [k for k, f in factions.items() if not f["units"] and not f["groups"]]
    for k in empty:
        del factions[k]
    noclass = [n for n in noclass if n in factions or n.lower() in
               dict((k.lower(), k) for k in factions)]

    io.open(args.out, "w", encoding="utf-8").write(json.dumps(
        {"factions": factions, "units": units, "groups": groups,
         "undeclared": noclass}, indent=1, sort_keys=True))

    print("read   %s" % rpt)
    print("wrote  %s" % args.out)
    print("       %d faction(s), %d unit(s), %d group(s)"
          % (len(factions), len(units), len(groups)))
    if empty:
        print("       %d faction(s) dropped - declared a class but field nothing"
              % len(empty))

    # THE SHAPE, SIDE BY SIDE. "96 factions" says nothing about whether the
    # Independent ones came through.
    by_side = {}
    for f in factions.values():
        by_side.setdefault(f["sideName"], []).append(f)
    for s in sorted(by_side):
        fl = by_side[s]
        print("       %-12s %3d faction(s)  %5d unit(s)  %4d group(s)"
              % (s, len(fl), sum(len(f["units"]) for f in fl),
                 sum(len(f["groups"]) for f in fl)))

    if noclass:
        print("       %d faction(s) field units or groups but declare no class"
              % len(noclass))
    # NOT SILENT. Anything that could not be linked is named, because a
    # silently empty roster is the failure this file exists to end.
    if lost_u or lost_g:
        print("       %d unit(s) and %d group(s) could not be linked to a faction"
              % (lost_u, lost_g))
    return 0


if __name__ == "__main__":
    sys.exit(main())
