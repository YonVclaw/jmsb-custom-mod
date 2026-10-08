// =====================================================================
//  REARMA (Russia) - new FA rounds for rearma's Russian weapons. 2040.
//    5.45x39  : 7N55 HEAB airburst, 7N56K / 7N56L anti-drone shot
//               (the Russian answer to NATO's Mk361 / Mk368K / Mk368L),
//               PSP-2 UW underwater dart for the ADS35
//    7.62x54R : 7N49 AP, 7U18 SUB
//    9x19     : 7N53 AP, 7U17 SUB (MP-443 / MP-446 S)
//    23mm     : KS-23 anti-drone - Shrapnel-AD50 / AD100 shot, Barrikada-AB
//    72.5mm   : RPG-26 / RShG-2 disposables (FA launcher variants)
//  Ball / AP loads inherit jmfsbfa_ammo's rounds so they keep FA's ACE
//  ballistics; shot, UW and launcher natures ride rearma's own classes.
//  Metric ACE units: caliber/length MM, mass GRAMS.
// =====================================================================
class CfgAmmo {
    class FA_o_545x39_7N44_HP;              // jmfsbfa_ammo 5.45 hollow point
    class FA_o_762x54R_Ball_HV;             // jmfsbfa_ammo 7.62x54R ball
    class AK2035_545x39SG_Ball_F;           // rearma AK35 5.45 pellet cartridge
    class AK2035_545x39SG_Ball_Deploy;      // rearma AK35 5.45 pellet
    class B_556x45_dual;                    // vanilla dual-medium dart (ADS35 UW mag)
    class B_9x19_7N31;                      // rearma MP-443 9x19 projectile
    class B_23Gauge_Pellets_Submunition;    // rearma KS-23 shot cartridge
    class B_23Gauge_Pellets_Submunition_Deploy;
    class B_23Gauge_Slug;                   // rearma KS-23 slug
    class ammo_Penetrator_Base;
    class R_PG26_AT;                        // rearma RPG-26 rocket
    class R_RSHG2_HE;                       // rearma RShG-2 rocket

    // =========================================================
    // 7N55 HEAB : 5.45x39 proximity airburst (counter-UAS)
    //   The Mk361 PAB scaled to the lighter 5.45 bullet: a smaller
    //   frag sleeve (~1.5% of the 40mm warhead) and a slightly
    //   tighter fuze. Registered in XEH_postInit.sqf.
    // =========================================================
    class FA_o_545x39_7N55_HEAB: FA_o_545x39_7N44_HP {
        displayName = "5.45x39 7N55 HEAB";
        hit = 7; caliber = 1.4;
        indirectHitRange = 1.15;
        ace_frag_metal = 3.0;
        ace_frag_charge = 0.47;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = 0.5;
        ace_frag_classes[] = {"ace_frag_tiny", "ace_frag_tiny_HD"};
    };
    class FA_o_545x39_7N55_HEAB_T_Red:    FA_o_545x39_7N55_HEAB { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_o_545x39_7N55_HEAB_T_Yellow: FA_o_545x39_7N55_HEAB { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_o_545x39_7N55_HEAB_T_Green:  FA_o_545x39_7N55_HEAB { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_o_545x39_7N55_HEAB_T_White:  FA_o_545x39_7N55_HEAB { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_o_545x39_7N55_HEAB_T_Blue:   FA_o_545x39_7N55_HEAB { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_o_545x39_7N55_HEAB_T_Orange: FA_o_545x39_7N55_HEAB { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_o_545x39_7N55_HEAB_T_IR:     FA_o_545x39_7N55_HEAB { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // 7N56 AD : 5.45x39 anti-drone shot (K short / L long)
    //   Mk368 pattern rule, scaled down for the smaller case: one
    //   pellet fewer on the K, the same count on the L, and 10% less
    //   reach on both. coneAngle = atan(0.3048 / effective range).
    // =========================================================
    // ---- 7N56K - 7 pellets, eff. 90 m, 660 m/s ----
    class FA_o_545x39_7N56K_AD_Sub: AK2035_545x39SG_Ball_Deploy {
        hit = 4.3;
        caliber = 0.48;
        airFriction = -0.0080;
        typicalSpeed = 660;
        airLock = 1;
        timeToLive = 3;
    };
    class FA_o_545x39_7N56K_AD: AK2035_545x39SG_Ball_F {
        displayName = "5.45mm 7N56K AD Shot";
        triggerTime = 0;
        submunitionAmmo = "FA_o_545x39_7N56K_AD_Sub";
        submunitionConeType[] = {"poissondisccenter", 7};
        submunitionConeAngle = 0.194; // 1 ft pattern radius at 90 m
        typicalSpeed = 660;
    };
    // ---- 7N56L - 5 heavier pellets, eff. 180 m, 660 m/s ----
    class FA_o_545x39_7N56L_AD_Sub: AK2035_545x39SG_Ball_Deploy {
        hit = 5.6;
        caliber = 0.56;
        airFriction = -0.0045;
        typicalSpeed = 660;
        airLock = 1;
        timeToLive = 3;
    };
    class FA_o_545x39_7N56L_AD: AK2035_545x39SG_Ball_F {
        displayName = "5.45mm 7N56L AD Shot";
        triggerTime = 0;
        submunitionAmmo = "FA_o_545x39_7N56L_AD_Sub";
        submunitionConeType[] = {"poissondisccenter", 5};
        submunitionConeAngle = 0.097; // 1 ft pattern radius at 180 m
        typicalSpeed = 660;
    };

    // =========================================================
    // PSP-2 UW : 5.45 supercavitating dart for the ADS35
    //   Heavier than the vanilla dual-medium dart the ADS35 mag
    //   fires. No ACE ballistics data on purpose - Advanced
    //   Ballistics has no water model, so the engine rules.
    // =========================================================
    class FA_o_545x39_PSP2_UW: B_556x45_dual {
        displayName = "5.45x39 PSP-2 UW";
        hit = 10; caliber = 1.2; typicalSpeed = 300; airFriction = -0.016; waterFriction = -0.008; deflecting = 10;
    };

    // =========================================================
    // 7N49 AP : 7.62x54R tungsten armour piercer (7N13 / 7N26 line)
    // =========================================================
    class FA_o_762x54R_7N49_AP: FA_o_762x54R_Ball_HV {
        displayName = "7.62x54R 7N49 AP";
        hit = 15; caliber = 3.8; typicalSpeed = 830; airFriction = -0.00074; deflecting = 11;
        ACE_bulletLength = 33.0; ACE_bulletMass = 9.9;
        ACE_ballisticCoefficients[] = {0.245};
        ACE_muzzleVelocities[] = {800, 830, 850};
        ACE_barrelLengths[]    = {550, 620, 720};
    };
    class FA_o_762x54R_7N49_AP_T_Red:    FA_o_762x54R_7N49_AP { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_o_762x54R_7N49_AP_T_Yellow: FA_o_762x54R_7N49_AP { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_o_762x54R_7N49_AP_T_Green:  FA_o_762x54R_7N49_AP { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_o_762x54R_7N49_AP_T_White:  FA_o_762x54R_7N49_AP { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_o_762x54R_7N49_AP_T_Blue:   FA_o_762x54R_7N49_AP { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_o_762x54R_7N49_AP_T_Orange: FA_o_762x54R_7N49_AP { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_o_762x54R_7N49_AP_T_IR:     FA_o_762x54R_7N49_AP { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // 7U18 SUB : 7.62x54R subsonic, 200 gr - suppressed marksman load.
    //   Velocity-capped under Mach 1; gains come from mass.
    // =========================================================
    class FA_o_762x54R_7U18_SUB: FA_o_762x54R_Ball_HV {
        displayName = "7.62x54R 7U18 SUB";
        hit = 13; caliber = 1.8; typicalSpeed = 310; airFriction = -0.00050; deflecting = 13;
        ACE_bulletLength = 38.0; ACE_bulletMass = 13.0;
        ACE_ballisticCoefficients[] = {0.300};
        ACE_muzzleVelocities[] = {300, 310, 315};
        ACE_barrelLengths[]    = {550, 620, 720};
    };
    class FA_o_762x54R_7U18_SUB_T_Red:    FA_o_762x54R_7U18_SUB { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_o_762x54R_7U18_SUB_T_Yellow: FA_o_762x54R_7U18_SUB { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_o_762x54R_7U18_SUB_T_Green:  FA_o_762x54R_7U18_SUB { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_o_762x54R_7U18_SUB_T_White:  FA_o_762x54R_7U18_SUB { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_o_762x54R_7U18_SUB_T_Blue:   FA_o_762x54R_7U18_SUB { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_o_762x54R_7U18_SUB_T_Orange: FA_o_762x54R_7U18_SUB { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_o_762x54R_7U18_SUB_T_IR:     FA_o_762x54R_7U18_SUB { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // ===== 9x19 (MP-443 / MP-446 S) =====
    // 7N53 AP - tungsten-core armour piercer (7N31 successor).
    class FA_o_9x19_7N53_AP: B_9x19_7N31 {
        displayName = "9x19 7N53 AP";
        caliber = 2.0; hit = 9; typicalSpeed = 470; airFriction = -0.0019; deflecting = 20;
        ACE_caliber = 9.02; ACE_bulletLength = 15.5; ACE_bulletMass = 4.9;
        ACE_dragModel = 1; ACE_ballisticCoefficients[] = {0.130};
        ACE_muzzleVelocities[] = {470}; ACE_barrelLengths[] = {112};
    };
    // 7U17 SUB - heavy subsonic load for the suppressed MP-446 S.
    class FA_o_9x19_7U17_SUB: B_9x19_7N31 {
        displayName = "9x19 7U17 SUB";
        caliber = 1.0; hit = 9; typicalSpeed = 295; airFriction = -0.0016; deflecting = 25;
        ACE_caliber = 9.02; ACE_bulletLength = 16.5; ACE_bulletMass = 9.5;
        ACE_dragModel = 1; ACE_ballisticCoefficients[] = {0.165};
        ACE_muzzleVelocities[] = {295}; ACE_barrelLengths[] = {112};
    };

    // =========================================================
    // KS-23 23mm - anti-drone family. The 12 ga Mk360 AD / Mk363
    // PAB-S pair scaled up to the 23mm (~4 gauge) shell: about
    // 1.5x the bore area, so more pellets, more reach and a bigger
    // frag sleeve. KS-23 barrel 510 mm.
    // =========================================================
    // ---- Shrapnel-AD50 - dense 24-pellet screen, eff. 50 m (config only) ----
    class FA_o_23mm_ShrapnelAD50_Sub: B_23Gauge_Pellets_Submunition_Deploy {
        hit = 6;
        caliber = 0.9;
        airFriction = -0.0085;
        typicalSpeed = 400;
        timeToLive = 2;
    };
    class FA_o_23mm_ShrapnelAD50: B_23Gauge_Pellets_Submunition {
        displayName = "23mm Shrapnel-AD50";
        submunitionAmmo = "FA_o_23mm_ShrapnelAD50_Sub";
        submunitionConeType[] = {"poissondisccenter", 24};
        submunitionConeAngle = 1.7; // ~1.5 m pattern radius at 50 m
        ACE_barrelLengths[] = {510};
        ACE_muzzleVelocities[] = {400};
    };
    // ---- Shrapnel-AD100 - 14 heavy tungsten pellets, eff. 100 m (config only) ----
    class FA_o_23mm_ShrapnelAD100_Sub: B_23Gauge_Pellets_Submunition_Deploy {
        hit = 9;
        caliber = 1.1;
        airFriction = -0.0050;
        typicalSpeed = 380;
        timeToLive = 3;
    };
    class FA_o_23mm_ShrapnelAD100: B_23Gauge_Pellets_Submunition {
        displayName = "23mm Shrapnel-AD100";
        submunitionAmmo = "FA_o_23mm_ShrapnelAD100_Sub";
        submunitionConeType[] = {"poissondisccenter", 14};
        submunitionConeAngle = 0.86; // ~1.5 m pattern radius at 100 m
        ACE_barrelLengths[] = {510};
        ACE_muzzleVelocities[] = {380};
    };
    // ---- Barrikada-AB - proximity airburst slug (script-driven) ----
    // Flies as a slug; the antidrone proximity fuze (XEH_postInit.sqf) bursts
    // it near a UAV. ACE frag: fabricated sleeve, ~20% of the 40mm warhead
    // (the 12 ga Mk363's 12.22% x the 23mm shell's larger volume).
    class FA_o_23mm_BarrikadaAB: B_23Gauge_Slug {
        displayName = "23mm Barrikada-AB";
        hit = 6;
        caliber = 1.0;
        airFriction = -0.0045;
        typicalSpeed = 420;
        airLock = 1;
        indirectHitRange = 2.0;
        ace_frag_metal = 40.0;
        ace_frag_charge = 6.4;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = 0.5;
        ace_frag_classes[] = {"ace_frag_tiny_HD", "ace_frag_small_HD"};
        ACE_barrelLengths[] = {510};
        ACE_muzzleVelocities[] = {420};
    };

    // =========================================================
    // RPG-26 / RShG-2 72.5mm - 2040 disposables, same tiering as FA's
    // RPG set. Penetration scale: engine RHA ~ penetrator caliber x 15 mm
    // (rearma's RPG-26 penetrator = 29.3 -> ~440 mm).
    // =========================================================
    // RPG-26M2 TNDM - ~600 mm RHA tandem
    class FA_ammo_Penetrator_RPG26M2: ammo_Penetrator_Base {
        caliber = 40;
        warheadName = "TandemHEAT";
        hit = 440;
    };
    class FA_R_RPG26M2_TNDM: R_PG26_AT {
        warheadName = "TandemHEAT";
        submunitionAmmo = "FA_ammo_Penetrator_RPG26M2";
        hit = 90;
    };
    // RPG-26 AB PROX - prefragmented proximity airburst vs drones; scripted fuze
    class FA_R_RPG26_AB26: R_PG26_AT {
        submunitionAmmo = "";
        submunitionDirectionType = "";
        submunitionInitSpeed = 0;
        triggerOnImpact = 0;
        warheadName = "HE";
        explosive = 1;
        hit = 80;
        indirectHit = 30;
        indirectHitRange = 6;
        ace_frag_metal = 1300;
        ace_frag_charge = 200;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = 0.5;
        ace_frag_classes[] = {"ace_frag_small", "ace_frag_small_HD"};
    };
    // RShG-2M2 TBX - heavier thermobaric fill than rearma's RShG-2
    class FA_R_RShG2M2_TBX: R_RSHG2_HE {
        explosive = 1;
        hit = 180;
        indirectHit = 48;
        indirectHitRange = 8;
        CraterEffects = "ArtyShellCrater";
        explosionEffects = "MortarExplosion";
    };
};
