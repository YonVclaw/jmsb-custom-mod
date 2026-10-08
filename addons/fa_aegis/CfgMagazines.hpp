class CfgMagazines {
    // Aegis weapon-fitted mag bases - the copies imported into jmfsb_weapons (tools/aegis_port)
    class EGVAR(weapons,10Rnd_762x54_SVD_Red_Mag_F);   // SVD Dragunov, 10Rnd 7.62x54R
    class EGVAR(weapons,5Rnd_127x99_Mag);                     // WF50, 5Rnd .50 BMG (12.7x99)
    class EGVAR(weapons,30Rnd_545x39_AK12_Mag_F);             // AK-12, 30Rnd 5.45x39
    class EGVAR(weapons,45Rnd_545x39_Mag_F);            // RPK-74, 45Rnd 5.45x39
    class EGVAR(weapons,60Rnd_545x39_Mag_F);            // AK-12 drum, 60Rnd 5.45x39

    // =========================================================
    // 7.62x54R SVD (Rahim_762x54) — FA 762x54R Ball HV
    // No FA 7.62x54R box-fed mag existed; built off the SVD mag base.
    // =========================================================
    class FA_Aegis_10Rnd_762x54_SVD_HV: EGVAR(weapons,10Rnd_762x54_SVD_Red_Mag_F) {
        author = QAUTHOR;
        displayName = "[JMSB] 10Rnd 7.62x54R Ball HV";
        descriptionShort = "7.62x54R Ball HV";
        ammo = "FA_o_762x54R_Ball_HV";
        lastRoundsTracer = 0;
        initSpeed = 855;
    };
    class FA_Aegis_10Rnd_762x54_SVD_HV_T_Red    : FA_Aegis_10Rnd_762x54_SVD_HV { displayName = "[JMSB] 10Rnd 7.62x54mmR HV (SVD) - Red Tracer";    descriptionShort = "7.62x54R Ball HV";    ammo = "FA_o_762x54R_Ball_HV_T_Red"; tracersEvery = 4; };
    class FA_Aegis_10Rnd_762x54_SVD_HV_T_Yellow : FA_Aegis_10Rnd_762x54_SVD_HV { displayName = "[JMSB] 10Rnd 7.62x54mmR HV (SVD) - Yellow Tracer"; descriptionShort = "7.62x54R Ball HV"; ammo = "FA_o_762x54R_Ball_HV_T_Yellow"; tracersEvery = 4; };
    class FA_Aegis_10Rnd_762x54_SVD_HV_T_Green  : FA_Aegis_10Rnd_762x54_SVD_HV { displayName = "[JMSB] 10Rnd 7.62x54mmR HV (SVD) - Green Tracer";  descriptionShort = "7.62x54R Ball HV";  ammo = "FA_o_762x54R_Ball_HV_T_Green"; tracersEvery = 4; };
    class FA_Aegis_10Rnd_762x54_SVD_HV_T_White  : FA_Aegis_10Rnd_762x54_SVD_HV { displayName = "[JMSB] 10Rnd 7.62x54mmR HV (SVD) - White Tracer";  descriptionShort = "7.62x54R Ball HV";  ammo = "FA_o_762x54R_Ball_HV_T_White"; tracersEvery = 4; };
    class FA_Aegis_10Rnd_762x54_SVD_HV_T_Blue   : FA_Aegis_10Rnd_762x54_SVD_HV { displayName = "[JMSB] 10Rnd 7.62x54mmR HV (SVD) - Blue Tracer";   descriptionShort = "7.62x54R Ball HV";   ammo = "FA_o_762x54R_Ball_HV_T_Blue"; tracersEvery = 4; };
    class FA_Aegis_10Rnd_762x54_SVD_HV_T_Orange : FA_Aegis_10Rnd_762x54_SVD_HV { displayName = "[JMSB] 10Rnd 7.62x54mmR HV (SVD) - Orange Tracer"; descriptionShort = "7.62x54R Ball HV"; ammo = "FA_o_762x54R_Ball_HV_T_Orange"; tracersEvery = 4; };
    class FA_Aegis_10Rnd_762x54_SVD_HV_T_IR     : FA_Aegis_10Rnd_762x54_SVD_HV { displayName = "[JMSB] 10Rnd 7.62x54mmR HV (SVD) - IR Tracer";     descriptionShort = "7.62x54R Ball HV";     ammo = "FA_o_762x54R_Ball_HV_T_IR"; tracersEvery = 4; };

    // =========================================================
    // .50 BMG WF50 (WF50_127x99) — FA Mk258 LRP + Mk211 Mod 0
    // No FA 12.7x99 mag existed; built off the WF50 mag base.
    // =========================================================
    class FA_Aegis_5Rnd_127x99_Mk258: EGVAR(weapons,5Rnd_127x99_Mag) {
        author = QAUTHOR;
        displayName = "[JMSB] 5Rnd Mk258 LRP";
        descriptionShort = "Mk258 LRP";
        ammo = "FA_b_127x99_Mk258_LRP";
        initSpeed = 860;
    };
    class FA_Aegis_5Rnd_127x99_Mk258_T_Red    : FA_Aegis_5Rnd_127x99_Mk258 { displayName = "[JMSB] 5Rnd 12.7mm Mk258 - Red Tracer";    descriptionShort = "Mk258 LRP";    ammo = "FA_b_127x99_Mk258_LRP_T_Red"; tracersEvery = 4; };
    class FA_Aegis_5Rnd_127x99_Mk258_T_Yellow : FA_Aegis_5Rnd_127x99_Mk258 { displayName = "[JMSB] 5Rnd 12.7mm Mk258 - Yellow Tracer"; descriptionShort = "Mk258 LRP"; ammo = "FA_b_127x99_Mk258_LRP_T_Yellow"; tracersEvery = 4; };
    class FA_Aegis_5Rnd_127x99_Mk258_T_Green  : FA_Aegis_5Rnd_127x99_Mk258 { displayName = "[JMSB] 5Rnd 12.7mm Mk258 - Green Tracer";  descriptionShort = "Mk258 LRP";  ammo = "FA_b_127x99_Mk258_LRP_T_Green"; tracersEvery = 4; };
    class FA_Aegis_5Rnd_127x99_Mk258_T_White  : FA_Aegis_5Rnd_127x99_Mk258 { displayName = "[JMSB] 5Rnd 12.7mm Mk258 - White Tracer";  descriptionShort = "Mk258 LRP";  ammo = "FA_b_127x99_Mk258_LRP_T_White"; tracersEvery = 4; };
    class FA_Aegis_5Rnd_127x99_Mk258_T_Blue   : FA_Aegis_5Rnd_127x99_Mk258 { displayName = "[JMSB] 5Rnd 12.7mm Mk258 - Blue Tracer";   descriptionShort = "Mk258 LRP";   ammo = "FA_b_127x99_Mk258_LRP_T_Blue"; tracersEvery = 4; };
    class FA_Aegis_5Rnd_127x99_Mk258_T_Orange : FA_Aegis_5Rnd_127x99_Mk258 { displayName = "[JMSB] 5Rnd 12.7mm Mk258 - Orange Tracer"; descriptionShort = "Mk258 LRP"; ammo = "FA_b_127x99_Mk258_LRP_T_Orange"; tracersEvery = 4; };
    class FA_Aegis_5Rnd_127x99_Mk258_T_IR     : FA_Aegis_5Rnd_127x99_Mk258 { displayName = "[JMSB] 5Rnd 12.7mm Mk258 - IR Tracer";     descriptionShort = "Mk258 LRP";     ammo = "FA_b_127x99_Mk258_LRP_T_IR"; tracersEvery = 4; };

    class FA_Aegis_5Rnd_127x99_Mk211Mod0: EGVAR(weapons,5Rnd_127x99_Mag) {
        author = QAUTHOR;
        displayName = "[JMSB] 5Rnd Mk211Mod0 AP";
        descriptionShort = "Mk211Mod0 AP";
        ammo = "FA_b_127x99_Mk211Mod0_AP";
        initSpeed = 890;
    };
    class FA_Aegis_5Rnd_127x99_Mk211Mod0_T_Red    : FA_Aegis_5Rnd_127x99_Mk211Mod0 { displayName = "[JMSB] 5Rnd 12.7mm Mk211Mod0 - Red Tracer";    descriptionShort = "Mk211Mod0 AP";    ammo = "FA_b_127x99_Mk211Mod0_AP_T_Red"; tracersEvery = 4; };
    class FA_Aegis_5Rnd_127x99_Mk211Mod0_T_Yellow : FA_Aegis_5Rnd_127x99_Mk211Mod0 { displayName = "[JMSB] 5Rnd 12.7mm Mk211Mod0 - Yellow Tracer"; descriptionShort = "Mk211Mod0 AP"; ammo = "FA_b_127x99_Mk211Mod0_AP_T_Yellow"; tracersEvery = 4; };
    class FA_Aegis_5Rnd_127x99_Mk211Mod0_T_Green  : FA_Aegis_5Rnd_127x99_Mk211Mod0 { displayName = "[JMSB] 5Rnd 12.7mm Mk211Mod0 - Green Tracer";  descriptionShort = "Mk211Mod0 AP";  ammo = "FA_b_127x99_Mk211Mod0_AP_T_Green"; tracersEvery = 4; };
    class FA_Aegis_5Rnd_127x99_Mk211Mod0_T_White  : FA_Aegis_5Rnd_127x99_Mk211Mod0 { displayName = "[JMSB] 5Rnd 12.7mm Mk211Mod0 - White Tracer";  descriptionShort = "Mk211Mod0 AP";  ammo = "FA_b_127x99_Mk211Mod0_AP_T_White"; tracersEvery = 4; };
    class FA_Aegis_5Rnd_127x99_Mk211Mod0_T_Blue   : FA_Aegis_5Rnd_127x99_Mk211Mod0 { displayName = "[JMSB] 5Rnd 12.7mm Mk211Mod0 - Blue Tracer";   descriptionShort = "Mk211Mod0 AP";   ammo = "FA_b_127x99_Mk211Mod0_AP_T_Blue"; tracersEvery = 4; };
    class FA_Aegis_5Rnd_127x99_Mk211Mod0_T_Orange : FA_Aegis_5Rnd_127x99_Mk211Mod0 { displayName = "[JMSB] 5Rnd 12.7mm Mk211Mod0 - Orange Tracer"; descriptionShort = "Mk211Mod0 AP"; ammo = "FA_b_127x99_Mk211Mod0_AP_T_Orange"; tracersEvery = 4; };
    class FA_Aegis_5Rnd_127x99_Mk211Mod0_T_IR     : FA_Aegis_5Rnd_127x99_Mk211Mod0 { displayName = "[JMSB] 5Rnd 12.7mm Mk211Mod0 - IR Tracer";     descriptionShort = "Mk211Mod0 AP";     ammo = "FA_b_127x99_Mk211Mod0_AP_T_IR"; tracersEvery = 4; };

    // =========================================================
    // 5.45x39 AK-12 / RPK-74 (AK_545x39) — FA 7N44 / 7N48 / 7U5
    // =========================================================
    // 7N44 Osa — 30Rnd (AK-12)
    class FA_Aegis_30Rnd_545x39_7N44: EGVAR(weapons,30Rnd_545x39_AK12_Mag_F) {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 7N44 HP";
        descriptionShort = "7N44 HP";
        ammo = "FA_o_545x39_7N44_HP";
        initSpeed = 925;
    };
    class FA_Aegis_30Rnd_545x39_7N44_T_Red    : FA_Aegis_30Rnd_545x39_7N44 { displayName = "[JMSB] 30Rnd 5.45mm 7N44 - Red Tracer";    descriptionShort = "7N44 HP";    ammo = "FA_o_545x39_7N44_HP_T_Red"; tracersEvery = 4; };
    class FA_Aegis_30Rnd_545x39_7N44_T_Yellow : FA_Aegis_30Rnd_545x39_7N44 { displayName = "[JMSB] 30Rnd 5.45mm 7N44 - Yellow Tracer"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Yellow"; tracersEvery = 4; };
    class FA_Aegis_30Rnd_545x39_7N44_T_Green  : FA_Aegis_30Rnd_545x39_7N44 { displayName = "[JMSB] 30Rnd 5.45mm 7N44 - Green Tracer";  descriptionShort = "7N44 HP";  ammo = "FA_o_545x39_7N44_HP_T_Green"; tracersEvery = 4; };
    class FA_Aegis_30Rnd_545x39_7N44_T_White  : FA_Aegis_30Rnd_545x39_7N44 { displayName = "[JMSB] 30Rnd 5.45mm 7N44 - White Tracer";  descriptionShort = "7N44 HP";  ammo = "FA_o_545x39_7N44_HP_T_White"; tracersEvery = 4; };
    class FA_Aegis_30Rnd_545x39_7N44_T_Blue   : FA_Aegis_30Rnd_545x39_7N44 { displayName = "[JMSB] 30Rnd 5.45mm 7N44 - Blue Tracer";   descriptionShort = "7N44 HP";   ammo = "FA_o_545x39_7N44_HP_T_Blue"; tracersEvery = 4; };
    class FA_Aegis_30Rnd_545x39_7N44_T_Orange : FA_Aegis_30Rnd_545x39_7N44 { displayName = "[JMSB] 30Rnd 5.45mm 7N44 - Orange Tracer"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Orange"; tracersEvery = 4; };
    class FA_Aegis_30Rnd_545x39_7N44_T_IR     : FA_Aegis_30Rnd_545x39_7N44 { displayName = "[JMSB] 30Rnd 5.45mm 7N44 - IR Tracer";     descriptionShort = "7N44 HP";     ammo = "FA_o_545x39_7N44_HP_T_IR"; tracersEvery = 4; };

    // 7N44 Osa — 45Rnd (RPK-74)
    class FA_Aegis_45Rnd_545x39_7N44: EGVAR(weapons,45Rnd_545x39_Mag_F) {
        author = QAUTHOR;
        displayName = "[JMSB] 45Rnd 7N44 HP";
        descriptionShort = "7N44 HP";
        ammo = "FA_o_545x39_7N44_HP";
        initSpeed = 925;
    };
    class FA_Aegis_45Rnd_545x39_7N44_T_Red    : FA_Aegis_45Rnd_545x39_7N44 { displayName = "[JMSB] 45Rnd 5.45mm 7N44 - Red Tracer";    descriptionShort = "7N44 HP";    ammo = "FA_o_545x39_7N44_HP_T_Red"; tracersEvery = 4; };
    class FA_Aegis_45Rnd_545x39_7N44_T_Yellow : FA_Aegis_45Rnd_545x39_7N44 { displayName = "[JMSB] 45Rnd 5.45mm 7N44 - Yellow Tracer"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Yellow"; tracersEvery = 4; };
    class FA_Aegis_45Rnd_545x39_7N44_T_Green  : FA_Aegis_45Rnd_545x39_7N44 { displayName = "[JMSB] 45Rnd 5.45mm 7N44 - Green Tracer";  descriptionShort = "7N44 HP";  ammo = "FA_o_545x39_7N44_HP_T_Green"; tracersEvery = 4; };
    class FA_Aegis_45Rnd_545x39_7N44_T_White  : FA_Aegis_45Rnd_545x39_7N44 { displayName = "[JMSB] 45Rnd 5.45mm 7N44 - White Tracer";  descriptionShort = "7N44 HP";  ammo = "FA_o_545x39_7N44_HP_T_White"; tracersEvery = 4; };
    class FA_Aegis_45Rnd_545x39_7N44_T_Blue   : FA_Aegis_45Rnd_545x39_7N44 { displayName = "[JMSB] 45Rnd 5.45mm 7N44 - Blue Tracer";   descriptionShort = "7N44 HP";   ammo = "FA_o_545x39_7N44_HP_T_Blue"; tracersEvery = 4; };
    class FA_Aegis_45Rnd_545x39_7N44_T_Orange : FA_Aegis_45Rnd_545x39_7N44 { displayName = "[JMSB] 45Rnd 5.45mm 7N44 - Orange Tracer"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Orange"; tracersEvery = 4; };
    class FA_Aegis_45Rnd_545x39_7N44_T_IR     : FA_Aegis_45Rnd_545x39_7N44 { displayName = "[JMSB] 45Rnd 5.45mm 7N44 - IR Tracer";     descriptionShort = "7N44 HP";     ammo = "FA_o_545x39_7N44_HP_T_IR"; tracersEvery = 4; };

    // 7N44 Osa — 60Rnd (AK-12 drum)
    class FA_Aegis_60Rnd_545x39_7N44: EGVAR(weapons,60Rnd_545x39_Mag_F) {
        author = QAUTHOR;
        displayName = "[JMSB] 60Rnd 7N44 HP";
        descriptionShort = "7N44 HP";
        ammo = "FA_o_545x39_7N44_HP";
        initSpeed = 925;
    };
    class FA_Aegis_60Rnd_545x39_7N44_T_Red    : FA_Aegis_60Rnd_545x39_7N44 { displayName = "[JMSB] 60Rnd 5.45mm 7N44 - Red Tracer";    descriptionShort = "7N44 HP";    ammo = "FA_o_545x39_7N44_HP_T_Red"; tracersEvery = 4; };
    class FA_Aegis_60Rnd_545x39_7N44_T_Yellow : FA_Aegis_60Rnd_545x39_7N44 { displayName = "[JMSB] 60Rnd 5.45mm 7N44 - Yellow Tracer"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Yellow"; tracersEvery = 4; };
    class FA_Aegis_60Rnd_545x39_7N44_T_Green  : FA_Aegis_60Rnd_545x39_7N44 { displayName = "[JMSB] 60Rnd 5.45mm 7N44 - Green Tracer";  descriptionShort = "7N44 HP";  ammo = "FA_o_545x39_7N44_HP_T_Green"; tracersEvery = 4; };
    class FA_Aegis_60Rnd_545x39_7N44_T_White  : FA_Aegis_60Rnd_545x39_7N44 { displayName = "[JMSB] 60Rnd 5.45mm 7N44 - White Tracer";  descriptionShort = "7N44 HP";  ammo = "FA_o_545x39_7N44_HP_T_White"; tracersEvery = 4; };
    class FA_Aegis_60Rnd_545x39_7N44_T_Blue   : FA_Aegis_60Rnd_545x39_7N44 { displayName = "[JMSB] 60Rnd 5.45mm 7N44 - Blue Tracer";   descriptionShort = "7N44 HP";   ammo = "FA_o_545x39_7N44_HP_T_Blue"; tracersEvery = 4; };
    class FA_Aegis_60Rnd_545x39_7N44_T_Orange : FA_Aegis_60Rnd_545x39_7N44 { displayName = "[JMSB] 60Rnd 5.45mm 7N44 - Orange Tracer"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Orange"; tracersEvery = 4; };
    class FA_Aegis_60Rnd_545x39_7N44_T_IR     : FA_Aegis_60Rnd_545x39_7N44 { displayName = "[JMSB] 60Rnd 5.45mm 7N44 - IR Tracer";     descriptionShort = "7N44 HP";     ammo = "FA_o_545x39_7N44_HP_T_IR"; tracersEvery = 4; };

    // 7N48 Osa-2 — 30Rnd (AK-12)
    class FA_Aegis_30Rnd_545x39_7N48: EGVAR(weapons,30Rnd_545x39_AK12_Mag_F) {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 7N48 CT";
        descriptionShort = "7N48 CT";
        ammo = "FA_o_545x39_7N48_CT";
        initSpeed = 950;
    };
    class FA_Aegis_30Rnd_545x39_7N48_T_Red    : FA_Aegis_30Rnd_545x39_7N48 { displayName = "[JMSB] 30Rnd 5.45mm 7N48 - Red Tracer";    descriptionShort = "7N48 CT";    ammo = "FA_o_545x39_7N48_CT_T_Red"; tracersEvery = 4; };
    class FA_Aegis_30Rnd_545x39_7N48_T_Yellow : FA_Aegis_30Rnd_545x39_7N48 { displayName = "[JMSB] 30Rnd 5.45mm 7N48 - Yellow Tracer"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Yellow"; tracersEvery = 4; };
    class FA_Aegis_30Rnd_545x39_7N48_T_Green  : FA_Aegis_30Rnd_545x39_7N48 { displayName = "[JMSB] 30Rnd 5.45mm 7N48 - Green Tracer";  descriptionShort = "7N48 CT";  ammo = "FA_o_545x39_7N48_CT_T_Green"; tracersEvery = 4; };
    class FA_Aegis_30Rnd_545x39_7N48_T_White  : FA_Aegis_30Rnd_545x39_7N48 { displayName = "[JMSB] 30Rnd 5.45mm 7N48 - White Tracer";  descriptionShort = "7N48 CT";  ammo = "FA_o_545x39_7N48_CT_T_White"; tracersEvery = 4; };
    class FA_Aegis_30Rnd_545x39_7N48_T_Blue   : FA_Aegis_30Rnd_545x39_7N48 { displayName = "[JMSB] 30Rnd 5.45mm 7N48 - Blue Tracer";   descriptionShort = "7N48 CT";   ammo = "FA_o_545x39_7N48_CT_T_Blue"; tracersEvery = 4; };
    class FA_Aegis_30Rnd_545x39_7N48_T_Orange : FA_Aegis_30Rnd_545x39_7N48 { displayName = "[JMSB] 30Rnd 5.45mm 7N48 - Orange Tracer"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Orange"; tracersEvery = 4; };
    class FA_Aegis_30Rnd_545x39_7N48_T_IR     : FA_Aegis_30Rnd_545x39_7N48 { displayName = "[JMSB] 30Rnd 5.45mm 7N48 - IR Tracer";     descriptionShort = "7N48 CT";     ammo = "FA_o_545x39_7N48_CT_T_IR"; tracersEvery = 4; };

    // 7N48 Osa-2 — 45Rnd (RPK-74)
    class FA_Aegis_45Rnd_545x39_7N48: EGVAR(weapons,45Rnd_545x39_Mag_F) {
        author = QAUTHOR;
        displayName = "[JMSB] 45Rnd 7N48 CT";
        descriptionShort = "7N48 CT";
        ammo = "FA_o_545x39_7N48_CT";
        initSpeed = 950;
    };
    class FA_Aegis_45Rnd_545x39_7N48_T_Red    : FA_Aegis_45Rnd_545x39_7N48 { displayName = "[JMSB] 45Rnd 5.45mm 7N48 - Red Tracer";    descriptionShort = "7N48 CT";    ammo = "FA_o_545x39_7N48_CT_T_Red"; tracersEvery = 4; };
    class FA_Aegis_45Rnd_545x39_7N48_T_Yellow : FA_Aegis_45Rnd_545x39_7N48 { displayName = "[JMSB] 45Rnd 5.45mm 7N48 - Yellow Tracer"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Yellow"; tracersEvery = 4; };
    class FA_Aegis_45Rnd_545x39_7N48_T_Green  : FA_Aegis_45Rnd_545x39_7N48 { displayName = "[JMSB] 45Rnd 5.45mm 7N48 - Green Tracer";  descriptionShort = "7N48 CT";  ammo = "FA_o_545x39_7N48_CT_T_Green"; tracersEvery = 4; };
    class FA_Aegis_45Rnd_545x39_7N48_T_White  : FA_Aegis_45Rnd_545x39_7N48 { displayName = "[JMSB] 45Rnd 5.45mm 7N48 - White Tracer";  descriptionShort = "7N48 CT";  ammo = "FA_o_545x39_7N48_CT_T_White"; tracersEvery = 4; };
    class FA_Aegis_45Rnd_545x39_7N48_T_Blue   : FA_Aegis_45Rnd_545x39_7N48 { displayName = "[JMSB] 45Rnd 5.45mm 7N48 - Blue Tracer";   descriptionShort = "7N48 CT";   ammo = "FA_o_545x39_7N48_CT_T_Blue"; tracersEvery = 4; };
    class FA_Aegis_45Rnd_545x39_7N48_T_Orange : FA_Aegis_45Rnd_545x39_7N48 { displayName = "[JMSB] 45Rnd 5.45mm 7N48 - Orange Tracer"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Orange"; tracersEvery = 4; };
    class FA_Aegis_45Rnd_545x39_7N48_T_IR     : FA_Aegis_45Rnd_545x39_7N48 { displayName = "[JMSB] 45Rnd 5.45mm 7N48 - IR Tracer";     descriptionShort = "7N48 CT";     ammo = "FA_o_545x39_7N48_CT_T_IR"; tracersEvery = 4; };

    // 7U5 Tishina-5 — 30Rnd (AK-12) subsonic
    class FA_Aegis_30Rnd_545x39_7U5: EGVAR(weapons,30Rnd_545x39_AK12_Mag_F) {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 7U5 SubAP";
        descriptionShort = "7U5 SubAP";
        ammo = "FA_o_545x39_7U5_SubAP";
        initSpeed = 303;
    };
    class FA_Aegis_30Rnd_545x39_7U5_T_Red    : FA_Aegis_30Rnd_545x39_7U5 { displayName = "[JMSB] 30Rnd 5.45mm 7U5 - Red Tracer";    descriptionShort = "7U5 SubAP";    ammo = "FA_o_545x39_7U5_SubAP_T_Red"; tracersEvery = 4; };
    class FA_Aegis_30Rnd_545x39_7U5_T_Yellow : FA_Aegis_30Rnd_545x39_7U5 { displayName = "[JMSB] 30Rnd 5.45mm 7U5 - Yellow Tracer"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_Yellow"; tracersEvery = 4; };
    class FA_Aegis_30Rnd_545x39_7U5_T_Green  : FA_Aegis_30Rnd_545x39_7U5 { displayName = "[JMSB] 30Rnd 5.45mm 7U5 - Green Tracer";  descriptionShort = "7U5 SubAP";  ammo = "FA_o_545x39_7U5_SubAP_T_Green"; tracersEvery = 4; };
    class FA_Aegis_30Rnd_545x39_7U5_T_White  : FA_Aegis_30Rnd_545x39_7U5 { displayName = "[JMSB] 30Rnd 5.45mm 7U5 - White Tracer";  descriptionShort = "7U5 SubAP";  ammo = "FA_o_545x39_7U5_SubAP_T_White"; tracersEvery = 4; };
    class FA_Aegis_30Rnd_545x39_7U5_T_Blue   : FA_Aegis_30Rnd_545x39_7U5 { displayName = "[JMSB] 30Rnd 5.45mm 7U5 - Blue Tracer";   descriptionShort = "7U5 SubAP";   ammo = "FA_o_545x39_7U5_SubAP_T_Blue"; tracersEvery = 4; };
    class FA_Aegis_30Rnd_545x39_7U5_T_Orange : FA_Aegis_30Rnd_545x39_7U5 { displayName = "[JMSB] 30Rnd 5.45mm 7U5 - Orange Tracer"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_Orange"; tracersEvery = 4; };
    class FA_Aegis_30Rnd_545x39_7U5_T_IR     : FA_Aegis_30Rnd_545x39_7U5 { displayName = "[JMSB] 30Rnd 5.45mm 7U5 - IR Tracer";     descriptionShort = "7U5 SubAP";     ammo = "FA_o_545x39_7U5_SubAP_T_IR"; tracersEvery = 4; };

};
