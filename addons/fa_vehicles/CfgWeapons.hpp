// =====================================================================
//  futureAmmo compat: shared vanilla vehicle secondary weapons
//  The QAV/VVE compat addons cover the mod-specific (vve_ / qav_) weapon
//  subclasses; this addon covers the VANILLA base weapons those vehicles (and
//  every other A3 vehicle) mount directly:
//    - 7.62 coax / RCWS      -> LMG_coax, LMG_RCWS
//    - .338 coax (SPMG)      -> MMG_02_coax, MMG_02_coax_amv  (Marshall ATGM)
//    - .50 commander / APC   -> HMG_127_MBT, HMG_127_APC, HMG_127_AFV  (Rhino commander)
//  These weapons hold their magazine list directly (no CBA wells), so every
//  append is `+=` on the existing shared class - same rule as jmfsbfa_missiles.
//  The belts already exist in jmfsbfa_ammo; this only wires them.
// =====================================================================

#define FA_MAGS_762 \
    "FA_b_200Rnd_762_M80A2_HV", "FA_200Rnd_762_M80A2_HV", \
    "FA_b_200Rnd_762_M80A2_HV_T_Red", "FA_200Rnd_762_M80A2_HV_T_Red", "FA_b_200Rnd_762_M80A2_HV_T_Yellow", "FA_200Rnd_762_M80A2_HV_T_Yellow", "FA_b_200Rnd_762_M80A2_HV_T_Green", "FA_200Rnd_762_M80A2_HV_T_Green", \
    "FA_b_200Rnd_762_M80A2_HV_T_White", "FA_200Rnd_762_M80A2_HV_T_White", "FA_b_200Rnd_762_M80A2_HV_T_Blue", "FA_200Rnd_762_M80A2_HV_T_Blue", "FA_b_200Rnd_762_M80A2_HV_T_Orange", "FA_200Rnd_762_M80A2_HV_T_Orange", "FA_b_200Rnd_762_M80A2_HV_T_IR", "FA_200Rnd_762_M80A2_HV_T_IR", \
    "FA_b_200Rnd_762_XM751_CTEP", "FA_200Rnd_762_XM751_CTEP", \
    "FA_b_200Rnd_762_XM751_CTEP_T_Red", "FA_200Rnd_762_XM751_CTEP_T_Red", "FA_b_200Rnd_762_XM751_CTEP_T_Yellow", "FA_200Rnd_762_XM751_CTEP_T_Yellow", "FA_b_200Rnd_762_XM751_CTEP_T_Green", "FA_200Rnd_762_XM751_CTEP_T_Green", \
    "FA_b_200Rnd_762_XM751_CTEP_T_White", "FA_200Rnd_762_XM751_CTEP_T_White", "FA_b_200Rnd_762_XM751_CTEP_T_Blue", "FA_200Rnd_762_XM751_CTEP_T_Blue", "FA_b_200Rnd_762_XM751_CTEP_T_Orange", "FA_200Rnd_762_XM751_CTEP_T_Orange", "FA_b_200Rnd_762_XM751_CTEP_T_IR", "FA_200Rnd_762_XM751_CTEP_T_IR"

#define FA_MAGS_338 \
    "FA_b_200Rnd_338_Mk372", "FA_200Rnd_338_Mk372", \
    "FA_b_200Rnd_338_Mk372_T_Red", "FA_200Rnd_338_Mk372_T_Red", "FA_b_200Rnd_338_Mk372_T_Yellow", "FA_200Rnd_338_Mk372_T_Yellow", "FA_b_200Rnd_338_Mk372_T_Green", "FA_200Rnd_338_Mk372_T_Green", \
    "FA_b_200Rnd_338_Mk372_T_White", "FA_200Rnd_338_Mk372_T_White", "FA_b_200Rnd_338_Mk372_T_Blue", "FA_200Rnd_338_Mk372_T_Blue", "FA_b_200Rnd_338_Mk372_T_Orange", "FA_200Rnd_338_Mk372_T_Orange", "FA_b_200Rnd_338_Mk372_T_IR", "FA_200Rnd_338_Mk372_T_IR"

#define FA_MAGS_50CAL \
    "FA_b_200Rnd_127_Mk211Mod0", "FA_200Rnd_127_Mk211Mod0", \
    "FA_b_200Rnd_127_Mk211Mod0_T_Red", "FA_200Rnd_127_Mk211Mod0_T_Red", "FA_b_200Rnd_127_Mk211Mod0_T_Yellow", "FA_200Rnd_127_Mk211Mod0_T_Yellow", "FA_b_200Rnd_127_Mk211Mod0_T_Green", "FA_200Rnd_127_Mk211Mod0_T_Green", \
    "FA_b_200Rnd_127_Mk211Mod0_T_White", "FA_200Rnd_127_Mk211Mod0_T_White", "FA_b_200Rnd_127_Mk211Mod0_T_Blue", "FA_200Rnd_127_Mk211Mod0_T_Blue", "FA_b_200Rnd_127_Mk211Mod0_T_Orange", "FA_200Rnd_127_Mk211Mod0_T_Orange", "FA_b_200Rnd_127_Mk211Mod0_T_IR", "FA_200Rnd_127_Mk211Mod0_T_IR", \
    "FA_b_200Rnd_127_Mk258", "FA_200Rnd_127_Mk258", \
    "FA_b_200Rnd_127_Mk258_T_Red", "FA_200Rnd_127_Mk258_T_Red", "FA_b_200Rnd_127_Mk258_T_Yellow", "FA_200Rnd_127_Mk258_T_Yellow", "FA_b_200Rnd_127_Mk258_T_Green", "FA_200Rnd_127_Mk258_T_Green", \
    "FA_b_200Rnd_127_Mk258_T_White", "FA_200Rnd_127_Mk258_T_White", "FA_b_200Rnd_127_Mk258_T_Blue", "FA_200Rnd_127_Mk258_T_Blue", "FA_b_200Rnd_127_Mk258_T_Orange", "FA_200Rnd_127_Mk258_T_Orange", "FA_b_200Rnd_127_Mk258_T_IR", "FA_200Rnd_127_Mk258_T_IR"

// Each shared weapon is reopened WITH its real parent named (and that parent
// forward-declared). A parentless reopen (`class LMG_coax { ... };`) makes HEMTT
// emit the class with no base, and when other mods (ACE / EF / Aegis) also reopen
// these same coax/HMG classes with undefined load order, the parentless one can
// win the bind and STRIP the vanilla parent link — collapsing the weapon, and
// everything that inherits it (LMG_coax_ext, ACE_/EF_ coax variants), to an empty
// scope=private stub. Naming the parent keeps the inheritance intact regardless
// of load order. Parents per vanilla: LMG_coax:LMG_RCWS:MGun, MMG_02_coax:
// MMG_02_vehicle, MMG_02_coax_amv:MMG_02_coax, HMG_127_APC/AFV:HMG_127,
// HMG_127_MBT:HMG_127_APC.
class CfgWeapons {
    // 7.62 coax + RCWS
    class MGun;
    class LMG_RCWS: MGun     { magazines[] += { FA_MAGS_762 }; };
    class LMG_coax: LMG_RCWS { magazines[] += { FA_MAGS_762 }; };

    // .338 coax (SPMG-based; _amv is the Aegis Marshall ATGM variant)
    class MMG_02_vehicle;
    class MMG_02_coax: MMG_02_vehicle  { magazines[] += { FA_MAGS_338 }; };
    class MMG_02_coax_amv: MMG_02_coax { magazines[] += { FA_MAGS_338 }; };

    // .50 commander / APC HMG
    class HMG_127;
    class HMG_127_APC: HMG_127     { magazines[] += { FA_MAGS_50CAL }; };
    class HMG_127_AFV: HMG_127     { magazines[] += { FA_MAGS_50CAL }; };
    class HMG_127_MBT: HMG_127_APC { magazines[] += { FA_MAGS_50CAL }; };  // Rhino commander HMG

    // -------------------------------------------------------------------
    // Heavy fires — vanilla artillery weapons.
    //
    // mortar_155mm_AMOS (shared by the M4 Scorcher B_MBT_01_arty_F — the "Sholef"
    // — and the 2S9 Sochor O_MBT_02_arty_F) is NO LONGER reopened here: its shells
    // now ride the ACE_155mm_artillery magazine well, see CfgMagazineWells.hpp.
    // Only the forward declaration remains, so weapon_ShipCannon_120mm below can
    // name it as its parent. A bare `class X;` is a declaration, not a reopen, so
    // it cannot strip AMOS -> CannonCore the way a parentless body would.
    // AMOS is defined in A3_Weapons_F (verified against a derapified weapons_f.pbo;
    // armor_f_gamma only mounts it on the SPG turrets).
    //
    // The 82mm / 230mm / 120mm naval guns below stay on magazines[] +=: neither
    // vanilla nor ACE/CBA define a magazine well for any of them, so a well here
    // would need us to reopen the weapon anyway to attach it — no gain. They do
    // each NAME their vanilla parent, same rule as the coax/HMG block above.
    // Parents per derapified weapons_f.pbo (all A3_Weapons_F): mortar_82mm:
    // CannonCore, rockets_230mm_GAT:RocketPods, HMG_NSVT:HMG_127.
    // -------------------------------------------------------------------
    class mortar_155mm_AMOS;
    class CannonCore;
    class RocketPods;
    // CSAT 12.7x108 heavy MG (HMG_NSVT / Kord) — HMG_127 declared with the .50s above
    class HMG_NSVT: HMG_127 {
        magazines[] += {
            "FA_450Rnd_127x108_7N40",
            "FA_450Rnd_127x108_7N41",
            "FA_450Rnd_127x108_7N42"
        };
    };
    // 230mm GAT MLRS — Seara / Zamak MLRS
    class rockets_230mm_GAT: RocketPods {
        magazines[] += {
            "FA_12Rnd_230mm_gmlrsu_B", "FA_12Rnd_230mm_gmlrsu_O", "FA_12Rnd_230mm_gmlrsu_I",
            "FA_12Rnd_230mm_gmlrser_B", "FA_12Rnd_230mm_gmlrser_O", "FA_12Rnd_230mm_gmlrser_I",
            "FA_12Rnd_230mm_aw_B", "FA_12Rnd_230mm_aw_O", "FA_12Rnd_230mm_aw_I"
        };
    };
    // 82mm Mk6 mortar (vanilla) — shared by B/O/I_Mortar_01_F.
    class mortar_82mm: CannonCore {
        magazines[] += {
            "FA_8Rnd_82mm_apmi_B", "FA_8Rnd_82mm_apmi_O", "FA_8Rnd_82mm_apmi_I",
            "FA_8Rnd_82mm_lgm_B", "FA_8Rnd_82mm_lgm_O", "FA_8Rnd_82mm_lgm_I",
            "FA_8Rnd_82mm_heer_B", "FA_8Rnd_82mm_heer_O", "FA_8Rnd_82mm_heer_I",
            "FA_8Rnd_82mm_strix_B", "FA_8Rnd_82mm_strix_O", "FA_8Rnd_82mm_strix_I",
            "FA_8Rnd_82mm_smk_B", "FA_8Rnd_82mm_smk_O", "FA_8Rnd_82mm_smk_I",
            "FA_8Rnd_82mm_tb_B", "FA_8Rnd_82mm_tb_O", "FA_8Rnd_82mm_tb_I",
            "FA_8Rnd_82mm_ir_B"
        };
    };
    // Mk45 Hammer naval gun (vanilla) — West-only. Name the real vanilla parent
    // (weapon_ShipCannon_120mm: mortar_155mm_AMOS, forward-declared above) rather
    // than reopening it parentless: a parentless reopen can win the bind under
    // undefined load order and strip the vanilla parent link, collapsing the gun
    // to a scope=private stub (it inherits scope down the mortar chain, its own
    // body sets none). The gun overrides magazines[] with = to its seven ship
    // shells, so this += appends our FA rounds onto those, not the 155mm mortar
    // mags — inheriting the parent does not pull those in.
    class weapon_ShipCannon_120mm: mortar_155mm_AMOS {
        magazines[] += {
            "FA_2Rnd_120N_glr",
            "FA_32Rnd_120N_he",
            "FA_2Rnd_120N_lg",
            "FA_2Rnd_120N_sfm",
            "FA_6Rnd_120N_smk"
        };
    };
};
