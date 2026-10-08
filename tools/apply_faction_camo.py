#!/usr/bin/env python3
"""Paint the factions' vehicles, and hide the ones asked for, in place.

    python tools/apply_faction_camo.py [--dry-run] [--map work/faction_camo.json] [--only faction_china,...]

--only writes (and prunes) the addons named and leaves every other addon in the map untouched - the map keeps
every faction's rows from earlier runs, and a run for one faction must not repaint the rest (2026-09-18: China
alone, "vechicles only").

THE ASK (user, 2026-09-14): "i want the vechicles in the russia faction to have green camo, hide
artic, and sand for arid", "the green hex for the tropical iran and china arid hex for arid factions
of china and iran", "sand textures for turkey"; then "can you make textures ?", "the russion shades
of green and sand need to be darker than the nato versions", "and tyrkey needs ti use Ardistan", a
photo "an example of russion artic vechicle camo" and two images "example of the chinise camo's for
vechicles"; then a Turkish Leopard 2 photo "as an example of arid camo for turkey make sure a small logo
for the turkish miltary is on each vecnicle", Chinese arid, arctic and desert photos, "need russian and
chinise camo for thses D:\\work\\qav\\type" and "eu woodland should be the wdl camos from aegis/atlas. find
or make an artic vertion and deset versions". Read as:
    faction_russia                    Russian Green, made: NATO Olive's hue at 80% of its lightness
    faction_russia_arc                Russian Arctic, made after the photo - and shown again: its hide
                                      (scope 1, scopeCurator 0) was for want of an arctic camo
    faction_russia_ard                Russian Sand, made: NATO Sand's hue at 80% of its lightness
    faction_china (CSAT Pacific's)    Chinese Woodland Digital } every China vehicle's appearance menu offers
    faction_china_ard                 Chinese Desert Digital   } Woodland, Arid, Desert and Arctic; the QAV
                                                               } Type 08s the three Russian ones too
    faction_iran                      Hex, the arid one (Iran has no tropical faction: it is CSAT's)
    faction_turkey, faction_turkey_ind  Turkish Arid, made after the photo, a small Turkish flag on each
    faction_eudf, faction_eudf_wdl    Aegis's/Atlas's own wdl (woodland), else made in its colours
    faction_eudf_des, faction_eudf_arc  Atlas's own desert where it has one, else the wdl's pattern in desert
                                      or arctic colours, else made in them
    faction_eudf_tna                  the wdl's pattern in tropical greens: every EU faction patterned while the
                                      US factions keep the game's plain NATO paints ("make eu and us a bit differnt")
    every plane in these factions     its air force's two greys over a light sky-colour underside, the underside
                                      where the model's own faces point down ("by aircraft i mean planes")
    every made camo                   leaves the wheels in their own paint, the wheel faces found from the model's
                                      wheel selections ("don;t camo thew wheels"); Chinese Woodland's colours
                                      from a ZBD-04A photo, its fourth light brown ("the pink needs to be light
                                      brown not pink")

THE MAP (work/faction_camo.json): {"camo": {addon: {class: {"camo", "from", "entry", "textures",
"copy": [[source file, path under addons\\]], "made": [[source, path under addons\\]]}}}, "hide":
{addon: [class]}, "unhide": {addon: [class]}}. Built 2026-09-14 from the
camo pool - the base game, its expansions and A3_Aegis_Public_Releases - taking, per vehicle, a paint
scheme of that name it already has; for the two hexes what CSAT Pacific or CSAT wears on that model;
else a scheme of that name for its model from the pool. A vehicle whose model has none is not in it
and is left as it is.

HOW, the way gen_us_factions.py paints its factions: `textureList[] = {};` - without it the game's
BIS_fnc_initVehicle repaints a spawned vehicle from its parent's list - and
`hiddenSelectionsTextures[]`, under a `// camo:` line a re-run finds and replaces. A texture from
Aegis, Atlas or OpF (APL-SA, like jmfsb) is copied into the faction's own data\\camo folder. Made
textures (data\\camo\\made - recolours of the vehicle's plainest paint that keep its shading and
markings) are written when the map is built, not by this tool; Turkey's are made once in
faction_turkey and named from faction_turkey_ind too - a texture is found by its path, so that needs
no requiredAddons entry. Files under a faction's data\\camo that nothing names any more are removed.
"""
import argparse
import io
import json
import os
import re
import shutil

ROOT = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
MAP = os.path.join(ROOT, "work", "faction_camo.json")
# A closing line can carry a note ("};   // the Falcon, in the east"): missing that walked a class's
# body on into the next class's.
# A faction config names its own classes through CBA's GVAR (docs/CODING_GUIDELINES.md): "class GVAR(x):"
# in addons/<c> is the class jmfsb_<c>_x.
HEAD = re.compile(r"^    class (?:GVAR\((\w+)\)|(\w+))\s*:\s*(?:GVAR\(\w+\)|EGVAR\(\w+,\s*\w+\)|\w+)\s*\{\s*(//.*)?$")
TAIL = re.compile(r"^    \};\s*(//.*)?$")
ARRAY_OPEN = re.compile(r"^        (textureList|hiddenSelectionsTextures|hiddenSelections)\[\]\s*=\s*\{")
MARK = "        // camo: "     # the line that marks a block this script wrote




def blocks(lines, prefix=None):
    """[(class, first line, closing line)] for every class body directly inside CfgVehicles.

    A name written as GVAR(x) is returned expanded, so the rest of the script sees the real class name."""
    out, i = [], 0
    while i < len(lines):
        m = HEAD.match(lines[i])
        if m:
            j = i + 1
            while j < len(lines) and not TAIL.match(lines[j]):
                j += 1
            name = m.group(1)
            out.append((("%s_%s" % (prefix, name)) if (name and prefix) else (name or m.group(2)), i, j))
            i = j
        i += 1
    return out


def strip_paint(body):
    """The body without an earlier run's camo, or any textureList/hiddenSelectionsTextures/TextureSources of
    its own."""
    out, i, own, ours = [], 0, False, False
    while i < len(body):
        line = body[i]
        if line.startswith(MARK):
            ours = True               # the arrays and menu under it are an earlier run's
            i += 1
            continue
        if line.startswith("        class TextureSources"):
            own = own or not ours
            while body[i].rstrip() != "        };":
                i += 1
            i += 1
            continue
        m = ARRAY_OPEN.match(line)
        if m:
            own = own or not ours
            while not re.search(r"\};\s*$", body[i]):
                i += 1
            i += 1
            continue
        out.append(line)
        i += 1
    return out, own


_strings = None


def plain(name, fallback):
    """A display name as words, never a stringtable key (user, 2026-09-20: "no strings"). A $STR_ key is looked up in
    the class table's strings; failing that the key's last word is used ("$STR_A3_TEXTURESOURCES_BLUE0" -> "Blue")."""
    global _strings
    if not isinstance(name, str) or not name.startswith("$"):
        return name or fallback
    if _strings is None:
        _strings = {}
        try:
            import pickle
            _t, _g, st = pickle.load(open(os.environ.get("JMFSB_CAMO_CACHE", r"D:\work\camo_cache") + r"action_table.pickle", "rb"))
            _strings = {k.lower(): v for k, v in st.items()}
        except Exception:
            pass
    got = _strings.get(name.lstrip("$").lower())
    if got and not got.startswith("$"):
        return got
    word = re.sub(r"\d+$", "", name.split("_")[-1])
    return word[:1].upper() + word[1:].lower() if word else fallback


def quote(s):
    return '"%s"' % s.replace('"', '""')


JMFSB_PATH = r"\z\jmfsb\addons" + "\\"


def macro(t, addon):
    """A jmfsb texture path as the mod writes paths elsewhere: QPATHTOF for this addon's own file, QPATHTOEF for
    another addon's. Both expand to exactly the string they replace, so nothing changes at run time."""
    if not isinstance(t, str) or not t.strip():
        return quote(t)
    q = t.strip()
    if not q.lower().startswith(JMFSB_PATH.lower()):
        return quote(q)
    rest = q[len(JMFSB_PATH):]
    owner, _, tail = rest.partition("\\")
    if not tail:
        return quote(q)
    return ("QPATHTOF(%s)" % tail) if owner.lower() == addon.lower() else ("QPATHTOEF(%s,%s)" % (owner, tail))


def paint(cls, pick, addon=""):
    tex = pick["textures"]
    # An EMPTY textureList stops BIS_fnc_initVehicle repainting a spawned vehicle from its parent's list,
    # but it also empties the texture dropdown. Naming our own entry does both jobs: the vehicle always
    # spawns in its faction camo, and the menu below still lists it and the paints it shipped with.
    default = pick.get("default")
    lines = [MARK + "%s (%s)" % (pick["camo"], pick["from"])]
    # textureList may only name a paint the vehicle ALREADY has: we add no TextureSources of our own any more,
    # so naming one would point at a class that does not exist. Without it the parent's list applies.
    if default and not str(default).startswith("jmfsb_camo_"):
        lines.append('        textureList[] = {"%s", 1};' % default)   # a paint the vehicle already has
    else:
        lines.append("        textureList[] = {};")                     # nothing may repaint our camo
    if pick.get("selections"):
        # a parent the pipeline could not read: the selections are named here, so the pairing is by name
        lines.append("        hiddenSelections[] = {%s};" % ", ".join(quote(x) for x in pick["selections"]))
    lines.append("        hiddenSelectionsTextures[] = {")
    lines += ['            %s%s' % (macro(t, addon), "," if n < len(tex) - 1 else "") for n, t in enumerate(tex)]
    lines.append("        };")
    # NO TextureSources anywhere (user, 2026-09-21, twice: "do not add   class TextureSources  to things",
    # "you do not need to add TextureSources to set the textures"). hiddenSelectionsTextures above sets the paint.
    # An EMPTY textureList is what keeps it: without one, BIS_fnc_initVehicle repaints a spawned vehicle from the
    # parent's list and the camo is lost. The cost is that these vehicles have no appearance dropdown of their own.
    return lines


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--map", default=MAP)
    ap.add_argument("--only", default="", help="comma-separated addons; the rest of the map is left alone")
    args = ap.parse_args()
    only = {x.strip().lower() for x in args.only.split(",") if x.strip()}
    m = json.load(io.open(args.map, encoding="utf-8"))
    for addon in sorted(set(m["camo"]) | set(m["hide"]) | set(m.get("unhide", {}))):
        if only and addon.lower() not in only:
            continue
        path = os.path.join(ROOT, "addons", addon, "CfgVehicles.hpp")
        raw = io.open(path, encoding="utf-8", newline="").read()
        nl = "\r\n" if "\r\n" in raw else "\n"
        lines = raw.replace("\r\n", "\n").split("\n")
        camo = {k.lower(): v for k, v in m["camo"].get(addon, {}).items()}
        hide = {k.lower() for k in m["hide"].get(addon, [])}
        unhide = {k.lower() for k in m.get("unhide", {}).get(addon, [])}
        painted = hidden = shown = unpainted = 0
        seen = set()
        for cls, i, j in reversed(blocks(lines, "jmfsb_%s" % addon)):
            lo = cls.lower()
            if lo not in camo and lo not in hide and lo not in unhide:
                # A vehicle the map no longer paints - the boats, once they were left in their own paint -
                # keeps an earlier run's camo block, and with it texture paths this run is about to prune.
                # Strip it, so dropping a vehicle from the map really does give it its own paint back.
                body = lines[i + 1:j]
                if any(b.startswith(MARK) for b in body):
                    lines[i + 1:j] = strip_paint(body)[0]
                    unpainted += 1
                continue
            seen.add(lo)
            body = lines[i + 1:j]
            if lo not in camo and any(b.startswith(MARK) for b in body):
                # hidden or shown again but no longer painted (the static weapons, 2026-09-20): the old block goes too
                body = strip_paint(body)[0]
                unpainted += 1
            if lo in camo:
                body, own = strip_paint(body)
                if own:
                    print("  %s: %s had a textureList or hiddenSelectionsTextures of its own - replaced" % (addon, cls))
                body += paint(cls, camo[lo], addon)
                painted += 1
            if lo in hide:
                body = [re.sub(r"^(        scope = )2;", r"\g<1>1;", b) for b in body]
                body = [re.sub(r"^(        scopeCurator = )2;", r"\g<1>0;", b) for b in body]
                hidden += 1
            if lo in unhide:          # an earlier hide undone: every class it hid was scope 2, scopeCurator 2
                body = [re.sub(r"^(        scope = )1;", r"\g<1>2;", b) for b in body]
                body = [re.sub(r"^(        scopeCurator = )0;", r"\g<1>2;", b) for b in body]
                shown += 1
            lines[i + 1:j] = body
        copied = 0
        for pick in camo.values():
            for src, rel in pick["copy"]:
                parts = ([addon] if rel.lower().startswith("data\\") else []) + rel.split("\\")
                dst = os.path.join(ROOT, "addons", *parts)
                if os.path.exists(dst) and os.path.getsize(dst) == os.path.getsize(src):
                    continue
                copied += 1
                if not args.dry_run:
                    os.makedirs(os.path.dirname(dst), exist_ok=True)
                    shutil.copy2(src, dst)
        missing = sorted((set(camo) | hide | unhide) - seen)
        print("%s: painted %d, unpainted %d, hidden %d, shown again %d, textures copied %d%s" % (
            addon, painted, unpainted, hidden, shown, copied, ("; NOT FOUND in CfgVehicles.hpp: " + ", ".join(missing)) if missing else ""))
        if not args.dry_run:
            io.open(path, "w", encoding="utf-8", newline="").write(nl.join(lines))
    prune(m, args.dry_run, only)


def prune(m, dry, only=()):
    """Remove the files under a faction's data\\camo that no faction's textures name any more - an
    earlier run's copies, replaced by made textures."""
    used = set()
    for picks in m["camo"].values():
        for pick in picks.values():
            # the appearance-menu camos are named too: leaving them out removed every China menu texture
            for t in pick["textures"] + [x for o in pick.get("options") or [] for x in o["textures"]]:
                lo = t.lower().lstrip("\\")
                if lo.startswith("z\\jmfsb\\addons\\"):
                    used.add(lo[len("z\\jmfsb\\addons\\"):])
    owners = {u.split("\\")[0] for u in used if u.startswith("faction_")} | set(m["camo"])
    if only:
        owners = {o for o in owners if o.lower() in only}
    gone = 0
    for addon in sorted(owners):
        base = os.path.join(ROOT, "addons", addon, "data", "camo")
        for r, _d, fs in os.walk(base, topdown=False):
            for x in fs:
                rel = os.path.relpath(os.path.join(r, x), os.path.join(ROOT, "addons")).replace("/", "\\").lower()
                if rel not in used:
                    gone += 1
                    if not dry:
                        os.remove(os.path.join(r, x))
            if not dry and not os.listdir(r):
                os.rmdir(r)
    print("camo textures no faction names any more%s: %d" % (" (would be removed)" if dry else ", removed", gone))


if __name__ == "__main__":
    main()
