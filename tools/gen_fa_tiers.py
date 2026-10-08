#!/usr/bin/env python3
"""Generate tier variants of the futureAmmo rounds.

    python tools/gen_fa_tiers.py

Writes addons/fa_tiers/, which carries a t4, t3 and t2 version of every FA round
that declares a lethality figure.

    tier 4   +6%   peer+, the edge nobody else has
    tier 3   as built - the FA round IS tier 3, so _t3 is an empty inherit
    tier 2   -12%
    tier 1,0 base game ammo - no FA round at all, so nothing is generated

WHAT SCALES, AND WHY ONLY THIS. hit, indirectHit, indirectHitRange and caliber
are what a round DOES - damage, splash, splash radius, penetration. Speed, drag
and the ACE bullet mass are what a round IS: scaling those changes the drop and
the lead, so a tier 2 rifleman would have to aim differently from a tier 4 one
with the same weapon. Tiers are meant to be a supply difference, not a
retraining exercise.

ONLY DECLARED PROPERTIES ARE TOUCHED. A round that inherits its `hit` from a
vanilla parent has no FA value to scale, and writing one would invent a number.

THE TIER 2 FLOOR IS CHECKED IN GAME, NOT HERE. "Never worse than base game"
needs vanilla's numbers, and vanilla's config is not readable from a text
editor - but it is readable from a running mission, where both configs exist
side by side. `#jmfsb fa.tiers` walks every generated t2 round, finds its
vanilla ancestor and reports any that came out weaker. That is the check; this
script cannot do it.

MAGAZINE WELLS. A tier magazine is a NEW CLASS, and a weapon knows its
magazines by name: magazines[] and CfgMagazineWells are matched on the class
name, and inheriting from FA_o_150Rnd_762x54_Box does not put _t4 in front of
the Zafir. So every generated magazine is written back into every well its base
magazine sits in (CfgMagazineWells.hpp, both halves) - without that a tier 4
rifleman spawns with eight magazines he cannot chamber, which is exactly what a
CSAT autorifleman did.

    python tools/gen_fa_tiers.py --wells-only

writes ONLY the wells files. The ammo and magazine files need the vanilla floor
(work/vanilla_ammo.json) to come out the same; the wells do not, so they can be
rebuilt on a machine without it.
"""
import collections
import io
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ADDONS = os.path.join(ROOT, "addons")
OUT = os.path.join(ADDONS, "fa_tiers")
VANILLA = os.path.join(ROOT, "work", "vanilla_ammo.json")

# FA ADDONS WHOSE MOD LEFT THE LOAD ORDER (2026-08-27: Aegis, Atlas, RHS, SPS).
# Not read, not tiered, not required. This matters more than it looks: every
# tier variant in fa_tiers_mods inherits from a round in one of these, and
# the PBO carried them ALL in requiredAddons with skipWhenMissingDependencies
# - so one absent mod dropped the whole of fa_tiers_mods, E22's and JCA's
# rounds with it, and every faction on a mod's rifle spawned with magazines
# that did not exist. The addons themselves still sit under addons/ as dead
# weight (their own requiredAddons keep them from loading); delete them when
# the reduction is done.
# AEGIS AND ATLAS CAME BACK on 2026-08-29 and their rounds are tiered again
# (user, 2026-08-30: "make sure all factions have future ammo"). Leaving
# them on this list is what left 2040 Russia carrying base-game 5.45: the
# only future build of the AK-12 magazine is fa_aegis's, and an untiered
# round is invisible to the faction generator, which only ever issues _t2
# / _t3 / _t4 classes.
# JCA'S WEAPON PACKS LEFT TOO (2026-10-02 - only JCA Land Systems and the ACEAX compat
# stay). fa_jca and fa_antidrone_jca skip themselves without them, and while they were
# required here they dropped fa_tiers_mods with them, and fa_tmt (Turkey's magazines)
# after it (RPT 2026-10-05).
DEAD = {"fa_rhs", "fa_sps", "fa_antidrone_rhs", "fa_jca", "fa_antidrone_jca"}
# REARMA IS NOT TIERED (2026-09-27). fa_rearma_cn/rus/us load only with the separate Rearma weapons mod
# (skipWhenMissingDependencies). Tiering them put all three in fa_tiers_mods' requiredAddons, so a load order
# without Rearma would drop fa_tiers_mods whole - every E22, JCA, EF, RF and Aegis tier round with it. They were
# never tiered before; if they are wanted, they need a tier addon of their own.
# fa_tmt carries its own _t2/_t3/_t4 (tools/gen_mod_factions.py) and REQUIRE
# fa_tiers_mods, so reading them here would be a dependency loop. fa_mcc and fa_mpp were
# never tiered, and tiering them would make MCC and MPP requirements of fa_tiers_mods.
# fa_tni and fa_adf (2026-10-06) carry their own tiers like fa_tmt (fa_minrf and fa_e22 went with the mods Russia used to build on).
UNTIERED = {"fa_rearma_cn", "fa_rearma_rus", "fa_rearma_us", "fa_tmt", "fa_tni", "fa_adf", "fa_mcc", "fa_mpp"}

# THE TIER 2 FLOOR, AND WHY IT IS ONLY ON PENETRATION.
#
# The rule was "tier 2 is -12%, but never worse than base game ammo". Measured
# against the real vanilla numbers (docs/AMMO_COMPARE.md) that is not
# satisfiable as written: futureAmmo sits BELOW vanilla on raw `hit` for much of
# the small-arms range ON PURPOSE - B_556x45_Ball is hit 9, FA's Mk327 HV is
# hit 8 with nearly triple the penetration. Clamping tier 2 up to the vanilla
# hit would make it hit HARDER than the tier 3 round it is meant to be a
# downgrade of.
#
# caliber is the property where FA genuinely leads - 393 rounds above vanilla
# against 69 below - so it is the one where a floor means something and cannot
# invert the tiers.
FLOOR_PROPS = ("caliber",)

# A round whose NATURE changed has no floor: FA_40mm_Mk384_MSmoke inherits a
# 40 mm HE grenade and does 0 damage because it is smoke. Comparing it to the
# grenade and "fixing" it would put an explosion back in a smoke round.
NATURE_CHANGED = ("smoke", "msmoke", "decoy", "emp", "ugs", "jammer", "flare",
                  "chaff", "carrier", "marker", "illum")

# What a round does, as opposed to what it is.
SCALED = ("hit", "indirectHit", "indirectHitRange", "caliber")

# TIER 3 IS THE ROUND AS BUILT, AND IS NAMED SO. It scales by 1.0 and carries
# an empty body - not a copy of the base figures, which would be a second place
# for them to drift apart. It exists because a name that follows the pattern is
# worth more than a variant saved: anything issuing ammunition can ask for
# X_t2 / X_t3 / X_t4 without knowing that one tier out of three is spelled
# differently from the other two.
TIERS = [("t4", 1.06), ("t3", 1.0), ("t2", 0.88)]

# [ 	]* rather than \s* for the indent: \s matches newlines, so a greedy
# leading \s* swallows blank lines between classes and the engine walks past
# openings it should have matched - which quietly found 165 of 495.
# The parent may be a macro - fa_aegis builds on EGVAR(weapons,<mag>) since the
# Aegis import - and a bare \w+ skipped those magazines without a word.
CLASS_OPEN = re.compile(r"^([ 	]*)class\s+(\w+)\s*:\s*(\w+(?:\([\w, ]*\))?)\s*\{", re.M)
PROP = re.compile(r"^\s*(\w+)\s*=\s*([0-9.]+)\s*;", re.M)
# ammo = "..." ANYWHERE A STATEMENT CAN START, not only at the head of a line.
# Requiring ^ meant every magazine written on one line was skipped silently -
# including FA_b_100Rnd_65x39_caseless_mag, the 6.5 machine gun belt, so the
# gunners kept vanilla ammunition while the riflemen were tiered.
AMMO_REF = re.compile(r'(?:^|[;{])\s*ammo\s*=\s*"([^"]+)"\s*;', re.M)


# ---------------------------------------------------------------------------
# ONLY SMALL ARMS ARE TIERED
# ---------------------------------------------------------------------------
# A tier is a supply difference in what a rifleman is issued. It is not a
# reason to make a Titan warhead or a 120mm APFSDS weaker, and a tiered missile
# is a mission that fails for a reason nobody can see. Cannon, missiles,
# rockets, mortars and 40mm grenades keep exactly the figures their mod ships.
#
# THE TEST IS THE VANILLA ANCESTOR, not the FA name. Every FA round is followed
# up its own inheritance chain to the first class that is not an FA class -
# B_556x45_Ball, B_65x39_Caseless and the rest - and only a bullet is tiered.
# Autocannon rounds are B_30mm_HE and B_35mm_AA, which carry no _Ball or
# _Caseless suffix and so fall out on the same rule.
#
# Anything excluded is COUNTED AND PRINTED by base class, so a nature that
# should have been tiered cannot go missing quietly.
SMALL_ARMS = re.compile(r"^B_\w*?(_Ball|_Caseless)(_F)?$")


def top_level_classes(text):
    """Yield (name, base, body) for classes one level inside the root block.

    Brace counting rather than a regex: FA ammo classes carry nested blocks -
    CamShakeFire, sounds, the ACE frag tables - and a regex that stops at the
    first `};` claims those as the end of the class.
    """
    out = []
    for m in CLASS_OPEN.finditer(text):
        indent, name, base = m.group(1), m.group(2), m.group(3)
        # root-level entries sit at 0; we want the ones one level in
        if len(indent.expandtabs(4)) == 0:
            continue
        i = m.end()
        depth = 1
        while i < len(text) and depth:
            if text[i] == "{":
                depth += 1
            elif text[i] == "}":
                depth -= 1
            i += 1
        out.append((name, base, text[m.end():i - 1]))
    return out



def root_blocks(text, root):
    """Every `class <root> { ... }` body in a file, concatenated.

    THE ROOT CLASS IS THE DISCRIMINATOR, NOT THE FILENAME. futureAmmo spreads
    its definitions over CfgAmmo.hpp, CfgAmmo_compat.hpp, CfgMag65_matrix.hpp
    and CfgMagazines_compat.hpp - and CfgMag65_matrix.hpp does not contain the
    word "magazine" anywhere in its name. Splitting on filenames read 394
    magazines as ammunition; asking which block a class sits in cannot.
    """
    out = []
    for m in re.finditer(r"^[ \t]*class\s+" + root + r"\s*\{", text, re.M):
        depth, j = 1, m.end()
        while j < len(text) and depth:
            if text[j] == "{":
                depth += 1
            elif text[j] == "}":
                depth -= 1
            j += 1
        out.append(text[m.end():j - 1])
    return chr(10).join(out)


def scaled_props(body):
    """Declared lethality figures, as {name: value}. Nested blocks excluded."""
    flat = re.sub(r"\{[^{}]*\}", "", body)
    found = {}
    for k, v in PROP.findall(flat):
        if k in SCALED:
            try:
                found[k] = float(v)
            except ValueError:
                pass
    return found


def fmt(v):
    r = round(v, 4)
    return str(int(r)) if r == int(r) else ("%.4f" % r).rstrip("0").rstrip(".")


HDR_AMMO = [
    "// TIER VARIANTS OF THE FUTUREAMMO ROUNDS.",
    "//",
    "//   _t4   +6%    peer+, the edge nobody else has",
    "//   _t3   as built - the FA round IS tier 3, so this is an empty inherit",
    "//   _t2   -12%",
    "//   t1/t0 base game ammo, so nothing is generated for them",
    "//",
    "// ONLY SMALL ARMS. A tier is a supply difference in what a rifleman is",
    "// issued, not a reason to weaken a Titan warhead or a 120mm APFSDS.",
    "//",
    "// Generated by tools/gen_fa_tiers.py - re-run rather than hand-edit.",
    "",
]

HDR_MAG = [
    "// The magazine for each tier variant, pointing at the tiered round.",
    "// Generated by tools/gen_fa_tiers.py - re-run rather than hand-edit.",
    "",
]


def can_skip(addon_dir):
    """True if this fa_* addon drops out when its third-party mod is absent.

    Read from the addon rather than listed here: the set changes whenever a
    new source is ported, and a hand-kept list is one somebody forgets.
    """
    cfg = os.path.join(ADDONS, addon_dir, "config.cpp")
    if not os.path.isfile(cfg):
        return False
    for line in io.open(cfg, encoding="utf-8", errors="replace"):
        t = line.strip()
        if t.startswith("//"):
            continue
        if "skipWhenMissingDependencies" in t:
            return True
    return False


# ONE TIER ADDON PER OPTIONAL SOURCE. Aegis's keeps the old name, fa_tiers_mods,
# which the faction generators and older missions already name; every other
# optional source gets fa_tiers_<source>, e.g. fa_ef -> fa_tiers_ef.
MODS_SOURCE = "aegis"


def TIER_ADDON(half):
    return "fa_tiers" if half == "core" else "fa_tiers_mods" if half == MODS_SOURCE else "fa_tiers_" + half


WELLS_ONLY = "--wells-only" in sys.argv[1:]


def main():
    # "core" is everything whose source addon always loads. Everything whose
    # source can vanish with its third-party mod is grouped BY THAT SOURCE, one
    # tier addon each (group(), below): one addon over two optional sources
    # either drops both when one is absent - Aegis's AK-12 tiers going with
    # the EF DLC - or, without the requirement, loads tiers whose parents are
    # gone (RPT 2026-10-06: every FA_EF_..._t2 "No entry", scope=private).
    ammo_out = collections.defaultdict(list)
    mag_out = collections.defaultdict(list)
    ammo_ext = collections.defaultdict(list)
    mag_ext = collections.defaultdict(list)
    mag_names = collections.defaultdict(list)
    need = collections.defaultdict(set)
    ammo_group = {}
    OPTIONAL = set()
    n_ammo = n_mag = 0
    tiered = set()
    skipped_nature = {}
    clamped = []

    vanilla = {}
    if os.path.isfile(VANILLA):
        vanilla = json.load(io.open(VANILLA, encoding="utf-8"))
    else:
        print("WARNING: no %s - tier 2 generated with NO floor" % VANILLA)

    # Every FA ammo class and what it declares, before any resolution.
    declared = {}
    bases = {}
    # Which addon defines each class. Two things need this: the external
    # declarations, and requiredAddons - a tier variant that loads before the
    # round it inherits from gets no parent at all.
    home = {}
    for d in sorted(os.listdir(ADDONS)):
        if not d.startswith("fa_") or d.startswith("fa_tiers") or d in DEAD or d in UNTIERED:
            continue
        if can_skip(d):
            OPTIONAL.add("jmfsb_" + d)
        # EVERY .hpp, NOT CfgAmmo.hpp. futureAmmo splits its definitions -
        # CfgAmmo_compat.hpp carries 435 more ammo classes, CfgMag65_matrix.hpp
        # and CfgMagazines_compat.hpp another 1528 magazines between them.
        # Reading one filename tiered a fraction of the mod and reported success.
        for f in sorted(os.listdir(os.path.join(ADDONS, d))):
            if not f.lower().endswith(".hpp"):
                continue
            p = os.path.join(ADDONS, d, f)
            text = root_blocks(io.open(p, encoding="utf-8", errors="replace").read(), "CfgAmmo")
            for name, base, body in top_level_classes(chr(10) + text):
                if not name.startswith("FA_"):
                    continue
                declared.setdefault(name, {})
                declared[name].update(scaled_props(body))
                bases.setdefault(name, base)
                home.setdefault(name, "jmfsb_" + d)

    def group(addon):
        return addon[len("jmfsb_fa_"):] if addon in OPTIONAL else "core"

    # RESOLVE UP THE FA CHAIN. A tracer variant declares a colour and nothing
    # else - FA_b_556_Mk327_HV_T_Red inherits every lethality figure from
    # FA_b_556_Mk327_HV. Scaling only what a class declares would tier the plain
    # round and leave all seven of its tracer colours at full strength, which is
    # most of the ammunition in the mod.
    #
    # The walk stops at the first ancestor outside FA: a vanilla parent's value
    # is not ours to scale, and inventing one is how a tier 2 round ends up
    # weaker than the base game.
    def resolve(name, seen=None):
        seen = seen or set()
        if name in seen or name not in declared:
            return {}
        seen.add(name)
        out = dict(resolve(bases.get(name, ""), seen))
        out.update(declared[name])
        return out

    for name in sorted(declared):
        props = resolve(name)
        if not props:
            continue
        anc = name
        while anc in bases:
            anc = bases[anc]

        # NOT A BULLET, NOT TIERED - see SMALL_ARMS above.
        if not SMALL_ARMS.match(anc):
            skipped_nature[anc] = skipped_nature.get(anc, 0) + 1
            continue

        floor = vanilla.get(anc, {})
        exempt = any(t in name.lower() for t in NATURE_CHANGED)

        # EVERY PARENT MUST BE DECLARED EXTERNAL. These rounds live in the
        # other fa_* addons, not here. A config that inherits from a name it
        # never mentions does not build (HEMTT L-C04), and at runtime would
        # produce a class with no parent and none of the inherited figures.
        half = group(home.get(name))
        ammo_group[name] = half
        ammo_ext[half].append(name)
        if name in home:
            need[half].add(home[name])

        for suffix, mult in TIERS:
            if mult == 1.0:
                # Tier 3 changes nothing, so it states nothing.
                ammo_out[half].append("    class %s_%s: %s {};" % (name, suffix, name))
                n_ammo += 1
                continue
            ammo_out[half].append("    class %s_%s: %s {" % (name, suffix, name))
            for k in SCALED:
                if k not in props:
                    continue
                v = props[k] * mult
                # Only tier 2 has a floor; tier 4 is an increase and cannot dip.
                if mult < 1 and k in FLOOR_PROPS and not exempt and k in floor:
                    if v < floor[k]:
                        v = floor[k]
                        clamped.append((name, k, props[k], floor[k]))
                ammo_out[half].append("        %s = %s;" % (k, fmt(v)))
            ammo_out[half].append("    };")
            n_ammo += 1
        tiered.add(name)

    for d in sorted(os.listdir(ADDONS)):
        if not d.startswith("fa_") or d.startswith("fa_tiers") or d in DEAD or d in UNTIERED:
            continue
        # Same again: the magazines are spread over several files.
        for f in sorted(os.listdir(os.path.join(ADDONS, d))):
            if not f.lower().endswith(".hpp"):
                continue
            p = os.path.join(ADDONS, d, f)
            text = root_blocks(io.open(p, encoding="utf-8", errors="replace").read(), "CfgMagazines")
            for name, base, body in top_level_classes(chr(10) + text):
                if not name.startswith("FA_"):
                    continue
                hit = AMMO_REF.search(re.sub(r"\{[^{}]*\}", "", body))
                if not hit or hit.group(1) not in tiered:
                    continue
                mhalf = group("jmfsb_" + d)
                ahalf = ammo_group[hit.group(1)]
                if mhalf == "core" and ahalf != "core":
                    # A core magazine on an optional round goes with the round.
                    mhalf = ahalf
                if ahalf not in ("core", mhalf):
                    # Its tier rounds live in another optional source's tier addon.
                    need[mhalf].add("jmfsb_" + TIER_ADDON(ahalf))
                mag_ext[mhalf].append(name)
                need[mhalf].add("jmfsb_" + d)
                for suffix, _ in TIERS:
                    mag_out[mhalf].append("    class %s_%s: %s {" % (name, suffix, name))
                    mag_out[mhalf].append('        ammo = "%s_%s";' % (hit.group(1), suffix))
                    mag_out[mhalf].append("    };")
                    n_mag += 1
                mag_names[mhalf].append(name)

    # WELLS. Every fa_* addon's CfgMagazinewells.hpp says which wells its
    # magazines sit in; a tier variant goes wherever its base magazine went.
    # Matched by name, which is what the engine does - see the docstring.
    well_of = {}
    for d in sorted(os.listdir(ADDONS)):
        if not d.startswith("fa_") or d.startswith("fa_tiers") or d in DEAD or d in UNTIERED:
            continue
        for f in sorted(os.listdir(os.path.join(ADDONS, d))):
            if f.lower() != "cfgmagazinewells.hpp":
                continue
            text = io.open(os.path.join(ADDONS, d, f), encoding="utf-8", errors="replace").read()
            text = re.sub(r"//[^\n]*", "", text)
            text = re.sub(r"/\*.*?\*/", "", text, flags=re.S)
            for m in re.finditer(r"class\s+(\w+)\s*\{", text):
                well = m.group(1)
                if well.lower() == "cfgmagazinewells":
                    continue
                i = m.end(); depth = 1
                while i < len(text) and depth:
                    depth += (text[i] == "{") - (text[i] == "}")
                    i += 1
                for mag in re.findall(r'"([A-Za-z0-9_]+)"', text[m.end():i]):
                    well_of.setdefault(mag, [])
                    if well not in well_of[mag]:
                        well_of[mag].append(well)
    wells_out = collections.defaultdict(dict)
    n_well_mags = 0
    for half in list(mag_names):
        for name in mag_names[half]:
            for well in well_of.get(name, []):
                lst = wells_out[half].setdefault(well, [])
                for suffix, _ in TIERS:
                    lst.append("%s_%s" % (name, suffix))
                    n_well_mags += 1

    B = chr(92)

    def emit(half, addon, beaut, optional):
        """Write one of the two tier addons."""
        out = os.path.join(ADDONS, addon)
        if not os.path.isdir(out):
            os.makedirs(out)

        def w(fn, lines):
            io.open(os.path.join(out, fn), "w", encoding="utf-8",
                    newline="\r\n").write("\n".join(lines) + "\n")

        wl = [
            "// Generated by tools/gen_fa_tiers.py - re-run rather than hand-edit.",
            "//",
            "// A TIER MAGAZINE IS A NEW CLASS, AND A WEAPON KNOWS ITS MAGAZINES BY",
            "// NAME. Inheriting from FA_o_150Rnd_762x54_Box makes _t4 look like the",
            "// belt and hit like the belt; it does not make the Zafir load it -",
            "// magazines[] and CfgMagazineWells are matched on the class name, and",
            "// neither had heard of a _t4. Every tier variant goes back into the",
            "// wells its base magazine sits in, so a tier 4 rifleman is not carrying",
            "// eight magazines he cannot chamber.",
            "class CfgMagazineWells {",
        ]
        for well in sorted(wells_out[half]):
            wl += ["    class %s {" % well, "        ADDON[] += {"]
            mags = wells_out[half][well]
            wl += ['            "%s"%s' % (m, "," if i < len(mags) - 1 else "") for i, m in enumerate(mags)]
            wl += ["        };", "    };"]
        wl.append("};")
        w("CfgMagazineWells.hpp", wl)

        if WELLS_ONLY:
            # The ammo and magazine files stay as they were built, floor and
            # all; only the include is guaranteed, in case config.cpp predates
            # the wells file.
            cp = os.path.join(out, "config.cpp")
            ct = io.open(cp, encoding="utf-8", newline="").read()
            if "CfgMagazineWells.hpp" not in ct:
                ct = ct.replace('#include "CfgMagazines.hpp"', '#include "CfgMagazines.hpp"\r\n#include "CfgMagazineWells.hpp"')
                io.open(cp, "w", encoding="utf-8", newline="").write(ct)
            return len(need[half])

        base = set(["jmfsb_main", "jmfsb_fa_main", "cba_xeh"])
        if optional:
            # ITS MAGAZINES POINT AT THE CORE HALF'S AMMO. A JCA magazine
            # carries an FA_b_ round that lives in fa_tiers, so that has to be
            # loaded and tiered first.
            base.add("jmfsb_fa_tiers")
        req = sorted(base | need[half])
        quoted = [chr(34) + a + chr(34) for a in req]

        w("$PBOPREFIX$", ["z" + B + "jmfsb" + B + "addons" + B + addon])
        w("script_component.hpp", [
            "#define COMPONENT " + addon,
            "#define COMPONENT_BEAUTIFIED " + beaut,
            '#include "' + B + "z" + B + "jmfsb" + B + "addons" + B + "main" + B + 'script_mod.hpp"',
            "",
            "// #define DEBUG_MODE_FULL",
            "",
            '#include "' + B + "z" + B + "jmfsb" + B + "addons" + B + "main" + B + 'script_macros.hpp"',
        ])

        head = [
            '#include "script_component.hpp"',
            "",
            "class CfgPatches {",
            "    class ADDON {",
            "        name = COMPONENT_NAME;",
            "        units[] = {};",
            "        weapons[] = {};",
            "        requiredVersion = REQUIRED_VERSION;",
        ]
        if optional:
            head += [
                "        // THE ROUNDS WHOSE SOURCE CAN VANISH. Its one source addon drops",
                "        // itself when its mod or DLC is absent, so this one drops with",
                "        // it, and takes only the tiers for rounds that are not there either.",
                "        requiredAddons[] = {" + ", ".join(quoted) + "};",
                "        skipWhenMissingDependencies = 1;",
            ]
        else:
            head += [
                "        // THE ROUNDS THAT ARE ALWAYS THERE. Not one addon below can skip",
                "        // itself, so this states its dependencies honestly and loads",
                "        // cleanly on any mod set. The mod-sourced tiers live in",
                "        // jmfsb_fa_tiers_mods, which is allowed to disappear.",
                "        //",
                "        // Splitting them is what ended two failures at once: one tier",
                "        // addon requiring fa_rhs either cascaded a skip - deleting every",
                "        // tier magazine when RHS was absent - or warned about an unmet",
                "        // dependency on every start.",
                "        requiredAddons[] = {" + ", ".join(quoted) + "};",
            ]
        head += [
            "        author = QAUTHOR;",
            "        VERSION_CONFIG;",
            "    };",
            "};",
            "",
        ]
        if not optional:
            # THE CORE HALF OWNS THE XEH CHAIN. XEH_preInit compiles
            # fnc_checkFloor and XEH_postInit registers `#jmfsb fa.tiers`;
            # without this include every one of them is dead code that ships
            # and never runs.
            head.append('#include "CfgEventHandlers.hpp"')
        head += [
            '#include "CfgAmmo.hpp"',
            '#include "CfgMagazines.hpp"',
            '#include "CfgMagazineWells.hpp"',
        ]
        w("config.cpp", head)

        w("CfgAmmo.hpp", HDR_AMMO + [
            "class CfgAmmo {",
            "    // ---- EXTERNAL. Defined by the fa_* addons named in requiredAddons,",
            "    // ---- declared here so the tier variants below have a parent.",
        ] + ["    class %s;" % c for c in sorted(set(ammo_ext[half]))]
          + [""] + ammo_out[half] + ["};"])

        w("CfgMagazines.hpp", HDR_MAG + [
            "class CfgMagazines {",
            "    // ---- EXTERNAL, as above.",
        ] + ["    class %s;" % c for c in sorted(set(mag_ext[half]))]
          + [""] + mag_out[half] + ["};"])

        return len(req)

    n_core = emit("core", "fa_tiers", "Future Ammunition - Tiers", False)
    n_opt = {}
    for half in sorted(set(ammo_out) | set(mag_out)):
        if half != "core":
            n_opt[half] = emit(half, TIER_ADDON(half), "Future Ammunition - Tiers (%s)" % half, True)

    if skipped_nature:
        tot = sum(skipped_nature.values())
        print("%d round(s) left untiered - not small arms:" % tot)
        for k, v in sorted(skipped_nature.items(), key=lambda x: -x[1]):
            print("    %-34s %4d" % (k, v))
    print("%d ammo class(es) tiered" % len(tiered))
    print("%d tier magazine(s) registered in %d well(s)%s"
          % (n_well_mags, len(wells_out["core"]) + len(wells_out["mods"]),
             " - wells only, ammo and magazines untouched" if WELLS_ONLY else ""))
    print("  fa_tiers       %5d ammo  %5d magazine  %2d requiredAddons"
          % (len(ammo_out["core"]), len(mag_out["core"]) // 3, n_core))
    for half in sorted(n_opt):
        print("  %-14s %5d ammo  %5d magazine  %2d requiredAddons"
              % (TIER_ADDON(half), len(ammo_out[half]), len(mag_out[half]) // 3, n_opt[half]))
    if clamped:
        print("%d tier 2 value(s) across %d round(s) clamped to the base game floor"
              % (len(clamped), len(set(c[0] for c in clamped))))
    # THE TIER MAGAZINES' NAMES. Written above with no displayName of their own, a base round and its
    # three tiers read identically in the arsenal; tools/fa_names.py gives every FA magazine its
    # "[JMSB] <rounds> <calibre> <load> (<magazine>) - <variant>" name, these included.
    import fa_names
    fa_names.main()
    return 0


if __name__ == "__main__":
    sys.exit(main())
