/*
 * See addons/mediumcaliber/CfgAmmo.hpp for the calibration methodology note —
 * same interim-baseline-times-ceiling approach, same caveat that ACE3 does not
 * carry real vanilla caliber/hit values for tank ammo to extract.
 *
 * One real anchor is used directly: the M1147 AMP's real muzzle velocity
 * (1,150 m/s, doc section 11) is used as the 2026 baseline for the 120mm
 * AMP/HEAT-MP family before the +12% velocity ceiling is applied.
 *
 * 120mm APFSDS-T ships with a baked Red variant (the doc's second explicit
 * worked example, alongside 30mm APFSDS-T in mediumcaliber). Every other
 * nature here is West-tier only this pass.
 */

class CfgAmmo {
    class Sh_120mm_APFSDS;
    class Sh_120mm_HEAT_MP;
    class Sh_120mm_HE;
    class Sh_125mm_APFSDS;
    class Sh_125mm_HEAT;

    // =========================================================
    // 105mm — 2040 light-tank / MGS family (XM1155/XM1160/XM1162). Vanilla-
    // ballistics tank shells reparented onto the 120mm shell bases (A3 has no
    // native 105mm shell base); no ACE Advanced Ballistics fields — tank
    // shells use vanilla hit/caliber/explosive/indirectHit.
    // =========================================================
    // XM1155 APFSDS-T — kinetic long-rod
    class FA_Sh_105mm_APFSDS: Sh_120mm_APFSDS {
        hit = 700;
        indirectHit = 8;
        indirectHitRange = 2;
        caliber = 22;
        explosive = 0;
        deflecting = 1;
        typicalSpeed = 1600;
        airFriction = -0.00006;
    };
    // 105mm APFSDS — tracer-color variants (full West performance)
    class FA_Sh_105mm_APFSDS_T_Red: FA_Sh_105mm_APFSDS { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_Sh_105mm_APFSDS_T_Yellow: FA_Sh_105mm_APFSDS { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_Sh_105mm_APFSDS_T_Green: FA_Sh_105mm_APFSDS { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_Sh_105mm_APFSDS_T_White: FA_Sh_105mm_APFSDS { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_Sh_105mm_APFSDS_T_Blue: FA_Sh_105mm_APFSDS { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_Sh_105mm_APFSDS_T_Orange: FA_Sh_105mm_APFSDS { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_Sh_105mm_APFSDS_T_IR: FA_Sh_105mm_APFSDS { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // XM1160 HEAT-MP-T — multipurpose, programmable airburst
    class FA_Sh_105mm_HEATMP: Sh_120mm_HEAT_MP {
        hit = 500;
        indirectHit = 45;
        indirectHitRange = 12;
        caliber = 14;
        explosive = 0.6;
        deflecting = 2;
        typicalSpeed = 1000;
    };
    // 105mm HEAT-MP — tracer-color variants (full West performance)
    class FA_Sh_105mm_HEATMP_T_Red: FA_Sh_105mm_HEATMP { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_Sh_105mm_HEATMP_T_Yellow: FA_Sh_105mm_HEATMP { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_Sh_105mm_HEATMP_T_Green: FA_Sh_105mm_HEATMP { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_Sh_105mm_HEATMP_T_White: FA_Sh_105mm_HEATMP { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_Sh_105mm_HEATMP_T_Blue: FA_Sh_105mm_HEATMP { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_Sh_105mm_HEATMP_T_Orange: FA_Sh_105mm_HEATMP { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_Sh_105mm_HEATMP_T_IR: FA_Sh_105mm_HEATMP { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // XM1162 HE-OB — HE airburst, anti-personnel / structure
    class FA_Sh_105mm_HEOB: Sh_120mm_HE {
        hit = 260;
        indirectHit = 55;
        indirectHitRange = 20;
        caliber = 6;
        explosive = 0.9;
        deflecting = 3;
        typicalSpeed = 1000;
    };
    // 105mm HE-OB — tracer-color variants (full West performance)
    class FA_Sh_105mm_HEOB_T_Red: FA_Sh_105mm_HEOB { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_Sh_105mm_HEOB_T_Yellow: FA_Sh_105mm_HEOB { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_Sh_105mm_HEOB_T_Green: FA_Sh_105mm_HEOB { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_Sh_105mm_HEOB_T_White: FA_Sh_105mm_HEOB { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_Sh_105mm_HEOB_T_Blue: FA_Sh_105mm_HEOB { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_Sh_105mm_HEOB_T_Orange: FA_Sh_105mm_HEOB { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_Sh_105mm_HEOB_T_IR: FA_Sh_105mm_HEOB { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // 120mm APFSDS-T — kinetic (CALIBRATE: base caliber 15.0, base velocity
    // 1670 m/s, M829A4-class estimate)
    // =========================================================
    class FA_Sh_120mm_APFSDS: Sh_120mm_APFSDS {
        hit = 1600;
        caliber = 19.5; // 15.0 * 1.30
        typicalSpeed = 1870; // 1670 * 1.12
    };
    // Red-FACTION performance gradient (not a tracer color — the _T_* classes
    // below are the tracer variants, which keep full West performance). Renamed
    // from the old _T_Red suffix so _T_ always means tracer color, matching the
    // 30mm APFSDS gradient in mediumcaliber.
    class FA_Sh_120mm_APFSDS_Red: FA_Sh_120mm_APFSDS {
        caliber = 18.4; // 15.0 * (1 + 0.30 * 0.75)
        typicalSpeed = 1820; // 1670 * (1 + 0.12 * 0.75)
    };
    // 120mm APFSDS — tracer-color variants (full West performance)
    class FA_Sh_120mm_APFSDS_T_Red: FA_Sh_120mm_APFSDS { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_Sh_120mm_APFSDS_T_Yellow: FA_Sh_120mm_APFSDS { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_Sh_120mm_APFSDS_T_Green: FA_Sh_120mm_APFSDS { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_Sh_120mm_APFSDS_T_White: FA_Sh_120mm_APFSDS { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_Sh_120mm_APFSDS_T_Blue: FA_Sh_120mm_APFSDS { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_Sh_120mm_APFSDS_T_Orange: FA_Sh_120mm_APFSDS { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_Sh_120mm_APFSDS_T_IR: FA_Sh_120mm_APFSDS { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // 120mm AMP — the headline round. Multi-purpose programmable fuze
    // (point-detonate / delay / airburst); the airburst mode is what the
    // shared engine tracks. Real anchor: M1147 muzzle velocity 1,150 m/s.
    // =========================================================
    class FA_Sh_120mm_AMP: Sh_120mm_HEAT_MP {
        hit = 400;
        indirectHit = 100; // 80 * 1.25
        indirectHitRange = 10; // 8 * 1.25
        typicalSpeed = 1288; // 1150 * 1.12
        // ACE frag: inherited Sh_120mm_HEAT_MP values (metal 5000, charge 2500)
        // scaled by the same +25% terminal-frag ceiling used on indirectHit above.
        ace_frag_metal = 6250; // 5000 * 1.25
        ace_frag_charge = 3125; // 2500 * 1.25
        ace_frag_gurney_c = 2500;
        ace_frag_gurney_k = 0.5;
        ace_frag_classes[] = {"ace_frag_small", "ace_frag_medium", "ace_frag_medium_HD", "ace_frag_medium_HD"};
    };
    // 120mm AMP — tracer-color variants (full West performance)
    class FA_Sh_120mm_AMP_T_Red: FA_Sh_120mm_AMP { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_Sh_120mm_AMP_T_Yellow: FA_Sh_120mm_AMP { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_Sh_120mm_AMP_T_Green: FA_Sh_120mm_AMP { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_Sh_120mm_AMP_T_White: FA_Sh_120mm_AMP { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_Sh_120mm_AMP_T_Blue: FA_Sh_120mm_AMP { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_Sh_120mm_AMP_T_Orange: FA_Sh_120mm_AMP { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_Sh_120mm_AMP_T_IR: FA_Sh_120mm_AMP { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // 120mm HEAT-MP — HE, point-detonate/delay mode (no airburst; same
    // warhead family as AMP, no programmable fuze)
    // =========================================================
    class FA_Sh_120mm_HEATMP: Sh_120mm_HEAT_MP {
        hit = 380;
        indirectHit = 87.5; // 70 * 1.25
        indirectHitRange = 7.5; // 6 * 1.25
        typicalSpeed = 1288; // 1150 * 1.12
        // ACE frag: same warhead family as AMP above.
        ace_frag_metal = 6250; // 5000 * 1.25
        ace_frag_charge = 3125; // 2500 * 1.25
        ace_frag_gurney_c = 2500;
        ace_frag_gurney_k = 0.5;
        ace_frag_classes[] = {"ace_frag_small", "ace_frag_medium", "ace_frag_medium_HD", "ace_frag_medium_HD"};
    };
    // 120mm HEAT-MP — tracer-color variants (full West performance)
    class FA_Sh_120mm_HEATMP_T_Red: FA_Sh_120mm_HEATMP { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_Sh_120mm_HEATMP_T_Yellow: FA_Sh_120mm_HEATMP { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_Sh_120mm_HEATMP_T_Green: FA_Sh_120mm_HEATMP { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_Sh_120mm_HEATMP_T_White: FA_Sh_120mm_HEATMP { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_Sh_120mm_HEATMP_T_Blue: FA_Sh_120mm_HEATMP { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_Sh_120mm_HEATMP_T_Orange: FA_Sh_120mm_HEATMP { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_Sh_120mm_HEATMP_T_IR: FA_Sh_120mm_HEATMP { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // 120mm HE-AB — airburst (CALIBRATE: base indirectHit 75, base
    // indirectHitRange 7, base velocity 1000 m/s)
    // =========================================================
    class FA_Sh_120mm_HEAB: Sh_120mm_HE {
        hit = 350;
        indirectHit = 93.75; // 75 * 1.25
        indirectHitRange = 8.75; // 7 * 1.25
        typicalSpeed = 1120; // 1000 * 1.12
        // ACE frag: inherited Sh_120mm_HE values (metal 23000, charge 3148)
        // scaled by the same +25% terminal-frag ceiling used on indirectHit above.
        ace_frag_metal = 28750; // 23000 * 1.25
        ace_frag_charge = 3935; // 3148 * 1.25
        ace_frag_gurney_c = 2830;
        ace_frag_gurney_k = 0.5;
        ace_frag_classes[] = {"ace_frag_medium", "ace_frag_medium_HD"};
    };
    // 120mm HE-AB — tracer-color variants (full West performance)
    class FA_Sh_120mm_HEAB_T_Red: FA_Sh_120mm_HEAB { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_Sh_120mm_HEAB_T_Yellow: FA_Sh_120mm_HEAB { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_Sh_120mm_HEAB_T_Green: FA_Sh_120mm_HEAB { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_Sh_120mm_HEAB_T_White: FA_Sh_120mm_HEAB { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_Sh_120mm_HEAB_T_Blue: FA_Sh_120mm_HEAB { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_Sh_120mm_HEAB_T_Orange: FA_Sh_120mm_HEAB { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_Sh_120mm_HEAB_T_IR: FA_Sh_120mm_HEAB { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // 125mm 3BM APFSDS-T — kinetic (CALIBRATE: base caliber 15.5, base
    // velocity 1750 m/s)
    // =========================================================
    class FA_Sh_125mm_APFSDS: Sh_125mm_APFSDS {
        hit = 1650;
        caliber = 20.15; // 15.5 * 1.30
        typicalSpeed = 1960; // 1750 * 1.12
    };
    // 125mm APFSDS — tracer-color variants (full West performance)
    class FA_Sh_125mm_APFSDS_T_Red: FA_Sh_125mm_APFSDS { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_Sh_125mm_APFSDS_T_Yellow: FA_Sh_125mm_APFSDS { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_Sh_125mm_APFSDS_T_Green: FA_Sh_125mm_APFSDS { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_Sh_125mm_APFSDS_T_White: FA_Sh_125mm_APFSDS { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_Sh_125mm_APFSDS_T_Blue: FA_Sh_125mm_APFSDS { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_Sh_125mm_APFSDS_T_Orange: FA_Sh_125mm_APFSDS { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_Sh_125mm_APFSDS_T_IR: FA_Sh_125mm_APFSDS { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // 125mm Type AMP — airburst (CALIBRATE: base indirectHit 78, base
    // indirectHitRange 7.5, base velocity 950 m/s)
    // =========================================================
    class FA_Sh_125mm_AMP: Sh_125mm_HEAT {
        hit = 420;
        indirectHit = 97.5; // 78 * 1.25
        indirectHitRange = 9.375; // 7.5 * 1.25
        typicalSpeed = 1064; // 950 * 1.12
        // ACE frag: Sh_125mm_HEAT is a shaped charge and ACE3 disables frag on
        // it upstream (ace_frag_skip = 1). AMP is a programmable MP/airburst
        // fuze (not a pure HEAT jet), so frag is explicitly re-enabled here
        // using the same MP-family profile as the 120mm HEAT-MP/AMP above,
        // with metal/charge carried over from Sh_125mm_HEAT and the same
        // +25% terminal-frag ceiling applied.
        ace_frag_skip = 0;
        ace_frag_metal = 20950; // 16760 * 1.25
        ace_frag_charge = 2050; // 1640 * 1.25
        ace_frag_gurney_c = 2901;
        ace_frag_gurney_k = 0.5;
        ace_frag_classes[] = {"ace_frag_small", "ace_frag_medium", "ace_frag_medium_HD", "ace_frag_medium_HD"};
    };
    // 125mm Type AMP — tracer-color variants (full West performance)
    class FA_Sh_125mm_AMP_T_Red: FA_Sh_125mm_AMP { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_Sh_125mm_AMP_T_Yellow: FA_Sh_125mm_AMP { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_Sh_125mm_AMP_T_Green: FA_Sh_125mm_AMP { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_Sh_125mm_AMP_T_White: FA_Sh_125mm_AMP { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_Sh_125mm_AMP_T_Blue: FA_Sh_125mm_AMP { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_Sh_125mm_AMP_T_Orange: FA_Sh_125mm_AMP { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_Sh_125mm_AMP_T_IR: FA_Sh_125mm_AMP { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // CSAT 125mm East natures (T-100 Varsuk / T-140 Angara) — 2040. Single-nature
    // GRAU-designated rounds (no tracer-color sets). 3OF-82 registers into the
    // shared airburst params (see XEH_postInit.sqf).
    // =========================================================
    class Sh_125mm_HE;
    class M_Vorona_HEAT;
    // 3BM70 Vacuum-2 — APFSDS-T long-rod, ~700mm@2km
    class FA_Sh_125mm_3BM70: Sh_125mm_APFSDS { displayName = "3BM70 Vacuum-2"; hit = 640; };
    // 3BK-31 Breza — HEAT-MP, ~550mm, 12 m frag
    class FA_Sh_125mm_3BK31: Sh_125mm_HEAT { displayName = "3BK-31 Breza"; hit = 470; indirectHit = 45; indirectHitRange = 12; };
    // 3OF-82 — HE-OB programmable airburst, ~22 m lethal
    class FA_Sh_125mm_3OF82: Sh_125mm_HE { displayName = "3OF-82"; indirectHit = 90; indirectHitRange = 22; };
    // 9M119M2 Refleks-M — gun-launched laser beam-riding ATGM, tandem HEAT ~900mm, 5 km
    class FA_M_125mm_Refleks: M_Vorona_HEAT { displayName = "9M119M2 Refleks-M"; hit = 130; maxControlRange = 5000; missileLockMaxDistance = 5000; };
};
