// =====================================================================
//  REARMA (US) - calibers FA had no round for. 2040 projection.
//    6.8x51 TVCM : M7 / M7A1 / RM277 / M250 (+ RM277 UW underwater)
//    6x38 TVCM   : NX / NXC / NX PDW / NXM / KAC AMG
//    4.6x30      : MP7A2
//    9x19        : M17 / M18
//    66mm        : M72A7 disposable (FA launcher variants, see CfgWeapons.hpp)
//  Parented to rearma's own projectiles so cartridge, sound and tracer
//  model stay the mod's; every performance field is FA's. The P320 fires
//  a vanilla round, so the 9x19 loads ride vanilla B_9x21_Ball.
//  Metric ACE units: caliber/length MM, mass GRAMS.
// =====================================================================
class CfgAmmo {
    class 680x51_TVCM_Ball;   // rearma 6.8x51 TVCM projectile
    class 680x51_TVCM_dual;   // rearma 6.8x51 underwater (dual-medium) projectile
    class 6x38_TVCM_Ball;     // rearma 6x38 TVCM projectile
    class 46x30_TVCM_Ball;    // rearma 4.6x30 TVCM projectile
    class B_9x21_Ball;        // vanilla 9 mm projectile
    class ammo_Penetrator_Base;
    class ammo_m72a7_rocket;  // rearma M72A7 66mm rocket

    // =========================================================
    // Mk400 HV : 6.8x51 hybrid-case general purpose, 135 gr
    //   level with FA's 7.62 M80A2 in damage, a touch flatter
    // =========================================================
    class FA_b_680_Mk400_HV: 680x51_TVCM_Ball {
        displayName = "6.8x51 Mk400 HV";
        hit = 14; caliber = 3.0; typicalSpeed = 950; airFriction = -0.00080; deflecting = 14; tracerScale = 0.8;
        ACE_caliber = 7.04; ACE_bulletLength = 31.0; ACE_bulletMass = 8.75;   // 135 gr
        ACE_muzzleVelocityVariationSD = 0.16;
        ACE_ballisticCoefficients[] = {0.230}; ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO"; ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {885, 950, 985};
        ACE_barrelLengths[]    = {330, 406, 508};
    };
    class FA_b_680_Mk400_HV_T_Red:    FA_b_680_Mk400_HV { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_680_Mk400_HV_T_Yellow: FA_b_680_Mk400_HV { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_680_Mk400_HV_T_Green:  FA_b_680_Mk400_HV { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_680_Mk400_HV_T_White:  FA_b_680_Mk400_HV { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_680_Mk400_HV_T_Blue:   FA_b_680_Mk400_HV { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_680_Mk400_HV_T_Orange: FA_b_680_Mk400_HV { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_680_Mk400_HV_T_IR:     FA_b_680_Mk400_HV { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // Mk401 AP : 6.8x51 two-stage tungsten armour piercer, 140 gr
    //   keeps the +0.6 penetration offset FA's AP loads carry over GP
    // =========================================================
    class FA_b_680_Mk401_AP: 680x51_TVCM_Ball {
        displayName = "6.8x51 Mk401 AP";
        hit = 14; caliber = 3.6; typicalSpeed = 925; airFriction = -0.00076; deflecting = 11; tracerScale = 0.8;
        ACE_caliber = 7.04; ACE_bulletLength = 32.5; ACE_bulletMass = 9.07;   // 140 gr, tungsten core
        ACE_muzzleVelocityVariationSD = 0.15;
        ACE_ballisticCoefficients[] = {0.245}; ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO"; ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {860, 925, 960};
        ACE_barrelLengths[]    = {330, 406, 508};
    };
    class FA_b_680_Mk401_AP_T_Red:    FA_b_680_Mk401_AP { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_680_Mk401_AP_T_Yellow: FA_b_680_Mk401_AP { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_680_Mk401_AP_T_Green:  FA_b_680_Mk401_AP { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_680_Mk401_AP_T_White:  FA_b_680_Mk401_AP { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_680_Mk401_AP_T_Blue:   FA_b_680_Mk401_AP { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_680_Mk401_AP_T_Orange: FA_b_680_Mk401_AP { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_680_Mk401_AP_T_IR:     FA_b_680_Mk401_AP { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // Mk402 PAB : 6.8x51 proximity airburst (counter-UAS)
    //   burst is driven by the antidrone proximity-fuze registry
    //   (see XEH_postInit.sqf); flies as a plain round if absent.
    // =========================================================
    class FA_b_680_Mk402_PAB: 680x51_TVCM_Ball {
        displayName = "6.8x51 Mk402 PAB";
        hit = 9; caliber = 2.0; typicalSpeed = 935; airFriction = -0.00084; deflecting = 14; tracerScale = 0.8;
        ACE_caliber = 7.04; ACE_bulletLength = 30.5; ACE_bulletMass = 8.4;
        ACE_muzzleVelocityVariationSD = 0.18;
        ACE_ballisticCoefficients[] = {0.215}; ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO"; ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {870, 935, 970};
        ACE_barrelLengths[]    = {330, 406, 508};
        // ACE frag: fabricated frag sleeve like the 7.62 Mk362, scaled down to
        // the 6.8 bullet. Detonated manually via ace_frag_fnc_frago.
        indirectHitRange = 1.5;
        ace_frag_metal = 7.6;
        ace_frag_charge = 1.2;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = 0.5;
        ace_frag_classes[] = {"ace_frag_tiny", "ace_frag_tiny_HD"};
    };
    class FA_b_680_Mk402_PAB_T_Red:    FA_b_680_Mk402_PAB { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_680_Mk402_PAB_T_Yellow: FA_b_680_Mk402_PAB { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_680_Mk402_PAB_T_Green:  FA_b_680_Mk402_PAB { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_680_Mk402_PAB_T_White:  FA_b_680_Mk402_PAB { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_680_Mk402_PAB_T_Blue:   FA_b_680_Mk402_PAB { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_680_Mk402_PAB_T_Orange: FA_b_680_Mk402_PAB { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_680_Mk402_PAB_T_IR:     FA_b_680_Mk402_PAB { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // Mk408 UW : 6.8x51 supercavitating dart for the RM277 UW
    //   Dual-medium like rearma's own UW round, with a heavier
    //   tungsten dart: more reach underwater and more punch.
    //   No ACE ballistics data on purpose - Advanced Ballistics
    //   has no water model, so the engine's friction values rule.
    // =========================================================
    class FA_b_680_Mk408_UW: 680x51_TVCM_dual {
        displayName = "6.8x51 Mk408 UW";
        hit = 13; caliber = 2.2; typicalSpeed = 330; airFriction = -0.0080; waterFriction = -0.0080; deflecting = 10;
    };

    // =========================================================
    // Mk405 HV : 6x38 hybrid-case general purpose, 100 gr
    //   sits between FA's 5.56 Mk327 and 6.5 Mk328
    // =========================================================
    class FA_b_6x38_Mk405_HV: 6x38_TVCM_Ball {
        displayName = "6x38 Mk405 HV";
        hit = 11; caliber = 2.6; typicalSpeed = 930; airFriction = -0.00098; deflecting = 15; tracerScale = 0.7;
        ACE_caliber = 6.17; ACE_bulletLength = 27.2; ACE_bulletMass = 6.48;   // 100 gr
        ACE_muzzleVelocityVariationSD = 0.16;
        ACE_ballisticCoefficients[] = {0.205}; ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO"; ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {860, 930, 960};
        ACE_barrelLengths[]    = {267, 406, 508};
    };
    class FA_b_6x38_Mk405_HV_T_Red:    FA_b_6x38_Mk405_HV { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_6x38_Mk405_HV_T_Yellow: FA_b_6x38_Mk405_HV { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_6x38_Mk405_HV_T_Green:  FA_b_6x38_Mk405_HV { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_6x38_Mk405_HV_T_White:  FA_b_6x38_Mk405_HV { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_6x38_Mk405_HV_T_Blue:   FA_b_6x38_Mk405_HV { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_6x38_Mk405_HV_T_Orange: FA_b_6x38_Mk405_HV { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_6x38_Mk405_HV_T_IR:     FA_b_6x38_Mk405_HV { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // Mk406 AP : 6x38 tungsten armour piercer, 105 gr
    // =========================================================
    class FA_b_6x38_Mk406_AP: 6x38_TVCM_Ball {
        displayName = "6x38 Mk406 AP";
        hit = 11; caliber = 3.2; typicalSpeed = 905; airFriction = -0.00095; deflecting = 12; tracerScale = 0.7;
        ACE_caliber = 6.17; ACE_bulletLength = 28.0; ACE_bulletMass = 6.8;   // 105 gr, tungsten core
        ACE_muzzleVelocityVariationSD = 0.15;
        ACE_ballisticCoefficients[] = {0.212}; ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO"; ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {835, 905, 935};
        ACE_barrelLengths[]    = {267, 406, 508};
    };
    class FA_b_6x38_Mk406_AP_T_Red:    FA_b_6x38_Mk406_AP { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_6x38_Mk406_AP_T_Yellow: FA_b_6x38_Mk406_AP { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_6x38_Mk406_AP_T_Green:  FA_b_6x38_Mk406_AP { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_6x38_Mk406_AP_T_White:  FA_b_6x38_Mk406_AP { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_6x38_Mk406_AP_T_Blue:   FA_b_6x38_Mk406_AP { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_6x38_Mk406_AP_T_Orange: FA_b_6x38_Mk406_AP { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_6x38_Mk406_AP_T_IR:     FA_b_6x38_Mk406_AP { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // Mk407 PAB : 6x38 proximity airburst (counter-UAS)
    //   frag sleeve and fuze envelope sit between the 5.56 Mk361
    //   and the 6.5 Mk367; registered in XEH_postInit.sqf.
    // =========================================================
    class FA_b_6x38_Mk407_PAB: 6x38_TVCM_Ball {
        displayName = "6x38 Mk407 PAB";
        hit = 8; caliber = 1.7; typicalSpeed = 915; airFriction = -0.00102; deflecting = 15; tracerScale = 0.7;
        ACE_caliber = 6.17; ACE_bulletLength = 26.8; ACE_bulletMass = 6.2;
        ACE_muzzleVelocityVariationSD = 0.18;
        ACE_ballisticCoefficients[] = {0.198}; ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO"; ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {845, 915, 945};
        ACE_barrelLengths[]    = {267, 406, 508};
        // ACE frag: fabricated sleeve, ~2.6% of the 40mm warhead (between the
        // Mk361's 1.73% and the Mk367's 3.44%). Detonated via ace_frag_fnc_frago.
        indirectHitRange = 1.3;
        ace_frag_metal = 5.2;
        ace_frag_charge = 0.83;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = 0.5;
        ace_frag_classes[] = {"ace_frag_tiny", "ace_frag_tiny_HD"};
    };
    class FA_b_6x38_Mk407_PAB_T_Red:    FA_b_6x38_Mk407_PAB { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_6x38_Mk407_PAB_T_Yellow: FA_b_6x38_Mk407_PAB { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_6x38_Mk407_PAB_T_Green:  FA_b_6x38_Mk407_PAB { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_6x38_Mk407_PAB_T_White:  FA_b_6x38_Mk407_PAB { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_6x38_Mk407_PAB_T_Blue:   FA_b_6x38_Mk407_PAB { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_6x38_Mk407_PAB_T_Orange: FA_b_6x38_Mk407_PAB { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_6x38_Mk407_PAB_T_IR:     FA_b_6x38_Mk407_PAB { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // ===== 4.6x30 (MP7A2) - PDW, Mk43x series beside the 5.7 Mk430/431 =====
    // Mk432 AP - tungsten penetrator; soft-armor defeat.
    class FA_b_46x30_Mk432_AP: 46x30_TVCM_Ball {
        displayName = "4.6x30 Mk432 AP";
        caliber = 2.8; hit = 9; typicalSpeed = 725; airFriction = -0.0019; deflecting = 20;
        ACE_caliber = 4.65; ACE_bulletLength = 15.5; ACE_bulletMass = 2.0;
        ACE_dragModel = 7; ACE_ballisticCoefficients[] = {0.075};
        ACE_muzzleVelocities[] = {725}; ACE_barrelLengths[] = {180};
    };
    // Mk433 SUB - subsonic suppressed PDW load.
    class FA_b_46x30_Mk433_SUB: 46x30_TVCM_Ball {
        displayName = "4.6x30 Mk433 SUB";
        caliber = 1.0; hit = 9; typicalSpeed = 300; airFriction = -0.0014; deflecting = 20;
        ACE_caliber = 4.65; ACE_bulletLength = 17.0; ACE_bulletMass = 4.0;
        ACE_dragModel = 1; ACE_ballisticCoefficients[] = {0.090};
        ACE_muzzleVelocities[] = {300}; ACE_barrelLengths[] = {180};
    };

    // ===== 9x19 (M17 / M18) - pistol, Mk42x series beside the .45 Mk421 =====
    // Mk422 AP - tungsten-core +P; defeats soft armor.
    class FA_b_9x19_Mk422_AP: B_9x21_Ball {
        displayName = "9x19 Mk422 AP";
        caliber = 1.8; hit = 8; typicalSpeed = 400; airFriction = -0.0020; deflecting = 22;
        ACE_caliber = 9.02; ACE_bulletLength = 15.2; ACE_bulletMass = 5.4;
        ACE_dragModel = 1; ACE_ballisticCoefficients[] = {0.140};
        ACE_muzzleVelocities[] = {400}; ACE_barrelLengths[] = {119};
    };
    // Mk423 SUB - 147 gr subsonic for suppressed pistols.
    class FA_b_9x19_Mk423_SUB: B_9x21_Ball {
        displayName = "9x19 Mk423 SUB";
        caliber = 0.9; hit = 9; typicalSpeed = 300; airFriction = -0.0016; deflecting = 25;
        ACE_caliber = 9.02; ACE_bulletLength = 16.5; ACE_bulletMass = 9.53;
        ACE_dragModel = 1; ACE_ballisticCoefficients[] = {0.165};
        ACE_muzzleVelocities[] = {300}; ACE_barrelLengths[] = {119};
    };

    // =========================================================
    // M72A7 66mm - 2040 disposable family. Same tiering as FA's RPG
    // set: tandem HEAT / thermobaric / C-UAS proximity airburst.
    // Penetration scale: engine RHA ~ penetrator caliber x 15 mm
    // (rearma's M72A7 HEDP penetrator = 10 -> ~150 mm).
    // =========================================================
    // M72A10 TNDM - ~350 mm RHA tandem shaped charge
    class FA_ammo_Penetrator_M72A10: ammo_Penetrator_Base {
        caliber = 23.3;
        warheadName = "TandemHEAT";
        hit = 380;
    };
    class FA_R_M72A10_TNDM: ammo_m72a7_rocket {
        warheadName = "TandemHEAT";
        submunitionAmmo = "FA_ammo_Penetrator_M72A10";
        hit = 120;
    };
    // M72A11 TBX - thermobaric, room / bunker clearing; no penetrator
    class FA_R_M72A11_TBX: ammo_m72a7_rocket {
        submunitionAmmo = "";
        submunitionDirectionType = "";
        submunitionInitSpeed = 0;
        triggerOnImpact = 0;
        warheadName = "HE";
        explosive = 1;
        hit = 140;
        indirectHit = 38;
        indirectHitRange = 7;
        CraterEffects = "ArtyShellCrater";
        explosionEffects = "MortarExplosion";
    };
    // M72A12 PROX - prefragmented proximity airburst vs drones. The kill is
    // the antidrone scripted fuze (XEH_postInit.sqf); flies as HE without it.
    class FA_R_M72A12_PROX: ammo_m72a7_rocket {
        submunitionAmmo = "";
        submunitionDirectionType = "";
        submunitionInitSpeed = 0;
        triggerOnImpact = 0;
        warheadName = "HE";
        explosive = 1;
        hit = 70;
        indirectHit = 26;
        indirectHitRange = 5;
        ace_frag_metal = 1100;
        ace_frag_charge = 170;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = 0.5;
        ace_frag_classes[] = {"ace_frag_small", "ace_frag_small_HD"};
    };
};
