class CfgMagazines {
    class 1Rnd_HE_Grenade_shell;
    class 3Rnd_HE_Grenade_shell;
    class 30Rnd_556x45_Stanag;
    class 200Rnd_556x45_Box_F;
    class 20Rnd_762x51_Mag;
    // Vehicle coax / HMG belt bases (Marshall coax, Rhino coax + commander HMG)
    class 200Rnd_762x51_Belt_T_Red;
    class 200Rnd_127x99_mag_Tracer_Red;
    class 200Rnd_338_Mag;
    class 130Rnd_338_Mag;
    class 150Rnd_762x54_Box;
    // ACE 7.62x51 HK417 mags
    class ACE_20Rnd_762x51_M993_AP_Mag;
    class ACE_10Rnd_762x51_Mag_SD;
    // ACE 12 Gauge shotgun mags
    class ACE_2Rnd_12Gauge_Pellets_No0_Buck;
    class ACE_2Rnd_12Gauge_Pellets_No1_Buck;
    class ACE_2Rnd_12Gauge_Pellets_No2_Buck;
    class ACE_2Rnd_12Gauge_Pellets_No3_Buck;
    class ACE_2Rnd_12Gauge_Pellets_No4_Buck;
    class ACE_2Rnd_12Gauge_Pellets_No4_Bird;
    class ACE_6Rnd_12Gauge_Pellets_No0_Buck;
    class ACE_6Rnd_12Gauge_Pellets_No1_Buck;
    class ACE_6Rnd_12Gauge_Pellets_No2_Buck;
    class ACE_6Rnd_12Gauge_Pellets_No3_Buck;
    class ACE_6Rnd_12Gauge_Pellets_No4_Buck;
    class ACE_6Rnd_12Gauge_Pellets_No4_Bird;
    // 7.62x39 — BI vanilla + Enoch
    class 30Rnd_762x39_Mag_F;
    class 30Rnd_762x39_Mag_Green_F;
    class 75Rnd_762x39_Mag_F;
    class 30Rnd_762x39_AK12_Mag_F;
    class 30Rnd_762x39_AK12_Lush_Mag_F;
    class 30Rnd_762x39_AK12_Arid_Mag_F;
    class 75rnd_762x39_AK12_Mag_F;
    class 75rnd_762x39_AK12_Lush_Mag_F;
    class 75rnd_762x39_AK12_Arid_Mag_F;
    class 100Rnd_65x39_caseless_black_mag;
    class 100Rnd_65x39_caseless_khaki_mag;
    class 100Rnd_65x39_caseless_mag;
    class 200Rnd_65x39_cased_Box;
    class 2000Rnd_65x39_Belt;
    class 1000Rnd_65x39_Belt;
    class 200Rnd_65x39_Belt;
    class 500Rnd_65x39_Belt;
    class PylonWeapon_2000Rnd_65x39_belt;
    // .338 LM base mag
    class 10Rnd_338_Mag;
    // Precision large-calibre base mags
    class 10Rnd_93x64_Mag;
    class 150Rnd_93x64_Mag;
    class 5Rnd_127x108_Mag;
    // .45 ACP base mags
    class 30Rnd_45ACP_Mag_SMG_01;
    class 11Rnd_45ACP_Mag;
    class 16Rnd_9x21_Mag;
    class 10Rnd_762x54_Mag;
    class 6Rnd_45ACP_Cylinder;
    class 7Rnd_408_Mag;
    class 30Rnd_9x21_Mag_SMG_02;
    // 5.8x42 base mag (Type 115 / CMR-76)
    class 30Rnd_580x42_Mag_F;

    // 6.5x39 Caseless base mags
    class 30Rnd_65x39_caseless_green;
    class 30Rnd_65x39_caseless_mag;
    class 30Rnd_65x39_caseless_black_mag;
    class 30Rnd_65x39_caseless_khaki_mag;
    class 30Rnd_65x39_caseless_msbs_mag;
    
    // =========================================================
    // 5.56x45mm — Mk327 HV (hybrid case, feeds existing 5.56 wells)
    // =========================================================
    class FA_b_30Rnd_556_Mk327_HV: 30Rnd_556x45_Stanag {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 5.56mm Mk327 HV";
        descriptionShort = "Mk327 HV";
        ammo = "FA_b_556_Mk327_HV";
        initSpeed = 1000;
        mass = 8;
    };
    class FA_b_30Rnd_556_Mk327_HV_T_Red: FA_b_30Rnd_556_Mk327_HV { ammo = "FA_b_556_Mk327_HV_T_Red"; displayName = "[JMSB] 30Rnd 5.56mm Mk327 HV - Red Tracer"; descriptionShort = "Mk327 HV"; tracersEvery = 4; };
    class FA_b_30Rnd_556_Mk327_HV_T_Yellow: FA_b_30Rnd_556_Mk327_HV { ammo = "FA_b_556_Mk327_HV_T_Yellow"; displayName = "[JMSB] 30Rnd 5.56mm Mk327 HV - Yellow Tracer"; descriptionShort = "Mk327 HV"; tracersEvery = 4; };
    class FA_b_30Rnd_556_Mk327_HV_T_Green: FA_b_30Rnd_556_Mk327_HV { ammo = "FA_b_556_Mk327_HV_T_Green"; displayName = "[JMSB] 30Rnd 5.56mm Mk327 HV - Green Tracer"; descriptionShort = "Mk327 HV"; tracersEvery = 4; };
    class FA_b_30Rnd_556_Mk327_HV_T_White: FA_b_30Rnd_556_Mk327_HV { ammo = "FA_b_556_Mk327_HV_T_White"; displayName = "[JMSB] 30Rnd 5.56mm Mk327 HV - White Tracer"; descriptionShort = "Mk327 HV"; tracersEvery = 4; };
    class FA_b_30Rnd_556_Mk327_HV_T_Blue: FA_b_30Rnd_556_Mk327_HV { ammo = "FA_b_556_Mk327_HV_T_Blue"; displayName = "[JMSB] 30Rnd 5.56mm Mk327 HV - Blue Tracer"; descriptionShort = "Mk327 HV"; tracersEvery = 4; };
    class FA_b_30Rnd_556_Mk327_HV_T_Orange: FA_b_30Rnd_556_Mk327_HV { ammo = "FA_b_556_Mk327_HV_T_Orange"; displayName = "[JMSB] 30Rnd 5.56mm Mk327 HV - Orange Tracer"; descriptionShort = "Mk327 HV"; tracersEvery = 4; };
    class FA_b_30Rnd_556_Mk327_HV_T_IR: FA_b_30Rnd_556_Mk327_HV { ammo = "FA_b_556_Mk327_HV_T_IR"; displayName = "[JMSB] 30Rnd 5.56mm Mk327 HV - IR Tracer"; descriptionShort = "Mk327 HV"; tracersEvery = 4; };

    // =========================================================
    // 5.56x45mm — XM891 CTEP (cased-telescoped, needs rated well)
    // =========================================================
    class FA_b_30Rnd_556_XM891_CTEP: 30Rnd_556x45_Stanag {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 5.56mm XM891 CTEP";
        descriptionShort = "XM891 CTEP";
        ammo = "FA_b_556_XM891_CTEP";
        initSpeed = 1015;
        mass = 6;
    };
    class FA_b_30Rnd_556_XM891_CTEP_T_Red: FA_b_30Rnd_556_XM891_CTEP { ammo = "FA_b_556_XM891_CTEP_T_Red"; displayName = "[JMSB] 30Rnd 5.56mm XM891 CTEP - Red Tracer"; descriptionShort = "XM891 CTEP"; tracersEvery = 4; };
    class FA_b_30Rnd_556_XM891_CTEP_T_Yellow: FA_b_30Rnd_556_XM891_CTEP { ammo = "FA_b_556_XM891_CTEP_T_Yellow"; displayName = "[JMSB] 30Rnd 5.56mm XM891 CTEP - Yellow Tracer"; descriptionShort = "XM891 CTEP"; tracersEvery = 4; };
    class FA_b_30Rnd_556_XM891_CTEP_T_Green: FA_b_30Rnd_556_XM891_CTEP { ammo = "FA_b_556_XM891_CTEP_T_Green"; displayName = "[JMSB] 30Rnd 5.56mm XM891 CTEP - Green Tracer"; descriptionShort = "XM891 CTEP"; tracersEvery = 4; };
    class FA_b_30Rnd_556_XM891_CTEP_T_White: FA_b_30Rnd_556_XM891_CTEP { ammo = "FA_b_556_XM891_CTEP_T_White"; displayName = "[JMSB] 30Rnd 5.56mm XM891 CTEP - White Tracer"; descriptionShort = "XM891 CTEP"; tracersEvery = 4; };
    class FA_b_30Rnd_556_XM891_CTEP_T_Blue: FA_b_30Rnd_556_XM891_CTEP { ammo = "FA_b_556_XM891_CTEP_T_Blue"; displayName = "[JMSB] 30Rnd 5.56mm XM891 CTEP - Blue Tracer"; descriptionShort = "XM891 CTEP"; tracersEvery = 4; };
    class FA_b_30Rnd_556_XM891_CTEP_T_Orange: FA_b_30Rnd_556_XM891_CTEP { ammo = "FA_b_556_XM891_CTEP_T_Orange"; displayName = "[JMSB] 30Rnd 5.56mm XM891 CTEP - Orange Tracer"; descriptionShort = "XM891 CTEP"; tracersEvery = 4; };
    class FA_b_30Rnd_556_XM891_CTEP_T_IR: FA_b_30Rnd_556_XM891_CTEP { ammo = "FA_b_556_XM891_CTEP_T_IR"; displayName = "[JMSB] 30Rnd 5.56mm XM891 CTEP - IR Tracer"; descriptionShort = "XM891 CTEP"; tracersEvery = 4; };

    // =========================================================
    // 7.62x51mm — M80A2 HV (hybrid case, feeds existing 7.62 wells)
    // =========================================================
    class FA_b_20Rnd_762_M80A2_HV: 20Rnd_762x51_Mag {
        author = QAUTHOR;
        displayName = "[JMSB] 20Rnd 7.62mm M80A2 HV";
        descriptionShort = "M80A2 HV";
        ammo = "FA_b_762_M80A2_HV";
        initSpeed = 940;
        mass = 16;
    };
    class FA_b_20Rnd_762_M80A2_HV_T_Red: FA_b_20Rnd_762_M80A2_HV { ammo = "FA_b_762_M80A2_HV_T_Red"; displayName = "[JMSB] 20Rnd 7.62mm M80A2 HV - Red Tracer"; descriptionShort = "M80A2 HV"; tracersEvery = 4; };
    class FA_b_20Rnd_762_M80A2_HV_T_Yellow: FA_b_20Rnd_762_M80A2_HV { ammo = "FA_b_762_M80A2_HV_T_Yellow"; displayName = "[JMSB] 20Rnd 7.62mm M80A2 HV - Yellow Tracer"; descriptionShort = "M80A2 HV"; tracersEvery = 4; };
    class FA_b_20Rnd_762_M80A2_HV_T_Green: FA_b_20Rnd_762_M80A2_HV { ammo = "FA_b_762_M80A2_HV_T_Green"; displayName = "[JMSB] 20Rnd 7.62mm M80A2 HV - Green Tracer"; descriptionShort = "M80A2 HV"; tracersEvery = 4; };
    class FA_b_20Rnd_762_M80A2_HV_T_White: FA_b_20Rnd_762_M80A2_HV { ammo = "FA_b_762_M80A2_HV_T_White"; displayName = "[JMSB] 20Rnd 7.62mm M80A2 HV - White Tracer"; descriptionShort = "M80A2 HV"; tracersEvery = 4; };
    class FA_b_20Rnd_762_M80A2_HV_T_Blue: FA_b_20Rnd_762_M80A2_HV { ammo = "FA_b_762_M80A2_HV_T_Blue"; displayName = "[JMSB] 20Rnd 7.62mm M80A2 HV - Blue Tracer"; descriptionShort = "M80A2 HV"; tracersEvery = 4; };
    class FA_b_20Rnd_762_M80A2_HV_T_Orange: FA_b_20Rnd_762_M80A2_HV { ammo = "FA_b_762_M80A2_HV_T_Orange"; displayName = "[JMSB] 20Rnd 7.62mm M80A2 HV - Orange Tracer"; descriptionShort = "M80A2 HV"; tracersEvery = 4; };
    class FA_b_20Rnd_762_M80A2_HV_T_IR: FA_b_20Rnd_762_M80A2_HV { ammo = "FA_b_762_M80A2_HV_T_IR"; displayName = "[JMSB] 20Rnd 7.62mm M80A2 HV - IR Tracer"; descriptionShort = "M80A2 HV"; tracersEvery = 4; };

    // =========================================================
    // 7.62x51mm — XM751 CTEP (cased-telescoped, needs rated well)
    // =========================================================
    class FA_b_20Rnd_762_XM751_CTEP: 20Rnd_762x51_Mag {
        author = QAUTHOR;
        displayName = "[JMSB] 20Rnd 7.62mm XM751 CTEP";
        descriptionShort = "XM751 CTEP";
        ammo = "FA_b_762_XM751_CTEP";
        initSpeed = 960;
        mass = 12;
    };
    class FA_b_20Rnd_762_XM751_CTEP_T_Red: FA_b_20Rnd_762_XM751_CTEP { ammo = "FA_b_762_XM751_CTEP_T_Red"; displayName = "[JMSB] 20Rnd 7.62mm XM751 CTEP - Red Tracer"; descriptionShort = "XM751 CTEP"; tracersEvery = 4; };
    class FA_b_20Rnd_762_XM751_CTEP_T_Yellow: FA_b_20Rnd_762_XM751_CTEP { ammo = "FA_b_762_XM751_CTEP_T_Yellow"; displayName = "[JMSB] 20Rnd 7.62mm XM751 CTEP - Yellow Tracer"; descriptionShort = "XM751 CTEP"; tracersEvery = 4; };
    class FA_b_20Rnd_762_XM751_CTEP_T_Green: FA_b_20Rnd_762_XM751_CTEP { ammo = "FA_b_762_XM751_CTEP_T_Green"; displayName = "[JMSB] 20Rnd 7.62mm XM751 CTEP - Green Tracer"; descriptionShort = "XM751 CTEP"; tracersEvery = 4; };
    class FA_b_20Rnd_762_XM751_CTEP_T_White: FA_b_20Rnd_762_XM751_CTEP { ammo = "FA_b_762_XM751_CTEP_T_White"; displayName = "[JMSB] 20Rnd 7.62mm XM751 CTEP - White Tracer"; descriptionShort = "XM751 CTEP"; tracersEvery = 4; };
    class FA_b_20Rnd_762_XM751_CTEP_T_Blue: FA_b_20Rnd_762_XM751_CTEP { ammo = "FA_b_762_XM751_CTEP_T_Blue"; displayName = "[JMSB] 20Rnd 7.62mm XM751 CTEP - Blue Tracer"; descriptionShort = "XM751 CTEP"; tracersEvery = 4; };
    class FA_b_20Rnd_762_XM751_CTEP_T_Orange: FA_b_20Rnd_762_XM751_CTEP { ammo = "FA_b_762_XM751_CTEP_T_Orange"; displayName = "[JMSB] 20Rnd 7.62mm XM751 CTEP - Orange Tracer"; descriptionShort = "XM751 CTEP"; tracersEvery = 4; };
    class FA_b_20Rnd_762_XM751_CTEP_T_IR: FA_b_20Rnd_762_XM751_CTEP { ammo = "FA_b_762_XM751_CTEP_T_IR"; displayName = "[JMSB] 20Rnd 7.62mm XM751 CTEP - IR Tracer"; descriptionShort = "XM751 CTEP"; tracersEvery = 4; };

    // =========================================================
    // 7.62x51mm — M80A2 HV — 200Rnd belt (Rhino coax et al.)
    // =========================================================
    class FA_b_200Rnd_762_M80A2_HV: 200Rnd_762x51_Belt_T_Red {
        author = QAUTHOR;
        displayName = "[JMSB] 200Rnd 7.62mm M80A2 HV";
        descriptionShort = "M80A2 HV";
        ammo = "FA_b_762_M80A2_HV";
        initSpeed = 940;
        tracersEvery = 0;
    };
    class FA_b_200Rnd_762_M80A2_HV_T_Red: FA_b_200Rnd_762_M80A2_HV { ammo = "FA_b_762_M80A2_HV_T_Red"; displayName = "[JMSB] 200Rnd 7.62mm M80A2 HV - Red Tracer"; descriptionShort = "M80A2 HV"; tracersEvery = 4; };
    class FA_b_200Rnd_762_M80A2_HV_T_Yellow: FA_b_200Rnd_762_M80A2_HV { ammo = "FA_b_762_M80A2_HV_T_Yellow"; displayName = "[JMSB] 200Rnd 7.62mm M80A2 HV - Yellow Tracer"; descriptionShort = "M80A2 HV"; tracersEvery = 4; };
    class FA_b_200Rnd_762_M80A2_HV_T_Green: FA_b_200Rnd_762_M80A2_HV { ammo = "FA_b_762_M80A2_HV_T_Green"; displayName = "[JMSB] 200Rnd 7.62mm M80A2 HV - Green Tracer"; descriptionShort = "M80A2 HV"; tracersEvery = 4; };
    class FA_b_200Rnd_762_M80A2_HV_T_White: FA_b_200Rnd_762_M80A2_HV { ammo = "FA_b_762_M80A2_HV_T_White"; displayName = "[JMSB] 200Rnd 7.62mm M80A2 HV - White Tracer"; descriptionShort = "M80A2 HV"; tracersEvery = 4; };
    class FA_b_200Rnd_762_M80A2_HV_T_Blue: FA_b_200Rnd_762_M80A2_HV { ammo = "FA_b_762_M80A2_HV_T_Blue"; displayName = "[JMSB] 200Rnd 7.62mm M80A2 HV - Blue Tracer"; descriptionShort = "M80A2 HV"; tracersEvery = 4; };
    class FA_b_200Rnd_762_M80A2_HV_T_Orange: FA_b_200Rnd_762_M80A2_HV { ammo = "FA_b_762_M80A2_HV_T_Orange"; displayName = "[JMSB] 200Rnd 7.62mm M80A2 HV - Orange Tracer"; descriptionShort = "M80A2 HV"; tracersEvery = 4; };
    class FA_b_200Rnd_762_M80A2_HV_T_IR: FA_b_200Rnd_762_M80A2_HV { ammo = "FA_b_762_M80A2_HV_T_IR"; displayName = "[JMSB] 200Rnd 7.62mm M80A2 HV - IR Tracer"; descriptionShort = "M80A2 HV"; tracersEvery = 4; };

    // =========================================================
    // 7.62x51mm — XM751 CTEP — 200Rnd belt (Rhino coax et al.)
    // =========================================================
    class FA_b_200Rnd_762_XM751_CTEP: 200Rnd_762x51_Belt_T_Red {
        author = QAUTHOR;
        displayName = "[JMSB] 200Rnd 7.62mm XM751 CTEP";
        descriptionShort = "XM751 CTEP";
        ammo = "FA_b_762_XM751_CTEP";
        initSpeed = 960;
        tracersEvery = 0;
    };
    class FA_b_200Rnd_762_XM751_CTEP_T_Red: FA_b_200Rnd_762_XM751_CTEP { ammo = "FA_b_762_XM751_CTEP_T_Red"; displayName = "[JMSB] 200Rnd 7.62mm XM751 CTEP - Red Tracer"; descriptionShort = "XM751 CTEP"; tracersEvery = 4; };
    class FA_b_200Rnd_762_XM751_CTEP_T_Yellow: FA_b_200Rnd_762_XM751_CTEP { ammo = "FA_b_762_XM751_CTEP_T_Yellow"; displayName = "[JMSB] 200Rnd 7.62mm XM751 CTEP - Yellow Tracer"; descriptionShort = "XM751 CTEP"; tracersEvery = 4; };
    class FA_b_200Rnd_762_XM751_CTEP_T_Green: FA_b_200Rnd_762_XM751_CTEP { ammo = "FA_b_762_XM751_CTEP_T_Green"; displayName = "[JMSB] 200Rnd 7.62mm XM751 CTEP - Green Tracer"; descriptionShort = "XM751 CTEP"; tracersEvery = 4; };
    class FA_b_200Rnd_762_XM751_CTEP_T_White: FA_b_200Rnd_762_XM751_CTEP { ammo = "FA_b_762_XM751_CTEP_T_White"; displayName = "[JMSB] 200Rnd 7.62mm XM751 CTEP - White Tracer"; descriptionShort = "XM751 CTEP"; tracersEvery = 4; };
    class FA_b_200Rnd_762_XM751_CTEP_T_Blue: FA_b_200Rnd_762_XM751_CTEP { ammo = "FA_b_762_XM751_CTEP_T_Blue"; displayName = "[JMSB] 200Rnd 7.62mm XM751 CTEP - Blue Tracer"; descriptionShort = "XM751 CTEP"; tracersEvery = 4; };
    class FA_b_200Rnd_762_XM751_CTEP_T_Orange: FA_b_200Rnd_762_XM751_CTEP { ammo = "FA_b_762_XM751_CTEP_T_Orange"; displayName = "[JMSB] 200Rnd 7.62mm XM751 CTEP - Orange Tracer"; descriptionShort = "XM751 CTEP"; tracersEvery = 4; };
    class FA_b_200Rnd_762_XM751_CTEP_T_IR: FA_b_200Rnd_762_XM751_CTEP { ammo = "FA_b_762_XM751_CTEP_T_IR"; displayName = "[JMSB] 200Rnd 7.62mm XM751 CTEP - IR Tracer"; descriptionShort = "XM751 CTEP"; tracersEvery = 4; };

    // =========================================================
    // 12.7x99 (.50 BMG) — Mk211 Mod 0 HEIAP — 200Rnd belt (M2/RWS, coax .50)
    // =========================================================
    class FA_b_200Rnd_127_Mk211Mod0: 200Rnd_127x99_mag_Tracer_Red {
        author = QAUTHOR;
        displayName = "[JMSB] 200Rnd 12.7mm Mk211Mod0 - 127";
        descriptionShort = "Mk211Mod0 AP";
        ammo = "FA_b_127x99_Mk211Mod0_AP";
        initSpeed = 890;
        tracersEvery = 0;
    };
    class FA_b_200Rnd_127_Mk211Mod0_T_Red: FA_b_200Rnd_127_Mk211Mod0 { ammo = "FA_b_127x99_Mk211Mod0_AP_T_Red"; displayName = "[JMSB] 200Rnd 12.7mm Mk211Mod0 - 127 - Red Tracer"; descriptionShort = "Mk211Mod0 AP"; tracersEvery = 4; };
    class FA_b_200Rnd_127_Mk211Mod0_T_Yellow: FA_b_200Rnd_127_Mk211Mod0 { ammo = "FA_b_127x99_Mk211Mod0_AP_T_Yellow"; displayName = "[JMSB] 200Rnd 12.7mm Mk211Mod0 - 127 - Yellow Tracer"; descriptionShort = "Mk211Mod0 AP"; tracersEvery = 4; };
    class FA_b_200Rnd_127_Mk211Mod0_T_Green: FA_b_200Rnd_127_Mk211Mod0 { ammo = "FA_b_127x99_Mk211Mod0_AP_T_Green"; displayName = "[JMSB] 200Rnd 12.7mm Mk211Mod0 - 127 - Green Tracer"; descriptionShort = "Mk211Mod0 AP"; tracersEvery = 4; };
    class FA_b_200Rnd_127_Mk211Mod0_T_White: FA_b_200Rnd_127_Mk211Mod0 { ammo = "FA_b_127x99_Mk211Mod0_AP_T_White"; displayName = "[JMSB] 200Rnd 12.7mm Mk211Mod0 - 127 - White Tracer"; descriptionShort = "Mk211Mod0 AP"; tracersEvery = 4; };
    class FA_b_200Rnd_127_Mk211Mod0_T_Blue: FA_b_200Rnd_127_Mk211Mod0 { ammo = "FA_b_127x99_Mk211Mod0_AP_T_Blue"; displayName = "[JMSB] 200Rnd 12.7mm Mk211Mod0 - 127 - Blue Tracer"; descriptionShort = "Mk211Mod0 AP"; tracersEvery = 4; };
    class FA_b_200Rnd_127_Mk211Mod0_T_Orange: FA_b_200Rnd_127_Mk211Mod0 { ammo = "FA_b_127x99_Mk211Mod0_AP_T_Orange"; displayName = "[JMSB] 200Rnd 12.7mm Mk211Mod0 - 127 - Orange Tracer"; descriptionShort = "Mk211Mod0 AP"; tracersEvery = 4; };
    class FA_b_200Rnd_127_Mk211Mod0_T_IR: FA_b_200Rnd_127_Mk211Mod0 { ammo = "FA_b_127x99_Mk211Mod0_AP_T_IR"; displayName = "[JMSB] 200Rnd 12.7mm Mk211Mod0 - 127 - IR Tracer"; descriptionShort = "Mk211Mod0 AP"; tracersEvery = 4; };

    // =========================================================
    // 12.7x99 (.50 BMG) — Mk258 LRP — 200Rnd belt (precision RWS)
    // =========================================================
    class FA_b_200Rnd_127_Mk258: 200Rnd_127x99_mag_Tracer_Red {
        author = QAUTHOR;
        displayName = "[JMSB] 200Rnd 12.7mm Mk258 - 127";
        descriptionShort = "Mk258 LRP";
        ammo = "FA_b_127x99_Mk258_LRP";
        initSpeed = 860;
        tracersEvery = 0;
    };
    class FA_b_200Rnd_127_Mk258_T_Red: FA_b_200Rnd_127_Mk258 { ammo = "FA_b_127x99_Mk258_LRP_T_Red"; displayName = "[JMSB] 200Rnd 12.7mm Mk258 - 127 - Red Tracer"; descriptionShort = "Mk258 LRP"; tracersEvery = 4; };
    class FA_b_200Rnd_127_Mk258_T_Yellow: FA_b_200Rnd_127_Mk258 { ammo = "FA_b_127x99_Mk258_LRP_T_Yellow"; displayName = "[JMSB] 200Rnd 12.7mm Mk258 - 127 - Yellow Tracer"; descriptionShort = "Mk258 LRP"; tracersEvery = 4; };
    class FA_b_200Rnd_127_Mk258_T_Green: FA_b_200Rnd_127_Mk258 { ammo = "FA_b_127x99_Mk258_LRP_T_Green"; displayName = "[JMSB] 200Rnd 12.7mm Mk258 - 127 - Green Tracer"; descriptionShort = "Mk258 LRP"; tracersEvery = 4; };
    class FA_b_200Rnd_127_Mk258_T_White: FA_b_200Rnd_127_Mk258 { ammo = "FA_b_127x99_Mk258_LRP_T_White"; displayName = "[JMSB] 200Rnd 12.7mm Mk258 - 127 - White Tracer"; descriptionShort = "Mk258 LRP"; tracersEvery = 4; };
    class FA_b_200Rnd_127_Mk258_T_Blue: FA_b_200Rnd_127_Mk258 { ammo = "FA_b_127x99_Mk258_LRP_T_Blue"; displayName = "[JMSB] 200Rnd 12.7mm Mk258 - 127 - Blue Tracer"; descriptionShort = "Mk258 LRP"; tracersEvery = 4; };
    class FA_b_200Rnd_127_Mk258_T_Orange: FA_b_200Rnd_127_Mk258 { ammo = "FA_b_127x99_Mk258_LRP_T_Orange"; displayName = "[JMSB] 200Rnd 12.7mm Mk258 - 127 - Orange Tracer"; descriptionShort = "Mk258 LRP"; tracersEvery = 4; };
    class FA_b_200Rnd_127_Mk258_T_IR: FA_b_200Rnd_127_Mk258 { ammo = "FA_b_127x99_Mk258_LRP_T_IR"; displayName = "[JMSB] 200Rnd 12.7mm Mk258 - 127 - IR Tracer"; descriptionShort = "Mk258 LRP"; tracersEvery = 4; };

    // =========================================================
    // .300 BLK (subsonic) — Mk341 SUB-AP
    // =========================================================
    class FA_b_30Rnd_300_Mk341_SubAP: 30Rnd_556x45_Stanag {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd .300 BLK Mk341 SubAP";
        descriptionShort = "Mk341 SubAP";
        ammo = "FA_b_300_Mk341_SubAP";
        initSpeed = 315;
        mass = 11;
    };
    class FA_b_30Rnd_300_Mk341_SubAP_T_Red: FA_b_30Rnd_300_Mk341_SubAP { ammo = "FA_b_300_Mk341_SubAP_T_Red"; displayName = "[JMSB] 30Rnd .300 BLK Mk341 SubAP - Red Tracer"; descriptionShort = "Mk341 SubAP"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk341_SubAP_T_Yellow: FA_b_30Rnd_300_Mk341_SubAP { ammo = "FA_b_300_Mk341_SubAP_T_Yellow"; displayName = "[JMSB] 30Rnd .300 BLK Mk341 SubAP - Yellow Tracer"; descriptionShort = "Mk341 SubAP"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk341_SubAP_T_Green: FA_b_30Rnd_300_Mk341_SubAP { ammo = "FA_b_300_Mk341_SubAP_T_Green"; displayName = "[JMSB] 30Rnd .300 BLK Mk341 SubAP - Green Tracer"; descriptionShort = "Mk341 SubAP"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk341_SubAP_T_White: FA_b_30Rnd_300_Mk341_SubAP { ammo = "FA_b_300_Mk341_SubAP_T_White"; displayName = "[JMSB] 30Rnd .300 BLK Mk341 SubAP - White Tracer"; descriptionShort = "Mk341 SubAP"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk341_SubAP_T_Blue: FA_b_30Rnd_300_Mk341_SubAP { ammo = "FA_b_300_Mk341_SubAP_T_Blue"; displayName = "[JMSB] 30Rnd .300 BLK Mk341 SubAP - Blue Tracer"; descriptionShort = "Mk341 SubAP"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk341_SubAP_T_Orange: FA_b_30Rnd_300_Mk341_SubAP { ammo = "FA_b_300_Mk341_SubAP_T_Orange"; displayName = "[JMSB] 30Rnd .300 BLK Mk341 SubAP - Orange Tracer"; descriptionShort = "Mk341 SubAP"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk341_SubAP_T_IR: FA_b_30Rnd_300_Mk341_SubAP { ammo = "FA_b_300_Mk341_SubAP_T_IR"; displayName = "[JMSB] 30Rnd .300 BLK Mk341 SubAP - IR Tracer"; descriptionShort = "Mk341 SubAP"; tracersEvery = 4; };

    // =========================================================
    // .300 BLK (subsonic) — XM345 SUB-AP2
    // =========================================================
    class FA_b_30Rnd_300_XM345_SubAP2: 30Rnd_556x45_Stanag {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd .300 BLK XM345 SubAP2";
        descriptionShort = "XM345 SubAP2";
        ammo = "FA_b_300_XM345_SubAP2";
        initSpeed = 312;
        mass = 11;
    };
    class FA_b_30Rnd_300_XM345_SubAP2_T_Red: FA_b_30Rnd_300_XM345_SubAP2 { ammo = "FA_b_300_XM345_SubAP2_T_Red"; displayName = "[JMSB] 30Rnd .300 BLK XM345 SubAP2 - Red Tracer"; descriptionShort = "XM345 SubAP2"; tracersEvery = 4; };
    class FA_b_30Rnd_300_XM345_SubAP2_T_Yellow: FA_b_30Rnd_300_XM345_SubAP2 { ammo = "FA_b_300_XM345_SubAP2_T_Yellow"; displayName = "[JMSB] 30Rnd .300 BLK XM345 SubAP2 - Yellow Tracer"; descriptionShort = "XM345 SubAP2"; tracersEvery = 4; };
    class FA_b_30Rnd_300_XM345_SubAP2_T_Green: FA_b_30Rnd_300_XM345_SubAP2 { ammo = "FA_b_300_XM345_SubAP2_T_Green"; displayName = "[JMSB] 30Rnd .300 BLK XM345 SubAP2 - Green Tracer"; descriptionShort = "XM345 SubAP2"; tracersEvery = 4; };
    class FA_b_30Rnd_300_XM345_SubAP2_T_White: FA_b_30Rnd_300_XM345_SubAP2 { ammo = "FA_b_300_XM345_SubAP2_T_White"; displayName = "[JMSB] 30Rnd .300 BLK XM345 SubAP2 - White Tracer"; descriptionShort = "XM345 SubAP2"; tracersEvery = 4; };
    class FA_b_30Rnd_300_XM345_SubAP2_T_Blue: FA_b_30Rnd_300_XM345_SubAP2 { ammo = "FA_b_300_XM345_SubAP2_T_Blue"; displayName = "[JMSB] 30Rnd .300 BLK XM345 SubAP2 - Blue Tracer"; descriptionShort = "XM345 SubAP2"; tracersEvery = 4; };
    class FA_b_30Rnd_300_XM345_SubAP2_T_Orange: FA_b_30Rnd_300_XM345_SubAP2 { ammo = "FA_b_300_XM345_SubAP2_T_Orange"; displayName = "[JMSB] 30Rnd .300 BLK XM345 SubAP2 - Orange Tracer"; descriptionShort = "XM345 SubAP2"; tracersEvery = 4; };
    class FA_b_30Rnd_300_XM345_SubAP2_T_IR: FA_b_30Rnd_300_XM345_SubAP2 { ammo = "FA_b_300_XM345_SubAP2_T_IR"; displayName = "[JMSB] 30Rnd .300 BLK XM345 SubAP2 - IR Tracer"; descriptionShort = "XM345 SubAP2"; tracersEvery = 4; };

    // =========================================================
    // .338 LM — Mk371 LRP Mod 0 (250gr, fast)
    // =========================================================
    class FA_b_10Rnd_338_Mk371_250gr: 10Rnd_338_Mag {
        author = QAUTHOR;
        displayName = "[JMSB] 10Rnd .338 Mk371 250gr";
        descriptionShort = "Mk371 250gr";
        ammo = "FA_b_338_Mk371_250gr";
        initSpeed = 905;
        mass = 8;
    };

    // =========================================================
    // .338 LM — Mk371 LRP Mod 1 (285gr, balanced)
    // =========================================================
    class FA_b_10Rnd_338_Mk371_285gr: 10Rnd_338_Mag {
        author = QAUTHOR;
        displayName = "[JMSB] 10Rnd .338 Mk371 285gr";
        descriptionShort = "Mk371 285gr";
        ammo = "FA_b_338_Mk371_285gr";
        initSpeed = 870;
        mass = 9;
    };

    // =========================================================
    // .338 LM — Mk371 LRP Mod 2 (300gr, extreme range)
    // =========================================================
    class FA_b_10Rnd_338_Mk371_300gr: 10Rnd_338_Mag {
        author = QAUTHOR;
        displayName = "[JMSB] 10Rnd .338 Mk371 300gr";
        descriptionShort = "Mk371 300gr";
        ammo = "FA_b_338_Mk371_300gr";
        initSpeed = 830;
        mass = 10;
    };

    // =========================================================
    // .300 BLK (supersonic) — Mk335 (110gr light)
    // =========================================================
    class FA_b_30Rnd_300_Mk335: 30Rnd_556x45_Stanag {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd .300 BLK Mk335";
        descriptionShort = "Mk335";
        ammo = "FA_b_300_Mk335";
        initSpeed = 725;
        mass = 7;
    };
    class FA_b_30Rnd_300_Mk335_T_Red: FA_b_30Rnd_300_Mk335 { ammo = "FA_b_300_Mk335_T_Red"; displayName = "[JMSB] 30Rnd .300 BLK Mk335 - Red Tracer"; descriptionShort = "Mk335"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk335_T_Yellow: FA_b_30Rnd_300_Mk335 { ammo = "FA_b_300_Mk335_T_Yellow"; displayName = "[JMSB] 30Rnd .300 BLK Mk335 - Yellow Tracer"; descriptionShort = "Mk335"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk335_T_Green: FA_b_30Rnd_300_Mk335 { ammo = "FA_b_300_Mk335_T_Green"; displayName = "[JMSB] 30Rnd .300 BLK Mk335 - Green Tracer"; descriptionShort = "Mk335"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk335_T_White: FA_b_30Rnd_300_Mk335 { ammo = "FA_b_300_Mk335_T_White"; displayName = "[JMSB] 30Rnd .300 BLK Mk335 - White Tracer"; descriptionShort = "Mk335"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk335_T_Blue: FA_b_30Rnd_300_Mk335 { ammo = "FA_b_300_Mk335_T_Blue"; displayName = "[JMSB] 30Rnd .300 BLK Mk335 - Blue Tracer"; descriptionShort = "Mk335"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk335_T_Orange: FA_b_30Rnd_300_Mk335 { ammo = "FA_b_300_Mk335_T_Orange"; displayName = "[JMSB] 30Rnd .300 BLK Mk335 - Orange Tracer"; descriptionShort = "Mk335"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk335_T_IR: FA_b_30Rnd_300_Mk335 { ammo = "FA_b_300_Mk335_T_IR"; displayName = "[JMSB] 30Rnd .300 BLK Mk335 - IR Tracer"; descriptionShort = "Mk335"; tracersEvery = 4; };

    // =========================================================
    // .300 BLK (supersonic) — Mk336 (125gr standard)
    // =========================================================
    class FA_b_30Rnd_300_Mk336: 30Rnd_556x45_Stanag {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd .300 BLK Mk336";
        descriptionShort = "Mk336";
        ammo = "FA_b_300_Mk336";
        initSpeed = 675;
        mass = 8;
    };
    class FA_b_30Rnd_300_Mk336_T_Red: FA_b_30Rnd_300_Mk336 { ammo = "FA_b_300_Mk336_T_Red"; displayName = "[JMSB] 30Rnd .300 BLK Mk336 - Red Tracer"; descriptionShort = "Mk336"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk336_T_Yellow: FA_b_30Rnd_300_Mk336 { ammo = "FA_b_300_Mk336_T_Yellow"; displayName = "[JMSB] 30Rnd .300 BLK Mk336 - Yellow Tracer"; descriptionShort = "Mk336"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk336_T_Green: FA_b_30Rnd_300_Mk336 { ammo = "FA_b_300_Mk336_T_Green"; displayName = "[JMSB] 30Rnd .300 BLK Mk336 - Green Tracer"; descriptionShort = "Mk336"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk336_T_White: FA_b_30Rnd_300_Mk336 { ammo = "FA_b_300_Mk336_T_White"; displayName = "[JMSB] 30Rnd .300 BLK Mk336 - White Tracer"; descriptionShort = "Mk336"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk336_T_Blue: FA_b_30Rnd_300_Mk336 { ammo = "FA_b_300_Mk336_T_Blue"; displayName = "[JMSB] 30Rnd .300 BLK Mk336 - Blue Tracer"; descriptionShort = "Mk336"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk336_T_Orange: FA_b_30Rnd_300_Mk336 { ammo = "FA_b_300_Mk336_T_Orange"; displayName = "[JMSB] 30Rnd .300 BLK Mk336 - Orange Tracer"; descriptionShort = "Mk336"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk336_T_IR: FA_b_30Rnd_300_Mk336 { ammo = "FA_b_300_Mk336_T_IR"; displayName = "[JMSB] 30Rnd .300 BLK Mk336 - IR Tracer"; descriptionShort = "Mk336"; tracersEvery = 4; };

    // =========================================================
    // .300 BLK (supersonic) — Mk337 (150gr heavy)
    // =========================================================
    class FA_b_30Rnd_300_Mk337: 30Rnd_556x45_Stanag {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd .300 BLK Mk337";
        descriptionShort = "Mk337";
        ammo = "FA_b_300_Mk337";
        initSpeed = 620;
        mass = 9;
    };
    class FA_b_30Rnd_300_Mk337_T_Red: FA_b_30Rnd_300_Mk337 { ammo = "FA_b_300_Mk337_T_Red"; displayName = "[JMSB] 30Rnd .300 BLK Mk337 - Red Tracer"; descriptionShort = "Mk337"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk337_T_Yellow: FA_b_30Rnd_300_Mk337 { ammo = "FA_b_300_Mk337_T_Yellow"; displayName = "[JMSB] 30Rnd .300 BLK Mk337 - Yellow Tracer"; descriptionShort = "Mk337"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk337_T_Green: FA_b_30Rnd_300_Mk337 { ammo = "FA_b_300_Mk337_T_Green"; displayName = "[JMSB] 30Rnd .300 BLK Mk337 - Green Tracer"; descriptionShort = "Mk337"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk337_T_White: FA_b_30Rnd_300_Mk337 { ammo = "FA_b_300_Mk337_T_White"; displayName = "[JMSB] 30Rnd .300 BLK Mk337 - White Tracer"; descriptionShort = "Mk337"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk337_T_Blue: FA_b_30Rnd_300_Mk337 { ammo = "FA_b_300_Mk337_T_Blue"; displayName = "[JMSB] 30Rnd .300 BLK Mk337 - Blue Tracer"; descriptionShort = "Mk337"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk337_T_Orange: FA_b_30Rnd_300_Mk337 { ammo = "FA_b_300_Mk337_T_Orange"; displayName = "[JMSB] 30Rnd .300 BLK Mk337 - Orange Tracer"; descriptionShort = "Mk337"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk337_T_IR: FA_b_30Rnd_300_Mk337 { ammo = "FA_b_300_Mk337_T_IR"; displayName = "[JMSB] 30Rnd .300 BLK Mk337 - IR Tracer"; descriptionShort = "Mk337"; tracersEvery = 4; };

    // =========================================================
    // .300 BLK (subsonic) — Mk342 (190gr)
    // =========================================================
    class FA_b_30Rnd_300_Mk342_Sub: 30Rnd_556x45_Stanag {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd .300 BLK Mk342 Sub";
        descriptionShort = "Mk342 Sub";
        ammo = "FA_b_300_Mk342_Sub";
        initSpeed = 318;
        mass = 10;
    };
    class FA_b_30Rnd_300_Mk342_Sub_T_Red: FA_b_30Rnd_300_Mk342_Sub { ammo = "FA_b_300_Mk342_Sub_T_Red"; displayName = "[JMSB] 30Rnd .300 BLK Mk342 Sub - Red Tracer"; descriptionShort = "Mk342 Sub"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk342_Sub_T_Yellow: FA_b_30Rnd_300_Mk342_Sub { ammo = "FA_b_300_Mk342_Sub_T_Yellow"; displayName = "[JMSB] 30Rnd .300 BLK Mk342 Sub - Yellow Tracer"; descriptionShort = "Mk342 Sub"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk342_Sub_T_Green: FA_b_30Rnd_300_Mk342_Sub { ammo = "FA_b_300_Mk342_Sub_T_Green"; displayName = "[JMSB] 30Rnd .300 BLK Mk342 Sub - Green Tracer"; descriptionShort = "Mk342 Sub"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk342_Sub_T_White: FA_b_30Rnd_300_Mk342_Sub { ammo = "FA_b_300_Mk342_Sub_T_White"; displayName = "[JMSB] 30Rnd .300 BLK Mk342 Sub - White Tracer"; descriptionShort = "Mk342 Sub"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk342_Sub_T_Blue: FA_b_30Rnd_300_Mk342_Sub { ammo = "FA_b_300_Mk342_Sub_T_Blue"; displayName = "[JMSB] 30Rnd .300 BLK Mk342 Sub - Blue Tracer"; descriptionShort = "Mk342 Sub"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk342_Sub_T_Orange: FA_b_30Rnd_300_Mk342_Sub { ammo = "FA_b_300_Mk342_Sub_T_Orange"; displayName = "[JMSB] 30Rnd .300 BLK Mk342 Sub - Orange Tracer"; descriptionShort = "Mk342 Sub"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk342_Sub_T_IR: FA_b_30Rnd_300_Mk342_Sub { ammo = "FA_b_300_Mk342_Sub_T_IR"; displayName = "[JMSB] 30Rnd .300 BLK Mk342 Sub - IR Tracer"; descriptionShort = "Mk342 Sub"; tracersEvery = 4; };

    // =========================================================
    // .300 BLK (subsonic) — Mk343 (220gr heavy)
    // =========================================================
    class FA_b_30Rnd_300_Mk343_Sub: 30Rnd_556x45_Stanag {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd .300 BLK Mk343 Sub";
        descriptionShort = "Mk343 Sub";
        ammo = "FA_b_300_Mk343_Sub";
        initSpeed = 305;
        mass = 11;
    };
    class FA_b_30Rnd_300_Mk343_Sub_T_Red: FA_b_30Rnd_300_Mk343_Sub { ammo = "FA_b_300_Mk343_Sub_T_Red"; displayName = "[JMSB] 30Rnd .300 BLK Mk343 Sub - Red Tracer"; descriptionShort = "Mk343 Sub"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk343_Sub_T_Yellow: FA_b_30Rnd_300_Mk343_Sub { ammo = "FA_b_300_Mk343_Sub_T_Yellow"; displayName = "[JMSB] 30Rnd .300 BLK Mk343 Sub - Yellow Tracer"; descriptionShort = "Mk343 Sub"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk343_Sub_T_Green: FA_b_30Rnd_300_Mk343_Sub { ammo = "FA_b_300_Mk343_Sub_T_Green"; displayName = "[JMSB] 30Rnd .300 BLK Mk343 Sub - Green Tracer"; descriptionShort = "Mk343 Sub"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk343_Sub_T_White: FA_b_30Rnd_300_Mk343_Sub { ammo = "FA_b_300_Mk343_Sub_T_White"; displayName = "[JMSB] 30Rnd .300 BLK Mk343 Sub - White Tracer"; descriptionShort = "Mk343 Sub"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk343_Sub_T_Blue: FA_b_30Rnd_300_Mk343_Sub { ammo = "FA_b_300_Mk343_Sub_T_Blue"; displayName = "[JMSB] 30Rnd .300 BLK Mk343 Sub - Blue Tracer"; descriptionShort = "Mk343 Sub"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk343_Sub_T_Orange: FA_b_30Rnd_300_Mk343_Sub { ammo = "FA_b_300_Mk343_Sub_T_Orange"; displayName = "[JMSB] 30Rnd .300 BLK Mk343 Sub - Orange Tracer"; descriptionShort = "Mk343 Sub"; tracersEvery = 4; };
    class FA_b_30Rnd_300_Mk343_Sub_T_IR: FA_b_30Rnd_300_Mk343_Sub { ammo = "FA_b_300_Mk343_Sub_T_IR"; displayName = "[JMSB] 30Rnd .300 BLK Mk343 Sub - IR Tracer"; descriptionShort = "Mk343 Sub"; tracersEvery = 4; };

    // =========================================================
    // .338 NM — Mk372 MMG — 200Rnd belt
    // =========================================================
    class FA_b_200Rnd_338_Mk372: 200Rnd_338_Mag {
        author = QAUTHOR;
        displayName = "[JMSB] 200Rnd .338 Mk372";
        descriptionShort = "Mk372";
        ammo = "FA_b_338_Mk372";
        initSpeed = 810;
        mass = 40;
    };
    class FA_b_200Rnd_338_Mk372_T_Red: FA_b_200Rnd_338_Mk372 { ammo = "FA_b_338_Mk372_T_Red"; displayName = "[JMSB] 200Rnd .338 Mk372 - Red Tracer"; descriptionShort = "Mk372"; tracersEvery = 4; };
    class FA_b_200Rnd_338_Mk372_T_Yellow: FA_b_200Rnd_338_Mk372 { ammo = "FA_b_338_Mk372_T_Yellow"; displayName = "[JMSB] 200Rnd .338 Mk372 - Yellow Tracer"; descriptionShort = "Mk372"; tracersEvery = 4; };
    class FA_b_200Rnd_338_Mk372_T_Green: FA_b_200Rnd_338_Mk372 { ammo = "FA_b_338_Mk372_T_Green"; displayName = "[JMSB] 200Rnd .338 Mk372 - Green Tracer"; descriptionShort = "Mk372"; tracersEvery = 4; };
    class FA_b_200Rnd_338_Mk372_T_White: FA_b_200Rnd_338_Mk372 { ammo = "FA_b_338_Mk372_T_White"; displayName = "[JMSB] 200Rnd .338 Mk372 - White Tracer"; descriptionShort = "Mk372"; tracersEvery = 4; };
    class FA_b_200Rnd_338_Mk372_T_Blue: FA_b_200Rnd_338_Mk372 { ammo = "FA_b_338_Mk372_T_Blue"; displayName = "[JMSB] 200Rnd .338 Mk372 - Blue Tracer"; descriptionShort = "Mk372"; tracersEvery = 4; };
    class FA_b_200Rnd_338_Mk372_T_Orange: FA_b_200Rnd_338_Mk372 { ammo = "FA_b_338_Mk372_T_Orange"; displayName = "[JMSB] 200Rnd .338 Mk372 - Orange Tracer"; descriptionShort = "Mk372"; tracersEvery = 4; };
    class FA_b_200Rnd_338_Mk372_T_IR: FA_b_200Rnd_338_Mk372 { ammo = "FA_b_338_Mk372_T_IR"; displayName = "[JMSB] 200Rnd .338 Mk372 - IR Tracer"; descriptionShort = "Mk372"; tracersEvery = 4; };

    // =========================================================
    // .338 NM — Mk372 MMG — 130Rnd belt
    // =========================================================
    class FA_b_130Rnd_338_Mk372: 130Rnd_338_Mag {
        author = QAUTHOR;
        displayName = "[JMSB] 130Rnd .338 Mk372";
        descriptionShort = "Mk372";
        ammo = "FA_b_338_Mk372";
        initSpeed = 810;
        mass = 28;
    };
    class FA_b_130Rnd_338_Mk372_T_Red: FA_b_130Rnd_338_Mk372 { ammo = "FA_b_338_Mk372_T_Red"; displayName = "[JMSB] 130Rnd .338 Mk372 - Red Tracer"; descriptionShort = "Mk372"; tracersEvery = 4; };
    class FA_b_130Rnd_338_Mk372_T_Yellow: FA_b_130Rnd_338_Mk372 { ammo = "FA_b_338_Mk372_T_Yellow"; displayName = "[JMSB] 130Rnd .338 Mk372 - Yellow Tracer"; descriptionShort = "Mk372"; tracersEvery = 4; };
    class FA_b_130Rnd_338_Mk372_T_Green: FA_b_130Rnd_338_Mk372 { ammo = "FA_b_338_Mk372_T_Green"; displayName = "[JMSB] 130Rnd .338 Mk372 - Green Tracer"; descriptionShort = "Mk372"; tracersEvery = 4; };
    class FA_b_130Rnd_338_Mk372_T_White: FA_b_130Rnd_338_Mk372 { ammo = "FA_b_338_Mk372_T_White"; displayName = "[JMSB] 130Rnd .338 Mk372 - White Tracer"; descriptionShort = "Mk372"; tracersEvery = 4; };
    class FA_b_130Rnd_338_Mk372_T_Blue: FA_b_130Rnd_338_Mk372 { ammo = "FA_b_338_Mk372_T_Blue"; displayName = "[JMSB] 130Rnd .338 Mk372 - Blue Tracer"; descriptionShort = "Mk372"; tracersEvery = 4; };
    class FA_b_130Rnd_338_Mk372_T_Orange: FA_b_130Rnd_338_Mk372 { ammo = "FA_b_338_Mk372_T_Orange"; displayName = "[JMSB] 130Rnd .338 Mk372 - Orange Tracer"; descriptionShort = "Mk372"; tracersEvery = 4; };
    class FA_b_130Rnd_338_Mk372_T_IR: FA_b_130Rnd_338_Mk372 { ammo = "FA_b_338_Mk372_T_IR"; displayName = "[JMSB] 130Rnd .338 Mk372 - IR Tracer"; descriptionShort = "Mk372"; tracersEvery = 4; };

    // =========================================================
    // 6.5x39 Caseless EPR — MX family only
    // =========================================================
    class FA_b_30Rnd_65_EPR: 30Rnd_65x39_caseless_mag {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 6.5mm EPR";
        descriptionShort = "Mk330 EPR";
        ammo = "FA_b_65_EPR";
        initSpeed = 950;
        mass = 7;
    };
    class FA_b_30Rnd_65_EPR_T_Red: FA_b_30Rnd_65_EPR { ammo = "FA_b_65_EPR_T_Red"; displayName = "[JMSB] 30Rnd 6.5mm EPR - Red Tracer"; descriptionShort = "Mk330 EPR"; tracersEvery = 4; };
    class FA_b_30Rnd_65_EPR_T_Yellow: FA_b_30Rnd_65_EPR { ammo = "FA_b_65_EPR_T_Yellow"; displayName = "[JMSB] 30Rnd 6.5mm EPR - Yellow Tracer"; descriptionShort = "Mk330 EPR"; tracersEvery = 4; };
    class FA_b_30Rnd_65_EPR_T_Green: FA_b_30Rnd_65_EPR { ammo = "FA_b_65_EPR_T_Green"; displayName = "[JMSB] 30Rnd 6.5mm EPR - Green Tracer"; descriptionShort = "Mk330 EPR"; tracersEvery = 4; };
    class FA_b_30Rnd_65_EPR_T_White: FA_b_30Rnd_65_EPR { ammo = "FA_b_65_EPR_T_White"; displayName = "[JMSB] 30Rnd 6.5mm EPR - White Tracer"; descriptionShort = "Mk330 EPR"; tracersEvery = 4; };
    class FA_b_30Rnd_65_EPR_T_Blue: FA_b_30Rnd_65_EPR { ammo = "FA_b_65_EPR_T_Blue"; displayName = "[JMSB] 30Rnd 6.5mm EPR - Blue Tracer"; descriptionShort = "Mk330 EPR"; tracersEvery = 4; };
    class FA_b_30Rnd_65_EPR_T_Orange: FA_b_30Rnd_65_EPR { ammo = "FA_b_65_EPR_T_Orange"; displayName = "[JMSB] 30Rnd 6.5mm EPR - Orange Tracer"; descriptionShort = "Mk330 EPR"; tracersEvery = 4; };
    class FA_b_30Rnd_65_EPR_T_IR: FA_b_30Rnd_65_EPR { ammo = "FA_b_65_EPR_T_IR"; displayName = "[JMSB] 30Rnd 6.5mm EPR - IR Tracer"; descriptionShort = "Mk330 EPR"; tracersEvery = 4; };

    class FA_b_30Rnd_65_EPR_Black: 30Rnd_65x39_caseless_black_mag {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 6.5mm EPR - Black";
        descriptionShort = "Mk330 EPR";
        ammo = "FA_b_65_EPR";
        initSpeed = 950;
        mass = 7;
    };
    class FA_b_30Rnd_65_EPR_Black_T_Red: FA_b_30Rnd_65_EPR_Black { ammo = "FA_b_65_EPR_T_Red"; displayName = "[JMSB] 30Rnd 6.5mm EPR - Red Tracer, Black"; descriptionShort = "Mk330 EPR"; tracersEvery = 4; };
    class FA_b_30Rnd_65_EPR_Black_T_Yellow: FA_b_30Rnd_65_EPR_Black { ammo = "FA_b_65_EPR_T_Yellow"; displayName = "[JMSB] 30Rnd 6.5mm EPR - Yellow Tracer, Black"; descriptionShort = "Mk330 EPR"; tracersEvery = 4; };
    class FA_b_30Rnd_65_EPR_Black_T_Green: FA_b_30Rnd_65_EPR_Black { ammo = "FA_b_65_EPR_T_Green"; displayName = "[JMSB] 30Rnd 6.5mm EPR - Green Tracer, Black"; descriptionShort = "Mk330 EPR"; tracersEvery = 4; };
    class FA_b_30Rnd_65_EPR_Black_T_White: FA_b_30Rnd_65_EPR_Black { ammo = "FA_b_65_EPR_T_White"; displayName = "[JMSB] 30Rnd 6.5mm EPR - White Tracer, Black"; descriptionShort = "Mk330 EPR"; tracersEvery = 4; };
    class FA_b_30Rnd_65_EPR_Black_T_Blue: FA_b_30Rnd_65_EPR_Black { ammo = "FA_b_65_EPR_T_Blue"; displayName = "[JMSB] 30Rnd 6.5mm EPR - Blue Tracer, Black"; descriptionShort = "Mk330 EPR"; tracersEvery = 4; };
    class FA_b_30Rnd_65_EPR_Black_T_Orange: FA_b_30Rnd_65_EPR_Black { ammo = "FA_b_65_EPR_T_Orange"; displayName = "[JMSB] 30Rnd 6.5mm EPR - Orange Tracer, Black"; descriptionShort = "Mk330 EPR"; tracersEvery = 4; };
    class FA_b_30Rnd_65_EPR_Black_T_IR: FA_b_30Rnd_65_EPR_Black { ammo = "FA_b_65_EPR_T_IR"; displayName = "[JMSB] 30Rnd 6.5mm EPR - IR Tracer, Black"; descriptionShort = "Mk330 EPR"; tracersEvery = 4; };

    class FA_b_30Rnd_65_EPR_Khaki: 30Rnd_65x39_caseless_khaki_mag {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 6.5mm EPR - Khaki";
        descriptionShort = "Mk330 EPR";
        ammo = "FA_b_65_EPR";
        initSpeed = 950;
        mass = 7;
    };
    class FA_b_30Rnd_65_EPR_Khaki_T_Red: FA_b_30Rnd_65_EPR_Khaki { ammo = "FA_b_65_EPR_T_Red"; displayName = "[JMSB] 30Rnd 6.5mm EPR - Red Tracer, Khaki"; descriptionShort = "Mk330 EPR"; tracersEvery = 4; };
    class FA_b_30Rnd_65_EPR_Khaki_T_Yellow: FA_b_30Rnd_65_EPR_Khaki { ammo = "FA_b_65_EPR_T_Yellow"; displayName = "[JMSB] 30Rnd 6.5mm EPR - Yellow Tracer, Khaki"; descriptionShort = "Mk330 EPR"; tracersEvery = 4; };
    class FA_b_30Rnd_65_EPR_Khaki_T_Green: FA_b_30Rnd_65_EPR_Khaki { ammo = "FA_b_65_EPR_T_Green"; displayName = "[JMSB] 30Rnd 6.5mm EPR - Green Tracer, Khaki"; descriptionShort = "Mk330 EPR"; tracersEvery = 4; };
    class FA_b_30Rnd_65_EPR_Khaki_T_White: FA_b_30Rnd_65_EPR_Khaki { ammo = "FA_b_65_EPR_T_White"; displayName = "[JMSB] 30Rnd 6.5mm EPR - White Tracer, Khaki"; descriptionShort = "Mk330 EPR"; tracersEvery = 4; };
    class FA_b_30Rnd_65_EPR_Khaki_T_Blue: FA_b_30Rnd_65_EPR_Khaki { ammo = "FA_b_65_EPR_T_Blue"; displayName = "[JMSB] 30Rnd 6.5mm EPR - Blue Tracer, Khaki"; descriptionShort = "Mk330 EPR"; tracersEvery = 4; };
    class FA_b_30Rnd_65_EPR_Khaki_T_Orange: FA_b_30Rnd_65_EPR_Khaki { ammo = "FA_b_65_EPR_T_Orange"; displayName = "[JMSB] 30Rnd 6.5mm EPR - Orange Tracer, Khaki"; descriptionShort = "Mk330 EPR"; tracersEvery = 4; };
    class FA_b_30Rnd_65_EPR_Khaki_T_IR: FA_b_30Rnd_65_EPR_Khaki { ammo = "FA_b_65_EPR_T_IR"; displayName = "[JMSB] 30Rnd 6.5mm EPR - IR Tracer, Khaki"; descriptionShort = "Mk330 EPR"; tracersEvery = 4; };

    class FA_b_30Rnd_65_EPR_MSBS: 30Rnd_65x39_caseless_msbs_mag {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 6.5mm EPR (MSBS)";
        descriptionShort = "Mk330 EPR";
        ammo = "FA_b_65_EPR";
        initSpeed = 950;
        mass = 7;
    };
    class FA_b_30Rnd_65_EPR_MSBS_T_Red: FA_b_30Rnd_65_EPR_MSBS { ammo = "FA_b_65_EPR_T_Red"; displayName = "[JMSB] 30Rnd 6.5mm EPR (MSBS) - Red Tracer"; descriptionShort = "Mk330 EPR"; tracersEvery = 4; };
    class FA_b_30Rnd_65_EPR_MSBS_T_Yellow: FA_b_30Rnd_65_EPR_MSBS { ammo = "FA_b_65_EPR_T_Yellow"; displayName = "[JMSB] 30Rnd 6.5mm EPR (MSBS) - Yellow Tracer"; descriptionShort = "Mk330 EPR"; tracersEvery = 4; };
    class FA_b_30Rnd_65_EPR_MSBS_T_Green: FA_b_30Rnd_65_EPR_MSBS { ammo = "FA_b_65_EPR_T_Green"; displayName = "[JMSB] 30Rnd 6.5mm EPR (MSBS) - Green Tracer"; descriptionShort = "Mk330 EPR"; tracersEvery = 4; };
    class FA_b_30Rnd_65_EPR_MSBS_T_White: FA_b_30Rnd_65_EPR_MSBS { ammo = "FA_b_65_EPR_T_White"; displayName = "[JMSB] 30Rnd 6.5mm EPR (MSBS) - White Tracer"; descriptionShort = "Mk330 EPR"; tracersEvery = 4; };
    class FA_b_30Rnd_65_EPR_MSBS_T_Blue: FA_b_30Rnd_65_EPR_MSBS { ammo = "FA_b_65_EPR_T_Blue"; displayName = "[JMSB] 30Rnd 6.5mm EPR (MSBS) - Blue Tracer"; descriptionShort = "Mk330 EPR"; tracersEvery = 4; };
    class FA_b_30Rnd_65_EPR_MSBS_T_Orange: FA_b_30Rnd_65_EPR_MSBS { ammo = "FA_b_65_EPR_T_Orange"; displayName = "[JMSB] 30Rnd 6.5mm EPR (MSBS) - Orange Tracer"; descriptionShort = "Mk330 EPR"; tracersEvery = 4; };
    class FA_b_30Rnd_65_EPR_MSBS_T_IR: FA_b_30Rnd_65_EPR_MSBS { ammo = "FA_b_65_EPR_T_IR"; displayName = "[JMSB] 30Rnd 6.5mm EPR (MSBS) - IR Tracer"; descriptionShort = "Mk330 EPR"; tracersEvery = 4; };

    // =========================================================
    // 7.62x39mm — 7N43 Kremen — BI vanilla 30Rnd
    // =========================================================
    class FA_o_30Rnd_762x39_7N43: 30Rnd_762x39_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 7.62x39mm 7N43";
        descriptionShort = "7.62x39 7N43 Kremen";
        ammo = "FA_o_762x39_7N43";
        initSpeed = 820;
        mass = 7;
    };
    class FA_o_30Rnd_762x39_7N43_T_Red: FA_o_30Rnd_762x39_7N43 { ammo = "FA_o_762x39_7N43_T_Red"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 - Red Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N43_T_Yellow: FA_o_30Rnd_762x39_7N43 { ammo = "FA_o_762x39_7N43_T_Yellow"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 - Yellow Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N43_T_Green: FA_o_30Rnd_762x39_7N43 { ammo = "FA_o_762x39_7N43_T_Green"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 - Green Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N43_T_White: FA_o_30Rnd_762x39_7N43 { ammo = "FA_o_762x39_7N43_T_White"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 - White Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N43_T_Blue: FA_o_30Rnd_762x39_7N43 { ammo = "FA_o_762x39_7N43_T_Blue"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 - Blue Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N43_T_Orange: FA_o_30Rnd_762x39_7N43 { ammo = "FA_o_762x39_7N43_T_Orange"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 - Orange Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N43_T_IR: FA_o_30Rnd_762x39_7N43 { ammo = "FA_o_762x39_7N43_T_IR"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 - IR Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };

    // =========================================================
    // 7.62x39mm — 7N43 Kremen — BI vanilla 30Rnd Green
    // =========================================================
    class FA_o_30Rnd_762x39_7N43_Green: 30Rnd_762x39_Mag_Green_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 - Green";
        descriptionShort = "7.62x39 7N43 Kremen";
        ammo = "FA_o_762x39_7N43";
        initSpeed = 820;
        mass = 7;
    };
    class FA_o_30Rnd_762x39_7N43_Green_T_Red: FA_o_30Rnd_762x39_7N43_Green { ammo = "FA_o_762x39_7N43_T_Red"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 - Red Tracer, Green"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N43_Green_T_Yellow: FA_o_30Rnd_762x39_7N43_Green { ammo = "FA_o_762x39_7N43_T_Yellow"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 - Yellow Tracer, Green"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N43_Green_T_Green: FA_o_30Rnd_762x39_7N43_Green { ammo = "FA_o_762x39_7N43_T_Green"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 - Green Tracer, Green"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N43_Green_T_White: FA_o_30Rnd_762x39_7N43_Green { ammo = "FA_o_762x39_7N43_T_White"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 - White Tracer, Green"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N43_Green_T_Blue: FA_o_30Rnd_762x39_7N43_Green { ammo = "FA_o_762x39_7N43_T_Blue"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 - Blue Tracer, Green"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N43_Green_T_Orange: FA_o_30Rnd_762x39_7N43_Green { ammo = "FA_o_762x39_7N43_T_Orange"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 - Orange Tracer, Green"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N43_Green_T_IR: FA_o_30Rnd_762x39_7N43_Green { ammo = "FA_o_762x39_7N43_T_IR"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 - IR Tracer, Green"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };

    // =========================================================
    // 7.62x39mm — 7N43 Kremen — BI Enoch 30Rnd Lush
    // =========================================================
    class FA_o_30Rnd_762x39_7N43_Lush: 30Rnd_762x39_AK12_Lush_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 Lush";
        descriptionShort = "7.62x39 7N43 Kremen";
        ammo = "FA_o_762x39_7N43";
        initSpeed = 820;
        mass = 7;
    };
    class FA_o_30Rnd_762x39_7N43_Lush_T_Red: FA_o_30Rnd_762x39_7N43_Lush { ammo = "FA_o_762x39_7N43_T_Red"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 Lush - Red Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N43_Lush_T_Yellow: FA_o_30Rnd_762x39_7N43_Lush { ammo = "FA_o_762x39_7N43_T_Yellow"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 Lush - Yellow Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N43_Lush_T_Green: FA_o_30Rnd_762x39_7N43_Lush { ammo = "FA_o_762x39_7N43_T_Green"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 Lush - Green Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N43_Lush_T_White: FA_o_30Rnd_762x39_7N43_Lush { ammo = "FA_o_762x39_7N43_T_White"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 Lush - White Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N43_Lush_T_Blue: FA_o_30Rnd_762x39_7N43_Lush { ammo = "FA_o_762x39_7N43_T_Blue"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 Lush - Blue Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N43_Lush_T_Orange: FA_o_30Rnd_762x39_7N43_Lush { ammo = "FA_o_762x39_7N43_T_Orange"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 Lush - Orange Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N43_Lush_T_IR: FA_o_30Rnd_762x39_7N43_Lush { ammo = "FA_o_762x39_7N43_T_IR"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 Lush - IR Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };

    // =========================================================
    // 7.62x39mm — 7N43 Kremen — BI Enoch 30Rnd Arid
    // =========================================================
    class FA_o_30Rnd_762x39_7N43_Arid: 30Rnd_762x39_AK12_Arid_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 - Arid";
        descriptionShort = "7.62x39 7N43 Kremen";
        ammo = "FA_o_762x39_7N43";
        initSpeed = 820;
        mass = 7;
    };
    class FA_o_30Rnd_762x39_7N43_Arid_T_Red: FA_o_30Rnd_762x39_7N43_Arid { ammo = "FA_o_762x39_7N43_T_Red"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 - Red Tracer, Arid"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N43_Arid_T_Yellow: FA_o_30Rnd_762x39_7N43_Arid { ammo = "FA_o_762x39_7N43_T_Yellow"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 - Yellow Tracer, Arid"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N43_Arid_T_Green: FA_o_30Rnd_762x39_7N43_Arid { ammo = "FA_o_762x39_7N43_T_Green"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 - Green Tracer, Arid"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N43_Arid_T_White: FA_o_30Rnd_762x39_7N43_Arid { ammo = "FA_o_762x39_7N43_T_White"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 - White Tracer, Arid"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N43_Arid_T_Blue: FA_o_30Rnd_762x39_7N43_Arid { ammo = "FA_o_762x39_7N43_T_Blue"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 - Blue Tracer, Arid"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N43_Arid_T_Orange: FA_o_30Rnd_762x39_7N43_Arid { ammo = "FA_o_762x39_7N43_T_Orange"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 - Orange Tracer, Arid"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N43_Arid_T_IR: FA_o_30Rnd_762x39_7N43_Arid { ammo = "FA_o_762x39_7N43_T_IR"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 - IR Tracer, Arid"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };

    // =========================================================
    // 7.62x39mm — 7N43 Kremen — Enoch AK-12 base 30Rnd
    // =========================================================
    class FA_o_30Rnd_762x39_7N43_AK12: 30Rnd_762x39_AK12_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 (AK-12)";
        descriptionShort = "7.62x39 7N43 Kremen";
        ammo = "FA_o_762x39_7N43";
        initSpeed = 820;
        mass = 7;
    };
    class FA_o_30Rnd_762x39_7N43_AK12_T_Red: FA_o_30Rnd_762x39_7N43_AK12 { ammo = "FA_o_762x39_7N43_T_Red"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 (AK-12) - Red Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N43_AK12_T_Yellow: FA_o_30Rnd_762x39_7N43_AK12 { ammo = "FA_o_762x39_7N43_T_Yellow"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 (AK-12) - Yellow Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N43_AK12_T_Green: FA_o_30Rnd_762x39_7N43_AK12 { ammo = "FA_o_762x39_7N43_T_Green"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 (AK-12) - Green Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N43_AK12_T_White: FA_o_30Rnd_762x39_7N43_AK12 { ammo = "FA_o_762x39_7N43_T_White"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 (AK-12) - White Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N43_AK12_T_Blue: FA_o_30Rnd_762x39_7N43_AK12 { ammo = "FA_o_762x39_7N43_T_Blue"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 (AK-12) - Blue Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N43_AK12_T_Orange: FA_o_30Rnd_762x39_7N43_AK12 { ammo = "FA_o_762x39_7N43_T_Orange"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 (AK-12) - Orange Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N43_AK12_T_IR: FA_o_30Rnd_762x39_7N43_AK12 { ammo = "FA_o_762x39_7N43_T_IR"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N43 (AK-12) - IR Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };

    // =========================================================
    // 7.62x39mm — 7N43 Kremen — BI vanilla 75Rnd drum
    // =========================================================
    class FA_o_75Rnd_762x39_7N43: 75Rnd_762x39_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 75Rnd 7.62x39mm 7N43";
        descriptionShort = "7.62x39 7N43 Kremen";
        ammo = "FA_o_762x39_7N43";
        initSpeed = 820;
        mass = 20;
    };
    class FA_o_75Rnd_762x39_7N43_T_Red: FA_o_75Rnd_762x39_7N43 { ammo = "FA_o_762x39_7N43_T_Red"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N43 - Red Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N43_T_Yellow: FA_o_75Rnd_762x39_7N43 { ammo = "FA_o_762x39_7N43_T_Yellow"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N43 - Yellow Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N43_T_Green: FA_o_75Rnd_762x39_7N43 { ammo = "FA_o_762x39_7N43_T_Green"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N43 - Green Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N43_T_White: FA_o_75Rnd_762x39_7N43 { ammo = "FA_o_762x39_7N43_T_White"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N43 - White Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N43_T_Blue: FA_o_75Rnd_762x39_7N43 { ammo = "FA_o_762x39_7N43_T_Blue"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N43 - Blue Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N43_T_Orange: FA_o_75Rnd_762x39_7N43 { ammo = "FA_o_762x39_7N43_T_Orange"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N43 - Orange Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N43_T_IR: FA_o_75Rnd_762x39_7N43 { ammo = "FA_o_762x39_7N43_T_IR"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N43 - IR Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };

    // =========================================================
    // 7.62x39mm — 7N43 Kremen — BI Enoch 75Rnd drum
    // =========================================================
    class FA_o_75Rnd_762x39_7N43_AK12: 75rnd_762x39_AK12_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 75Rnd 7.62x39mm 7N43 (AK-12)";
        descriptionShort = "7.62x39 7N43 Kremen";
        ammo = "FA_o_762x39_7N43";
        initSpeed = 820;
        mass = 20;
    };
    class FA_o_75Rnd_762x39_7N43_AK12_T_Red: FA_o_75Rnd_762x39_7N43_AK12 { ammo = "FA_o_762x39_7N43_T_Red"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N43 (AK-12) - Red Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N43_AK12_T_Yellow: FA_o_75Rnd_762x39_7N43_AK12 { ammo = "FA_o_762x39_7N43_T_Yellow"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N43 (AK-12) - Yellow Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N43_AK12_T_Green: FA_o_75Rnd_762x39_7N43_AK12 { ammo = "FA_o_762x39_7N43_T_Green"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N43 (AK-12) - Green Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N43_AK12_T_White: FA_o_75Rnd_762x39_7N43_AK12 { ammo = "FA_o_762x39_7N43_T_White"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N43 (AK-12) - White Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N43_AK12_T_Blue: FA_o_75Rnd_762x39_7N43_AK12 { ammo = "FA_o_762x39_7N43_T_Blue"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N43 (AK-12) - Blue Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N43_AK12_T_Orange: FA_o_75Rnd_762x39_7N43_AK12 { ammo = "FA_o_762x39_7N43_T_Orange"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N43 (AK-12) - Orange Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N43_AK12_T_IR: FA_o_75Rnd_762x39_7N43_AK12 { ammo = "FA_o_762x39_7N43_T_IR"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N43 (AK-12) - IR Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };

    // =========================================================
    // 7.62x39mm — 7N43 Kremen — BI Enoch 75Rnd Lush
    // =========================================================
    class FA_o_75Rnd_762x39_7N43_Lush: 75rnd_762x39_AK12_Lush_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 75Rnd 7.62x39mm 7N43 Lush";
        descriptionShort = "7.62x39 7N43 Kremen";
        ammo = "FA_o_762x39_7N43";
        initSpeed = 820;
        mass = 20;
    };
    class FA_o_75Rnd_762x39_7N43_Lush_T_Red: FA_o_75Rnd_762x39_7N43_Lush { ammo = "FA_o_762x39_7N43_T_Red"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N43 Lush - Red Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N43_Lush_T_Yellow: FA_o_75Rnd_762x39_7N43_Lush { ammo = "FA_o_762x39_7N43_T_Yellow"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N43 Lush - Yellow Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N43_Lush_T_Green: FA_o_75Rnd_762x39_7N43_Lush { ammo = "FA_o_762x39_7N43_T_Green"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N43 Lush - Green Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N43_Lush_T_White: FA_o_75Rnd_762x39_7N43_Lush { ammo = "FA_o_762x39_7N43_T_White"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N43 Lush - White Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N43_Lush_T_Blue: FA_o_75Rnd_762x39_7N43_Lush { ammo = "FA_o_762x39_7N43_T_Blue"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N43 Lush - Blue Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N43_Lush_T_Orange: FA_o_75Rnd_762x39_7N43_Lush { ammo = "FA_o_762x39_7N43_T_Orange"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N43 Lush - Orange Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N43_Lush_T_IR: FA_o_75Rnd_762x39_7N43_Lush { ammo = "FA_o_762x39_7N43_T_IR"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N43 Lush - IR Tracer"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };

    // =========================================================
    // 7.62x39mm — 7N43 Kremen — BI Enoch 75Rnd Arid
    // =========================================================
    class FA_o_75Rnd_762x39_7N43_Arid: 75rnd_762x39_AK12_Arid_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 75Rnd 7.62x39mm 7N43 - Arid";
        descriptionShort = "7.62x39 7N43 Kremen";
        ammo = "FA_o_762x39_7N43";
        initSpeed = 820;
        mass = 20;
    };
    class FA_o_75Rnd_762x39_7N43_Arid_T_Red: FA_o_75Rnd_762x39_7N43_Arid { ammo = "FA_o_762x39_7N43_T_Red"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N43 - Red Tracer, Arid"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N43_Arid_T_Yellow: FA_o_75Rnd_762x39_7N43_Arid { ammo = "FA_o_762x39_7N43_T_Yellow"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N43 - Yellow Tracer, Arid"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N43_Arid_T_Green: FA_o_75Rnd_762x39_7N43_Arid { ammo = "FA_o_762x39_7N43_T_Green"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N43 - Green Tracer, Arid"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N43_Arid_T_White: FA_o_75Rnd_762x39_7N43_Arid { ammo = "FA_o_762x39_7N43_T_White"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N43 - White Tracer, Arid"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N43_Arid_T_Blue: FA_o_75Rnd_762x39_7N43_Arid { ammo = "FA_o_762x39_7N43_T_Blue"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N43 - Blue Tracer, Arid"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N43_Arid_T_Orange: FA_o_75Rnd_762x39_7N43_Arid { ammo = "FA_o_762x39_7N43_T_Orange"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N43 - Orange Tracer, Arid"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N43_Arid_T_IR: FA_o_75Rnd_762x39_7N43_Arid { ammo = "FA_o_762x39_7N43_T_IR"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N43 - IR Tracer, Arid"; descriptionShort = "7.62x39 7N43 Kremen"; tracersEvery = 4; };

    // =========================================================
    // 7.62x39mm — 7N47 Kremen-2 CT — vanilla 30Rnd + 75Rnd
    // =========================================================
    class FA_o_30Rnd_762x39_7N47_CT: 30Rnd_762x39_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT";
        descriptionShort = "7.62x39 7N47 Kremen-2 CT";
        ammo = "FA_o_762x39_7N47_CT";
        initSpeed = 845;
        mass = 7;
    };
    class FA_o_30Rnd_762x39_7N47_CT_T_Red: FA_o_30Rnd_762x39_7N47_CT { ammo = "FA_o_762x39_7N47_CT_T_Red"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT - Red Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N47_CT_T_Yellow: FA_o_30Rnd_762x39_7N47_CT { ammo = "FA_o_762x39_7N47_CT_T_Yellow"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT - Yellow Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N47_CT_T_Green: FA_o_30Rnd_762x39_7N47_CT { ammo = "FA_o_762x39_7N47_CT_T_Green"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT - Green Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N47_CT_T_White: FA_o_30Rnd_762x39_7N47_CT { ammo = "FA_o_762x39_7N47_CT_T_White"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT - White Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N47_CT_T_Blue: FA_o_30Rnd_762x39_7N47_CT { ammo = "FA_o_762x39_7N47_CT_T_Blue"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT - Blue Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N47_CT_T_Orange: FA_o_30Rnd_762x39_7N47_CT { ammo = "FA_o_762x39_7N47_CT_T_Orange"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT - Orange Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N47_CT_T_IR: FA_o_30Rnd_762x39_7N47_CT { ammo = "FA_o_762x39_7N47_CT_T_IR"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT - IR Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };

    class FA_o_75Rnd_762x39_7N47_CT: 75Rnd_762x39_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 75Rnd 7.62x39mm 7N47 CT";
        descriptionShort = "7.62x39 7N47 Kremen-2 CT";
        ammo = "FA_o_762x39_7N47_CT";
        initSpeed = 845;
        mass = 20;
    };
    class FA_o_75Rnd_762x39_7N47_CT_T_Red: FA_o_75Rnd_762x39_7N47_CT { ammo = "FA_o_762x39_7N47_CT_T_Red"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N47 CT - Red Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N47_CT_T_Yellow: FA_o_75Rnd_762x39_7N47_CT { ammo = "FA_o_762x39_7N47_CT_T_Yellow"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N47 CT - Yellow Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N47_CT_T_Green: FA_o_75Rnd_762x39_7N47_CT { ammo = "FA_o_762x39_7N47_CT_T_Green"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N47 CT - Green Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N47_CT_T_White: FA_o_75Rnd_762x39_7N47_CT { ammo = "FA_o_762x39_7N47_CT_T_White"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N47 CT - White Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N47_CT_T_Blue: FA_o_75Rnd_762x39_7N47_CT { ammo = "FA_o_762x39_7N47_CT_T_Blue"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N47 CT - Blue Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N47_CT_T_Orange: FA_o_75Rnd_762x39_7N47_CT { ammo = "FA_o_762x39_7N47_CT_T_Orange"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N47 CT - Orange Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N47_CT_T_IR: FA_o_75Rnd_762x39_7N47_CT { ammo = "FA_o_762x39_7N47_CT_T_IR"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N47 CT - IR Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };

    // =========================================================
    // 7.62x39mm — 7U4 Tishina-2 Sub — vanilla 30Rnd
    // =========================================================
    class FA_o_30Rnd_762x39_7U4_Sub: 30Rnd_762x39_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub";
        descriptionShort = "7.62x39 7U4 Tishina-2 SubAP";
        ammo = "FA_o_762x39_7U4_Sub";
        initSpeed = 300;
        mass = 8;
    };
    class FA_o_30Rnd_762x39_7U4_Sub_T_Red: FA_o_30Rnd_762x39_7U4_Sub { ammo = "FA_o_762x39_7U4_Sub_T_Red"; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub - Red Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7U4_Sub_T_Yellow: FA_o_30Rnd_762x39_7U4_Sub { ammo = "FA_o_762x39_7U4_Sub_T_Yellow"; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub - Yellow Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7U4_Sub_T_Green: FA_o_30Rnd_762x39_7U4_Sub { ammo = "FA_o_762x39_7U4_Sub_T_Green"; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub - Green Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7U4_Sub_T_White: FA_o_30Rnd_762x39_7U4_Sub { ammo = "FA_o_762x39_7U4_Sub_T_White"; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub - White Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7U4_Sub_T_Blue: FA_o_30Rnd_762x39_7U4_Sub { ammo = "FA_o_762x39_7U4_Sub_T_Blue"; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub - Blue Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7U4_Sub_T_Orange: FA_o_30Rnd_762x39_7U4_Sub { ammo = "FA_o_762x39_7U4_Sub_T_Orange"; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub - Orange Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7U4_Sub_T_IR: FA_o_30Rnd_762x39_7U4_Sub { ammo = "FA_o_762x39_7U4_Sub_T_IR"; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub - IR Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };

    // =========================================================
    // 7.62x54R — 150Rnd_762x54_Box (PKM/PKP)
    // =========================================================
    class FA_o_150Rnd_762x54_Box: 150Rnd_762x54_Box { author = QAUTHOR; displayName = "[JMSB] 150Rnd 7.62x54mmR (Box)"; descriptionShort = "7.62x54R Ball HV"; ammo = "FA_o_762x54R_Ball_HV"; initSpeed = 850; };
    class FA_o_150Rnd_762x54_Box_T_Red : 150Rnd_762x54_Box { author = QAUTHOR; displayName = "[JMSB] 150Rnd 7.62x54mmR (Box) - Red Tracer"; descriptionShort = "7.62x54R Ball HV"; ammo = "FA_o_762x54R_Ball_HV_T_Red"; initSpeed = 855; tracersEvery = 4; };
    class FA_o_150Rnd_762x54_Box_T_Yellow : 150Rnd_762x54_Box { author = QAUTHOR; displayName = "[JMSB] 150Rnd 7.62x54mmR (Box) - Yellow Tracer"; descriptionShort = "7.62x54R Ball HV"; ammo = "FA_o_762x54R_Ball_HV_T_Yellow"; initSpeed = 855; tracersEvery = 4; };
    class FA_o_150Rnd_762x54_Box_T_Green : 150Rnd_762x54_Box { author = QAUTHOR; displayName = "[JMSB] 150Rnd 7.62x54mmR (Box) - Green Tracer"; descriptionShort = "7.62x54R Ball HV"; ammo = "FA_o_762x54R_Ball_HV_T_Green"; initSpeed = 855; tracersEvery = 4; };
    class FA_o_150Rnd_762x54_Box_T_White : 150Rnd_762x54_Box { author = QAUTHOR; displayName = "[JMSB] 150Rnd 7.62x54mmR (Box) - White Tracer"; descriptionShort = "7.62x54R Ball HV"; ammo = "FA_o_762x54R_Ball_HV_T_White"; initSpeed = 855; tracersEvery = 4; };
    class FA_o_150Rnd_762x54_Box_T_Blue : 150Rnd_762x54_Box { author = QAUTHOR; displayName = "[JMSB] 150Rnd 7.62x54mmR (Box) - Blue Tracer"; descriptionShort = "7.62x54R Ball HV"; ammo = "FA_o_762x54R_Ball_HV_T_Blue"; initSpeed = 855; tracersEvery = 4; };
    class FA_o_150Rnd_762x54_Box_T_Orange : 150Rnd_762x54_Box { author = QAUTHOR; displayName = "[JMSB] 150Rnd 7.62x54mmR (Box) - Orange Tracer"; descriptionShort = "7.62x54R Ball HV"; ammo = "FA_o_762x54R_Ball_HV_T_Orange"; initSpeed = 855; tracersEvery = 4; };
    class FA_o_150Rnd_762x54_Box_T_IR : 150Rnd_762x54_Box { author = QAUTHOR; displayName = "[JMSB] 150Rnd 7.62x54mmR (Box) - IR Tracer"; descriptionShort = "7.62x54R Ball HV"; ammo = "FA_o_762x54R_Ball_HV_T_IR"; initSpeed = 855; tracersEvery = 4; };

    // =========================================================
    // ACE 7.62x51 HK417 — ACE_20Rnd_762x51_M993_AP_Mag
    // =========================================================
    class FA_b_ACE_20Rnd_762x51_M993_AP: ACE_20Rnd_762x51_M993_AP_Mag { author = QAUTHOR; displayName = "[JMSB] 20Rnd 7.62mm M993 AP"; descriptionShort = "M80A2 HV"; ammo = "FA_b_762_M80A2_HV"; initSpeed = 833; };
    class FA_b_ACE_20Rnd_762x51_M993_AP_T_Red : ACE_20Rnd_762x51_M993_AP_Mag { author = QAUTHOR; displayName = "[JMSB] 20Rnd 7.62mm M993 AP - Red Tracer"; descriptionShort = "M80A2 HV"; ammo = "FA_b_762_M80A2_HV_T_Red"; initSpeed = 940; tracersEvery = 4; };
    class FA_b_ACE_20Rnd_762x51_M993_AP_T_Yellow : ACE_20Rnd_762x51_M993_AP_Mag { author = QAUTHOR; displayName = "[JMSB] 20Rnd 7.62mm M993 AP - Yellow Tracer"; descriptionShort = "M80A2 HV"; ammo = "FA_b_762_M80A2_HV_T_Yellow"; initSpeed = 940; tracersEvery = 4; };
    class FA_b_ACE_20Rnd_762x51_M993_AP_T_Green : ACE_20Rnd_762x51_M993_AP_Mag { author = QAUTHOR; displayName = "[JMSB] 20Rnd 7.62mm M993 AP - Green Tracer"; descriptionShort = "M80A2 HV"; ammo = "FA_b_762_M80A2_HV_T_Green"; initSpeed = 940; tracersEvery = 4; };
    class FA_b_ACE_20Rnd_762x51_M993_AP_T_White : ACE_20Rnd_762x51_M993_AP_Mag { author = QAUTHOR; displayName = "[JMSB] 20Rnd 7.62mm M993 AP - White Tracer"; descriptionShort = "M80A2 HV"; ammo = "FA_b_762_M80A2_HV_T_White"; initSpeed = 940; tracersEvery = 4; };
    class FA_b_ACE_20Rnd_762x51_M993_AP_T_Blue : ACE_20Rnd_762x51_M993_AP_Mag { author = QAUTHOR; displayName = "[JMSB] 20Rnd 7.62mm M993 AP - Blue Tracer"; descriptionShort = "M80A2 HV"; ammo = "FA_b_762_M80A2_HV_T_Blue"; initSpeed = 940; tracersEvery = 4; };
    class FA_b_ACE_20Rnd_762x51_M993_AP_T_Orange : ACE_20Rnd_762x51_M993_AP_Mag { author = QAUTHOR; displayName = "[JMSB] 20Rnd 7.62mm M993 AP - Orange Tracer"; descriptionShort = "M80A2 HV"; ammo = "FA_b_762_M80A2_HV_T_Orange"; initSpeed = 940; tracersEvery = 4; };
    class FA_b_ACE_20Rnd_762x51_M993_AP_T_IR : ACE_20Rnd_762x51_M993_AP_Mag { author = QAUTHOR; displayName = "[JMSB] 20Rnd 7.62mm M993 AP - IR Tracer"; descriptionShort = "M80A2 HV"; ammo = "FA_b_762_M80A2_HV_T_IR"; initSpeed = 940; tracersEvery = 4; };

    // =========================================================
    // ACE 7.62x51 HK417 — ACE_10Rnd_762x51_Mag_SD
    // =========================================================
    class FA_b_ACE_10Rnd_762x51_SD: ACE_10Rnd_762x51_Mag_SD { author = QAUTHOR; displayName = "[JMSB] 10Rnd 7.62mm SD"; descriptionShort = "M80A2 HV"; ammo = "FA_b_762_M80A2_HV"; initSpeed = 833; };
    class FA_b_ACE_10Rnd_762x51_SD_T_Red : ACE_10Rnd_762x51_Mag_SD { author = QAUTHOR; displayName = "[JMSB] 10Rnd 7.62mm SD - Red Tracer"; descriptionShort = "M80A2 HV"; ammo = "FA_b_762_M80A2_HV_T_Red"; initSpeed = 940; tracersEvery = 4; };
    class FA_b_ACE_10Rnd_762x51_SD_T_Yellow : ACE_10Rnd_762x51_Mag_SD { author = QAUTHOR; displayName = "[JMSB] 10Rnd 7.62mm SD - Yellow Tracer"; descriptionShort = "M80A2 HV"; ammo = "FA_b_762_M80A2_HV_T_Yellow"; initSpeed = 940; tracersEvery = 4; };
    class FA_b_ACE_10Rnd_762x51_SD_T_Green : ACE_10Rnd_762x51_Mag_SD { author = QAUTHOR; displayName = "[JMSB] 10Rnd 7.62mm SD - Green Tracer"; descriptionShort = "M80A2 HV"; ammo = "FA_b_762_M80A2_HV_T_Green"; initSpeed = 940; tracersEvery = 4; };
    class FA_b_ACE_10Rnd_762x51_SD_T_White : ACE_10Rnd_762x51_Mag_SD { author = QAUTHOR; displayName = "[JMSB] 10Rnd 7.62mm SD - White Tracer"; descriptionShort = "M80A2 HV"; ammo = "FA_b_762_M80A2_HV_T_White"; initSpeed = 940; tracersEvery = 4; };
    class FA_b_ACE_10Rnd_762x51_SD_T_Blue : ACE_10Rnd_762x51_Mag_SD { author = QAUTHOR; displayName = "[JMSB] 10Rnd 7.62mm SD - Blue Tracer"; descriptionShort = "M80A2 HV"; ammo = "FA_b_762_M80A2_HV_T_Blue"; initSpeed = 940; tracersEvery = 4; };
    class FA_b_ACE_10Rnd_762x51_SD_T_Orange : ACE_10Rnd_762x51_Mag_SD { author = QAUTHOR; displayName = "[JMSB] 10Rnd 7.62mm SD - Orange Tracer"; descriptionShort = "M80A2 HV"; ammo = "FA_b_762_M80A2_HV_T_Orange"; initSpeed = 940; tracersEvery = 4; };
    class FA_b_ACE_10Rnd_762x51_SD_T_IR : ACE_10Rnd_762x51_Mag_SD { author = QAUTHOR; displayName = "[JMSB] 10Rnd 7.62mm SD - IR Tracer"; descriptionShort = "M80A2 HV"; ammo = "FA_b_762_M80A2_HV_T_IR"; initSpeed = 940; tracersEvery = 4; };


    // =========================================================
    // 6.5x39 — 100Rnd_65x39_caseless_black_mag
    // =========================================================
    class FA_b_100Rnd_65x39_caseless_black_mag : 100Rnd_65x39_caseless_black_mag { author = QAUTHOR; displayName = "[JMSB] 100Rnd 6.5mm - Black"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR"; initSpeed = 950; };
    class FA_b_100Rnd_65x39_caseless_black_mag_T_Red : 100Rnd_65x39_caseless_black_mag { author = QAUTHOR; displayName = "[JMSB] 100Rnd 6.5mm - Red Tracer, Black"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Red"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_100Rnd_65x39_caseless_black_mag_T_Yellow : 100Rnd_65x39_caseless_black_mag { author = QAUTHOR; displayName = "[JMSB] 100Rnd 6.5mm - Yellow Tracer, Black"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Yellow"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_100Rnd_65x39_caseless_black_mag_T_Green : 100Rnd_65x39_caseless_black_mag { author = QAUTHOR; displayName = "[JMSB] 100Rnd 6.5mm - Green Tracer, Black"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Green"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_100Rnd_65x39_caseless_black_mag_T_White : 100Rnd_65x39_caseless_black_mag { author = QAUTHOR; displayName = "[JMSB] 100Rnd 6.5mm - White Tracer, Black"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_White"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_100Rnd_65x39_caseless_black_mag_T_Blue : 100Rnd_65x39_caseless_black_mag { author = QAUTHOR; displayName = "[JMSB] 100Rnd 6.5mm - Blue Tracer, Black"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Blue"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_100Rnd_65x39_caseless_black_mag_T_Orange : 100Rnd_65x39_caseless_black_mag { author = QAUTHOR; displayName = "[JMSB] 100Rnd 6.5mm - Orange Tracer, Black"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Orange"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_100Rnd_65x39_caseless_black_mag_T_IR : 100Rnd_65x39_caseless_black_mag { author = QAUTHOR; displayName = "[JMSB] 100Rnd 6.5mm - IR Tracer, Black"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_IR"; initSpeed = 950; tracersEvery = 4; };

    // =========================================================
    // 6.5x39 — 100Rnd_65x39_caseless_khaki_mag
    // =========================================================
    class FA_b_100Rnd_65x39_caseless_khaki_mag : 100Rnd_65x39_caseless_khaki_mag { author = QAUTHOR; displayName = "[JMSB] 100Rnd 6.5mm - Khaki"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR"; initSpeed = 950; };
    class FA_b_100Rnd_65x39_caseless_khaki_mag_T_Red : 100Rnd_65x39_caseless_khaki_mag { author = QAUTHOR; displayName = "[JMSB] 100Rnd 6.5mm - Red Tracer, Khaki"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Red"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_100Rnd_65x39_caseless_khaki_mag_T_Yellow : 100Rnd_65x39_caseless_khaki_mag { author = QAUTHOR; displayName = "[JMSB] 100Rnd 6.5mm - Yellow Tracer, Khaki"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Yellow"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_100Rnd_65x39_caseless_khaki_mag_T_Green : 100Rnd_65x39_caseless_khaki_mag { author = QAUTHOR; displayName = "[JMSB] 100Rnd 6.5mm - Green Tracer, Khaki"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Green"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_100Rnd_65x39_caseless_khaki_mag_T_White : 100Rnd_65x39_caseless_khaki_mag { author = QAUTHOR; displayName = "[JMSB] 100Rnd 6.5mm - White Tracer, Khaki"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_White"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_100Rnd_65x39_caseless_khaki_mag_T_Blue : 100Rnd_65x39_caseless_khaki_mag { author = QAUTHOR; displayName = "[JMSB] 100Rnd 6.5mm - Blue Tracer, Khaki"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Blue"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_100Rnd_65x39_caseless_khaki_mag_T_Orange : 100Rnd_65x39_caseless_khaki_mag { author = QAUTHOR; displayName = "[JMSB] 100Rnd 6.5mm - Orange Tracer, Khaki"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Orange"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_100Rnd_65x39_caseless_khaki_mag_T_IR : 100Rnd_65x39_caseless_khaki_mag { author = QAUTHOR; displayName = "[JMSB] 100Rnd 6.5mm - IR Tracer, Khaki"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_IR"; initSpeed = 950; tracersEvery = 4; };

    // =========================================================
    // 6.5x39 — 100Rnd_65x39_caseless_mag
    // =========================================================
    class FA_b_100Rnd_65x39_caseless_mag : 100Rnd_65x39_caseless_mag { author = QAUTHOR; displayName = "[JMSB] 100Rnd 6.5mm"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR"; initSpeed = 950; };
    class FA_b_100Rnd_65x39_caseless_mag_T_Red : 100Rnd_65x39_caseless_mag { author = QAUTHOR; displayName = "[JMSB] 100Rnd 6.5mm - Red Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Red"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_100Rnd_65x39_caseless_mag_T_Yellow : 100Rnd_65x39_caseless_mag { author = QAUTHOR; displayName = "[JMSB] 100Rnd 6.5mm - Yellow Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Yellow"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_100Rnd_65x39_caseless_mag_T_Green : 100Rnd_65x39_caseless_mag { author = QAUTHOR; displayName = "[JMSB] 100Rnd 6.5mm - Green Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Green"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_100Rnd_65x39_caseless_mag_T_White : 100Rnd_65x39_caseless_mag { author = QAUTHOR; displayName = "[JMSB] 100Rnd 6.5mm - White Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_White"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_100Rnd_65x39_caseless_mag_T_Blue : 100Rnd_65x39_caseless_mag { author = QAUTHOR; displayName = "[JMSB] 100Rnd 6.5mm - Blue Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Blue"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_100Rnd_65x39_caseless_mag_T_Orange : 100Rnd_65x39_caseless_mag { author = QAUTHOR; displayName = "[JMSB] 100Rnd 6.5mm - Orange Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Orange"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_100Rnd_65x39_caseless_mag_T_IR : 100Rnd_65x39_caseless_mag { author = QAUTHOR; displayName = "[JMSB] 100Rnd 6.5mm - IR Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_IR"; initSpeed = 950; tracersEvery = 4; };

    // =========================================================
    // 6.5x39 — 200Rnd_65x39_cased_Box
    // =========================================================
    class FA_b_200Rnd_65x39_cased_Box : 200Rnd_65x39_cased_Box { author = QAUTHOR; displayName = "[JMSB] 200Rnd 6.5mm (Box)"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR"; initSpeed = 950; };
    class FA_b_200Rnd_65x39_cased_Box_T_Red : 200Rnd_65x39_cased_Box { author = QAUTHOR; displayName = "[JMSB] 200Rnd 6.5mm (Box) - Red Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Red"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_200Rnd_65x39_cased_Box_T_Yellow : 200Rnd_65x39_cased_Box { author = QAUTHOR; displayName = "[JMSB] 200Rnd 6.5mm (Box) - Yellow Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Yellow"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_200Rnd_65x39_cased_Box_T_Green : 200Rnd_65x39_cased_Box { author = QAUTHOR; displayName = "[JMSB] 200Rnd 6.5mm (Box) - Green Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Green"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_200Rnd_65x39_cased_Box_T_White : 200Rnd_65x39_cased_Box { author = QAUTHOR; displayName = "[JMSB] 200Rnd 6.5mm (Box) - White Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_White"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_200Rnd_65x39_cased_Box_T_Blue : 200Rnd_65x39_cased_Box { author = QAUTHOR; displayName = "[JMSB] 200Rnd 6.5mm (Box) - Blue Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Blue"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_200Rnd_65x39_cased_Box_T_Orange : 200Rnd_65x39_cased_Box { author = QAUTHOR; displayName = "[JMSB] 200Rnd 6.5mm (Box) - Orange Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Orange"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_200Rnd_65x39_cased_Box_T_IR : 200Rnd_65x39_cased_Box { author = QAUTHOR; displayName = "[JMSB] 200Rnd 6.5mm (Box) - IR Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_IR"; initSpeed = 950; tracersEvery = 4; };

    // =========================================================
    // 6.5x39 — 2000Rnd_65x39_Belt
    // =========================================================
    class FA_b_2000Rnd_65x39_Belt_T_Red : 2000Rnd_65x39_Belt { author = QAUTHOR; displayName = "[JMSB] 2000Rnd 6.5mm (Belt) - Red Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Red"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_2000Rnd_65x39_Belt_T_Yellow : 2000Rnd_65x39_Belt { author = QAUTHOR; displayName = "[JMSB] 2000Rnd 6.5mm (Belt) - Yellow Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Yellow"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_2000Rnd_65x39_Belt_T_Green : 2000Rnd_65x39_Belt { author = QAUTHOR; displayName = "[JMSB] 2000Rnd 6.5mm (Belt) - Green Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Green"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_2000Rnd_65x39_Belt_T_White : 2000Rnd_65x39_Belt { author = QAUTHOR; displayName = "[JMSB] 2000Rnd 6.5mm (Belt) - White Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_White"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_2000Rnd_65x39_Belt_T_Blue : 2000Rnd_65x39_Belt { author = QAUTHOR; displayName = "[JMSB] 2000Rnd 6.5mm (Belt) - Blue Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Blue"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_2000Rnd_65x39_Belt_T_Orange : 2000Rnd_65x39_Belt { author = QAUTHOR; displayName = "[JMSB] 2000Rnd 6.5mm (Belt) - Orange Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Orange"; initSpeed = 950; tracersEvery = 4; };

    // =========================================================
    // 6.5x39 — 1000Rnd_65x39_Belt
    // =========================================================
    class FA_b_1000Rnd_65x39_Belt_T_Red : 1000Rnd_65x39_Belt { author = QAUTHOR; displayName = "[JMSB] 1000Rnd 6.5mm (Belt) - Red Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Red"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_1000Rnd_65x39_Belt_T_Yellow : 1000Rnd_65x39_Belt { author = QAUTHOR; displayName = "[JMSB] 1000Rnd 6.5mm (Belt) - Yellow Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Yellow"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_1000Rnd_65x39_Belt_T_Green : 1000Rnd_65x39_Belt { author = QAUTHOR; displayName = "[JMSB] 1000Rnd 6.5mm (Belt) - Green Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Green"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_1000Rnd_65x39_Belt_T_White : 1000Rnd_65x39_Belt { author = QAUTHOR; displayName = "[JMSB] 1000Rnd 6.5mm (Belt) - White Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_White"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_1000Rnd_65x39_Belt_T_Blue : 1000Rnd_65x39_Belt { author = QAUTHOR; displayName = "[JMSB] 1000Rnd 6.5mm (Belt) - Blue Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Blue"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_1000Rnd_65x39_Belt_T_Orange : 1000Rnd_65x39_Belt { author = QAUTHOR; displayName = "[JMSB] 1000Rnd 6.5mm (Belt) - Orange Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Orange"; initSpeed = 950; tracersEvery = 4; };

    // =========================================================
    // 6.5x39 — 200Rnd_65x39_Belt
    // =========================================================
    class FA_b_200Rnd_65x39_Belt_T_Red : 200Rnd_65x39_Belt { author = QAUTHOR; displayName = "[JMSB] 200Rnd 6.5mm (Belt) - Red Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Red"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_200Rnd_65x39_Belt_T_Yellow : 200Rnd_65x39_Belt { author = QAUTHOR; displayName = "[JMSB] 200Rnd 6.5mm (Belt) - Yellow Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Yellow"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_200Rnd_65x39_Belt_T_Green : 200Rnd_65x39_Belt { author = QAUTHOR; displayName = "[JMSB] 200Rnd 6.5mm (Belt) - Green Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Green"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_200Rnd_65x39_Belt_T_White : 200Rnd_65x39_Belt { author = QAUTHOR; displayName = "[JMSB] 200Rnd 6.5mm (Belt) - White Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_White"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_200Rnd_65x39_Belt_T_Blue : 200Rnd_65x39_Belt { author = QAUTHOR; displayName = "[JMSB] 200Rnd 6.5mm (Belt) - Blue Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Blue"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_200Rnd_65x39_Belt_T_Orange : 200Rnd_65x39_Belt { author = QAUTHOR; displayName = "[JMSB] 200Rnd 6.5mm (Belt) - Orange Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Orange"; initSpeed = 950; tracersEvery = 4; };


    // =========================================================
    // 6.5x39 — 500Rnd_65x39_Belt
    // =========================================================
    class FA_b_500Rnd_65x39_Belt_T_Red : 500Rnd_65x39_Belt { author = QAUTHOR; displayName = "[JMSB] 500Rnd 6.5mm (Belt) - Red Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Red"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_500Rnd_65x39_Belt_T_Yellow : 500Rnd_65x39_Belt { author = QAUTHOR; displayName = "[JMSB] 500Rnd 6.5mm (Belt) - Yellow Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Yellow"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_500Rnd_65x39_Belt_T_Green : 500Rnd_65x39_Belt { author = QAUTHOR; displayName = "[JMSB] 500Rnd 6.5mm (Belt) - Green Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Green"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_500Rnd_65x39_Belt_T_White : 500Rnd_65x39_Belt { author = QAUTHOR; displayName = "[JMSB] 500Rnd 6.5mm (Belt) - White Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_White"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_500Rnd_65x39_Belt_T_Blue : 500Rnd_65x39_Belt { author = QAUTHOR; displayName = "[JMSB] 500Rnd 6.5mm (Belt) - Blue Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Blue"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_500Rnd_65x39_Belt_T_Orange : 500Rnd_65x39_Belt { author = QAUTHOR; displayName = "[JMSB] 500Rnd 6.5mm (Belt) - Orange Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Orange"; initSpeed = 950; tracersEvery = 4; };

    // =========================================================
    // 6.5x39 — PylonWeapon_2000Rnd_65x39_belt
    // =========================================================
    class FA_b_PylonWeapon_2000Rnd_65x39_belt_T_Red : PylonWeapon_2000Rnd_65x39_belt { author = QAUTHOR; displayName = "[JMSB] 2000Rnd 6.5mm (Belt) - PylonWeapon - Red Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Red"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_PylonWeapon_2000Rnd_65x39_belt_T_Yellow : PylonWeapon_2000Rnd_65x39_belt { author = QAUTHOR; displayName = "[JMSB] 2000Rnd 6.5mm (Belt) - PylonWeapon - Yellow Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Yellow"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_PylonWeapon_2000Rnd_65x39_belt_T_Green : PylonWeapon_2000Rnd_65x39_belt { author = QAUTHOR; displayName = "[JMSB] 2000Rnd 6.5mm (Belt) - PylonWeapon - Green Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Green"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_PylonWeapon_2000Rnd_65x39_belt_T_White : PylonWeapon_2000Rnd_65x39_belt { author = QAUTHOR; displayName = "[JMSB] 2000Rnd 6.5mm (Belt) - PylonWeapon - White Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_White"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_PylonWeapon_2000Rnd_65x39_belt_T_Blue : PylonWeapon_2000Rnd_65x39_belt { author = QAUTHOR; displayName = "[JMSB] 2000Rnd 6.5mm (Belt) - PylonWeapon - Blue Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Blue"; initSpeed = 950; tracersEvery = 4; };
    class FA_b_PylonWeapon_2000Rnd_65x39_belt_T_Orange : PylonWeapon_2000Rnd_65x39_belt { author = QAUTHOR; displayName = "[JMSB] 2000Rnd 6.5mm (Belt) - PylonWeapon - Orange Tracer"; descriptionShort = "Mk330 EPR"; ammo = "FA_b_65_EPR_T_Orange"; initSpeed = 950; tracersEvery = 4; };

    // =========================================================
    // .338 LM — 10Rnd_338_Mag (vanilla MAR-10)
    // =========================================================
    class FA_b_10Rnd_338_Mk371_250gr_T_Red : 10Rnd_338_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd .338 Mk371 250gr - Red Tracer"; descriptionShort = "Mk371 250gr"; ammo = "FA_b_338_Mk371_250gr_T_Red"; initSpeed = 905; tracersEvery = 4; };
    class FA_b_10Rnd_338_Mk371_250gr_T_Yellow : 10Rnd_338_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd .338 Mk371 250gr - Yellow Tracer"; descriptionShort = "Mk371 250gr"; ammo = "FA_b_338_Mk371_250gr_T_Yellow"; initSpeed = 905; tracersEvery = 4; };
    class FA_b_10Rnd_338_Mk371_250gr_T_Green : 10Rnd_338_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd .338 Mk371 250gr - Green Tracer"; descriptionShort = "Mk371 250gr"; ammo = "FA_b_338_Mk371_250gr_T_Green"; initSpeed = 905; tracersEvery = 4; };
    class FA_b_10Rnd_338_Mk371_250gr_T_White : 10Rnd_338_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd .338 Mk371 250gr - White Tracer"; descriptionShort = "Mk371 250gr"; ammo = "FA_b_338_Mk371_250gr_T_White"; initSpeed = 905; tracersEvery = 4; };
    class FA_b_10Rnd_338_Mk371_250gr_T_Blue : 10Rnd_338_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd .338 Mk371 250gr - Blue Tracer"; descriptionShort = "Mk371 250gr"; ammo = "FA_b_338_Mk371_250gr_T_Blue"; initSpeed = 905; tracersEvery = 4; };
    class FA_b_10Rnd_338_Mk371_250gr_T_Orange : 10Rnd_338_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd .338 Mk371 250gr - Orange Tracer"; descriptionShort = "Mk371 250gr"; ammo = "FA_b_338_Mk371_250gr_T_Orange"; initSpeed = 905; tracersEvery = 4; };
    class FA_b_10Rnd_338_Mk371_250gr_T_IR : 10Rnd_338_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd .338 Mk371 250gr - IR Tracer"; descriptionShort = "Mk371 250gr"; ammo = "FA_b_338_Mk371_250gr_T_IR"; initSpeed = 905; tracersEvery = 4; };
    class FA_b_10Rnd_338_Mk371_285gr_T_Red : 10Rnd_338_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd .338 Mk371 285gr - Red Tracer"; descriptionShort = "Mk371 285gr"; ammo = "FA_b_338_Mk371_285gr_T_Red"; initSpeed = 870; tracersEvery = 4; };
    class FA_b_10Rnd_338_Mk371_285gr_T_Yellow : 10Rnd_338_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd .338 Mk371 285gr - Yellow Tracer"; descriptionShort = "Mk371 285gr"; ammo = "FA_b_338_Mk371_285gr_T_Yellow"; initSpeed = 870; tracersEvery = 4; };
    class FA_b_10Rnd_338_Mk371_285gr_T_Green : 10Rnd_338_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd .338 Mk371 285gr - Green Tracer"; descriptionShort = "Mk371 285gr"; ammo = "FA_b_338_Mk371_285gr_T_Green"; initSpeed = 870; tracersEvery = 4; };
    class FA_b_10Rnd_338_Mk371_285gr_T_White : 10Rnd_338_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd .338 Mk371 285gr - White Tracer"; descriptionShort = "Mk371 285gr"; ammo = "FA_b_338_Mk371_285gr_T_White"; initSpeed = 870; tracersEvery = 4; };
    class FA_b_10Rnd_338_Mk371_285gr_T_Blue : 10Rnd_338_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd .338 Mk371 285gr - Blue Tracer"; descriptionShort = "Mk371 285gr"; ammo = "FA_b_338_Mk371_285gr_T_Blue"; initSpeed = 870; tracersEvery = 4; };
    class FA_b_10Rnd_338_Mk371_285gr_T_Orange : 10Rnd_338_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd .338 Mk371 285gr - Orange Tracer"; descriptionShort = "Mk371 285gr"; ammo = "FA_b_338_Mk371_285gr_T_Orange"; initSpeed = 870; tracersEvery = 4; };
    class FA_b_10Rnd_338_Mk371_285gr_T_IR : 10Rnd_338_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd .338 Mk371 285gr - IR Tracer"; descriptionShort = "Mk371 285gr"; ammo = "FA_b_338_Mk371_285gr_T_IR"; initSpeed = 870; tracersEvery = 4; };
    class FA_b_10Rnd_338_Mk371_300gr_T_Red : 10Rnd_338_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd .338 Mk371 300gr - Red Tracer"; descriptionShort = "Mk371 300gr"; ammo = "FA_b_338_Mk371_300gr_T_Red"; initSpeed = 830; tracersEvery = 4; };
    class FA_b_10Rnd_338_Mk371_300gr_T_Yellow : 10Rnd_338_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd .338 Mk371 300gr - Yellow Tracer"; descriptionShort = "Mk371 300gr"; ammo = "FA_b_338_Mk371_300gr_T_Yellow"; initSpeed = 830; tracersEvery = 4; };
    class FA_b_10Rnd_338_Mk371_300gr_T_Green : 10Rnd_338_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd .338 Mk371 300gr - Green Tracer"; descriptionShort = "Mk371 300gr"; ammo = "FA_b_338_Mk371_300gr_T_Green"; initSpeed = 830; tracersEvery = 4; };
    class FA_b_10Rnd_338_Mk371_300gr_T_White : 10Rnd_338_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd .338 Mk371 300gr - White Tracer"; descriptionShort = "Mk371 300gr"; ammo = "FA_b_338_Mk371_300gr_T_White"; initSpeed = 830; tracersEvery = 4; };
    class FA_b_10Rnd_338_Mk371_300gr_T_Blue : 10Rnd_338_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd .338 Mk371 300gr - Blue Tracer"; descriptionShort = "Mk371 300gr"; ammo = "FA_b_338_Mk371_300gr_T_Blue"; initSpeed = 830; tracersEvery = 4; };
    class FA_b_10Rnd_338_Mk371_300gr_T_Orange : 10Rnd_338_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd .338 Mk371 300gr - Orange Tracer"; descriptionShort = "Mk371 300gr"; ammo = "FA_b_338_Mk371_300gr_T_Orange"; initSpeed = 830; tracersEvery = 4; };
    class FA_b_10Rnd_338_Mk371_300gr_T_IR : 10Rnd_338_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd .338 Mk371 300gr - IR Tracer"; descriptionShort = "Mk371 300gr"; ammo = "FA_b_338_Mk371_300gr_T_IR"; initSpeed = 830; tracersEvery = 4; };

    // =========================================================
    // 9.3x64 Type 40 — 10Rnd_93x64_Mag (Cyrus)
    // =========================================================
    class FA_o_10Rnd_93x64_Type40: 10Rnd_93x64_Mag {
        author = QAUTHOR;
        displayName = "[JMSB] 10Rnd 9.3mm Type40";
        descriptionShort = "Type40";
        ammo = "FA_o_93x64_Type40";
        initSpeed = 882;
        mass = 9;
    };
    class FA_o_10Rnd_93x64_Type40_T_Red    : 10Rnd_93x64_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd 9.3mm Type40 - Red Tracer";    descriptionShort = "Type40";    ammo = "FA_o_93x64_Type40_T_Red";    initSpeed = 882; tracersEvery = 4; };
    class FA_o_10Rnd_93x64_Type40_T_Yellow : 10Rnd_93x64_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd 9.3mm Type40 - Yellow Tracer"; descriptionShort = "Type40"; ammo = "FA_o_93x64_Type40_T_Yellow"; initSpeed = 882; tracersEvery = 4; };
    class FA_o_10Rnd_93x64_Type40_T_Green  : 10Rnd_93x64_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd 9.3mm Type40 - Green Tracer";  descriptionShort = "Type40";  ammo = "FA_o_93x64_Type40_T_Green";  initSpeed = 882; tracersEvery = 4; };
    class FA_o_10Rnd_93x64_Type40_T_White  : 10Rnd_93x64_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd 9.3mm Type40 - White Tracer";  descriptionShort = "Type40";  ammo = "FA_o_93x64_Type40_T_White";  initSpeed = 882; tracersEvery = 4; };
    class FA_o_10Rnd_93x64_Type40_T_Blue   : 10Rnd_93x64_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd 9.3mm Type40 - Blue Tracer";   descriptionShort = "Type40";   ammo = "FA_o_93x64_Type40_T_Blue";   initSpeed = 882; tracersEvery = 4; };
    class FA_o_10Rnd_93x64_Type40_T_Orange : 10Rnd_93x64_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd 9.3mm Type40 - Orange Tracer"; descriptionShort = "Type40"; ammo = "FA_o_93x64_Type40_T_Orange"; initSpeed = 882; tracersEvery = 4; };
    class FA_o_10Rnd_93x64_Type40_T_IR     : 10Rnd_93x64_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd 9.3mm Type40 - IR Tracer";     descriptionShort = "Type40";     ammo = "FA_o_93x64_Type40_T_IR";     initSpeed = 882; tracersEvery = 4; };

    // 9.3x64 Type 40 belt - 150Rnd_93x64_Mag (Navid). Same round as the Cyrus's,
    // belted; the Navid's own muzzle velocity. CSAT Iran's machine gun (2026-08-28).
    class FA_o_150Rnd_93x64_Type40: 150Rnd_93x64_Mag { author = QAUTHOR; displayName = "[JMSB] 150Rnd 9.3mm Type40"; descriptionShort = "Type40"; ammo = "FA_o_93x64_Type40"; initSpeed = 785; };
    class FA_o_150Rnd_93x64_Type40_T_Red    : 150Rnd_93x64_Mag { author = QAUTHOR; displayName = "[JMSB] 150Rnd 9.3mm Type40 - Red Tracer"; descriptionShort = "Type40"; ammo = "FA_o_93x64_Type40_T_Red"; initSpeed = 785; tracersEvery = 3; };
    class FA_o_150Rnd_93x64_Type40_T_Yellow : 150Rnd_93x64_Mag { author = QAUTHOR; displayName = "[JMSB] 150Rnd 9.3mm Type40 - Yellow Tracer"; descriptionShort = "Type40"; ammo = "FA_o_93x64_Type40_T_Yellow"; initSpeed = 785; tracersEvery = 3; };
    class FA_o_150Rnd_93x64_Type40_T_Green  : 150Rnd_93x64_Mag { author = QAUTHOR; displayName = "[JMSB] 150Rnd 9.3mm Type40 - Green Tracer"; descriptionShort = "Type40"; ammo = "FA_o_93x64_Type40_T_Green"; initSpeed = 785; tracersEvery = 3; };
    class FA_o_150Rnd_93x64_Type40_T_White  : 150Rnd_93x64_Mag { author = QAUTHOR; displayName = "[JMSB] 150Rnd 9.3mm Type40 - White Tracer"; descriptionShort = "Type40"; ammo = "FA_o_93x64_Type40_T_White"; initSpeed = 785; tracersEvery = 3; };
    class FA_o_150Rnd_93x64_Type40_T_Blue   : 150Rnd_93x64_Mag { author = QAUTHOR; displayName = "[JMSB] 150Rnd 9.3mm Type40 - Blue Tracer"; descriptionShort = "Type40"; ammo = "FA_o_93x64_Type40_T_Blue"; initSpeed = 785; tracersEvery = 3; };
    class FA_o_150Rnd_93x64_Type40_T_Orange : 150Rnd_93x64_Mag { author = QAUTHOR; displayName = "[JMSB] 150Rnd 9.3mm Type40 - Orange Tracer"; descriptionShort = "Type40"; ammo = "FA_o_93x64_Type40_T_Orange"; initSpeed = 785; tracersEvery = 3; };
    class FA_o_150Rnd_93x64_Type40_T_IR     : 150Rnd_93x64_Mag { author = QAUTHOR; displayName = "[JMSB] 150Rnd 9.3mm Type40 - IR Tracer"; descriptionShort = "Type40"; ammo = "FA_o_93x64_Type40_T_IR"; initSpeed = 785; tracersEvery = 3; };

    // =========================================================
    // .408 Mk240 LRP — 10Rnd_338_Mag body (MAR-10 housing, .408 chambering)
    // =========================================================
    class FA_b_10Rnd_408_Mk240: 10Rnd_338_Mag {
        author = QAUTHOR;
        displayName = "[JMSB] 10Rnd .408 Mk240";
        descriptionShort = "Mk240";
        ammo = "FA_b_408_Mk240";
        count = 7;
        initSpeed = 965;
        mass = 10;
    };
    class FA_b_10Rnd_408_Mk240_T_Red    : 10Rnd_338_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd .408 Mk240 - Red Tracer";    descriptionShort = "Mk240";    ammo = "FA_b_408_Mk240_T_Red";    count = 7; initSpeed = 965; tracersEvery = 4; };
    class FA_b_10Rnd_408_Mk240_T_Yellow : 10Rnd_338_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd .408 Mk240 - Yellow Tracer"; descriptionShort = "Mk240"; ammo = "FA_b_408_Mk240_T_Yellow"; count = 7; initSpeed = 965; tracersEvery = 4; };
    class FA_b_10Rnd_408_Mk240_T_Green  : 10Rnd_338_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd .408 Mk240 - Green Tracer";  descriptionShort = "Mk240";  ammo = "FA_b_408_Mk240_T_Green";  count = 7; initSpeed = 965; tracersEvery = 4; };
    class FA_b_10Rnd_408_Mk240_T_White  : 10Rnd_338_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd .408 Mk240 - White Tracer";  descriptionShort = "Mk240";  ammo = "FA_b_408_Mk240_T_White";  count = 7; initSpeed = 965; tracersEvery = 4; };
    class FA_b_10Rnd_408_Mk240_T_Blue   : 10Rnd_338_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd .408 Mk240 - Blue Tracer";   descriptionShort = "Mk240";   ammo = "FA_b_408_Mk240_T_Blue";   count = 7; initSpeed = 965; tracersEvery = 4; };
    class FA_b_10Rnd_408_Mk240_T_Orange : 10Rnd_338_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd .408 Mk240 - Orange Tracer"; descriptionShort = "Mk240"; ammo = "FA_b_408_Mk240_T_Orange"; count = 7; initSpeed = 965; tracersEvery = 4; };
    class FA_b_10Rnd_408_Mk240_T_IR     : 10Rnd_338_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd .408 Mk240 - IR Tracer";     descriptionShort = "Mk240";     ammo = "FA_b_408_Mk240_T_IR";     count = 7; initSpeed = 965; tracersEvery = 4; };

    // =========================================================
    // 12.7x108 Mk250 LRP — 5Rnd_127x108_Mag (GM6 Lynx)
    // =========================================================
    class FA_b_5Rnd_127x108_Mk250: 5Rnd_127x108_Mag {
        author = QAUTHOR;
        displayName = "[JMSB] 5Rnd 12.7x108mm Mk250";
        descriptionShort = "Mk250";
        ammo = "FA_b_127x108_Mk250";
        initSpeed = 870;
        mass = 15;
    };
    class FA_b_5Rnd_127x108_Mk250_T_Red    : 5Rnd_127x108_Mag { author = QAUTHOR; displayName = "[JMSB] 5Rnd 12.7x108mm Mk250 - Red Tracer";    descriptionShort = "Mk250";    ammo = "FA_b_127x108_Mk250_T_Red";    initSpeed = 870; tracersEvery = 4; };
    class FA_b_5Rnd_127x108_Mk250_T_Yellow : 5Rnd_127x108_Mag { author = QAUTHOR; displayName = "[JMSB] 5Rnd 12.7x108mm Mk250 - Yellow Tracer"; descriptionShort = "Mk250"; ammo = "FA_b_127x108_Mk250_T_Yellow"; initSpeed = 870; tracersEvery = 4; };
    class FA_b_5Rnd_127x108_Mk250_T_Green  : 5Rnd_127x108_Mag { author = QAUTHOR; displayName = "[JMSB] 5Rnd 12.7x108mm Mk250 - Green Tracer";  descriptionShort = "Mk250";  ammo = "FA_b_127x108_Mk250_T_Green";  initSpeed = 870; tracersEvery = 4; };
    class FA_b_5Rnd_127x108_Mk250_T_White  : 5Rnd_127x108_Mag { author = QAUTHOR; displayName = "[JMSB] 5Rnd 12.7x108mm Mk250 - White Tracer";  descriptionShort = "Mk250";  ammo = "FA_b_127x108_Mk250_T_White";  initSpeed = 870; tracersEvery = 4; };
    class FA_b_5Rnd_127x108_Mk250_T_Blue   : 5Rnd_127x108_Mag { author = QAUTHOR; displayName = "[JMSB] 5Rnd 12.7x108mm Mk250 - Blue Tracer";   descriptionShort = "Mk250";   ammo = "FA_b_127x108_Mk250_T_Blue";   initSpeed = 870; tracersEvery = 4; };
    class FA_b_5Rnd_127x108_Mk250_T_Orange : 5Rnd_127x108_Mag { author = QAUTHOR; displayName = "[JMSB] 5Rnd 12.7x108mm Mk250 - Orange Tracer"; descriptionShort = "Mk250"; ammo = "FA_b_127x108_Mk250_T_Orange"; initSpeed = 870; tracersEvery = 4; };
    class FA_b_5Rnd_127x108_Mk250_T_IR     : 5Rnd_127x108_Mag { author = QAUTHOR; displayName = "[JMSB] 5Rnd 12.7x108mm Mk250 - IR Tracer";     descriptionShort = "Mk250";     ammo = "FA_b_127x108_Mk250_T_IR";     initSpeed = 870; tracersEvery = 4; };

    // =========================================================
    // 12.7x108 Mk211 Mod 2 (HEIAP) — 5Rnd_127x108_Mag (GM6 Lynx)
    // =========================================================
    class FA_b_5Rnd_127x108_Mk211Mod2: 5Rnd_127x108_Mag {
        author = QAUTHOR;
        displayName = "[JMSB] 5Rnd 12.7x108mm Mk211Mod2";
        descriptionShort = "Mk211Mod2";
        ammo = "FA_b_127x108_Mk211Mod2";
        initSpeed = 900;
        mass = 15;
    };
    class FA_b_5Rnd_127x108_Mk211Mod2_T_Red    : 5Rnd_127x108_Mag { author = QAUTHOR; displayName = "[JMSB] 5Rnd 12.7x108mm Mk211Mod2 - Red Tracer";    descriptionShort = "Mk211Mod2";    ammo = "FA_b_127x108_Mk211Mod2_T_Red";    initSpeed = 900; tracersEvery = 4; };
    class FA_b_5Rnd_127x108_Mk211Mod2_T_Yellow : 5Rnd_127x108_Mag { author = QAUTHOR; displayName = "[JMSB] 5Rnd 12.7x108mm Mk211Mod2 - Yellow Tracer"; descriptionShort = "Mk211Mod2"; ammo = "FA_b_127x108_Mk211Mod2_T_Yellow"; initSpeed = 900; tracersEvery = 4; };
    class FA_b_5Rnd_127x108_Mk211Mod2_T_Green  : 5Rnd_127x108_Mag { author = QAUTHOR; displayName = "[JMSB] 5Rnd 12.7x108mm Mk211Mod2 - Green Tracer";  descriptionShort = "Mk211Mod2";  ammo = "FA_b_127x108_Mk211Mod2_T_Green";  initSpeed = 900; tracersEvery = 4; };
    class FA_b_5Rnd_127x108_Mk211Mod2_T_White  : 5Rnd_127x108_Mag { author = QAUTHOR; displayName = "[JMSB] 5Rnd 12.7x108mm Mk211Mod2 - White Tracer";  descriptionShort = "Mk211Mod2";  ammo = "FA_b_127x108_Mk211Mod2_T_White";  initSpeed = 900; tracersEvery = 4; };
    class FA_b_5Rnd_127x108_Mk211Mod2_T_Blue   : 5Rnd_127x108_Mag { author = QAUTHOR; displayName = "[JMSB] 5Rnd 12.7x108mm Mk211Mod2 - Blue Tracer";   descriptionShort = "Mk211Mod2";   ammo = "FA_b_127x108_Mk211Mod2_T_Blue";   initSpeed = 900; tracersEvery = 4; };
    class FA_b_5Rnd_127x108_Mk211Mod2_T_Orange : 5Rnd_127x108_Mag { author = QAUTHOR; displayName = "[JMSB] 5Rnd 12.7x108mm Mk211Mod2 - Orange Tracer"; descriptionShort = "Mk211Mod2"; ammo = "FA_b_127x108_Mk211Mod2_T_Orange"; initSpeed = 900; tracersEvery = 4; };
    class FA_b_5Rnd_127x108_Mk211Mod2_T_IR     : 5Rnd_127x108_Mag { author = QAUTHOR; displayName = "[JMSB] 5Rnd 12.7x108mm Mk211Mod2 - IR Tracer";     descriptionShort = "Mk211Mod2";     ammo = "FA_b_127x108_Mk211Mod2_T_IR";     initSpeed = 900; tracersEvery = 4; };

    // =========================================================
    // 12.7x99 (.50 BMG) — Mk258 LRP — 200Rnd belt (Rhino commander HMG et al.)
    // FA's other .50 x99 mags are 5Rnd sniper mags (aegis WF50), not belts.
    // =========================================================
    class FA_b_200Rnd_127x99_Mk258: 200Rnd_127x99_mag_Tracer_Red {
        author = QAUTHOR;
        displayName = "[JMSB] 200Rnd 12.7mm Mk258 - 127x99";
        descriptionShort = "Mk258 LRP";
        ammo = "FA_b_127x99_Mk258_LRP";
        initSpeed = 860;
        tracersEvery = 0;
    };
    class FA_b_200Rnd_127x99_Mk258_T_Red: FA_b_200Rnd_127x99_Mk258 { ammo = "FA_b_127x99_Mk258_LRP_T_Red"; displayName = "[JMSB] 200Rnd 12.7mm Mk258 - 127x99 - Red Tracer"; descriptionShort = "Mk258 LRP"; tracersEvery = 4; };
    class FA_b_200Rnd_127x99_Mk258_T_Yellow: FA_b_200Rnd_127x99_Mk258 { ammo = "FA_b_127x99_Mk258_LRP_T_Yellow"; displayName = "[JMSB] 200Rnd 12.7mm Mk258 - 127x99 - Yellow Tracer"; descriptionShort = "Mk258 LRP"; tracersEvery = 4; };
    class FA_b_200Rnd_127x99_Mk258_T_Green: FA_b_200Rnd_127x99_Mk258 { ammo = "FA_b_127x99_Mk258_LRP_T_Green"; displayName = "[JMSB] 200Rnd 12.7mm Mk258 - 127x99 - Green Tracer"; descriptionShort = "Mk258 LRP"; tracersEvery = 4; };
    class FA_b_200Rnd_127x99_Mk258_T_White: FA_b_200Rnd_127x99_Mk258 { ammo = "FA_b_127x99_Mk258_LRP_T_White"; displayName = "[JMSB] 200Rnd 12.7mm Mk258 - 127x99 - White Tracer"; descriptionShort = "Mk258 LRP"; tracersEvery = 4; };
    class FA_b_200Rnd_127x99_Mk258_T_Blue: FA_b_200Rnd_127x99_Mk258 { ammo = "FA_b_127x99_Mk258_LRP_T_Blue"; displayName = "[JMSB] 200Rnd 12.7mm Mk258 - 127x99 - Blue Tracer"; descriptionShort = "Mk258 LRP"; tracersEvery = 4; };
    class FA_b_200Rnd_127x99_Mk258_T_Orange: FA_b_200Rnd_127x99_Mk258 { ammo = "FA_b_127x99_Mk258_LRP_T_Orange"; displayName = "[JMSB] 200Rnd 12.7mm Mk258 - 127x99 - Orange Tracer"; descriptionShort = "Mk258 LRP"; tracersEvery = 4; };
    class FA_b_200Rnd_127x99_Mk258_T_IR: FA_b_200Rnd_127x99_Mk258 { ammo = "FA_b_127x99_Mk258_LRP_T_IR"; displayName = "[JMSB] 200Rnd 12.7mm Mk258 - 127x99 - IR Tracer"; descriptionShort = "Mk258 LRP"; tracersEvery = 4; };

    // =========================================================
    // 12.7x99 (.50 BMG) — Mk211 Mod 0 HEIAP — 200Rnd belt (Rhino commander HMG et al.)
    // =========================================================
    class FA_b_200Rnd_127x99_Mk211Mod0: 200Rnd_127x99_mag_Tracer_Red {
        author = QAUTHOR;
        displayName = "[JMSB] 200Rnd 12.7mm Mk211Mod0 - 127x99";
        descriptionShort = "Mk211Mod0 AP";
        ammo = "FA_b_127x99_Mk211Mod0_AP";
        initSpeed = 890;
        tracersEvery = 0;
    };
    class FA_b_200Rnd_127x99_Mk211Mod0_T_Red: FA_b_200Rnd_127x99_Mk211Mod0 { ammo = "FA_b_127x99_Mk211Mod0_AP_T_Red"; displayName = "[JMSB] 200Rnd 12.7mm Mk211Mod0 - 127x99 - Red Tracer"; descriptionShort = "Mk211Mod0 AP"; tracersEvery = 4; };
    class FA_b_200Rnd_127x99_Mk211Mod0_T_Yellow: FA_b_200Rnd_127x99_Mk211Mod0 { ammo = "FA_b_127x99_Mk211Mod0_AP_T_Yellow"; displayName = "[JMSB] 200Rnd 12.7mm Mk211Mod0 - 127x99 - Yellow Tracer"; descriptionShort = "Mk211Mod0 AP"; tracersEvery = 4; };
    class FA_b_200Rnd_127x99_Mk211Mod0_T_Green: FA_b_200Rnd_127x99_Mk211Mod0 { ammo = "FA_b_127x99_Mk211Mod0_AP_T_Green"; displayName = "[JMSB] 200Rnd 12.7mm Mk211Mod0 - 127x99 - Green Tracer"; descriptionShort = "Mk211Mod0 AP"; tracersEvery = 4; };
    class FA_b_200Rnd_127x99_Mk211Mod0_T_White: FA_b_200Rnd_127x99_Mk211Mod0 { ammo = "FA_b_127x99_Mk211Mod0_AP_T_White"; displayName = "[JMSB] 200Rnd 12.7mm Mk211Mod0 - 127x99 - White Tracer"; descriptionShort = "Mk211Mod0 AP"; tracersEvery = 4; };
    class FA_b_200Rnd_127x99_Mk211Mod0_T_Blue: FA_b_200Rnd_127x99_Mk211Mod0 { ammo = "FA_b_127x99_Mk211Mod0_AP_T_Blue"; displayName = "[JMSB] 200Rnd 12.7mm Mk211Mod0 - 127x99 - Blue Tracer"; descriptionShort = "Mk211Mod0 AP"; tracersEvery = 4; };
    class FA_b_200Rnd_127x99_Mk211Mod0_T_Orange: FA_b_200Rnd_127x99_Mk211Mod0 { ammo = "FA_b_127x99_Mk211Mod0_AP_T_Orange"; displayName = "[JMSB] 200Rnd 12.7mm Mk211Mod0 - 127x99 - Orange Tracer"; descriptionShort = "Mk211Mod0 AP"; tracersEvery = 4; };
    class FA_b_200Rnd_127x99_Mk211Mod0_T_IR: FA_b_200Rnd_127x99_Mk211Mod0 { ammo = "FA_b_127x99_Mk211Mod0_AP_T_IR"; displayName = "[JMSB] 200Rnd 12.7mm Mk211Mod0 - 127x99 - IR Tracer"; descriptionShort = "Mk211Mod0 AP"; tracersEvery = 4; };

    // =========================================================
    // 5.56x45 — 200Rnd_556x45_Box_F (vanilla MINIMI belt box)
    // =========================================================
    class FA_b_200Rnd_556x45_Box_F: 200Rnd_556x45_Box_F { author = QAUTHOR; displayName = "[JMSB] 200Rnd 5.56mm (Box)"; descriptionShort = "Mk327 HV"; ammo = "FA_b_556_Mk327_HV"; initSpeed = 1000; };
    class FA_b_200Rnd_556x45_Box_F_T_Red : 200Rnd_556x45_Box_F { author = QAUTHOR; displayName = "[JMSB] 200Rnd 5.56mm (Box) - Red Tracer"; descriptionShort = "Mk327 HV"; ammo = "FA_b_556_Mk327_HV_T_Red"; initSpeed = 1000; tracersEvery = 4; };
    class FA_b_200Rnd_556x45_Box_F_T_Yellow : 200Rnd_556x45_Box_F { author = QAUTHOR; displayName = "[JMSB] 200Rnd 5.56mm (Box) - Yellow Tracer"; descriptionShort = "Mk327 HV"; ammo = "FA_b_556_Mk327_HV_T_Yellow"; initSpeed = 1000; tracersEvery = 4; };
    class FA_b_200Rnd_556x45_Box_F_T_Green : 200Rnd_556x45_Box_F { author = QAUTHOR; displayName = "[JMSB] 200Rnd 5.56mm (Box) - Green Tracer"; descriptionShort = "Mk327 HV"; ammo = "FA_b_556_Mk327_HV_T_Green"; initSpeed = 1000; tracersEvery = 4; };
    class FA_b_200Rnd_556x45_Box_F_T_White : 200Rnd_556x45_Box_F { author = QAUTHOR; displayName = "[JMSB] 200Rnd 5.56mm (Box) - White Tracer"; descriptionShort = "Mk327 HV"; ammo = "FA_b_556_Mk327_HV_T_White"; initSpeed = 1000; tracersEvery = 4; };
    class FA_b_200Rnd_556x45_Box_F_T_Blue : 200Rnd_556x45_Box_F { author = QAUTHOR; displayName = "[JMSB] 200Rnd 5.56mm (Box) - Blue Tracer"; descriptionShort = "Mk327 HV"; ammo = "FA_b_556_Mk327_HV_T_Blue"; initSpeed = 1000; tracersEvery = 4; };
    class FA_b_200Rnd_556x45_Box_F_T_Orange : 200Rnd_556x45_Box_F { author = QAUTHOR; displayName = "[JMSB] 200Rnd 5.56mm (Box) - Orange Tracer"; descriptionShort = "Mk327 HV"; ammo = "FA_b_556_Mk327_HV_T_Orange"; initSpeed = 1000; tracersEvery = 4; };
    class FA_b_200Rnd_556x45_Box_F_T_IR : 200Rnd_556x45_Box_F { author = QAUTHOR; displayName = "[JMSB] 200Rnd 5.56mm (Box) - IR Tracer"; descriptionShort = "Mk327 HV"; ammo = "FA_b_556_Mk327_HV_T_IR"; initSpeed = 1000; tracersEvery = 4; };
    // =========================================================
    // 12 Gauge — 2Rnd break-action (Hunter / CBA_12g_2rnds)
    // =========================================================
    class FA_b_2Rnd_12g_No0_Buck: ACE_2Rnd_12Gauge_Pellets_No0_Buck { author = QAUTHOR; displayName = "[JMSB] 2Rnd 12ga No0 Buck"; descriptionShort = "12 Gauge No.0 Buck — 9 pellets 8.4mm"; };
    class FA_b_2Rnd_12g_No1_Buck: ACE_2Rnd_12Gauge_Pellets_No1_Buck { author = QAUTHOR; displayName = "[JMSB] 2Rnd 12ga No1 Buck"; descriptionShort = "12 Gauge No.1 Buck — 12 pellets 7.6mm"; };
    class FA_b_2Rnd_12g_No2_Buck: ACE_2Rnd_12Gauge_Pellets_No2_Buck { author = QAUTHOR; displayName = "[JMSB] 2Rnd 12ga No2 Buck"; descriptionShort = "12 Gauge No.2 Buck — 15 pellets 6.9mm"; };
    class FA_b_2Rnd_12g_No3_Buck: ACE_2Rnd_12Gauge_Pellets_No3_Buck { author = QAUTHOR; displayName = "[JMSB] 2Rnd 12ga No3 Buck"; descriptionShort = "12 Gauge No.3 Buck — 21 pellets 6.4mm"; };
    class FA_b_2Rnd_12g_No4_Buck: ACE_2Rnd_12Gauge_Pellets_No4_Buck { author = QAUTHOR; displayName = "[JMSB] 2Rnd 12ga No4 Buck"; descriptionShort = "12 Gauge No.4 Buck — 27 pellets 6.1mm"; };
    class FA_b_2Rnd_12g_No4_Bird: ACE_2Rnd_12Gauge_Pellets_No4_Bird { author = QAUTHOR; displayName = "[JMSB] 2Rnd 12ga No4 Bird"; descriptionShort = "12 Gauge No.4 Birdshot — fine pellets"; };

    // =========================================================
    // 12 Gauge — 6Rnd tube magazine (UBS / Saiga-type)
    // =========================================================
    class FA_b_6Rnd_12g_No0_Buck: ACE_6Rnd_12Gauge_Pellets_No0_Buck { author = QAUTHOR; displayName = "[JMSB] 6Rnd 12ga No0 Buck"; descriptionShort = "12 Gauge No.0 Buck — 9 pellets 8.4mm"; };
    class FA_b_6Rnd_12g_No1_Buck: ACE_6Rnd_12Gauge_Pellets_No1_Buck { author = QAUTHOR; displayName = "[JMSB] 6Rnd 12ga No1 Buck"; descriptionShort = "12 Gauge No.1 Buck — 12 pellets 7.6mm"; };
    class FA_b_6Rnd_12g_No2_Buck: ACE_6Rnd_12Gauge_Pellets_No2_Buck { author = QAUTHOR; displayName = "[JMSB] 6Rnd 12ga No2 Buck"; descriptionShort = "12 Gauge No.2 Buck — 15 pellets 6.9mm"; };
    class FA_b_6Rnd_12g_No3_Buck: ACE_6Rnd_12Gauge_Pellets_No3_Buck { author = QAUTHOR; displayName = "[JMSB] 6Rnd 12ga No3 Buck"; descriptionShort = "12 Gauge No.3 Buck — 21 pellets 6.4mm"; };
    class FA_b_6Rnd_12g_No4_Buck: ACE_6Rnd_12Gauge_Pellets_No4_Buck { author = QAUTHOR; displayName = "[JMSB] 6Rnd 12ga No4 Buck"; descriptionShort = "12 Gauge No.4 Buck — 27 pellets 6.1mm"; };
    class FA_b_6Rnd_12g_No4_Bird: ACE_6Rnd_12Gauge_Pellets_No4_Bird { author = QAUTHOR; displayName = "[JMSB] 6Rnd 12ga No4 Bird"; descriptionShort = "12 Gauge No.4 Birdshot — fine pellets"; };

    // =========================================================
    // 5.8x42 Ball HV — 30Rnd (Type 115 / CMR-76)
    // =========================================================
    class FA_o_30Rnd_580x42_Ball_HV: 30Rnd_580x42_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 5.8mm Ball HV";
        descriptionShort = "5.8x42mm Ball HV";
        ammo = "FA_o_580_Ball_HV";
        initSpeed = 940;
    };
    class FA_o_30Rnd_580x42_Ball_HV_T_Red    : 30Rnd_580x42_Mag_F { author = QAUTHOR; displayName = "[JMSB] 30Rnd 5.8mm Ball HV - Red Tracer";    descriptionShort = "5.8x42mm Ball HV";    ammo = "FA_o_580_Ball_HV_T_Red";    initSpeed = 940; tracersEvery = 4; };
    class FA_o_30Rnd_580x42_Ball_HV_T_Yellow : 30Rnd_580x42_Mag_F { author = QAUTHOR; displayName = "[JMSB] 30Rnd 5.8mm Ball HV - Yellow Tracer"; descriptionShort = "5.8x42mm Ball HV"; ammo = "FA_o_580_Ball_HV_T_Yellow"; initSpeed = 940; tracersEvery = 4; };
    class FA_o_30Rnd_580x42_Ball_HV_T_Green  : 30Rnd_580x42_Mag_F { author = QAUTHOR; displayName = "[JMSB] 30Rnd 5.8mm Ball HV - Green Tracer";  descriptionShort = "5.8x42mm Ball HV";  ammo = "FA_o_580_Ball_HV_T_Green";  initSpeed = 940; tracersEvery = 4; };
    class FA_o_30Rnd_580x42_Ball_HV_T_White  : 30Rnd_580x42_Mag_F { author = QAUTHOR; displayName = "[JMSB] 30Rnd 5.8mm Ball HV - White Tracer";  descriptionShort = "5.8x42mm Ball HV";  ammo = "FA_o_580_Ball_HV_T_White";  initSpeed = 940; tracersEvery = 4; };
    class FA_o_30Rnd_580x42_Ball_HV_T_Blue   : 30Rnd_580x42_Mag_F { author = QAUTHOR; displayName = "[JMSB] 30Rnd 5.8mm Ball HV - Blue Tracer";   descriptionShort = "5.8x42mm Ball HV";   ammo = "FA_o_580_Ball_HV_T_Blue";   initSpeed = 940; tracersEvery = 4; };
    class FA_o_30Rnd_580x42_Ball_HV_T_Orange : 30Rnd_580x42_Mag_F { author = QAUTHOR; displayName = "[JMSB] 30Rnd 5.8mm Ball HV - Orange Tracer"; descriptionShort = "5.8x42mm Ball HV"; ammo = "FA_o_580_Ball_HV_T_Orange"; initSpeed = 940; tracersEvery = 4; };
    class FA_o_30Rnd_580x42_Ball_HV_T_IR     : 30Rnd_580x42_Mag_F { author = QAUTHOR; displayName = "[JMSB] 30Rnd 5.8mm Ball HV - IR Tracer";     descriptionShort = "5.8x42mm Ball HV";     ammo = "FA_o_580_Ball_HV_T_IR";     initSpeed = 940; tracersEvery = 4; };

    // =========================================================
    // .45 ACP Mk421 SUB-AP — 30Rnd SMG (Vermin)
    // =========================================================
    class FA_b_30Rnd_45ACP_Mk421: 30Rnd_45ACP_Mag_SMG_01 {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd .45 ACP Mk421";
        descriptionShort = "45ACP Mk421 SubAP";
        ammo = "FA_b_45ACP_Mk421_SubAP";
        initSpeed = 290;
        mass = 6;
    };
    class FA_b_30Rnd_45ACP_Mk421_T_Red    : 30Rnd_45ACP_Mag_SMG_01 { author = QAUTHOR; displayName = "[JMSB] 30Rnd .45 ACP Mk421 - Red Tracer";    descriptionShort = "45ACP Mk421 SubAP";    ammo = "FA_b_45ACP_Mk421_SubAP_T_Red";    initSpeed = 290; tracersEvery = 4; };
    class FA_b_30Rnd_45ACP_Mk421_T_Yellow : 30Rnd_45ACP_Mag_SMG_01 { author = QAUTHOR; displayName = "[JMSB] 30Rnd .45 ACP Mk421 - Yellow Tracer"; descriptionShort = "45ACP Mk421 SubAP"; ammo = "FA_b_45ACP_Mk421_SubAP_T_Yellow"; initSpeed = 290; tracersEvery = 4; };
    class FA_b_30Rnd_45ACP_Mk421_T_Green  : 30Rnd_45ACP_Mag_SMG_01 { author = QAUTHOR; displayName = "[JMSB] 30Rnd .45 ACP Mk421 - Green Tracer";  descriptionShort = "45ACP Mk421 SubAP";  ammo = "FA_b_45ACP_Mk421_SubAP_T_Green";  initSpeed = 290; tracersEvery = 4; };
    class FA_b_30Rnd_45ACP_Mk421_T_White  : 30Rnd_45ACP_Mag_SMG_01 { author = QAUTHOR; displayName = "[JMSB] 30Rnd .45 ACP Mk421 - White Tracer";  descriptionShort = "45ACP Mk421 SubAP";  ammo = "FA_b_45ACP_Mk421_SubAP_T_White";  initSpeed = 290; tracersEvery = 4; };
    class FA_b_30Rnd_45ACP_Mk421_T_Blue   : 30Rnd_45ACP_Mag_SMG_01 { author = QAUTHOR; displayName = "[JMSB] 30Rnd .45 ACP Mk421 - Blue Tracer";   descriptionShort = "45ACP Mk421 SubAP";   ammo = "FA_b_45ACP_Mk421_SubAP_T_Blue";   initSpeed = 290; tracersEvery = 4; };
    class FA_b_30Rnd_45ACP_Mk421_T_Orange : 30Rnd_45ACP_Mag_SMG_01 { author = QAUTHOR; displayName = "[JMSB] 30Rnd .45 ACP Mk421 - Orange Tracer"; descriptionShort = "45ACP Mk421 SubAP"; ammo = "FA_b_45ACP_Mk421_SubAP_T_Orange"; initSpeed = 290; tracersEvery = 4; };
    class FA_b_30Rnd_45ACP_Mk421_T_IR     : 30Rnd_45ACP_Mag_SMG_01 { author = QAUTHOR; displayName = "[JMSB] 30Rnd .45 ACP Mk421 - IR Tracer";     descriptionShort = "45ACP Mk421 SubAP";     ammo = "FA_b_45ACP_Mk421_SubAP_T_IR";     initSpeed = 290; tracersEvery = 4; };

    // =========================================================
    // .45 ACP Mk421 SUB-AP — 11Rnd pistol (4-five)
    // =========================================================
    class FA_b_11Rnd_45ACP_Mk421: 11Rnd_45ACP_Mag {
        author = QAUTHOR;
        displayName = "[JMSB] 11Rnd .45 ACP Mk421";
        descriptionShort = "45ACP Mk421 SubAP";
        ammo = "FA_b_45ACP_Mk421_SubAP";
        initSpeed = 280;
        mass = 3;
    };
    class FA_b_11Rnd_45ACP_Mk421_T_Red    : 11Rnd_45ACP_Mag { author = QAUTHOR; displayName = "[JMSB] 11Rnd .45 ACP Mk421 - Red Tracer";    descriptionShort = "45ACP Mk421 SubAP";    ammo = "FA_b_45ACP_Mk421_SubAP_T_Red";    initSpeed = 280; tracersEvery = 4; };
    class FA_b_11Rnd_45ACP_Mk421_T_Yellow : 11Rnd_45ACP_Mag { author = QAUTHOR; displayName = "[JMSB] 11Rnd .45 ACP Mk421 - Yellow Tracer"; descriptionShort = "45ACP Mk421 SubAP"; ammo = "FA_b_45ACP_Mk421_SubAP_T_Yellow"; initSpeed = 280; tracersEvery = 4; };
    class FA_b_11Rnd_45ACP_Mk421_T_Green  : 11Rnd_45ACP_Mag { author = QAUTHOR; displayName = "[JMSB] 11Rnd .45 ACP Mk421 - Green Tracer";  descriptionShort = "45ACP Mk421 SubAP";  ammo = "FA_b_45ACP_Mk421_SubAP_T_Green";  initSpeed = 280; tracersEvery = 4; };
    class FA_b_11Rnd_45ACP_Mk421_T_White  : 11Rnd_45ACP_Mag { author = QAUTHOR; displayName = "[JMSB] 11Rnd .45 ACP Mk421 - White Tracer";  descriptionShort = "45ACP Mk421 SubAP";  ammo = "FA_b_45ACP_Mk421_SubAP_T_White";  initSpeed = 280; tracersEvery = 4; };
    class FA_b_11Rnd_45ACP_Mk421_T_Blue   : 11Rnd_45ACP_Mag { author = QAUTHOR; displayName = "[JMSB] 11Rnd .45 ACP Mk421 - Blue Tracer";   descriptionShort = "45ACP Mk421 SubAP";   ammo = "FA_b_45ACP_Mk421_SubAP_T_Blue";   initSpeed = 280; tracersEvery = 4; };
    class FA_b_11Rnd_45ACP_Mk421_T_Orange : 11Rnd_45ACP_Mag { author = QAUTHOR; displayName = "[JMSB] 11Rnd .45 ACP Mk421 - Orange Tracer"; descriptionShort = "45ACP Mk421 SubAP"; ammo = "FA_b_45ACP_Mk421_SubAP_T_Orange"; initSpeed = 280; tracersEvery = 4; };
    class FA_b_11Rnd_45ACP_Mk421_T_IR     : 11Rnd_45ACP_Mag { author = QAUTHOR; displayName = "[JMSB] 11Rnd .45 ACP Mk421 - IR Tracer";     descriptionShort = "45ACP Mk421 SubAP";     ammo = "FA_b_45ACP_Mk421_SubAP_T_IR";     initSpeed = 280; tracersEvery = 4; };

    // =========================================================
    // Mk389 TBK — 40mm Tungsten Buckshot (UGL / MGL)
    // High initSpeed for a flat, fast pattern effective to ~100 m.
    // =========================================================
    class FA_b_1Rnd_40mm_Mk389_TBK: 1Rnd_HE_Grenade_shell {
        author = QAUTHOR;
        displayName = "[JMSB] 1Rnd 40mm Mk389 TBK";
        descriptionShort = "Mk389 Tungsten Buckshot";
        ammo = "FA_b_40mm_Mk389_TBK";
        initSpeed = 180;
    };
    class FA_b_3Rnd_40mm_Mk389_TBK: 3Rnd_HE_Grenade_shell {
        author = QAUTHOR;
        displayName = "[JMSB] 3Rnd 40mm Mk389 TBK";
        descriptionShort = "Mk389 Tungsten Buckshot";
        ammo = "FA_b_40mm_Mk389_TBK";
        initSpeed = 180;
    };
    #include "CfgMag65_matrix.hpp"
    class FA_b_30Rnd_556_Mk332_AP: 30Rnd_556x45_Stanag { author = QAUTHOR; displayName = "[JMSB] 30Rnd 5.56mm Mk332 AP"; descriptionShort = "Mk332 AP"; ammo = "FA_b_556_Mk332_AP"; initSpeed = 940; };
    class FA_b_30Rnd_556_Mk332_AP_T_Red: FA_b_30Rnd_556_Mk332_AP { ammo = "FA_b_556_Mk332_AP_T_Red"; displayName = "[JMSB] 30Rnd 5.56mm Mk332 AP - Red Tracer"; descriptionShort = "Mk332 AP"; tracersEvery = 4; };
    class FA_b_30Rnd_556_Mk332_AP_T_Yellow: FA_b_30Rnd_556_Mk332_AP { ammo = "FA_b_556_Mk332_AP_T_Yellow"; displayName = "[JMSB] 30Rnd 5.56mm Mk332 AP - Yellow Tracer"; descriptionShort = "Mk332 AP"; tracersEvery = 4; };
    class FA_b_30Rnd_556_Mk332_AP_T_Green: FA_b_30Rnd_556_Mk332_AP { ammo = "FA_b_556_Mk332_AP_T_Green"; displayName = "[JMSB] 30Rnd 5.56mm Mk332 AP - Green Tracer"; descriptionShort = "Mk332 AP"; tracersEvery = 4; };
    class FA_b_30Rnd_556_Mk332_AP_T_White: FA_b_30Rnd_556_Mk332_AP { ammo = "FA_b_556_Mk332_AP_T_White"; displayName = "[JMSB] 30Rnd 5.56mm Mk332 AP - White Tracer"; descriptionShort = "Mk332 AP"; tracersEvery = 4; };
    class FA_b_30Rnd_556_Mk332_AP_T_Blue: FA_b_30Rnd_556_Mk332_AP { ammo = "FA_b_556_Mk332_AP_T_Blue"; displayName = "[JMSB] 30Rnd 5.56mm Mk332 AP - Blue Tracer"; descriptionShort = "Mk332 AP"; tracersEvery = 4; };
    class FA_b_30Rnd_556_Mk332_AP_T_Orange: FA_b_30Rnd_556_Mk332_AP { ammo = "FA_b_556_Mk332_AP_T_Orange"; displayName = "[JMSB] 30Rnd 5.56mm Mk332 AP - Orange Tracer"; descriptionShort = "Mk332 AP"; tracersEvery = 4; };
    class FA_b_30Rnd_556_Mk332_AP_T_IR: FA_b_30Rnd_556_Mk332_AP { ammo = "FA_b_556_Mk332_AP_T_IR"; displayName = "[JMSB] 30Rnd 5.56mm Mk332 AP - IR Tracer"; descriptionShort = "Mk332 AP"; tracersEvery = 4; };
    class FA_b_200Rnd_556x45_Box_F_XM891_CTEP: 200Rnd_556x45_Box_F { author = QAUTHOR; displayName = "[JMSB] 200Rnd 5.56mm XM891 CTEP (Box)"; descriptionShort = "XM891 CTEP"; ammo = "FA_b_556_XM891_CTEP"; initSpeed = 980; };
    class FA_b_200Rnd_556x45_Box_F_XM891_CTEP_T_Red: FA_b_200Rnd_556x45_Box_F_XM891_CTEP { ammo = "FA_b_556_XM891_CTEP_T_Red"; displayName = "[JMSB] 200Rnd 5.56mm XM891 CTEP (Box) - Red Tracer"; descriptionShort = "XM891 CTEP"; tracersEvery = 4; };
    class FA_b_200Rnd_556x45_Box_F_XM891_CTEP_T_Yellow: FA_b_200Rnd_556x45_Box_F_XM891_CTEP { ammo = "FA_b_556_XM891_CTEP_T_Yellow"; displayName = "[JMSB] 200Rnd 5.56mm XM891 CTEP (Box) - Yellow Tracer"; descriptionShort = "XM891 CTEP"; tracersEvery = 4; };
    class FA_b_200Rnd_556x45_Box_F_XM891_CTEP_T_Green: FA_b_200Rnd_556x45_Box_F_XM891_CTEP { ammo = "FA_b_556_XM891_CTEP_T_Green"; displayName = "[JMSB] 200Rnd 5.56mm XM891 CTEP (Box) - Green Tracer"; descriptionShort = "XM891 CTEP"; tracersEvery = 4; };
    class FA_b_200Rnd_556x45_Box_F_XM891_CTEP_T_White: FA_b_200Rnd_556x45_Box_F_XM891_CTEP { ammo = "FA_b_556_XM891_CTEP_T_White"; displayName = "[JMSB] 200Rnd 5.56mm XM891 CTEP (Box) - White Tracer"; descriptionShort = "XM891 CTEP"; tracersEvery = 4; };
    class FA_b_200Rnd_556x45_Box_F_XM891_CTEP_T_Blue: FA_b_200Rnd_556x45_Box_F_XM891_CTEP { ammo = "FA_b_556_XM891_CTEP_T_Blue"; displayName = "[JMSB] 200Rnd 5.56mm XM891 CTEP (Box) - Blue Tracer"; descriptionShort = "XM891 CTEP"; tracersEvery = 4; };
    class FA_b_200Rnd_556x45_Box_F_XM891_CTEP_T_Orange: FA_b_200Rnd_556x45_Box_F_XM891_CTEP { ammo = "FA_b_556_XM891_CTEP_T_Orange"; displayName = "[JMSB] 200Rnd 5.56mm XM891 CTEP (Box) - Orange Tracer"; descriptionShort = "XM891 CTEP"; tracersEvery = 4; };
    class FA_b_200Rnd_556x45_Box_F_XM891_CTEP_T_IR: FA_b_200Rnd_556x45_Box_F_XM891_CTEP { ammo = "FA_b_556_XM891_CTEP_T_IR"; displayName = "[JMSB] 200Rnd 5.56mm XM891 CTEP (Box) - IR Tracer"; descriptionShort = "XM891 CTEP"; tracersEvery = 4; };
    class FA_b_200Rnd_556x45_Box_F_Mk332_AP: 200Rnd_556x45_Box_F { author = QAUTHOR; displayName = "[JMSB] 200Rnd 5.56mm Mk332 AP (Box)"; descriptionShort = "Mk332 AP"; ammo = "FA_b_556_Mk332_AP"; initSpeed = 940; };
    class FA_b_200Rnd_556x45_Box_F_Mk332_AP_T_Red: FA_b_200Rnd_556x45_Box_F_Mk332_AP { ammo = "FA_b_556_Mk332_AP_T_Red"; displayName = "[JMSB] 200Rnd 5.56mm Mk332 AP (Box) - Red Tracer"; descriptionShort = "Mk332 AP"; tracersEvery = 4; };
    class FA_b_200Rnd_556x45_Box_F_Mk332_AP_T_Yellow: FA_b_200Rnd_556x45_Box_F_Mk332_AP { ammo = "FA_b_556_Mk332_AP_T_Yellow"; displayName = "[JMSB] 200Rnd 5.56mm Mk332 AP (Box) - Yellow Tracer"; descriptionShort = "Mk332 AP"; tracersEvery = 4; };
    class FA_b_200Rnd_556x45_Box_F_Mk332_AP_T_Green: FA_b_200Rnd_556x45_Box_F_Mk332_AP { ammo = "FA_b_556_Mk332_AP_T_Green"; displayName = "[JMSB] 200Rnd 5.56mm Mk332 AP (Box) - Green Tracer"; descriptionShort = "Mk332 AP"; tracersEvery = 4; };
    class FA_b_200Rnd_556x45_Box_F_Mk332_AP_T_White: FA_b_200Rnd_556x45_Box_F_Mk332_AP { ammo = "FA_b_556_Mk332_AP_T_White"; displayName = "[JMSB] 200Rnd 5.56mm Mk332 AP (Box) - White Tracer"; descriptionShort = "Mk332 AP"; tracersEvery = 4; };
    class FA_b_200Rnd_556x45_Box_F_Mk332_AP_T_Blue: FA_b_200Rnd_556x45_Box_F_Mk332_AP { ammo = "FA_b_556_Mk332_AP_T_Blue"; displayName = "[JMSB] 200Rnd 5.56mm Mk332 AP (Box) - Blue Tracer"; descriptionShort = "Mk332 AP"; tracersEvery = 4; };
    class FA_b_200Rnd_556x45_Box_F_Mk332_AP_T_Orange: FA_b_200Rnd_556x45_Box_F_Mk332_AP { ammo = "FA_b_556_Mk332_AP_T_Orange"; displayName = "[JMSB] 200Rnd 5.56mm Mk332 AP (Box) - Orange Tracer"; descriptionShort = "Mk332 AP"; tracersEvery = 4; };
    class FA_b_200Rnd_556x45_Box_F_Mk332_AP_T_IR: FA_b_200Rnd_556x45_Box_F_Mk332_AP { ammo = "FA_b_556_Mk332_AP_T_IR"; displayName = "[JMSB] 200Rnd 5.56mm Mk332 AP (Box) - IR Tracer"; descriptionShort = "Mk332 AP"; tracersEvery = 4; };
    class FA_b_ACE_20Rnd_762x51_M993_AP_XM751_CTEP: ACE_20Rnd_762x51_M993_AP_Mag { author = QAUTHOR; displayName = "[JMSB] 20Rnd 7.62mm M993 AP XM751 CTEP"; descriptionShort = "XM751 CTEP"; ammo = "FA_b_762_XM751_CTEP"; initSpeed = 850; };
    class FA_b_ACE_20Rnd_762x51_M993_AP_XM751_CTEP_T_Red: FA_b_ACE_20Rnd_762x51_M993_AP_XM751_CTEP { ammo = "FA_b_762_XM751_CTEP_T_Red"; displayName = "[JMSB] 20Rnd 7.62mm M993 AP XM751 CTEP - Red Tracer"; descriptionShort = "XM751 CTEP"; tracersEvery = 4; };
    class FA_b_ACE_20Rnd_762x51_M993_AP_XM751_CTEP_T_Yellow: FA_b_ACE_20Rnd_762x51_M993_AP_XM751_CTEP { ammo = "FA_b_762_XM751_CTEP_T_Yellow"; displayName = "[JMSB] 20Rnd 7.62mm M993 AP XM751 CTEP - Yellow Tracer"; descriptionShort = "XM751 CTEP"; tracersEvery = 4; };
    class FA_b_ACE_20Rnd_762x51_M993_AP_XM751_CTEP_T_Green: FA_b_ACE_20Rnd_762x51_M993_AP_XM751_CTEP { ammo = "FA_b_762_XM751_CTEP_T_Green"; displayName = "[JMSB] 20Rnd 7.62mm M993 AP XM751 CTEP - Green Tracer"; descriptionShort = "XM751 CTEP"; tracersEvery = 4; };
    class FA_b_ACE_20Rnd_762x51_M993_AP_XM751_CTEP_T_White: FA_b_ACE_20Rnd_762x51_M993_AP_XM751_CTEP { ammo = "FA_b_762_XM751_CTEP_T_White"; displayName = "[JMSB] 20Rnd 7.62mm M993 AP XM751 CTEP - White Tracer"; descriptionShort = "XM751 CTEP"; tracersEvery = 4; };
    class FA_b_ACE_20Rnd_762x51_M993_AP_XM751_CTEP_T_Blue: FA_b_ACE_20Rnd_762x51_M993_AP_XM751_CTEP { ammo = "FA_b_762_XM751_CTEP_T_Blue"; displayName = "[JMSB] 20Rnd 7.62mm M993 AP XM751 CTEP - Blue Tracer"; descriptionShort = "XM751 CTEP"; tracersEvery = 4; };
    class FA_b_ACE_20Rnd_762x51_M993_AP_XM751_CTEP_T_Orange: FA_b_ACE_20Rnd_762x51_M993_AP_XM751_CTEP { ammo = "FA_b_762_XM751_CTEP_T_Orange"; displayName = "[JMSB] 20Rnd 7.62mm M993 AP XM751 CTEP - Orange Tracer"; descriptionShort = "XM751 CTEP"; tracersEvery = 4; };
    class FA_b_ACE_20Rnd_762x51_M993_AP_XM751_CTEP_T_IR: FA_b_ACE_20Rnd_762x51_M993_AP_XM751_CTEP { ammo = "FA_b_762_XM751_CTEP_T_IR"; displayName = "[JMSB] 20Rnd 7.62mm M993 AP XM751 CTEP - IR Tracer"; descriptionShort = "XM751 CTEP"; tracersEvery = 4; };
    class FA_b_ACE_10Rnd_762x51_SD_XM751_CTEP: ACE_10Rnd_762x51_Mag_SD { author = QAUTHOR; displayName = "[JMSB] 10Rnd 7.62mm SD XM751 CTEP"; descriptionShort = "XM751 CTEP"; ammo = "FA_b_762_XM751_CTEP"; initSpeed = 850; };
    class FA_b_ACE_10Rnd_762x51_SD_XM751_CTEP_T_Red: FA_b_ACE_10Rnd_762x51_SD_XM751_CTEP { ammo = "FA_b_762_XM751_CTEP_T_Red"; displayName = "[JMSB] 10Rnd 7.62mm SD XM751 CTEP - Red Tracer"; descriptionShort = "XM751 CTEP"; tracersEvery = 4; };
    class FA_b_ACE_10Rnd_762x51_SD_XM751_CTEP_T_Yellow: FA_b_ACE_10Rnd_762x51_SD_XM751_CTEP { ammo = "FA_b_762_XM751_CTEP_T_Yellow"; displayName = "[JMSB] 10Rnd 7.62mm SD XM751 CTEP - Yellow Tracer"; descriptionShort = "XM751 CTEP"; tracersEvery = 4; };
    class FA_b_ACE_10Rnd_762x51_SD_XM751_CTEP_T_Green: FA_b_ACE_10Rnd_762x51_SD_XM751_CTEP { ammo = "FA_b_762_XM751_CTEP_T_Green"; displayName = "[JMSB] 10Rnd 7.62mm SD XM751 CTEP - Green Tracer"; descriptionShort = "XM751 CTEP"; tracersEvery = 4; };
    class FA_b_ACE_10Rnd_762x51_SD_XM751_CTEP_T_White: FA_b_ACE_10Rnd_762x51_SD_XM751_CTEP { ammo = "FA_b_762_XM751_CTEP_T_White"; displayName = "[JMSB] 10Rnd 7.62mm SD XM751 CTEP - White Tracer"; descriptionShort = "XM751 CTEP"; tracersEvery = 4; };
    class FA_b_ACE_10Rnd_762x51_SD_XM751_CTEP_T_Blue: FA_b_ACE_10Rnd_762x51_SD_XM751_CTEP { ammo = "FA_b_762_XM751_CTEP_T_Blue"; displayName = "[JMSB] 10Rnd 7.62mm SD XM751 CTEP - Blue Tracer"; descriptionShort = "XM751 CTEP"; tracersEvery = 4; };
    class FA_b_ACE_10Rnd_762x51_SD_XM751_CTEP_T_Orange: FA_b_ACE_10Rnd_762x51_SD_XM751_CTEP { ammo = "FA_b_762_XM751_CTEP_T_Orange"; displayName = "[JMSB] 10Rnd 7.62mm SD XM751 CTEP - Orange Tracer"; descriptionShort = "XM751 CTEP"; tracersEvery = 4; };
    class FA_b_ACE_10Rnd_762x51_SD_XM751_CTEP_T_IR: FA_b_ACE_10Rnd_762x51_SD_XM751_CTEP { ammo = "FA_b_762_XM751_CTEP_T_IR"; displayName = "[JMSB] 10Rnd 7.62mm SD XM751 CTEP - IR Tracer"; descriptionShort = "XM751 CTEP"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N47_CT_Green: 30Rnd_762x39_Mag_Green_F { author = QAUTHOR; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT - Green"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; ammo = "FA_o_762x39_7N47_CT"; initSpeed = 800; };
    class FA_o_30Rnd_762x39_7N47_CT_Green_T_Red: FA_o_30Rnd_762x39_7N47_CT_Green { ammo = "FA_o_762x39_7N47_CT_T_Red"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT - Red Tracer, Green"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N47_CT_Green_T_Yellow: FA_o_30Rnd_762x39_7N47_CT_Green { ammo = "FA_o_762x39_7N47_CT_T_Yellow"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT - Yellow Tracer, Green"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N47_CT_Green_T_Green: FA_o_30Rnd_762x39_7N47_CT_Green { ammo = "FA_o_762x39_7N47_CT_T_Green"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT - Green Tracer, Green"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N47_CT_Green_T_White: FA_o_30Rnd_762x39_7N47_CT_Green { ammo = "FA_o_762x39_7N47_CT_T_White"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT - White Tracer, Green"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N47_CT_Green_T_Blue: FA_o_30Rnd_762x39_7N47_CT_Green { ammo = "FA_o_762x39_7N47_CT_T_Blue"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT - Blue Tracer, Green"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N47_CT_Green_T_Orange: FA_o_30Rnd_762x39_7N47_CT_Green { ammo = "FA_o_762x39_7N47_CT_T_Orange"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT - Orange Tracer, Green"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N47_CT_Green_T_IR: FA_o_30Rnd_762x39_7N47_CT_Green { ammo = "FA_o_762x39_7N47_CT_T_IR"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT - IR Tracer, Green"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7U4_Sub_Green: 30Rnd_762x39_Mag_Green_F { author = QAUTHOR; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub - Green"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; ammo = "FA_o_762x39_7U4_Sub"; initSpeed = 290; };
    class FA_o_30Rnd_762x39_7U4_Sub_Green_T_Red: FA_o_30Rnd_762x39_7U4_Sub_Green { ammo = "FA_o_762x39_7U4_Sub_T_Red"; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub - Red Tracer, Green"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7U4_Sub_Green_T_Yellow: FA_o_30Rnd_762x39_7U4_Sub_Green { ammo = "FA_o_762x39_7U4_Sub_T_Yellow"; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub - Yellow Tracer, Green"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7U4_Sub_Green_T_Green: FA_o_30Rnd_762x39_7U4_Sub_Green { ammo = "FA_o_762x39_7U4_Sub_T_Green"; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub - Green Tracer, Green"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7U4_Sub_Green_T_White: FA_o_30Rnd_762x39_7U4_Sub_Green { ammo = "FA_o_762x39_7U4_Sub_T_White"; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub - White Tracer, Green"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7U4_Sub_Green_T_Blue: FA_o_30Rnd_762x39_7U4_Sub_Green { ammo = "FA_o_762x39_7U4_Sub_T_Blue"; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub - Blue Tracer, Green"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7U4_Sub_Green_T_Orange: FA_o_30Rnd_762x39_7U4_Sub_Green { ammo = "FA_o_762x39_7U4_Sub_T_Orange"; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub - Orange Tracer, Green"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7U4_Sub_Green_T_IR: FA_o_30Rnd_762x39_7U4_Sub_Green { ammo = "FA_o_762x39_7U4_Sub_T_IR"; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub - IR Tracer, Green"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N47_CT_Lush: 30Rnd_762x39_AK12_Lush_Mag_F { author = QAUTHOR; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT Lush"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; ammo = "FA_o_762x39_7N47_CT"; initSpeed = 800; };
    class FA_o_30Rnd_762x39_7N47_CT_Lush_T_Red: FA_o_30Rnd_762x39_7N47_CT_Lush { ammo = "FA_o_762x39_7N47_CT_T_Red"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT Lush - Red Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N47_CT_Lush_T_Yellow: FA_o_30Rnd_762x39_7N47_CT_Lush { ammo = "FA_o_762x39_7N47_CT_T_Yellow"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT Lush - Yellow Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N47_CT_Lush_T_Green: FA_o_30Rnd_762x39_7N47_CT_Lush { ammo = "FA_o_762x39_7N47_CT_T_Green"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT Lush - Green Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N47_CT_Lush_T_White: FA_o_30Rnd_762x39_7N47_CT_Lush { ammo = "FA_o_762x39_7N47_CT_T_White"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT Lush - White Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N47_CT_Lush_T_Blue: FA_o_30Rnd_762x39_7N47_CT_Lush { ammo = "FA_o_762x39_7N47_CT_T_Blue"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT Lush - Blue Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N47_CT_Lush_T_Orange: FA_o_30Rnd_762x39_7N47_CT_Lush { ammo = "FA_o_762x39_7N47_CT_T_Orange"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT Lush - Orange Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N47_CT_Lush_T_IR: FA_o_30Rnd_762x39_7N47_CT_Lush { ammo = "FA_o_762x39_7N47_CT_T_IR"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT Lush - IR Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7U4_Sub_Lush: 30Rnd_762x39_AK12_Lush_Mag_F { author = QAUTHOR; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub Lush"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; ammo = "FA_o_762x39_7U4_Sub"; initSpeed = 290; };
    class FA_o_30Rnd_762x39_7U4_Sub_Lush_T_Red: FA_o_30Rnd_762x39_7U4_Sub_Lush { ammo = "FA_o_762x39_7U4_Sub_T_Red"; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub Lush - Red Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7U4_Sub_Lush_T_Yellow: FA_o_30Rnd_762x39_7U4_Sub_Lush { ammo = "FA_o_762x39_7U4_Sub_T_Yellow"; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub Lush - Yellow Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7U4_Sub_Lush_T_Green: FA_o_30Rnd_762x39_7U4_Sub_Lush { ammo = "FA_o_762x39_7U4_Sub_T_Green"; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub Lush - Green Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7U4_Sub_Lush_T_White: FA_o_30Rnd_762x39_7U4_Sub_Lush { ammo = "FA_o_762x39_7U4_Sub_T_White"; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub Lush - White Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7U4_Sub_Lush_T_Blue: FA_o_30Rnd_762x39_7U4_Sub_Lush { ammo = "FA_o_762x39_7U4_Sub_T_Blue"; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub Lush - Blue Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7U4_Sub_Lush_T_Orange: FA_o_30Rnd_762x39_7U4_Sub_Lush { ammo = "FA_o_762x39_7U4_Sub_T_Orange"; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub Lush - Orange Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7U4_Sub_Lush_T_IR: FA_o_30Rnd_762x39_7U4_Sub_Lush { ammo = "FA_o_762x39_7U4_Sub_T_IR"; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub Lush - IR Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N47_CT_Arid: 30Rnd_762x39_AK12_Arid_Mag_F { author = QAUTHOR; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT - Arid"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; ammo = "FA_o_762x39_7N47_CT"; initSpeed = 800; };
    class FA_o_30Rnd_762x39_7N47_CT_Arid_T_Red: FA_o_30Rnd_762x39_7N47_CT_Arid { ammo = "FA_o_762x39_7N47_CT_T_Red"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT - Red Tracer, Arid"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N47_CT_Arid_T_Yellow: FA_o_30Rnd_762x39_7N47_CT_Arid { ammo = "FA_o_762x39_7N47_CT_T_Yellow"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT - Yellow Tracer, Arid"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N47_CT_Arid_T_Green: FA_o_30Rnd_762x39_7N47_CT_Arid { ammo = "FA_o_762x39_7N47_CT_T_Green"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT - Green Tracer, Arid"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N47_CT_Arid_T_White: FA_o_30Rnd_762x39_7N47_CT_Arid { ammo = "FA_o_762x39_7N47_CT_T_White"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT - White Tracer, Arid"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N47_CT_Arid_T_Blue: FA_o_30Rnd_762x39_7N47_CT_Arid { ammo = "FA_o_762x39_7N47_CT_T_Blue"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT - Blue Tracer, Arid"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N47_CT_Arid_T_Orange: FA_o_30Rnd_762x39_7N47_CT_Arid { ammo = "FA_o_762x39_7N47_CT_T_Orange"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT - Orange Tracer, Arid"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N47_CT_Arid_T_IR: FA_o_30Rnd_762x39_7N47_CT_Arid { ammo = "FA_o_762x39_7N47_CT_T_IR"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT - IR Tracer, Arid"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7U4_Sub_Arid: 30Rnd_762x39_AK12_Arid_Mag_F { author = QAUTHOR; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub - Arid"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; ammo = "FA_o_762x39_7U4_Sub"; initSpeed = 290; };
    class FA_o_30Rnd_762x39_7U4_Sub_Arid_T_Red: FA_o_30Rnd_762x39_7U4_Sub_Arid { ammo = "FA_o_762x39_7U4_Sub_T_Red"; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub - Red Tracer, Arid"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7U4_Sub_Arid_T_Yellow: FA_o_30Rnd_762x39_7U4_Sub_Arid { ammo = "FA_o_762x39_7U4_Sub_T_Yellow"; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub - Yellow Tracer, Arid"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7U4_Sub_Arid_T_Green: FA_o_30Rnd_762x39_7U4_Sub_Arid { ammo = "FA_o_762x39_7U4_Sub_T_Green"; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub - Green Tracer, Arid"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7U4_Sub_Arid_T_White: FA_o_30Rnd_762x39_7U4_Sub_Arid { ammo = "FA_o_762x39_7U4_Sub_T_White"; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub - White Tracer, Arid"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7U4_Sub_Arid_T_Blue: FA_o_30Rnd_762x39_7U4_Sub_Arid { ammo = "FA_o_762x39_7U4_Sub_T_Blue"; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub - Blue Tracer, Arid"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7U4_Sub_Arid_T_Orange: FA_o_30Rnd_762x39_7U4_Sub_Arid { ammo = "FA_o_762x39_7U4_Sub_T_Orange"; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub - Orange Tracer, Arid"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7U4_Sub_Arid_T_IR: FA_o_30Rnd_762x39_7U4_Sub_Arid { ammo = "FA_o_762x39_7U4_Sub_T_IR"; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub - IR Tracer, Arid"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N47_CT_AK12: 30Rnd_762x39_AK12_Mag_F { author = QAUTHOR; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT (AK-12)"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; ammo = "FA_o_762x39_7N47_CT"; initSpeed = 800; };
    class FA_o_30Rnd_762x39_7N47_CT_AK12_T_Red: FA_o_30Rnd_762x39_7N47_CT_AK12 { ammo = "FA_o_762x39_7N47_CT_T_Red"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT (AK-12) - Red Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N47_CT_AK12_T_Yellow: FA_o_30Rnd_762x39_7N47_CT_AK12 { ammo = "FA_o_762x39_7N47_CT_T_Yellow"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT (AK-12) - Yellow Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N47_CT_AK12_T_Green: FA_o_30Rnd_762x39_7N47_CT_AK12 { ammo = "FA_o_762x39_7N47_CT_T_Green"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT (AK-12) - Green Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N47_CT_AK12_T_White: FA_o_30Rnd_762x39_7N47_CT_AK12 { ammo = "FA_o_762x39_7N47_CT_T_White"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT (AK-12) - White Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N47_CT_AK12_T_Blue: FA_o_30Rnd_762x39_7N47_CT_AK12 { ammo = "FA_o_762x39_7N47_CT_T_Blue"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT (AK-12) - Blue Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N47_CT_AK12_T_Orange: FA_o_30Rnd_762x39_7N47_CT_AK12 { ammo = "FA_o_762x39_7N47_CT_T_Orange"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT (AK-12) - Orange Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7N47_CT_AK12_T_IR: FA_o_30Rnd_762x39_7N47_CT_AK12 { ammo = "FA_o_762x39_7N47_CT_T_IR"; displayName = "[JMSB] 30Rnd 7.62x39mm 7N47 CT (AK-12) - IR Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7U4_Sub_AK12: 30Rnd_762x39_AK12_Mag_F { author = QAUTHOR; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub (AK-12)"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; ammo = "FA_o_762x39_7U4_Sub"; initSpeed = 290; };
    class FA_o_30Rnd_762x39_7U4_Sub_AK12_T_Red: FA_o_30Rnd_762x39_7U4_Sub_AK12 { ammo = "FA_o_762x39_7U4_Sub_T_Red"; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub (AK-12) - Red Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7U4_Sub_AK12_T_Yellow: FA_o_30Rnd_762x39_7U4_Sub_AK12 { ammo = "FA_o_762x39_7U4_Sub_T_Yellow"; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub (AK-12) - Yellow Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7U4_Sub_AK12_T_Green: FA_o_30Rnd_762x39_7U4_Sub_AK12 { ammo = "FA_o_762x39_7U4_Sub_T_Green"; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub (AK-12) - Green Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7U4_Sub_AK12_T_White: FA_o_30Rnd_762x39_7U4_Sub_AK12 { ammo = "FA_o_762x39_7U4_Sub_T_White"; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub (AK-12) - White Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7U4_Sub_AK12_T_Blue: FA_o_30Rnd_762x39_7U4_Sub_AK12 { ammo = "FA_o_762x39_7U4_Sub_T_Blue"; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub (AK-12) - Blue Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7U4_Sub_AK12_T_Orange: FA_o_30Rnd_762x39_7U4_Sub_AK12 { ammo = "FA_o_762x39_7U4_Sub_T_Orange"; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub (AK-12) - Orange Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_30Rnd_762x39_7U4_Sub_AK12_T_IR: FA_o_30Rnd_762x39_7U4_Sub_AK12 { ammo = "FA_o_762x39_7U4_Sub_T_IR"; displayName = "[JMSB] 30Rnd 7.62x39mm 7U4 Sub (AK-12) - IR Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7U4_Sub: 75Rnd_762x39_Mag_F { author = QAUTHOR; displayName = "[JMSB] 75Rnd 7.62x39mm 7U4 Sub"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; ammo = "FA_o_762x39_7U4_Sub"; initSpeed = 290; };
    class FA_o_75Rnd_762x39_7U4_Sub_T_Red: FA_o_75Rnd_762x39_7U4_Sub { ammo = "FA_o_762x39_7U4_Sub_T_Red"; displayName = "[JMSB] 75Rnd 7.62x39mm 7U4 Sub - Red Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7U4_Sub_T_Yellow: FA_o_75Rnd_762x39_7U4_Sub { ammo = "FA_o_762x39_7U4_Sub_T_Yellow"; displayName = "[JMSB] 75Rnd 7.62x39mm 7U4 Sub - Yellow Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7U4_Sub_T_Green: FA_o_75Rnd_762x39_7U4_Sub { ammo = "FA_o_762x39_7U4_Sub_T_Green"; displayName = "[JMSB] 75Rnd 7.62x39mm 7U4 Sub - Green Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7U4_Sub_T_White: FA_o_75Rnd_762x39_7U4_Sub { ammo = "FA_o_762x39_7U4_Sub_T_White"; displayName = "[JMSB] 75Rnd 7.62x39mm 7U4 Sub - White Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7U4_Sub_T_Blue: FA_o_75Rnd_762x39_7U4_Sub { ammo = "FA_o_762x39_7U4_Sub_T_Blue"; displayName = "[JMSB] 75Rnd 7.62x39mm 7U4 Sub - Blue Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7U4_Sub_T_Orange: FA_o_75Rnd_762x39_7U4_Sub { ammo = "FA_o_762x39_7U4_Sub_T_Orange"; displayName = "[JMSB] 75Rnd 7.62x39mm 7U4 Sub - Orange Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7U4_Sub_T_IR: FA_o_75Rnd_762x39_7U4_Sub { ammo = "FA_o_762x39_7U4_Sub_T_IR"; displayName = "[JMSB] 75Rnd 7.62x39mm 7U4 Sub - IR Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N47_CT_AK12: 75rnd_762x39_AK12_Mag_F { author = QAUTHOR; displayName = "[JMSB] 75Rnd 7.62x39mm 7N47 CT (AK-12)"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; ammo = "FA_o_762x39_7N47_CT"; initSpeed = 800; };
    class FA_o_75Rnd_762x39_7N47_CT_AK12_T_Red: FA_o_75Rnd_762x39_7N47_CT_AK12 { ammo = "FA_o_762x39_7N47_CT_T_Red"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N47 CT (AK-12) - Red Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N47_CT_AK12_T_Yellow: FA_o_75Rnd_762x39_7N47_CT_AK12 { ammo = "FA_o_762x39_7N47_CT_T_Yellow"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N47 CT (AK-12) - Yellow Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N47_CT_AK12_T_Green: FA_o_75Rnd_762x39_7N47_CT_AK12 { ammo = "FA_o_762x39_7N47_CT_T_Green"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N47 CT (AK-12) - Green Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N47_CT_AK12_T_White: FA_o_75Rnd_762x39_7N47_CT_AK12 { ammo = "FA_o_762x39_7N47_CT_T_White"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N47 CT (AK-12) - White Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N47_CT_AK12_T_Blue: FA_o_75Rnd_762x39_7N47_CT_AK12 { ammo = "FA_o_762x39_7N47_CT_T_Blue"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N47 CT (AK-12) - Blue Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N47_CT_AK12_T_Orange: FA_o_75Rnd_762x39_7N47_CT_AK12 { ammo = "FA_o_762x39_7N47_CT_T_Orange"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N47 CT (AK-12) - Orange Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N47_CT_AK12_T_IR: FA_o_75Rnd_762x39_7N47_CT_AK12 { ammo = "FA_o_762x39_7N47_CT_T_IR"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N47 CT (AK-12) - IR Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7U4_Sub_AK12: 75rnd_762x39_AK12_Mag_F { author = QAUTHOR; displayName = "[JMSB] 75Rnd 7.62x39mm 7U4 Sub (AK-12)"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; ammo = "FA_o_762x39_7U4_Sub"; initSpeed = 290; };
    class FA_o_75Rnd_762x39_7U4_Sub_AK12_T_Red: FA_o_75Rnd_762x39_7U4_Sub_AK12 { ammo = "FA_o_762x39_7U4_Sub_T_Red"; displayName = "[JMSB] 75Rnd 7.62x39mm 7U4 Sub (AK-12) - Red Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7U4_Sub_AK12_T_Yellow: FA_o_75Rnd_762x39_7U4_Sub_AK12 { ammo = "FA_o_762x39_7U4_Sub_T_Yellow"; displayName = "[JMSB] 75Rnd 7.62x39mm 7U4 Sub (AK-12) - Yellow Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7U4_Sub_AK12_T_Green: FA_o_75Rnd_762x39_7U4_Sub_AK12 { ammo = "FA_o_762x39_7U4_Sub_T_Green"; displayName = "[JMSB] 75Rnd 7.62x39mm 7U4 Sub (AK-12) - Green Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7U4_Sub_AK12_T_White: FA_o_75Rnd_762x39_7U4_Sub_AK12 { ammo = "FA_o_762x39_7U4_Sub_T_White"; displayName = "[JMSB] 75Rnd 7.62x39mm 7U4 Sub (AK-12) - White Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7U4_Sub_AK12_T_Blue: FA_o_75Rnd_762x39_7U4_Sub_AK12 { ammo = "FA_o_762x39_7U4_Sub_T_Blue"; displayName = "[JMSB] 75Rnd 7.62x39mm 7U4 Sub (AK-12) - Blue Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7U4_Sub_AK12_T_Orange: FA_o_75Rnd_762x39_7U4_Sub_AK12 { ammo = "FA_o_762x39_7U4_Sub_T_Orange"; displayName = "[JMSB] 75Rnd 7.62x39mm 7U4 Sub (AK-12) - Orange Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7U4_Sub_AK12_T_IR: FA_o_75Rnd_762x39_7U4_Sub_AK12 { ammo = "FA_o_762x39_7U4_Sub_T_IR"; displayName = "[JMSB] 75Rnd 7.62x39mm 7U4 Sub (AK-12) - IR Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N47_CT_Lush: 75rnd_762x39_AK12_Lush_Mag_F { author = QAUTHOR; displayName = "[JMSB] 75Rnd 7.62x39mm 7N47 CT Lush"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; ammo = "FA_o_762x39_7N47_CT"; initSpeed = 800; };
    class FA_o_75Rnd_762x39_7N47_CT_Lush_T_Red: FA_o_75Rnd_762x39_7N47_CT_Lush { ammo = "FA_o_762x39_7N47_CT_T_Red"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N47 CT Lush - Red Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N47_CT_Lush_T_Yellow: FA_o_75Rnd_762x39_7N47_CT_Lush { ammo = "FA_o_762x39_7N47_CT_T_Yellow"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N47 CT Lush - Yellow Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N47_CT_Lush_T_Green: FA_o_75Rnd_762x39_7N47_CT_Lush { ammo = "FA_o_762x39_7N47_CT_T_Green"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N47 CT Lush - Green Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N47_CT_Lush_T_White: FA_o_75Rnd_762x39_7N47_CT_Lush { ammo = "FA_o_762x39_7N47_CT_T_White"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N47 CT Lush - White Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N47_CT_Lush_T_Blue: FA_o_75Rnd_762x39_7N47_CT_Lush { ammo = "FA_o_762x39_7N47_CT_T_Blue"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N47 CT Lush - Blue Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N47_CT_Lush_T_Orange: FA_o_75Rnd_762x39_7N47_CT_Lush { ammo = "FA_o_762x39_7N47_CT_T_Orange"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N47 CT Lush - Orange Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N47_CT_Lush_T_IR: FA_o_75Rnd_762x39_7N47_CT_Lush { ammo = "FA_o_762x39_7N47_CT_T_IR"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N47 CT Lush - IR Tracer"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7U4_Sub_Lush: 75rnd_762x39_AK12_Lush_Mag_F { author = QAUTHOR; displayName = "[JMSB] 75Rnd 7.62x39mm 7U4 Sub Lush"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; ammo = "FA_o_762x39_7U4_Sub"; initSpeed = 290; };
    class FA_o_75Rnd_762x39_7U4_Sub_Lush_T_Red: FA_o_75Rnd_762x39_7U4_Sub_Lush { ammo = "FA_o_762x39_7U4_Sub_T_Red"; displayName = "[JMSB] 75Rnd 7.62x39mm 7U4 Sub Lush - Red Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7U4_Sub_Lush_T_Yellow: FA_o_75Rnd_762x39_7U4_Sub_Lush { ammo = "FA_o_762x39_7U4_Sub_T_Yellow"; displayName = "[JMSB] 75Rnd 7.62x39mm 7U4 Sub Lush - Yellow Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7U4_Sub_Lush_T_Green: FA_o_75Rnd_762x39_7U4_Sub_Lush { ammo = "FA_o_762x39_7U4_Sub_T_Green"; displayName = "[JMSB] 75Rnd 7.62x39mm 7U4 Sub Lush - Green Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7U4_Sub_Lush_T_White: FA_o_75Rnd_762x39_7U4_Sub_Lush { ammo = "FA_o_762x39_7U4_Sub_T_White"; displayName = "[JMSB] 75Rnd 7.62x39mm 7U4 Sub Lush - White Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7U4_Sub_Lush_T_Blue: FA_o_75Rnd_762x39_7U4_Sub_Lush { ammo = "FA_o_762x39_7U4_Sub_T_Blue"; displayName = "[JMSB] 75Rnd 7.62x39mm 7U4 Sub Lush - Blue Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7U4_Sub_Lush_T_Orange: FA_o_75Rnd_762x39_7U4_Sub_Lush { ammo = "FA_o_762x39_7U4_Sub_T_Orange"; displayName = "[JMSB] 75Rnd 7.62x39mm 7U4 Sub Lush - Orange Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7U4_Sub_Lush_T_IR: FA_o_75Rnd_762x39_7U4_Sub_Lush { ammo = "FA_o_762x39_7U4_Sub_T_IR"; displayName = "[JMSB] 75Rnd 7.62x39mm 7U4 Sub Lush - IR Tracer"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N47_CT_Arid: 75rnd_762x39_AK12_Arid_Mag_F { author = QAUTHOR; displayName = "[JMSB] 75Rnd 7.62x39mm 7N47 CT - Arid"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; ammo = "FA_o_762x39_7N47_CT"; initSpeed = 800; };
    class FA_o_75Rnd_762x39_7N47_CT_Arid_T_Red: FA_o_75Rnd_762x39_7N47_CT_Arid { ammo = "FA_o_762x39_7N47_CT_T_Red"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N47 CT - Red Tracer, Arid"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N47_CT_Arid_T_Yellow: FA_o_75Rnd_762x39_7N47_CT_Arid { ammo = "FA_o_762x39_7N47_CT_T_Yellow"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N47 CT - Yellow Tracer, Arid"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N47_CT_Arid_T_Green: FA_o_75Rnd_762x39_7N47_CT_Arid { ammo = "FA_o_762x39_7N47_CT_T_Green"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N47 CT - Green Tracer, Arid"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N47_CT_Arid_T_White: FA_o_75Rnd_762x39_7N47_CT_Arid { ammo = "FA_o_762x39_7N47_CT_T_White"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N47 CT - White Tracer, Arid"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N47_CT_Arid_T_Blue: FA_o_75Rnd_762x39_7N47_CT_Arid { ammo = "FA_o_762x39_7N47_CT_T_Blue"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N47 CT - Blue Tracer, Arid"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N47_CT_Arid_T_Orange: FA_o_75Rnd_762x39_7N47_CT_Arid { ammo = "FA_o_762x39_7N47_CT_T_Orange"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N47 CT - Orange Tracer, Arid"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7N47_CT_Arid_T_IR: FA_o_75Rnd_762x39_7N47_CT_Arid { ammo = "FA_o_762x39_7N47_CT_T_IR"; displayName = "[JMSB] 75Rnd 7.62x39mm 7N47 CT - IR Tracer, Arid"; descriptionShort = "7.62x39 7N47 Kremen-2 CT"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7U4_Sub_Arid: 75rnd_762x39_AK12_Arid_Mag_F { author = QAUTHOR; displayName = "[JMSB] 75Rnd 7.62x39mm 7U4 Sub - Arid"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; ammo = "FA_o_762x39_7U4_Sub"; initSpeed = 290; };
    class FA_o_75Rnd_762x39_7U4_Sub_Arid_T_Red: FA_o_75Rnd_762x39_7U4_Sub_Arid { ammo = "FA_o_762x39_7U4_Sub_T_Red"; displayName = "[JMSB] 75Rnd 7.62x39mm 7U4 Sub - Red Tracer, Arid"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7U4_Sub_Arid_T_Yellow: FA_o_75Rnd_762x39_7U4_Sub_Arid { ammo = "FA_o_762x39_7U4_Sub_T_Yellow"; displayName = "[JMSB] 75Rnd 7.62x39mm 7U4 Sub - Yellow Tracer, Arid"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7U4_Sub_Arid_T_Green: FA_o_75Rnd_762x39_7U4_Sub_Arid { ammo = "FA_o_762x39_7U4_Sub_T_Green"; displayName = "[JMSB] 75Rnd 7.62x39mm 7U4 Sub - Green Tracer, Arid"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7U4_Sub_Arid_T_White: FA_o_75Rnd_762x39_7U4_Sub_Arid { ammo = "FA_o_762x39_7U4_Sub_T_White"; displayName = "[JMSB] 75Rnd 7.62x39mm 7U4 Sub - White Tracer, Arid"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7U4_Sub_Arid_T_Blue: FA_o_75Rnd_762x39_7U4_Sub_Arid { ammo = "FA_o_762x39_7U4_Sub_T_Blue"; displayName = "[JMSB] 75Rnd 7.62x39mm 7U4 Sub - Blue Tracer, Arid"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7U4_Sub_Arid_T_Orange: FA_o_75Rnd_762x39_7U4_Sub_Arid { ammo = "FA_o_762x39_7U4_Sub_T_Orange"; displayName = "[JMSB] 75Rnd 7.62x39mm 7U4 Sub - Orange Tracer, Arid"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };
    class FA_o_75Rnd_762x39_7U4_Sub_Arid_T_IR: FA_o_75Rnd_762x39_7U4_Sub_Arid { ammo = "FA_o_762x39_7U4_Sub_T_IR"; displayName = "[JMSB] 75Rnd 7.62x39mm 7U4 Sub - IR Tracer, Arid"; descriptionShort = "7.62x39 7U4 Tishina-2 SubAP"; tracersEvery = 4; };

    // =========================================================
    // FACTION BASE AMMO magazines — AAF Stanag/Box/20Rnd, CSAT Katiba green,
    // 5.8x42 DBP-39/DBP-40
    // =========================================================
    class FA_i_30Rnd_556_AF556_HV: 30Rnd_556x45_Stanag {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 5.56mm AF556 HV";
        descriptionShort = "AF-556 HV";
        ammo = "FA_i_556_AF556_HV";
        initSpeed = 950;
        mass = 8;
    };
    class FA_i_30Rnd_556_AF556_HV_T_Red: FA_i_30Rnd_556_AF556_HV {
        displayName = "[JMSB] 30Rnd 5.56mm AF556 HV - Red Tracer";
        descriptionShort = "AF-556 HV";
        ammo = "FA_i_556_AF556_HV_T_Red";
        tracersEvery = 4;
    };
    class FA_i_30Rnd_556_AF556_HV_T_Yellow: FA_i_30Rnd_556_AF556_HV {
        displayName = "[JMSB] 30Rnd 5.56mm AF556 HV - Yellow Tracer";
        descriptionShort = "AF-556 HV";
        ammo = "FA_i_556_AF556_HV_T_Yellow";
        tracersEvery = 4;
    };
    class FA_i_30Rnd_556_AF556_HV_T_Green: FA_i_30Rnd_556_AF556_HV {
        displayName = "[JMSB] 30Rnd 5.56mm AF556 HV - Green Tracer";
        descriptionShort = "AF-556 HV";
        ammo = "FA_i_556_AF556_HV_T_Green";
        tracersEvery = 4;
    };
    class FA_i_30Rnd_556_AF556_HV_T_White: FA_i_30Rnd_556_AF556_HV {
        displayName = "[JMSB] 30Rnd 5.56mm AF556 HV - White Tracer";
        descriptionShort = "AF-556 HV";
        ammo = "FA_i_556_AF556_HV_T_White";
        tracersEvery = 4;
    };
    class FA_i_30Rnd_556_AF556_HV_T_Blue: FA_i_30Rnd_556_AF556_HV {
        displayName = "[JMSB] 30Rnd 5.56mm AF556 HV - Blue Tracer";
        descriptionShort = "AF-556 HV";
        ammo = "FA_i_556_AF556_HV_T_Blue";
        tracersEvery = 4;
    };
    class FA_i_30Rnd_556_AF556_HV_T_Orange: FA_i_30Rnd_556_AF556_HV {
        displayName = "[JMSB] 30Rnd 5.56mm AF556 HV - Orange Tracer";
        descriptionShort = "AF-556 HV";
        ammo = "FA_i_556_AF556_HV_T_Orange";
        tracersEvery = 4;
    };
    class FA_i_30Rnd_556_AF556_HV_T_IR: FA_i_30Rnd_556_AF556_HV {
        displayName = "[JMSB] 30Rnd 5.56mm AF556 HV - IR Tracer";
        descriptionShort = "AF-556 HV";
        ammo = "FA_i_556_AF556_HV_T_IR";
        tracersEvery = 4;
    };
    class FA_i_30Rnd_556_AF556C_CT: 30Rnd_556x45_Stanag {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 5.56mm AF556C CT";
        descriptionShort = "AF-556C CT";
        ammo = "FA_i_556_AF556C_CT";
        initSpeed = 965;
        mass = 6;
    };
    class FA_i_30Rnd_556_AF556C_CT_T_Red: FA_i_30Rnd_556_AF556C_CT {
        displayName = "[JMSB] 30Rnd 5.56mm AF556C CT - Red Tracer";
        descriptionShort = "AF-556C CT";
        ammo = "FA_i_556_AF556C_CT_T_Red";
        tracersEvery = 4;
    };
    class FA_i_30Rnd_556_AF556C_CT_T_Yellow: FA_i_30Rnd_556_AF556C_CT {
        displayName = "[JMSB] 30Rnd 5.56mm AF556C CT - Yellow Tracer";
        descriptionShort = "AF-556C CT";
        ammo = "FA_i_556_AF556C_CT_T_Yellow";
        tracersEvery = 4;
    };
    class FA_i_30Rnd_556_AF556C_CT_T_Green: FA_i_30Rnd_556_AF556C_CT {
        displayName = "[JMSB] 30Rnd 5.56mm AF556C CT - Green Tracer";
        descriptionShort = "AF-556C CT";
        ammo = "FA_i_556_AF556C_CT_T_Green";
        tracersEvery = 4;
    };
    class FA_i_30Rnd_556_AF556C_CT_T_White: FA_i_30Rnd_556_AF556C_CT {
        displayName = "[JMSB] 30Rnd 5.56mm AF556C CT - White Tracer";
        descriptionShort = "AF-556C CT";
        ammo = "FA_i_556_AF556C_CT_T_White";
        tracersEvery = 4;
    };
    class FA_i_30Rnd_556_AF556C_CT_T_Blue: FA_i_30Rnd_556_AF556C_CT {
        displayName = "[JMSB] 30Rnd 5.56mm AF556C CT - Blue Tracer";
        descriptionShort = "AF-556C CT";
        ammo = "FA_i_556_AF556C_CT_T_Blue";
        tracersEvery = 4;
    };
    class FA_i_30Rnd_556_AF556C_CT_T_Orange: FA_i_30Rnd_556_AF556C_CT {
        displayName = "[JMSB] 30Rnd 5.56mm AF556C CT - Orange Tracer";
        descriptionShort = "AF-556C CT";
        ammo = "FA_i_556_AF556C_CT_T_Orange";
        tracersEvery = 4;
    };
    class FA_i_30Rnd_556_AF556C_CT_T_IR: FA_i_30Rnd_556_AF556C_CT {
        displayName = "[JMSB] 30Rnd 5.56mm AF556C CT - IR Tracer";
        descriptionShort = "AF-556C CT";
        ammo = "FA_i_556_AF556C_CT_T_IR";
        tracersEvery = 4;
    };
    class FA_i_30Rnd_556_AF556P_AP: 30Rnd_556x45_Stanag {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 5.56mm AF556P AP";
        descriptionShort = "AF-556P AP";
        ammo = "FA_i_556_AF556P_AP";
        initSpeed = 895;
    };
    class FA_i_30Rnd_556_AF556P_AP_T_Red: FA_i_30Rnd_556_AF556P_AP {
        displayName = "[JMSB] 30Rnd 5.56mm AF556P AP - Red Tracer";
        descriptionShort = "AF-556P AP";
        ammo = "FA_i_556_AF556P_AP_T_Red";
        tracersEvery = 4;
    };
    class FA_i_30Rnd_556_AF556P_AP_T_Yellow: FA_i_30Rnd_556_AF556P_AP {
        displayName = "[JMSB] 30Rnd 5.56mm AF556P AP - Yellow Tracer";
        descriptionShort = "AF-556P AP";
        ammo = "FA_i_556_AF556P_AP_T_Yellow";
        tracersEvery = 4;
    };
    class FA_i_30Rnd_556_AF556P_AP_T_Green: FA_i_30Rnd_556_AF556P_AP {
        displayName = "[JMSB] 30Rnd 5.56mm AF556P AP - Green Tracer";
        descriptionShort = "AF-556P AP";
        ammo = "FA_i_556_AF556P_AP_T_Green";
        tracersEvery = 4;
    };
    class FA_i_30Rnd_556_AF556P_AP_T_White: FA_i_30Rnd_556_AF556P_AP {
        displayName = "[JMSB] 30Rnd 5.56mm AF556P AP - White Tracer";
        descriptionShort = "AF-556P AP";
        ammo = "FA_i_556_AF556P_AP_T_White";
        tracersEvery = 4;
    };
    class FA_i_30Rnd_556_AF556P_AP_T_Blue: FA_i_30Rnd_556_AF556P_AP {
        displayName = "[JMSB] 30Rnd 5.56mm AF556P AP - Blue Tracer";
        descriptionShort = "AF-556P AP";
        ammo = "FA_i_556_AF556P_AP_T_Blue";
        tracersEvery = 4;
    };
    class FA_i_30Rnd_556_AF556P_AP_T_Orange: FA_i_30Rnd_556_AF556P_AP {
        displayName = "[JMSB] 30Rnd 5.56mm AF556P AP - Orange Tracer";
        descriptionShort = "AF-556P AP";
        ammo = "FA_i_556_AF556P_AP_T_Orange";
        tracersEvery = 4;
    };
    class FA_i_30Rnd_556_AF556P_AP_T_IR: FA_i_30Rnd_556_AF556P_AP {
        displayName = "[JMSB] 30Rnd 5.56mm AF556P AP - IR Tracer";
        descriptionShort = "AF-556P AP";
        ammo = "FA_i_556_AF556P_AP_T_IR";
        tracersEvery = 4;
    };
    class FA_i_200Rnd_556x45_Box_F_AF556_HV: 200Rnd_556x45_Box_F {
        author = QAUTHOR;
        displayName = "[JMSB] 200Rnd 5.56mm AF556 HV (Box)";
        descriptionShort = "AF-556 HV";
        ammo = "FA_i_556_AF556_HV";
        initSpeed = 950;
    };
    class FA_i_200Rnd_556x45_Box_F_AF556_HV_T_Red: FA_i_200Rnd_556x45_Box_F_AF556_HV {
        displayName = "[JMSB] 200Rnd 5.56mm AF556 HV (Box) - Red Tracer";
        descriptionShort = "AF-556 HV";
        ammo = "FA_i_556_AF556_HV_T_Red";
        tracersEvery = 4;
    };
    class FA_i_200Rnd_556x45_Box_F_AF556_HV_T_Yellow: FA_i_200Rnd_556x45_Box_F_AF556_HV {
        displayName = "[JMSB] 200Rnd 5.56mm AF556 HV (Box) - Yellow Tracer";
        descriptionShort = "AF-556 HV";
        ammo = "FA_i_556_AF556_HV_T_Yellow";
        tracersEvery = 4;
    };
    class FA_i_200Rnd_556x45_Box_F_AF556_HV_T_Green: FA_i_200Rnd_556x45_Box_F_AF556_HV {
        displayName = "[JMSB] 200Rnd 5.56mm AF556 HV (Box) - Green Tracer";
        descriptionShort = "AF-556 HV";
        ammo = "FA_i_556_AF556_HV_T_Green";
        tracersEvery = 4;
    };
    class FA_i_200Rnd_556x45_Box_F_AF556_HV_T_White: FA_i_200Rnd_556x45_Box_F_AF556_HV {
        displayName = "[JMSB] 200Rnd 5.56mm AF556 HV (Box) - White Tracer";
        descriptionShort = "AF-556 HV";
        ammo = "FA_i_556_AF556_HV_T_White";
        tracersEvery = 4;
    };
    class FA_i_200Rnd_556x45_Box_F_AF556_HV_T_Blue: FA_i_200Rnd_556x45_Box_F_AF556_HV {
        displayName = "[JMSB] 200Rnd 5.56mm AF556 HV (Box) - Blue Tracer";
        descriptionShort = "AF-556 HV";
        ammo = "FA_i_556_AF556_HV_T_Blue";
        tracersEvery = 4;
    };
    class FA_i_200Rnd_556x45_Box_F_AF556_HV_T_Orange: FA_i_200Rnd_556x45_Box_F_AF556_HV {
        displayName = "[JMSB] 200Rnd 5.56mm AF556 HV (Box) - Orange Tracer";
        descriptionShort = "AF-556 HV";
        ammo = "FA_i_556_AF556_HV_T_Orange";
        tracersEvery = 4;
    };
    class FA_i_200Rnd_556x45_Box_F_AF556_HV_T_IR: FA_i_200Rnd_556x45_Box_F_AF556_HV {
        displayName = "[JMSB] 200Rnd 5.56mm AF556 HV (Box) - IR Tracer";
        descriptionShort = "AF-556 HV";
        ammo = "FA_i_556_AF556_HV_T_IR";
        tracersEvery = 4;
    };
    class FA_i_200Rnd_556x45_Box_F_AF556C_CT: 200Rnd_556x45_Box_F {
        author = QAUTHOR;
        displayName = "[JMSB] 200Rnd 5.56mm AF556C CT (Box)";
        descriptionShort = "AF-556C CT";
        ammo = "FA_i_556_AF556C_CT";
        initSpeed = 965;
    };
    class FA_i_200Rnd_556x45_Box_F_AF556C_CT_T_Red: FA_i_200Rnd_556x45_Box_F_AF556C_CT {
        displayName = "[JMSB] 200Rnd 5.56mm AF556C CT (Box) - Red Tracer";
        descriptionShort = "AF-556C CT";
        ammo = "FA_i_556_AF556C_CT_T_Red";
        tracersEvery = 4;
    };
    class FA_i_200Rnd_556x45_Box_F_AF556C_CT_T_Yellow: FA_i_200Rnd_556x45_Box_F_AF556C_CT {
        displayName = "[JMSB] 200Rnd 5.56mm AF556C CT (Box) - Yellow Tracer";
        descriptionShort = "AF-556C CT";
        ammo = "FA_i_556_AF556C_CT_T_Yellow";
        tracersEvery = 4;
    };
    class FA_i_200Rnd_556x45_Box_F_AF556C_CT_T_Green: FA_i_200Rnd_556x45_Box_F_AF556C_CT {
        displayName = "[JMSB] 200Rnd 5.56mm AF556C CT (Box) - Green Tracer";
        descriptionShort = "AF-556C CT";
        ammo = "FA_i_556_AF556C_CT_T_Green";
        tracersEvery = 4;
    };
    class FA_i_200Rnd_556x45_Box_F_AF556C_CT_T_White: FA_i_200Rnd_556x45_Box_F_AF556C_CT {
        displayName = "[JMSB] 200Rnd 5.56mm AF556C CT (Box) - White Tracer";
        descriptionShort = "AF-556C CT";
        ammo = "FA_i_556_AF556C_CT_T_White";
        tracersEvery = 4;
    };
    class FA_i_200Rnd_556x45_Box_F_AF556C_CT_T_Blue: FA_i_200Rnd_556x45_Box_F_AF556C_CT {
        displayName = "[JMSB] 200Rnd 5.56mm AF556C CT (Box) - Blue Tracer";
        descriptionShort = "AF-556C CT";
        ammo = "FA_i_556_AF556C_CT_T_Blue";
        tracersEvery = 4;
    };
    class FA_i_200Rnd_556x45_Box_F_AF556C_CT_T_Orange: FA_i_200Rnd_556x45_Box_F_AF556C_CT {
        displayName = "[JMSB] 200Rnd 5.56mm AF556C CT (Box) - Orange Tracer";
        descriptionShort = "AF-556C CT";
        ammo = "FA_i_556_AF556C_CT_T_Orange";
        tracersEvery = 4;
    };
    class FA_i_200Rnd_556x45_Box_F_AF556C_CT_T_IR: FA_i_200Rnd_556x45_Box_F_AF556C_CT {
        displayName = "[JMSB] 200Rnd 5.56mm AF556C CT (Box) - IR Tracer";
        descriptionShort = "AF-556C CT";
        ammo = "FA_i_556_AF556C_CT_T_IR";
        tracersEvery = 4;
    };
    class FA_i_200Rnd_556x45_Box_F_AF556P_AP: 200Rnd_556x45_Box_F {
        author = QAUTHOR;
        displayName = "[JMSB] 200Rnd 5.56mm AF556P AP (Box)";
        descriptionShort = "AF-556P AP";
        ammo = "FA_i_556_AF556P_AP";
        initSpeed = 895;
    };
    class FA_i_200Rnd_556x45_Box_F_AF556P_AP_T_Red: FA_i_200Rnd_556x45_Box_F_AF556P_AP {
        displayName = "[JMSB] 200Rnd 5.56mm AF556P AP (Box) - Red Tracer";
        descriptionShort = "AF-556P AP";
        ammo = "FA_i_556_AF556P_AP_T_Red";
        tracersEvery = 4;
    };
    class FA_i_200Rnd_556x45_Box_F_AF556P_AP_T_Yellow: FA_i_200Rnd_556x45_Box_F_AF556P_AP {
        displayName = "[JMSB] 200Rnd 5.56mm AF556P AP (Box) - Yellow Tracer";
        descriptionShort = "AF-556P AP";
        ammo = "FA_i_556_AF556P_AP_T_Yellow";
        tracersEvery = 4;
    };
    class FA_i_200Rnd_556x45_Box_F_AF556P_AP_T_Green: FA_i_200Rnd_556x45_Box_F_AF556P_AP {
        displayName = "[JMSB] 200Rnd 5.56mm AF556P AP (Box) - Green Tracer";
        descriptionShort = "AF-556P AP";
        ammo = "FA_i_556_AF556P_AP_T_Green";
        tracersEvery = 4;
    };
    class FA_i_200Rnd_556x45_Box_F_AF556P_AP_T_White: FA_i_200Rnd_556x45_Box_F_AF556P_AP {
        displayName = "[JMSB] 200Rnd 5.56mm AF556P AP (Box) - White Tracer";
        descriptionShort = "AF-556P AP";
        ammo = "FA_i_556_AF556P_AP_T_White";
        tracersEvery = 4;
    };
    class FA_i_200Rnd_556x45_Box_F_AF556P_AP_T_Blue: FA_i_200Rnd_556x45_Box_F_AF556P_AP {
        displayName = "[JMSB] 200Rnd 5.56mm AF556P AP (Box) - Blue Tracer";
        descriptionShort = "AF-556P AP";
        ammo = "FA_i_556_AF556P_AP_T_Blue";
        tracersEvery = 4;
    };
    class FA_i_200Rnd_556x45_Box_F_AF556P_AP_T_Orange: FA_i_200Rnd_556x45_Box_F_AF556P_AP {
        displayName = "[JMSB] 200Rnd 5.56mm AF556P AP (Box) - Orange Tracer";
        descriptionShort = "AF-556P AP";
        ammo = "FA_i_556_AF556P_AP_T_Orange";
        tracersEvery = 4;
    };
    class FA_i_200Rnd_556x45_Box_F_AF556P_AP_T_IR: FA_i_200Rnd_556x45_Box_F_AF556P_AP {
        displayName = "[JMSB] 200Rnd 5.56mm AF556P AP (Box) - IR Tracer";
        descriptionShort = "AF-556P AP";
        ammo = "FA_i_556_AF556P_AP_T_IR";
        tracersEvery = 4;
    };
    class FA_i_20Rnd_762_AF762_HV: 20Rnd_762x51_Mag {
        author = QAUTHOR;
        displayName = "[JMSB] 20Rnd 7.62mm AF762 HV";
        descriptionShort = "AF-762 HV";
        ammo = "FA_i_762_AF762_HV";
        initSpeed = 895;
        mass = 16;
    };
    class FA_i_20Rnd_762_AF762_HV_T_Red: FA_i_20Rnd_762_AF762_HV {
        displayName = "[JMSB] 20Rnd 7.62mm AF762 HV - Red Tracer";
        descriptionShort = "AF-762 HV";
        ammo = "FA_i_762_AF762_HV_T_Red";
        tracersEvery = 4;
    };
    class FA_i_20Rnd_762_AF762_HV_T_Yellow: FA_i_20Rnd_762_AF762_HV {
        displayName = "[JMSB] 20Rnd 7.62mm AF762 HV - Yellow Tracer";
        descriptionShort = "AF-762 HV";
        ammo = "FA_i_762_AF762_HV_T_Yellow";
        tracersEvery = 4;
    };
    class FA_i_20Rnd_762_AF762_HV_T_Green: FA_i_20Rnd_762_AF762_HV {
        displayName = "[JMSB] 20Rnd 7.62mm AF762 HV - Green Tracer";
        descriptionShort = "AF-762 HV";
        ammo = "FA_i_762_AF762_HV_T_Green";
        tracersEvery = 4;
    };
    class FA_i_20Rnd_762_AF762_HV_T_White: FA_i_20Rnd_762_AF762_HV {
        displayName = "[JMSB] 20Rnd 7.62mm AF762 HV - White Tracer";
        descriptionShort = "AF-762 HV";
        ammo = "FA_i_762_AF762_HV_T_White";
        tracersEvery = 4;
    };
    class FA_i_20Rnd_762_AF762_HV_T_Blue: FA_i_20Rnd_762_AF762_HV {
        displayName = "[JMSB] 20Rnd 7.62mm AF762 HV - Blue Tracer";
        descriptionShort = "AF-762 HV";
        ammo = "FA_i_762_AF762_HV_T_Blue";
        tracersEvery = 4;
    };
    class FA_i_20Rnd_762_AF762_HV_T_Orange: FA_i_20Rnd_762_AF762_HV {
        displayName = "[JMSB] 20Rnd 7.62mm AF762 HV - Orange Tracer";
        descriptionShort = "AF-762 HV";
        ammo = "FA_i_762_AF762_HV_T_Orange";
        tracersEvery = 4;
    };
    class FA_i_20Rnd_762_AF762_HV_T_IR: FA_i_20Rnd_762_AF762_HV {
        displayName = "[JMSB] 20Rnd 7.62mm AF762 HV - IR Tracer";
        descriptionShort = "AF-762 HV";
        ammo = "FA_i_762_AF762_HV_T_IR";
        tracersEvery = 4;
    };
    class FA_i_20Rnd_762_AF762C_CT: 20Rnd_762x51_Mag {
        author = QAUTHOR;
        displayName = "[JMSB] 20Rnd 7.62mm AF762C CT";
        descriptionShort = "AF-762C CT";
        ammo = "FA_i_762_AF762C_CT";
        initSpeed = 910;
    };
    class FA_i_20Rnd_762_AF762C_CT_T_Red: FA_i_20Rnd_762_AF762C_CT {
        displayName = "[JMSB] 20Rnd 7.62mm AF762C CT - Red Tracer";
        descriptionShort = "AF-762C CT";
        ammo = "FA_i_762_AF762C_CT_T_Red";
        tracersEvery = 4;
    };
    class FA_i_20Rnd_762_AF762C_CT_T_Yellow: FA_i_20Rnd_762_AF762C_CT {
        displayName = "[JMSB] 20Rnd 7.62mm AF762C CT - Yellow Tracer";
        descriptionShort = "AF-762C CT";
        ammo = "FA_i_762_AF762C_CT_T_Yellow";
        tracersEvery = 4;
    };
    class FA_i_20Rnd_762_AF762C_CT_T_Green: FA_i_20Rnd_762_AF762C_CT {
        displayName = "[JMSB] 20Rnd 7.62mm AF762C CT - Green Tracer";
        descriptionShort = "AF-762C CT";
        ammo = "FA_i_762_AF762C_CT_T_Green";
        tracersEvery = 4;
    };
    class FA_i_20Rnd_762_AF762C_CT_T_White: FA_i_20Rnd_762_AF762C_CT {
        displayName = "[JMSB] 20Rnd 7.62mm AF762C CT - White Tracer";
        descriptionShort = "AF-762C CT";
        ammo = "FA_i_762_AF762C_CT_T_White";
        tracersEvery = 4;
    };
    class FA_i_20Rnd_762_AF762C_CT_T_Blue: FA_i_20Rnd_762_AF762C_CT {
        displayName = "[JMSB] 20Rnd 7.62mm AF762C CT - Blue Tracer";
        descriptionShort = "AF-762C CT";
        ammo = "FA_i_762_AF762C_CT_T_Blue";
        tracersEvery = 4;
    };
    class FA_i_20Rnd_762_AF762C_CT_T_Orange: FA_i_20Rnd_762_AF762C_CT {
        displayName = "[JMSB] 20Rnd 7.62mm AF762C CT - Orange Tracer";
        descriptionShort = "AF-762C CT";
        ammo = "FA_i_762_AF762C_CT_T_Orange";
        tracersEvery = 4;
    };
    class FA_i_20Rnd_762_AF762C_CT_T_IR: FA_i_20Rnd_762_AF762C_CT {
        displayName = "[JMSB] 20Rnd 7.62mm AF762C CT - IR Tracer";
        descriptionShort = "AF-762C CT";
        ammo = "FA_i_762_AF762C_CT_T_IR";
        tracersEvery = 4;
    };
    class FA_i_20Rnd_762_AF762P_AP: 20Rnd_762x51_Mag {
        author = QAUTHOR;
        displayName = "[JMSB] 20Rnd 7.62mm AF762P AP";
        descriptionShort = "AF-762P AP";
        ammo = "FA_i_762_AF762P_AP";
        initSpeed = 895;
    };
    class FA_i_20Rnd_762_AF762P_AP_T_Red: FA_i_20Rnd_762_AF762P_AP {
        displayName = "[JMSB] 20Rnd 7.62mm AF762P AP - Red Tracer";
        descriptionShort = "AF-762P AP";
        ammo = "FA_i_762_AF762P_AP_T_Red";
        tracersEvery = 4;
    };
    class FA_i_20Rnd_762_AF762P_AP_T_Yellow: FA_i_20Rnd_762_AF762P_AP {
        displayName = "[JMSB] 20Rnd 7.62mm AF762P AP - Yellow Tracer";
        descriptionShort = "AF-762P AP";
        ammo = "FA_i_762_AF762P_AP_T_Yellow";
        tracersEvery = 4;
    };
    class FA_i_20Rnd_762_AF762P_AP_T_Green: FA_i_20Rnd_762_AF762P_AP {
        displayName = "[JMSB] 20Rnd 7.62mm AF762P AP - Green Tracer";
        descriptionShort = "AF-762P AP";
        ammo = "FA_i_762_AF762P_AP_T_Green";
        tracersEvery = 4;
    };
    class FA_i_20Rnd_762_AF762P_AP_T_White: FA_i_20Rnd_762_AF762P_AP {
        displayName = "[JMSB] 20Rnd 7.62mm AF762P AP - White Tracer";
        descriptionShort = "AF-762P AP";
        ammo = "FA_i_762_AF762P_AP_T_White";
        tracersEvery = 4;
    };
    class FA_i_20Rnd_762_AF762P_AP_T_Blue: FA_i_20Rnd_762_AF762P_AP {
        displayName = "[JMSB] 20Rnd 7.62mm AF762P AP - Blue Tracer";
        descriptionShort = "AF-762P AP";
        ammo = "FA_i_762_AF762P_AP_T_Blue";
        tracersEvery = 4;
    };
    class FA_i_20Rnd_762_AF762P_AP_T_Orange: FA_i_20Rnd_762_AF762P_AP {
        displayName = "[JMSB] 20Rnd 7.62mm AF762P AP - Orange Tracer";
        descriptionShort = "AF-762P AP";
        ammo = "FA_i_762_AF762P_AP_T_Orange";
        tracersEvery = 4;
    };
    class FA_i_20Rnd_762_AF762P_AP_T_IR: FA_i_20Rnd_762_AF762P_AP {
        displayName = "[JMSB] 20Rnd 7.62mm AF762P AP - IR Tracer";
        descriptionShort = "AF-762P AP";
        ammo = "FA_i_762_AF762P_AP_T_IR";
        tracersEvery = 4;
    };
    class FA_o_30Rnd_65_Type41_EPR: 30Rnd_65x39_caseless_green {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 6.5mm Type41 EPR";
        descriptionShort = "Type 41 EPR";
        ammo = "FA_o_65_Type41_EPR";
        initSpeed = 855;
        mass = 7;
    };
    class FA_o_30Rnd_65_Type41_EPR_T_Red: FA_o_30Rnd_65_Type41_EPR {
        displayName = "[JMSB] 30Rnd 6.5mm Type41 EPR - Red Tracer";
        descriptionShort = "Type 41 EPR";
        ammo = "FA_o_65_Type41_EPR_T_Red";
        tracersEvery = 4;
    };
    class FA_o_30Rnd_65_Type41_EPR_T_Yellow: FA_o_30Rnd_65_Type41_EPR {
        displayName = "[JMSB] 30Rnd 6.5mm Type41 EPR - Yellow Tracer";
        descriptionShort = "Type 41 EPR";
        ammo = "FA_o_65_Type41_EPR_T_Yellow";
        tracersEvery = 4;
    };
    class FA_o_30Rnd_65_Type41_EPR_T_Green: FA_o_30Rnd_65_Type41_EPR {
        displayName = "[JMSB] 30Rnd 6.5mm Type41 EPR - Green Tracer";
        descriptionShort = "Type 41 EPR";
        ammo = "FA_o_65_Type41_EPR_T_Green";
        tracersEvery = 4;
    };
    class FA_o_30Rnd_65_Type41_EPR_T_White: FA_o_30Rnd_65_Type41_EPR {
        displayName = "[JMSB] 30Rnd 6.5mm Type41 EPR - White Tracer";
        descriptionShort = "Type 41 EPR";
        ammo = "FA_o_65_Type41_EPR_T_White";
        tracersEvery = 4;
    };
    class FA_o_30Rnd_65_Type41_EPR_T_Blue: FA_o_30Rnd_65_Type41_EPR {
        displayName = "[JMSB] 30Rnd 6.5mm Type41 EPR - Blue Tracer";
        descriptionShort = "Type 41 EPR";
        ammo = "FA_o_65_Type41_EPR_T_Blue";
        tracersEvery = 4;
    };
    class FA_o_30Rnd_65_Type41_EPR_T_Orange: FA_o_30Rnd_65_Type41_EPR {
        displayName = "[JMSB] 30Rnd 6.5mm Type41 EPR - Orange Tracer";
        descriptionShort = "Type 41 EPR";
        ammo = "FA_o_65_Type41_EPR_T_Orange";
        tracersEvery = 4;
    };
    class FA_o_30Rnd_65_Type41_EPR_T_IR: FA_o_30Rnd_65_Type41_EPR {
        displayName = "[JMSB] 30Rnd 6.5mm Type41 EPR - IR Tracer";
        descriptionShort = "Type 41 EPR";
        ammo = "FA_o_65_Type41_EPR_T_IR";
        tracersEvery = 4;
    };
    class FA_o_30Rnd_65_Type42_CT: 30Rnd_65x39_caseless_green {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 6.5mm Type42 CT";
        descriptionShort = "Type 42 CT";
        ammo = "FA_o_65_Type42_CT";
        initSpeed = 873;
    };
    class FA_o_30Rnd_65_Type42_CT_T_Red: FA_o_30Rnd_65_Type42_CT {
        displayName = "[JMSB] 30Rnd 6.5mm Type42 CT - Red Tracer";
        descriptionShort = "Type 42 CT";
        ammo = "FA_o_65_Type42_CT_T_Red";
        tracersEvery = 4;
    };
    class FA_o_30Rnd_65_Type42_CT_T_Yellow: FA_o_30Rnd_65_Type42_CT {
        displayName = "[JMSB] 30Rnd 6.5mm Type42 CT - Yellow Tracer";
        descriptionShort = "Type 42 CT";
        ammo = "FA_o_65_Type42_CT_T_Yellow";
        tracersEvery = 4;
    };
    class FA_o_30Rnd_65_Type42_CT_T_Green: FA_o_30Rnd_65_Type42_CT {
        displayName = "[JMSB] 30Rnd 6.5mm Type42 CT - Green Tracer";
        descriptionShort = "Type 42 CT";
        ammo = "FA_o_65_Type42_CT_T_Green";
        tracersEvery = 4;
    };
    class FA_o_30Rnd_65_Type42_CT_T_White: FA_o_30Rnd_65_Type42_CT {
        displayName = "[JMSB] 30Rnd 6.5mm Type42 CT - White Tracer";
        descriptionShort = "Type 42 CT";
        ammo = "FA_o_65_Type42_CT_T_White";
        tracersEvery = 4;
    };
    class FA_o_30Rnd_65_Type42_CT_T_Blue: FA_o_30Rnd_65_Type42_CT {
        displayName = "[JMSB] 30Rnd 6.5mm Type42 CT - Blue Tracer";
        descriptionShort = "Type 42 CT";
        ammo = "FA_o_65_Type42_CT_T_Blue";
        tracersEvery = 4;
    };
    class FA_o_30Rnd_65_Type42_CT_T_Orange: FA_o_30Rnd_65_Type42_CT {
        displayName = "[JMSB] 30Rnd 6.5mm Type42 CT - Orange Tracer";
        descriptionShort = "Type 42 CT";
        ammo = "FA_o_65_Type42_CT_T_Orange";
        tracersEvery = 4;
    };
    class FA_o_30Rnd_65_Type42_CT_T_IR: FA_o_30Rnd_65_Type42_CT {
        displayName = "[JMSB] 30Rnd 6.5mm Type42 CT - IR Tracer";
        descriptionShort = "Type 42 CT";
        ammo = "FA_o_65_Type42_CT_T_IR";
        tracersEvery = 4;
    };
    class FA_o_30Rnd_65_Type43_AP: 30Rnd_65x39_caseless_green {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 6.5mm Type43 AP";
        descriptionShort = "Type 43 AP";
        ammo = "FA_o_65_Type43_AP";
        initSpeed = 851;
    };
    class FA_o_30Rnd_65_Type43_AP_T_Red: FA_o_30Rnd_65_Type43_AP {
        displayName = "[JMSB] 30Rnd 6.5mm Type43 AP - Red Tracer";
        descriptionShort = "Type 43 AP";
        ammo = "FA_o_65_Type43_AP_T_Red";
        tracersEvery = 4;
    };
    class FA_o_30Rnd_65_Type43_AP_T_Yellow: FA_o_30Rnd_65_Type43_AP {
        displayName = "[JMSB] 30Rnd 6.5mm Type43 AP - Yellow Tracer";
        descriptionShort = "Type 43 AP";
        ammo = "FA_o_65_Type43_AP_T_Yellow";
        tracersEvery = 4;
    };
    class FA_o_30Rnd_65_Type43_AP_T_Green: FA_o_30Rnd_65_Type43_AP {
        displayName = "[JMSB] 30Rnd 6.5mm Type43 AP - Green Tracer";
        descriptionShort = "Type 43 AP";
        ammo = "FA_o_65_Type43_AP_T_Green";
        tracersEvery = 4;
    };
    class FA_o_30Rnd_65_Type43_AP_T_White: FA_o_30Rnd_65_Type43_AP {
        displayName = "[JMSB] 30Rnd 6.5mm Type43 AP - White Tracer";
        descriptionShort = "Type 43 AP";
        ammo = "FA_o_65_Type43_AP_T_White";
        tracersEvery = 4;
    };
    class FA_o_30Rnd_65_Type43_AP_T_Blue: FA_o_30Rnd_65_Type43_AP {
        displayName = "[JMSB] 30Rnd 6.5mm Type43 AP - Blue Tracer";
        descriptionShort = "Type 43 AP";
        ammo = "FA_o_65_Type43_AP_T_Blue";
        tracersEvery = 4;
    };
    class FA_o_30Rnd_65_Type43_AP_T_Orange: FA_o_30Rnd_65_Type43_AP {
        displayName = "[JMSB] 30Rnd 6.5mm Type43 AP - Orange Tracer";
        descriptionShort = "Type 43 AP";
        ammo = "FA_o_65_Type43_AP_T_Orange";
        tracersEvery = 4;
    };
    class FA_o_30Rnd_65_Type43_AP_T_IR: FA_o_30Rnd_65_Type43_AP {
        displayName = "[JMSB] 30Rnd 6.5mm Type43 AP - IR Tracer";
        descriptionShort = "Type 43 AP";
        ammo = "FA_o_65_Type43_AP_T_IR";
        tracersEvery = 4;
    };
    class FA_o_30Rnd_580x42_DBP39_CT: 30Rnd_580x42_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 5.8mm DBP39 CT";
        descriptionShort = "DBP-39 CT";
        ammo = "FA_o_580_DBP39_CT";
        initSpeed = 950;
    };
    class FA_o_30Rnd_580x42_DBP39_CT_T_Red: FA_o_30Rnd_580x42_DBP39_CT {
        displayName = "[JMSB] 30Rnd 5.8mm DBP39 CT - Red Tracer";
        descriptionShort = "DBP-39 CT";
        ammo = "FA_o_580_DBP39_CT_T_Red";
        tracersEvery = 4;
    };
    class FA_o_30Rnd_580x42_DBP39_CT_T_Yellow: FA_o_30Rnd_580x42_DBP39_CT {
        displayName = "[JMSB] 30Rnd 5.8mm DBP39 CT - Yellow Tracer";
        descriptionShort = "DBP-39 CT";
        ammo = "FA_o_580_DBP39_CT_T_Yellow";
        tracersEvery = 4;
    };
    class FA_o_30Rnd_580x42_DBP39_CT_T_Green: FA_o_30Rnd_580x42_DBP39_CT {
        displayName = "[JMSB] 30Rnd 5.8mm DBP39 CT - Green Tracer";
        descriptionShort = "DBP-39 CT";
        ammo = "FA_o_580_DBP39_CT_T_Green";
        tracersEvery = 4;
    };
    class FA_o_30Rnd_580x42_DBP39_CT_T_White: FA_o_30Rnd_580x42_DBP39_CT {
        displayName = "[JMSB] 30Rnd 5.8mm DBP39 CT - White Tracer";
        descriptionShort = "DBP-39 CT";
        ammo = "FA_o_580_DBP39_CT_T_White";
        tracersEvery = 4;
    };
    class FA_o_30Rnd_580x42_DBP39_CT_T_Blue: FA_o_30Rnd_580x42_DBP39_CT {
        displayName = "[JMSB] 30Rnd 5.8mm DBP39 CT - Blue Tracer";
        descriptionShort = "DBP-39 CT";
        ammo = "FA_o_580_DBP39_CT_T_Blue";
        tracersEvery = 4;
    };
    class FA_o_30Rnd_580x42_DBP39_CT_T_Orange: FA_o_30Rnd_580x42_DBP39_CT {
        displayName = "[JMSB] 30Rnd 5.8mm DBP39 CT - Orange Tracer";
        descriptionShort = "DBP-39 CT";
        ammo = "FA_o_580_DBP39_CT_T_Orange";
        tracersEvery = 4;
    };
    class FA_o_30Rnd_580x42_DBP39_CT_T_IR: FA_o_30Rnd_580x42_DBP39_CT {
        displayName = "[JMSB] 30Rnd 5.8mm DBP39 CT - IR Tracer";
        descriptionShort = "DBP-39 CT";
        ammo = "FA_o_580_DBP39_CT_T_IR";
        tracersEvery = 4;
    };
    class FA_o_30Rnd_580x42_DBP40_AP: 30Rnd_580x42_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 5.8mm DBP40 AP";
        descriptionShort = "DBP-40 AP";
        ammo = "FA_o_580_DBP40_AP";
        initSpeed = 915;
    };
    class FA_o_30Rnd_580x42_DBP40_AP_T_Red: FA_o_30Rnd_580x42_DBP40_AP {
        displayName = "[JMSB] 30Rnd 5.8mm DBP40 AP - Red Tracer";
        descriptionShort = "DBP-40 AP";
        ammo = "FA_o_580_DBP40_AP_T_Red";
        tracersEvery = 4;
    };
    class FA_o_30Rnd_580x42_DBP40_AP_T_Yellow: FA_o_30Rnd_580x42_DBP40_AP {
        displayName = "[JMSB] 30Rnd 5.8mm DBP40 AP - Yellow Tracer";
        descriptionShort = "DBP-40 AP";
        ammo = "FA_o_580_DBP40_AP_T_Yellow";
        tracersEvery = 4;
    };
    class FA_o_30Rnd_580x42_DBP40_AP_T_Green: FA_o_30Rnd_580x42_DBP40_AP {
        displayName = "[JMSB] 30Rnd 5.8mm DBP40 AP - Green Tracer";
        descriptionShort = "DBP-40 AP";
        ammo = "FA_o_580_DBP40_AP_T_Green";
        tracersEvery = 4;
    };
    class FA_o_30Rnd_580x42_DBP40_AP_T_White: FA_o_30Rnd_580x42_DBP40_AP {
        displayName = "[JMSB] 30Rnd 5.8mm DBP40 AP - White Tracer";
        descriptionShort = "DBP-40 AP";
        ammo = "FA_o_580_DBP40_AP_T_White";
        tracersEvery = 4;
    };
    class FA_o_30Rnd_580x42_DBP40_AP_T_Blue: FA_o_30Rnd_580x42_DBP40_AP {
        displayName = "[JMSB] 30Rnd 5.8mm DBP40 AP - Blue Tracer";
        descriptionShort = "DBP-40 AP";
        ammo = "FA_o_580_DBP40_AP_T_Blue";
        tracersEvery = 4;
    };
    class FA_o_30Rnd_580x42_DBP40_AP_T_Orange: FA_o_30Rnd_580x42_DBP40_AP {
        displayName = "[JMSB] 30Rnd 5.8mm DBP40 AP - Orange Tracer";
        descriptionShort = "DBP-40 AP";
        ammo = "FA_o_580_DBP40_AP_T_Orange";
        tracersEvery = 4;
    };
    class FA_o_30Rnd_580x42_DBP40_AP_T_IR: FA_o_30Rnd_580x42_DBP40_AP {
        displayName = "[JMSB] 30Rnd 5.8mm DBP40 AP - IR Tracer";
        descriptionShort = "DBP-40 AP";
        ammo = "FA_o_580_DBP40_AP_T_IR";
        tracersEvery = 4;
    };

    // P07 / Rook 40 (user, 2026-09-27)
    class FA_b_16Rnd_9x21_Mk424_AP: 16Rnd_9x21_Mag { author = QAUTHOR; displayName = "[JMSB] 16Rnd 9x21mm Mk424 AP"; displayNameShort = "Mk424 AP"; descriptionShort = "9x21 Mk424 AP"; ammo = "FA_b_9x21_Mk424_AP"; initSpeed = 470; };
    // Rahim DMR-01 - 10Rnd_762x54_Mag, the 7.62x54R round the Zafir belt already fires (user, 2026-09-27)
    // The issued weapons that had no FA magazine (user, 2026-09-27: "fix missing mags"). Each is the weapon's own
    // magazine carrying an FA round that already existed; the SMG figures use the rounds' SMG-barrel velocity.
    class FA_b_30Rnd_9x21_SMG_02_Mk424_AP: 30Rnd_9x21_Mag_SMG_02 { author = QAUTHOR; displayName = "[JMSB] 30Rnd 9x21mm Mk424 AP (SMG)"; displayNameShort = "Mk424 AP"; descriptionShort = "9x21 Mk424 AP"; ammo = "FA_b_9x21_Mk424_AP"; initSpeed = 580; };
    class FA_b_6Rnd_45ACP_Mk421: 6Rnd_45ACP_Cylinder { author = QAUTHOR; displayName = "[JMSB] 6Rnd .45 ACP Mk421"; descriptionShort = "45ACP Mk421 SubAP"; ammo = "FA_b_45ACP_Mk421_SubAP"; initSpeed = 280; };
    class FA_b_7Rnd_408_Mk240: 7Rnd_408_Mag { author = QAUTHOR; displayName = "[JMSB] 7Rnd .408 Mk240"; descriptionShort = ".408 Mk240"; ammo = "FA_b_408_Mk240"; initSpeed = 965; };
    class FA_o_10Rnd_762x54_Ball_HV: 10Rnd_762x54_Mag { author = QAUTHOR; displayName = "[JMSB] 10Rnd 7.62x54mmR Ball HV"; descriptionShort = "7.62x54R Ball HV"; ammo = "FA_o_762x54R_Ball_HV"; initSpeed = 850; };

    #include "CfgMagazines_compat.hpp"
};
