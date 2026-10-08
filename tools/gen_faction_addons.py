#!/usr/bin/env python3
"""Scaffold one jmfsb addon per faction we intend to MODIFY.

    python tools/gen_faction_addons.py [--side west] [--force]

Reads work/factions.json (produced from an in-game ORBAT dump) and writes
addons/faction_<slug>/ for every faction on the chosen side that is on the
modify list. Also writes docs/FACTIONS.md - the standing record of which
factions we touch, at what tier, and which we deliberately leave alone.

WHY ONE ADDON PER FACTION: a faction is a per-faction decision - its tier, its
shape, its whole loadout table - and each wants its own file, its own README
and its own PBO. A single "factions" addon would make every edit a merge
conflict.

NOT MODIFIED IS NOT HIDDEN. A faction we are not rebuilding gets NO addon and
no config: it stays exactly as its own mod ships it. Hiding it would itself be
a change, and the point of that list is that we are not making one. The list
lives in docs/FACTIONS.md so the decision is written down somewhere other than
somebody's memory.

A MODIFIED FACTION IS RENAMED "jmfsb <name>" IN 3DEN AND ZEUS. Once a faction's
loadouts are ours it is no longer the thing the mod shipped, and a mission
maker scrolling forty NATO variants has no way to tell which ones we rebuilt.
The prefix is that way.

EXISTING ADDONS ARE NEVER OVERWRITTEN without --force. This scaffolds; the tier
work that follows is by hand.
"""
import argparse
import io
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DATA = os.path.join(ROOT, "work", "factions.json")
ADDONS = os.path.join(ROOT, "addons")
DOCS = os.path.join(ROOT, "docs")

B = chr(92)
SIDES = {0: "east", 1: "west", 2: "guer", 3: "civ"}

# A roster this small is a stub - a case-variant duplicate, a vehicle-only
# pack, a mod that registered a faction and never filled it. One sub-group is
# nothing to tier, so it goes on the leave-alone list.
STUB_MAX = 4

# WHAT A MODIFIED FACTION IS CALLED IN 3DEN AND ZEUS. A space, not an
# underscore: this is a name a person reads off a list, not an identifier.
JMFSB_PREFIX = "2040 "

# Factions left exactly as their mod ships them whatever their size, with the
# reason. Stubs are added to this automatically; these are the deliberate ones.
NEVER = {
    "Marine_BLU_USMC_F": "MJTF carries the Marine role now - two Marine forces is one too many",
    # CTRG stays as its mod ships it. jmfsb_faction_jmsb is built FROM it in
    # addons/faction_jmsb rather than over the top of it, so both exist and
    # the original is never touched.
    "BLU_CTRG_F": "left as shipped - jmfsb_faction_jmsb is built from it, not over it",
    "BLU_CTRG_tna_F": "left as shipped - jmfsb_faction_jmsb is built from it, not over it",
}

# cls: (tier, strength, shape, flavor, rename or None, why)
#
# RENAME IS THE FACTION'S NEW IDENTITY, not decoration - it becomes the 3DEN and
# Zeus name as jmfsb_<rename>, and the addon README's title.
#
# Tier/strength/shape are judgement calls about what a faction should FEEL like.
# They live in this one table so re-tiering is one line and a re-run, never a
# hunt through forty addons.
PLAN = {
    # --- peer+ -----------------------------------------------------------
    # NOTHING HERE. The only blue peer+ is jmfsb_faction_jmsb, which is not in this
    # table because it is not an existing faction being modified - it is four
    # new factions built from CTRG in addons/faction_jmsb. Everything blue in
    # this table tops out at tier 3.

    # --- peer ------------------------------------------------------------
    "BLU_F":             (3, 2, "elite",    "west",      "US Army",
                          "US 2040 canon: t3 gear, t4 R&D, elite shape, low strength"),
    "BLU_T_F":           (3, 2, "elite",    "west",      "US Army (Pacific)",
                          "US pacific - same force, different theatre"),
    "BLU_W_F":           (3, 2, "elite",    "west",      "US Army (Woodland)",
                          "US woodland - same force, different theatre"),
    "BLU_NATO_lxWS":     (3, 2, "elite",    "west",      "US Army (Desert)",
                          "US desert - same force, different theatre"),
    "EF_B_MJTF_Des":     (3, 2, "elite",    "west",      "Marine (Desert)",
                          "The Marines, desert - MJTF renamed, carries the USMC role"),
    "EF_B_MJTF_Wdl":     (3, 2, "elite",    "west",      "Marine (Woodland)",
                          "The Marines, woodland - MJTF renamed"),
    "BLU_A_F":           (3, 2, "balanced", "west",      "BAF", "BAF - peer ally"),
    "BLU_A_tna_F":       (3, 2, "balanced", "west",      "BAF (Pacific)", "BAF pacific"),
    "BLU_A_wdl_F":       (3, 2, "balanced", "west",      "BAF (Woodland)", "BAF woodland"),
    "Atlas_BLU_G_F":     (3, 3, "balanced", "west",      "Bundeswehr",
                          "Bundeswehr - G36/G433 is the t3 lane in the pools doc"),
    "Atlas_BLU_G_ard_F": (3, 3, "balanced", "west",      "Bundeswehr (Arid)", "Bundeswehr arid"),
    "AddGis_BLU_G_D_F":  (3, 3, "balanced", "west",      "Bundeswehr (Desert)", "Bundeswehr desert"),

    # --- near-peer -------------------------------------------------------
    "Atlas_BLU_A_F":     (2, 3, "balanced", "west",      "ADF", "ADF - near-peer"),
    "Atlas_BLU_A_ard_F": (2, 3, "balanced", "west",      "ADF (Arid)", "ADF arid"),
    "Atlas_BLU_A_trp_F": (2, 3, "balanced", "west",      "ADF (Pacific)", "ADF pacific"),
    "BLU_EAF_F":         (2, 3, "balanced", "west",      "LDF",
                          "LDF - national defence force, near-peer"),
    "BLU_EAF_ard_F":     (2, 3, "balanced", "west",      "LDF (Arid)", "LDF arid"),
    "Atlas_BLU_H_F":     (2, 3, "balanced", "west",      "HIMF", "HIMF - near-peer"),
    "Atlas_BLU_L_F":     (2, 2, "elite",    "west",      "Legionnaires",
                          "Legionnaires - small and professional"),
    "BLU_ION_lxWS":      (2, 2, "elite",    "west",      "ION Services",
                          "ION - PMC, bought kit, small"),
    "QAV_vehicles":      (2, 1, "balanced", "west",      "QAV",
                          "QAV - a vehicle pack, not a force; kit lives on whoever crews it"),

    # --- funded / proxy --------------------------------------------------
    "Atlas_BLU_K_F":     (1, 3, "balanced", "west",      "Karzeghistan",
                          "Karzeghistan - funded, last-gen service rifles"),
    "Atlas_BLU_M_F":     (1, 3, "balanced", "west",      "Marar", "Marar - funded, last-gen"),
    "BLU_UN_lxWS":       (1, 2, "balanced", "west",      "UNA",
                          "UNA - peacekeepers, restrained kit"),
    "BLU_TURA_lxWS":     (1, 2, "balanced", "west",      "Tura", "Tura - light national force"),
    "BLU_GEN_F":         (1, 2, "balanced", "west",      "Gendarmerie",
                          "Gendarmerie - police, not an army"),
    "BLU_G_F":           (1, 3, "horde",    "irregular", "FIA",
                          "FIA - funded insurgents, patron toys"),

    # --- broke -----------------------------------------------------------
    "Opf_BLU_P_F":       (0, 3, "horde",    "irregular", "Partisans",
                          "Partisans - broke, surplus, no optics"),
}


def slug(name):
    return re.sub(r"[^a-z0-9]+", "_", name.lower()).strip("_")


def crlf(path, lines):
    io.open(path, "w", encoding="utf-8", newline="\r\n").write("\n".join(lines) + "\n")


def load(side):
    facs = json.load(io.open(DATA, encoding="utf-8"))
    want = sorted([k for k, v in facs.items() if SIDES.get(v.get("side")) == side],
                  key=str.lower)

    # CONFIG IS CASE-INSENSITIVE AND THE DUMP IS NOT. BLU_NATO_LXWS and
    # BLU_NATO_lxWS are one faction two mods spelled differently, and the engine
    # treats them as one - so a per-case addon would be two addons for one
    # faction, with a 3-unit stub deciding whether a 147-unit force gets built.
    merged = {}
    for cls in want:
        key = slug(cls)
        fac = facs[cls]
        if key not in merged:
            merged[key] = {"cls": cls, "name": fac["name"], "side": fac["side"],
                           "units": list(fac["units"]), "aka": []}
            continue
        m = merged[key]
        m["aka"].append(cls)
        seen = set(u["cls"].lower() for u in m["units"])
        for u in fac["units"]:
            if u["cls"].lower() not in seen:
                m["units"].append(u)
                seen.add(u["cls"].lower())
        if not m["name"]:
            m["name"] = fac["name"]

    plan = dict((k.lower(), v) for k, v in PLAN.items())
    never = dict((k.lower(), v) for k, v in NEVER.items())

    out = []
    for key in sorted(merged):
        m = merged[key]
        why_not = never.get(m["cls"].lower())
        if why_not is None and len(m["units"]) <= STUB_MAX:
            why_not = "one sub-group only (%d unit%s) - nothing to tier" % (
                len(m["units"]), "" if len(m["units"]) == 1 else "s")
        m["skip"] = why_not
        m["plan"] = plan.get(m["cls"].lower())
        out.append(m)
    return out


def write_addon(fac, force):
    cls = fac["cls"]
    units = fac["units"]
    # A STAGED SIDE HAS NO TIER CALLS YET, and that must not stop it being
    # scaffolded: the roster is the thing somebody reads while making those
    # calls. An unassigned faction gets the addon and says so at the top of it.
    tier, strength, shape, flavor, rename, why = fac["plan"] or (
        None, None, None, None, None, "UNASSIGNED - needs a tier call")
    was = fac["name"] or cls
    name = rename or was
    jmfsb_name = JMFSB_PREFIX + name

    comp = "faction_" + slug(cls)
    path = os.path.join(ADDONS, comp)
    if os.path.isdir(path) and not force:
        return comp, False
    if not os.path.isdir(path):
        os.makedirs(path)

    main_inc = B + "z" + B + "jmfsb" + B + "addons" + B + "main" + B

    crlf(os.path.join(path, "$PBOPREFIX$"), ["z" + B + "jmfsb" + B + "addons" + B + comp])

    crlf(os.path.join(path, "script_component.hpp"), [
        "#define COMPONENT " + comp,
        "#define COMPONENT_BEAUTIFIED " + name,
        '#include "' + main_inc + 'script_mod.hpp"',
        "",
        "// #define DEBUG_MODE_FULL",
        "// #define DISABLE_COMPILE_CACHE",
        "",
        '#include "' + main_inc + 'script_macros.hpp"',
    ])

    crlf(os.path.join(path, "config.cpp"), [
        '#include "script_component.hpp"',
        "",
        "class CfgPatches {",
        "    class ADDON {",
        "        name = COMPONENT_NAME;",
        "        units[] = {};",
        "        weapons[] = {};",
        "        requiredVersion = REQUIRED_VERSION;",
        "        // NOTHING FROM THE FACTION'S OWN MOD IS REQUIRED, DELIBERATELY.",
        "        // This patches classes that belong to somebody else, and must not",
        "        // break a load order that does not have them - see faction.hpp.",
        '        requiredAddons[] = {"jmfsb_main"};',
        "        author = QAUTHOR;",
        "        VERSION_CONFIG;",
        "    };",
        "};",
        "",
        '#include "faction.hpp"',
        '#include "units.hpp"',
    ])

    fhpp = [
        "// THE 3DEN AND ZEUS NAME.",
        "//",
        "// Once a faction's loadouts are ours it is not the thing the mod shipped,",
        "// and a mission maker scrolling forty NATO variants has no way to tell",
        "// which ones we rebuilt. Everything we modify carries the jmfsb prefix;",
        "// everything we left alone keeps its own name, so the two are one glance",
        "// apart in the editor and in Zeus.",
        "//",
        "// NO BASE CLASS, AND THAT IS WHAT MAKES THIS SAFE. This merges into the",
        "// existing faction wherever it came from; if that mod is not loaded it",
        "// leaves an inert empty class instead of a broken config. Either way it",
        "// cannot break a load order.",
    ]
    if rename and rename != was:
        fhpp += ["//", "// RENAMED: was " + was + ". " + why + "."]
    fhpp += [
        "",
        "class CfgFactionClasses {",
        "    class " + cls + " {",
        '        displayName = "' + jmfsb_name + '";',
        "    };",
        "};",
    ]
    crlf(os.path.join(path, "faction.hpp"), fhpp)

    out = [
        "// " + cls + " - " + jmfsb_name,
        "// " + str(len(units)) + " unit(s), read from a live ORBAT dump.",
        "//",
    ]
    if fac.get("aka"):
        out += [
            "// ALSO SPELLED " + ", ".join(fac["aka"]) + " in unit configs. Config is",
            "// case-insensitive, so that is this same faction - the rosters are merged",
            "// here rather than split across two addons that would fight each other.",
            "//",
        ]
    out += [
        "// TO BUILD, against docs/faction_builder_handoff.md:",
        "//   tier " + str(tier) + " / strength " + str(strength) +
        " / shape " + str(shape) + " / flavor " + str(flavor),
        "//   " + why,
        "//",
        "// Nothing is overridden yet - this addon renames the faction and does not",
        "// touch a single unit. The roster below is what there is to work with.",
        "",
    ]
    by = {}
    for u in units:
        by.setdefault(u["vclass"] or "(no category)", []).append(u)
    for vc in sorted(by):
        out.append("// -- " + vc + " (" + str(len(by[vc])) + ") --")
        for u in sorted(by[vc], key=lambda x: x["cls"].lower()):
            out.append("//    " + u["cls"] + " | " + u["name"])
        out.append("//")
    crlf(os.path.join(path, "units.hpp"), out)

    readme = [
        "# " + name,
        "",
        "`jmfsb_" + comp + "`",
        "",
        "Faction `" + cls + "` - " + str(len(units)) +
        " unit(s), shown in 3DEN and Zeus as **" + jmfsb_name + "**.",
        "",
    ]
    if rename and rename != was:
        readme += ["Renamed from *" + was + "*. " + why + ".", ""]
    readme += [
        "| | |",
        "|---|---|",
        "| Tier | " + str(tier) + " |",
        "| Strength | " + str(strength) + " |",
        "| Shape | " + str(shape) + " |",
        "| Flavor | " + str(flavor) + " |",
        "",
        "Loadouts are not built yet: this addon renames the faction and changes",
        "nothing else. `units.hpp` carries the roster grouped by editor category.",
        "The build spec is `docs/faction_builder_handoff.md`; the classnames it",
        "draws from are `docs/weapon_pools_2040.md`.",
    ]
    crlf(os.path.join(path, "README.md"), readme)
    return comp, True


def write_docs(side, facs):
    mod = [f for f in facs if f["plan"] and not f["skip"]]
    skip = [f for f in facs if f["skip"]]
    unplanned = [f for f in facs if not f["plan"] and not f["skip"]]

    mod.sort(key=lambda f: (-f["plan"][0], -len(f["units"])))
    skip.sort(key=lambda f: -len(f["units"]))

    out = [
        "# Factions",
        "",
        "Generated by `tools/gen_faction_addons.py` - do not hand-edit. The tier",
        "table lives at the top of that script; re-run it after a change.",
        "",
        "Every faction we modify is rebuilt to `faction_builder_handoff.md` and is",
        "renamed **jmfsb <name>** in 3DEN and Zeus, so a modified faction is one",
        "glance apart from one we left alone. Factions we are not modifying get no",
        "addon and no config at all - they stay exactly as their own mod ships them.",
        "",
        "## " + side.upper() + " - modified (" + str(len(mod)) + ")",
        "",
        "| 3DEN / Zeus name | Faction class | Units | Tier | Str | Shape | Flavor | Note |",
        "|---|---|---:|:---:|:---:|---|---|---|",
    ]
    for f in mod:
        tier, strength, shape, flavor, rename, why = f["plan"]
        was = f["name"] or f["cls"]
        name = rename or was
        note = why + (" *(was " + was + ")*" if rename and rename != was else "")
        out.append("| **%s%s** | `%s` | %d | %s | %s | %s | %s | %s |" % (JMFSB_PREFIX,
            name, f["cls"], len(f["units"]), tier, strength, shape, flavor, note))

    out += [
        "",
        "## " + side.upper() + " - not modified (" + str(len(skip)) + ")",
        "",
        "No addon, no config, no rename. Left exactly as shipped.",
        "",
        "| Faction class | Name | Units | Why |",
        "|---|---|---:|---|",
    ]
    for f in skip:
        out.append("| `%s` | %s | %d | %s |" % (
            f["cls"], f["name"] or "", len(f["units"]), f["skip"]))

    if unplanned:
        out += [
            "",
            "## " + side.upper() + " - unassigned (" + str(len(unplanned)) + ")",
            "",
            "In the dump and on neither list. Needs a tier call.",
            "",
            "| Faction class | Name | Units |",
            "|---|---|---:|",
        ]
        for f in unplanned:
            out.append("| `%s` | %s | %d |" % (f["cls"], f["name"] or "", len(f["units"])))

    # West is the side in play, so it keeps the plain name that everything else
    # references. The staged sides get their own file each.
    name = "FACTIONS.md" if side == "west" else ("FACTIONS_%s.md" % side.upper())
    crlf(os.path.join(DOCS, name), out)
    return name, len(mod), len(skip), len(unplanned)


def main():
    global ADDONS
    ap = argparse.ArgumentParser()
    ap.add_argument("--side", default="west", choices=sorted(set(SIDES.values())))
    ap.add_argument("--force", action="store_true")
    # STAGING, NOT SHIPPING. work/ is not packed into a PBO, so a faction can be
    # scaffolded and read long before anybody decides it should build. Only the
    # factions actually in play live under addons/.
    ap.add_argument("--out", default=ADDONS,
                    help="where to write the addons (default addons/)")
    args = ap.parse_args()

    ADDONS = args.out
    if not os.path.isdir(ADDONS):
        os.makedirs(ADDONS)

    if not os.path.isfile(DATA):
        print("no %s - run the ORBAT dump and parse it first" % DATA)
        return 1

    facs = load(args.side)

    made = skipped = 0
    for f in facs:
        if f["skip"]:
            continue
        comp, wrote = write_addon(f, args.force)
        if wrote:
            made += 1
            print("  %-36s %s" % (comp,
                  "tier %s" % f["plan"][0] if f["plan"] else "UNASSIGNED"))
        else:
            skipped += 1

    doc, nmod, nskip, nun = write_docs(args.side, facs)
    print("")
    print("%d addon(s) written to %s, %d already existed" % (made, ADDONS, skipped))
    print("docs/%s: %d modified, %d not modified, %d unassigned" % (doc, nmod, nskip, nun))
    return 0


if __name__ == "__main__":
    sys.exit(main())
