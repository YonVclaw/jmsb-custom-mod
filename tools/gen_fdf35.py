"""Clone the FDF 2035 faction (KAR_FIN35_FACTION) into jmfsb with futureAmmo.

Units are subclassed from the KAR classes, so they keep their own uniforms,
vests, helmets and models -- only ammunition is swapped. Three EF MJTF woodland
MRAPs are added, and every squad gets the mod's own UAV operator.
"""
import os, io, json, collections

D = os.path.dirname(os.path.abspath(__file__))
BASE = r"O:\GIT\jmfsb\addons"
COMP = "faction_b_fdf35"
FCLS = "jmfsb_b_fdf35"
DISP = "FDF 2035"
COL = "Red"

_FIN = json.load(io.open(os.path.join(D, "fin_classes.json"), encoding="utf-8"))
_A3 = json.load(io.open(os.path.join(D, "a3_classes.json"), encoding="utf-8"))
_MOD = json.load(io.open(os.path.join(D, "mod_classes.json"), encoding="utf-8"))
# chains must resolve all the way into vanilla or turret ammo is never found
C = {}
for _src in (_A3, _MOD, _FIN):
    for _k, _v in _src.items():
        C.setdefault(_k, {}).update(_v)
FA = set(io.open(os.path.join(D, "fa_classes.txt")).read().split())
CI = {k.lower(): k for k in C}


def res(n, key):
    seen = set()
    while n and n.lower() in CI and n not in seen:
        seen.add(n)
        e = C[CI[n.lower()]]
        if key in e:
            return e[key]
        n = e.get("parent")
    return None


def res_turrets(n):
    chain, seen = [], set()
    x = n
    while x and x.lower() in CI and x not in seen:
        seen.add(x); chain.append(CI[x.lower()]); x = C[CI[x.lower()]].get("parent")
    acc = {}
    for cl in reversed(chain):
        for path, d in (C[cl].get("turrets") or {}).items():
            if d.get("magazines") is not None:
                acc[path] = d["magazines"]
    return acc


# vanilla / mod magazine -> FA base name (tracer colour appended when it exists)
MAP = {
    "KAR_FDF35_556_PMAG":              "FA_30Rnd_556_Mk327_HV",
    "30Rnd_556x45_Stanag":             "FA_30Rnd_556_Mk327_HV",
    "KAR_FDF35_RK_MAG":                "FA_30Rnd_762x39_7N43",
    "30Rnd_65x39_caseless_black_mag":  "FA_30Rnd_65_EPR_Black",
    "30Rnd_65x39_caseless_mag":        "FA_30Rnd_65_EPR",
    "200Rnd_65x39_cased_Box_Red":      "FA_200Rnd_65_Mk328",
    "200Rnd_65x39_cased_Box":          "FA_200Rnd_65_Mk328",
    "20Rnd_762x51_Mag":                "FA_20Rnd_762_M80A2_HV",
    "Aegis_20Rnd_762x51_SMAG":         "FA_20Rnd_762_M80A2_HV",
    "150Rnd_762x54_Box":               "FA_150Rnd_762x54_Box",
    "7Rnd_408_Mag":                    "FA_10Rnd_408_Mk240",
    "1Rnd_HE_Grenade_shell":           "FA_1Rnd_40mm_Mk380_NRP",
    "3Rnd_HE_Grenade_shell":           "FA_1Rnd_40mm_Mk380_NRP",
}
TMAP = {
    "200Rnd_762x51_Belt_Red":               "FA_200Rnd_762_M80A2_HV",
    "100Rnd_127x99_mag_Tracer_Red":         "FA_200Rnd_127_Mk258",
    "200Rnd_127x99_mag_Tracer_Red":         "FA_200Rnd_127_Mk258",
    "12Rnd_120mm_APFSDS_shells_Tracer_Red": "FA_30Rnd_120mm_APFSDS",
    "8Rnd_120mm_HE_shells_Tracer_Red":      "FA_30Rnd_120mm_AMP",
    "8Rnd_120mm_HEAT_MP_T_Red":             "FA_30Rnd_120mm_HEATMP",
    "32Rnd_155mm_Mo_shells":                "FA_32Rnd_155mm_heer_B",
    "4Rnd_155mm_Mo_guided":                 "FA_4Rnd_155mm_apmi_B",
    "6Rnd_155mm_Mo_mine":                   "FA_6Rnd_155mm_apmine_B",
    "2Rnd_155mm_Mo_Cluster":                "FA_2Rnd_155mm_sfm_B",
    "6Rnd_155mm_Mo_smoke":                  "FA_6Rnd_155mm_smk_B",
    "2Rnd_155mm_Mo_LG":                     "FA_4Rnd_155mm_lgm_B",
    "6Rnd_155mm_Mo_AT_mine":                "FA_6Rnd_155mm_atmine_B",
    "12Rnd_230mm_rockets":                  "FA_12Rnd_230mm_gmlrsu_B",
    "8Rnd_82mm_Mo_shells":                  "FA_8Rnd_82mm_Mo_shells",
}


def fa_of(mag, table):
    base = table.get(mag)
    if not base:
        return None
    for cand in ("%s_T_%s" % (base, COL), base):
        if cand in FA:
            return cand
    return None


roster = sorted(n for n in C
                if res(n, "faction") == "KAR_FIN35_FACTION" and res(n, "scope") == "2")

# EF MJTF woodland MRAPs requested on top of the mod's own roster. Their owning
# mod is intentionally NOT a requiredAddon: skipWhenMissingDependencies would
# drop the whole faction if EF were absent.
EXTRA = [
    "EF_B_MRAP_01_FSV_MJTF_Wdl",
    "EF_B_MRAP_01_AT_MJTF_Wdl",
    "EF_B_MRAP_01_LAAD_MJTF_Wdl",
    # the mod's own drone (no explicit scope, so it misses the roster filter)
    "KAR_FDF35_UAV",
    # same drone set faction_b_fdf fields. Units only, never CfgGroups entries;
    # owning mods stay out of requiredAddons on purpose.
    "B_UAV_RC40_HE_RF",
    "B_UAV_RC40_SENSOR_RF",
    "B_T_UAV_03_dynamicLoadout_F",
    "B_T_UGV_01_olive_F",
    "B_T_UGV_01_rcws_olive_F",
    "GX_B_HONEYBADGER_UGV_AT_GREEN",
    "GX_B_HUNTER_SP_UAV",
    "GX_B_MAGURA_V5_USV",
    "GX_B_MQ8B_UAV_ARMED",
    "GX_B_MQ8B_UAV_RECON",
    "GX_B_MQ8B_UAV_RECON_SEATED",
    "GX_B_THEMIS_UGV_CARGO",
    "GX_B_THEMIS_UGV_DEFNDER_MEDIUM",
    "GX_B_THEMIS_UGV_HUNTER_LAUNCHER",
    "qav_ripsaw_Mk44",
    "qav_ripsaw_c",
    "rksla3_aeroshark_blufor",
]

EXTRA = [x for x in EXTRA if x not in roster]   # roster may already cover these
clone = {n: "jmfsb_%s_%s" % (COMP, n) for n in roster + EXTRA}

d = os.path.join(BASE, COMP)
os.makedirs(d, exist_ok=True)
W = lambda n, c: io.open(os.path.join(d, n), "w", encoding="utf-8", newline="\n").write(c)
io.open(os.path.join(d, "$PBOPREFIX$"), "w", newline="\n").write(
    "z\\jmfsb\\addons\\%s\n" % COMP)

W("script_component.hpp",
  '#define COMPONENT %s\n#define COMPONENT_BEAUTIFIED %s\n'
  '#include "\\z\\jmfsb\\addons\\main\\script_mod.hpp"\n'
  '#include "\\z\\jmfsb\\addons\\main\\script_macros.hpp"\n' % (COMP, DISP))

CATS = '// Our own Eden category -- the clones point at it, so it must exist.\nclass CfgEditorCategories {\n    class %s {\n        displayName = "[JMSB] %s";\n    };\n};\n'
W("CfgEditorCategories.hpp", CATS % (FCLS, DISP))

W("CfgFactionClasses.hpp",
  'class CfgFactionClasses {\n'
  '    class %s {\n'
  '        displayName = "[JMSB] %s";\n'
  '        priority = 3;\n'
  '        side = 1;\n'
  '        icon = "\\A3\\ui_f\\data\\map\\markers\\nato\\b_inf.paa";\n'
  '        flag = "\\A3\\Data_F\\Flags\\flag_nato_co.paa";\n'
  '    };\n};\n' % (FCLS, DISP))

# ---------------------------------------------------------------- CfgVehicles
fwd, bodies, nmag, ntur = [], [], 0, 0
struct = {}
for n in roster + EXTRA:
    tnew = {}
    # MainTurret only: an empty nested forward-decl on any other turret severs it
    # No turret overrides here: the forward-decl skeleton they require emits an
    # empty nested `class MainTurret;` on the vanilla class, which SEVERS the
    # inherited turret (hundreds of B_MBT_01_mlrs_F/MainTurret.* warnings).
    # jmfsbfa already patches the vanilla artillery turrets, so inheriting is
    # both safe and still futureAmmo.
    _tur = {} if True else {k: v for k, v in res_turrets(n).items()
            if k == "MainTurret" or k.startswith("MainTurret/")}
    for path, tm in _tur.items():
        conv = [fa_of(x, TMAP) or x for x in tm]
        if conv != tm:
            tnew[path] = conv
    if tnew:
        struct[n] = tnew

for n in roster + EXTRA:
    if n not in struct:
        fwd.append("    class %s;" % n)
for n in sorted(struct):
    p = res(n, "parent") and C[CI[n.lower()]].get("parent")
    par = CI.get((p or "").lower())
    if par and par not in struct:
        fwd.append("    class %s;" % par)
    fwd.append("    class %s: %s {" % (n, par) if par else "    class %s {" % n)
    fwd.append("        class Turrets {")
    for path in sorted(struct[n]):
        fwd.append("            class %s;" % path.split("/")[-1])
    fwd.append("        };")
    fwd.append("    };")

for n in roster + EXTRA:
    b = ["    class %s: %s {" % (clone[n], n),
         "        scope = 2;",
         "        scopeCurator = 2;",
         "        side = 1;",
         '        faction = "%s";' % FCLS]
    # KAR sets editorCategory = "KAR_FDF35_TOP" (its own Eden category), which
    # pulls the clone out of our faction's tree. Units categorise by faction, so
    # point it at ours and use the stock EdSubcat_* subcategories.
    ch2, x = set(), n
    while x and x.lower() in CI and x not in ch2:
        ch2.add(x)
        x = C[CI[x.lower()]].get("parent")
    low = " ".join(ch2).lower()
    nl = n.lower()
    # statics first: a mortar is artillery too, but it is a turret first
    if ch2 & {"StaticWeapon", "StaticMortar", "StaticCannon", "StaticMGWeapon",
              "StaticATWeapon", "StaticAAWeapon", "Radar_System_01_base_F",
              "SAM_System_03_base_F"}:
        sub = "EdSubcat_Turrets"
    elif ch2 & {"KAR_FDF35_S_BASE"} or res(n, "uniformClass"):
        sub = "EdSubcat_Personnel_SpecialForces" if ("sof" in nl or "sis" in nl) \
              else "EdSubcat_Personnel"
    elif "uav" in nl or "ugv" in nl or "drone" in nl or "ripsaw" in nl or "themis" in nl \
            or "honeybadger" in nl or "magura" in nl or "aeroshark" in nl or "mq8b" in nl \
            or "hunter_sp" in nl or "rc40" in nl:
        sub = "EdSubcat_Drones"
    elif "heli" in low:
        sub = "EdSubcat_Helicopters"
    elif "_f35" in nl or "plane" in low:
        sub = "EdSubcat_Planes"
    elif "leo2" in low or "iptsv" in low:
        sub = "EdSubcat_Tanks"
    elif "patria" in low or "rpsv" in low or "mrap" in low or "matv" in low:
        sub = "EdSubcat_APCs"
    elif "arty" in low or "krh" in low or "rsrakh" in low or "mostka" in low:
        sub = "EdSubcat_Artillery"
    elif "ito" in low or "pstohj" in low or "laad" in low:
        sub = "EdSubcat_AAs"
    else:
        sub = "EdSubcat_Cars"
    b.append('        editorCategory = "%s";' % FCLS)
    b.append('        editorSubcategory = "%s";' % sub)
    mags = res(n, "magazines") or []
    new, changed = [], False
    for m in mags:
        f = fa_of(m, MAP)
        new.append(f or m)
        changed = changed or bool(f)
    if changed:
        nmag += 1
        for arr in ("magazines", "respawnMagazines"):
            b.append("        %s[] = {" % arr)
            for i, m in enumerate(new):
                b.append('            "%s"%s' % (m, "," if i < len(new) - 1 else ""))
            b.append("        };")
    crew = res(n, "crew")
    if crew and CI.get(crew.lower()) in clone:
        b.append('        crew = "%s";' % clone[CI[crew.lower()]])
    if n in struct:
        ntur += 1
        b.append("        class Turrets: Turrets {")
        for path in sorted(struct[n]):
            leaf = path.split("/")[-1]
            b.append("            class %s: %s {" % (leaf, leaf))
            b.append("                magazines[] = {")
            ms = struct[n][path]
            for i, m in enumerate(ms):
                b.append('                    "%s"%s' % (m, "," if i < len(ms) - 1 else ""))
            b.append("                };")
            b.append("            };")
        b.append("        };")
    b.append("    };")
    bodies += b

W("CfgVehicles.hpp", "\n".join(["class CfgVehicles {"] + fwd + [""] + bodies + ["};"]) + "\n")

# ------------------------------------------------------------------ CfgGroups
UAV = "KAR_FDF35_UAV_OP"          # every squad gets the mod's own drone operator
I = "\\A3\\UI_F\\Data\\Map\\Markers\\NATO\\b_inf.paa"
S = "\\A3\\UI_F\\Data\\Map\\Markers\\NATO\\b_support.paa"
RC = "\\A3\\UI_F\\Data\\Map\\Markers\\NATO\\b_recon.paa"
MO = "\\A3\\UI_F\\Data\\Map\\Markers\\NATO\\b_motor_inf.paa"
ME = "\\A3\\UI_F\\Data\\Map\\Markers\\NATO\\b_mech_inf.paa"
AR = "\\A3\\UI_F\\Data\\Map\\Markers\\NATO\\b_armor.paa"
AI = "\\A3\\UI_F\\Data\\Map\\Markers\\NATO\\b_air.paa"

GROUPS = [
 ("Infantry", "Infantry", I, "InfSquad", "Rifle Squad",
  ["KAR_FDF35_SL", "KAR_FDF35_RIF", "KAR_FDF35_RIF", "KAR_FDF35_GRE",
   "KAR_FDF35_MG", "KAR_FDF35_AT", "KAR_FDF35_MED", UAV]),
 ("Infantry", "Infantry", I, "InfTeam", "Fire Team",
  ["KAR_FDF35_SL", "KAR_FDF35_RIF", "KAR_FDF35_GRE", "KAR_FDF35_AT", UAV]),
 ("Infantry", "Infantry", I, "JaegerSquad", "Jaeger Squad",
  ["KAR_FDF35_SIS_SL", "KAR_FDF35_SIS", "KAR_FDF35_SIS", "KAR_FDF35_SIS_AT",
   "KAR_FDF35_SIS_MK", "KAR_FDF35_SIS_MED", "KAR_FDF35_SIS_RADISTI", UAV]),
 ("Support", "Support", S, "ATTeam", "Anti-Tank Team",
  ["KAR_FDF35_SL", "KAR_FDF35_AT", "KAR_FDF35_AT", UAV]),
 ("Support", "Support", S, "AATeam", "Anti-Air Team",
  ["KAR_FDF35_SL", "KAR_FDF35_AA", "KAR_FDF35_AA", UAV]),
 ("Support", "Support", S, "EngTeam", "Engineer Team",
  ["KAR_FDF35_ENG", "KAR_FDF35_EOD", "KAR_FDF35_RADISTI", UAV]),
 ("SpecOps", "Special Forces", RC, "SOFTeam", "SOF Team",
  ["KAR_FDF35_SOF_SL", "KAR_FDF35_SOF_RIF", "KAR_FDF35_SOF_MG",
   "KAR_FDF35_SOF_AT", "KAR_FDF35_SOF_MK", "KAR_FDF35_SOF_MED", UAV]),
 ("SpecOps", "Special Forces", RC, "SOFSniper", "SOF Sniper Team",
  ["KAR_FDF35_SOF_SNI", "KAR_FDF35_SOF_SNI_G", UAV]),
 ("SpecOps", "Special Forces", RC, "SniperTeam", "Sniper Team",
  ["KAR_FDF35_SNI", "KAR_FDF35_MK", UAV]),
]
VGROUPS = [
 ("Motorized", "Motorized", MO, "MotPatrol", "Motorized Patrol",
  ["KAR_FDF35_MRAP_HMG", "KAR_FDF35_MRAP"]),
 ("Motorized", "Motorized", MO, "MotSquad", "Motorized Rifle Squad",
  ["KAR_FDF35_MRAP", "KAR_FDF35_SL", "KAR_FDF35_RIF", "KAR_FDF35_MG",
   "KAR_FDF35_AT", "KAR_FDF35_MED", UAV]),
 ("Motorized", "Motorized", MO, "MJTFPatrol", "MJTF Patrol",
  ["EF_B_MRAP_01_FSV_MJTF_Wdl", "EF_B_MRAP_01_AT_MJTF_Wdl",
   "EF_B_MRAP_01_LAAD_MJTF_Wdl"]),
 ("Mechanized", "Mechanized", ME, "MechSquad", "Mechanized Rifle Squad",
  ["KAR_FDF35_PATRIA360", "KAR_FDF35_SL", "KAR_FDF35_RIF", "KAR_FDF35_MG",
   "KAR_FDF35_AT", "KAR_FDF35_MED", UAV]),
 ("Mechanized", "Mechanized", ME, "MechSection", "Mechanized Section",
  ["KAR_FDF35_PATRIA360", "KAR_FDF35_PATRIA360_ATGM", "KAR_FDF35_PATRIA360_CV"]),
 ("Armored", "Armored", AR, "TankSection", "Tank Section",
  ["KAR_FDF35_LEO2SG", "KAR_FDF35_LEO2SG"]),
 ("Armored", "Armored", AR, "Artillery", "Artillery Battery",
  ["KAR_FDF35_ARTY", "KAR_FDF35_KRH"]),
 ("Armored", "Armored", AR, "AASection", "Anti-Air Section",
  ["KAR_FDF35_ITOMIM", "KAR_FDF35_ITOHJ"]),
 ("Air", "Air", AI, "HeliLight", "Light Helicopter", ["KAR_FDF35_HELI_L"]),
 ("Air", "Air", AI, "HeliTransport", "Transport Helicopter", ["KAR_FDF35_HELIKIPOTER"]),
 ("Air", "Air", AI, "CAS", "Close Air Support", ["KAR_FDF35_F35"]),
]

cats, order = {}, []
skipped = []
for cat, catname, icon, gid, gname, units in GROUPS + VGROUPS:
    us = [u for u in units if u in clone]
    skipped += [u for u in units if u not in clone]
    if not us:
        continue
    if cat not in cats:
        cats[cat] = (catname, []); order.append(cat)
    cats[cat][1].append((icon, gid, gname, us))

g = ["class CfgGroups {", "    class West {", "        class %s {" % FCLS,
     '            name = "[JMSB] %s";' % DISP]
ng = 0
for cat in order:
    catname, gs = cats[cat]
    g.append("            class %s {" % cat)
    g.append('                name = "%s";' % catname)
    for icon, gid, gname, us in gs:
        ng += 1
        g.append("                class GVAR(%s) {" % gid)
        g.append('                    name = "%s";' % gname)
        g.append("                    side = 1;")
        g.append('                    faction = "%s";' % FCLS)
        g.append('                    icon = "%s";' % icon)
        for k, u in enumerate(us):
            x, y = (k % 2) * 5 - 2, -(k * 5)
            g.append("                    class Unit%d {" % k)
            g.append("                        side = 1;")
            g.append('                        vehicle = "%s";' % clone[u])
            g.append('                        rank = "%s";' % ("SERGEANT" if k == 0 else "PRIVATE"))
            g.append("                        position[] = {%d, %d, 0};" % (x, y))
            g.append("                    };")
        g.append("                };")
    g.append("            };")
g += ["        };", "    };", "};"]
W("CfgGroups.hpp", "\n".join(g) + "\n")

units = ",\n            ".join("QGVAR(%s)" % n for n in roster + EXTRA)
reqs = ['"jmfsb_main"', '"KAR_FDF35_Faction"', '"KAR_FDF35_V"', '"KAR_FDF35_U"',
        # weapon pbos the cloned loadouts pull from (verified present in the RPT)
        '"A3_Weapons_F"', '"A3_Weapons_F_Exp"', '"A3_Weapons_F_Exp_Rifles_AK12"',
        '"A3_Weapons_F_Mark"', '"A3_Aegis_Weapons_F_Aegis_Rifles_SCAR"',
        '"A3_Weapons_F_Exp_Rifles_SPAR_01"', '"A3_Weapons_F_Exp_Rifles_SPAR_03"',
        # everything KAR_FDF35_V itself depends on -- the cloned vehicles inherit
        # from these, so they must load first
        '"KAR_FDF35_Faction_W"', '"A3_Aegis_Armor_F_Aegis"',
        '"A3_Armor_F_Beta_APC_Wheeled_01"', '"A3_Armor_F_Beta_APC_Wheeled_02"',
        '"A3_Armor_F_Exp_APC_Wheeled_01"', '"A3_Armor_F_Exp_APC_Wheeled_02"',
        '"A3_Armor_F_EPB_MBT_03"', '"A3_Soft_F_Exp"', '"A3_Soft_F_MRAP_01"',
        '"A3_Armor_F_Exp_MBT_01"', '"A3_Air_F_Exp_UAV_03"', '"A3_Characters_F_BLUFOR"',
        '"jmfsbfa_ammo"', '"jmfsbfa_vehicles"', '"jmfsbfa_maincaliber"',
        '"jmfsbfa_mediumcaliber"', '"jmfsbfa_grenade_40mm"', '"jmfsbfa_missiles"']
W("config.cpp", '''#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            %s
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            %s
        };
        skipWhenMissingDependencies = 1;
        authorUrl = "https://github.com/Joint-Multi-Functional-Strike-Battalion/";
        author = QAUTHOR;
        authors[] = {"JMSB"};
        VERSION_CONFIG;
    };
};

#include "CfgEditorCategories.hpp"
#include "CfgFactionClasses.hpp"
#include "CfgVehicles.hpp"
#include "CfgGroups.hpp"
''' % (units, ",\n            ".join(reqs)))

print("units cloned: %d (roster %d + extra %d)" % (len(roster) + len(EXTRA), len(roster), len(EXTRA)))
print("FA magazine swaps: %d   turret swaps: %d" % (nmag, ntur))
print("groups: %d   squads with a UAV operator: %d" % (ng, sum(
    1 for _c, _cn, _i, _g, _n, u in GROUPS + VGROUPS if UAV in u)))
if skipped:
    print("group slots skipped (class not in roster):", sorted(set(skipped)))
