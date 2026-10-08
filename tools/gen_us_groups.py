#!/usr/bin/env python3
"""Give every US faction the same order of battle.

    python tools/gen_us_groups.py

Writes addons/faction_<x>/CfgGroups.hpp for each of the six US factions, each
carrying the SAME 47 groups, built out of that faction's own units.

WHY. The six US factions were nowhere near each other. BLU_F ships 47 groups,
BLU_T_F 45, BLU_W_F six - all infantry, no armour, no support, no recon - and
the three mod factions ship whatever their mod felt like. A mission that picks
"a US mechanised squad" gets one from BLU_F and nothing at all from BLU_W_F.
None of the six faction addons in this repo defined a single group.

BLU_F IS THE TEMPLATE because it is the complete one: 47 groups across
Infantry, SpecOps, Motorized, Mechanized, Armored and Support. Every other
faction gets those same 47, with each man swapped for its own equivalent.

HOW A UNIT IS MATCHED, in order, and the first hit wins:

  1. The faction's own roster, by ROLE. `B_soldier_AR_F` reduces to the role
     `soldier_ar`, and so does `B_D_soldier_AR_lxWS` - prefix and suffix
     stripped. This carries most of it.
  2. The base game index, by constructed name. BLU_T_F and BLU_W_F are BI
     factions whose classes follow `B_` -> `B_T_` / `B_W_` exactly, and some of
     those units are scope 1 and so absent from the ORBAT dump.
  3. The alias table below. The MJTF Marines use entirely different role words -
     `Marine_AR`, not `soldier_AR` - so no amount of affix stripping matches
     them and the mapping has to be written down.
  4. Failing all of that, BLU_F's own class, and the substitution is PRINTED.
     A faction with no divers keeps BLU_F's divers rather than losing the group;
     that is a real decision and it is visible rather than silent.

THE FACTIONS' OWN GROUPS ARE LEFT ALONE. These are added alongside, under
jmfsb_ names, so nothing that already works stops working and the two sets are
one glance apart in Zeus.
"""
import io
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ADDONS = os.path.join(ROOT, "addons")
GROUPS = os.path.join(ROOT, "work", "vanilla_groups.json")
FACTIONS = os.path.join(ROOT, "work", "factions.json")
VEHICLES = os.path.join(ROOT, "work", "vanilla_vehicles.json")
A3 = os.path.join(r"D:\Dropbox\Documents\Arma 3 Projects", "a3")

SOURCE = ("WEST", "BLU_F")

# faction -> (addon dir, prefixes to strip, suffixes to strip, name-swap prefix)
# The name-swap prefix is only meaningful for the BI factions, where
# `B_x` -> `B_T_x` is exact; it is None for the mod factions.
TARGETS = [
    ("BLU_F",         "faction_blu_f",
     ["B_"], ["_F"], None),
    ("BLU_T_F",       "faction_blu_t_f",
     ["B_T_"], ["_F"], "B_T_"),
    ("BLU_W_F",       "faction_blu_w_f",
     ["B_W_"], ["_F"], "B_W_"),
    ("BLU_NATO_lxWS", "faction_blu_nato_lxws",
     ["Aegis_B_D_", "Atlas_B_D_", "B_D_", "EF_B_"],
     ["_lxWS_v2", "_lxWS", "_NATO_Des", "_Des", "_RF", "_rf", "_F"], None),
    ("EF_B_MJTF_Des", "faction_ef_b_mjtf_des",
     ["EF_B_Marine_", "Aegis_B_MJTF_D_", "EF_B_"],
     ["_MJTF_Des", "_MJTF_des", "_Des", "_des", "_F"], None),
    ("EF_B_MJTF_Wdl", "faction_ef_b_mjtf_wdl",
     ["EF_B_Marine_", "Aegis_B_MJTF_W_", "EF_B_"],
     ["_MJTF_Wdl", "_MJTF_wdl", "_Wdl", "_wdl", "_F"], None),
]

# BLU_F role -> the role that faction family calls the same job.
#
# THE MARINES ARE A DIFFERENT VOCABULARY, not a different spelling: an ammo
# bearer is `AB` not `soldier_A`, a marksman is `Mark` not `soldier_M`, and the
# rifleman is just `R`. Affix stripping cannot find any of that.
ALIAS_MJTF = {
    "soldier": "r",
    "soldier_tl": "tl",
    "soldier_sl": "sl",
    "soldier_ar": "ar",
    "soldier_a": "ab",
    "soldier_aar": "ab",
    "soldier_gl": "gl",
    "soldier_m": "mark",
    "soldier_lat": "lat",
    "soldier_lat2": "lat2",
    "soldier_at": "at",
    "soldier_aat": "aat",
    "soldier_aa": "aa",
    "soldier_aaa": "aaa",
    "soldier_exp": "exp",
    "soldier_repair": "repair",
    "soldier_uav": "uav",
    "engineer": "eng",
    # No MMG man of its own - the automatic rifleman is the closest weapon.
    "heavygunner": "ar",
    "sharpshooter": "mark",
    "sniper": "recon_m",
    "spotter": "recon_m",
    "recon_sharpshooter": "recon_m",
    "diver_exp": "diver_eng",
    "support_mg": "hmg",
    "support_amg": "amg",
    "support_gmg": "gmg",
    "support_mort": "mort",
    "support_amort": "amort",
    # The Marines field the AAV rather than the Marshall or the Rhino.
    "afv_wheeled_01_cannon": "aav9_50mm",
    "afv_wheeled_01_up_cannon": "aav9_50mm",
    "apc_wheeled_01_cannon": "aav9_50mm",
    "apc_tracked_01_rcws": "aav9",
    # No tracked SPAAG; the LAAD MRAP is the air defence vehicle.
    "apc_tracked_01_aa": "mrap_01_laad",
    # No self-propelled gun, only the rocket artillery.
    "mbt_01_arty": "mbt_01_mlrs",
    "uav_02": "uav_02_dynamicloadout",
    "uav_02_cas": "uav_02_dynamicloadout",
}

ALIAS_LXWS = {
    "sniper": "recon_sharpshooter",
    "spotter": "recon_m",
    "soldier_uav": "uav01",
    "boat_transport_01": "combatboat_unarmed",
    "uav_02": "uav_02_dynamicloadout",
    "uav_02_cas": "uav_02_dynamicloadout",
    # No dedicated static-weapon crew; the MMG man carries the gun and the
    # ammo bearer carries the rest.
    "support_mg": "heavygunner",
    "support_gmg": "heavygunner",
    "support_amg": "soldier_a",
    "support_mort": "support_cmort",
}

ALIASES = {
    "BLU_NATO_lxWS": ALIAS_LXWS,
    "EF_B_MJTF_Des": ALIAS_MJTF,
    "EF_B_MJTF_Wdl": ALIAS_MJTF,
}


def load_stringtable(a3):
    """key -> English text, from every stringtable.xml in the base game tree.

    GROUP NAMES ARE STRINGTABLE KEYS, all 47 of them. Writing "jmfsb " in front
    of `$STR_A3_CfgGroups_...` does not prefix the group's name - it breaks the
    lookup, and the editor shows the raw key. The key has to be resolved first
    and the prefix put in front of the ANSWER.
    """
    import glob
    out = {}
    if not os.path.isdir(a3):
        return out
    for p in glob.glob(os.path.join(a3, "**", "stringtable.xml"), recursive=True):
        try:
            t = io.open(p, encoding="utf-8", errors="replace").read()
        except OSError:
            continue
        for m in re.finditer(
                r'<Key\s+ID="([^"]+)"\s*>(.*?)</Key>', t, re.S | re.I):
            en = re.search(r"<English>(.*?)</English>", m.group(2), re.S | re.I)
            if en:
                out.setdefault(m.group(1).lower(), en.group(1).strip())
    return out


def role_key(cls, prefixes, suffixes):
    s = cls
    for p in sorted(prefixes, key=len, reverse=True):
        if s.lower().startswith(p.lower()):
            s = s[len(p):]
            break
    for x in sorted(suffixes, key=len, reverse=True):
        if s.lower().endswith(x.lower()):
            s = s[:-len(x)]
            break
    return s.lower()


def main():
    for p in (GROUPS, FACTIONS, VEHICLES):
        if not os.path.isfile(p):
            print("missing %s" % p)
            return 1

    allgroups = json.load(io.open(GROUPS, encoding="utf-8"))
    factions = json.load(io.open(FACTIONS, encoding="utf-8"))
    vanilla = json.load(io.open(VEHICLES, encoding="utf-8"))
    van_ci = dict((k.lower(), k) for k in vanilla)

    strings = load_stringtable(A3)
    print("%d stringtable key(s) loaded" % len(strings))

    def display(name):
        if name.startswith("$"):
            return strings.get(name[1:].lower(), name)
        return name

    src = allgroups[SOURCE[0]][SOURCE[1]]
    n_src = sum(len(c) for c in src.values())

    print("template: %s, %d groups in %d categories"
          % (SOURCE[1], n_src, len(src)))
    print("")

    total_fallback = 0
    bad = 0
    for fac, addon, prefixes, suffixes, swap in TARGETS:
        outdir = os.path.join(ADDONS, addon)
        if not os.path.isdir(outdir):
            print("%s: no addon dir %s - skipped" % (fac, addon))
            continue

        roster = [u["cls"] for u in factions.get(fac, {}).get("units", [])]
        by_role = {}
        for c in roster:
            by_role.setdefault(role_key(c, prefixes, suffixes), c)
        alias = ALIASES.get(fac, {})

        fallbacks = []
        resolved = {}
        unknown = set()

        def resolve(cls):
            if cls in resolved:
                return resolved[cls]
            role = role_key(cls, ["B_"], ["_F"])

            # 1. the faction's own roster, by role
            hit = by_role.get(role)

            # 2. the base game index, by constructed name - catches the scope 1
            #    units the ORBAT dump never recorded
            if not hit and swap and cls.startswith("B_"):
                cand = swap + cls[2:]
                hit = van_ci.get(cand.lower())

            # 3. the alias table
            if not hit and role in alias:
                a = alias[role]
                hit = by_role.get(a)
                if not hit and swap:
                    hit = van_ci.get((swap + a + "_F").lower())

            # 4. BLU_F's own class, and say so. Not for BLU_F itself: the
            #    template standing in for the template is the identity, not a
            #    substitution, and reporting it as one is noise.
            if not hit:
                hit = cls
                if fac != SOURCE[1]:
                    fallbacks.append((role, cls))

            # EVERY EMITTED CLASS MUST EXIST. A group naming a class that is not
            # in any config spawns a man-shaped hole, and the RPT says nothing
            # useful about it.
            if hit.lower() not in van_ci and hit not in roster:
                unknown.add(hit)

            resolved[cls] = hit
            return hit

        lines = [
            "// THE US ORDER OF BATTLE, THE SAME ACROSS EVERY US FACTION.",
            "//",
            "// %d groups mirrored from %s, each man swapped for %s's own" % (n_src, SOURCE[1], fac),
            "// equivalent. The six US factions shipped 47, 45, 6 and three unknown",
            "// counts between them, so a mission asking any of them for an armoured",
            "// platoon got one from BLU_F and nothing from the rest.",
            "//",
            "// %s'S OWN GROUPS ARE UNTOUCHED. These are added alongside under jmfsb_" % fac,
            "// names, so nothing that already worked stops working, and the two sets",
            "// are one glance apart in Zeus.",
            "//",
            "// NO BASE CLASS ON THE FACTION, which is what makes this safe: it merges",
            "// into the faction wherever it came from, and leaves an inert empty class",
            "// rather than a broken config if that mod is absent.",
            "//",
            "// Generated by tools/gen_us_groups.py - re-run rather than hand-edit.",
            "",
            "class CfgGroups {",
            "    class West {",
            "        class %s {" % fac,
        ]

        n_grp = 0
        for cat in sorted(src):
            lines.append("")
            lines.append("            class %s {" % cat)
            for grp in sorted(src[cat]):
                rec = src[cat][grp]
                gname = "jmfsb_%s_%s" % (fac, re.sub(r"^BUS_", "", grp))
                lines.append("")
                lines.append("                class %s {" % gname)
                lines.append('                    name = "jmfsb %s";' % display(rec["name"]))
                lines.append("                    side = 1;")
                lines.append('                    faction = "%s";' % fac)
                if rec.get("icon"):
                    lines.append('                    icon = "%s";' % rec["icon"])
                lines.append("                    rarityGroup = %s;" % _num(rec.get("rarityGroup", 1)))
                for i, man in enumerate(rec["men"]):
                    lines.append("")
                    lines.append("                    class Unit%d {" % i)
                    lines.append("                        side = 1;")
                    lines.append('                        vehicle = "%s";' % resolve(man["cls"]))
                    lines.append('                        rank = "%s";' % man["rank"])
                    lines.append("                        position[] = {%s};"
                                 % ", ".join(_num(x) for x in man["pos"]))
                    lines.append("                    };")
                lines.append("                };")
                n_grp += 1
            lines.append("            };")

        lines += ["        };", "    };", "};"]

        io.open(os.path.join(outdir, "CfgGroups.hpp"), "w",
                encoding="utf-8", newline="\r\n").write("\n".join(lines) + "\n")

        uniq = sorted(set(f[1] for f in fallbacks))
        total_fallback += len(uniq)
        print("%-16s %2d groups, %d unit class(es) mapped, %d kept from %s"
              % (fac, n_grp, len(resolved), len(uniq), SOURCE[1]))
        for c in uniq:
            print("                 kept %s - no equivalent in this faction" % c)
        if unknown:
            bad += len(unknown)
            for c in sorted(unknown):
                print("                 *** %s IS IN NO CONFIG - group will not field" % c)

    print("")
    print("%d substitution(s) total. Each one is a %s unit standing in for a"
          % (total_fallback, SOURCE[1]))
    print("unit the faction does not have, so the group still fields.")
    if bad:
        print("")
        print("%d class(es) exist in no config at all - fix before shipping" % bad)
        return 1
    return 0


def _num(v):
    f = float(v)
    return str(int(f)) if f == int(f) else ("%g" % f)


if __name__ == "__main__":
    sys.exit(main())
