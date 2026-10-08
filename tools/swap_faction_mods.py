#!/usr/bin/env python3
"""Replace what the generated factions name but the load order does not load, in place.

    python tools/swap_faction_mods.py [--dry-run] [--map work/faction_swap.json]

THE ASK (user, 2026-09-13): "look at the exesting factions and replace any dependice thats
missing". Settled by question the same day: the imported jmfsb class where the Aegis/Atlas/OpF
import (tools/aegis_port) has one; otherwise the closest base-game class of the same side and type,
the faction's own kit kept; drop only what has neither.

WHY IN PLACE, NOT BY RE-RUNNING THE GENERATOR. The same reason tools/strip_faction_mods.py gives:
gen_us_factions.py reads an ORBAT dump taken with Aegis, Atlas, Athena, the Aegis Gear Overhaul and
the rest loaded, and that load order is gone. A re-run from that dump would bring every one of these
names back.

THE MAP (work/faction_swap.json): {faction addon: {"swap": {missing class: {"to": replacement or
null, "via": how it was chosen, "table", "kind"}}, "units": {soldier: {"magazines": [...],
"respawnMagazines": [...]}}}}. "units" is each soldier whose magazines had to follow a weapon that
changed - or that named a magazine which does not load - written out whole. It was built on 2026-09-13 against an inventory of
every class that session's load order loads - the base game, the 48 mod folders on its -mod line,
jmfsb's own build - and checked against the RPT (every class the RPT named as declared-but-undefined
came out missing). A class is missing when nothing in that inventory defines it. A replacement had
to load, be a real class (scope 1 or 2, never an abstract base), be the same kind, and for a soldier
the same side. "via" says how it was found:
  jmfsb-import       the import's copy of it                 Aegis_arifle_X -> jmfsb_weapons_arifle_X
  as-is/base-name    the name without the mod's markers      Aegis_O_T_UAV_01_F -> O_UAV_01_F
  ancestor(X)        the nearest real class it was built on  a mod's repaint -> the game's vehicle
  rule(...)          a side, colour, arctic or _vN token off B_D_Soldier_F -> B_Soldier_F
  fa-tier(...)       a future-ammo tier magazine's source    FA_Aegis_30Rnd_..._t3 -> 30Rnd_545x39_Mag_F
  plain-weapon(...)  a preset without its attachments        LMG_03_Arco_Pointer_F -> LMG_03_F
  best-match(score)  the loaded class of that kind sharing the most name words - a weapon by its
                     family word and calibre, a soldier by role, theatre and side
  rifleman(X)        a soldier nothing else matched: the base-game rifleman of his side and theatre
Candidates came only from the base game and the import's five addons (and, for magazines, jmfsb's
future-ammo addons) - never another jmfsb faction, never a mod gen_us_factions.py drops.
A different load order needs a new map.

WHAT IT DOES, per addons/faction_* whose files carry the generator's header:

  CfgWeapons.hpp     a preset's forward declaration, parent, baseWeapon and linked attachment are
                     swapped. A preset whose weapon has no replacement goes, and so does every
                     weapons[] entry naming it; an attachment with none is unlinked.
  CfgVehicles.hpp    forward declarations and parents swapped; uniformClass, backpack, linkedItems,
                     weapons, magazines and items swapped, or the item taken out when nothing
                     replaces it. Then a unit or vehicle whose parent has no replacement goes, through
                     strip_faction_mods.strip_vehicles: its children with it, its crew seats re-crewed.
  CfgGroups.hpp      strip_faction_mods.strip_groups - slots, groups and categories left empty go.
  config.cpp         units[] and weapons[] to what is still defined; requiredAddons gains the jmfsb
                     addons a replacement lives in (they have no dependencies and always load).
  CfgFactionClasses  an icon or flag in a mod's data becomes the base game's side art.
  README.md          the unit count.

NOTHING GOES IN SILENCE: every swap, removal and drop is printed.
"""
import argparse
import io
import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import gen_us_factions as G  # noqa: E402
import strip_faction_mods as S  # noqa: E402

MAP = os.path.join(G.ROOT, "work", "faction_swap.json")
IMPORTED = ("vehicle", "weapons", "vests", "uniform", "headware")
MOD_ART = re.compile(r"(?i)\\A3_(?:Aegis|Atlas|OpF|Athena|AddGis)\\")
KIT_ARRAY = re.compile(r"(\b(?:linkedItems|respawnLinkedItems|weapons|respawnWeapons|magazines|respawnMagazines|"
                       r"items|respawnItems)\[\]\s*=\s*\{)(.*?)(\};)", re.S)
KIT_SCALAR = re.compile(r'^(\s*)(uniformClass|backpack) = "([A-Za-z0-9_]+)";\s*$')
QUOTED = re.compile(r'"([A-Za-z0-9_]+)"')


class CI(dict):
    """A dict whose keys are class names: the game does not care how they are spelled, and the
    generated files do not always spell them the way the map does ("16rnd_9x21_mag_v2")."""
    def __init__(self, d=()):
        super().__init__((k.lower(), v) for k, v in dict(d).items())

    def __contains__(self, k):
        return super().__contains__(k.lower())

    def __getitem__(self, k):
        return super().__getitem__(k.lower())

    def get(self, k, default=None):
        return super().get(k.lower(), default)


class CISet(set):
    def __init__(self, s=()):
        super().__init__(x.lower() for x in s)

    def __contains__(self, k):
        return isinstance(k, str) and super().__contains__(k.lower())

    def __or__(self, other):
        return CISet(set(self) | {x.lower() for x in other})


def swap_arrays(text, swaps, gone, rep, where="CfgVehicles"):
    def sub(m):
        items = QUOTED.findall(m.group(2))
        if not any(x in swaps or x in gone for x in items):
            return m.group(0)
        kept = []
        for x in items:
            if x in gone:
                rep["removed"].append((where, x))
                continue
            if x in swaps:
                rep["kit"].add((x, swaps[x]))
            kept.append(swaps.get(x, x))
        return m.group(1) + ",".join('"%s"' % x for x in kept) + m.group(3)
    return KIT_ARRAY.sub(sub, text)


def swap_weapons(text, swaps, gone_weapons, gone_attach, rep):
    """-> (text, names of the presets that went)."""
    tree = S.parse(S.split_lines(text))
    roots = [n for n in S.blocks(tree) if n[3] == "CfgWeapons"]
    if not roots:
        return text, set()
    root, removed, declared = roots[0], set(), set()

    def fix_body(nodes):
        for n in nodes:
            if n[0] == "line":
                m = re.match(r'^(\s*)(baseWeapon|item) = "([A-Za-z0-9_]+)";\s*$', n[1])
                if m and m.group(3) in swaps:
                    n[1] = '%s%s = "%s";' % (m.group(1), m.group(2), swaps[m.group(3)])
            else:
                item = [it for it in n[5] if it[0] == "line" and re.match(r'^\s*item = "([A-Za-z0-9_]+)";', it[1])]
                name = re.match(r'^\s*item = "([A-Za-z0-9_]+)";', item[0][1]).group(1) if item else None
                if name in gone_attach:
                    n[0] = "drop"
                    rep["unlinked"].append(name)
                    continue
                fix_body(n[5])
                n[5] = [k for k in n[5] if k[0] != "drop"]

    for n in root[5]:
        if n[0] == "line":
            m = S.RE_DECL.match(n[1])
            if m:
                name = m.group(2)
                if name in gone_weapons:
                    n[0] = "drop"
                    continue
                new = swaps.get(name, name)
                if new.lower() in declared:
                    n[0] = "drop"
                    continue
                declared.add(new.lower())
                n[1] = "%sclass %s;" % (m.group(1), new)
            continue
        if n[4] in gone_weapons:
            n[0] = "drop"
            removed.add(n[3])
            rep["preset"].append((n[3], n[4]))
            continue
        if n[4] in swaps:
            rep["parent"].append((n[3], n[4], swaps[n[4]]))
            n[1] = "%sclass %s: %s {" % (" " * n[2], n[3], swaps[n[4]])
        fix_body(n[5])
    root[5] = [n for n in root[5] if n[0] != "drop"]
    return "\n".join(S.collapse_blanks(S.emit(tree, []))), removed


def swap_vehicles(text, swaps, gone_items, units, rep):
    text = swap_arrays(text, swaps, gone_items, rep)
    out, declared, cur = [], set(), None
    for ln in S.split_lines(text):
        m = S.RE_OPEN.match(ln)
        if m and len(m.group(1)) == 4:
            cur = m.group(2)
        elif ln.startswith("    };"):
            cur = None
        mm = re.match(r"^(\s*)(magazines|respawnMagazines)\[\] = \{", ln)
        if mm and cur in units and mm.group(2) in units[cur]:
            rep["mags"].add(cur)
            out.append('%s%s[] = {%s};' % (mm.group(1), mm.group(2), ",".join('"%s"' % x for x in units[cur][mm.group(2)])))
            continue
        m = S.RE_DECL.match(ln)
        if m:
            name = m.group(2)
            new = swaps.get(name, name)
            if new.lower() in declared:
                continue
            declared.add(new.lower())
            out.append("%sclass %s;" % (m.group(1), new) if new != name else ln)
            continue
        m = S.RE_OPEN.match(ln)
        if m and m.group(3) and m.group(3) in swaps:
            rep["parent"].append((m.group(2), m.group(3), swaps[m.group(3)]))
            out.append("%sclass %s: %s {" % (m.group(1), m.group(2), swaps[m.group(3)]))
            continue
        m = KIT_SCALAR.match(ln)
        if m:
            v = m.group(3)
            if v in gone_items:
                rep["removed"].append(("CfgVehicles", v))
                continue
            if v in swaps:
                rep["kit"].add((v, swaps[v]))
                ln = '%s%s = "%s";' % (m.group(1), m.group(2), swaps[v])
        out.append(ln)
    return "\n".join(out)


def fix_config(text, kept, removed_presets, need):
    text = S.strip_patches(text, kept)

    def weapons(m):
        items = [x for x in QUOTED.findall(m.group(2)) if x not in removed_presets]
        return m.group(1) + ",".join('"%s"' % x for x in items) + m.group(3)
    text = re.sub(r"(\bweapons\[\]\s*=\s*\{)(.*?)(\};)", weapons, text, flags=re.S)

    def required(m):
        have = QUOTED.findall(m.group(2))
        add = [a for a in sorted(need) if a not in have]
        return m.group(1) + ", ".join('"%s"' % x for x in have + add) + m.group(3) if add else m.group(0)
    return re.sub(r"(\brequiredAddons\[\]\s*=\s*\{)(.*?)(\};)", required, text, count=1, flags=re.S)


def fix_faction_art(text, rep):
    m = re.search(r"^\s*side = (\d);", text, re.M)
    side = int(m.group(1)) if m else 1

    def sub(mm):
        if MOD_ART.search(mm.group(2)):
            rep["art"].append((mm.group(1), mm.group(2)))
            return '%s = "%s";' % (mm.group(1), G.VANILLA_ART[mm.group(1)][side])
        return mm.group(0)
    return re.sub(r'(icon|flag) = "([^"]+)";', sub, text)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--map", default=MAP)
    args = ap.parse_args()
    if not os.path.exists(args.map):
        print("%s is missing - it is built from an inventory of the load order; see the header." % args.map)
        return 2
    table = json.load(io.open(args.map, encoding="utf-8"))

    for addon in sorted(table):
        entries = table[addon]["swap"]
        units = table[addon].get("units", {})
        d = os.path.join(G.ADDONS, addon)
        vp = os.path.join(d, "CfgVehicles.hpp")
        if not os.path.exists(vp) or S.GEN_HDR not in S.read(vp):
            if entries:
                print("%-22s not generated by gen_us_factions.py - not touched (%d missing names)" % (addon, len(entries)))
            continue
        # a magazine is not swapped by name: each soldier's list comes whole from "units"
        # a replacement the file already names is written the way the file writes it: HEMTT holds a
        # parent to the spelling of its declaration (L-C05), and the generator wrote B_soldier_F
        canon = {}
        for p in (vp, os.path.join(d, "CfgWeapons.hpp")):
            if os.path.exists(p):
                for m in re.finditer(r"^\s*class (\w+)(?:: (\w+))?\s*[{;]", S.read(p), re.M):
                    for nm in (m.group(1), m.group(2)):
                        if nm:
                            canon.setdefault(nm.lower(), nm)
        swaps = CI({n: canon.get(e["to"].lower(), e["to"]) for n, e in entries.items() if e["to"] and e["kind"] != "kit-magazine"})
        gone = lambda kinds: CISet(n for n, e in entries.items() if not e["to"] and e["kind"] in kinds)
        via = CI({n: e["via"] for n, e in entries.items()})
        gone_parents = gone(("parent-unit", "parent-vehicle"))
        gone_weapons = gone(("parent-weapon",))
        gone_attach = gone(("preset-attachment",))
        gone_items = gone(("kit-linked", "kit-uniform", "kit-weapon"))
        named = list(swaps.values()) + [x for u in units.values() for arr in u.values() for x in arr]
        need = {"jmfsb_" + a for a in IMPORTED for t in named if t.lower().startswith("jmfsb_%s_" % a)}

        rep = dict(decl=[], cls=[], crew=[], paint=[], kit=set(), left=[], slot=[], group=[], group_veh=[],
                   partial=[], cat=[], art=[], vehicles=set(), parent=[], removed=[], preset=[], unlinked=[],
                   mags=set())
        wp = os.path.join(d, "CfgWeapons.hpp")
        wtext, removed_presets = swap_weapons(S.read(wp), swaps, gone_weapons, gone_attach, rep) if os.path.exists(wp) else (None, set())
        vtext = swap_vehicles(S.read(vp), swaps, gone_items | removed_presets, units, rep)
        G.is_dropped = lambda c, vanilla=None, faction=None: c in gone_parents
        vtext, kept = S.strip_vehicles(vtext, None, rep, None)
        if not kept:
            print("%-22s EVERY unit is gone - left alone; decide what to do with the addon" % addon)
            continue
        gp = os.path.join(d, "CfgGroups.hpp")
        gtext = S.strip_groups(S.read(gp), kept, rep)
        cp = os.path.join(d, "config.cpp")
        ctext = fix_config(S.read(cp), kept, removed_presets, need)
        fp = os.path.join(d, "CfgFactionClasses.hpp")
        ftext = fix_faction_art(S.read(fp), rep)
        rp = os.path.join(d, "README.md")
        rtext = S.fix_readme(S.read(rp), len(kept)) if os.path.exists(rp) else None

        for p, t in ((vp, vtext), (gp, gtext), (cp, ctext), (fp, ftext), (wp, wtext), (rp, rtext)):
            if t is not None:
                S.write(p, t, args.dry_run)

        print("%-22s %4d kept, %3d parents swapped, %3d kit swapped, %3d soldiers re-magazined, %3d items removed, "
              "%3d dropped, %d preset(s) gone, %d slot(s) and %d group(s) gone%s"
              % (addon, len(kept), len(rep["parent"]), len(rep["kit"]), len(rep["mags"]), len(rep["removed"]), len(rep["cls"]),
                 len(rep["preset"]), len(rep["slot"]), len(rep["group"]) + len(rep["group_veh"]),
                 "  [dry run]" if args.dry_run else ""))
        for cls, old, new in rep["parent"]:
            print("      parent %s: %s -> %s  (%s)" % (cls, old, new, via.get(old)))
        for old, new in sorted(rep["kit"]):
            print("      kit    %s -> %s  (%s)" % (old, new, via.get(old)))
        for where, item in sorted(set(rep["removed"])):
            print("      out    %s (nothing replaces it)" % item)
        for name, parent in rep["cls"]:
            print("      drop   %s (%s)" % (name, parent))
        for p, w in rep["preset"]:
            print("      preset %s gone (%s has no replacement)" % (p, w))
        for a in sorted(set(rep["unlinked"])):
            print("      unlink %s" % a)
        for veh, cr, new in rep["crew"]:
            print("      crew   %s: %s -> %s" % (veh, cr, new or "(parent's crew stands)"))
        for g in rep["group"]:
            print("      group  %s: no slots left" % g)
        for g, vehs in rep["group_veh"]:
            print("      group  %s: lost %s - dropped" % (g, ", ".join(vehs)))
        for g, lost, total, vehs in rep["partial"]:
            print("      group  %s: %d of %d lost, kept short" % (g, lost, total))
        for kind, val in rep["art"]:
            print("      art    %s was %s" % (kind, val))
        if need:
            print("      requires %s" % ", ".join(sorted(need)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
