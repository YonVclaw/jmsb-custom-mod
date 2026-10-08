#!/usr/bin/env python
"""2040 peer armour: the vests Iran, Russia and China wear, on jmfsb's own protection numbers.

JMSB's NATO carriers wear JMFSB_PLATE_CARRIER_STANDARD_PROTECTION (chest 29 / 0.085, abdomen 19, arms and
legs 12; addons/main/script_macros.hpp). The opposing forces did not: Iran's JAM SOF CHPC carriers were 14 / 0.1,
China's KBT rigs 16 / 0.3, and most of Russia wore a Smersh or a chest rig - load-bearing kit with no plates at
all. A peer army of 2040 is plated like the side it fights (user, 2026-10-07: "the vest we have on iran russia and
china make sure they are aligned with a 2040 peer make copies if you need to"):

    Iran     vests_sof's CHPC carriers (jmfsb's own copies of JAM SOF's) get the standard protection, and Iran's
             soldiers - its CDLC overlays included - wear those instead of the SOF mod's originals
    China    uniform_pla's KBT rigs and Smersh vests are China's alone: the light rigs and Smersh vests take the
             standard protection, the heavy (GL) rigs the heavy, in place
    Russia   the Smersh vests and the chest rig are the base game's, worn by everyone: uniform_ru gets jmfsb
             copies with the standard protection (its own tactical vest takes it in place), and uniform_ru's
             soldiers wear the copies. gen_mod_factions.py builds faction_russia from those soldiers.

Belts, bandoliers and the divers' rebreathers are left as they are: they are not armour on any side.

Idempotent; the generators that rewrite these files call it at their end (port_to_addon.py, gen_pla_kit.py,
gen_us_factions.py, cdlc_split.py).

    python tools/peer_vests.py
"""

import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ADDONS = os.path.join(ROOT, "addons")
STANDARD = "JMFSB_PLATE_CARRIER_STANDARD_PROTECTION"
HEAVY = "JMFSB_PLATE_CARRIER_HEAVY_PROTECTION"

# Russia: the base game's vests uniform_ru's soldiers wear, copied with plates
RU_COPIES = [
    ("V_SmershVest_01_F", "Smersh Vest (Plates)"),
    ("V_SmershVest_01_radio_F", "Smersh Vest (Radio, Plates)"),
    ("V_TacChestrig_grn_F", "Tactical Chest Rig (Green, Plates)"),
]
RU_IN_PLACE = ["GVAR(V_TacVest_grn)"]
# China: uniform_pla's own classes, by name pattern -> protection
PLA = [(r"jmfsb_uniform_pla_V_CarrierRigKBT_01_heavy_\w+", HEAVY),
       (r"jmfsb_uniform_pla_V_CarrierRigKBT_01_light_\w+", STANDARD),
       (r"jmfsb_uniform_pla_V_SmershVest_01_\w+", STANDARD)]
IRAN_FILES = ["faction_iran/CfgVehicles.hpp", "faction_iran_tna/CfgVehicles.hpp",
              "compatibility/cdlc_rf/content.hpp", "compatibility/cdlc_ws/content.hpp"]
BEGIN = "    // ---- 2040 peer armour: tools/peer_vests.py ----"
END = "    // ---- end 2040 peer armour ----"


def rd(p):
    return open(p, encoding="utf-8", newline="").read()


def wr(p, t, old):
    if t != old:
        open(p, "w", encoding="utf-8", newline="").write(t)
        return 1
    return 0


def block_end(t, i):
    """Index just past the `};` closing the class whose `{` is at or after i."""
    j, d = t.index("{", i) + 1, 1
    while d:
        d += {"{": 1, "}": -1}.get(t[j], 0)
        j += 1
    return t.index(";", j) + 1


def give(t, head_re, macro, nl, add=True):
    """Every class matching head_re wears macro: its own HitpointsProtectionInfo replaced, or (add) an ItemInfo
    added. add=False for a family whose camo variants inherit the protection of one base class."""
    out, pos = [], 0
    for m in re.finditer(r"(?m)^    class (%s)\s*:\s*[\w()]+\s*\{" % head_re, t):
        if m.start() < pos:
            continue
        e = block_end(t, m.start())
        body = t[m.end():e]
        if macro in body:
            continue
        hp = re.search(r"class HitpointsProtectionInfo\s*\{", body)
        if hp:
            he = block_end(body, hp.start())
            body = body[:hp.start()] + macro + body[he:]
        elif not add:
            continue
        else:
            close = body.rstrip().rfind("}")
            body = body[:close].rstrip() + nl + "        class ItemInfo: ItemInfo {" + nl + \
                "            " + macro + nl + "        };" + nl + "    " + body[close:]
        out.append(t[pos:m.end()] + body)
        pos = e
    out.append(t[pos:])
    return "".join(out)


def russia():
    n = 0
    cw = os.path.join(ADDONS, "uniform_ru", "CfgWeapons.hpp")
    t0 = t = rd(cw)
    nl = "\r\n" if "\r\n" in t else "\n"
    t = re.sub(re.escape(BEGIN) + r".*?" + re.escape(END) + r"\r?\n", "", t, flags=re.S)
    for cls in RU_IN_PLACE:
        t = give(t, re.escape(cls), STANDARD, nl)
    block = [BEGIN, "    // the base game's vests uniform_ru's soldiers wear, with the plates a 2040 peer carries"]
    block += ["    class %s;" % v for v, _ in RU_COPIES]
    for v, name in RU_COPIES:
        block += ["    class GVAR(%s): %s {" % (v, v),
                  "        author = QAUTHOR;",
                  "        scope = 2;",
                  "        scopeArsenal = 2;",
                  '        displayName = "%s";' % name,
                  "        class ItemInfo: ItemInfo {",
                  "            " + STANDARD,
                  "        };",
                  "    };"]
    block += [END]
    close = t.rstrip().rfind("};")
    t = t[:close] + nl.join(block) + nl + t[close:]
    # a top-level declaration, not one of the nested `class ItemInfo;` uniforms already carry
    if not re.search(r"(?m)^    class ItemInfo;", t):
        t = t.replace("class CfgWeapons {" + nl, "class CfgWeapons {" + nl + "    class ItemInfo;" + nl, 1)
    n += wr(cw, t, t0)
    # CfgPatches weapons[]
    cp = os.path.join(ADDONS, "uniform_ru", "config.cpp")
    c0 = c = rd(cp)
    for v, _ in RU_COPIES:
        if "QGVAR(%s)" % v not in c:
            c = re.sub(r"(weapons\[\]\s*=\s*\{)", r"\1" + nl + "            QGVAR(%s)," % v, c, count=1)
    n += wr(cp, c, c0)
    # the soldiers
    for f in ("CfgVehicles.hpp", "arctic_CfgVehicles.hpp"):
        cv = os.path.join(ADDONS, "uniform_ru", f)
        if not os.path.exists(cv):
            continue
        v0 = v = rd(cv)
        for vest, _ in RU_COPIES:
            v = v.replace('"%s"' % vest, "QGVAR(%s)" % vest)
        n += wr(cv, v, v0)
    return n


def china():
    p = os.path.join(ADDONS, "uniform_pla", "CfgWeapons.hpp")
    t0 = t = rd(p)
    nl = "\r\n" if "\r\n" in t else "\n"
    for pat, macro in PLA:
        t = give(t, pat, macro, nl)
    return wr(p, t, t0)


def iran():
    n = 0
    p = os.path.join(ADDONS, "vests_sof", "CfgWeapons.hpp")
    t0 = t = rd(p)
    nl = "\r\n" if "\r\n" in t else "\n"
    t = give(t, r"GVAR\(SOF_V_CHPCCarrier_\w+\)", STANDARD, nl, add=False)
    n += wr(p, t, t0)
    swap = lambda s: re.sub(r'"(SOF_V_CHPCCarrier_\w+)"', r'"jmfsb_vests_sof_\1"', s)
    for f in IRAN_FILES:
        fp = os.path.join(ADDONS, f)
        if os.path.exists(fp):
            s0 = rd(fp)
            n += wr(fp, swap(s0), s0)
    # the CDLC split's record, so its next render keeps the swap
    rec = os.path.join(ROOT, "tools", "cdlc_split.json")
    if os.path.exists(rec):
        r0 = rd(rec)
        r1 = re.sub(r'\\"(SOF_V_CHPCCarrier_\w+)\\"', r'\\"jmfsb_vests_sof_\1\\"', r0)
        if r1 != r0:
            json.loads(r1)
            n += wr(rec, r1, r0)
    return n


def main():
    n = russia() + china() + iran()
    print("peer_vests: %d file(s) changed" % n)
    return 0


if __name__ == "__main__":
    sys.exit(main())
