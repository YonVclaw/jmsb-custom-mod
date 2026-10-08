// =====================================================================
//  futureAmmo compat: QAV AbramsX vehicle weapons
//  Appends every caliber-matched FA magazine onto the AbramsX turret weapons.
//
//  Muzzle notes:
//   - 30mm M914 is MULTI-muzzle {"HighROF"}; the HighROF muzzle (extends HE)
//     carries the magazines[], so the append goes there, not on the weapon.
//     The single-barrel coax (qav_30mm_M914_coax) inherits M914 and its
//     HighROF unchanged -> covered automatically, no own block.
//     The twin (autocannon_30mm_M914_twin) REDEFINES its own HighROF, so it
//     needs a separate append.
//   - 120mm M360, the .338/.50 coax, the .50 RWS and the 7.62 XM134 are all
//     single-muzzle -> append on the weapon class.
// =====================================================================

// ---- FA magazine lists (grouped by caliber) ----------------------------
#define FA_MAGS_30MM \
    "FA_60Rnd_30mm_APFSDS", "FA_60Rnd_30mm_APFSDS_Red", \
    "FA_60Rnd_30mm_APFSDS_T_Red", "FA_60Rnd_30mm_APFSDS_T_Yellow", "FA_60Rnd_30mm_APFSDS_T_Green", \
    "FA_60Rnd_30mm_APFSDS_T_White", "FA_60Rnd_30mm_APFSDS_T_Blue", "FA_60Rnd_30mm_APFSDS_T_Orange", "FA_60Rnd_30mm_APFSDS_T_IR", \
    "FA_140Rnd_30mm_API", \
    "FA_140Rnd_30mm_API_T_Red", "FA_140Rnd_30mm_API_T_Yellow", "FA_140Rnd_30mm_API_T_Green", \
    "FA_140Rnd_30mm_API_T_White", "FA_140Rnd_30mm_API_T_Blue", "FA_140Rnd_30mm_API_T_Orange", "FA_140Rnd_30mm_API_T_IR", \
    "FA_250Rnd_30mm_HEI", \
    "FA_250Rnd_30mm_HEI_T_Red", "FA_250Rnd_30mm_HEI_T_Yellow", "FA_250Rnd_30mm_HEI_T_Green", \
    "FA_250Rnd_30mm_HEI_T_White", "FA_250Rnd_30mm_HEI_T_Blue", "FA_250Rnd_30mm_HEI_T_Orange", "FA_250Rnd_30mm_HEI_T_IR", \
    "FA_250Rnd_30mm_ABM", \
    "FA_250Rnd_30mm_ABM_T_Red", "FA_250Rnd_30mm_ABM_T_Yellow", "FA_250Rnd_30mm_ABM_T_Green", \
    "FA_250Rnd_30mm_ABM_T_White", "FA_250Rnd_30mm_ABM_T_Blue", "FA_250Rnd_30mm_ABM_T_Orange", "FA_250Rnd_30mm_ABM_T_IR", \
    "FA_250Rnd_30mm_PROX", \
    "FA_250Rnd_30mm_PROX_T_Red", "FA_250Rnd_30mm_PROX_T_Yellow", "FA_250Rnd_30mm_PROX_T_Green", \
    "FA_250Rnd_30mm_PROX_T_White", "FA_250Rnd_30mm_PROX_T_Blue", "FA_250Rnd_30mm_PROX_T_Orange", "FA_250Rnd_30mm_PROX_T_IR"

#define FA_MAGS_120MM \
    "FA_30Rnd_120mm_APFSDS", "FA_30Rnd_120mm_APFSDS_Red", \
    "FA_30Rnd_120mm_APFSDS_T_Red", "FA_30Rnd_120mm_APFSDS_T_Yellow", "FA_30Rnd_120mm_APFSDS_T_Green", \
    "FA_30Rnd_120mm_APFSDS_T_White", "FA_30Rnd_120mm_APFSDS_T_Blue", "FA_30Rnd_120mm_APFSDS_T_Orange", "FA_30Rnd_120mm_APFSDS_T_IR", \
    "FA_30Rnd_120mm_AMP", \
    "FA_30Rnd_120mm_AMP_T_Red", "FA_30Rnd_120mm_AMP_T_Yellow", "FA_30Rnd_120mm_AMP_T_Green", \
    "FA_30Rnd_120mm_AMP_T_White", "FA_30Rnd_120mm_AMP_T_Blue", "FA_30Rnd_120mm_AMP_T_Orange", "FA_30Rnd_120mm_AMP_T_IR", \
    "FA_30Rnd_120mm_HEATMP", \
    "FA_30Rnd_120mm_HEATMP_T_Red", "FA_30Rnd_120mm_HEATMP_T_Yellow", "FA_30Rnd_120mm_HEATMP_T_Green", \
    "FA_30Rnd_120mm_HEATMP_T_White", "FA_30Rnd_120mm_HEATMP_T_Blue", "FA_30Rnd_120mm_HEATMP_T_Orange", "FA_30Rnd_120mm_HEATMP_T_IR", \
    "FA_30Rnd_120mm_HEAB", \
    "FA_30Rnd_120mm_HEAB_T_Red", "FA_30Rnd_120mm_HEAB_T_Yellow", "FA_30Rnd_120mm_HEAB_T_Green", \
    "FA_30Rnd_120mm_HEAB_T_White", "FA_30Rnd_120mm_HEAB_T_Blue", "FA_30Rnd_120mm_HEAB_T_Orange", "FA_30Rnd_120mm_HEAB_T_IR"

#define FA_MAGS_338 \
    "FA_b_200Rnd_338_Mk372", \
    "FA_b_200Rnd_338_Mk372_T_Red", "FA_b_200Rnd_338_Mk372_T_Yellow", "FA_b_200Rnd_338_Mk372_T_Green", \
    "FA_b_200Rnd_338_Mk372_T_White", "FA_b_200Rnd_338_Mk372_T_Blue", "FA_b_200Rnd_338_Mk372_T_Orange", "FA_b_200Rnd_338_Mk372_T_IR"

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

// ---- appends -----------------------------------------------------------
class CfgWeapons {
    // 30mm XM914 — main gun (HighROF muzzle) + inherited single-barrel coax.
    // QAV writes `class HighROF: HE`, so the append reopens it WITH that
    // parent. A bare `class HighROF {` rebinds the fire mode to no parent and
    // drops everything it inherits from HE - the RPT says so: "Updating base
    // class 'HighROF'->'', by jmfsb_fa_qav_abramsx". HE is CTWS's own fire
    // mode, declared here with no body so the children can name it.
    class autocannon_Base_F;
    class autocannon_30mm_CTWS: autocannon_Base_F {
        class HE;
    };
    class autocannon_30mm_M914: autocannon_30mm_CTWS {
        class HighROF: HE { magazines[] += { FA_MAGS_30MM }; };
    };
    // 30mm XM914 twin — redefines its own HighROF, needs its own append
    class autocannon_30mm_M914_twin: autocannon_30mm_CTWS {
        class HighROF: HE { magazines[] += { FA_MAGS_30MM }; };
    };

    // 120mm M360 main gun
    class cannon_120mm_long;
    class cannon_120mm_M360: cannon_120mm_long { magazines[] += { FA_MAGS_120MM }; };

    // .338 coax (SIG MG338)
    class MMG_02_coax;
    class qav_abrams_coax: MMG_02_coax { magazines[] += { FA_MAGS_338 }; };

    // .50 coax + Kongsberg M2 RWS
    class HMG_127_MBT;
    class qav_abrams_m2_coax: HMG_127_MBT { magazines[] += { FA_MAGS_50CAL }; };
    class QAV_abramsx_M2_RWS: HMG_127_MBT { magazines[] += { FA_MAGS_50CAL }; };

    // 7.62 XM134 minigun (base M134_minigun; stock belt is 762x51-derived)
    class M134_minigun;
    class qav_abramsx_XM134: M134_minigun { magazines[] += { FA_MAGS_762 }; };
};
