"""Rebuild the US BLUFOR factions as 1:1 clones of the four NATO factions
(vanilla + Aegis/Atlas), with futureAmmo ammunition.

  MX   = exact clone of the source faction, ammo -> FA
  SPAR = same, with the MX-family primary swapped for the SPAR family

Gear (uniform/vest/helmet/backpack/linkedItems) is NEVER touched -- units keep
whatever the source faction issues them.
"""
import os, io, json, re, collections

D = os.path.dirname(os.path.abspath(__file__))
BASE = r"O:\GIT\jmfsb\addons"

A3C = json.load(io.open(os.path.join(D, "a3_classes.json"), encoding="utf-8"))
A3G = json.load(io.open(os.path.join(D, "a3_groups.json"), encoding="utf-8"))
MDC = json.load(io.open(os.path.join(D, "mod_classes.json"), encoding="utf-8"))
MDG = json.load(io.open(os.path.join(D, "mod_groups.json"), encoding="utf-8"))
FA_EXISTS = set(io.open(os.path.join(D, "fa_classes.txt")).read().split())

# merged class table: mod entries win on props they define, vanilla fills the rest
C = {}
for src in (A3C, MDC):
    for k, v in src.items():
        C.setdefault(k, {}).update(v)
CI = {k.lower(): k for k in C}

FACTIONS = {                       # camo -> (source faction, tracer colour)
    "arid":     ("BLU_F",         "Red"),
    "desert":   ("BLU_NATO_lxWS", "Red"),
    "tropical": ("BLU_T_F",       "Green"),
    "woodland": ("BLU_W_F",       "Green"),
    # camo variants with no source faction of their own: BLU_F roster re-dressed
    # in the jmfsb OCP / Multicam-Snow gear ported from ACP
    "ocp":      ("BLU_F",         "Red"),
    "snow":     ("BLU_F",         "Red"),
}

# Gear re-dress. Everything is matched off the unit's existing kit, so roles keep
# their relative loadout (a GL carrier stays a GL carrier, a light rig stays
# light). Applied to EVERY faction: the source rosters mix vanilla, Aegis and
# Atlas units, so an un-dressed faction fields 11-16 different vests -- ranger
# green chest rigs next to MTP carriers next to arid ones.
def _vest_set(suffix, jmfsb=True):
    p = "jmfsb_vests_V_PlateCarrier" if jmfsb else "V_PlateCarrier"
    return {
        "V_PlateCarrier1":    "%s1%s" % (p, suffix),
        "V_PlateCarrier2":    "%s2%s" % (p, suffix),
        "V_PlateCarrierGL":   "%sGL%s" % (p, suffix),
        "V_PlateCarrierSpec": "%s2%s" % (p, suffix),   # no special-purpose rigs
        "V_PlateCarrierH":    "%sH_CTRG%s" % (p, suffix),
        "V_PlateCarrierL":    "%sL_CTRG%s" % (p, suffix),
    }


GEAR = {
    "arid": {
        "uniform": "U_B_CombatUniform_mcam",
        "vest": _vest_set("_mcam"),
        "vest_default": "jmfsb_vests_V_PlateCarrier1_mcam",
        "helmet": "jmfsb_headware_H_Helmet_FASTMT_Cover_Multicam_F",
        "hat":    "jmfsb_headware_H_Booniehat_Multicam_F",
        "bag": {
            "Kitbag":       "jmfsb_backpack_Kitbag_Multicam",
            "Carryall":     "jmfsb_backpack_Carryall_Multicam",
            "FieldPack":    "jmfsb_backpack_FieldPack_Multicam",
            "AssaultPack":  "jmfsb_backpack_AssaultPack_Multicam",
            "TacticalPack": "jmfsb_backpack_TacticalPack_Multicam",
            "Bergen":       "jmfsb_backpack_Bergen_Multicam",
            "RadioBag":     "jmfsb_backpack_B_RadioBag_01_Multicam",
        },
        "bag_default": "jmfsb_backpack_AssaultPack_Multicam",
    },
    "woodland": {
        "uniform": "U_B_CombatUniform_mcam_wdl_f",
        "vest": _vest_set("_mcam_wdl"),
        "vest_default": "jmfsb_vests_V_PlateCarrier1_mcam_wdl",
        "helmet": "jmfsb_headware_H_Helmet_FASTMT_Cover_wdl_F",
        "hat":    "jmfsb_headware_H_Booniehat_Multicam_Woodland_F",
        "bag": {
            "Kitbag":       "jmfsb_backpack_Kitbag_Multicam_Woodland",
            "Carryall":     "jmfsb_backpack_Carryall_Multicam_Woodland",
            "FieldPack":    "jmfsb_backpack_FieldPack_Multicam_Woodland",
            "AssaultPack":  "jmfsb_backpack_AssaultPack_Multicam_Woodland",
            "TacticalPack": "jmfsb_backpack_TacticalPack_Multicam_Woodland",
            "Bergen":       "jmfsb_backpack_Bergen_Multicam_Woodland",
            "RadioBag":     "jmfsb_backpack_B_RadioBag_01_Multicam_Woodland",
        },
        "bag_default": "jmfsb_backpack_AssaultPack_Multicam_Woodland",
    },
    # no jmfsb vests in tropic/desert patterns -- use the vanilla families, which
    # are coherent sets in their own right
    "tropical": {
        "uniform": "U_B_T_Soldier_F",
        # vanilla tropic carriers (verified present); no CTRG rigs in this pattern
        "vest": {
            "V_PlateCarrier1":    "V_PlateCarrier1_tna_F",
            "V_PlateCarrier2":    "V_PlateCarrier2_tna_F",
            "V_PlateCarrierGL":   "V_PlateCarrierGL_tna_F",
            "V_PlateCarrierSpec": "V_PlateCarrier2_tna_F",
            "V_PlateCarrierH":    "V_PlateCarrier2_tna_F",
            "V_PlateCarrierL":    "V_PlateCarrier1_tna_F",
        },
        "vest_default": "V_PlateCarrier1_tna_F",
        "helmet": "jmfsb_headware_H_Helmet_FASTMT_Cover_tna_F",
        "hat":    "jmfsb_headware_H_Booniehat_Solid_Ranger_Green_F",
        "bag": {
            "Kitbag":       "jmfsb_backpack_Kitbag_Solid_Ranger_Green",
            "Carryall":     "jmfsb_backpack_Carryall_Solid_Ranger_Green",
            "FieldPack":    "jmfsb_backpack_FieldPack_Solid_Ranger_Green",
            "AssaultPack":  "jmfsb_backpack_AssaultPack_Solid_Ranger_Green",
            "TacticalPack": "jmfsb_backpack_TacticalPack_Solid_Ranger_Green",
            "Bergen":       "jmfsb_backpack_Bergen_Solid_Ranger_Green",
            "RadioBag":     "jmfsb_backpack_B_RadioBag_01_Solid_Ranger_Green",
        },
        "bag_default": "jmfsb_backpack_AssaultPack_Solid_Ranger_Green",
    },
    "desert": {
        "uniform": "U_lxWS_B_CombatUniform_desert",
        # Western Sahara desert carriers -- note the V_lxWS_ prefix
        "vest": {
            "V_PlateCarrier1":    "V_lxWS_PlateCarrier1_desert",
            "V_PlateCarrier2":    "V_lxWS_PlateCarrier2_desert",
            "V_PlateCarrierGL":   "V_lxWS_PlateCarrierGL_desert",
            "V_PlateCarrierSpec": "V_lxWS_PlateCarrierSpec_desert",
            "V_PlateCarrierH":    "V_lxWS_PlateCarrier2_desert",
            "V_PlateCarrierL":    "V_lxWS_PlateCarrier1_desert",
        },
        "vest_default": "V_lxWS_PlateCarrier1_desert",
        "helmet": "jmfsb_headware_H_Helmet_FASTMT_Cover_desert_F",
        "hat":    "jmfsb_headware_H_Booniehat_Solid_CoyoteBrown_F",
        "bag": {
            "Kitbag":       "jmfsb_backpack_Kitbag_Solid_CoyoteBrown",
            "Carryall":     "jmfsb_backpack_Carryall_Solid_CoyoteBrown",
            "FieldPack":    "jmfsb_backpack_FieldPack_Solid_CoyoteBrown",
            "AssaultPack":  "jmfsb_backpack_AssaultPack_Solid_CoyoteBrown",
            "TacticalPack": "jmfsb_backpack_TacticalPack_Solid_CoyoteBrown",
            "Bergen":       "jmfsb_backpack_Bergen_Solid_CoyoteBrown",
            "RadioBag":     "jmfsb_backpack_B_RadioBag_01_Solid_CoyoteBrown",
        },
        "bag_default": "jmfsb_backpack_AssaultPack_Solid_CoyoteBrown",
    },
    "ocp": {
        "uniform": "jmfsb_uniform_U_B_CombatUniform_ocp_F",
        "vest": {
            "V_PlateCarrier1":    "jmfsb_vests_V_PlateCarrier1_ocp",
            "V_PlateCarrier2":    "jmfsb_vests_V_PlateCarrier2_ocp",
            "V_PlateCarrierGL":   "jmfsb_vests_V_PlateCarrierGL_ocp",
            "V_PlateCarrierSpec": "jmfsb_vests_V_PlateCarrier2_ocp",
            "V_PlateCarrierH":    "jmfsb_vests_V_PlateCarrierH_CTRG_ocp",
            "V_PlateCarrierL":    "jmfsb_vests_V_PlateCarrierL_CTRG_ocp",
        },
        "vest_default": "jmfsb_vests_V_PlateCarrier1_ocp",
        "helmet": "jmfsb_headware_H_Helmet_FASTMT_Cover_US_OCP_F",
        "hat":    "jmfsb_headware_H_Booniehat_ocp_F",
        "facewear": "jmfsb_headware_G_Balaclava_US_OCP",
        "bag": {
            "Kitbag":     "jmfsb_backpack_Kitbag_ocp",
            "Bergen":     "jmfsb_backpack_Bergen_ocp",
            "Carryall":   "jmfsb_backpack_Carryall_ocp",
            "FieldPack":  "jmfsb_backpack_FieldPack_ocp",
            "AssaultPack": "jmfsb_backpack_AssaultPack_ocp",
            "TacticalPack": "jmfsb_backpack_TacticalPack_ocp",
        },
        "bag_default": "jmfsb_backpack_AssaultPack_ocp",
    },
    "snow": {
        "uniform": "jmfsb_uniform_U_B_CombatUniform_snow_F",
        "vest": {
            "V_PlateCarrier1":    "jmfsb_vests_V_PlateCarrier1_mcam_snow",
            "V_PlateCarrier2":    "jmfsb_vests_V_PlateCarrier2_mcam_snow",
            "V_PlateCarrierGL":   "jmfsb_vests_V_PlateCarrierGL_mcam_snow",
            "V_PlateCarrierSpec": "jmfsb_vests_V_PlateCarrier2_mcam_snow",
            "V_PlateCarrierH":    "jmfsb_vests_V_PlateCarrierH_CTRG_mcam_snow",
            "V_PlateCarrierL":    "jmfsb_vests_V_PlateCarrierL_CTRG_mcam_snow",
        },
        "vest_default": "jmfsb_vests_V_PlateCarrier1_mcam_snow",
        "helmet": "jmfsb_headware_H_Helmet_FASTMT_Cover_Multicam_Snow_F",
        "hat":    "jmfsb_headware_H_Booniehat_Multicam_Snow_F",
        "facewear": "jmfsb_headware_G_Balaclava_Multicam_Snow",
        "bag": {
            "Kitbag":     "jmfsb_backpack_Kitbag_Multicam_Snow",
            "Bergen":     "jmfsb_backpack_Bergen_Multicam_Snow",
            "Carryall":   "jmfsb_backpack_Carryall_Multicam_Snow",
            "FieldPack":  "jmfsb_backpack_FieldPack_Multicam_Snow",
            "AssaultPack": "jmfsb_backpack_AssaultPack_Multicam_Snow",
            "TacticalPack": "jmfsb_backpack_TacticalPack_Multicam_Snow",
            "RadioBag":   "jmfsb_backpack_B_RadioBag_01_Multicam_Snow",
        },
        "bag_default": "jmfsb_backpack_AssaultPack_Multicam_Snow",
    },
}


# The four source-faction camos keep all their issued kit (user: "leave the
# uniforms where they are just use them") but still get a faction-appropriate
# combat uniform forced on. Vanilla classes, no new jmfsb retextures.
UNIFORM_ONLY = {
    "arid":     "U_B_CombatUniform_mcam",
    "desert":   "U_lxWS_B_CombatUniform_desert",
    "tropical": "U_B_T_Soldier_F",
    "woodland": "U_B_CombatUniform_mcam_wdl_f",
}


def uniform_for(camo):
    if camo in GEAR:
        return GEAR[camo]["uniform"]
    return UNIFORM_ONLY.get(camo)


def regear(camo, linked, bag):
    """-> (new linkedItems, new backpack) for a camo-variant faction.

    Slot is matched anywhere in the name, not just at the start: mod gear is
    prefixed (Aegis_V_PlateCarrier2_alt_MTP, Aegis_H_Helmet_FASTMT_Cover_MTP_F)
    and a startswith() test lets all of it through in the wrong camo.
    """
    g = GEAR[camo]
    out = []
    for it in linked or []:
        low = it.lower()
        if re.search(r'(^|_)V_', it):                       # vest
            key = next((k for k in g["vest"] if k.lower().lstrip("v_") in low), None)
            out.append(g["vest"][key] if key else g["vest_default"])
        elif re.search(r'(^|_)H_', it):                     # headgear
            soft = any(w in low for w in ("booniehat", "cap", "beret", "bandanna",
                                          "watchcap", "beanie", "shemag", "turban"))
            out.append(g["hat"] if soft else g["helmet"])
        elif re.search(r'(^|_)G_', it) and g.get("facewear"):
            out.append(g["facewear"])
        else:
            out.append(it)
    nb = None
    if bag:
        key = next((k for k in g["bag"] if k.lower() in bag.lower()), None)
        nb = g["bag"][key] if key else g["bag_default"]
    return out, nb
FAMILIES = {"mxc": False, "spar": True}

# --------------------------------------------------------------------------
# magazine mapping.  value = FA base name; _T_<colour> is appended when that
# tracer variant actually exists in futureAmmo.  Anything not listed keeps its
# vanilla magazine (pistols, grenades, smoke, mines, NLAW/MRAWS, CM flares,
# and every turret weapon FA does not wire).
# --------------------------------------------------------------------------
MAP = {
    # 6.5 caseless
    "30Rnd_65x39_caseless_mag":              "FA_30Rnd_65_EPR",
    "30Rnd_65x39_caseless_mag_Tracer":       "FA_30Rnd_65_EPR",
    "30Rnd_65x39_caseless_black_mag":        "FA_30Rnd_65_EPR_Black",
    "30Rnd_65x39_caseless_black_mag_Tracer": "FA_30Rnd_65_EPR_Black",
    "30Rnd_65x39_caseless_khaki_mag":        "FA_30Rnd_65_EPR_Khaki",
    "30Rnd_65x39_caseless_khaki_mag_Tracer": "FA_30Rnd_65_EPR_Khaki",
    "100Rnd_65x39_caseless_mag":             "FA_100Rnd_65_Mk328",
    "100Rnd_65x39_caseless_mag_Tracer":      "FA_100Rnd_65_Mk328",
    "100Rnd_65x39_caseless_black_mag":       "FA_100Rnd_65_Mk328_Black",
    "100Rnd_65x39_caseless_khaki_mag":       "FA_100Rnd_65_Mk328_Khaki",
    "200Rnd_65x39_cased_Box":                "FA_200Rnd_65_Mk328",
    "200Rnd_65x39_cased_Box_Tracer":         "FA_200Rnd_65_Mk328",
    # 5.56
    "30Rnd_556x45_Stanag":                   "FA_30Rnd_556_Mk327_HV",
    "30Rnd_556x45_Stanag_red":               "FA_30Rnd_556_Mk327_HV",
    "30Rnd_556x45_Stanag_Tracer_Red":        "FA_30Rnd_556_Mk327_HV",
    "20Rnd_556x45_UW_mag":                   "FA_30Rnd_556_Mk327_HV",
    # 7.62
    "20Rnd_762x51_Mag":                      "FA_20Rnd_762_M80A2_HV",
    "150Rnd_762x54_Box":                     "FA_150Rnd_762x54_Box",
    # .338 / .408
    "10Rnd_338_Mag":                         "FA_10Rnd_338_Mk371_300gr",
    "130Rnd_338_Mag":                        "FA_130Rnd_338_Mk372",
    "7Rnd_408_Mag":                          "FA_10Rnd_408_Mk240",
    # 40mm UGL
    "1Rnd_HE_Grenade_shell":                 "FA_1Rnd_40mm_Mk380_NRP",
    "3Rnd_HE_Grenade_shell":                 "FA_1Rnd_40mm_Mk380_NRP",
    # launchers
    "Titan_AA":                              "FA_Titan_AA_MIM165_Sentry",
    "Titan_AT":                              "FA_Titan_AT_BGM185_Broadsword",
}
# turret magazines (only weapons futureAmmo actually wires)
TMAP = {
    "200Rnd_762x51_Belt_Red":                "FA_200Rnd_762_M80A2_HV",
    "200Rnd_762x51_Belt_Tracer_Red":         "FA_200Rnd_762_M80A2_HV",
    "100Rnd_127x99_mag_Tracer_Red":          "FA_200Rnd_127_Mk258",
    "200Rnd_127x99_mag_Tracer_Red":          "FA_200Rnd_127_Mk258",
    "500Rnd_127x99_mag_Tracer_Red":          "FA_200Rnd_127_Mk258",
    "200Rnd_338_Mag":                        "FA_200Rnd_338_Mk372",
    "130Rnd_338_Mag":                        "FA_130Rnd_338_Mk372",
    "2000Rnd_65x39_Belt_Tracer_Red":         "FA_200Rnd_65_Mk328",
    "2000Rnd_65x39_belt_Tracer_Red":         "FA_200Rnd_65_Mk328",
    "12Rnd_120mm_APFSDS_shells_Tracer_Red":  "FA_30Rnd_120mm_APFSDS",
    "24Rnd_120mm_APFSDS_shells_Tracer_Red":  "FA_30Rnd_120mm_APFSDS",
    "8Rnd_120mm_HE_shells_Tracer_Red":       "FA_30Rnd_120mm_AMP",
    "12Rnd_120mm_HE_shells_Tracer_Red":      "FA_30Rnd_120mm_AMP",
    "8Rnd_120mm_HEAT_MP_T_Red":              "FA_30Rnd_120mm_HEATMP",
    "12Rnd_120mm_HEAT_MP_T_Red":             "FA_30Rnd_120mm_HEATMP",
    "680Rnd_35mm_AA_shells_Tracer_Red":      "FA_680Rnd_35mm_AHEAD",
    "32Rnd_155mm_Mo_shells":                 "FA_32Rnd_155mm_heer_B",
    "4Rnd_155mm_Mo_guided":                  "FA_4Rnd_155mm_apmi_B",
    "6Rnd_155mm_Mo_mine":                    "FA_6Rnd_155mm_apmine_B",
    "2Rnd_155mm_Mo_Cluster":                 "FA_2Rnd_155mm_sfm_B",
    "6Rnd_155mm_Mo_smoke":                   "FA_6Rnd_155mm_smk_B",
    "2Rnd_155mm_Mo_LG":                      "FA_4Rnd_155mm_lgm_B",
    "6Rnd_155mm_Mo_AT_mine":                 "FA_6Rnd_155mm_atmine_B",
    "12Rnd_230mm_rockets":                   "FA_12Rnd_230mm_gmlrsu_B",
}

UNMAPPED = collections.Counter()

# Mod drones every US faction fields, carried over from the pre-rebuild build.
# These are CfgVehicles units, never CfgGroups entries. Their owning mods are
# deliberately NOT added to requiredAddons: skipWhenMissingDependencies would
# drop the whole faction if one drone mod were absent (the old build made the
# same call).
# QAV / VVE mod vehicles the pre-rebuild US factions fielded (Abrams-X, the
# wheeled Marshall family, Ripsaw). Units only -- no CfgGroups slots -- and the
# owning mods ARE in requiredAddons, since they are already verified loaded.
QAV_VEHICLES = [
    "qav_abramsx_templar",
    "qav_abramsx_tusk",
    "VVE_APC_Wheeled_01_apc_QAV",
    "VVE_APC_Wheeled_01_mgs_QAV",
    "VVE_APC_Wheeled_01_mgs_up_QAV",
    "VVE_APC_Wheeled_01_shorad_QAV",
]

# Extra properties stamped onto a cloned class, on top of the usual
# scope/side/faction. Vanilla values are in the comments; for audible and
# camouflage LOWER is stealthier (Helicopter base is 50 / 100).
OVERRIDES = {
    "B_Heli_Transport_01_F": [
        ('displayName = "UH-80 Ghost Hawk (Ultra Stealth)";', None),
        ("radarTargetSize = 0.2;", "vanilla 0.7"),
        ("irTargetSize = 0.3;", "vanilla 0.8"),
        ("audible = 2;", "vanilla 50 (Helicopter base)"),
        ("camouflage = 0.8;", "vanilla 100 (Helicopter base)"),
    ],
}

# Vanilla classes every US faction fields whatever its camo. The tropical and
# woodland source factions issue only their own re-textured Ghosthawk, so the
# base green one has to be added back by hand. Roster members, not drone-style
# clone-only extras, so they get the tracer/weapon treatment and pull their
# owning pbo into requiredAddons like anything else.
ALWAYS = [
    "B_Heli_Transport_01_F",
]

DRONES = [
    "B_T_UAV_03_dynamicLoadout_F",
    "B_UAV_RC40_HE_RF",
    "B_UAV_RC40_SENSOR_RF",
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


def fa_of(mag, col, table):
    """vanilla magazine -> FA magazine (tracer-coloured when available)."""
    base = table.get(mag)
    if not base:
        return None
    tinted = "%s_T_%s" % (base, col)
    if tinted in FA_EXISTS:
        return tinted
    if base in FA_EXISTS:
        return base
    UNMAPPED[base] += 1
    return None


# --------------------------------------------------------------------------
# class-table helpers
# --------------------------------------------------------------------------
def real(n):
    k = CI.get((n or "").lower())
    return k


def chain(n):
    out, seen = [], set()
    k = real(n)
    while k and k not in seen:
        seen.add(k); out.append(k)
        k = real(C[k].get("parent"))
    return out


def res(n, key):
    for k in chain(n):
        if key in C[k]:
            return C[k][key]
    return None


def res_turrets(n):
    """merged turret magazines down the parent chain (child wins)"""
    acc = {}
    for k in reversed(chain(n)):
        for path, d in (C[k].get("turrets") or {}).items():
            if d.get("magazines") is not None:
                acc[path] = d["magazines"]
    return acc


def roster_of(fac):
    mem = set()
    for n in C:
        if res(n, "faction") == fac and res(n, "scope") == "2":
            mem.add(n)
    for GS in (A3G, MDG):
        if fac in GS:
            for cat in GS[fac]["cats"].values():
                for g in cat["groups"].values():
                    for u in g["units"]:
                        k = real(u["vehicle"])
                        if k:
                            mem.add(k)
    return mem


# --------------------------------------------------------------------------
# SPAR weapon swap
# --------------------------------------------------------------------------
SPAR16 = "arifle_SPAR_01_blk_F"
SPAR16GL = "arifle_SPAR_01_GL_blk_F"
SPAR17 = "arifle_SPAR_03_blk_F"


def spar_swap(weps):
    """MX-family primary -> SPAR family. returns (new weapons, ammo-class)"""
    out, cal = [], None
    for w in weps:
        lw = w.lower()
        if lw.startswith("arifle_mx_gl") or lw.startswith("arifle_mx_sw") and False:
            out.append(SPAR16GL); cal = "556"
        elif lw.startswith("arifle_mx_gl"):
            out.append(SPAR16GL); cal = "556"
        elif lw.startswith("arifle_mx_sw"):
            out.append(SPAR17); cal = "762"
        elif lw.startswith("arifle_mxm"):
            out.append(SPAR17); cal = "762"
        elif lw.startswith("arifle_mxc") or lw.startswith("arifle_mx_"):
            out.append(SPAR16); cal = "556"
        elif lw.startswith("arifle_mx"):
            out.append(SPAR16); cal = "556"
        else:
            out.append(w)
    return out, cal


SPAR_MAG = {"556": "FA_30Rnd_556_Mk327_HV", "762": "FA_20Rnd_762_M80A2_HV"}
SIXFIVE = ("30Rnd_65x39", "100Rnd_65x39", "200Rnd_65x39")


def q(s):
    return '"%s"' % s


def arr_lines(name, items, ind):
    if not items:
        return []
    out = ["%s%s[] = {" % (ind, name)]
    for i, it in enumerate(items):
        out.append("%s    %s%s" % (ind, q(it), "," if i < len(items) - 1 else ""))
    out.append("%s};" % ind)
    return out
