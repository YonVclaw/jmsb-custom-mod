// =====================================================================
//  REARMA (China) - new FA rounds for rearma's Chinese weapons. 2040.
//    5.8x42     : DBJ-39 PAB airburst, DBS-39K / DBS-39L anti-drone shot
//                 (the PLA answer to NATO's Mk361 / Mk368K / Mk368L)
//    8.6x39 BLK : DBP-41, DBP-42 SubAP, DBJ-41 PAB (QBW-201)
//    9x21       : DBP-43 AP, DBP-44 SUB (QCQ-171 / QSZ-92A / QSZ-92B)
//    12.7x108   : DBJ-127 PAB (QBU-201)
//    35mm       : QLU-11 - FA's 40mm lineup at reduced power
//    QN-205     : mini-missile natures
//    80mm       : PF-89A / WPF-89 disposables (FA launcher variants)
//  PLA naming continues FA's DBP (ball) / DBJ (airburst) line.
//  Metric ACE units: caliber/length MM, mass GRAMS.
// =====================================================================
class CfgAmmo {
    class B_860x39_BLK_F;                         // rearma 8.6x39 BLK projectile
    class B_9x21_FMJ;                             // rearma 9x21 projectile
    class FA_o_580_Ball_HV;                       // jmfsbfa_ammo 5.8x42 ball
    class B_580x42SG_Ball_F;                      // rearma QBZ 5.8 pellet cartridge
    class B_580x42SG_Ball_Deploy;                 // rearma QBZ 5.8 pellet
    class FA_b_127x108_Mk250;                     // jmfsbfa_ammo 12.7x108 match
    class G_35mm_HE;                              // rearma QLU-11 35mm HE
    class B_12Gauge_Pellets_Submunition;
    class B_12Gauge_Pellets_Submunition_Cartridge; // declared by jmfsbfa_ammo
    class ammo_Penetrator_Base;
    class M_QN205_HEAT;                           // rearma QN-205 mini-missile
    class R_PF89_F;                               // rearma PF-89A rocket
    class R_WPF89_F;                              // rearma WPF-89 thermobaric rocket

    // =========================================================
    // DBJ-39 PAB : 5.8x42 proximity airburst (counter-UAS)
    //   The Mk361 PAB scaled to the heavier 5.8 bullet: ~1.9% of the
    //   40mm warhead. Registered in XEH_postInit.sqf.
    // =========================================================
    class FA_o_580_DBJ39_PAB: FA_o_580_Ball_HV {
        displayName = "5.8x42 DBJ-39 PAB";
        hit = 7; caliber = 1.4;
        indirectHitRange = 1.25;
        ace_frag_metal = 3.8;
        ace_frag_charge = 0.6;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = 0.5;
        ace_frag_classes[] = {"ace_frag_tiny", "ace_frag_tiny_HD"};
    };
    class FA_o_580_DBJ39_PAB_T_Red:    FA_o_580_DBJ39_PAB { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_o_580_DBJ39_PAB_T_Yellow: FA_o_580_DBJ39_PAB { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_o_580_DBJ39_PAB_T_Green:  FA_o_580_DBJ39_PAB { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_o_580_DBJ39_PAB_T_White:  FA_o_580_DBJ39_PAB { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_o_580_DBJ39_PAB_T_Blue:   FA_o_580_DBJ39_PAB { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_o_580_DBJ39_PAB_T_Orange: FA_o_580_DBJ39_PAB { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_o_580_DBJ39_PAB_T_IR:     FA_o_580_DBJ39_PAB { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // DBS-39 AD : 5.8x42 anti-drone shot (K short / L long)
    //   Mk368 pattern rule, scaled up for the bigger 5.8 case: the
    //   same 8 pellets on the K, one more on the L, and 10% more reach.
    //   coneAngle = atan(0.3048 / effective range).
    // =========================================================
    // ---- DBS-39K - 8 pellets, eff. 110 m, 680 m/s ----
    class FA_o_580_DBS39K_AD_Sub: B_580x42SG_Ball_Deploy {
        hit = 4.6;
        caliber = 0.52;
        airFriction = -0.0072;
        typicalSpeed = 680;
        airLock = 1;
        timeToLive = 3;
    };
    class FA_o_580_DBS39K_AD: B_580x42SG_Ball_F {
        displayName = "5.8mm DBS-39K AD Shot";
        triggerTime = 0;
        submunitionAmmo = "FA_o_580_DBS39K_AD_Sub";
        submunitionConeType[] = {"poissondisccenter", 8};
        submunitionConeAngle = 0.159; // 1 ft pattern radius at 110 m
        typicalSpeed = 680;
    };
    // ---- DBS-39L - 6 heavier pellets, eff. 210 m, 680 m/s ----
    class FA_o_580_DBS39L_AD_Sub: B_580x42SG_Ball_Deploy {
        hit = 6.2;
        caliber = 0.62;
        airFriction = -0.0038;
        typicalSpeed = 680;
        airLock = 1;
        timeToLive = 3;
    };
    class FA_o_580_DBS39L_AD: B_580x42SG_Ball_F {
        displayName = "5.8mm DBS-39L AD Shot";
        triggerTime = 0;
        submunitionAmmo = "FA_o_580_DBS39L_AD_Sub";
        submunitionConeType[] = {"poissondisccenter", 6};
        submunitionConeAngle = 0.083; // 1 ft pattern radius at 210 m
        typicalSpeed = 680;
    };

    // =========================================================
    // DBP-41 : 8.6x39 supersonic, 190 gr - the rifle's general load
    // =========================================================
    class FA_o_86x39_DBP41: B_860x39_BLK_F {
        displayName = "8.6x39 DBP-41";
        hit = 14; caliber = 2.6; typicalSpeed = 690; airFriction = -0.00105; deflecting = 16; tracerScale = 0.8;
        ACE_caliber = 8.61; ACE_bulletLength = 30.0; ACE_bulletMass = 12.31;   // 190 gr
        ACE_muzzleVelocityVariationSD = 0.15;
        ACE_ballisticCoefficients[] = {0.215}; ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO"; ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {650, 690, 715};
        ACE_barrelLengths[]    = {229, 330, 406};
    };
    class FA_o_86x39_DBP41_T_Red:    FA_o_86x39_DBP41 { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_o_86x39_DBP41_T_Yellow: FA_o_86x39_DBP41 { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_o_86x39_DBP41_T_Green:  FA_o_86x39_DBP41 { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_o_86x39_DBP41_T_White:  FA_o_86x39_DBP41 { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_o_86x39_DBP41_T_Blue:   FA_o_86x39_DBP41 { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_o_86x39_DBP41_T_Orange: FA_o_86x39_DBP41 { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_o_86x39_DBP41_T_IR:     FA_o_86x39_DBP41 { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // DBP-42 SubAP : 8.6x39 subsonic tungsten, 300 gr - quiet barrier
    //   defeat. Velocity-capped under Mach 1; gains come from mass.
    // =========================================================
    class FA_o_86x39_DBP42_SubAP: B_860x39_BLK_F {
        displayName = "8.6x39 DBP-42 SubAP";
        hit = 15; caliber = 2.2; typicalSpeed = 315; airFriction = -0.00058; deflecting = 13; tracerScale = 0.8;
        ACE_caliber = 8.61; ACE_bulletLength = 38.0; ACE_bulletMass = 19.44;   // 300 gr
        ACE_muzzleVelocityVariationSD = 0.12;
        ACE_ballisticCoefficients[] = {0.300}; ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO"; ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {305, 315, 320};
        ACE_barrelLengths[]    = {229, 330, 406};
    };
    class FA_o_86x39_DBP42_SubAP_T_Red:    FA_o_86x39_DBP42_SubAP { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_o_86x39_DBP42_SubAP_T_Yellow: FA_o_86x39_DBP42_SubAP { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_o_86x39_DBP42_SubAP_T_Green:  FA_o_86x39_DBP42_SubAP { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_o_86x39_DBP42_SubAP_T_White:  FA_o_86x39_DBP42_SubAP { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_o_86x39_DBP42_SubAP_T_Blue:   FA_o_86x39_DBP42_SubAP { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_o_86x39_DBP42_SubAP_T_Orange: FA_o_86x39_DBP42_SubAP { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_o_86x39_DBP42_SubAP_T_IR:     FA_o_86x39_DBP42_SubAP { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // DBJ-41 PAB : 8.6x39 proximity airburst (counter-UAS)
    //   The .300 BLK Mk363 scaled to the 1.5x heavier 8.6 bullet:
    //   ~5.2% of the 40mm warhead. Registered in XEH_postInit.sqf.
    // =========================================================
    class FA_o_86x39_DBJ41_PAB: FA_o_86x39_DBP41 {
        displayName = "8.6x39 DBJ-41 PAB";
        hit = 9; caliber = 1.6;
        indirectHitRange = 1.5;
        ace_frag_metal = 10.5;
        ace_frag_charge = 1.7;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = 0.5;
        ace_frag_classes[] = {"ace_frag_tiny", "ace_frag_tiny_HD"};
    };
    class FA_o_86x39_DBJ41_PAB_T_Red:    FA_o_86x39_DBJ41_PAB { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_o_86x39_DBJ41_PAB_T_Yellow: FA_o_86x39_DBJ41_PAB { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_o_86x39_DBJ41_PAB_T_Green:  FA_o_86x39_DBJ41_PAB { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_o_86x39_DBJ41_PAB_T_White:  FA_o_86x39_DBJ41_PAB { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_o_86x39_DBJ41_PAB_T_Blue:   FA_o_86x39_DBJ41_PAB { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_o_86x39_DBJ41_PAB_T_Orange: FA_o_86x39_DBJ41_PAB { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_o_86x39_DBJ41_PAB_T_IR:     FA_o_86x39_DBJ41_PAB { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // ===== 9x21 (QCQ-171 SMG / QSZ-92 pistol) =====
    // DBP-43 AP - tungsten-core armour piercer.
    class FA_o_9x21_DBP43_AP: B_9x21_FMJ {
        displayName = "9x21 DBP-43 AP";
        caliber = 2.0; hit = 9; typicalSpeed = 560; airFriction = -0.0017; deflecting = 20;
        ACE_caliber = 9.02; ACE_bulletLength = 15.5; ACE_bulletMass = 5.2;
        ACE_dragModel = 1; ACE_ballisticCoefficients[] = {0.135};
        ACE_muzzleVelocities[] = {470, 580}; ACE_barrelLengths[] = {115, 230};
    };
    // DBP-44 SUB - heavy subsonic for suppressed work.
    class FA_o_9x21_DBP44_SUB: B_9x21_FMJ {
        displayName = "9x21 DBP-44 SUB";
        caliber = 1.0; hit = 9; typicalSpeed = 300; airFriction = -0.0016; deflecting = 25;
        ACE_caliber = 9.02; ACE_bulletLength = 16.5; ACE_bulletMass = 9.5;
        ACE_dragModel = 1; ACE_ballisticCoefficients[] = {0.165};
        ACE_muzzleVelocities[] = {295, 305}; ACE_barrelLengths[] = {115, 230};
    };

    // =========================================================
    // DBJ-127 PAB : 12.7x108 proximity airburst for the QBU-201
    //   Same frag sleeve and fuze envelope as the 12.7x99 Mk366.
    // =========================================================
    class FA_o_127x108_DBJ127_PAB: FA_b_127x108_Mk250 {
        displayName = "12.7x108 DBJ-127 PAB";
        hit = 20; caliber = 2.5; tracerScale = 1.2;
        indirectHitRange = 2.2;
        ace_frag_metal = 36.2;
        ace_frag_charge = 5.8;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = 0.5;
        ace_frag_classes[] = {"ace_frag_tiny_HD", "ace_frag_small_HD"};
    };
    class FA_o_127x108_DBJ127_PAB_T_Red:    FA_o_127x108_DBJ127_PAB { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_o_127x108_DBJ127_PAB_T_Yellow: FA_o_127x108_DBJ127_PAB { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_o_127x108_DBJ127_PAB_T_Green:  FA_o_127x108_DBJ127_PAB { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_o_127x108_DBJ127_PAB_T_White:  FA_o_127x108_DBJ127_PAB { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_o_127x108_DBJ127_PAB_T_Blue:   FA_o_127x108_DBJ127_PAB { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_o_127x108_DBJ127_PAB_T_Orange: FA_o_127x108_DBJ127_PAB { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_o_127x108_DBJ127_PAB_T_IR:     FA_o_127x108_DBJ127_PAB { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // QLU-11 35mm - every FA 40mm option, at reduced power.
    //   A 35mm grenade carries ~0.67x the payload of a 40mm, so
    //   charge / frag metal / damage scale by ~0.67 and effect radii
    //   by ~0.8. Mirrors: DFK-135 = Mk364 PAB, DFB-135 = Mk389 TBK,
    //   DFP-135 = RC40 HE-P, DFJ-135 = RC40 DP, DFZ-13x = Mk380 block.
    //   The QLU-11 fires at 450 m/s, so reach is longer than a UGL's.
    // =========================================================
    // DFK-135 PAB - proximity fuze + programmable airburst + HE on impact
    // (Mk364 dial). Mk364 warhead is metal 200 g / charge 32 g.
    class FA_o_35mm_DFK135_PAB: G_35mm_HE {
        displayName = "35mm DFK-135 PAB";
        hit = 40;
        indirectHit = 6;
        indirectHitRange = 8;
        ace_frag_metal = 134;
        ace_frag_charge = 21;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = 0.6;
        ace_frag_classes[] = {"ace_frag_small_HD", "ace_frag_tiny_HD"};
    };
    // DFP-135 HE-P - programmable airburst HE (RC40 HE-P: 22 / 8 m, frag 90 / 40)
    class FA_o_35mm_DFP135_HEP: G_35mm_HE {
        displayName = "35mm DFP-135 HE-P";
        hit = 45;
        indirectHit = 15;
        indirectHitRange = 6.5;
        ace_frag_metal = 60;
        ace_frag_charge = 27;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = 0.6;
        ace_frag_classes[] = {"ace_frag_small", "ace_frag_small_HD"};
    };
    // DFJ-135 DP - dual-purpose HEAT + frag (RC40 DP: ~50 mm RHA, 14 / 5 m)
    class FA_o_35mm_DFJ135_DP: G_35mm_HE {
        displayName = "35mm DFJ-135 DP";
        warheadName = "HEAT";
        caliber = 2.6;    // ~40 mm RHA
        hit = 45;
        indirectHit = 10;
        indirectHitRange = 4;
    };
    // DFB-135 TBK - tungsten buckshot (Mk389 TBK: 18 pellets, hit 11).
    // 12 lighter pellets at the QLU-11's higher velocity; eff. ~150 m.
    class FA_o_35mm_DFB135_TBK_Sub: B_12Gauge_Pellets_Submunition {
        hit = 8;
        caliber = 1.0;
        airFriction = -0.0048;
        typicalSpeed = 450;
    };
    class FA_o_35mm_DFB135_TBK: B_12Gauge_Pellets_Submunition_Cartridge {
        displayName = "35mm DFB-135 Tungsten Buckshot";
        cartridge = "FxCartridge_35";
        triggerTime = 0;
        submunitionAmmo = "FA_o_35mm_DFB135_TBK_Sub";
        submunitionConeAngle = 1.1;                          // ~2.9 m pattern radius at 150 m
        submunitionConeType[] = {"poissondisccenter", 12};   // 12 pellets
        typicalSpeed = 450;
    };
    // DFZ-13x - inert ISR / EW carriers (Mk380 block). Fly like the QLU-11
    // HE round but do no damage; jmfsbfa_grenade_40mm's framework deletes
    // them at apex and deploys the payload (XEH_postInit.sqf registers them
    // with shorter lifetimes and smaller radii than the 40mm rounds).
    class FA_o_35mm_Carrier_Base: G_35mm_HE {
        hit = 0; indirectHit = 0; indirectHitRange = 0; explosive = 0;
        cost = 0; airLock = 0; deflecting = 0;
        soundHit1[] = {"",1,1}; soundHit2[] = {"",1,1}; soundHit3[] = {"",1,1}; soundHit4[] = {"",1,1};
        explosionEffects = ""; craterEffects = "";
    };
    class FA_o_35mm_DFZ130_NRP:    FA_o_35mm_Carrier_Base {};
    class FA_o_35mm_DFZ133_EMP:    FA_o_35mm_Carrier_Base {};
    class FA_o_35mm_DFZ134_MSmoke: FA_o_35mm_Carrier_Base {};
    class FA_o_35mm_DFZ135_Decoy:  FA_o_35mm_Carrier_Base {};
    class FA_o_35mm_DFZ136_UGS:    FA_o_35mm_Carrier_Base {};
    class FA_o_35mm_DFZ138_Jammer: FA_o_35mm_Carrier_Base {};

    // =========================================================
    // QN-205 mini-missiles - 2040 natures. Rearma's HEAT keeps the IR
    // lock and top-down profile; its penetrator is caliber 20 (~300 mm).
    // =========================================================
    // QN-205T TNDM - tandem top-attack, ~450 mm RHA
    class FA_o_ammo_Penetrator_QN205T: ammo_Penetrator_Base {
        caliber = 30;
        warheadName = "TandemHEAT";
        hit = 380;
    };
    class FA_M_QN205T_TNDM: M_QN205_HEAT {
        warheadName = "TandemHEAT";
        submunitionAmmo = "FA_o_ammo_Penetrator_QN205T";
        hit = 80;
    };
    // QN-205B TBX - thermobaric + prefrag, programmable airburst (Mk364 dial)
    class FA_M_QN205B_TBX: M_QN205_HEAT {
        submunitionAmmo = "";
        submunitionDirectionType = "";
        submunitionInitSpeed = 0;
        triggerOnImpact = 0;
        warheadName = "HE";
        explosive = 1;
        hit = 90;
        indirectHit = 45;
        indirectHitRange = 9;
        ace_frag_metal = 900;
        ace_frag_charge = 260;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = 0.6;
        ace_frag_classes[] = {"ace_frag_small", "ace_frag_small_HD"};
    };
    // QN-205D C-UAS - IR lock on air targets and drones, proximity burst
    class FA_M_QN205D_CUAS: M_QN205_HEAT {
        submunitionAmmo = "";
        submunitionDirectionType = "";
        submunitionInitSpeed = 0;
        triggerOnImpact = 0;
        warheadName = "HE";
        explosive = 1;
        hit = 50;
        indirectHit = 35;
        indirectHitRange = 6;
        airLock = 2;
        proximityExplosionDistance = 8;
        flightProfiles[] = {"Direct"};
        missileLockMinDistance = 50;
        missileLockMaxDistance = 1500;
        ace_frag_metal = 700;
        ace_frag_charge = 150;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = 0.5;
        ace_frag_classes[] = {"ace_frag_small", "ace_frag_small_HD"};
    };

    // =========================================================
    // PF-89A / WPF-89 80mm - 2040 disposables, same tiering as FA's RPG
    // set. Penetration scale: engine RHA ~ penetrator caliber x 15 mm.
    // =========================================================
    // PF-89C TNDM - ~675 mm RHA tandem, under the RPG-32 PG-32V-2
    class FA_ammo_Penetrator_PF89C: ammo_Penetrator_Base {
        caliber = 45;
        warheadName = "TandemHEAT";
        hit = 480;
    };
    class FA_R_PF89C_TNDM: R_PF89_F {
        warheadName = "TandemHEAT";
        submunitionAmmo = "FA_ammo_Penetrator_PF89C";
        hit = 130;
    };
    // WPF-89C TBX - heavier thermobaric fill than rearma's WPF-89
    class FA_R_WPF89C_TBX: R_WPF89_F {
        hit = 220;
        indirectHit = 58;
        indirectHitRange = 9;
    };
    // PF-89K PROX - prefragmented proximity airburst vs drones; scripted fuze
    class FA_R_PF89K_PROX: R_WPF89_F {
        hit = 100;
        indirectHit = 36;
        indirectHitRange = 7;
        ace_frag_metal = 1600;
        ace_frag_charge = 260;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = 0.5;
        ace_frag_classes[] = {"ace_frag_small", "ace_frag_small_HD"};
    };
};
