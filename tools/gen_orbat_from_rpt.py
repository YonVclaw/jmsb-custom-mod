"""Build work/orbat/<faction>.cpp from an in-game dump already in the RPT.

WHY THIS EXISTS. work/dump_orbat.sqf is the right tool and has not run
successfully yet. The 2026-08-22 17:42 RPT already holds everything needed -
every unit's weapons, magazines, linkedItems, uniformClass, backpack,
identityTypes, parent and display name; every group with its men, ranks and
formation positions; and every faction class with its icon, flag and priority -
so the configs can be built from what is on disk instead of another trip
through the game.

EACH FILE CARRIES ALL THREE ROOTS:

    class CfgFactionClasses { ... }   what the faction IS
    class CfgVehicles { ... }         the roster, and the kit each man carries
    class CfgGroups { ... }           how they are organised

work/blue.sqf is CfgVehicles alone, because that is all ORBAT Creator exports.
A faction is not just its roster.

WHAT IS NOT IN THE RESULT, stated plainly:

  ALiVE_orbatCreator_loadout - getUnitLoadout output: attachments split from
  weapons, magazine counts, what sits in which container. That is in no config
  anywhere, so it cannot be built from a config dump and is NOT invented here.
  Units still spawn with the right kit because weapons[]/magazines[]/
  linkedItems[] describe it; what is missing is ALiVE's exact-loadout restore.

  The per-vehicle `class Turrets : Turrets { ... gunnerType = ""; }` override.
  Turret names are nested classes and the property dump did not record them.
  A vehicle therefore keeps its own turrets, which is right for a straight
  dump - ORBAT Creator's crew-stripping is what is absent, not the guns.

    python tools/gen_orbat_from_rpt.py --rpt <file>
"""
import os, io, re, sys, glob, argparse, collections

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = os.path.join(ROOT, "work", "orbat")

STAMP = re.compile(r"^\s*\d{1,2}:\d{2}:\d{2}(?:\.\d+)?\s")
RE_UNIT = re.compile(r"^UNIT;([^;]+);([^;]*);([^;]*);(-?\d+);(-?\d+)$")
RE_PROP = re.compile(r"^([FUG])PROP;([^;]+);(own|inh);(num|txt|arr);([^;]*);([^;]+);(.*)$")
RE_GROUP = re.compile(r"^GROUP;(\d+);([^;]+);([^;]*);([^;]*);([^;]+?)(?:;(.*))?$")
RE_GMAN = re.compile(r"^GMAN;(\d+);(\d+);([^;]*);([^;]*?)(?:;(\[.*\]))?$")

# East, West, Independent, Civilian - every side that has factions
# (2026-08-30; civilians were excluded until then and never reached the
# per-faction files, though docs/FACTIONS_CIV.md is written from them).
WANT = (0, 1, 2, 3)

# CfgGroups also carries an "Empty" side holding building compositions - Altis
# Terminal and the like. That is not an order of battle.
GROUP_SIDES = ("west", "east", "indep", "guer", "guerrilla", "independent",
               "civ", "civilian")

# NOT UNITS. A dismantled static weapon is a backpack; a minefield is a mine.
SKIP_VCLASS = ("Backpacks", "Mines", "Structures_Military", "Structures_Walls",
               "Sounds", "Respawn", "Virtual", "Items", "Intel", "Training",
               "WeaponsSecondary", "WeaponsPrimary", "Cargo")

MANINIT = ("if (local (_this select 0)) then {_onSpawn = {_this = _this select 0;sleep 0.2; "
           "_backpack = gettext(configfile >> 'cfgvehicles' >> (typeof _this) >> 'backpack'); "
           "waituntil {sleep 0.2; backpack _this == _backpack};"
           "if !(_this getVariable ['ALiVE_OverrideLoadout',false]) then "
           "{_loadout = getArray(configFile >> 'CfgVehicles' >> (typeOf _this) >> "
           "'ALiVE_orbatCreator_loadout'); _this setunitloadout _loadout;reload _this};};"
           "_this spawn _onSpawn;(_this select 0) addMPEventHandler ['MPRespawn', _onSpawn];};")
VEHINIT = ("if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;};"
           "_this spawn _onSpawn;(_this select 0) addMPEventHandler ['MPRespawn', _onSpawn];};")


def is_man(vclass, pr):
    """A man is detected from what he has, not from a list of category names.

    A fixed vehicleClass whitelist missed MenTanoan, Afroamerican, European and
    Asian. Anything wearing a uniform or carrying an identity is a man.
    """
    if pr.get("uniformClass", (None, ""))[1]:
        return True
    if pr.get("identityTypes", (None, ""))[1] not in ("", "[]", None):
        return True
    return vclass.startswith("Men")


def newest_rpt():
    base = os.environ.get("LOCALAPPDATA")
    if not base:
        return None
    hits = glob.glob(os.path.join(base, "Arma 3", "Arma3_x64_*.rpt"))
    return max(hits, key=os.path.getmtime) if hits else None


def cfg_arr(v):
    """SQF `["a","b"]` -> config `{"a","b"}`; None if it will not convert."""
    v = (v or "").strip()
    if not v.startswith("["):
        return None
    depth = 0
    out = []
    for ch in v:
        if ch == "[":
            out.append("{")
            depth += 1
        elif ch == "]":
            out.append("}")
            depth -= 1
        else:
            out.append(ch)
    return "".join(out) if depth == 0 else None


def gmen_values(gmen, gid):
    """A group's men in slot order: (vehicle, rank, position)."""
    men = gmen.get(gid, {})
    return [men[i] for i in sorted(men, key=int)]


RE_WEAPON = re.compile(r"^WEAPON;([^;]+);([^;]*);(\d+);([^;]*);([^;]*);(.*)$")


def read_weapons(rpt):
    """class -> {parent, type, name, linked (muzzle item or ""), compat [...]}
    from the dump's WEAPON lines - {} for a dump made before the dump script
    logged weapons (tools/dump_orbat.sqf, 2026-08-28)."""
    out = {}
    with io.open(rpt, encoding="utf-8", errors="replace") as fh:
        for raw in fh:
            m = RE_WEAPON.match(STAMP.sub("", raw.rstrip("\r\n")))
            if m:
                cls, parent, typ, name, linked, compat = m.groups()
                out[cls] = {"parent": parent, "type": int(typ), "name": name, "linked": linked,
                            "compat": re.findall(r'"([^"]+)"', compat)}
    return out


def read(rpt):
    facside, facprops = {}, collections.defaultdict(dict)
    units, props = {}, collections.defaultdict(dict)
    groups, gprops = {}, collections.defaultdict(dict)
    gmen = collections.defaultdict(dict)

    with io.open(rpt, encoding="utf-8", errors="replace") as fh:
        for raw in fh:
            line = STAMP.sub("", raw.rstrip("\r\n"))

            m = RE_UNIT.match(line)
            if m:
                units[m.group(1)] = {"faction": m.group(2).lower(),
                                     "parent": m.group(3),
                                     "side": int(m.group(4)),
                                     "scope": int(m.group(5))}
                continue

            m = RE_GROUP.match(line)
            if m:
                gid, side, fac, cat, cls, name = m.groups()
                if side.lower() in GROUP_SIDES:
                    g = groups.setdefault(gid, {})
                    g.update({"side": side, "faction": fac, "cat": cat, "cls": cls})
                    if name:
                        g["name"] = name
                continue

            m = RE_GMAN.match(line)
            if m:
                gid, i, veh, rank, pos = m.groups()
                # TWO RUNS ARE IN THIS FILE and only the earlier one recorded
                # position. Never let the positionless run overwrite it.
                cur = gmen[gid].get(i)
                if cur is None or (pos and not cur[2]):
                    gmen[gid][i] = (veh, rank, pos or "")
                continue

            m = RE_PROP.match(line)
            if m:
                kind, key, _flag, typ, path, name, val = m.groups()
                if path:
                    continue
                if kind == "F":
                    facprops[key][name] = val
                    if name == "side":
                        try:
                            facside[key.lower()] = int(float(val))
                        except ValueError:
                            pass
                elif kind == "G":
                    gprops[key][name] = val
                else:
                    props[key][name] = (typ, val)

    return facside, facprops, units, props, groups, gprops, gmen


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--rpt")
    ap.add_argument("--out", default=OUT)
    args = ap.parse_args()

    rpt = args.rpt or newest_rpt()
    if not rpt or not os.path.exists(rpt):
        print("no RPT given and none found - pass --rpt <path>")
        return 2

    facside, facprops, units, props, groups, gprops, gmen = read(rpt)
    if not units:
        print("%s holds no UNIT records - wrong RPT?" % rpt)
        return 2

    fs = dict((k, v) for k, v in facside.items() if v in WANT)
    for c, u in units.items():
        f = u["faction"]
        if f and f != "default" and f not in fs and u["side"] in WANT:
            fs[f] = u["side"]

    by_fac = collections.defaultdict(list)
    for c, u in units.items():
        if u["faction"] in fs and u["scope"] == 2:
            by_fac[u["faction"]].append(c)
    # A faction can field groups without fielding a scope-2 unit of its own.
    for g in groups:
        f = groups[g].get("faction", "").lower()
        if f in fs:
            by_fac.setdefault(f, [])

    if not os.path.isdir(args.out):
        os.makedirs(args.out)

    print("read   %s" % rpt)
    print("       %d unit record(s), %d group(s), %d faction(s) on East/West/Ind/Civ"
          % (len(units), len(groups), len(fs)))

    nfile = nunit = ngrp = 0
    skipped = {}

    for fac in sorted(by_fac):
        clss = []
        for c in sorted(by_fac[fac]):
            vc = props.get(c, {}).get("vehicleClass", (None, ""))[1] or ""
            if vc in SKIP_VCLASS:
                skipped[vc] = skipped.get(vc, 0) + 1
                continue
            clss.append(c)

        mine = [g for g in groups if groups[g].get("faction", "").lower() == fac]
        if not clss and not mine:
            continue

        L = ["//" * 40 + "//",
             "// Faction config rebuilt by tools/gen_orbat_from_rpt.py",
             "// from an in-game dump. ALiVE_orbatCreator_loadout and the",
             "// per-vehicle Turrets override are absent - see that file's header.",
             "//" * 40 + "//", "", "",
             "class CBA_Extended_EventHandlers_base;", ""]

        # ---------------- CfgFactionClasses ----------------
        fname, fp = None, None
        for k in facprops:
            if k.lower() == fac:
                fname, fp = k, facprops[k]
                break
        if fp:
            L += ["class CfgFactionClasses {", "    class %s {" % fname]
            for n in ("displayName", "author"):
                if fp.get(n):
                    L.append('        %s = "%s";' % (n, fp[n]))
            for n in ("side", "priority"):
                if n in fp:
                    L.append("        %s = %s;" % (n, fp[n]))
            for n in ("icon", "flag"):
                if fp.get(n):
                    L.append('        %s = "%s";' % (n, fp[n]))
            L += ["    };", "};", ""]

        # ---------------- CfgVehicles ----------------
        if clss:
            L += ["class CfgVehicles {", ""]
            seen_par = []
            for c in clss:
                p = units[c]["parent"]
                if p and p not in seen_par:
                    seen_par.append(p)
            for p in seen_par:
                L += ["    class %s;" % p,
                      "    class %s_OCimport_01 : %s { scope = 0; class EventHandlers; };" % (p, p),
                      "    class %s_OCimport_02 : %s_OCimport_01 { class EventHandlers; };" % (p, p),
                      ""]

            for c in clss:
                u = units[c]
                pr = props.get(c, {})
                g = lambda n: pr.get(n, (None, None))[1]
                vclass = g("vehicleClass") or ""
                man = is_man(vclass, pr)

                L += ["    class %s : %s_OCimport_02 {" % (c, u["parent"]),
                      '        author = "YonV";',
                      "        scope = 2;",
                      "        scopeCurator = %s;" % (g("scopeCurator") or "2"),
                      '        displayName = "%s";' % (g("displayName") or c),
                      "        side = %d;" % u["side"],
                      '        faction = "%s";' % fac]
                if not man and g("crew"):
                    L.append('        crew = "%s";' % g("crew"))
                L.append("")

                if man:
                    idt = cfg_arr(g("identityTypes"))
                    if idt and idt != "{}":
                        L += ["        identityTypes[] = %s;" % idt, ""]
                    if g("uniformClass"):
                        L += ['        uniformClass = "%s";' % g("uniformClass"), ""]
                    if g("backpack"):
                        L += ['        backpack = "%s";' % g("backpack"), ""]
                    for a, b in (("linkedItems", "respawnlinkedItems"),
                                 ("weapons", "respawnWeapons"),
                                 ("magazines", "respawnMagazines")):
                        arr = cfg_arr(g(a))
                        if arr and arr != "{}":
                            L += ["        %s[] = %s;" % (a, arr),
                                  "        %s[] = %s;" % (b, arr), ""]
                    L.append("")

                L += ["        class EventHandlers : EventHandlers {",
                      "            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};",
                      "",
                      "            class ALiVE_orbatCreator {",
                      '                init = "%s";' % (MANINIT if man else VEHINIT),
                      "            };", "", "        };", "",
                      "        // custom attributes (do not delete)",
                      "        ALiVE_orbatCreator_owned = 1;", "",
                      "    };", ""]
                nunit += 1
            L.append("};")

        # ---------------- CfgGroups ----------------
        if mine:
            L.append("")
            tree = collections.defaultdict(lambda: collections.defaultdict(list))
            for g in mine:
                tree[groups[g]["side"]][groups[g]["cat"]].append(g)
            real_fac = groups[mine[0]]["faction"]

            L.append("class CfgGroups {")
            for side in sorted(tree):
                L += ["    class %s {" % side, "        class %s {" % real_fac]
                for cat in sorted(tree[side]):
                    L.append("            class %s {" % cat)
                    for g in sorted(tree[side][cat], key=lambda x: groups[x]["cls"]):
                        gp = gprops.get(g, {})
                        gname = groups[g].get("name") or gp.get("name", "")
                        L.append("                class %s {" % groups[g]["cls"])
                        if gname:
                            L.append('                    name = "%s";' % gname)
                        for n in ("side", "rarityGroup"):
                            if n in gp:
                                L.append("                    %s = %s;" % (n, gp[n]))
                        L.append('                    faction = "%s";' % real_fac)
                        if gp.get("icon"):
                            L.append('                    icon = "%s";' % gp["icon"])
                        men = gmen.get(g, {})
                        for i in sorted(men, key=int):
                            veh, rank, pos = men[i]
                            L += ["", "                    class Unit%s {" % i,
                                  '                        vehicle = "%s";' % veh]
                            if rank:
                                L.append('                        rank = "%s";' % rank)
                            L.append("                        position[] = %s;"
                                     % (cfg_arr(pos) or "{0,0,0}"))
                            L.append("                    };")
                        L.append("                };")
                    L.append("            };")
                L += ["        };", "    };"]
            L.append("};")
            ngrp += len(mine)

        text = "\n".join(L) + "\n"
        if text.count("{") != text.count("}"):
            print("  !! %s unbalanced braces - not written" % fac)
            continue
        io.open(os.path.join(args.out, fac + ".cpp"), "w",
                encoding="utf-8", newline="\r\n").write(text)
        nfile += 1

    print("wrote  %d faction file(s), %d unit(s), %d group(s) into %s"
          % (nfile, nunit, ngrp, args.out))
    if skipped:
        # SAID OUT LOUD. Silently dropping things is how a roster ends up short
        # and nobody knows which.
        print("       skipped (not units): %s" % ", ".join(
            "%s %d" % (k, v) for k, v in sorted(skipped.items(), key=lambda x: -x[1])))
    return 0


if __name__ == "__main__":
    sys.exit(main())
