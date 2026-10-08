// =====================================================================
//  futureAmmo compat: QAV Ripsaw vehicle weapons
//  These are QAV-specific weapon subclasses that REDEFINE magazines[] with = ,
//  so they don't inherit the shared-class appends from jmfsbfa_mediumcaliber /
//  jmfsbfa_vehicles - each needs its own += here.
//
//  QAV_ripsaw_mk30 is multi-muzzle {"AP","HE"}; the mags live on the muzzles,
//  split by role -> kinetic/AP natures on AP, HE/airburst natures on HE.
//  M2 RWS (.50) and coax (7.62) are single-muzzle.
// =====================================================================

// AP muzzle: kinetic sabot (+ Red faction gradient) and API armor-piercing
#define FA_MAGS_30MM_AP \
    "FA_60Rnd_30mm_APFSDS", "FA_60Rnd_30mm_APFSDS_Red", \
    "FA_60Rnd_30mm_APFSDS_T_Red", "FA_60Rnd_30mm_APFSDS_T_Yellow", "FA_60Rnd_30mm_APFSDS_T_Green", \
    "FA_60Rnd_30mm_APFSDS_T_White", "FA_60Rnd_30mm_APFSDS_T_Blue", "FA_60Rnd_30mm_APFSDS_T_Orange", "FA_60Rnd_30mm_APFSDS_T_IR", \
    "FA_140Rnd_30mm_API", \
    "FA_140Rnd_30mm_API_T_Red", "FA_140Rnd_30mm_API_T_Yellow", "FA_140Rnd_30mm_API_T_Green", \
    "FA_140Rnd_30mm_API_T_White", "FA_140Rnd_30mm_API_T_Blue", "FA_140Rnd_30mm_API_T_Orange", "FA_140Rnd_30mm_API_T_IR"

// HE muzzle: HEI + airburst (ABM) + counter-UAS proximity (PROX)
#define FA_MAGS_30MM_HE \
    "FA_250Rnd_30mm_HEI", \
    "FA_250Rnd_30mm_HEI_T_Red", "FA_250Rnd_30mm_HEI_T_Yellow", "FA_250Rnd_30mm_HEI_T_Green", \
    "FA_250Rnd_30mm_HEI_T_White", "FA_250Rnd_30mm_HEI_T_Blue", "FA_250Rnd_30mm_HEI_T_Orange", "FA_250Rnd_30mm_HEI_T_IR", \
    "FA_250Rnd_30mm_ABM", \
    "FA_250Rnd_30mm_ABM_T_Red", "FA_250Rnd_30mm_ABM_T_Yellow", "FA_250Rnd_30mm_ABM_T_Green", \
    "FA_250Rnd_30mm_ABM_T_White", "FA_250Rnd_30mm_ABM_T_Blue", "FA_250Rnd_30mm_ABM_T_Orange", "FA_250Rnd_30mm_ABM_T_IR", \
    "FA_250Rnd_30mm_PROX", \
    "FA_250Rnd_30mm_PROX_T_Red", "FA_250Rnd_30mm_PROX_T_Yellow", "FA_250Rnd_30mm_PROX_T_Green", \
    "FA_250Rnd_30mm_PROX_T_White", "FA_250Rnd_30mm_PROX_T_Blue", "FA_250Rnd_30mm_PROX_T_Orange", "FA_250Rnd_30mm_PROX_T_IR"

#define FA_MAGS_50CAL \
    "FA_b_200Rnd_127_Mk211Mod0", \
    "FA_b_200Rnd_127_Mk211Mod0_T_Red", "FA_b_200Rnd_127_Mk211Mod0_T_Yellow", "FA_b_200Rnd_127_Mk211Mod0_T_Green", \
    "FA_b_200Rnd_127_Mk211Mod0_T_White", "FA_b_200Rnd_127_Mk211Mod0_T_Blue", "FA_b_200Rnd_127_Mk211Mod0_T_Orange", "FA_b_200Rnd_127_Mk211Mod0_T_IR", \
    "FA_b_200Rnd_127_Mk258", \
    "FA_b_200Rnd_127_Mk258_T_Red", "FA_b_200Rnd_127_Mk258_T_Yellow", "FA_b_200Rnd_127_Mk258_T_Green", \
    "FA_b_200Rnd_127_Mk258_T_White", "FA_b_200Rnd_127_Mk258_T_Blue", "FA_b_200Rnd_127_Mk258_T_Orange", "FA_b_200Rnd_127_Mk258_T_IR"

#define FA_MAGS_762 \
    "FA_b_200Rnd_762_M80A2_HV", \
    "FA_b_200Rnd_762_M80A2_HV_T_Red", "FA_b_200Rnd_762_M80A2_HV_T_Yellow", "FA_b_200Rnd_762_M80A2_HV_T_Green", \
    "FA_b_200Rnd_762_M80A2_HV_T_White", "FA_b_200Rnd_762_M80A2_HV_T_Blue", "FA_b_200Rnd_762_M80A2_HV_T_Orange", "FA_b_200Rnd_762_M80A2_HV_T_IR", \
    "FA_b_200Rnd_762_XM751_CTEP", \
    "FA_b_200Rnd_762_XM751_CTEP_T_Red", "FA_b_200Rnd_762_XM751_CTEP_T_Yellow", "FA_b_200Rnd_762_XM751_CTEP_T_Green", \
    "FA_b_200Rnd_762_XM751_CTEP_T_White", "FA_b_200Rnd_762_XM751_CTEP_T_Blue", "FA_b_200Rnd_762_XM751_CTEP_T_Orange", "FA_b_200Rnd_762_XM751_CTEP_T_IR"

class CfgWeapons {
    // 30mm Mk44 — multi-muzzle {"AP","HE"}; append per muzzle
    class autocannon_Base_F;
    class QAV_ripsaw_mk30: autocannon_Base_F {
        class AP: autocannon_Base_F { magazines[] += { FA_MAGS_30MM_AP }; };
        class HE: autocannon_Base_F { magazines[] += { FA_MAGS_30MM_HE }; };
    };

    // .50 M2 RWS
    class HMG_M2_Mounted;
    class QAV_ripsaw_M2_RWS: HMG_M2_Mounted { magazines[] += { FA_MAGS_50CAL }; };

    // 7.62 coax
    class lmg_coax;
    class qav_ripsaw_coax: lmg_coax { magazines[] += { FA_MAGS_762 }; };
};
