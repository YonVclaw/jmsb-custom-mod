// =====================================================================
//  futureAmmo compat: VVE_Core vehicle weapons
//  Appends every caliber-matched FA magazine onto the VVE turret weapons.
//  All VVE weapons are single-muzzle -> magazines[] sits on the weapon class,
//  so forward-declare the stock parent and re-open the leaf with += .
//
//  Coverage: 30mm RCWS, 35mm, both .50 HMGs, Titan launcher.
//  NOT wired: vve_cannon_100mm / vve_cannon_105mm — futureAmmo fields no
//  100mm or 105mm nature, so there is nothing caliber-correct to add.
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

#define FA_MAGS_35MM \
    "FA_680Rnd_35mm_AHEAD", \
    "FA_680Rnd_35mm_AHEAD_T_Red", "FA_680Rnd_35mm_AHEAD_T_Yellow", "FA_680Rnd_35mm_AHEAD_T_Green", \
    "FA_680Rnd_35mm_AHEAD_T_White", "FA_680Rnd_35mm_AHEAD_T_Blue", "FA_680Rnd_35mm_AHEAD_T_Orange", "FA_680Rnd_35mm_AHEAD_T_IR"

#define FA_MAGS_50CAL \
    "FA_b_200Rnd_127_Mk211Mod0", \
    "FA_b_200Rnd_127_Mk211Mod0_T_Red", "FA_b_200Rnd_127_Mk211Mod0_T_Yellow", "FA_b_200Rnd_127_Mk211Mod0_T_Green", \
    "FA_b_200Rnd_127_Mk211Mod0_T_White", "FA_b_200Rnd_127_Mk211Mod0_T_Blue", "FA_b_200Rnd_127_Mk211Mod0_T_Orange", "FA_b_200Rnd_127_Mk211Mod0_T_IR", \
    "FA_b_200Rnd_127_Mk258", \
    "FA_b_200Rnd_127_Mk258_T_Red", "FA_b_200Rnd_127_Mk258_T_Yellow", "FA_b_200Rnd_127_Mk258_T_Green", \
    "FA_b_200Rnd_127_Mk258_T_White", "FA_b_200Rnd_127_Mk258_T_Blue", "FA_b_200Rnd_127_Mk258_T_Orange", "FA_b_200Rnd_127_Mk258_T_IR"

// vve_missiles_titan redefines magazines[] with = , wiping the FA family that
// jmfsbfa_missiles appends to the vanilla missiles_titan parent. Restore the
// FULL family here (Broadsword/Copperhead AT + Sentry/Roadrunner AA), not just
// the AA pair, so the AT/MP tubes get FA rounds too.
// This launcher fires 1-round tubes (vve_1Rnd_GAT/GAA/GAP), so use the count=1
// FA variants — matching its per-tube reload granularity, not the 2/4Rnd racks.
#define FA_MAGS_TITAN \
    "FA_1Rnd_BGM185_Broadsword", \
    "FA_1Rnd_XM1200_Copperhead", \
    "FA_1Rnd_MIM165_Sentry", "FA_1Rnd_MIM166_Roadrunner"

#define FA_MAGS_105MM \
    "FA_20Rnd_105mm_APFSDS", \
    "FA_20Rnd_105mm_APFSDS_T_Red", "FA_20Rnd_105mm_APFSDS_T_Yellow", "FA_20Rnd_105mm_APFSDS_T_Green", \
    "FA_20Rnd_105mm_APFSDS_T_White", "FA_20Rnd_105mm_APFSDS_T_Blue", "FA_20Rnd_105mm_APFSDS_T_Orange", "FA_20Rnd_105mm_APFSDS_T_IR", \
    "FA_20Rnd_105mm_HEATMP", \
    "FA_20Rnd_105mm_HEATMP_T_Red", "FA_20Rnd_105mm_HEATMP_T_Yellow", "FA_20Rnd_105mm_HEATMP_T_Green", \
    "FA_20Rnd_105mm_HEATMP_T_White", "FA_20Rnd_105mm_HEATMP_T_Blue", "FA_20Rnd_105mm_HEATMP_T_Orange", "FA_20Rnd_105mm_HEATMP_T_IR", \
    "FA_20Rnd_105mm_HEOB", \
    "FA_20Rnd_105mm_HEOB_T_Red", "FA_20Rnd_105mm_HEOB_T_Yellow", "FA_20Rnd_105mm_HEOB_T_Green", \
    "FA_20Rnd_105mm_HEOB_T_White", "FA_20Rnd_105mm_HEOB_T_Blue", "FA_20Rnd_105mm_HEOB_T_Orange", "FA_20Rnd_105mm_HEOB_T_IR"

// ---- appends -----------------------------------------------------------
class CfgWeapons {
    // 30mm RCWS (Marshall APC autocannon)
    class autocannon_30mm_RCWS;
    class vve_autocannon_30mm_RCWS: autocannon_30mm_RCWS { magazines[] += { FA_MAGS_30MM }; };

    // 35mm (SPAAG / IFV autocannon)
    class autocannon_35mm;
    class vve_autocannon_35mm: autocannon_35mm { magazines[] += { FA_MAGS_35MM }; };

    // .50 cal — APC coax/RWS and pintle M2
    class HMG_127_APC;
    class vve_HMG_127_APC: HMG_127_APC { magazines[] += { FA_MAGS_50CAL }; };

    class HMG_M2_Mounted;
    class vve_HMG_M2_Mounted: HMG_M2_Mounted { magazines[] += { FA_MAGS_50CAL }; };

    // Titan-rack launcher (SHORAD / AT)
    class missiles_titan;
    class vve_missiles_titan: missiles_titan { magazines[] += { FA_MAGS_TITAN }; };

    // 105mm MGS main gun (Marshall MGS) — from jmfsbfa_maincaliber.
    // cannon_105mm is NOT vanilla A3; it ships with the VVE dependency chain, so
    // this base-class patch lives here (gated behind vve_core) rather than in
    // maincaliber, which always loads and would otherwise stub the class.
    // vve_cannon_105mm redefines magazines[] with = , so it needs its own += too.
    // Name cannon_105mm's parent (CannonCore) rather than reopening it parentless,
    // so a cross-mod bind order can't strip it to an empty stub (which would then
    // cascade into vve_cannon_105mm).
    class CannonCore;
    class cannon_105mm: CannonCore { magazines[] += { FA_MAGS_105MM }; };
    class vve_cannon_105mm: cannon_105mm { magazines[] += { FA_MAGS_105MM }; };
};
