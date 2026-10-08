#!/usr/bin/env python3
"""Vendor the ACP "Chinese Xingkong" camo (Arid + Woodland) into addons/uniform_pla.

    python tools/gen_pla_kit.py [--acp D:\\work\\camo\\z\\acp\\addons]

THE PLA'S KIT IS SEB'S ACP RETEXTURES ON BASE-GAME MODELS. The user gave the
camo pack (2026-08-28) and said to copy the camo into this mod rather than
depend on it. So this reads the ACP addons' configs, takes the classes in KIT
- every one of them a retexture of a base-game uniform, helmet, vest or
pack, never one of ACP's own models - copies each class definition under our
own name (acp_CN_Xingkong_A_core_H_HelmetO_CN_Xingkong_A becomes
jmfsb_uniform_pla_H_HelmetO_A), copies the textures it names into
addons/uniform_pla/data/<A|W>/ and repaths them. A uniform is an item AND a
wearer body, and the two name each other; both are carried across and
re-paired. Credit stays with the author (the class's `author` and README).

WHAT IS DELIBERATELY NOT HERE: ACP's CF carrier rigs, Luchnik carriers,
EAST/Specter helmets and Aegis-pattern fatigues. Those sit on acp_main's own
models and would drag the whole pack in as a dependency.
"""
import io
import os
import re
import shutil
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ADDON = os.path.join(ROOT, "addons", "uniform_pla")
DEFAULT_ACP = r"D:\work\camo\z\acp\addons"
PREFIX = "jmfsb_uniform_pla"
THEATRES = {"A": "Arid", "W": "Woodland"}

# (ACP addon, ACP class with {T} for the theatre letter). The class may be a
# CfgWeapons item (uniform, helmet, vest) or a CfgVehicles backpack.
KIT = [
    ("CN_Xingkong_{T}_core",           "U_B_CombatUniform_CN_Xingkong_{T}"),
    ("CN_Xingkong_{T}_core",           "U_B_CombatUniform_vest_CN_Xingkong_{T}"),
    ("CN_Xingkong_{T}_core",           "U_B_CombatUniform_tshirt_CN_Xingkong_{T}"),
    ("CN_Xingkong_{T}_core",           "U_B_GhillieSuit_CN_Xingkong_{T}"),
    ("CN_Xingkong_{T}_core",           "H_HelmetO_CN_Xingkong_{T}"),
    ("CN_Xingkong_{T}_core",           "H_HelmetLeaderO_CN_Xingkong_{T}"),
    ("CN_Xingkong_{T}_core",           "H_HelmetSpecO_CN_Xingkong_{T}"),
    ("CN_Xingkong_{T}_core",           "H_Booniehat_CN_Xingkong_{T}"),
    ("CN_Xingkong_{T}_core",           "B_Kitbag_rgr_CN_Xingkong_{T}"),
    ("CN_Xingkong_{T}_core",           "B_Carryall_CN_Xingkong_{T}"),
    ("CN_Xingkong_{T}_core",           "B_AssaultPack_CN_Xingkong_{T}"),
    ("CN_Xingkong_{T}_core",           "B_ViperHarness_CN_Xingkong_{T}_F"),
    ("CN_Xingkong_{T}_core",           "B_ViperLightHarness_CN_Xingkong_{T}_F"),
    ("CN_Xingkong_{T}_core",           "B_FieldPack_CN_Xingkong_{T}"),
    ("CN_Xingkong_{T}_core",           "B_TacticalPack_CN_Xingkong_{T}"),
    ("CN_Xingkong_{T}_contact",        "B_RadioBag_01_CN_Xingkong_{T}_F"),
    ("CN_Xingkong_{T}_contact",        "V_CarrierRigKBT_01_CN_Xingkong_{T}_F"),
    ("CN_Xingkong_{T}_contact",        "V_CarrierRigKBT_01_heavy_CN_Xingkong_{T}_F"),
    ("CN_Xingkong_{T}_contact",        "V_CarrierRigKBT_01_light_CN_Xingkong_{T}_F"),
    ("CN_Xingkong_{T}_contact",        "H_HelmetHBK_F_CN_Xingkong_{T}"),
    ("CN_Xingkong_{T}_contact",        "H_HelmetHBK_chops_F_CN_Xingkong_{T}"),
    ("CN_Xingkong_{T}_contact",        "H_HelmetHBK_ear_F_CN_Xingkong_{T}"),
    ("CN_Xingkong_{T}_contact",        "H_HelmetHBK_headset_F_CN_Xingkong_{T}"),
    ("CN_Xingkong_{T}_vehicle_crew",   "U_Tank_CN_Xingkong_{T}_F"),
    ("CN_Xingkong_{T}_vehicle_crew",   "U_O_PilotCoveralls_CN_Xingkong_{T}"),
    ("CN_Xingkong_{T}_vehicle_crew",   "U_B_HeliPilotCoveralls_CN_Xingkong_{T}"),
    ("CN_Xingkong_{T}_vehicle_crew",   "H_HelmetCrew_CN_Xingkong_{T}"),
    ("CN_Xingkong_{T}_vehicle_crew",   "H_PilotHelmetHeli_CN_Xingkong_{T}"),
    ("CN_Xingkong_{T}_vehicle_crew",   "H_CrewHelmetHeli_CN_Xingkong_{T}"),
    ("CN_Xingkong_{T}_extra_headgear", "H_MilCap_CN_Xingkong_{T}"),
    ("CN_Xingkong_{T}_extra_headgear", "H_Cap_CN_Xingkong_{T}"),
    ("CN_Xingkong_{T}_modern_east",    "V_SmershVest_01_CN_Xingkong_{T}_F"),
    ("CN_Xingkong_{T}_modern_east",    "V_SmershVest_01_radio_CN_Xingkong_{T}_F"),
    # THE VIPERS (user, 2026-08-28): ACP's "futuristic" set retextures the Viper
    # Special Purpose Suit and helmet; the suit's ACP class is oddly named
    # U_O_officer_..._hex - NAME_FIX gives it the base game's name.
    ("CN_Xingkong_{T}_futuristic",     "H_HelmetO_ViperSP_CN_Xingkong_{T}_F"),
    ("CN_Xingkong_{T}_futuristic",     "U_O_officer_CN_Xingkong_{T}_hex_F"),
]
NAME_FIX = {"U_O_officer_hex": "U_O_V_Soldier_Viper", "Soldier_U_O_officer_hex": "Soldier_U_O_V_Soldier_Viper"}

# THE MEN'S PACKS STAY THE MEN'S PACKS (user, 2026-08-28: "back packs need to be
# pla"). A loaded pack - B_FieldPack_ocamo_Medic and its kind - IS the role's
# kit; swapping it for an empty Xingkong one would strip the medic. So every
# loaded pack OPF_F's men carry is re-declared here as a child of itself with
# the Xingkong skin of its model family, contents and all, and gen_us_factions
# points the man at the child (work/pla_packs.json). Families by prefix.
LOADED_PACKS = [
    "B_ViperHarness_hex_M_F", "B_ViperHarness_hex_TL_F", "B_ViperHarness_hex_Medic_F", "B_ViperHarness_hex_LAT_F",
    "B_ViperHarness_hex_LAT_lxWS", "B_ViperHarness_hex_JTAC_F", "B_ViperHarness_hex_Exp_F",
    "B_FieldPack_ocamo_Medic", "B_FieldPack_cbr_LAT", "B_FieldPack_cbr_HAT", "B_FieldPack_blk_DiverExp",
    "B_FieldPack_ocamo_LAT_F", "B_FieldPack_oucamo_AT", "B_FieldPack_ocamo_AA", "B_FieldPack_cbr_Ammo",
    "B_FieldPack_ocamo_ReconMedic", "B_FieldPack_cbr_AT", "B_FieldPack_cbr_Ammo_F", "B_FieldPack_cbr_RPG_AT",
    "B_FieldPack_ocamo_ReconExp", "B_FieldPack_cbr_Repair", "B_FieldPack_oucamo_LAT", "B_FieldPack_oucamo_AA",
    "B_FieldPack_oucamo_Medic", "B_FieldPack_oucamo_Ammo", "B_FieldPack_oucamo_Repair",
    "B_TacticalPack_ocamo_AT_F", "B_TacticalPack_ocamo_AA_F",
    "B_Carryall_oucamo_AAA", "B_Carryall_cbr_AHAT", "B_Carryall_oucamo_Eng", "B_Carryall_oucamo_AAT",
    "B_Carryall_ocamo_Eng", "B_Carryall_ocamo_AAR", "B_Carryall_cbr_AAT", "B_Carryall_oucamo_Exp",
    "B_Carryall_ocamo_Exp", "B_Carryall_ocamo_AAA", "B_Carryall_oucamo_AAR", "B_Carryall_ocamo_Mine",
    "B_AssaultPack_ocamo_Medic_F", "B_RadioBag_01_hex_F",
]
# prefix -> the vendored pack whose textures the family shares (ACP class name pattern)
PACK_FAMILY = [
    ("B_ViperHarness_", "B_ViperHarness_CN_Xingkong_{T}_F"),
    ("B_FieldPack_",    "B_FieldPack_CN_Xingkong_{T}"),
    ("B_TacticalPack_", "B_TacticalPack_CN_Xingkong_{T}"),
    ("B_Carryall_",     "B_Carryall_CN_Xingkong_{T}"),
    ("B_AssaultPack_",  "B_AssaultPack_CN_Xingkong_{T}"),
    ("B_Kitbag_",       "B_Kitbag_rgr_CN_Xingkong_{T}"),
    ("B_RadioBag_01_",  "B_RadioBag_01_CN_Xingkong_{T}_F"),
]

HDR = ("// Generated by tools/gen_pla_kit.py - re-run rather than hand-edit.\n"
       "// Seb's ACP Chinese Xingkong retextures, vendored onto base-game models;\n"
       "// see the README for the credit and what was left out.\n")


def block_end(s, i):
    depth, j = 1, i
    while depth and j < len(s):
        depth += (s[j] == "{") - (s[j] == "}")
        j += 1
    return j


def strip_comments(s):
    s = re.sub(r"/\*.*?\*/", "", s, flags=re.S)
    return re.sub(r"//[^\n]*", "", s)


def our_name(acp_cls, addon, t):
    """acp_<addon>_<X>_CN_Xingkong_<T>[_F] -> jmfsb_uniform_pla_<X>_<T>."""
    x = acp_cls[len("acp_" + addon + "_"):]
    x = x.replace("_CN_Xingkong_%s" % t, "")
    if x.endswith("_F"):
        x = x[:-2]
    x = NAME_FIX.get(x, x)
    return "%s_%s_%s" % (PREFIX, x, t)


def find_class(text, name):
    """(parent, body-with-braces, start, end) of a top-level-ish class."""
    m = re.search(r"class\s+%s\s*:\s*(\w+)\s*\{" % re.escape(name), text)
    if not m:
        return None
    e = block_end(text, m.end())
    return m.group(1), text[m.end():e - 1], m.start(), e


def main():
    acp = DEFAULT_ACP
    if "--acp" in sys.argv:
        acp = sys.argv[sys.argv.index("--acp") + 1]
    if not os.path.isdir(acp):
        print("!! no ACP tree at %s" % acp)
        return 2

    weapons, vehicles, units_list, weapons_list, parents = [], [], [], [], set()
    copied, authors, skipped = 0, set(), []
    for t, tname in THEATRES.items():
        data_dir = os.path.join(ADDON, "data", t)
        os.makedirs(data_dir, exist_ok=True)
        cfg_cache = {}
        for addon_pat, cls_pat in KIT:
            addon, cls = addon_pat.format(T=t), cls_pat.format(T=t)
            if addon not in cfg_cache:
                cfg_cache[addon] = strip_comments(io.open(os.path.join(acp, addon, "config.cpp"),
                                                          encoding="utf-8", errors="replace").read())
            cfg = cfg_cache[addon]
            full = "acp_%s_%s" % (addon, cls)
            item = find_class(cfg, full)
            if not item:
                skipped.append((t, cls, "not found"))
                continue
            names = {full: our_name(full, addon, t)}
            # a uniform's wearer body, referenced from its ItemInfo
            body_ref = re.search(r'uniformClass\s*=\s*"?(acp_\w+)"?', item[1])
            body = find_class(cfg, body_ref.group(1)) if body_ref else None
            if body_ref and not body:
                skipped.append((t, cls, "body %s not found" % body_ref.group(1)))
                continue
            if body_ref:
                names[body_ref.group(1)] = our_name(body_ref.group(1), addon, t)
            chunks = [(full, item, "weapons" if not cls.startswith("B_") else "vehicles")]
            if body:
                chunks.append((body_ref.group(1), body, "vehicles"))
            for acp_name, (parent, inner, _s, _e), where in chunks:
                if parent.startswith("acp_"):
                    skipped.append((t, cls, "parent %s is ACP's own model" % parent))
                    break
                parents.add((where, parent))
                text = inner
                for old, new in names.items():
                    text = re.sub(r"\b%s\b" % re.escape(old), new, text)
                # textures and materials: vendor and repath
                def repath(m):
                    nonlocal copied
                    src_rel = m.group(1)
                    fn = os.path.basename(src_rel.replace("\\", "/")).lower()
                    src = os.path.join(acp, addon, *src_rel.replace("\\", "/").split("/")[-2:]) if "data" in src_rel.lower() else None
                    # ACP paths are \z\acp\addons\<addon>\data\<file>
                    parts = src_rel.replace("\\", "/").split("/")
                    if "addons" in parts:
                        src = os.path.join(acp, *parts[parts.index("addons") + 1:])
                    dst = os.path.join(data_dir, fn)
                    if src and os.path.exists(src):
                        if not os.path.exists(dst):
                            shutil.copy2(src, dst)
                            copied += 1
                    else:
                        skipped.append((t, cls, "texture missing: %s" % src_rel))
                    return '"\\z\\jmfsb\\addons\\uniform_pla\\data\\%s\\%s"' % (t, fn)
                text = re.sub(r'"([^"]+\.(?:paa|rvmat))"', repath, text)
                a = re.search(r'author\s*=\s*"([^"]*)"', text)
                if a:
                    authors.add(a.group(1))
                    text = text.replace(a.group(0), 'author = "%s (ACP), vendored by 2040"' % a.group(1))
                dn = re.search(r'displayName\s*=\s*"([^"]*)"', text)
                if dn:
                    # "[CN Xingkong A] Combat Fatigues [NATO]" -> "[2040] PLA Combat Fatigues (Arid)"
                    clean = re.sub(r"\s*\[[^\]]*\]\s*", " ", dn.group(1)).strip()
                    text = text.replace(dn.group(0), 'displayName = "[2040] PLA %s (%s)"' % (clean, tname))
                # ACP's tabs and bare `=`: the repo's config style is four spaces and `key = value`
                text = text.replace("\t", "    ")
                text = re.sub(r"(?m)^(\s*[A-Za-z_][\w\[\]]*)\s*=\s*", r"\1 = ", text)
                # tidy: one class, its own indentation
                lines = [ln.rstrip() for ln in text.strip("\n").split("\n")]
                mn = min((len(ln) - len(ln.lstrip()) for ln in lines if ln.strip()), default=0)
                lines = ["        " + ln[mn:] if ln.strip() else "" for ln in lines]
                out = ["    class %s: %s {" % (names[acp_name], parent)] + lines + ["    };"]
                (weapons if where == "weapons" else vehicles).extend(out)
                (weapons_list if where == "weapons" else units_list).append(names[acp_name])

    # ---- the loaded packs: children of CSAT's, in the family's Xingkong skin ----
    import json as _json
    tex_of = {}   # (T, family ACP class) -> hiddenSelectionsTextures lines already repathed
    for ln in vehicles:
        pass
    packs_out = {}
    for t, tname in THEATRES.items():
        for fam_prefix, fam_pat in PACK_FAMILY:
            fam_cls = "%s_%s" % (PREFIX, our_name("acp_x_" + fam_pat.format(T=t), "x", t)[len(PREFIX) + 1:])
            # find that class's texture block in what was generated
            blk = "\n".join(vehicles)
            i = blk.find("class %s:" % fam_cls)
            if i < 0:
                skipped.append((t, fam_pat, "family pack not generated")); continue
            j = blk.find("hiddenSelectionsTextures[]", i)
            k = blk.find("};", j)
            tex_block = blk[j:k + 2]
            for orig in LOADED_PACKS:
                if not orig.startswith(fam_prefix):
                    continue
                cls = "%s_%s_%s" % (PREFIX, orig, t)
                parents.add(("vehicles", orig))
                vehicles += ["    class %s: %s {" % (cls, orig),
                             '        author = "Seb (ACP), vendored by 2040";',
                             "        scope = 1;",
                             "        scopeCurator = 0;",
                             "        " + tex_block.replace("\n", "\n        "),
                             "    };"]
                units_list.append(cls)
                packs_out.setdefault(orig, {})[t] = cls
    io.open(os.path.join(ROOT, "work", "pla_packs.json"), "w", encoding="utf-8").write(_json.dumps(packs_out, indent=1, sort_keys=True))

    # ---- write the addon ----------------------------------------------------
    def crlf(name, lines):
        io.open(os.path.join(ADDON, name), "w", encoding="utf-8", newline="\r\n").write("\n".join(lines) + "\n")

    crlf("$PBOPREFIX$", ["z\\jmfsb\\addons\\uniform_pla"])
    crlf("script_component.hpp", [
        "#define COMPONENT uniform_pla",
        "#define COMPONENT_BEAUTIFIED uniform_pla",
        '#include "\\z\\jmfsb\\addons\\main\\script_mod.hpp"',
        "",
        "// #define DEBUG_MODE_FULL",
        "// #define DISABLE_COMPILE_CACHE",
        "",
        "#ifdef DEBUG_ENABLED_uniform_pla",
        "    #define DEBUG_MODE_FULL",
        "#endif",
        "    #ifdef DEBUG_SETTINGS_uniform_pla",
        "    #define DEBUG_SETTINGS DEBUG_SETTINGS_uniform_pla",
        "#endif",
        "",
        '#include "\\z\\jmfsb\\addons\\main\\script_macros.hpp"',
    ])
    wp = sorted(p for w, p in parents if w == "weapons")
    vp = sorted(p for w, p in parents if w == "vehicles")
    crlf("CfgWeapons.hpp", [HDR.rstrip("\n"), "", "class CfgWeapons {",
                            "    // the items' ItemInfo inherit their base-game parent's, as BI's own retextures do;",
                            "    // hemtt wants the name declared external", "    class ItemInfo;"] +
         ["    class %s;" % p for p in wp] + [""] + weapons + ["};"])
    crlf("CfgVehicles.hpp", [HDR.rstrip("\n"), "", "class CfgVehicles {"] +
         ["    class %s;" % p for p in vp] + [""] + vehicles + ["};"])
    crlf("config.cpp", [
        '#include "script_component.hpp"',
        "",
        "class CfgPatches {",
        "    class ADDON {",
        "        name = COMPONENT_NAME;",
        "        units[] = {"] +
        ['            "%s"%s' % (u, "," if i < len(units_list) - 1 else "") for i, u in enumerate(units_list)] +
        ["        };",
         "        weapons[] = {"] +
        ['            "%s"%s' % (w, "," if i < len(weapons_list) - 1 else "") for i, w in enumerate(weapons_list)] +
        ["        };",
         "        requiredVersion = REQUIRED_VERSION;",
         "        // Base-game characters only: every parent is A3's. ACP itself is NOT",
         "        // required - its textures are vendored under data/.",
         '        requiredAddons[] = {"jmfsb_main", "A3_Characters_F", "A3_Characters_F_Exp", "A3_Characters_F_Enoch", "A3_Characters_F_Tank"};',
         "        skipWhenMissingDependencies = 1;",
         "        author = QAUTHOR;",
         "        VERSION_CONFIG;",
         "    };",
         "};",
         "",
         '#include "CfgWeapons.hpp"',
         '#include "CfgVehicles.hpp"'])
    readme = os.path.join(ADDON, "README.md")
    if not os.path.exists(readme):
        io.open(readme, "w", encoding="utf-8", newline="\n").write(
            "# uniform_pla\n\n`jmfsb_uniform_pla`\n\n"
            "The PLA's kit: Seb's **ACP (Arma Camo Pack)** \"Chinese Xingkong\" Arid and "
            "Woodland retextures of base-game uniforms, helmets, vests and packs, vendored "
            "here so the PLA factions carry no dependency on the pack. Classes and textures "
            "are copied by `tools/gen_pla_kit.py` from the unpacked pack (author credit kept "
            "on every class). ACP's own-model items (CF rigs, Luchnik carriers, EAST/Specter "
            "helmets, Aegis-pattern fatigues) were left out on purpose.\n\n"
            "<!-- generated below this line by tools/gen_addon_readmes.py - do not edit -->\n")
    print("wrote addons/uniform_pla: %d weapon(s), %d unit(s), %d texture(s) copied; authors %s" % (
        len(weapons_list), len(units_list), copied, sorted(authors)))
    for s in skipped:
        print("  !! %s %s - %s" % s)
    return 0


if __name__ == "__main__":
    rc = main()
    # 2040 PEER ARMOUR. This rewrites files tools/peer_vests.py edits; put its protection and vest swaps back.
    import peer_vests
    peer_vests.main()
    sys.exit(rc)
