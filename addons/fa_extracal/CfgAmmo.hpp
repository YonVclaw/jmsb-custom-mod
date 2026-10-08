// CBA-well caliber gaps — 2040. 9x39 (East spec-ops), 14.5x114 (East heavy MG /
// anti-materiel), 5.7x28 (West PDW). Each round's magazine joins the caliber's
// CBA magazineWell (CfgMagazinewells.hpp), so it works on every mod's weapon in
// that caliber. ACE metric props (caliber/length mm, mass g) drive Advanced
// Ballistics. Base ammo classes are vanilla PLACEHOLDERS — reparent to the
// caliber's real mod ammo for correct visuals/model.
class CfgAmmo {
    class B_65x39_Case;      // 6.8 SPC / 6 ARC / 6.5x43 base
    class B_762x39_Ball_F;    // 9x39 placeholder base
    class B_127x99_Ball;    // 14.5x114 placeholder base
    class B_556x45_Ball;    // 5.7x28 placeholder base

    // ===== 9x39 (VSS Vintorez / AS Val) — subsonic AP, 7U series =====
    // 7U15 — subsonic tungsten AP (SP-6 successor); defeats body armor quietly.
    class FA_o_ammo_9x39_7U15: B_762x39_Ball_F {
        displayName = "7U15";
        caliber = 4.0; hit = 14; typicalSpeed = 295; airFriction = -0.0009;
        ACE_caliber = 9.25; ACE_bulletLength = 27.0; ACE_bulletMass = 16.2;
        ACE_dragModel = 1; ACE_ballisticCoefficients[] = {0.22};
        ACE_muzzleVelocities[] = {295}; ACE_barrelLengths[] = {200};
    };
    // 7U16 — subsonic HP (SP-5 successor); suppressed anti-personnel.
    class FA_o_ammo_9x39_7U16: B_762x39_Ball_F {
        displayName = "7U16";
        caliber = 2.0; hit = 16; typicalSpeed = 295; airFriction = -0.0008;
        ACE_caliber = 9.25; ACE_bulletLength = 25.0; ACE_bulletMass = 16.0;
        ACE_dragModel = 1; ACE_ballisticCoefficients[] = {0.20};
        ACE_muzzleVelocities[] = {295}; ACE_barrelLengths[] = {200};
    };

    // ===== 14.5x114 (KPV heavy MG / anti-materiel) — above .50 =====
    // 7N60 AP-T — tungsten AP-tracer (BS-41 successor); shreds light vehicles.
    class FA_o_ammo_145_7N60: B_127x99_Ball {
        displayName = "7N60 AP-T";
        caliber = 12.0; hit = 45; typicalSpeed = 1005; airFriction = -0.0008;
        ACE_caliber = 14.9; ACE_bulletLength = 51.0; ACE_bulletMass = 60.0;
        ACE_dragModel = 7; ACE_ballisticCoefficients[] = {0.40};
        ACE_muzzleVelocities[] = {1005}; ACE_barrelLengths[] = {1346};
    };
    // 7N61 HEIAP — HE incendiary AP, multipurpose.
    class FA_o_ammo_145_7N61: B_127x99_Ball {
        displayName = "7N61 HEIAP";
        caliber = 9.0; hit = 42; indirectHit = 6; indirectHitRange = 1; explosive = 0.3;
        typicalSpeed = 1000; airFriction = -0.0009;
        ACE_caliber = 14.9; ACE_bulletLength = 53.0; ACE_bulletMass = 59.0;
        ACE_dragModel = 7; ACE_ballisticCoefficients[] = {0.38};
        ACE_muzzleVelocities[] = {1000}; ACE_barrelLengths[] = {1346};
    };
    // 7N62 HEAB — proximity airburst (C-UAS). Hooks the PAB script (XEH_postInit);
    // makes the KPV a drone-killer. Flies as ball if the script is not loaded.
    class FA_o_ammo_145_7N62: B_127x99_Ball {
        displayName = "7N62 HEAB";
        caliber = 5.0; hit = 35; typicalSpeed = 1000; airFriction = -0.0009;
        ACE_caliber = 14.9; ACE_bulletLength = 52.0; ACE_bulletMass = 58.0;
        ACE_dragModel = 7; ACE_ballisticCoefficients[] = {0.36};
        ACE_muzzleVelocities[] = {1000}; ACE_barrelLengths[] = {1346};
        ace_frag_metal = 60; ace_frag_charge = 8; ace_frag_gurney_c = 2700; ace_frag_gurney_k = 0.5;
        ace_frag_classes[] = {"ace_frag_tiny", "ace_frag_tiny_HD"};
    };

    // ===== 5.7x28 (P90 / Five-seveN) — PDW AP, Mk series =====
    // Mk430 AP — tungsten penetrator (SS190 successor); soft-armor defeat.
    class FA_b_ammo_57_Mk430: B_556x45_Ball {
        displayName = "Mk430 AP";
        caliber = 3.0; hit = 8; typicalSpeed = 715; airFriction = -0.0016;
        ACE_caliber = 5.7; ACE_bulletLength = 21.0; ACE_bulletMass = 2.02;
        ACE_dragModel = 7; ACE_ballisticCoefficients[] = {0.08};
        ACE_muzzleVelocities[] = {715}; ACE_barrelLengths[] = {263};
    };
    // Mk431 SUB — subsonic suppressed PDW load.
    class FA_b_ammo_57_Mk431: B_556x45_Ball {
        displayName = "Mk431 SUB";
        caliber = 1.0; hit = 9; typicalSpeed = 305; airFriction = -0.0012;
        ACE_caliber = 5.7; ACE_bulletLength = 22.0; ACE_bulletMass = 3.6;
        ACE_dragModel = 1; ACE_ballisticCoefficients[] = {0.10};
        ACE_muzzleVelocities[] = {305}; ACE_barrelLengths[] = {263};
    };

    // 6.5x39 caseless loads (Mk328/XM892/Mk329/XM893) now live in jmfsbfa_ammo,
    // with the full colour/tracer matrix — removed from here.

    // ===== 6.8 SPC, 6 ARC, 6.5x43 - for the MCC rifles (user, 2026-10-04) =====
    // The rounds as specified (user, 2026-10-04): case, bullet, pressure and muzzle velocity from the spec.
    // Placed between FA 5.56 (hit 10-11) and FA 7.62 (14), like the cartridges are.
    // fa_mcc / jmfsbfa mcc put them in MCC's own magazines (tools/gen_fa_mcc.py).

    // ----- 6.8x43 SPC - carbine -----
    // Mk334 TC - brass, 7.1g tungsten-core ball, 58 kpsi - 800 m/s from 16in
    class FA_b_68_Mk334_TC: B_65x39_Case {
        displayName = "Mk334 TC";
        hit = 12; caliber = 3.2; typicalSpeed = 800; airFriction = -0.00088; deflecting = 14; tracerScale = 0.7;
        ACE_caliber = 7.04; ACE_bulletLength = 26.5; ACE_bulletMass = 7.1; ACE_muzzleVelocityVariationSD = 0.15;
        ACE_ballisticCoefficients[] = {0.19}; ACE_velocityBoundaries[] = {}; ACE_standardAtmosphere = "ICAO"; ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {755, 800, 815}; ACE_barrelLengths[] = {318, 406, 457};
    };
    class FA_b_68_Mk334_TC_T_Red: FA_b_68_Mk334_TC { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_68_Mk334_TC_T_Yellow: FA_b_68_Mk334_TC { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_68_Mk334_TC_T_Green: FA_b_68_Mk334_TC { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_68_Mk334_TC_T_White: FA_b_68_Mk334_TC { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_68_Mk334_TC_T_Blue: FA_b_68_Mk334_TC { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_68_Mk334_TC_T_Orange: FA_b_68_Mk334_TC { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_68_Mk334_TC_T_IR: FA_b_68_Mk334_TC { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // ----- 6x38 ARC - DMR, the long-range pair -----
    // Mk333 LR - hybrid case, 7.0g tungsten EPR, high BC, 58 kpsi - 825 m/s from 18in
    class FA_b_6ARC_Mk333_LR: B_65x39_Case {
        displayName = "Mk333 LR";
        hit = 11; caliber = 3.0; typicalSpeed = 825; airFriction = -0.00074; deflecting = 15; tracerScale = 0.7;
        ACE_caliber = 6.18; ACE_bulletLength = 31.0; ACE_bulletMass = 7.0; ACE_muzzleVelocityVariationSD = 0.15;
        ACE_ballisticCoefficients[] = {0.28}; ACE_velocityBoundaries[] = {}; ACE_standardAtmosphere = "ICAO"; ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {770, 805, 825}; ACE_barrelLengths[] = {305, 406, 457};
    };
    class FA_b_6ARC_Mk333_LR_T_Red: FA_b_6ARC_Mk333_LR { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_6ARC_Mk333_LR_T_Yellow: FA_b_6ARC_Mk333_LR { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_6ARC_Mk333_LR_T_Green: FA_b_6ARC_Mk333_LR { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_6ARC_Mk333_LR_T_White: FA_b_6ARC_Mk333_LR { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_6ARC_Mk333_LR_T_Blue: FA_b_6ARC_Mk333_LR { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_6ARC_Mk333_LR_T_Orange: FA_b_6ARC_Mk333_LR { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_6ARC_Mk333_LR_T_IR: FA_b_6ARC_Mk333_LR { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };
    // XM895 CTEP - cased-telescoped, 7.1g two-stage tungsten, 85 kpsi - 890 m/s from 18in
    class FA_b_6ARC_XM895_CTEP: B_65x39_Case {
        displayName = "XM895 CTEP";
        hit = 12; caliber = 3.6; typicalSpeed = 890; airFriction = -0.00072; deflecting = 13; tracerScale = 0.7;
        ACE_caliber = 6.18; ACE_bulletLength = 31.5; ACE_bulletMass = 7.1; ACE_muzzleVelocityVariationSD = 0.15;
        ACE_ballisticCoefficients[] = {0.285}; ACE_velocityBoundaries[] = {}; ACE_standardAtmosphere = "ICAO"; ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {830, 870, 890}; ACE_barrelLengths[] = {305, 406, 457};
    };
    class FA_b_6ARC_XM895_CTEP_T_Red: FA_b_6ARC_XM895_CTEP { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_6ARC_XM895_CTEP_T_Yellow: FA_b_6ARC_XM895_CTEP { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_6ARC_XM895_CTEP_T_Green: FA_b_6ARC_XM895_CTEP { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_6ARC_XM895_CTEP_T_White: FA_b_6ARC_XM895_CTEP { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_6ARC_XM895_CTEP_T_Blue: FA_b_6ARC_XM895_CTEP { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_6ARC_XM895_CTEP_T_Orange: FA_b_6ARC_XM895_CTEP { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_6ARC_XM895_CTEP_T_IR: FA_b_6ARC_XM895_CTEP { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // ----- 6.5x43 - rifle, carbine, DMR and LMG belt -----
    // Mk331 EPR - steel two-piece case, 7.5g tungsten EPR, 70 kpsi - 860 m/s from 14.5in
    class FA_b_65x43_Mk331_EPR: B_65x39_Case {
        displayName = "Mk331 EPR";
        hit = 12; caliber = 3.2; typicalSpeed = 860; airFriction = -0.00076; deflecting = 15; tracerScale = 0.7;
        ACE_caliber = 6.71; ACE_bulletLength = 32.5; ACE_bulletMass = 7.5; ACE_muzzleVelocityVariationSD = 0.15;
        ACE_ballisticCoefficients[] = {0.27}; ACE_velocityBoundaries[] = {}; ACE_standardAtmosphere = "ICAO"; ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {835, 860, 895}; ACE_barrelLengths[] = {318, 368, 508};
    };
    class FA_b_65x43_Mk331_EPR_T_Red: FA_b_65x43_Mk331_EPR { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_65x43_Mk331_EPR_T_Yellow: FA_b_65x43_Mk331_EPR { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_65x43_Mk331_EPR_T_Green: FA_b_65x43_Mk331_EPR { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_65x43_Mk331_EPR_T_White: FA_b_65x43_Mk331_EPR { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_65x43_Mk331_EPR_T_Blue: FA_b_65x43_Mk331_EPR { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_65x43_Mk331_EPR_T_Orange: FA_b_65x43_Mk331_EPR { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_65x43_Mk331_EPR_T_IR: FA_b_65x43_Mk331_EPR { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };
    // XM894 CTEP - cased-telescoped, 7.8g two-stage tungsten, 85 kpsi - 900 m/s from 14.5in
    class FA_b_65x43_XM894_CTEP: B_65x39_Case {
        displayName = "XM894 CTEP";
        hit = 13; caliber = 3.7; typicalSpeed = 900; airFriction = -0.00074; deflecting = 13; tracerScale = 0.7;
        ACE_caliber = 6.71; ACE_bulletLength = 33.5; ACE_bulletMass = 7.8; ACE_muzzleVelocityVariationSD = 0.15;
        ACE_ballisticCoefficients[] = {0.29}; ACE_velocityBoundaries[] = {}; ACE_standardAtmosphere = "ICAO"; ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {870, 900, 935}; ACE_barrelLengths[] = {318, 368, 508};
    };
    class FA_b_65x43_XM894_CTEP_T_Red: FA_b_65x43_XM894_CTEP { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_65x43_XM894_CTEP_T_Yellow: FA_b_65x43_XM894_CTEP { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_65x43_XM894_CTEP_T_Green: FA_b_65x43_XM894_CTEP { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_65x43_XM894_CTEP_T_White: FA_b_65x43_XM894_CTEP { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_65x43_XM894_CTEP_T_Blue: FA_b_65x43_XM894_CTEP { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_65x43_XM894_CTEP_T_Orange: FA_b_65x43_XM894_CTEP { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_65x43_XM894_CTEP_T_IR: FA_b_65x43_XM894_CTEP { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    #include "CfgAmmo_compat.hpp"
};
