#!/usr/bin/env python3
"""Future Ammunition in the MCC rifles' and the MPP pistols' own magazines.

    python tools/gen_fa_mcc.py [--src D:/work/mcc] [--fa D:/Git/futureAmmo]

Writes addons/fa_mcc and addons/fa_mpp here, and the same two as addons/mcc and
addons/mpp in the futureAmmo repo (user, 2026-10-04: "add mags from these mods
with future ammo, also copy that ammo and mags to D:/Git/futureAmmo").

THE fa_jca PATTERN. Every magazine LOOK the mod ships - a PMAG, an EMAG, a
Glock stick - gets one copy per FA round of its calibre, plain and in each
tracer colour, inheriting the mod's own class so it keeps the model, picture,
count and mass. Each copy goes into every well the mod puts that look in, so
anything that takes the mod's magazine takes ours.

A LOOK IS A CLASS THAT DRAWS ITSELF. MCC derives every ammo type from one body
(MCC_PMAG_556_556_30_M855 is the black PMAG; M855A1, Mk262 ... inherit it), so
a body is a class that sets its own picture or model. Copying the descendants
would be one PMAG twelve times over.

ONLY CALIBRES FA HAS ROUNDS FOR. 6.8 SPC, 6 ARC and 6.5x43 got rounds of their own
in fa_extracal for this (2026-10-04); .22 LR has none and was not wanted, so its
magazines get nothing rather than a round of the wrong calibre.

THE TWO MODS STAY APART. One addon each, each skipped whole when its mod is
absent (skipWhenMissingDependencies), so a server with only the pistols still
gets the pistols' magazines.
"""
import argparse
import os
import re

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TRACERS = ["Red", "Yellow", "Green", "White", "Blue", "Orange", "IR"]

# calibre -> the FA rounds a magazine of it is filled with (base classes; the
# tracer classes are found from these)
ROUNDS = {
    "556": ["FA_b_556_Mk327_HV", "FA_b_556_XM891_CTEP", "FA_b_556_Mk332_AP"],
    "300": ["FA_b_300_Mk335", "FA_b_300_Mk336", "FA_b_300_Mk337", "FA_b_300_Mk342_Sub",
            "FA_b_300_Mk343_Sub", "FA_b_300_Mk341_SubAP", "FA_b_300_XM345_SubAP2"],
    "762x39": ["FA_o_762x39_7N43", "FA_o_762x39_7N47_CT", "FA_o_762x39_7U4_Sub"],
    "545": ["FA_o_545x39_7N44_HP", "FA_o_545x39_7N48_CT", "FA_o_545x39_7U5_SubAP"],
    "762x51": ["FA_b_762_M80A2_HV", "FA_b_762_XM751_CTEP"],
    "9x19": ["FA_rf_9x19_Mk422_AP"],
    "57": ["FA_b_ammo_57_Mk430", "FA_b_ammo_57_Mk431"],
    "45": ["FA_b_45ACP_Mk421_SubAP"],
    # specified for MCC (user, 2026-10-04) - fa_extracal
    "68": ["FA_b_68_Mk334_TC"],
    "6arc": ["FA_b_6ARC_Mk333_LR", "FA_b_6ARC_XM895_CTEP"],
    "65x43": ["FA_b_65x43_Mk331_EPR", "FA_b_65x43_XM894_CTEP"],
}


def calibre_of_well(w):
    lw = w.lower()
    if "556x45" in lw: return "556"
    if "300blk" in lw: return "300"
    if "762x39" in lw: return "762x39"
    if "545x39" in lw: return "545"
    if "762x51" in lw: return "762x51"
    if "9x19" in lw: return "9x19"
    if "57x28" in lw: return "57"
    if "45acp" in lw: return "45"
    if "68spc" in lw: return "68"
    if "6x38" in lw: return "6arc"
    if "65x43" in lw: return "65x43"
    return None


def strip_comments(t):
    t = re.sub(r"/\*.*?\*/", "", t, flags=re.S)
    return re.sub(r"//[^\n]*", "", t)


def classes(text):
    """Every class with a body: name -> (parent, body text). Nested bodies are
    kept inside their parent's text; magazines and wells are flat enough."""
    out = {}
    for m in re.finditer(r"class\s+(\w+)\s*(?::\s*(\w+))?\s*\{", text):
        i, depth = m.end(), 1
        while i < len(text) and depth:
            depth += {"{": 1, "}": -1}.get(text[i], 0)
            i += 1
        out[m.group(1)] = (m.group(2), text[m.end():i - 1])
    return out


def prop(body, key):
    # anywhere in the body - FA writes many classes on one line ({ a = 1; b = 2; })
    m = re.search(r"(?i)(?:^|[\s;{])%s\s*=\s*(\"[^\"]*\"|[^;]+);" % key, body)
    return m.group(1).strip().strip('"') if m else None


def read_tree(paths):
    allc = {}
    for p in paths:
        allc.update(classes(strip_comments(open(p, encoding="utf-8", errors="replace").read())))
    return allc


def resolve(allc, name, key, seen=0):
    while name in allc and seen < 30:
        parent, body = allc[name]
        v = prop(body, key)
        if v is not None:
            return v
        name, seen = parent, seen + 1
    return None


def fa_index():
    """Every FA ammo class and the addon that defines it, and each base round's
    magazine facts - nature name and muzzle velocity - off FA's own magazines,
    wherever they live (5.45's are with the Russian rearm, not in fa_ammo)."""
    ammo, facts = {}, {}
    adir = os.path.join(ROOT, "addons")
    for a in sorted(os.listdir(adir)):
        if not a.startswith("fa_") or a in ("fa_mcc", "fa_mpp") or a.startswith("fa_tiers"):
            continue
        p = os.path.join(adir, a, "CfgAmmo.hpp")
        if os.path.exists(p):
            for c in re.findall(r"(?m)^\s*class\s+(FA_\w+)\s*:", open(p, encoding="utf-8").read()):
                ammo.setdefault(c, a)
    for a in sorted(os.listdir(adir)):
        p = os.path.join(adir, a, "CfgMagazines.hpp")
        if not a.startswith("fa_") or a in ("fa_mcc", "fa_mpp") or a.startswith("fa_tiers") or not os.path.exists(p):
            continue
        mags = classes(strip_comments(open(p, encoding="utf-8").read()))
        for name, (parent, body) in mags.items():
            am = prop(body, "ammo")
            if not am or am in facts or re.search(r"_T_\w+$", am):
                continue
            dn = re.sub(r"^\[JMSB\]\s*\d+Rnd\s*", "", prop(body, "displayName") or "")
            facts[am] = {"nature": prop(body, "descriptionShort") or dn or am,
                         "initSpeed": resolve(mags, name, "initSpeed")}
    # A round no FA magazine carries yet - the ones made for MCC - is named and
    # timed off its own ammo class instead.
    for a in sorted(os.listdir(adir)):
        p = os.path.join(adir, a, "CfgAmmo.hpp")
        if not a.startswith("fa_") or not os.path.exists(p):
            continue
        for name, (_parent, body) in classes(strip_comments(open(p, encoding="utf-8").read())).items():
            if name.startswith("FA_") and name not in facts and not re.search(r"_T_\w+$", name):
                dn, spd = prop(body, "displayName"), prop(body, "typicalSpeed")
                if dn and spd:
                    facts[name] = {"nature": dn, "initSpeed": spd}
    return ammo, facts

def wells_of(paths):
    """well -> magazines the mod puts in it."""
    out = {}
    for p in paths:
        for name, (_parent, body) in classes(strip_comments(open(p, encoding="utf-8", errors="replace").read())).items():
            mags = re.findall(r'"([^"]+)"', body)
            if mags and not name.lower().startswith("cfg"):
                out.setdefault(name, set()).update(mags)
    return out


def build(src_mags, src_wells, tag, mod_patch, ammo, facts):
    """The copies for one mod: (magazine blocks, well -> copies, required FA addons, body count)."""
    allc = read_tree(src_mags)
    wells = wells_of(src_wells)
    # a magazine's wells, and so its calibre
    mag_wells = {}
    for w, mags in wells.items():
        for m in mags:
            mag_wells.setdefault(m, set()).add(w)
    # descendants, to give a body the wells its children are listed in
    kids = {}
    for n, (p, _b) in allc.items():
        kids.setdefault(p, []).append(n)

    def family(n):
        out, todo = [], [n]
        while todo:
            x = todo.pop()
            out.append(x)
            todo += [k for k in kids.get(x, []) if not (prop(allc[k][1], "picture") or prop(allc[k][1], "modelSpecial") or prop(allc[k][1], "model"))]
        return out

    blocks, into, need, bodies = [], {}, set(), []

    def depth(n):
        d = 0
        while n in allc and d < 30:
            n, d = allc[n][0], d + 1
        return d

    # A LOOK IS WHAT YOU SEE - picture, model and capacity in one calibre - not
    # a class: MCC's FDE line sets its picture again on every ammo type, so a
    # class-per-look count was one FDE PMAG nine times. Group, keep the
    # shallowest class of each look, and give it the wells of the whole group.
    looks = {}
    for name, (_parent, body) in allc.items():
        if not (prop(body, "picture") or prop(body, "modelSpecial") or prop(body, "model")):
            continue
        if resolve(allc, name, "scope") == "0":
            continue
        ws = set()
        for f in family(name):
            ws |= mag_wells.get(f, set())
        cals = {calibre_of_well(w) for w in ws} - {None}
        if len(cals) != 1:
            continue
        cal = cals.pop()
        count = resolve(allc, name, "count") or "30"
        key = (resolve(allc, name, "picture"), resolve(allc, name, "modelSpecial") or resolve(allc, name, "model"), count, cal)
        if key not in looks or depth(name) < depth(looks[key][0]):
            prev = looks.get(key, (None, set()))[1]
            looks[key] = (name, prev | ws)
        else:
            looks[key][1].update(ws)

    for (pic, mdl, count, cal), (name, ws) in sorted(looks.items(), key=lambda kv: kv[1][0]):
        look = (resolve(allc, name, "displayname") or resolve(allc, name, "displayName") or name)
        # the look, not the round the mod loaded it with: "30rd 5.56 PMAG G3 M855" -> "30rd 5.56 PMAG G3"
        dshort = resolve(allc, name, "displaynameshort") or resolve(allc, name, "displayNameShort") or ""
        if dshort and look.endswith(dshort):
            look = look[:-len(dshort)].strip()
        bodies.append(name)
        copies = []
        for rnd in ROUNDS[cal]:
            if rnd not in ammo or rnd not in facts:
                continue
            if ammo[rnd] != "fa_ammo":
                need.add(ammo[rnd])
            nature, speed = facts[rnd]["nature"], facts[rnd]["initSpeed"]
            short = re.sub(r"^FA_(b_ammo_|o_ammo_|b_|o_|rf_|i_)", "", rnd)
            for tr in [None] + TRACERS:
                am = rnd if tr is None else "%s_T_%s" % (rnd, tr)
                if am not in ammo:
                    continue
                cls = "FA_%s_%s_%s%s" % (tag, re.sub(r"^(MCC|MPP)_", "", name), short, "" if tr is None else "_T_" + tr)
                dn = "[JMSB] %sRnd %s%s" % (count, nature, "" if tr is None else " %s Tracer" % tr)
                lines = ["    class %s: %s {" % (cls, name),
                         "        author = QAUTHOR;",
                         '        displayName = "%s";' % dn,
                         '        displayNameShort = "%s";' % nature,
                         '        descriptionShort = "%s<br/>In the %s";' % (nature, look.replace('"', "'")),
                         '        ammo = "%s";' % am]
                if speed:
                    lines.append("        initSpeed = %s;" % speed)
                if tr is not None:
                    lines.append("        tracersEvery = 4;")
                lines.append("    };")
                blocks.append("\n".join(lines))
                copies.append(cls)
        for w in sorted(ws):
            into.setdefault(w, []).extend(copies)
    return blocks, into, need, bodies


def write_addon(dst, comp, beaut, mod_prefix, mod_patch, blocks, into, need, bodies):
    os.makedirs(dst, exist_ok=True)
    fa = "jmfsbfa_" if mod_prefix == "jmfsbfa" else "jmfsb_fa_"
    req = ['"cba_main"', '"ace_ballistics"', '"%sammo"' % fa] + ['"%s%s"' % (fa, n.replace("fa_", "")) for n in sorted(need) if n != "fa_ammo"] + ['"%s"' % mod_patch]
    mags = [b.split("class ", 1)[1].split(":", 1)[0] for b in blocks]

    def w(name, text):
        with open(os.path.join(dst, name), "w", encoding="utf-8", newline="\n") as fh:
            fh.write(text)

    w("$PBOPREFIX$", "z\\%s\\addons\\%s\n" % (mod_prefix, comp))
    w("script_component.hpp", "\n".join([
        "#define COMPONENT %s" % comp,
        "#define COMPONENT_BEAUTIFIED %s" % beaut,
        '#include "\\z\\%s\\addons\\%s\\script_mod.hpp"' % (mod_prefix, "fa_main" if mod_prefix == "jmfsb" else "main"),
        "",
        "// #define DEBUG_MODE_FULL",
        "// #define DISABLE_COMPILE_CACHE",
        "",
        "#ifdef DEBUG_ENABLED_%s" % comp.upper(),
        "    #define DEBUG_MODE_FULL",
        "#endif",
        "#ifdef DEBUG_SETTINGS_%s" % comp.upper(),
        "    #define DEBUG_SETTINGS DEBUG_SETTINGS_%s" % comp.upper(),
        "#endif",
        "",
        '#include "\\z\\%s\\addons\\%s\\script_macros.hpp"' % (mod_prefix, "fa_main" if mod_prefix == "jmfsb" else "main"),
        ""]))
    w("config.cpp", "\n".join([
        '#include "script_component.hpp"',
        "",
        "// Generated by tools/gen_fa_mcc.py (jmfsb) - re-run rather than hand-edit.",
        "class CfgPatches {",
        "    class ADDON {",
        "        name = COMPONENT_NAME;",
        "        units[] = {};",
        "        weapons[] = {};",
        "        requiredVersion = REQUIRED_VERSION;",
        "        requiredAddons[] = {%s};" % ", ".join(req),
        "        skipWhenMissingDependencies = 1;",
        "        author = QAUTHOR;",
        "        VERSION_CONFIG;",
        "        magazines[] = {",
        ",\n".join('            "%s"' % m for m in mags),
        "        };",
        "    };",
        "};",
        "",
        '#include "CfgMagazines.hpp"',
        '#include "CfgMagazineWells.hpp"',
        ""]))
    w("CfgMagazines.hpp", "\n".join(
        ["// Generated by tools/gen_fa_mcc.py - re-run rather than hand-edit.",
         "// One copy of each of the mod's magazine looks per FA round of its calibre,",
         "// plain and in every tracer colour; inheriting keeps the model, picture,",
         "// count and mass.",
         "class CfgMagazines {"] + ["    class %s;" % b for b in bodies] + [""] + blocks + ["};", ""]))
    wl = ["// Generated by tools/gen_fa_mcc.py - re-run rather than hand-edit.",
          "// Every copy goes into every well its look is in, so whatever takes the",
          "// mod's magazine takes ours.",
          "class CfgMagazineWells {"]
    for well in sorted(into):
        if not into[well]:
            continue
        wl.append("    class %s {" % well)
        wl.append("        ADDON[] += {")
        wl.append(",\n".join('            "%s"' % c for c in into[well]))
        wl.append("        };")
        wl.append("    };")
    wl += ["};", ""]
    w("CfgMagazineWells.hpp", "\n".join(wl))
    return len(mags)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--src", default=r"D:/work/mcc")
    ap.add_argument("--fa", default=r"D:/Git/futureAmmo")
    a = ap.parse_args()
    ammo, facts = fa_index()

    def files(root, pat):
        out = []
        for dp, _d, fs in os.walk(root):
            out += [os.path.join(dp, f) for f in fs if re.match(pat, f, re.I)]
        return sorted(out)

    mcc_core = os.path.join(a.src, "MCC", "MCC_Core")
    mpp = os.path.join(a.src, "MPP", "MPP_PISTOLS")
    jobs = [
        ("mcc", "MCC", "Future Ammunition - MCC", "MCC_Core",
         files(mcc_core, r"magazines.*\.hpp$"), files(mcc_core, r"magwells\.hpp$")),
        ("mpp", "MPP", "Future Ammunition - MPP", "MPP_PISTOLS",
         files(mpp, r"magazines\.hpp$"), files(mpp, r"magwells\.hpp$")),
    ]
    for comp, tag, beaut, patch, mags, wells in jobs:
        blocks, into, need, bodies = build(mags, wells, tag, patch, ammo, facts)
        n = write_addon(os.path.join(ROOT, "addons", "fa_" + comp), "fa_" + comp, beaut, "jmfsb", patch,
                        blocks, into, need, bodies)
        write_addon(os.path.join(a.fa, "addons", comp), comp, beaut, "jmfsbfa", patch,
                    blocks, into, need, bodies)
        print("%s: %d looks, %d magazines, %d wells, needs %s" % (comp, len(bodies), n, len(into), sorted(need) or "-"))


if __name__ == "__main__":
    main()
