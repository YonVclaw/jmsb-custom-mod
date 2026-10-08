/*
 * Calibration note: ACE3 does not remodel autocannon/tank-gun ballistics (it only
 * touches infantry small arms via Advanced Ballistics), so there is no source in
 * this workspace for the real vanilla `caliber`/`hit`/velocity baselines on these
 * ammo classes. Values below are interim 2026-baseline anchors (marked CALIBRATE)
 * with the design doc's West/Green/Red ceiling formula applied on top:
 *     value = base * (1 + ceiling * factionFraction)
 * Penetration ceiling +30%, velocity ceiling +12% (design doc section 2).
 * The only doc-given real anchor is 30mm APFSDS-T penetration (base 9.0), used as-is.
 * Faction fraction: West 1.00, Green 0.85, Red 0.75 (doc section 2).
 * Only 30mm APFSDS-T ships with a baked Red-FACTION variant this pass (doc's
 * explicit worked example, class suffix _Red); every other nature is West-tier
 * only, per the approved plan. The _T_<color> classes are visual tracer-color
 * variants at full West performance — same convention as the small arms.
 */

class CfgAmmo {
    class B_30mm_APFSDS;
    class B_30mm_MP;
    class B_30mm_HE;
    class B_35mm_AA;
    class B_40mm_APFSDS;

    // =========================================================
    // 30mm APFSDS-T — kinetic (CALIBRATE: base caliber 9.0 is the doc's own
    // worked anchor; base velocity 1620 m/s is a Mk44 Bushmaster II-class estimate)
    // =========================================================
    class FA_B_30mm_APFSDS: B_30mm_APFSDS {
        hit = 350;
        caliber = 11.70; // 9.0 * (1 + 0.30 * 1.00)
        typicalSpeed = 1814; // 1620 * (1 + 0.12 * 1.00)
    };
    // Red-FACTION performance gradient (not a tracer color — those are the
    // _T_* classes below, which keep full West performance)
    class FA_B_30mm_APFSDS_Red: FA_B_30mm_APFSDS {
        caliber = 11.03; // 9.0 * (1 + 0.30 * 0.75)
        typicalSpeed = 1766; // 1620 * (1 + 0.12 * 0.75)
    };
    class FA_B_30mm_APFSDS_T_Red:    FA_B_30mm_APFSDS { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_B_30mm_APFSDS_T_Yellow: FA_B_30mm_APFSDS { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_B_30mm_APFSDS_T_Green:  FA_B_30mm_APFSDS { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_B_30mm_APFSDS_T_White:  FA_B_30mm_APFSDS { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_B_30mm_APFSDS_T_Blue:   FA_B_30mm_APFSDS { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_B_30mm_APFSDS_T_Orange: FA_B_30mm_APFSDS { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_B_30mm_APFSDS_T_IR:     FA_B_30mm_APFSDS { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // 30mm API-T — kinetic, multi-purpose body (CALIBRATE: base caliber 6.5,
    // base velocity 1000 m/s)
    // =========================================================
    class FA_B_30mm_API: B_30mm_MP {
        hit = 260;
        caliber = 8.45; // 6.5 * 1.30
        typicalSpeed = 1120; // 1000 * 1.12
    };
    class FA_B_30mm_API_T_Red:    FA_B_30mm_API { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_B_30mm_API_T_Yellow: FA_B_30mm_API { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_B_30mm_API_T_Green:  FA_B_30mm_API { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_B_30mm_API_T_White:  FA_B_30mm_API { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_B_30mm_API_T_Blue:   FA_B_30mm_API { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_B_30mm_API_T_Orange: FA_B_30mm_API { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_B_30mm_API_T_IR:     FA_B_30mm_API { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // 30mm HEI-T — HE (CALIBRATE: base indirectHit 40, base indirectHitRange 3;
    // terminal-frag ceiling +25%)
    // =========================================================
    class FA_B_30mm_HEI: B_30mm_HE {
        hit = 60;
        indirectHit = 50; // 40 * 1.25
        indirectHitRange = 3.75; // 3 * 1.25
        typicalSpeed = 1050;
        // ACE frag: inherited B_30mm_HE values (metal 320, charge 25) scaled by
        // the same +25% terminal-frag ceiling used on indirectHit above.
        ace_frag_metal = 400; // 320 * 1.25
        ace_frag_charge = 31.25; // 25 * 1.25
        ace_frag_gurney_c = 2552;
        ace_frag_gurney_k = 0.5;
        ace_frag_classes[] = {"ace_frag_tiny_HD", "ace_frag_tiny_HD", "ace_frag_small_HD"};
    };
    class FA_B_30mm_HEI_T_Red:    FA_B_30mm_HEI { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_B_30mm_HEI_T_Yellow: FA_B_30mm_HEI { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_B_30mm_HEI_T_Green:  FA_B_30mm_HEI { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_B_30mm_HEI_T_White:  FA_B_30mm_HEI { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_B_30mm_HEI_T_Blue:   FA_B_30mm_HEI { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_B_30mm_HEI_T_Orange: FA_B_30mm_HEI { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_B_30mm_HEI_T_IR:     FA_B_30mm_HEI { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // 30mm ABM — programmable airburst (defilade defeat). Same warhead as HEI-T;
    // the proximity/airburst behavior is entirely script-driven (shared engine),
    // this ammo class carries no special config flag for it.
    // =========================================================
    class FA_B_30mm_ABM: B_30mm_HE {
        hit = 60;
        indirectHit = 50;
        indirectHitRange = 3.75;
        typicalSpeed = 1050;
        // ACE frag: same warhead as HEI-T above.
        ace_frag_metal = 400;
        ace_frag_charge = 31.25;
        ace_frag_gurney_c = 2552;
        ace_frag_gurney_k = 0.5;
        ace_frag_classes[] = {"ace_frag_tiny_HD", "ace_frag_tiny_HD", "ace_frag_small_HD"};
    };
    class FA_B_30mm_ABM_T_Red:    FA_B_30mm_ABM { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_B_30mm_ABM_T_Yellow: FA_B_30mm_ABM { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_B_30mm_ABM_T_Green:  FA_B_30mm_ABM { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_B_30mm_ABM_T_White:  FA_B_30mm_ABM { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_B_30mm_ABM_T_Blue:   FA_B_30mm_ABM { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_B_30mm_ABM_T_Orange: FA_B_30mm_ABM { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_B_30mm_ABM_T_IR:     FA_B_30mm_ABM { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // 30mm PROX — counter-UAS proximity airburst
    // =========================================================
    class FA_B_30mm_PROX: B_30mm_HE {
        hit = 60;
        indirectHit = 50;
        indirectHitRange = 3.75;
        typicalSpeed = 1050;
        // ACE frag: same warhead as HEI-T above.
        ace_frag_metal = 400;
        ace_frag_charge = 31.25;
        ace_frag_gurney_c = 2552;
        ace_frag_gurney_k = 0.5;
        ace_frag_classes[] = {"ace_frag_tiny_HD", "ace_frag_tiny_HD", "ace_frag_small_HD"};
    };
    class FA_B_30mm_PROX_T_Red:    FA_B_30mm_PROX { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_B_30mm_PROX_T_Yellow: FA_B_30mm_PROX { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_B_30mm_PROX_T_Green:  FA_B_30mm_PROX { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_B_30mm_PROX_T_White:  FA_B_30mm_PROX { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_B_30mm_PROX_T_Blue:   FA_B_30mm_PROX { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_B_30mm_PROX_T_Orange: FA_B_30mm_PROX { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_B_30mm_PROX_T_IR:     FA_B_30mm_PROX { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // 35mm AHEAD — timed tungsten sub-projectile airburst (CALIBRATE: base
    // caliber 3.0, base indirectHit 35, base indirectHitRange 4, base velocity 1050 m/s)
    // =========================================================
    class FA_B_35mm_AHEAD: B_35mm_AA {
        hit = 45;
        caliber = 3.0;
        indirectHit = 43.75; // 35 * 1.25
        indirectHitRange = 5; // 4 * 1.25
        typicalSpeed = 1176; // 1050 * 1.12
        // ACE frag: inherited B_35mm_AA values (metal 400, charge 98) scaled by
        // the same +25% terminal-frag ceiling used on indirectHit above.
        ace_frag_metal = 500; // 400 * 1.25
        ace_frag_charge = 122.5; // 98 * 1.25
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = 0.5;
        ace_frag_classes[] = {"ace_frag_tiny_HD", "ace_frag_tiny_HD", "ace_frag_small_HD"};
    };
    class FA_B_35mm_AHEAD_T_Red:    FA_B_35mm_AHEAD { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_B_35mm_AHEAD_T_Yellow: FA_B_35mm_AHEAD { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_B_35mm_AHEAD_T_Green:  FA_B_35mm_AHEAD { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_B_35mm_AHEAD_T_White:  FA_B_35mm_AHEAD { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_B_35mm_AHEAD_T_Blue:   FA_B_35mm_AHEAD { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_B_35mm_AHEAD_T_Orange: FA_B_35mm_AHEAD { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_B_35mm_AHEAD_T_IR:     FA_B_35mm_AHEAD { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // 50mm HEAB — airburst, DORMANT (no confirmed 50mm platform; ammo/magazine
    // built and documented per the doc's "flagship" framing, not wired to any
    // weapon). Interim parent B_30mm_HE per the doc.
    // =========================================================
    class FA_B_50mm_HEAB: B_30mm_HE {
        hit = 75;
        indirectHit = 68.75; // 55 * 1.25
        indirectHitRange = 6.25; // 5 * 1.25
        typicalSpeed = 1120;
        // ACE frag: inherited B_30mm_HE values (metal 320, charge 25), scaled
        // by the indirectHit ratio to HEI-T's base (55/40) and the same +25%
        // terminal-frag ceiling, bumped one fragment-size tier as the largest
        // warhead of the family.
        ace_frag_metal = 550; // 320 * 1.375 * 1.25
        ace_frag_charge = 43.75; // 25 * 1.375 * 1.25
        ace_frag_gurney_c = 2552;
        ace_frag_gurney_k = 0.5;
        ace_frag_classes[] = {"ace_frag_small_HD", "ace_frag_small_HD", "ace_frag_medium_HD"};
    };

    // =========================================================
    // 50mm APFSDS-T — kinetic, DORMANT. Interim parent B_40mm_APFSDS per the doc.
    // =========================================================
    class FA_B_50mm_APFSDS: B_40mm_APFSDS {
        hit = 420;
        caliber = 15.6; // 12.0 * 1.30
        typicalSpeed = 1680; // 1500 * 1.12
    };
};
