class CfgAmmo {
    class B_556x45_Ball;
    class B_762x51_Ball;
    class B_762x39_Ball_F;
    class B_93x64_Ball;
    class B_127x108_Ball;
    class B_127x99_Ball;
    class B_45ACP_Ball;
    class B_9x21_Ball;
    class BulletBase;
    class B_338_Mag: BulletBase {};
    class B_338_LM_Ball: B_338_Mag {};
    class B_338_NM_Ball: BulletBase {}; // the game's parent (weapons_f_mark) - B_338_Mag rebinds it, RPT "Updating base class"
    class B_65x39_Caseless;
    class B_12Gauge_Pellets_Submunition;
    class B_12Gauge_Pellets_Submunition_Cartridge: B_12Gauge_Pellets_Submunition {};
    class B_12Gauge_Slug;

    // =========================================================
    // 5.56x45mm
    // =========================================================

    // Release 1 (~2033) — Mk327 Mod 0 EPR-HV, hybrid case, ~83 kpsi, 70gr tungsten
    class FA_b_556_Mk327_HV: B_556x45_Ball {
        hit = 10;
        caliber = 2.4;
        typicalSpeed = 960;
        airFriction = -0.00126;
        deflecting = 15;
        tracerScale = 0.6;
        ACE_caliber = 5.69;
        ACE_bulletLength = 23.0;
        ACE_bulletMass = 4.0;
        ACE_muzzleVelocityVariationSD = 0.18;
        ACE_ballisticCoefficients[] = {0.151};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {900, 960, 1000};
        ACE_barrelLengths[] = {254, 368, 508};
    };
    class FA_b_556_Mk327_HV_T_Red: FA_b_556_Mk327_HV { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_556_Mk327_HV_T_Yellow: FA_b_556_Mk327_HV { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_556_Mk327_HV_T_Green: FA_b_556_Mk327_HV { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_556_Mk327_HV_T_White: FA_b_556_Mk327_HV { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_556_Mk327_HV_T_Blue: FA_b_556_Mk327_HV { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_556_Mk327_HV_T_Orange: FA_b_556_Mk327_HV { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_556_Mk327_HV_T_IR: FA_b_556_Mk327_HV { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // Release 2 (~2039) — XM891 CTEP, cased-telescoped composite, ~85 kpsi, 68gr 2-stage tungsten
    class FA_b_556_XM891_CTEP: B_556x45_Ball {
        hit = 11;
        caliber = 2.6;
        typicalSpeed = 980;
        airFriction = -0.00120;
        deflecting = 14;
        tracerScale = 0.6;
        ACE_caliber = 5.69;
        ACE_bulletLength = 24.0;
        ACE_bulletMass = 4.0;
        ACE_muzzleVelocityVariationSD = 0.16;
        ACE_ballisticCoefficients[] = {0.162};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {915, 980, 1020};
        ACE_barrelLengths[] = {254, 368, 508};
    };
    class FA_b_556_XM891_CTEP_T_Red: FA_b_556_XM891_CTEP { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_556_XM891_CTEP_T_Yellow: FA_b_556_XM891_CTEP { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_556_XM891_CTEP_T_Green: FA_b_556_XM891_CTEP { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_556_XM891_CTEP_T_White: FA_b_556_XM891_CTEP { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_556_XM891_CTEP_T_Blue: FA_b_556_XM891_CTEP { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_556_XM891_CTEP_T_Orange: FA_b_556_XM891_CTEP { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_556_XM891_CTEP_T_IR: FA_b_556_XM891_CTEP { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // Mk332 AP — caseless-era 5.56 tungsten armor-piercing (metric, 2040)
    class FA_b_556_Mk332_AP: B_556x45_Ball {
        hit = 10; caliber = 3.0; typicalSpeed = 940; airFriction = -0.00118; deflecting = 12; tracerScale = 0.6;
        ACE_caliber = 5.69; ACE_bulletLength = 24.5; ACE_bulletMass = 4.2; ACE_muzzleVelocityVariationSD = 0.15;
        ACE_ballisticCoefficients[] = {0.170}; ACE_velocityBoundaries[] = {}; ACE_standardAtmosphere = "ICAO"; ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {880, 940, 980}; ACE_barrelLengths[] = {254, 368, 508};
    };
    class FA_b_556_Mk332_AP_T_Red: FA_b_556_Mk332_AP { tracer = 1; tracerColor[] = {1.0,0.0,0.0,1.0}; };
    class FA_b_556_Mk332_AP_T_Yellow: FA_b_556_Mk332_AP { tracer = 1; tracerColor[] = {1.0,1.0,0.0,1.0}; };
    class FA_b_556_Mk332_AP_T_Green: FA_b_556_Mk332_AP { tracer = 1; tracerColor[] = {0.0,1.0,0.0,1.0}; };
    class FA_b_556_Mk332_AP_T_White: FA_b_556_Mk332_AP { tracer = 1; tracerColor[] = {1.0,1.0,1.0,1.0}; };
    class FA_b_556_Mk332_AP_T_Blue: FA_b_556_Mk332_AP { tracer = 1; tracerColor[] = {0.0,0.3,1.0,1.0}; };
    class FA_b_556_Mk332_AP_T_Orange: FA_b_556_Mk332_AP { tracer = 1; tracerColor[] = {1.0,0.4,0.0,1.0}; };
    class FA_b_556_Mk332_AP_T_IR: FA_b_556_Mk332_AP { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2,1.0,0.2,1.0}; };

    // =========================================================
    // 7.62x51mm
    // =========================================================

    // Release 1 (~2032) — M80A2 HV-EPR, hybrid case, ~78 kpsi, 135gr tungsten
    class FA_b_762_M80A2_HV: B_762x51_Ball {
        hit = 14;
        caliber = 3.0;
        typicalSpeed = 940;
        airFriction = -0.00082;
        deflecting = 15;
        tracerScale = 0.8;
        ACE_caliber = 7.82;
        ACE_bulletLength = 29.21;
        ACE_bulletMass = 8.75;
        ACE_ballisticCoefficients[] = {0.228};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {885, 920, 940, 955};
        ACE_barrelLengths[] = {406, 508, 610, 660};
    };
    class FA_b_762_M80A2_HV_T_Red: FA_b_762_M80A2_HV { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_762_M80A2_HV_T_Yellow: FA_b_762_M80A2_HV { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_762_M80A2_HV_T_Green: FA_b_762_M80A2_HV { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_762_M80A2_HV_T_White: FA_b_762_M80A2_HV { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_762_M80A2_HV_T_Blue: FA_b_762_M80A2_HV { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_762_M80A2_HV_T_Orange: FA_b_762_M80A2_HV { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_762_M80A2_HV_T_IR: FA_b_762_M80A2_HV { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // Release 2 (~2039) — XM751 CTEP, cased-telescoped, ~82 kpsi, 140gr 2-stage tungsten
    class FA_b_762_XM751_CTEP: B_762x51_Ball {
        hit = 15;
        caliber = 3.4;
        typicalSpeed = 960;
        airFriction = -0.00078;
        deflecting = 14;
        tracerScale = 0.8;
        ACE_caliber = 7.82;
        ACE_bulletLength = 30.48;
        ACE_bulletMass = 9.07;
        ACE_ballisticCoefficients[] = {0.245};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {905, 945, 960, 975};
        ACE_barrelLengths[] = {406, 508, 610, 660};
    };
    class FA_b_762_XM751_CTEP_T_Red: FA_b_762_XM751_CTEP { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_762_XM751_CTEP_T_Yellow: FA_b_762_XM751_CTEP { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_762_XM751_CTEP_T_Green: FA_b_762_XM751_CTEP { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_762_XM751_CTEP_T_White: FA_b_762_XM751_CTEP { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_762_XM751_CTEP_T_Blue: FA_b_762_XM751_CTEP { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_762_XM751_CTEP_T_Orange: FA_b_762_XM751_CTEP { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_762_XM751_CTEP_T_IR: FA_b_762_XM751_CTEP { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // 7.62x67mm (.300 Win Mag) — Mk248 family
    // No vanilla .300 WM base — inherits B_762x51_Ball (.308 bore) as a
    // structural placeholder; ACE ballistics drive the real behaviour.
    // =========================================================
    // Mk248 Mod 2 — 220gr hybrid + tungsten, extreme long range
    class FA_b_762x67_Mk248Mod2: B_762x51_Ball {
        hit = 13;
        caliber = 3.6;
        typicalSpeed = 900;
        airFriction = -0.00080;
        deflecting = 12;
        tracerScale = 0.8;
        ACE_caliber = 7.82;
        ACE_bulletLength = 38.1;
        ACE_bulletMass = 14.26;
        ACE_ballisticCoefficients[] = {0.330};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {850, 890, 900};
        ACE_barrelLengths[]    = {508, 609.6, 660.4};
    };
    class FA_b_762x67_Mk248Mod2_T_Red:    FA_b_762x67_Mk248Mod2 { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_762x67_Mk248Mod2_T_Yellow: FA_b_762x67_Mk248Mod2 { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_762x67_Mk248Mod2_T_Green:  FA_b_762x67_Mk248Mod2 { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_762x67_Mk248Mod2_T_White:  FA_b_762x67_Mk248Mod2 { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_762x67_Mk248Mod2_T_Blue:   FA_b_762x67_Mk248Mod2 { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_762x67_Mk248Mod2_T_Orange: FA_b_762x67_Mk248Mod2 { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_762x67_Mk248Mod2_T_IR:     FA_b_762x67_Mk248Mod2 { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // Mk248 LV — 190gr light, fast, flat-shooting
    class FA_b_762x67_Mk248LV: B_762x51_Ball {
        hit = 12;
        caliber = 3.2;
        typicalSpeed = 965;
        airFriction = -0.00090;
        deflecting = 13;
        tracerScale = 0.8;
        ACE_caliber = 7.82;
        ACE_bulletLength = 33.02;
        ACE_bulletMass = 12.31;
        ACE_ballisticCoefficients[] = {0.275};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {910, 950, 965};
        ACE_barrelLengths[]    = {508, 609.6, 660.4};
    };
    class FA_b_762x67_Mk248LV_T_Red:    FA_b_762x67_Mk248LV { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_762x67_Mk248LV_T_Yellow: FA_b_762x67_Mk248LV { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_762x67_Mk248LV_T_Green:  FA_b_762x67_Mk248LV { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_762x67_Mk248LV_T_White:  FA_b_762x67_Mk248LV { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_762x67_Mk248LV_T_Blue:   FA_b_762x67_Mk248LV { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_762x67_Mk248LV_T_Orange: FA_b_762x67_Mk248LV { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_762x67_Mk248LV_T_IR:     FA_b_762x67_Mk248LV { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // .300 BLK (subsonic) — velocity-capped, improves via mass/material only
    // =========================================================

    // Release 1 (~2033) — Mk341 SUB-AP, conventional brass, ~48 kpsi, 210gr tungsten
    class FA_b_300_Mk341_SubAP: B_762x51_Ball {
        hit = 10;
        caliber = 2.3;
        typicalSpeed = 315;
        airFriction = -0.00055;
        deflecting = 14;
        tracerScale = 0.7;
        ACE_caliber = 7.82;
        ACE_bulletLength = 34.54;
        ACE_bulletMass = 13.61;
        ACE_ballisticCoefficients[] = {0.290};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {300, 310, 315};
        ACE_barrelLengths[] = {229, 305, 406};
    };
    class FA_b_300_Mk341_SubAP_T_Red: FA_b_300_Mk341_SubAP { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_300_Mk341_SubAP_T_Yellow: FA_b_300_Mk341_SubAP { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_300_Mk341_SubAP_T_Green: FA_b_300_Mk341_SubAP { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_300_Mk341_SubAP_T_White: FA_b_300_Mk341_SubAP { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_300_Mk341_SubAP_T_Blue: FA_b_300_Mk341_SubAP { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_300_Mk341_SubAP_T_Orange: FA_b_300_Mk341_SubAP { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_300_Mk341_SubAP_T_IR: FA_b_300_Mk341_SubAP { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // Release 2 (~2039) — XM345 SUB-AP2, conventional brass, ~49 kpsi, 220gr 2-stage tungsten
    class FA_b_300_XM345_SubAP2: B_762x51_Ball {
        hit = 11;
        caliber = 2.7;
        typicalSpeed = 312;
        airFriction = -0.00052;
        deflecting = 13;
        tracerScale = 0.7;
        ACE_caliber = 7.82;
        ACE_bulletLength = 35.56;
        ACE_bulletMass = 14.26;
        ACE_ballisticCoefficients[] = {0.310};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {298, 308, 312};
        ACE_barrelLengths[] = {229, 305, 406};
    };
    class FA_b_300_XM345_SubAP2_T_Red: FA_b_300_XM345_SubAP2 { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_300_XM345_SubAP2_T_Yellow: FA_b_300_XM345_SubAP2 { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_300_XM345_SubAP2_T_Green: FA_b_300_XM345_SubAP2 { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_300_XM345_SubAP2_T_White: FA_b_300_XM345_SubAP2 { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_300_XM345_SubAP2_T_Blue: FA_b_300_XM345_SubAP2 { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_300_XM345_SubAP2_T_Orange: FA_b_300_XM345_SubAP2 { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_300_XM345_SubAP2_T_IR: FA_b_300_XM345_SubAP2 { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // .338 Lapua Magnum — Mk371 LRP (hybrid case, tungsten)
    // All three Mods share the MAR-10 magazine well.
    // =========================================================

    // Mod 0 — 250gr, fastest, flattest near-to-mid
    class FA_b_338_Mk371_250gr: B_338_LM_Ball {
        hit = 22;
        caliber = 3.6;
        typicalSpeed = 905;
        airFriction = -0.00055;
        deflecting = 12;
        tracerScale = 1.0;
        ACE_caliber = 8.59;
        ACE_bulletLength = 37.01;
        ACE_bulletMass = 16.2;
        ACE_ballisticCoefficients[] = {0.322};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {875, 895, 905};
        ACE_barrelLengths[] = {610, 660, 686};
    };
    class FA_b_338_Mk371_250gr_T_Red: FA_b_338_Mk371_250gr { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_338_Mk371_250gr_T_Yellow: FA_b_338_Mk371_250gr { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_338_Mk371_250gr_T_Green: FA_b_338_Mk371_250gr { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_338_Mk371_250gr_T_White: FA_b_338_Mk371_250gr { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_338_Mk371_250gr_T_Blue: FA_b_338_Mk371_250gr { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_338_Mk371_250gr_T_Orange: FA_b_338_Mk371_250gr { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_338_Mk371_250gr_T_IR: FA_b_338_Mk371_250gr { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // Mod 1 — 285gr, balanced BC vs speed
    class FA_b_338_Mk371_285gr: B_338_LM_Ball {
        hit = 24;
        caliber = 3.8;
        typicalSpeed = 870;
        airFriction = -0.00050;
        deflecting = 11;
        tracerScale = 1.0;
        ACE_caliber = 8.59;
        ACE_bulletLength = 41.66;
        ACE_bulletMass = 18.47;
        ACE_ballisticCoefficients[] = {0.380};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {840, 862, 870};
        ACE_barrelLengths[] = {610, 660, 686};
    };
    class FA_b_338_Mk371_285gr_T_Red: FA_b_338_Mk371_285gr { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_338_Mk371_285gr_T_Yellow: FA_b_338_Mk371_285gr { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_338_Mk371_285gr_T_Green: FA_b_338_Mk371_285gr { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_338_Mk371_285gr_T_White: FA_b_338_Mk371_285gr { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_338_Mk371_285gr_T_Blue: FA_b_338_Mk371_285gr { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_338_Mk371_285gr_T_Orange: FA_b_338_Mk371_285gr { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_338_Mk371_285gr_T_IR: FA_b_338_Mk371_285gr { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // Mod 2 — 300gr, extreme range, best retained velocity
    class FA_b_338_Mk371_300gr: B_338_LM_Ball {
        hit = 25;
        caliber = 4.0;
        typicalSpeed = 830;
        airFriction = -0.00046;
        deflecting = 10;
        tracerScale = 1.0;
        ACE_caliber = 8.59;
        ACE_bulletLength = 43.69;
        ACE_bulletMass = 19.44;
        ACE_ballisticCoefficients[] = {0.400};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {805, 825, 830};
        ACE_barrelLengths[] = {610, 660, 686};
    };
    class FA_b_338_Mk371_300gr_T_Red: FA_b_338_Mk371_300gr { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_338_Mk371_300gr_T_Yellow: FA_b_338_Mk371_300gr { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_338_Mk371_300gr_T_Green: FA_b_338_Mk371_300gr { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_338_Mk371_300gr_T_White: FA_b_338_Mk371_300gr { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_338_Mk371_300gr_T_Blue: FA_b_338_Mk371_300gr { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_338_Mk371_300gr_T_Orange: FA_b_338_Mk371_300gr { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_338_Mk371_300gr_T_IR: FA_b_338_Mk371_300gr { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // .300 BLK (supersonic) — Mk335 / Mk336 / Mk337
    // STANAG-compatible; gate to .300 BLK rated weapons for balance.
    // =========================================================

    // Mk335 — 110gr light supersonic
    class FA_b_300_Mk335: B_762x51_Ball {
        hit = 9;
        caliber = 1.4;
        typicalSpeed = 725;
        airFriction = -0.00170;
        deflecting = 20;
        tracerScale = 0.7;
        ACE_caliber = 7.82;
        ACE_bulletLength = 24.89;
        ACE_bulletMass = 7.13;
        ACE_ballisticCoefficients[] = {0.130};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {640, 690, 725};
        ACE_barrelLengths[] = {229, 305, 406};
    };
    class FA_b_300_Mk335_T_Red: FA_b_300_Mk335 { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_300_Mk335_T_Yellow: FA_b_300_Mk335 { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_300_Mk335_T_Green: FA_b_300_Mk335 { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_300_Mk335_T_White: FA_b_300_Mk335 { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_300_Mk335_T_Blue: FA_b_300_Mk335 { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_300_Mk335_T_Orange: FA_b_300_Mk335 { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_300_Mk335_T_IR: FA_b_300_Mk335 { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // Mk336 — 125gr standard supersonic
    class FA_b_300_Mk336: B_762x51_Ball {
        hit = 10;
        caliber = 1.5;
        typicalSpeed = 675;
        airFriction = -0.00150;
        deflecting = 18;
        tracerScale = 0.7;
        ACE_caliber = 7.82;
        ACE_bulletLength = 26.67;
        ACE_bulletMass = 8.1;
        ACE_ballisticCoefficients[] = {0.160};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {600, 650, 675};
        ACE_barrelLengths[] = {229, 305, 406};
    };
    class FA_b_300_Mk336_T_Red: FA_b_300_Mk336 { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_300_Mk336_T_Yellow: FA_b_300_Mk336 { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_300_Mk336_T_Green: FA_b_300_Mk336 { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_300_Mk336_T_White: FA_b_300_Mk336 { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_300_Mk336_T_Blue: FA_b_300_Mk336 { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_300_Mk336_T_Orange: FA_b_300_Mk336 { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_300_Mk336_T_IR: FA_b_300_Mk336 { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // Mk337 — 150gr heavy supersonic (drops subsonic at distance)
    class FA_b_300_Mk337: B_762x51_Ball {
        hit = 11;
        caliber = 1.6;
        typicalSpeed = 620;
        airFriction = -0.00140;
        deflecting = 17;
        tracerScale = 0.7;
        ACE_caliber = 7.82;
        ACE_bulletLength = 27.94;
        ACE_bulletMass = 9.72;
        ACE_ballisticCoefficients[] = {0.180};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {560, 600, 620};
        ACE_barrelLengths[] = {229, 305, 406};
    };
    class FA_b_300_Mk337_T_Red: FA_b_300_Mk337 { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_300_Mk337_T_Yellow: FA_b_300_Mk337 { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_300_Mk337_T_Green: FA_b_300_Mk337 { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_300_Mk337_T_White: FA_b_300_Mk337 { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_300_Mk337_T_Blue: FA_b_300_Mk337 { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_300_Mk337_T_Orange: FA_b_300_Mk337 { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_300_Mk337_T_IR: FA_b_300_Mk337 { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // .300 BLK (subsonic) — Mk342 / Mk343 (non-AP variants)
    // Complement to Mk341 SUB-AP / XM345 SUB-AP2; no tungsten core.
    // =========================================================

    // Mk342 — 190gr subsonic
    class FA_b_300_Mk342_Sub: B_762x51_Ball {
        hit = 8;
        caliber = 1.7;
        typicalSpeed = 318;
        airFriction = -0.00060;
        deflecting = 15;
        tracerScale = 0.7;
        ACE_caliber = 7.82;
        ACE_bulletLength = 32.51;
        ACE_bulletMass = 12.31;
        ACE_ballisticCoefficients[] = {0.250};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {300, 312, 318};
        ACE_barrelLengths[] = {229, 305, 406};
    };
    class FA_b_300_Mk342_Sub_T_Red: FA_b_300_Mk342_Sub { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_300_Mk342_Sub_T_Yellow: FA_b_300_Mk342_Sub { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_300_Mk342_Sub_T_Green: FA_b_300_Mk342_Sub { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_300_Mk342_Sub_T_White: FA_b_300_Mk342_Sub { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_300_Mk342_Sub_T_Blue: FA_b_300_Mk342_Sub { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_300_Mk342_Sub_T_Orange: FA_b_300_Mk342_Sub { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_300_Mk342_Sub_T_IR: FA_b_300_Mk342_Sub { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // Mk343 — 220gr heavy subsonic (best BC, quietest)
    class FA_b_300_Mk343_Sub: B_762x51_Ball {
        hit = 9;
        caliber = 1.9;
        typicalSpeed = 305;
        airFriction = -0.00055;
        deflecting = 14;
        tracerScale = 0.7;
        ACE_caliber = 7.82;
        ACE_bulletLength = 34.54;
        ACE_bulletMass = 14.26;
        ACE_ballisticCoefficients[] = {0.300};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {295, 303, 305};
        ACE_barrelLengths[] = {229, 305, 406};
    };
    class FA_b_300_Mk343_Sub_T_Red: FA_b_300_Mk343_Sub { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_300_Mk343_Sub_T_Yellow: FA_b_300_Mk343_Sub { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_300_Mk343_Sub_T_Green: FA_b_300_Mk343_Sub { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_300_Mk343_Sub_T_White: FA_b_300_Mk343_Sub { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_300_Mk343_Sub_T_Blue: FA_b_300_Mk343_Sub { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_300_Mk343_Sub_T_Orange: FA_b_300_Mk343_Sub { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_300_Mk343_Sub_T_IR: FA_b_300_Mk343_Sub { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // .338 Norma Magnum — Mk372 MMG (hybrid case, tungsten)
    // Belt-fed medium MG role; pairs with Mk371 LRP (precision).
    // Base: B_338_NM_Ball (vanilla SPMG round).
    // =========================================================

    // Mk372 — 300gr, high BC, best sustained-fire reach (single load)
    class FA_b_338_Mk372: B_338_NM_Ball {
        hit = 25;
        caliber = 4.0;
        typicalSpeed = 810;
        airFriction = -0.00046;
        deflecting = 10;
        tracerScale = 1.0;
        ACE_caliber = 8.59;
        ACE_bulletLength = 43.69;
        ACE_bulletMass = 19.44;
        ACE_ballisticCoefficients[] = {0.400};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {780, 800, 810};
        ACE_barrelLengths[] = {600, 640, 680};
    };
    class FA_b_338_Mk372_T_Red: FA_b_338_Mk372 { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_338_Mk372_T_Yellow: FA_b_338_Mk372 { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_338_Mk372_T_Green: FA_b_338_Mk372 { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_338_Mk372_T_White: FA_b_338_Mk372 { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_338_Mk372_T_Blue: FA_b_338_Mk372 { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_338_Mk372_T_Orange: FA_b_338_Mk372 { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_338_Mk372_T_IR: FA_b_338_Mk372 { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // 6.5x39 Caseless (Arma 3 canon, 2035)
    // Inherits vanilla caseless; gate to MX family via magazineWell.
    // =========================================================

    // =========================================================
    // 5.8x42mm Chinese (Type 95/97 family)
    // =========================================================

    // Ball HV (~2033) — 64gr tungsten-core, ~940 m/s
    class FA_o_580_Ball_HV: B_556x45_Ball {
        displayName = "5.8x42mm Ball HV";
        hit = 11;
        caliber = 2.2;
        typicalSpeed = 940;
        airFriction = -0.00095;
        deflecting = 18;
        tracerScale = 0.6;
        ACE_caliber = 5.79;
        ACE_bulletLength = 22.61;
        ACE_bulletMass = 4.15;
        ACE_ballisticCoefficients[] = {0.200};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {895, 925, 940, 960};
        ACE_barrelLengths[] = {368, 406, 463, 508};
    };
    class FA_o_580_Ball_HV_T_Red: FA_o_580_Ball_HV { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_o_580_Ball_HV_T_Yellow: FA_o_580_Ball_HV { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_o_580_Ball_HV_T_Green: FA_o_580_Ball_HV { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_o_580_Ball_HV_T_White: FA_o_580_Ball_HV { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_o_580_Ball_HV_T_Blue: FA_o_580_Ball_HV { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_o_580_Ball_HV_T_Orange: FA_o_580_Ball_HV { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_o_580_Ball_HV_T_IR: FA_o_580_Ball_HV { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // 7.62x54R (PKM/PKP family — belt-fed LMG)
    // =========================================================

    // Ball HV (~2033) — 145gr tungsten-core, ~855 m/s
    class FA_o_762x54R_Ball_HV: B_762x51_Ball {
        displayName = "7.62x54R Ball HV";
        hit = 15;
        caliber = 3.2;
        typicalSpeed = 855;
        airFriction = -0.00078;
        deflecting = 15;
        tracerScale = 0.8;
        ACE_caliber = 7.92;
        ACE_bulletLength = 30.99;
        ACE_bulletMass = 9.4;
        ACE_ballisticCoefficients[] = {0.231};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {820, 845, 855, 865};
        ACE_barrelLengths[] = {525, 590, 658, 720};
    };
    class FA_o_762x54R_Ball_HV_T_Red: FA_o_762x54R_Ball_HV { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_o_762x54R_Ball_HV_T_Yellow: FA_o_762x54R_Ball_HV { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_o_762x54R_Ball_HV_T_Green: FA_o_762x54R_Ball_HV { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_o_762x54R_Ball_HV_T_White: FA_o_762x54R_Ball_HV { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_o_762x54R_Ball_HV_T_Blue: FA_o_762x54R_Ball_HV { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_o_762x54R_Ball_HV_T_Orange: FA_o_762x54R_Ball_HV { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_o_762x54R_Ball_HV_T_IR: FA_o_762x54R_Ball_HV { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // 6.5x39 Caseless (Arma 3 canon, 2035)
    // Inherits vanilla caseless; gate to MX family via magazineWell.
    // =========================================================

    // The whole West 6.5 family is pinned midway between the 5.56 and 7.62 lines:
    // every stat below is the arithmetic midpoint of its 5.56 and 7.62 role peer
    // (Mk327/M80A2 for GP, XM891/XM751 for CTEP), so 6.5 is a true intermediate —
    // ~2.9 kJ muzzle energy against 1.8 kJ (5.56) and 3.9 kJ (7.62).

    // 6.5mm Caseless EPR (~2035) — caseless, ~75 kpsi (fictional), 99gr tungsten
    // GP tier: midpoint of Mk327 HV (5.56) and M80A2 HV (7.62).
    class FA_b_65_EPR: B_65x39_Caseless {
        displayName = "Mk330 EPR";
        hit = 11;
        caliber = 2.7;
        typicalSpeed = 950;
        airFriction = -0.00104;
        deflecting = 15;
        tracerScale = 0.7;
        ACE_caliber = 6.71;
        ACE_bulletLength = 26.1;
        ACE_bulletMass = 6.4;
        ACE_muzzleVelocityVariationSD = 0.16;
        ACE_ballisticCoefficients[] = {0.190};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {910, 950, 985};
        ACE_barrelLengths[] = {330, 407, 508};
    };
    class FA_b_65_EPR_T_Red: FA_b_65_EPR { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_65_EPR_T_Yellow: FA_b_65_EPR { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_65_EPR_T_Green: FA_b_65_EPR { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_65_EPR_T_White: FA_b_65_EPR { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_65_EPR_T_Blue: FA_b_65_EPR { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_65_EPR_T_Orange: FA_b_65_EPR { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_65_EPR_T_IR: FA_b_65_EPR { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };
    // Mk331 AP — caseless tungsten armor-piercing (metric, 2040)
    // AP tier: 5.56 Mk332 AP carries +0.6 pen over its GP round, so the 6.5 AP sits
    // +0.6 over Mk330 (2.7 -> 3.3), between the 5.56 AP and a notional 7.62 AP.
    class FA_b_65_Mk331_AP: B_65x39_Caseless { hit=11; caliber=3.3; typicalSpeed=945; airFriction=-0.00100; deflecting=12; tracerScale=0.7; displayName="Mk331 AP"; ACE_caliber=6.71; ACE_bulletLength=27.0; ACE_bulletMass=6.6; ACE_muzzleVelocityVariationSD=0.14; ACE_ballisticCoefficients[]={0.201}; ACE_velocityBoundaries[]={}; ACE_standardAtmosphere="ICAO"; ACE_dragModel=7; ACE_muzzleVelocities[]={905,945,980}; ACE_barrelLengths[]={330,407,508}; };
    class FA_b_65_Mk331_AP_T_Red: FA_b_65_Mk331_AP { tracer=1; tracerColor[]={1,0,0,1}; };
    class FA_b_65_Mk331_AP_T_Yellow: FA_b_65_Mk331_AP { tracer=1; tracerColor[]={1,1,0,1}; };
    class FA_b_65_Mk331_AP_T_Green: FA_b_65_Mk331_AP { tracer=1; tracerColor[]={0,1,0,1}; };
    class FA_b_65_Mk331_AP_T_White: FA_b_65_Mk331_AP { tracer=1; tracerColor[]={1,1,1,1}; };
    class FA_b_65_Mk331_AP_T_Blue: FA_b_65_Mk331_AP { tracer=1; tracerColor[]={0,0.3,1,1}; };
    class FA_b_65_Mk331_AP_T_Orange: FA_b_65_Mk331_AP { tracer=1; tracerColor[]={1,0.4,0,1}; };
    class FA_b_65_Mk331_AP_T_IR: FA_b_65_Mk331_AP { tracer=1; nvgOnly=1; tracerColor[]={0.2,1,0.2,1}; };

    // ===== 6.5x39 caseless extra loads (Mk328/XM892/Mk329/XM893) =====
    // Same 5.56<->7.62 midpoint band as Mk330/Mk331 above, spread by role:
    // Mk328 hot GP, XM892 CTEP (both carbine, 330/407/508), then the two 610 mm
    // DMR/MG loads Mk329 LR and XM893 CTEP at the top of the band.
    class FA_b_ammo_65g_Mk328: B_65x39_Caseless { displayName = "Mk328 HV"; caliber = 2.8; hit = 11; typicalSpeed = 965; airFriction = -0.00101; deflecting = 14; tracerScale = 0.7; ACE_caliber = 6.71; ACE_bulletLength = 26.5; ACE_bulletMass = 6.4; ACE_muzzleVelocityVariationSD = 0.16; ACE_dragModel = 7; ACE_ballisticCoefficients[] = {0.196}; ACE_velocityBoundaries[] = {}; ACE_standardAtmosphere = "ICAO"; ACE_muzzleVelocities[] = {925, 965, 1000}; ACE_barrelLengths[] = {330, 407, 508}; };
    class FA_b_ammo_65g_XM892: B_65x39_Caseless { displayName = "XM892 CTEP"; caliber = 3.0; hit = 12; typicalSpeed = 970; airFriction = -0.00099; deflecting = 14; tracerScale = 0.7; ACE_caliber = 6.71; ACE_bulletLength = 27.2; ACE_bulletMass = 6.5; ACE_muzzleVelocityVariationSD = 0.14; ACE_dragModel = 7; ACE_ballisticCoefficients[] = {0.204}; ACE_velocityBoundaries[] = {}; ACE_standardAtmosphere = "ICAO"; ACE_muzzleVelocities[] = {930, 970, 1005}; ACE_barrelLengths[] = {330, 407, 508}; };
    class FA_b_ammo_65cm_Mk329: B_65x39_Caseless { displayName = "Mk329 LR"; caliber = 2.9; hit = 12; typicalSpeed = 960; airFriction = -0.00095; deflecting = 13; tracerScale = 0.7; ACE_caliber = 6.71; ACE_bulletLength = 28.0; ACE_bulletMass = 6.8; ACE_muzzleVelocityVariationSD = 0.12; ACE_dragModel = 7; ACE_ballisticCoefficients[] = {0.212}; ACE_velocityBoundaries[] = {}; ACE_standardAtmosphere = "ICAO"; ACE_muzzleVelocities[] = {925, 945, 960}; ACE_barrelLengths[] = {406, 508, 610}; };
    class FA_b_ammo_65cm_XM893: B_65x39_Caseless { displayName = "XM893 CTEP"; caliber = 3.2; hit = 12; typicalSpeed = 980; airFriction = -0.00092; deflecting = 13; tracerScale = 0.7; ACE_caliber = 6.71; ACE_bulletLength = 28.6; ACE_bulletMass = 6.9; ACE_muzzleVelocityVariationSD = 0.12; ACE_dragModel = 7; ACE_ballisticCoefficients[] = {0.219}; ACE_velocityBoundaries[] = {}; ACE_standardAtmosphere = "ICAO"; ACE_muzzleVelocities[] = {945, 965, 980}; ACE_barrelLengths[] = {406, 508, 610}; };
// 6.5 tracer ammo variants for the 4 caseless rifle loads (generated)
    class FA_b_ammo_65g_Mk328_T_Red: FA_b_ammo_65g_Mk328 { tracer=1; tracerColor[]={1,0,0,1}; };
    class FA_b_ammo_65g_Mk328_T_Yellow: FA_b_ammo_65g_Mk328 { tracer=1; tracerColor[]={1,1,0,1}; };
    class FA_b_ammo_65g_Mk328_T_Green: FA_b_ammo_65g_Mk328 { tracer=1; tracerColor[]={0,1,0,1}; };
    class FA_b_ammo_65g_Mk328_T_White: FA_b_ammo_65g_Mk328 { tracer=1; tracerColor[]={1,1,1,1}; };
    class FA_b_ammo_65g_Mk328_T_Blue: FA_b_ammo_65g_Mk328 { tracer=1; tracerColor[]={0,0.3,1,1}; };
    class FA_b_ammo_65g_Mk328_T_Orange: FA_b_ammo_65g_Mk328 { tracer=1; tracerColor[]={1,0.4,0,1}; };
    class FA_b_ammo_65g_Mk328_T_IR: FA_b_ammo_65g_Mk328 { tracer=1; nvgOnly=1; tracerColor[]={0.2,1,0.2,1}; };
    class FA_b_ammo_65g_XM892_T_Red: FA_b_ammo_65g_XM892 { tracer=1; tracerColor[]={1,0,0,1}; };
    class FA_b_ammo_65g_XM892_T_Yellow: FA_b_ammo_65g_XM892 { tracer=1; tracerColor[]={1,1,0,1}; };
    class FA_b_ammo_65g_XM892_T_Green: FA_b_ammo_65g_XM892 { tracer=1; tracerColor[]={0,1,0,1}; };
    class FA_b_ammo_65g_XM892_T_White: FA_b_ammo_65g_XM892 { tracer=1; tracerColor[]={1,1,1,1}; };
    class FA_b_ammo_65g_XM892_T_Blue: FA_b_ammo_65g_XM892 { tracer=1; tracerColor[]={0,0.3,1,1}; };
    class FA_b_ammo_65g_XM892_T_Orange: FA_b_ammo_65g_XM892 { tracer=1; tracerColor[]={1,0.4,0,1}; };
    class FA_b_ammo_65g_XM892_T_IR: FA_b_ammo_65g_XM892 { tracer=1; nvgOnly=1; tracerColor[]={0.2,1,0.2,1}; };
    class FA_b_ammo_65cm_Mk329_T_Red: FA_b_ammo_65cm_Mk329 { tracer=1; tracerColor[]={1,0,0,1}; };
    class FA_b_ammo_65cm_Mk329_T_Yellow: FA_b_ammo_65cm_Mk329 { tracer=1; tracerColor[]={1,1,0,1}; };
    class FA_b_ammo_65cm_Mk329_T_Green: FA_b_ammo_65cm_Mk329 { tracer=1; tracerColor[]={0,1,0,1}; };
    class FA_b_ammo_65cm_Mk329_T_White: FA_b_ammo_65cm_Mk329 { tracer=1; tracerColor[]={1,1,1,1}; };
    class FA_b_ammo_65cm_Mk329_T_Blue: FA_b_ammo_65cm_Mk329 { tracer=1; tracerColor[]={0,0.3,1,1}; };
    class FA_b_ammo_65cm_Mk329_T_Orange: FA_b_ammo_65cm_Mk329 { tracer=1; tracerColor[]={1,0.4,0,1}; };
    class FA_b_ammo_65cm_Mk329_T_IR: FA_b_ammo_65cm_Mk329 { tracer=1; nvgOnly=1; tracerColor[]={0.2,1,0.2,1}; };
    class FA_b_ammo_65cm_XM893_T_Red: FA_b_ammo_65cm_XM893 { tracer=1; tracerColor[]={1,0,0,1}; };
    class FA_b_ammo_65cm_XM893_T_Yellow: FA_b_ammo_65cm_XM893 { tracer=1; tracerColor[]={1,1,0,1}; };
    class FA_b_ammo_65cm_XM893_T_Green: FA_b_ammo_65cm_XM893 { tracer=1; tracerColor[]={0,1,0,1}; };
    class FA_b_ammo_65cm_XM893_T_White: FA_b_ammo_65cm_XM893 { tracer=1; tracerColor[]={1,1,1,1}; };
    class FA_b_ammo_65cm_XM893_T_Blue: FA_b_ammo_65cm_XM893 { tracer=1; tracerColor[]={0,0.3,1,1}; };
    class FA_b_ammo_65cm_XM893_T_Orange: FA_b_ammo_65cm_XM893 { tracer=1; tracerColor[]={1,0.4,0,1}; };
    class FA_b_ammo_65cm_XM893_T_IR: FA_b_ammo_65cm_XM893 { tracer=1; nvgOnly=1; tracerColor[]={0.2,1,0.2,1}; };

    // =========================================================
    // 7.62x39mm (AK family — AK-12, RPK-12)
    // =========================================================

    // 7N43 "Kremen" (~2034) — hybrid case, tungsten core, ~70 kpsi
    class FA_o_762x39_7N43: B_762x39_Ball_F {
        displayName = "7.62x39 7N43 Kremen";
        hit = 12;
        caliber = 2.8;
        typicalSpeed = 820;
        airFriction = -0.00130;
        deflecting = 16;
        tracerScale = 0.7;
        ACE_caliber = 7.9;
        ACE_bulletLength = 25.91;
        ACE_bulletMass = 7.52;
        ACE_ballisticCoefficients[] = {0.150};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {750, 795, 820};
        ACE_barrelLengths[] = {255, 415, 590};
    };
    class FA_o_762x39_7N43_T_Red: FA_o_762x39_7N43 { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_o_762x39_7N43_T_Yellow: FA_o_762x39_7N43 { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_o_762x39_7N43_T_Green: FA_o_762x39_7N43 { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_o_762x39_7N43_T_White: FA_o_762x39_7N43 { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_o_762x39_7N43_T_Blue: FA_o_762x39_7N43 { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_o_762x39_7N43_T_Orange: FA_o_762x39_7N43 { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_o_762x39_7N43_T_IR: FA_o_762x39_7N43 { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // 7N47 "Kremen-2" (~2040) — cased-telescoped, 2-stage tungsten, ~75 kpsi
    class FA_o_762x39_7N47_CT: B_762x39_Ball_F {
        displayName = "7.62x39 7N47 Kremen-2 CT";
        hit = 12;
        caliber = 3.2;
        typicalSpeed = 840;
        airFriction = -0.00120;
        deflecting = 15;
        tracerScale = 0.7;
        ACE_caliber = 7.9;
        ACE_bulletLength = 26.92;
        ACE_bulletMass = 7.65;
        ACE_ballisticCoefficients[] = {0.165};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {775, 820, 845};
        ACE_barrelLengths[] = {255, 415, 590};
    };
    class FA_o_762x39_7N47_CT_T_Red: FA_o_762x39_7N47_CT { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_o_762x39_7N47_CT_T_Yellow: FA_o_762x39_7N47_CT { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_o_762x39_7N47_CT_T_Green: FA_o_762x39_7N47_CT { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_o_762x39_7N47_CT_T_White: FA_o_762x39_7N47_CT { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_o_762x39_7N47_CT_T_Blue: FA_o_762x39_7N47_CT { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_o_762x39_7N47_CT_T_Orange: FA_o_762x39_7N47_CT { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_o_762x39_7N47_CT_T_IR: FA_o_762x39_7N47_CT { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // 7U4 "Tishina-2" — subsonic tungsten AP, velocity-capped
    class FA_o_762x39_7U4_Sub: B_762x39_Ball_F {
        displayName = "7.62x39 7U4 Tishina-2 SubAP";
        hit = 11;
        caliber = 2.0;
        typicalSpeed = 300;
        airFriction = -0.00060;
        deflecting = 13;
        tracerScale = 0.5;
        ACE_caliber = 7.9;
        ACE_bulletLength = 34.04;
        ACE_bulletMass = 13.61;
        ACE_ballisticCoefficients[] = {0.180};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {290, 298, 302};
        ACE_barrelLengths[] = {255, 415, 590};
    };
    class FA_o_762x39_7U4_Sub_T_Red: FA_o_762x39_7U4_Sub { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_o_762x39_7U4_Sub_T_Yellow: FA_o_762x39_7U4_Sub { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_o_762x39_7U4_Sub_T_Green: FA_o_762x39_7U4_Sub { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_o_762x39_7U4_Sub_T_White: FA_o_762x39_7U4_Sub { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_o_762x39_7U4_Sub_T_Blue: FA_o_762x39_7U4_Sub { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_o_762x39_7U4_Sub_T_Orange: FA_o_762x39_7U4_Sub { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_o_762x39_7U4_Sub_T_IR: FA_o_762x39_7U4_Sub { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // 5.45x39mm (AK-74 / AK-12 family) — GRAU-designated next-gen
    // Not vanilla — inherits B_762x39_Ball_F as a structural placeholder;
    // ACE ballistics drive the real 5.45 behaviour.
    // =========================================================
    // 7N44 "Osa" — hybrid case, tungsten core, high-pressure
    class FA_o_545x39_7N44_HP: B_762x39_Ball_F {
        hit = 10;
        caliber = 2.3;
        typicalSpeed = 925;
        airFriction = -0.00125;
        deflecting = 17;
        tracerScale = 0.8;
        ACE_caliber = 5.6;
        ACE_bulletLength = 25.4;
        ACE_bulletMass = 3.63;
        ACE_ballisticCoefficients[] = {0.130};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {850, 905, 925};
        ACE_barrelLengths[]    = {206, 415, 590};
    };
    class FA_o_545x39_7N44_HP_T_Red:    FA_o_545x39_7N44_HP { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_o_545x39_7N44_HP_T_Yellow: FA_o_545x39_7N44_HP { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_o_545x39_7N44_HP_T_Green:  FA_o_545x39_7N44_HP { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_o_545x39_7N44_HP_T_White:  FA_o_545x39_7N44_HP { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_o_545x39_7N44_HP_T_Blue:   FA_o_545x39_7N44_HP { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_o_545x39_7N44_HP_T_Orange: FA_o_545x39_7N44_HP { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_o_545x39_7N44_HP_T_IR:     FA_o_545x39_7N44_HP { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // 7N48 "Osa-2" — cased-telescoped, 2-stage tungsten
    class FA_o_545x39_7N48_CT: B_762x39_Ball_F {
        hit = 10;
        caliber = 2.6;
        typicalSpeed = 950;
        airFriction = -0.00118;
        deflecting = 16;
        tracerScale = 0.8;
        ACE_caliber = 5.6;
        ACE_bulletLength = 26.42;
        ACE_bulletMass = 3.69;
        ACE_ballisticCoefficients[] = {0.150};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {875, 930, 950};
        ACE_barrelLengths[]    = {206, 415, 590};
    };
    class FA_o_545x39_7N48_CT_T_Red:    FA_o_545x39_7N48_CT { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_o_545x39_7N48_CT_T_Yellow: FA_o_545x39_7N48_CT { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_o_545x39_7N48_CT_T_Green:  FA_o_545x39_7N48_CT { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_o_545x39_7N48_CT_T_White:  FA_o_545x39_7N48_CT { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_o_545x39_7N48_CT_T_Blue:   FA_o_545x39_7N48_CT { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_o_545x39_7N48_CT_T_Orange: FA_o_545x39_7N48_CT { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_o_545x39_7N48_CT_T_IR:     FA_o_545x39_7N48_CT { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // 7U5 "Tishina-5" — subsonic tungsten (suppressed, niche)
    class FA_o_545x39_7U5_SubAP: B_762x39_Ball_F {
        hit = 8;
        caliber = 1.6;
        typicalSpeed = 303;
        airFriction = -0.00075;
        deflecting = 14;
        tracerScale = 0.8;
        ACE_caliber = 5.6;
        ACE_bulletLength = 33.02;
        ACE_bulletMass = 5.51;
        ACE_ballisticCoefficients[] = {0.120};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {295, 300, 303};
        ACE_barrelLengths[]    = {206, 415, 590};
    };
    class FA_o_545x39_7U5_SubAP_T_Red:    FA_o_545x39_7U5_SubAP { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_o_545x39_7U5_SubAP_T_Yellow: FA_o_545x39_7U5_SubAP { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_o_545x39_7U5_SubAP_T_Green:  FA_o_545x39_7U5_SubAP { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_o_545x39_7U5_SubAP_T_White:  FA_o_545x39_7U5_SubAP { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_o_545x39_7U5_SubAP_T_Blue:   FA_o_545x39_7U5_SubAP { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_o_545x39_7U5_SubAP_T_Orange: FA_o_545x39_7U5_SubAP { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_o_545x39_7U5_SubAP_T_IR:     FA_o_545x39_7U5_SubAP { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // 9.3x64 "Type 40" — CSAT precision marksman, hybrid case + tungsten
    // =========================================================
    class FA_o_93x64_Type40: B_93x64_Ball {
        hit = 26;
        caliber = 3.8;
        typicalSpeed = 882;
        airFriction = -0.00075;
        deflecting = 8;
        tracerScale = 0.7;
        ACE_caliber = 9.27;
        ACE_bulletLength = 38.1;
        ACE_bulletMass = 17.5;
        ACE_ballisticCoefficients[] = {0.300};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {850, 872, 882};
        ACE_barrelLengths[]    = {508, 609.6, 660.4};
    };
    class FA_o_93x64_Type40_T_Red:    FA_o_93x64_Type40 { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_o_93x64_Type40_T_Yellow: FA_o_93x64_Type40 { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_o_93x64_Type40_T_Green:  FA_o_93x64_Type40 { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_o_93x64_Type40_T_White:  FA_o_93x64_Type40 { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_o_93x64_Type40_T_Blue:   FA_o_93x64_Type40 { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_o_93x64_Type40_T_Orange: FA_o_93x64_Type40 { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_o_93x64_Type40_T_IR:     FA_o_93x64_Type40 { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // .408 CheyTac "Mk240 LRP" — extreme-range precision, hybrid + tungsten
    // =========================================================
    class FA_b_408_Mk240: B_338_LM_Ball {
        hit = 30;
        caliber = 4.2;
        typicalSpeed = 965;
        airFriction = -0.00050;
        deflecting = 7;
        tracerScale = 0.7;
        ACE_caliber = 10.36;
        ACE_bulletLength = 50.04;
        ACE_bulletMass = 22.03;
        ACE_ballisticCoefficients[] = {0.420};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {930, 955, 965};
        ACE_barrelLengths[]    = {660.4, 711.2, 762};
    };
    class FA_b_408_Mk240_T_Red:    FA_b_408_Mk240 { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_408_Mk240_T_Yellow: FA_b_408_Mk240 { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_408_Mk240_T_Green:  FA_b_408_Mk240 { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_408_Mk240_T_White:  FA_b_408_Mk240 { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_408_Mk240_T_Blue:   FA_b_408_Mk240 { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_408_Mk240_T_Orange: FA_b_408_Mk240 { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_408_Mk240_T_IR:     FA_b_408_Mk240 { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // .408 CheyTac "Mk241 ELR" — heavy high-BC extreme long range
    // =========================================================
    class FA_b_408_Mk241_ELR: B_338_LM_Ball {
        hit = 32;
        caliber = 4.0;
        typicalSpeed = 905;
        airFriction = -0.00044;
        deflecting = 7;
        tracerScale = 0.7;
        ACE_caliber = 10.36;
        ACE_bulletLength = 53.34;
        ACE_bulletMass = 27.15;
        ACE_ballisticCoefficients[] = {0.460};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {870, 895, 905};
        ACE_barrelLengths[]    = {660.4, 711.2, 762};
    };
    class FA_b_408_Mk241_ELR_T_Red:    FA_b_408_Mk241_ELR { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_408_Mk241_ELR_T_Yellow: FA_b_408_Mk241_ELR { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_408_Mk241_ELR_T_Green:  FA_b_408_Mk241_ELR { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_408_Mk241_ELR_T_White:  FA_b_408_Mk241_ELR { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_408_Mk241_ELR_T_Blue:   FA_b_408_Mk241_ELR { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_408_Mk241_ELR_T_Orange: FA_b_408_Mk241_ELR { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_408_Mk241_ELR_T_IR:     FA_b_408_Mk241_ELR { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // .408 CheyTac "Mk242 HV" — light, fast, flat-shooting
    // =========================================================
    class FA_b_408_Mk242_HV: B_338_LM_Ball {
        hit = 28;
        caliber = 3.8;
        typicalSpeed = 1015;
        airFriction = -0.00060;
        deflecting = 7;
        tracerScale = 0.7;
        ACE_caliber = 10.36;
        ACE_bulletLength = 45.21;
        ACE_bulletMass = 19.76;
        ACE_ballisticCoefficients[] = {0.350};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {975, 1005, 1015};
        ACE_barrelLengths[]    = {660.4, 711.2, 762};
    };
    class FA_b_408_Mk242_HV_T_Red:    FA_b_408_Mk242_HV { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_408_Mk242_HV_T_Yellow: FA_b_408_Mk242_HV { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_408_Mk242_HV_T_Green:  FA_b_408_Mk242_HV { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_408_Mk242_HV_T_White:  FA_b_408_Mk242_HV { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_408_Mk242_HV_T_Blue:   FA_b_408_Mk242_HV { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_408_Mk242_HV_T_Orange: FA_b_408_Mk242_HV { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_408_Mk242_HV_T_IR:     FA_b_408_Mk242_HV { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // .408 CheyTac "Mk243 AP" — tungsten penetrator, anti-materiel
    // =========================================================
    class FA_b_408_Mk243_AP: B_338_LM_Ball {
        hit = 30;
        caliber = 6.0;
        typicalSpeed = 980;
        airFriction = -0.00052;
        deflecting = 6;
        tracerScale = 0.7;
        ACE_caliber = 10.36;
        ACE_bulletLength = 48.26;
        ACE_bulletMass = 20.99;
        ACE_ballisticCoefficients[] = {0.400};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {945, 970, 980};
        ACE_barrelLengths[]    = {660.4, 711.2, 762};
    };
    class FA_b_408_Mk243_AP_T_Red:    FA_b_408_Mk243_AP { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_408_Mk243_AP_T_Yellow: FA_b_408_Mk243_AP { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_408_Mk243_AP_T_Green:  FA_b_408_Mk243_AP { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_408_Mk243_AP_T_White:  FA_b_408_Mk243_AP { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_408_Mk243_AP_T_Blue:   FA_b_408_Mk243_AP { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_408_Mk243_AP_T_Orange: FA_b_408_Mk243_AP { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_408_Mk243_AP_T_IR:     FA_b_408_Mk243_AP { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // 12.7x108 "Mk250 LRP" — .50 precision / match
    // =========================================================
    class FA_b_127x108_Mk250: B_127x108_Ball {
        hit = 42;
        caliber = 5.5;
        typicalSpeed = 870;
        airFriction = -0.00045;
        deflecting = 6;
        tracerScale = 0.8;
        ACE_caliber = 12.95;
        ACE_bulletLength = 57.91;
        ACE_bulletMass = 47.95;
        ACE_ballisticCoefficients[] = {0.370};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {840, 860, 870};
        ACE_barrelLengths[]    = {660.4, 711.2, 737};
    };
    class FA_b_127x108_Mk250_T_Red:    FA_b_127x108_Mk250 { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_127x108_Mk250_T_Yellow: FA_b_127x108_Mk250 { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_127x108_Mk250_T_Green:  FA_b_127x108_Mk250 { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_127x108_Mk250_T_White:  FA_b_127x108_Mk250 { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_127x108_Mk250_T_Blue:   FA_b_127x108_Mk250 { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_127x108_Mk250_T_Orange: FA_b_127x108_Mk250 { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_127x108_Mk250_T_IR:     FA_b_127x108_Mk250 { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // 12.7x108 "Mk211 Mod 2" — .50 HEIAP anti-materiel
    // =========================================================
    class FA_b_127x108_Mk211Mod2: B_127x108_Ball {
        hit = 48;
        caliber = 8.0;
        typicalSpeed = 900;
        airFriction = -0.00040;
        deflecting = 5;
        tracerScale = 0.8;
        ACE_caliber = 12.95;
        ACE_bulletLength = 59.94;
        ACE_bulletMass = 44.06;
        ACE_ballisticCoefficients[] = {0.330};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {870, 890, 900};
        ACE_barrelLengths[]    = {660.4, 711.2, 737};
    };
    class FA_b_127x108_Mk211Mod2_T_Red:    FA_b_127x108_Mk211Mod2 { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_127x108_Mk211Mod2_T_Yellow: FA_b_127x108_Mk211Mod2 { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_127x108_Mk211Mod2_T_Green:  FA_b_127x108_Mk211Mod2 { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_127x108_Mk211Mod2_T_White:  FA_b_127x108_Mk211Mod2 { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_127x108_Mk211Mod2_T_Blue:   FA_b_127x108_Mk211Mod2 { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_127x108_Mk211Mod2_T_Orange: FA_b_127x108_Mk211Mod2 { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_127x108_Mk211Mod2_T_IR:     FA_b_127x108_Mk211Mod2 { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // 12.7x99 (.50 BMG) "Mk258 LRP" — precision / match (AS50)
    // =========================================================
    class FA_b_127x99_Mk258_LRP: B_127x99_Ball {
        hit = 42;
        caliber = 5.5;
        typicalSpeed = 860;
        airFriction = -0.00044;
        deflecting = 6;
        tracerScale = 0.8;
        ACE_caliber = 12.95;
        ACE_bulletLength = 58.42;
        ACE_bulletMass = 48.6;
        ACE_ballisticCoefficients[] = {0.380};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {820, 850, 860};
        ACE_barrelLengths[]    = {736.6, 736.6, 736.6};
    };
    class FA_b_127x99_Mk258_LRP_T_Red:    FA_b_127x99_Mk258_LRP { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_127x99_Mk258_LRP_T_Yellow: FA_b_127x99_Mk258_LRP { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_127x99_Mk258_LRP_T_Green:  FA_b_127x99_Mk258_LRP { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_127x99_Mk258_LRP_T_White:  FA_b_127x99_Mk258_LRP { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_127x99_Mk258_LRP_T_Blue:   FA_b_127x99_Mk258_LRP { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_127x99_Mk258_LRP_T_Orange: FA_b_127x99_Mk258_LRP { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_127x99_Mk258_LRP_T_IR:     FA_b_127x99_Mk258_LRP { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // 12.7x99 (.50 BMG) "Mk211 Mod 0" — Raufoss HEIAP anti-materiel (AS50)
    // =========================================================
    class FA_b_127x99_Mk211Mod0_AP: B_127x99_Ball {
        hit = 48;
        caliber = 8.0;
        typicalSpeed = 890;
        airFriction = -0.00040;
        deflecting = 5;
        tracerScale = 0.8;
        ACE_caliber = 12.95;
        ACE_bulletLength = 58.67;
        ACE_bulletMass = 43.48;
        ACE_ballisticCoefficients[] = {0.330};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {850, 880, 890};
        ACE_barrelLengths[]    = {736.6, 736.6, 736.6};
    };
    class FA_b_127x99_Mk211Mod0_AP_T_Red:    FA_b_127x99_Mk211Mod0_AP { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_127x99_Mk211Mod0_AP_T_Yellow: FA_b_127x99_Mk211Mod0_AP { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_127x99_Mk211Mod0_AP_T_Green:  FA_b_127x99_Mk211Mod0_AP { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_127x99_Mk211Mod0_AP_T_White:  FA_b_127x99_Mk211Mod0_AP { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_127x99_Mk211Mod0_AP_T_Blue:   FA_b_127x99_Mk211Mod0_AP { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_127x99_Mk211Mod0_AP_T_Orange: FA_b_127x99_Mk211Mod0_AP { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_127x99_Mk211Mod0_AP_T_IR:     FA_b_127x99_Mk211Mod0_AP { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // .45 ACP "Mk421 SUB-AP" — subsonic tungsten-core AP, CQB suppressed
    // =========================================================
    class FA_b_45ACP_Mk421_SubAP: B_45ACP_Ball {
        hit = 12;
        caliber = 1.4;
        typicalSpeed = 290;
        airFriction = -0.00090;
        deflecting = 22;
        tracerScale = 0.5;
        ACE_caliber = 11.48;
        ACE_bulletLength = 17.3;
        ACE_bulletMass = 15.03;
        ACE_ballisticCoefficients[] = {0.195};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 1;
        ACE_muzzleVelocities[] = {255, 280, 290};
        ACE_barrelLengths[]    = {127, 200, 254};
    };
    class FA_b_45ACP_Mk421_SubAP_T_Red:    FA_b_45ACP_Mk421_SubAP { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_b_45ACP_Mk421_SubAP_T_Yellow: FA_b_45ACP_Mk421_SubAP { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_b_45ACP_Mk421_SubAP_T_Green:  FA_b_45ACP_Mk421_SubAP { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_b_45ACP_Mk421_SubAP_T_White:  FA_b_45ACP_Mk421_SubAP { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_b_45ACP_Mk421_SubAP_T_Blue:   FA_b_45ACP_Mk421_SubAP { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_b_45ACP_Mk421_SubAP_T_Orange: FA_b_45ACP_Mk421_SubAP { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_b_45ACP_Mk421_SubAP_T_IR:     FA_b_45ACP_Mk421_SubAP { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // 12 Gauge — LOT M1014 shotgun ammunition (Mk35x / Mk360 / Mk363)
    // Magazines and magwells for these live in the lot addon.
    // =========================================================

    // ---- Mk350 TBS — Tungsten Buckshot ----
    // Denser, harder pellets: more penetration and less velocity
    // bleed than lead — effective to ~50 m vs. soft targets.
    class FA_b_12G_Mk350_TBS_Sub: B_12Gauge_Pellets_Submunition {
        hit = 8;
        caliber = 1.0;
        airFriction = -0.0120;
        typicalSpeed = 400;
    };
    class FA_b_12G_Mk350_TBS: B_12Gauge_Pellets_Submunition_Cartridge {
        displayName = "12g Mk350 Tungsten Buckshot";
        submunitionAmmo = "FA_b_12G_Mk350_TBS_Sub";
        submunitionConeAngle = 3.0;
        ACE_barrelLengths[] = {470, 508};
        ACE_muzzleVelocities[] = {392, 400};
    };

    // ---- Mk351 FLE — Tungsten Flechette ----
    // Fin-stabilised darts: tight pattern, low drag, high
    // penetration. Effective to ~80 m; passes light cover.
    class FA_b_12G_Mk351_FLE_Sub: B_12Gauge_Pellets_Submunition {
        hit = 5;
        caliber = 1.6;
        airFriction = -0.0060;
        typicalSpeed = 450;
    };
    class FA_b_12G_Mk351_FLE: B_12Gauge_Pellets_Submunition_Cartridge {
        displayName = "12g Mk351 Tungsten Flechette";
        submunitionAmmo = "FA_b_12G_Mk351_FLE_Sub";
        submunitionConeAngle = 1.3;
        ACE_barrelLengths[] = {470, 508};
        ACE_muzzleVelocities[] = {442, 450};
    };

    // ---- Mk352 APS — Tungsten AP Slug ----
    // Single heavy projectile; tungsten core for light-armor /
    // hard-cover defeat at close range.
    class FA_b_12G_Mk352_APS: B_12Gauge_Slug {
        displayName = "12g Mk352 Tungsten AP Slug";
        hit = 30;
        caliber = 2.2;
        airFriction = -0.0050;
        typicalSpeed = 450;
        ACE_barrelLengths[] = {470, 508};
        ACE_muzzleVelocities[] = {440, 450};
    };

    // ---- Mk353 BRC — Frangible Breaching Round ----
    // Defeats a lock or hinge up close then sheds energy fast:
    // near-zero over-penetration. Door breach is handled by
    // FA_ammo_fnc_breach (gated by CBA setting).
    class FA_b_12G_Mk353_BRC: B_12Gauge_Slug {
        displayName = "12g Mk353 Frangible Breaching";
        hit = 35;
        caliber = 0.15;
        airFriction = -0.0800;
        typicalSpeed = 320;
        deflecting = 4;
        ACE_barrelLengths[] = {470, 508};
        ACE_muzzleVelocities[] = {312, 320};
    };

    // ---- Mk360 AD — Anti-Drone Shot ----
    // Dense tungsten pattern tuned for FPV/quad intercept at
    // close range (~40-50 m). Config-only; no script needed.
    class FA_b_12G_Mk360_AD_Sub: B_12Gauge_Pellets_Submunition {
        hit = 6;
        caliber = 0.9;
        airFriction = -0.0110;
        typicalSpeed = 410;
    };
    class FA_b_12G_Mk360_AD: B_12Gauge_Pellets_Submunition_Cartridge {
        displayName = "12g Mk360 Anti-Drone Shot";
        submunitionAmmo = "FA_b_12G_Mk360_AD_Sub";
        submunitionConeAngle = 2.2;
        ACE_barrelLengths[] = {470, 508};
        ACE_muzzleVelocities[] = {402, 410};
    };

    // ---- Mk363 PABS — Proximity Airburst Slug (script-driven) ----
    // Flies as a slug; proximity script detonates it near a UAV
    // for anti-drone reach the shot pattern can't achieve.
    // Registered in the antidrone AD_params table (jmfsbfa_antidrone,
    // fnc_initAntiDrone) so the fired EH installs proximity tracking.
    // ACE frag: fabricated sleeve, no real charge — the detonation is
    // scripted (fnc_detonateAD). Sized as the slug's share of the 40mm HE
    // warhead: 12.22% of 40mm mass (right.json percent_of_40mm_mass) ->
    // metal 200 g x12.22% = 24.4 g, charge 32 g x12.22% = 3.9 g.
    class FA_b_12G_Mk363_PABS: B_12Gauge_Slug {
        displayName = "12g Mk363 Proximity Airburst";
        hit = 4;
        caliber = 0.8;
        airFriction = -0.0050;
        typicalSpeed = 430;
        airLock = 1;
        indirectHitRange = 1.6;
        ace_frag_metal = 24.4;
        ace_frag_charge = 3.9;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = 0.5;
        ace_frag_classes[] = {"ace_frag_tiny_HD", "ace_frag_small_HD"};
        ACE_barrelLengths[] = {470, 508};
        ACE_muzzleVelocities[] = {420, 430};
    };

    // =========================================================
    // Mk389 TBK — 40mm Tungsten Buckshot (UGL anti-personnel)
    // 18 low-drag tungsten pellets fired flat at high velocity.
    // Tight 1.5 deg cone keeps the pattern lethal out to ~100 m,
    // far past a conventional 40mm buckshot (~30-40 m).
    // Pellets/magazines/magwells all live in the ammo addon.
    // =========================================================
    class FA_b_40mm_Mk389_TBK_Sub: B_12Gauge_Pellets_Submunition {
        hit = 11;
        caliber = 1.3;
        airFriction = -0.0045;   // low drag: holds energy to 100 m
        typicalSpeed = 180;
    };
    class FA_b_40mm_Mk389_TBK: B_12Gauge_Pellets_Submunition_Cartridge {
        displayName = "40mm Mk389 Tungsten Buckshot";
        triggerTime = 0;
        submunitionAmmo = "FA_b_40mm_Mk389_TBK_Sub";
        submunitionConeAngle = 1.5;                       // ~2.6 m pattern radius at 100 m
        submunitionConeType[] = {"poissondisccenter", 18}; // 18 pellets
        typicalSpeed = 180;
    };

    // =========================================================
    // FACTION BASE AMMO — AAF (AF-*, ~95%% of West), CSAT 6.5 (Type 4x, ~90%%),
    // 5.8x42 trio completion (DBP-39 CT / DBP-40 AP)
    // =========================================================
    class FA_i_556_AF556_HV: B_556x45_Ball {
        displayName = "AF-556 HV";
        hit = 9;
        caliber = 2.3;
        typicalSpeed = 910;
        airFriction = -0.00126;
        deflecting = 15;
        tracerScale = 0.6;
        ACE_caliber = 5.69;
        ACE_bulletLength = 23;
        ACE_bulletMass = 4;
        ACE_muzzleVelocityVariationSD = 0.18;
        ACE_ballisticCoefficients[] = {0.151};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {855, 910, 950};
        ACE_barrelLengths[] = {254, 368, 508};
    };
    class FA_i_556_AF556_HV_T_Red: FA_i_556_AF556_HV {
        tracer = 1;
        tracerColor[] = {1.0, 0.0, 0.0, 1.0};
    };
    class FA_i_556_AF556_HV_T_Yellow: FA_i_556_AF556_HV {
        tracer = 1;
        tracerColor[] = {1.0, 1.0, 0.0, 1.0};
    };
    class FA_i_556_AF556_HV_T_Green: FA_i_556_AF556_HV {
        tracer = 1;
        tracerColor[] = {0.0, 1.0, 0.0, 1.0};
    };
    class FA_i_556_AF556_HV_T_White: FA_i_556_AF556_HV {
        tracer = 1;
        tracerColor[] = {1.0, 1.0, 1.0, 1.0};
    };
    class FA_i_556_AF556_HV_T_Blue: FA_i_556_AF556_HV {
        tracer = 1;
        tracerColor[] = {0.0, 0.3, 1.0, 1.0};
    };
    class FA_i_556_AF556_HV_T_Orange: FA_i_556_AF556_HV {
        tracer = 1;
        tracerColor[] = {1.0, 0.4, 0.0, 1.0};
    };
    class FA_i_556_AF556_HV_T_IR: FA_i_556_AF556_HV {
        tracer = 1;
        nvgOnly = 1;
        tracerColor[] = {0.2, 1.0, 0.2, 1.0};
    };
    class FA_i_556_AF556C_CT: B_556x45_Ball {
        displayName = "AF-556C CT";
        hit = 10;
        caliber = 2.5;
        typicalSpeed = 930;
        airFriction = -0.0012;
        deflecting = 14;
        tracerScale = 0.6;
        ACE_caliber = 5.69;
        ACE_bulletLength = 24;
        ACE_bulletMass = 4;
        ACE_muzzleVelocityVariationSD = 0.16;
        ACE_ballisticCoefficients[] = {0.162};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {870, 930, 970};
        ACE_barrelLengths[] = {254, 368, 508};
    };
    class FA_i_556_AF556C_CT_T_Red: FA_i_556_AF556C_CT {
        tracer = 1;
        tracerColor[] = {1.0, 0.0, 0.0, 1.0};
    };
    class FA_i_556_AF556C_CT_T_Yellow: FA_i_556_AF556C_CT {
        tracer = 1;
        tracerColor[] = {1.0, 1.0, 0.0, 1.0};
    };
    class FA_i_556_AF556C_CT_T_Green: FA_i_556_AF556C_CT {
        tracer = 1;
        tracerColor[] = {0.0, 1.0, 0.0, 1.0};
    };
    class FA_i_556_AF556C_CT_T_White: FA_i_556_AF556C_CT {
        tracer = 1;
        tracerColor[] = {1.0, 1.0, 1.0, 1.0};
    };
    class FA_i_556_AF556C_CT_T_Blue: FA_i_556_AF556C_CT {
        tracer = 1;
        tracerColor[] = {0.0, 0.3, 1.0, 1.0};
    };
    class FA_i_556_AF556C_CT_T_Orange: FA_i_556_AF556C_CT {
        tracer = 1;
        tracerColor[] = {1.0, 0.4, 0.0, 1.0};
    };
    class FA_i_556_AF556C_CT_T_IR: FA_i_556_AF556C_CT {
        tracer = 1;
        nvgOnly = 1;
        tracerColor[] = {0.2, 1.0, 0.2, 1.0};
    };
    class FA_i_556_AF556P_AP: B_556x45_Ball {
        displayName = "AF-556P AP";
        hit = 9;
        caliber = 2.85;
        typicalSpeed = 895;
        airFriction = -0.00118;
        deflecting = 12;
        tracerScale = 0.6;
        ACE_caliber = 5.69;
        ACE_bulletLength = 24.5;
        ACE_bulletMass = 4.2;
        ACE_muzzleVelocityVariationSD = 0.15;
        ACE_ballisticCoefficients[] = {0.170};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {835, 895, 930};
        ACE_barrelLengths[] = {254, 368, 508};
    };
    class FA_i_556_AF556P_AP_T_Red: FA_i_556_AF556P_AP {
        tracer = 1;
        tracerColor[] = {1.0, 0.0, 0.0, 1.0};
    };
    class FA_i_556_AF556P_AP_T_Yellow: FA_i_556_AF556P_AP {
        tracer = 1;
        tracerColor[] = {1.0, 1.0, 0.0, 1.0};
    };
    class FA_i_556_AF556P_AP_T_Green: FA_i_556_AF556P_AP {
        tracer = 1;
        tracerColor[] = {0.0, 1.0, 0.0, 1.0};
    };
    class FA_i_556_AF556P_AP_T_White: FA_i_556_AF556P_AP {
        tracer = 1;
        tracerColor[] = {1.0, 1.0, 1.0, 1.0};
    };
    class FA_i_556_AF556P_AP_T_Blue: FA_i_556_AF556P_AP {
        tracer = 1;
        tracerColor[] = {0.0, 0.3, 1.0, 1.0};
    };
    class FA_i_556_AF556P_AP_T_Orange: FA_i_556_AF556P_AP {
        tracer = 1;
        tracerColor[] = {1.0, 0.4, 0.0, 1.0};
    };
    class FA_i_556_AF556P_AP_T_IR: FA_i_556_AF556P_AP {
        tracer = 1;
        nvgOnly = 1;
        tracerColor[] = {0.2, 1.0, 0.2, 1.0};
    };
    class FA_i_762_AF762_HV: B_762x51_Ball {
        displayName = "AF-762 HV";
        hit = 13;
        caliber = 2.85;
        typicalSpeed = 895;
        airFriction = -0.00082;
        deflecting = 15;
        tracerScale = 0.8;
        ACE_caliber = 7.82;
        ACE_bulletLength = 29.21;
        ACE_bulletMass = 8.75;
        ACE_ballisticCoefficients[] = {0.228};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {840, 875, 895, 905};
        ACE_barrelLengths[] = {406, 508, 610, 660};
    };
    class FA_i_762_AF762_HV_T_Red: FA_i_762_AF762_HV {
        tracer = 1;
        tracerColor[] = {1.0, 0.0, 0.0, 1.0};
    };
    class FA_i_762_AF762_HV_T_Yellow: FA_i_762_AF762_HV {
        tracer = 1;
        tracerColor[] = {1.0, 1.0, 0.0, 1.0};
    };
    class FA_i_762_AF762_HV_T_Green: FA_i_762_AF762_HV {
        tracer = 1;
        tracerColor[] = {0.0, 1.0, 0.0, 1.0};
    };
    class FA_i_762_AF762_HV_T_White: FA_i_762_AF762_HV {
        tracer = 1;
        tracerColor[] = {1.0, 1.0, 1.0, 1.0};
    };
    class FA_i_762_AF762_HV_T_Blue: FA_i_762_AF762_HV {
        tracer = 1;
        tracerColor[] = {0.0, 0.3, 1.0, 1.0};
    };
    class FA_i_762_AF762_HV_T_Orange: FA_i_762_AF762_HV {
        tracer = 1;
        tracerColor[] = {1.0, 0.4, 0.0, 1.0};
    };
    class FA_i_762_AF762_HV_T_IR: FA_i_762_AF762_HV {
        tracer = 1;
        nvgOnly = 1;
        tracerColor[] = {0.2, 1.0, 0.2, 1.0};
    };
    class FA_i_762_AF762C_CT: B_762x51_Ball {
        displayName = "AF-762C CT";
        hit = 14;
        caliber = 3.2;
        typicalSpeed = 910;
        airFriction = -0.00078;
        deflecting = 14;
        tracerScale = 0.8;
        ACE_caliber = 7.82;
        ACE_bulletLength = 30.48;
        ACE_bulletMass = 9.07;
        ACE_ballisticCoefficients[] = {0.245};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {860, 900, 910, 925};
        ACE_barrelLengths[] = {406, 508, 610, 660};
    };
    class FA_i_762_AF762C_CT_T_Red: FA_i_762_AF762C_CT {
        tracer = 1;
        tracerColor[] = {1.0, 0.0, 0.0, 1.0};
    };
    class FA_i_762_AF762C_CT_T_Yellow: FA_i_762_AF762C_CT {
        tracer = 1;
        tracerColor[] = {1.0, 1.0, 0.0, 1.0};
    };
    class FA_i_762_AF762C_CT_T_Green: FA_i_762_AF762C_CT {
        tracer = 1;
        tracerColor[] = {0.0, 1.0, 0.0, 1.0};
    };
    class FA_i_762_AF762C_CT_T_White: FA_i_762_AF762C_CT {
        tracer = 1;
        tracerColor[] = {1.0, 1.0, 1.0, 1.0};
    };
    class FA_i_762_AF762C_CT_T_Blue: FA_i_762_AF762C_CT {
        tracer = 1;
        tracerColor[] = {0.0, 0.3, 1.0, 1.0};
    };
    class FA_i_762_AF762C_CT_T_Orange: FA_i_762_AF762C_CT {
        tracer = 1;
        tracerColor[] = {1.0, 0.4, 0.0, 1.0};
    };
    class FA_i_762_AF762C_CT_T_IR: FA_i_762_AF762C_CT {
        tracer = 1;
        nvgOnly = 1;
        tracerColor[] = {0.2, 1.0, 0.2, 1.0};
    };
    class FA_i_762_AF762P_AP: B_762x51_Ball {
        displayName = "AF-762P AP";
        hit = 14;
        caliber = 3.6;
        typicalSpeed = 895;
        airFriction = -0.00078;
        deflecting = 12;
        tracerScale = 0.8;
        ACE_caliber = 7.82;
        ACE_bulletLength = 30.9;
        ACE_bulletMass = 9.5;
        ACE_ballisticCoefficients[] = {0.245};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {850, 885, 895, 910};
        ACE_barrelLengths[] = {406, 508, 610, 660};
    };
    class FA_i_762_AF762P_AP_T_Red: FA_i_762_AF762P_AP {
        tracer = 1;
        tracerColor[] = {1.0, 0.0, 0.0, 1.0};
    };
    class FA_i_762_AF762P_AP_T_Yellow: FA_i_762_AF762P_AP {
        tracer = 1;
        tracerColor[] = {1.0, 1.0, 0.0, 1.0};
    };
    class FA_i_762_AF762P_AP_T_Green: FA_i_762_AF762P_AP {
        tracer = 1;
        tracerColor[] = {0.0, 1.0, 0.0, 1.0};
    };
    class FA_i_762_AF762P_AP_T_White: FA_i_762_AF762P_AP {
        tracer = 1;
        tracerColor[] = {1.0, 1.0, 1.0, 1.0};
    };
    class FA_i_762_AF762P_AP_T_Blue: FA_i_762_AF762P_AP {
        tracer = 1;
        tracerColor[] = {0.0, 0.3, 1.0, 1.0};
    };
    class FA_i_762_AF762P_AP_T_Orange: FA_i_762_AF762P_AP {
        tracer = 1;
        tracerColor[] = {1.0, 0.4, 0.0, 1.0};
    };
    class FA_i_762_AF762P_AP_T_IR: FA_i_762_AF762P_AP {
        tracer = 1;
        nvgOnly = 1;
        tracerColor[] = {0.2, 1.0, 0.2, 1.0};
    };
    // CSAT 6.5 keeps its x0.90 gradient on speed/pen against the rebalanced West
    // peer (Mk330), geometry and BC copied from the parent as before.
    class FA_o_65_Type41_EPR: B_65x39_Caseless {
        displayName = "Type 41 EPR";
        hit = 10;
        caliber = 2.4;
        typicalSpeed = 855;
        airFriction = -0.00104;
        deflecting = 15;
        tracerScale = 0.7;
        ACE_caliber = 6.71;
        ACE_bulletLength = 26.1;
        ACE_bulletMass = 6.4;
        ACE_muzzleVelocityVariationSD = 0.16;
        ACE_ballisticCoefficients[] = {0.190};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {820, 855, 887};
        ACE_barrelLengths[] = {330, 407, 508};
    };
    class FA_o_65_Type41_EPR_T_Red: FA_o_65_Type41_EPR {
        tracer = 1;
        tracerColor[] = {1.0, 0.0, 0.0, 1.0};
    };
    class FA_o_65_Type41_EPR_T_Yellow: FA_o_65_Type41_EPR {
        tracer = 1;
        tracerColor[] = {1.0, 1.0, 0.0, 1.0};
    };
    class FA_o_65_Type41_EPR_T_Green: FA_o_65_Type41_EPR {
        tracer = 1;
        tracerColor[] = {0.0, 1.0, 0.0, 1.0};
    };
    class FA_o_65_Type41_EPR_T_White: FA_o_65_Type41_EPR {
        tracer = 1;
        tracerColor[] = {1.0, 1.0, 1.0, 1.0};
    };
    class FA_o_65_Type41_EPR_T_Blue: FA_o_65_Type41_EPR {
        tracer = 1;
        tracerColor[] = {0.0, 0.3, 1.0, 1.0};
    };
    class FA_o_65_Type41_EPR_T_Orange: FA_o_65_Type41_EPR {
        tracer = 1;
        tracerColor[] = {1.0, 0.4, 0.0, 1.0};
    };
    class FA_o_65_Type41_EPR_T_IR: FA_o_65_Type41_EPR {
        tracer = 1;
        nvgOnly = 1;
        tracerColor[] = {0.2, 1.0, 0.2, 1.0};
    };
    class FA_o_65_Type42_CT: B_65x39_Caseless {
        displayName = "Type 42 CT";
        hit = 11;
        caliber = 2.7;
        typicalSpeed = 873;
        airFriction = -0.00099;
        deflecting = 14;
        tracerScale = 0.7;
        ACE_caliber = 6.71;
        ACE_bulletLength = 27.2;
        ACE_bulletMass = 6.5;
        ACE_muzzleVelocityVariationSD = 0.14;
        ACE_ballisticCoefficients[] = {0.204};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {837, 873, 905};
        ACE_barrelLengths[] = {330, 407, 508};
    };
    class FA_o_65_Type42_CT_T_Red: FA_o_65_Type42_CT {
        tracer = 1;
        tracerColor[] = {1.0, 0.0, 0.0, 1.0};
    };
    class FA_o_65_Type42_CT_T_Yellow: FA_o_65_Type42_CT {
        tracer = 1;
        tracerColor[] = {1.0, 1.0, 0.0, 1.0};
    };
    class FA_o_65_Type42_CT_T_Green: FA_o_65_Type42_CT {
        tracer = 1;
        tracerColor[] = {0.0, 1.0, 0.0, 1.0};
    };
    class FA_o_65_Type42_CT_T_White: FA_o_65_Type42_CT {
        tracer = 1;
        tracerColor[] = {1.0, 1.0, 1.0, 1.0};
    };
    class FA_o_65_Type42_CT_T_Blue: FA_o_65_Type42_CT {
        tracer = 1;
        tracerColor[] = {0.0, 0.3, 1.0, 1.0};
    };
    class FA_o_65_Type42_CT_T_Orange: FA_o_65_Type42_CT {
        tracer = 1;
        tracerColor[] = {1.0, 0.4, 0.0, 1.0};
    };
    class FA_o_65_Type42_CT_T_IR: FA_o_65_Type42_CT {
        tracer = 1;
        nvgOnly = 1;
        tracerColor[] = {0.2, 1.0, 0.2, 1.0};
    };
    class FA_o_65_Type43_AP: B_65x39_Caseless {
        displayName = "Type 43 AP";
        hit = 10;
        caliber = 3.0;
        typicalSpeed = 851;
        airFriction = -0.00100;
        deflecting = 12;
        tracerScale = 0.7;
        ACE_caliber = 6.71;
        ACE_bulletLength = 27.0;
        ACE_bulletMass = 6.6;
        ACE_muzzleVelocityVariationSD = 0.14;
        ACE_ballisticCoefficients[] = {0.201};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {815, 851, 882};
        ACE_barrelLengths[] = {330, 407, 508};
    };
    class FA_o_65_Type43_AP_T_Red: FA_o_65_Type43_AP {
        tracer = 1;
        tracerColor[] = {1.0, 0.0, 0.0, 1.0};
    };
    class FA_o_65_Type43_AP_T_Yellow: FA_o_65_Type43_AP {
        tracer = 1;
        tracerColor[] = {1.0, 1.0, 0.0, 1.0};
    };
    class FA_o_65_Type43_AP_T_Green: FA_o_65_Type43_AP {
        tracer = 1;
        tracerColor[] = {0.0, 1.0, 0.0, 1.0};
    };
    class FA_o_65_Type43_AP_T_White: FA_o_65_Type43_AP {
        tracer = 1;
        tracerColor[] = {1.0, 1.0, 1.0, 1.0};
    };
    class FA_o_65_Type43_AP_T_Blue: FA_o_65_Type43_AP {
        tracer = 1;
        tracerColor[] = {0.0, 0.3, 1.0, 1.0};
    };
    class FA_o_65_Type43_AP_T_Orange: FA_o_65_Type43_AP {
        tracer = 1;
        tracerColor[] = {1.0, 0.4, 0.0, 1.0};
    };
    class FA_o_65_Type43_AP_T_IR: FA_o_65_Type43_AP {
        tracer = 1;
        nvgOnly = 1;
        tracerColor[] = {0.2, 1.0, 0.2, 1.0};
    };
    class FA_o_580_DBP39_CT: B_556x45_Ball {
        displayName = "DBP-39 CT";
        hit = 11;
        caliber = 2.4;
        typicalSpeed = 950;
        airFriction = -0.0009;
        deflecting = 16;
        tracerScale = 0.6;
        ACE_caliber = 5.79;
        ACE_bulletLength = 23.5;
        ACE_bulletMass = 4.2;
        ACE_ballisticCoefficients[] = {0.210};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {905, 935, 950, 970};
        ACE_barrelLengths[] = {368, 406, 463, 508};
    };
    class FA_o_580_DBP39_CT_T_Red: FA_o_580_DBP39_CT {
        tracer = 1;
        tracerColor[] = {1.0, 0.0, 0.0, 1.0};
    };
    class FA_o_580_DBP39_CT_T_Yellow: FA_o_580_DBP39_CT {
        tracer = 1;
        tracerColor[] = {1.0, 1.0, 0.0, 1.0};
    };
    class FA_o_580_DBP39_CT_T_Green: FA_o_580_DBP39_CT {
        tracer = 1;
        tracerColor[] = {0.0, 1.0, 0.0, 1.0};
    };
    class FA_o_580_DBP39_CT_T_White: FA_o_580_DBP39_CT {
        tracer = 1;
        tracerColor[] = {1.0, 1.0, 1.0, 1.0};
    };
    class FA_o_580_DBP39_CT_T_Blue: FA_o_580_DBP39_CT {
        tracer = 1;
        tracerColor[] = {0.0, 0.3, 1.0, 1.0};
    };
    class FA_o_580_DBP39_CT_T_Orange: FA_o_580_DBP39_CT {
        tracer = 1;
        tracerColor[] = {1.0, 0.4, 0.0, 1.0};
    };
    class FA_o_580_DBP39_CT_T_IR: FA_o_580_DBP39_CT {
        tracer = 1;
        nvgOnly = 1;
        tracerColor[] = {0.2, 1.0, 0.2, 1.0};
    };
    class FA_o_580_DBP40_AP: B_556x45_Ball {
        displayName = "DBP-40 AP";
        hit = 10;
        caliber = 2.7;
        typicalSpeed = 915;
        airFriction = -0.00092;
        deflecting = 12;
        tracerScale = 0.6;
        ACE_caliber = 5.79;
        ACE_bulletLength = 23.8;
        ACE_bulletMass = 4.4;
        ACE_ballisticCoefficients[] = {0.215};
        ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {870, 900, 915, 935};
        ACE_barrelLengths[] = {368, 406, 463, 508};
    };
    class FA_o_580_DBP40_AP_T_Red: FA_o_580_DBP40_AP {
        tracer = 1;
        tracerColor[] = {1.0, 0.0, 0.0, 1.0};
    };
    class FA_o_580_DBP40_AP_T_Yellow: FA_o_580_DBP40_AP {
        tracer = 1;
        tracerColor[] = {1.0, 1.0, 0.0, 1.0};
    };
    class FA_o_580_DBP40_AP_T_Green: FA_o_580_DBP40_AP {
        tracer = 1;
        tracerColor[] = {0.0, 1.0, 0.0, 1.0};
    };
    class FA_o_580_DBP40_AP_T_White: FA_o_580_DBP40_AP {
        tracer = 1;
        tracerColor[] = {1.0, 1.0, 1.0, 1.0};
    };
    class FA_o_580_DBP40_AP_T_Blue: FA_o_580_DBP40_AP {
        tracer = 1;
        tracerColor[] = {0.0, 0.3, 1.0, 1.0};
    };
    class FA_o_580_DBP40_AP_T_Orange: FA_o_580_DBP40_AP {
        tracer = 1;
        tracerColor[] = {1.0, 0.4, 0.0, 1.0};
    };
    class FA_o_580_DBP40_AP_T_IR: FA_o_580_DBP40_AP {
        tracer = 1;
        nvgOnly = 1;
        tracerColor[] = {0.2, 1.0, 0.2, 1.0};
    };

    // 9x21 Mk424 AP - the P07 / Rook 40's round (user, 2026-09-27: "make mags for 16Rnd_9x21_Mag"). The figures
    // are the Rearma DBP-43 AP's, the only FA 9x21 design, but on the base game's ball round so it loads without
    // Rearma and fa_tiers builds its _t2/_t3/_t4.
    class FA_b_9x21_Mk424_AP: B_9x21_Ball {
        displayName = "9x21 Mk424 AP";
        caliber = 2.0; hit = 9; typicalSpeed = 560; airFriction = -0.0017; deflecting = 20;
        ACE_caliber = 9.02; ACE_bulletLength = 15.5; ACE_bulletMass = 5.2;
        ACE_dragModel = 1; ACE_ballisticCoefficients[] = {0.135};
        ACE_muzzleVelocities[] = {470, 580}; ACE_barrelLengths[] = {115, 230};
    };

    // =========================================================
    // 12.7x55 and 9x19 - moved here from fa_rf when the creator DLCs left (2026-10-05). They sit on the base
    // game's rounds, and fa_tmt, fa_adf and fa_mpp issue them, so they stay with the core ammo.

    // 7N52 Molot - tungsten AP, transonic. Barrier / light-armor at short range.
    class FA_rf_ammo_127x55_7N52: B_127x99_Ball {
        displayName = "7N52 Molot";
        caliber = 3.5; hit = 22; typicalSpeed = 430; airFriction = -0.0011;
        ACE_caliber = 12.95; ACE_bulletLength = 35.0; ACE_bulletMass = 20.0;
        ACE_dragModel = 7; ACE_ballisticCoefficients[] = {0.15};
        ACE_muzzleVelocities[] = {430}; ACE_barrelLengths[] = {230};
    };
    // 7U13 Molot-S - subsonic tungsten AP. Suppressed, quiet, hits hard.
    class FA_rf_ammo_127x55_7U13: B_127x99_Ball {
        displayName = "7U13 Molot-S";
        caliber = 2.8; hit = 26; typicalSpeed = 290; airFriction = -0.0009;
        ACE_caliber = 12.95; ACE_bulletLength = 33.0; ACE_bulletMass = 22.0;
        ACE_dragModel = 1; ACE_ballisticCoefficients[] = {0.20};
        ACE_muzzleVelocities[] = {290}; ACE_barrelLengths[] = {230};
    };
    // 7U14 Uragan - subsonic heavy HP. Suppressed anti-personnel, massive bullet.
    class FA_rf_ammo_127x55_7U14: B_127x99_Ball {
        displayName = "7U14 Uragan";
        caliber = 1.6; hit = 35; typicalSpeed = 290; airFriction = -0.0008;
        ACE_caliber = 12.95; ACE_bulletLength = 40.0; ACE_bulletMass = 33.0;
        ACE_dragModel = 1; ACE_ballisticCoefficients[] = {0.25};
        ACE_muzzleVelocities[] = {290}; ACE_barrelLengths[] = {230};
    };
    // 9x19 Mk422 AP (user, 2026-09-27). The Rearma Mk422's figures, on the base game's ball round so it loads
    // without Rearma and is tiered.
    class FA_rf_9x19_Mk422_AP: B_9x21_Ball {
        displayName = "9x19 Mk422 AP";
        caliber = 1.8; hit = 8; typicalSpeed = 400; airFriction = -0.0020; deflecting = 22;
        ACE_caliber = 9.02; ACE_bulletLength = 15.2; ACE_bulletMass = 5.4;
        ACE_dragModel = 1; ACE_ballisticCoefficients[] = {0.140};
        ACE_muzzleVelocities[] = {400}; ACE_barrelLengths[] = {119};
    };

    #include "CfgAmmo_compat.hpp"
};
