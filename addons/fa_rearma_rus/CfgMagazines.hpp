// FA rounds on rearma's own Russian magazine bodies, so the arsenal and the
// weapon show the right model. Every magazine joins the rearma well its body
// already lives in (CfgMagazinewells.hpp). Rifle / MG loads carry the full
// tracer set; shot, pistol and underwater loads have none. Drum and belt
// bodies that fire a tracer every third round are reset so tracers only come
// from the _T_ variants.
class CfgMagazines {
    class 30Rnd_545x39_AK35_Mag_F;
    class 30Rnd_545x39_AK35_Camo_Mag_F;
    class 45Rnd_545x39_AK35_Mag_F;
    class 45Rnd_545x39_AK35_Camo_Mag_F;
    class 95Rnd_545x39_RPK35_Drum_F;
    class 95Rnd_545x39_RPK35_Drum_Camo_F;
    class 30Rnd_SG_AK35_Mag_F;
    class 30Rnd_SG_AK35_Camo_Mag_F;
    class 30Rnd_545x39UW_ADS35_Mag_F;
    class 200Rnd_545x39_RPL_Reload_Tracer_Green_Mag;
    class 100Rnd_762x54_PK_Reload_Tracer_Green_Mag;
    class 10Rnd_762X54R_SVCh;
    class 10Rnd_338_SVCh;
    class 17Rnd_9x19_MP443_Mag_F;
    class 5Rnd_23mm_Pellets;
    class 5Rnd_23mm_Slug;
    class RPG26_M;
    class RSHG2_M;

    // ===== 30Rnd 5.45x39 - AK35 family - body 30Rnd_545x39_AK35_Mag_F =====
    class FA_rearma_30Rnd_545x39_7N44_HP: 30Rnd_545x39_AK35_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 5.45mm 7N44 HP";
        displayNameShort = "7N44 HP";
        descriptionShort = "7N44 HP";
        ammo = "FA_o_545x39_7N44_HP";
        initSpeed = 925;
    };
    class FA_rearma_30Rnd_545x39_7N44_HP_T_Red: FA_rearma_30Rnd_545x39_7N44_HP { displayName = "[JMSB] 30Rnd 5.45mm 7N44 HP - Red Tracer"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Red"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_7N44_HP_T_Yellow: FA_rearma_30Rnd_545x39_7N44_HP { displayName = "[JMSB] 30Rnd 5.45mm 7N44 HP - Yellow Tracer"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_7N44_HP_T_Green: FA_rearma_30Rnd_545x39_7N44_HP { displayName = "[JMSB] 30Rnd 5.45mm 7N44 HP - Green Tracer"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Green"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_7N44_HP_T_White: FA_rearma_30Rnd_545x39_7N44_HP { displayName = "[JMSB] 30Rnd 5.45mm 7N44 HP - White Tracer"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_White"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_7N44_HP_T_Blue: FA_rearma_30Rnd_545x39_7N44_HP { displayName = "[JMSB] 30Rnd 5.45mm 7N44 HP - Blue Tracer"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Blue"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_7N44_HP_T_Orange: FA_rearma_30Rnd_545x39_7N44_HP { displayName = "[JMSB] 30Rnd 5.45mm 7N44 HP - Orange Tracer"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Orange"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_7N44_HP_T_IR: FA_rearma_30Rnd_545x39_7N44_HP { displayName = "[JMSB] 30Rnd 5.45mm 7N44 HP - IR Tracer"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_IR"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_7N48_CT: 30Rnd_545x39_AK35_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 5.45mm 7N48 CT";
        displayNameShort = "7N48 CT";
        descriptionShort = "7N48 CT";
        ammo = "FA_o_545x39_7N48_CT";
        initSpeed = 950;
    };
    class FA_rearma_30Rnd_545x39_7N48_CT_T_Red: FA_rearma_30Rnd_545x39_7N48_CT { displayName = "[JMSB] 30Rnd 5.45mm 7N48 CT - Red Tracer"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Red"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_7N48_CT_T_Yellow: FA_rearma_30Rnd_545x39_7N48_CT { displayName = "[JMSB] 30Rnd 5.45mm 7N48 CT - Yellow Tracer"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_7N48_CT_T_Green: FA_rearma_30Rnd_545x39_7N48_CT { displayName = "[JMSB] 30Rnd 5.45mm 7N48 CT - Green Tracer"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Green"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_7N48_CT_T_White: FA_rearma_30Rnd_545x39_7N48_CT { displayName = "[JMSB] 30Rnd 5.45mm 7N48 CT - White Tracer"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_White"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_7N48_CT_T_Blue: FA_rearma_30Rnd_545x39_7N48_CT { displayName = "[JMSB] 30Rnd 5.45mm 7N48 CT - Blue Tracer"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Blue"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_7N48_CT_T_Orange: FA_rearma_30Rnd_545x39_7N48_CT { displayName = "[JMSB] 30Rnd 5.45mm 7N48 CT - Orange Tracer"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Orange"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_7N48_CT_T_IR: FA_rearma_30Rnd_545x39_7N48_CT { displayName = "[JMSB] 30Rnd 5.45mm 7N48 CT - IR Tracer"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_IR"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_7U5_SubAP: 30Rnd_545x39_AK35_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 5.45mm 7U5 SubAP";
        displayNameShort = "7U5 SubAP";
        descriptionShort = "7U5 SubAP";
        ammo = "FA_o_545x39_7U5_SubAP";
        initSpeed = 303;
    };
    class FA_rearma_30Rnd_545x39_7U5_SubAP_T_Red: FA_rearma_30Rnd_545x39_7U5_SubAP { displayName = "[JMSB] 30Rnd 5.45mm 7U5 SubAP - Red Tracer"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_Red"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_7U5_SubAP_T_Yellow: FA_rearma_30Rnd_545x39_7U5_SubAP { displayName = "[JMSB] 30Rnd 5.45mm 7U5 SubAP - Yellow Tracer"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_7U5_SubAP_T_Green: FA_rearma_30Rnd_545x39_7U5_SubAP { displayName = "[JMSB] 30Rnd 5.45mm 7U5 SubAP - Green Tracer"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_Green"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_7U5_SubAP_T_White: FA_rearma_30Rnd_545x39_7U5_SubAP { displayName = "[JMSB] 30Rnd 5.45mm 7U5 SubAP - White Tracer"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_White"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_7U5_SubAP_T_Blue: FA_rearma_30Rnd_545x39_7U5_SubAP { displayName = "[JMSB] 30Rnd 5.45mm 7U5 SubAP - Blue Tracer"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_Blue"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_7U5_SubAP_T_Orange: FA_rearma_30Rnd_545x39_7U5_SubAP { displayName = "[JMSB] 30Rnd 5.45mm 7U5 SubAP - Orange Tracer"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_Orange"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_7U5_SubAP_T_IR: FA_rearma_30Rnd_545x39_7U5_SubAP { displayName = "[JMSB] 30Rnd 5.45mm 7U5 SubAP - IR Tracer"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_IR"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_7N55_HEAB: 30Rnd_545x39_AK35_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 5.45mm 7N55 HEAB";
        displayNameShort = "7N55 HEAB";
        descriptionShort = "7N55 HEAB airburst, counter-UAS";
        ammo = "FA_o_545x39_7N55_HEAB";
        initSpeed = 925;
    };
    class FA_rearma_30Rnd_545x39_7N55_HEAB_T_Red: FA_rearma_30Rnd_545x39_7N55_HEAB { displayName = "[JMSB] 30Rnd 5.45mm 7N55 HEAB - Red Tracer"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_Red"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_7N55_HEAB_T_Yellow: FA_rearma_30Rnd_545x39_7N55_HEAB { displayName = "[JMSB] 30Rnd 5.45mm 7N55 HEAB - Yellow Tracer"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_7N55_HEAB_T_Green: FA_rearma_30Rnd_545x39_7N55_HEAB { displayName = "[JMSB] 30Rnd 5.45mm 7N55 HEAB - Green Tracer"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_Green"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_7N55_HEAB_T_White: FA_rearma_30Rnd_545x39_7N55_HEAB { displayName = "[JMSB] 30Rnd 5.45mm 7N55 HEAB - White Tracer"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_White"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_7N55_HEAB_T_Blue: FA_rearma_30Rnd_545x39_7N55_HEAB { displayName = "[JMSB] 30Rnd 5.45mm 7N55 HEAB - Blue Tracer"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_Blue"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_7N55_HEAB_T_Orange: FA_rearma_30Rnd_545x39_7N55_HEAB { displayName = "[JMSB] 30Rnd 5.45mm 7N55 HEAB - Orange Tracer"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_Orange"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_7N55_HEAB_T_IR: FA_rearma_30Rnd_545x39_7N55_HEAB { displayName = "[JMSB] 30Rnd 5.45mm 7N55 HEAB - IR Tracer"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_IR"; tracersEvery = 4; };

    // ===== 30Rnd 5.45x39 camo - AK35 family - body 30Rnd_545x39_AK35_Camo_Mag_F =====
    class FA_rearma_30Rnd_545x39_Camo_7N44_HP: 30Rnd_545x39_AK35_Camo_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 5.45mm 7N44 HP - Camo";
        displayNameShort = "7N44 HP";
        descriptionShort = "7N44 HP";
        ammo = "FA_o_545x39_7N44_HP";
        initSpeed = 925;
    };
    class FA_rearma_30Rnd_545x39_Camo_7N44_HP_T_Red: FA_rearma_30Rnd_545x39_Camo_7N44_HP { displayName = "[JMSB] 30Rnd 5.45mm 7N44 HP - Red Tracer, Camo"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Red"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_Camo_7N44_HP_T_Yellow: FA_rearma_30Rnd_545x39_Camo_7N44_HP { displayName = "[JMSB] 30Rnd 5.45mm 7N44 HP - Yellow Tracer, Camo"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_Camo_7N44_HP_T_Green: FA_rearma_30Rnd_545x39_Camo_7N44_HP { displayName = "[JMSB] 30Rnd 5.45mm 7N44 HP - Green Tracer, Camo"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Green"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_Camo_7N44_HP_T_White: FA_rearma_30Rnd_545x39_Camo_7N44_HP { displayName = "[JMSB] 30Rnd 5.45mm 7N44 HP - White Tracer, Camo"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_White"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_Camo_7N44_HP_T_Blue: FA_rearma_30Rnd_545x39_Camo_7N44_HP { displayName = "[JMSB] 30Rnd 5.45mm 7N44 HP - Blue Tracer, Camo"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Blue"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_Camo_7N44_HP_T_Orange: FA_rearma_30Rnd_545x39_Camo_7N44_HP { displayName = "[JMSB] 30Rnd 5.45mm 7N44 HP - Orange Tracer, Camo"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Orange"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_Camo_7N44_HP_T_IR: FA_rearma_30Rnd_545x39_Camo_7N44_HP { displayName = "[JMSB] 30Rnd 5.45mm 7N44 HP - IR Tracer, Camo"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_IR"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_Camo_7N48_CT: 30Rnd_545x39_AK35_Camo_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 5.45mm 7N48 CT - Camo";
        displayNameShort = "7N48 CT";
        descriptionShort = "7N48 CT";
        ammo = "FA_o_545x39_7N48_CT";
        initSpeed = 950;
    };
    class FA_rearma_30Rnd_545x39_Camo_7N48_CT_T_Red: FA_rearma_30Rnd_545x39_Camo_7N48_CT { displayName = "[JMSB] 30Rnd 5.45mm 7N48 CT - Red Tracer, Camo"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Red"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_Camo_7N48_CT_T_Yellow: FA_rearma_30Rnd_545x39_Camo_7N48_CT { displayName = "[JMSB] 30Rnd 5.45mm 7N48 CT - Yellow Tracer, Camo"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_Camo_7N48_CT_T_Green: FA_rearma_30Rnd_545x39_Camo_7N48_CT { displayName = "[JMSB] 30Rnd 5.45mm 7N48 CT - Green Tracer, Camo"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Green"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_Camo_7N48_CT_T_White: FA_rearma_30Rnd_545x39_Camo_7N48_CT { displayName = "[JMSB] 30Rnd 5.45mm 7N48 CT - White Tracer, Camo"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_White"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_Camo_7N48_CT_T_Blue: FA_rearma_30Rnd_545x39_Camo_7N48_CT { displayName = "[JMSB] 30Rnd 5.45mm 7N48 CT - Blue Tracer, Camo"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Blue"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_Camo_7N48_CT_T_Orange: FA_rearma_30Rnd_545x39_Camo_7N48_CT { displayName = "[JMSB] 30Rnd 5.45mm 7N48 CT - Orange Tracer, Camo"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Orange"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_Camo_7N48_CT_T_IR: FA_rearma_30Rnd_545x39_Camo_7N48_CT { displayName = "[JMSB] 30Rnd 5.45mm 7N48 CT - IR Tracer, Camo"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_IR"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_Camo_7U5_SubAP: 30Rnd_545x39_AK35_Camo_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 5.45mm 7U5 SubAP - Camo";
        displayNameShort = "7U5 SubAP";
        descriptionShort = "7U5 SubAP";
        ammo = "FA_o_545x39_7U5_SubAP";
        initSpeed = 303;
    };
    class FA_rearma_30Rnd_545x39_Camo_7U5_SubAP_T_Red: FA_rearma_30Rnd_545x39_Camo_7U5_SubAP { displayName = "[JMSB] 30Rnd 5.45mm 7U5 SubAP - Red Tracer, Camo"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_Red"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_Camo_7U5_SubAP_T_Yellow: FA_rearma_30Rnd_545x39_Camo_7U5_SubAP { displayName = "[JMSB] 30Rnd 5.45mm 7U5 SubAP - Yellow Tracer, Camo"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_Camo_7U5_SubAP_T_Green: FA_rearma_30Rnd_545x39_Camo_7U5_SubAP { displayName = "[JMSB] 30Rnd 5.45mm 7U5 SubAP - Green Tracer, Camo"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_Green"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_Camo_7U5_SubAP_T_White: FA_rearma_30Rnd_545x39_Camo_7U5_SubAP { displayName = "[JMSB] 30Rnd 5.45mm 7U5 SubAP - White Tracer, Camo"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_White"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_Camo_7U5_SubAP_T_Blue: FA_rearma_30Rnd_545x39_Camo_7U5_SubAP { displayName = "[JMSB] 30Rnd 5.45mm 7U5 SubAP - Blue Tracer, Camo"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_Blue"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_Camo_7U5_SubAP_T_Orange: FA_rearma_30Rnd_545x39_Camo_7U5_SubAP { displayName = "[JMSB] 30Rnd 5.45mm 7U5 SubAP - Orange Tracer, Camo"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_Orange"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_Camo_7U5_SubAP_T_IR: FA_rearma_30Rnd_545x39_Camo_7U5_SubAP { displayName = "[JMSB] 30Rnd 5.45mm 7U5 SubAP - IR Tracer, Camo"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_IR"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_Camo_7N55_HEAB: 30Rnd_545x39_AK35_Camo_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 5.45mm 7N55 HEAB - Camo";
        displayNameShort = "7N55 HEAB";
        descriptionShort = "7N55 HEAB airburst, counter-UAS";
        ammo = "FA_o_545x39_7N55_HEAB";
        initSpeed = 925;
    };
    class FA_rearma_30Rnd_545x39_Camo_7N55_HEAB_T_Red: FA_rearma_30Rnd_545x39_Camo_7N55_HEAB { displayName = "[JMSB] 30Rnd 5.45mm 7N55 HEAB - Red Tracer, Camo"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_Red"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_Camo_7N55_HEAB_T_Yellow: FA_rearma_30Rnd_545x39_Camo_7N55_HEAB { displayName = "[JMSB] 30Rnd 5.45mm 7N55 HEAB - Yellow Tracer, Camo"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_Camo_7N55_HEAB_T_Green: FA_rearma_30Rnd_545x39_Camo_7N55_HEAB { displayName = "[JMSB] 30Rnd 5.45mm 7N55 HEAB - Green Tracer, Camo"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_Green"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_Camo_7N55_HEAB_T_White: FA_rearma_30Rnd_545x39_Camo_7N55_HEAB { displayName = "[JMSB] 30Rnd 5.45mm 7N55 HEAB - White Tracer, Camo"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_White"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_Camo_7N55_HEAB_T_Blue: FA_rearma_30Rnd_545x39_Camo_7N55_HEAB { displayName = "[JMSB] 30Rnd 5.45mm 7N55 HEAB - Blue Tracer, Camo"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_Blue"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_Camo_7N55_HEAB_T_Orange: FA_rearma_30Rnd_545x39_Camo_7N55_HEAB { displayName = "[JMSB] 30Rnd 5.45mm 7N55 HEAB - Orange Tracer, Camo"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_Orange"; tracersEvery = 4; };
    class FA_rearma_30Rnd_545x39_Camo_7N55_HEAB_T_IR: FA_rearma_30Rnd_545x39_Camo_7N55_HEAB { displayName = "[JMSB] 30Rnd 5.45mm 7N55 HEAB - IR Tracer, Camo"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_IR"; tracersEvery = 4; };

    // ===== 45Rnd 5.45x39 - AK35 family - body 45Rnd_545x39_AK35_Mag_F =====
    class FA_rearma_45Rnd_545x39_7N44_HP: 45Rnd_545x39_AK35_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 45Rnd 5.45mm 7N44 HP";
        displayNameShort = "7N44 HP";
        descriptionShort = "7N44 HP";
        ammo = "FA_o_545x39_7N44_HP";
        initSpeed = 925;
    };
    class FA_rearma_45Rnd_545x39_7N44_HP_T_Red: FA_rearma_45Rnd_545x39_7N44_HP { displayName = "[JMSB] 45Rnd 5.45mm 7N44 HP - Red Tracer"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Red"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_7N44_HP_T_Yellow: FA_rearma_45Rnd_545x39_7N44_HP { displayName = "[JMSB] 45Rnd 5.45mm 7N44 HP - Yellow Tracer"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_7N44_HP_T_Green: FA_rearma_45Rnd_545x39_7N44_HP { displayName = "[JMSB] 45Rnd 5.45mm 7N44 HP - Green Tracer"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Green"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_7N44_HP_T_White: FA_rearma_45Rnd_545x39_7N44_HP { displayName = "[JMSB] 45Rnd 5.45mm 7N44 HP - White Tracer"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_White"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_7N44_HP_T_Blue: FA_rearma_45Rnd_545x39_7N44_HP { displayName = "[JMSB] 45Rnd 5.45mm 7N44 HP - Blue Tracer"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Blue"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_7N44_HP_T_Orange: FA_rearma_45Rnd_545x39_7N44_HP { displayName = "[JMSB] 45Rnd 5.45mm 7N44 HP - Orange Tracer"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Orange"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_7N44_HP_T_IR: FA_rearma_45Rnd_545x39_7N44_HP { displayName = "[JMSB] 45Rnd 5.45mm 7N44 HP - IR Tracer"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_IR"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_7N48_CT: 45Rnd_545x39_AK35_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 45Rnd 5.45mm 7N48 CT";
        displayNameShort = "7N48 CT";
        descriptionShort = "7N48 CT";
        ammo = "FA_o_545x39_7N48_CT";
        initSpeed = 950;
    };
    class FA_rearma_45Rnd_545x39_7N48_CT_T_Red: FA_rearma_45Rnd_545x39_7N48_CT { displayName = "[JMSB] 45Rnd 5.45mm 7N48 CT - Red Tracer"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Red"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_7N48_CT_T_Yellow: FA_rearma_45Rnd_545x39_7N48_CT { displayName = "[JMSB] 45Rnd 5.45mm 7N48 CT - Yellow Tracer"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_7N48_CT_T_Green: FA_rearma_45Rnd_545x39_7N48_CT { displayName = "[JMSB] 45Rnd 5.45mm 7N48 CT - Green Tracer"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Green"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_7N48_CT_T_White: FA_rearma_45Rnd_545x39_7N48_CT { displayName = "[JMSB] 45Rnd 5.45mm 7N48 CT - White Tracer"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_White"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_7N48_CT_T_Blue: FA_rearma_45Rnd_545x39_7N48_CT { displayName = "[JMSB] 45Rnd 5.45mm 7N48 CT - Blue Tracer"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Blue"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_7N48_CT_T_Orange: FA_rearma_45Rnd_545x39_7N48_CT { displayName = "[JMSB] 45Rnd 5.45mm 7N48 CT - Orange Tracer"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Orange"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_7N48_CT_T_IR: FA_rearma_45Rnd_545x39_7N48_CT { displayName = "[JMSB] 45Rnd 5.45mm 7N48 CT - IR Tracer"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_IR"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_7U5_SubAP: 45Rnd_545x39_AK35_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 45Rnd 5.45mm 7U5 SubAP";
        displayNameShort = "7U5 SubAP";
        descriptionShort = "7U5 SubAP";
        ammo = "FA_o_545x39_7U5_SubAP";
        initSpeed = 303;
    };
    class FA_rearma_45Rnd_545x39_7U5_SubAP_T_Red: FA_rearma_45Rnd_545x39_7U5_SubAP { displayName = "[JMSB] 45Rnd 5.45mm 7U5 SubAP - Red Tracer"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_Red"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_7U5_SubAP_T_Yellow: FA_rearma_45Rnd_545x39_7U5_SubAP { displayName = "[JMSB] 45Rnd 5.45mm 7U5 SubAP - Yellow Tracer"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_7U5_SubAP_T_Green: FA_rearma_45Rnd_545x39_7U5_SubAP { displayName = "[JMSB] 45Rnd 5.45mm 7U5 SubAP - Green Tracer"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_Green"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_7U5_SubAP_T_White: FA_rearma_45Rnd_545x39_7U5_SubAP { displayName = "[JMSB] 45Rnd 5.45mm 7U5 SubAP - White Tracer"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_White"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_7U5_SubAP_T_Blue: FA_rearma_45Rnd_545x39_7U5_SubAP { displayName = "[JMSB] 45Rnd 5.45mm 7U5 SubAP - Blue Tracer"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_Blue"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_7U5_SubAP_T_Orange: FA_rearma_45Rnd_545x39_7U5_SubAP { displayName = "[JMSB] 45Rnd 5.45mm 7U5 SubAP - Orange Tracer"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_Orange"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_7U5_SubAP_T_IR: FA_rearma_45Rnd_545x39_7U5_SubAP { displayName = "[JMSB] 45Rnd 5.45mm 7U5 SubAP - IR Tracer"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_IR"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_7N55_HEAB: 45Rnd_545x39_AK35_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 45Rnd 5.45mm 7N55 HEAB";
        displayNameShort = "7N55 HEAB";
        descriptionShort = "7N55 HEAB airburst, counter-UAS";
        ammo = "FA_o_545x39_7N55_HEAB";
        initSpeed = 925;
    };
    class FA_rearma_45Rnd_545x39_7N55_HEAB_T_Red: FA_rearma_45Rnd_545x39_7N55_HEAB { displayName = "[JMSB] 45Rnd 5.45mm 7N55 HEAB - Red Tracer"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_Red"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_7N55_HEAB_T_Yellow: FA_rearma_45Rnd_545x39_7N55_HEAB { displayName = "[JMSB] 45Rnd 5.45mm 7N55 HEAB - Yellow Tracer"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_7N55_HEAB_T_Green: FA_rearma_45Rnd_545x39_7N55_HEAB { displayName = "[JMSB] 45Rnd 5.45mm 7N55 HEAB - Green Tracer"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_Green"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_7N55_HEAB_T_White: FA_rearma_45Rnd_545x39_7N55_HEAB { displayName = "[JMSB] 45Rnd 5.45mm 7N55 HEAB - White Tracer"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_White"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_7N55_HEAB_T_Blue: FA_rearma_45Rnd_545x39_7N55_HEAB { displayName = "[JMSB] 45Rnd 5.45mm 7N55 HEAB - Blue Tracer"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_Blue"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_7N55_HEAB_T_Orange: FA_rearma_45Rnd_545x39_7N55_HEAB { displayName = "[JMSB] 45Rnd 5.45mm 7N55 HEAB - Orange Tracer"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_Orange"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_7N55_HEAB_T_IR: FA_rearma_45Rnd_545x39_7N55_HEAB { displayName = "[JMSB] 45Rnd 5.45mm 7N55 HEAB - IR Tracer"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_IR"; tracersEvery = 4; };

    // ===== 45Rnd 5.45x39 camo - AK35 family - body 45Rnd_545x39_AK35_Camo_Mag_F =====
    class FA_rearma_45Rnd_545x39_Camo_7N44_HP: 45Rnd_545x39_AK35_Camo_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 45Rnd 5.45mm 7N44 HP - Camo";
        displayNameShort = "7N44 HP";
        descriptionShort = "7N44 HP";
        ammo = "FA_o_545x39_7N44_HP";
        initSpeed = 925;
    };
    class FA_rearma_45Rnd_545x39_Camo_7N44_HP_T_Red: FA_rearma_45Rnd_545x39_Camo_7N44_HP { displayName = "[JMSB] 45Rnd 5.45mm 7N44 HP - Red Tracer, Camo"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Red"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_Camo_7N44_HP_T_Yellow: FA_rearma_45Rnd_545x39_Camo_7N44_HP { displayName = "[JMSB] 45Rnd 5.45mm 7N44 HP - Yellow Tracer, Camo"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_Camo_7N44_HP_T_Green: FA_rearma_45Rnd_545x39_Camo_7N44_HP { displayName = "[JMSB] 45Rnd 5.45mm 7N44 HP - Green Tracer, Camo"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Green"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_Camo_7N44_HP_T_White: FA_rearma_45Rnd_545x39_Camo_7N44_HP { displayName = "[JMSB] 45Rnd 5.45mm 7N44 HP - White Tracer, Camo"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_White"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_Camo_7N44_HP_T_Blue: FA_rearma_45Rnd_545x39_Camo_7N44_HP { displayName = "[JMSB] 45Rnd 5.45mm 7N44 HP - Blue Tracer, Camo"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Blue"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_Camo_7N44_HP_T_Orange: FA_rearma_45Rnd_545x39_Camo_7N44_HP { displayName = "[JMSB] 45Rnd 5.45mm 7N44 HP - Orange Tracer, Camo"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Orange"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_Camo_7N44_HP_T_IR: FA_rearma_45Rnd_545x39_Camo_7N44_HP { displayName = "[JMSB] 45Rnd 5.45mm 7N44 HP - IR Tracer, Camo"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_IR"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_Camo_7N48_CT: 45Rnd_545x39_AK35_Camo_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 45Rnd 5.45mm 7N48 CT - Camo";
        displayNameShort = "7N48 CT";
        descriptionShort = "7N48 CT";
        ammo = "FA_o_545x39_7N48_CT";
        initSpeed = 950;
    };
    class FA_rearma_45Rnd_545x39_Camo_7N48_CT_T_Red: FA_rearma_45Rnd_545x39_Camo_7N48_CT { displayName = "[JMSB] 45Rnd 5.45mm 7N48 CT - Red Tracer, Camo"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Red"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_Camo_7N48_CT_T_Yellow: FA_rearma_45Rnd_545x39_Camo_7N48_CT { displayName = "[JMSB] 45Rnd 5.45mm 7N48 CT - Yellow Tracer, Camo"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_Camo_7N48_CT_T_Green: FA_rearma_45Rnd_545x39_Camo_7N48_CT { displayName = "[JMSB] 45Rnd 5.45mm 7N48 CT - Green Tracer, Camo"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Green"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_Camo_7N48_CT_T_White: FA_rearma_45Rnd_545x39_Camo_7N48_CT { displayName = "[JMSB] 45Rnd 5.45mm 7N48 CT - White Tracer, Camo"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_White"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_Camo_7N48_CT_T_Blue: FA_rearma_45Rnd_545x39_Camo_7N48_CT { displayName = "[JMSB] 45Rnd 5.45mm 7N48 CT - Blue Tracer, Camo"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Blue"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_Camo_7N48_CT_T_Orange: FA_rearma_45Rnd_545x39_Camo_7N48_CT { displayName = "[JMSB] 45Rnd 5.45mm 7N48 CT - Orange Tracer, Camo"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Orange"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_Camo_7N48_CT_T_IR: FA_rearma_45Rnd_545x39_Camo_7N48_CT { displayName = "[JMSB] 45Rnd 5.45mm 7N48 CT - IR Tracer, Camo"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_IR"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_Camo_7U5_SubAP: 45Rnd_545x39_AK35_Camo_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 45Rnd 5.45mm 7U5 SubAP - Camo";
        displayNameShort = "7U5 SubAP";
        descriptionShort = "7U5 SubAP";
        ammo = "FA_o_545x39_7U5_SubAP";
        initSpeed = 303;
    };
    class FA_rearma_45Rnd_545x39_Camo_7U5_SubAP_T_Red: FA_rearma_45Rnd_545x39_Camo_7U5_SubAP { displayName = "[JMSB] 45Rnd 5.45mm 7U5 SubAP - Red Tracer, Camo"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_Red"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_Camo_7U5_SubAP_T_Yellow: FA_rearma_45Rnd_545x39_Camo_7U5_SubAP { displayName = "[JMSB] 45Rnd 5.45mm 7U5 SubAP - Yellow Tracer, Camo"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_Camo_7U5_SubAP_T_Green: FA_rearma_45Rnd_545x39_Camo_7U5_SubAP { displayName = "[JMSB] 45Rnd 5.45mm 7U5 SubAP - Green Tracer, Camo"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_Green"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_Camo_7U5_SubAP_T_White: FA_rearma_45Rnd_545x39_Camo_7U5_SubAP { displayName = "[JMSB] 45Rnd 5.45mm 7U5 SubAP - White Tracer, Camo"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_White"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_Camo_7U5_SubAP_T_Blue: FA_rearma_45Rnd_545x39_Camo_7U5_SubAP { displayName = "[JMSB] 45Rnd 5.45mm 7U5 SubAP - Blue Tracer, Camo"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_Blue"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_Camo_7U5_SubAP_T_Orange: FA_rearma_45Rnd_545x39_Camo_7U5_SubAP { displayName = "[JMSB] 45Rnd 5.45mm 7U5 SubAP - Orange Tracer, Camo"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_Orange"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_Camo_7U5_SubAP_T_IR: FA_rearma_45Rnd_545x39_Camo_7U5_SubAP { displayName = "[JMSB] 45Rnd 5.45mm 7U5 SubAP - IR Tracer, Camo"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_IR"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_Camo_7N55_HEAB: 45Rnd_545x39_AK35_Camo_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 45Rnd 5.45mm 7N55 HEAB - Camo";
        displayNameShort = "7N55 HEAB";
        descriptionShort = "7N55 HEAB airburst, counter-UAS";
        ammo = "FA_o_545x39_7N55_HEAB";
        initSpeed = 925;
    };
    class FA_rearma_45Rnd_545x39_Camo_7N55_HEAB_T_Red: FA_rearma_45Rnd_545x39_Camo_7N55_HEAB { displayName = "[JMSB] 45Rnd 5.45mm 7N55 HEAB - Red Tracer, Camo"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_Red"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_Camo_7N55_HEAB_T_Yellow: FA_rearma_45Rnd_545x39_Camo_7N55_HEAB { displayName = "[JMSB] 45Rnd 5.45mm 7N55 HEAB - Yellow Tracer, Camo"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_Camo_7N55_HEAB_T_Green: FA_rearma_45Rnd_545x39_Camo_7N55_HEAB { displayName = "[JMSB] 45Rnd 5.45mm 7N55 HEAB - Green Tracer, Camo"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_Green"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_Camo_7N55_HEAB_T_White: FA_rearma_45Rnd_545x39_Camo_7N55_HEAB { displayName = "[JMSB] 45Rnd 5.45mm 7N55 HEAB - White Tracer, Camo"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_White"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_Camo_7N55_HEAB_T_Blue: FA_rearma_45Rnd_545x39_Camo_7N55_HEAB { displayName = "[JMSB] 45Rnd 5.45mm 7N55 HEAB - Blue Tracer, Camo"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_Blue"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_Camo_7N55_HEAB_T_Orange: FA_rearma_45Rnd_545x39_Camo_7N55_HEAB { displayName = "[JMSB] 45Rnd 5.45mm 7N55 HEAB - Orange Tracer, Camo"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_Orange"; tracersEvery = 4; };
    class FA_rearma_45Rnd_545x39_Camo_7N55_HEAB_T_IR: FA_rearma_45Rnd_545x39_Camo_7N55_HEAB { displayName = "[JMSB] 45Rnd 5.45mm 7N55 HEAB - IR Tracer, Camo"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_IR"; tracersEvery = 4; };

    // ===== 95Rnd 5.45x39 drum - RPK35 - body 95Rnd_545x39_RPK35_Drum_F =====
    class FA_rearma_95Rnd_545x39_7N44_HP: 95Rnd_545x39_RPK35_Drum_F {
        author = QAUTHOR;
        displayName = "[JMSB] 95Rnd 5.45mm 7N44 HP";
        displayNameShort = "7N44 HP";
        descriptionShort = "7N44 HP";
        ammo = "FA_o_545x39_7N44_HP";
        initSpeed = 925;
        tracersEvery = 0;
    };
    class FA_rearma_95Rnd_545x39_7N44_HP_T_Red: FA_rearma_95Rnd_545x39_7N44_HP { displayName = "[JMSB] 95Rnd 5.45mm 7N44 HP - Red Tracer"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Red"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_7N44_HP_T_Yellow: FA_rearma_95Rnd_545x39_7N44_HP { displayName = "[JMSB] 95Rnd 5.45mm 7N44 HP - Yellow Tracer"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_7N44_HP_T_Green: FA_rearma_95Rnd_545x39_7N44_HP { displayName = "[JMSB] 95Rnd 5.45mm 7N44 HP - Green Tracer"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Green"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_7N44_HP_T_White: FA_rearma_95Rnd_545x39_7N44_HP { displayName = "[JMSB] 95Rnd 5.45mm 7N44 HP - White Tracer"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_White"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_7N44_HP_T_Blue: FA_rearma_95Rnd_545x39_7N44_HP { displayName = "[JMSB] 95Rnd 5.45mm 7N44 HP - Blue Tracer"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Blue"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_7N44_HP_T_Orange: FA_rearma_95Rnd_545x39_7N44_HP { displayName = "[JMSB] 95Rnd 5.45mm 7N44 HP - Orange Tracer"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Orange"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_7N44_HP_T_IR: FA_rearma_95Rnd_545x39_7N44_HP { displayName = "[JMSB] 95Rnd 5.45mm 7N44 HP - IR Tracer"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_IR"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_7N48_CT: 95Rnd_545x39_RPK35_Drum_F {
        author = QAUTHOR;
        displayName = "[JMSB] 95Rnd 5.45mm 7N48 CT";
        displayNameShort = "7N48 CT";
        descriptionShort = "7N48 CT";
        ammo = "FA_o_545x39_7N48_CT";
        initSpeed = 950;
        tracersEvery = 0;
    };
    class FA_rearma_95Rnd_545x39_7N48_CT_T_Red: FA_rearma_95Rnd_545x39_7N48_CT { displayName = "[JMSB] 95Rnd 5.45mm 7N48 CT - Red Tracer"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Red"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_7N48_CT_T_Yellow: FA_rearma_95Rnd_545x39_7N48_CT { displayName = "[JMSB] 95Rnd 5.45mm 7N48 CT - Yellow Tracer"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_7N48_CT_T_Green: FA_rearma_95Rnd_545x39_7N48_CT { displayName = "[JMSB] 95Rnd 5.45mm 7N48 CT - Green Tracer"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Green"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_7N48_CT_T_White: FA_rearma_95Rnd_545x39_7N48_CT { displayName = "[JMSB] 95Rnd 5.45mm 7N48 CT - White Tracer"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_White"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_7N48_CT_T_Blue: FA_rearma_95Rnd_545x39_7N48_CT { displayName = "[JMSB] 95Rnd 5.45mm 7N48 CT - Blue Tracer"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Blue"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_7N48_CT_T_Orange: FA_rearma_95Rnd_545x39_7N48_CT { displayName = "[JMSB] 95Rnd 5.45mm 7N48 CT - Orange Tracer"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Orange"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_7N48_CT_T_IR: FA_rearma_95Rnd_545x39_7N48_CT { displayName = "[JMSB] 95Rnd 5.45mm 7N48 CT - IR Tracer"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_IR"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_7U5_SubAP: 95Rnd_545x39_RPK35_Drum_F {
        author = QAUTHOR;
        displayName = "[JMSB] 95Rnd 5.45mm 7U5 SubAP";
        displayNameShort = "7U5 SubAP";
        descriptionShort = "7U5 SubAP";
        ammo = "FA_o_545x39_7U5_SubAP";
        initSpeed = 303;
        tracersEvery = 0;
    };
    class FA_rearma_95Rnd_545x39_7U5_SubAP_T_Red: FA_rearma_95Rnd_545x39_7U5_SubAP { displayName = "[JMSB] 95Rnd 5.45mm 7U5 SubAP - Red Tracer"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_Red"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_7U5_SubAP_T_Yellow: FA_rearma_95Rnd_545x39_7U5_SubAP { displayName = "[JMSB] 95Rnd 5.45mm 7U5 SubAP - Yellow Tracer"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_7U5_SubAP_T_Green: FA_rearma_95Rnd_545x39_7U5_SubAP { displayName = "[JMSB] 95Rnd 5.45mm 7U5 SubAP - Green Tracer"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_Green"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_7U5_SubAP_T_White: FA_rearma_95Rnd_545x39_7U5_SubAP { displayName = "[JMSB] 95Rnd 5.45mm 7U5 SubAP - White Tracer"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_White"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_7U5_SubAP_T_Blue: FA_rearma_95Rnd_545x39_7U5_SubAP { displayName = "[JMSB] 95Rnd 5.45mm 7U5 SubAP - Blue Tracer"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_Blue"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_7U5_SubAP_T_Orange: FA_rearma_95Rnd_545x39_7U5_SubAP { displayName = "[JMSB] 95Rnd 5.45mm 7U5 SubAP - Orange Tracer"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_Orange"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_7U5_SubAP_T_IR: FA_rearma_95Rnd_545x39_7U5_SubAP { displayName = "[JMSB] 95Rnd 5.45mm 7U5 SubAP - IR Tracer"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_IR"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_7N55_HEAB: 95Rnd_545x39_RPK35_Drum_F {
        author = QAUTHOR;
        displayName = "[JMSB] 95Rnd 5.45mm 7N55 HEAB";
        displayNameShort = "7N55 HEAB";
        descriptionShort = "7N55 HEAB airburst, counter-UAS";
        ammo = "FA_o_545x39_7N55_HEAB";
        initSpeed = 925;
        tracersEvery = 0;
    };
    class FA_rearma_95Rnd_545x39_7N55_HEAB_T_Red: FA_rearma_95Rnd_545x39_7N55_HEAB { displayName = "[JMSB] 95Rnd 5.45mm 7N55 HEAB - Red Tracer"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_Red"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_7N55_HEAB_T_Yellow: FA_rearma_95Rnd_545x39_7N55_HEAB { displayName = "[JMSB] 95Rnd 5.45mm 7N55 HEAB - Yellow Tracer"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_7N55_HEAB_T_Green: FA_rearma_95Rnd_545x39_7N55_HEAB { displayName = "[JMSB] 95Rnd 5.45mm 7N55 HEAB - Green Tracer"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_Green"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_7N55_HEAB_T_White: FA_rearma_95Rnd_545x39_7N55_HEAB { displayName = "[JMSB] 95Rnd 5.45mm 7N55 HEAB - White Tracer"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_White"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_7N55_HEAB_T_Blue: FA_rearma_95Rnd_545x39_7N55_HEAB { displayName = "[JMSB] 95Rnd 5.45mm 7N55 HEAB - Blue Tracer"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_Blue"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_7N55_HEAB_T_Orange: FA_rearma_95Rnd_545x39_7N55_HEAB { displayName = "[JMSB] 95Rnd 5.45mm 7N55 HEAB - Orange Tracer"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_Orange"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_7N55_HEAB_T_IR: FA_rearma_95Rnd_545x39_7N55_HEAB { displayName = "[JMSB] 95Rnd 5.45mm 7N55 HEAB - IR Tracer"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_IR"; tracersEvery = 4; };

    // ===== 95Rnd 5.45x39 camo drum - RPK35 - body 95Rnd_545x39_RPK35_Drum_Camo_F =====
    class FA_rearma_95Rnd_545x39_Camo_7N44_HP: 95Rnd_545x39_RPK35_Drum_Camo_F {
        author = QAUTHOR;
        displayName = "[JMSB] 95Rnd 5.45mm 7N44 HP - Camo";
        displayNameShort = "7N44 HP";
        descriptionShort = "7N44 HP";
        ammo = "FA_o_545x39_7N44_HP";
        initSpeed = 925;
        tracersEvery = 0;
    };
    class FA_rearma_95Rnd_545x39_Camo_7N44_HP_T_Red: FA_rearma_95Rnd_545x39_Camo_7N44_HP { displayName = "[JMSB] 95Rnd 5.45mm 7N44 HP - Red Tracer, Camo"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Red"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_Camo_7N44_HP_T_Yellow: FA_rearma_95Rnd_545x39_Camo_7N44_HP { displayName = "[JMSB] 95Rnd 5.45mm 7N44 HP - Yellow Tracer, Camo"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_Camo_7N44_HP_T_Green: FA_rearma_95Rnd_545x39_Camo_7N44_HP { displayName = "[JMSB] 95Rnd 5.45mm 7N44 HP - Green Tracer, Camo"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Green"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_Camo_7N44_HP_T_White: FA_rearma_95Rnd_545x39_Camo_7N44_HP { displayName = "[JMSB] 95Rnd 5.45mm 7N44 HP - White Tracer, Camo"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_White"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_Camo_7N44_HP_T_Blue: FA_rearma_95Rnd_545x39_Camo_7N44_HP { displayName = "[JMSB] 95Rnd 5.45mm 7N44 HP - Blue Tracer, Camo"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Blue"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_Camo_7N44_HP_T_Orange: FA_rearma_95Rnd_545x39_Camo_7N44_HP { displayName = "[JMSB] 95Rnd 5.45mm 7N44 HP - Orange Tracer, Camo"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Orange"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_Camo_7N44_HP_T_IR: FA_rearma_95Rnd_545x39_Camo_7N44_HP { displayName = "[JMSB] 95Rnd 5.45mm 7N44 HP - IR Tracer, Camo"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_IR"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_Camo_7N48_CT: 95Rnd_545x39_RPK35_Drum_Camo_F {
        author = QAUTHOR;
        displayName = "[JMSB] 95Rnd 5.45mm 7N48 CT - Camo";
        displayNameShort = "7N48 CT";
        descriptionShort = "7N48 CT";
        ammo = "FA_o_545x39_7N48_CT";
        initSpeed = 950;
        tracersEvery = 0;
    };
    class FA_rearma_95Rnd_545x39_Camo_7N48_CT_T_Red: FA_rearma_95Rnd_545x39_Camo_7N48_CT { displayName = "[JMSB] 95Rnd 5.45mm 7N48 CT - Red Tracer, Camo"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Red"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_Camo_7N48_CT_T_Yellow: FA_rearma_95Rnd_545x39_Camo_7N48_CT { displayName = "[JMSB] 95Rnd 5.45mm 7N48 CT - Yellow Tracer, Camo"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_Camo_7N48_CT_T_Green: FA_rearma_95Rnd_545x39_Camo_7N48_CT { displayName = "[JMSB] 95Rnd 5.45mm 7N48 CT - Green Tracer, Camo"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Green"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_Camo_7N48_CT_T_White: FA_rearma_95Rnd_545x39_Camo_7N48_CT { displayName = "[JMSB] 95Rnd 5.45mm 7N48 CT - White Tracer, Camo"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_White"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_Camo_7N48_CT_T_Blue: FA_rearma_95Rnd_545x39_Camo_7N48_CT { displayName = "[JMSB] 95Rnd 5.45mm 7N48 CT - Blue Tracer, Camo"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Blue"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_Camo_7N48_CT_T_Orange: FA_rearma_95Rnd_545x39_Camo_7N48_CT { displayName = "[JMSB] 95Rnd 5.45mm 7N48 CT - Orange Tracer, Camo"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Orange"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_Camo_7N48_CT_T_IR: FA_rearma_95Rnd_545x39_Camo_7N48_CT { displayName = "[JMSB] 95Rnd 5.45mm 7N48 CT - IR Tracer, Camo"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_IR"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_Camo_7U5_SubAP: 95Rnd_545x39_RPK35_Drum_Camo_F {
        author = QAUTHOR;
        displayName = "[JMSB] 95Rnd 5.45mm 7U5 SubAP - Camo";
        displayNameShort = "7U5 SubAP";
        descriptionShort = "7U5 SubAP";
        ammo = "FA_o_545x39_7U5_SubAP";
        initSpeed = 303;
        tracersEvery = 0;
    };
    class FA_rearma_95Rnd_545x39_Camo_7U5_SubAP_T_Red: FA_rearma_95Rnd_545x39_Camo_7U5_SubAP { displayName = "[JMSB] 95Rnd 5.45mm 7U5 SubAP - Red Tracer, Camo"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_Red"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_Camo_7U5_SubAP_T_Yellow: FA_rearma_95Rnd_545x39_Camo_7U5_SubAP { displayName = "[JMSB] 95Rnd 5.45mm 7U5 SubAP - Yellow Tracer, Camo"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_Camo_7U5_SubAP_T_Green: FA_rearma_95Rnd_545x39_Camo_7U5_SubAP { displayName = "[JMSB] 95Rnd 5.45mm 7U5 SubAP - Green Tracer, Camo"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_Green"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_Camo_7U5_SubAP_T_White: FA_rearma_95Rnd_545x39_Camo_7U5_SubAP { displayName = "[JMSB] 95Rnd 5.45mm 7U5 SubAP - White Tracer, Camo"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_White"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_Camo_7U5_SubAP_T_Blue: FA_rearma_95Rnd_545x39_Camo_7U5_SubAP { displayName = "[JMSB] 95Rnd 5.45mm 7U5 SubAP - Blue Tracer, Camo"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_Blue"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_Camo_7U5_SubAP_T_Orange: FA_rearma_95Rnd_545x39_Camo_7U5_SubAP { displayName = "[JMSB] 95Rnd 5.45mm 7U5 SubAP - Orange Tracer, Camo"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_Orange"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_Camo_7U5_SubAP_T_IR: FA_rearma_95Rnd_545x39_Camo_7U5_SubAP { displayName = "[JMSB] 95Rnd 5.45mm 7U5 SubAP - IR Tracer, Camo"; descriptionShort = "7U5 SubAP"; ammo = "FA_o_545x39_7U5_SubAP_T_IR"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_Camo_7N55_HEAB: 95Rnd_545x39_RPK35_Drum_Camo_F {
        author = QAUTHOR;
        displayName = "[JMSB] 95Rnd 5.45mm 7N55 HEAB - Camo";
        displayNameShort = "7N55 HEAB";
        descriptionShort = "7N55 HEAB airburst, counter-UAS";
        ammo = "FA_o_545x39_7N55_HEAB";
        initSpeed = 925;
        tracersEvery = 0;
    };
    class FA_rearma_95Rnd_545x39_Camo_7N55_HEAB_T_Red: FA_rearma_95Rnd_545x39_Camo_7N55_HEAB { displayName = "[JMSB] 95Rnd 5.45mm 7N55 HEAB - Red Tracer, Camo"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_Red"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_Camo_7N55_HEAB_T_Yellow: FA_rearma_95Rnd_545x39_Camo_7N55_HEAB { displayName = "[JMSB] 95Rnd 5.45mm 7N55 HEAB - Yellow Tracer, Camo"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_Camo_7N55_HEAB_T_Green: FA_rearma_95Rnd_545x39_Camo_7N55_HEAB { displayName = "[JMSB] 95Rnd 5.45mm 7N55 HEAB - Green Tracer, Camo"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_Green"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_Camo_7N55_HEAB_T_White: FA_rearma_95Rnd_545x39_Camo_7N55_HEAB { displayName = "[JMSB] 95Rnd 5.45mm 7N55 HEAB - White Tracer, Camo"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_White"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_Camo_7N55_HEAB_T_Blue: FA_rearma_95Rnd_545x39_Camo_7N55_HEAB { displayName = "[JMSB] 95Rnd 5.45mm 7N55 HEAB - Blue Tracer, Camo"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_Blue"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_Camo_7N55_HEAB_T_Orange: FA_rearma_95Rnd_545x39_Camo_7N55_HEAB { displayName = "[JMSB] 95Rnd 5.45mm 7N55 HEAB - Orange Tracer, Camo"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_Orange"; tracersEvery = 4; };
    class FA_rearma_95Rnd_545x39_Camo_7N55_HEAB_T_IR: FA_rearma_95Rnd_545x39_Camo_7N55_HEAB { displayName = "[JMSB] 95Rnd 5.45mm 7N55 HEAB - IR Tracer, Camo"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_IR"; tracersEvery = 4; };

    // ===== 30Rnd 5.45x39 pellet mag - AK35 family - body 30Rnd_SG_AK35_Mag_F =====
    class FA_rearma_30Rnd_545x39_SG_7N56K_AD: 30Rnd_SG_AK35_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 5.45mm SG 7N56K AD";
        displayNameShort = "7N56K AD";
        descriptionShort = "7N56K AD 7-pellet shot, eff. 90 m";
        ammo = "FA_o_545x39_7N56K_AD";
        initSpeed = 660;
        tracersEvery = 0;
        lastRoundsTracer = 0;
    };
    class FA_rearma_30Rnd_545x39_SG_7N56L_AD: 30Rnd_SG_AK35_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 5.45mm SG 7N56L AD";
        displayNameShort = "7N56L AD";
        descriptionShort = "7N56L AD 5-pellet shot, eff. 180 m";
        ammo = "FA_o_545x39_7N56L_AD";
        initSpeed = 660;
        tracersEvery = 0;
        lastRoundsTracer = 0;
    };

    // ===== 30Rnd 5.45x39 camo pellet mag - AK35 family - body 30Rnd_SG_AK35_Camo_Mag_F =====
    class FA_rearma_30Rnd_545x39_SGCamo_7N56K_AD: 30Rnd_SG_AK35_Camo_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 5.45mm SGCamo 7N56K AD";
        displayNameShort = "7N56K AD";
        descriptionShort = "7N56K AD 7-pellet shot, eff. 90 m";
        ammo = "FA_o_545x39_7N56K_AD";
        initSpeed = 660;
        tracersEvery = 0;
        lastRoundsTracer = 0;
    };
    class FA_rearma_30Rnd_545x39_SGCamo_7N56L_AD: 30Rnd_SG_AK35_Camo_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 5.45mm SGCamo 7N56L AD";
        displayNameShort = "7N56L AD";
        descriptionShort = "7N56L AD 5-pellet shot, eff. 180 m";
        ammo = "FA_o_545x39_7N56L_AD";
        initSpeed = 660;
        tracersEvery = 0;
        lastRoundsTracer = 0;
    };

    // ===== 30Rnd 5.45 underwater - ADS35 - body 30Rnd_545x39UW_ADS35_Mag_F =====
    class FA_rearma_30Rnd_545x39_UW_PSP2_UW: 30Rnd_545x39UW_ADS35_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 5.45mm UW PSP2";
        displayNameShort = "PSP-2 UW";
        descriptionShort = "PSP-2 UW - 5.45 underwater dart";
        ammo = "FA_o_545x39_PSP2_UW";
        initSpeed = 300;
    };

    // ===== 200Rnd 5.45x39 belt - RPL 35 - body 200Rnd_545x39_RPL_Reload_Tracer_Green_Mag =====
    class FA_rearma_200Rnd_545x39_7N44_HP: 200Rnd_545x39_RPL_Reload_Tracer_Green_Mag {
        author = QAUTHOR;
        displayName = "[JMSB] 200Rnd 5.45mm 7N44 HP";
        displayNameShort = "7N44 HP";
        descriptionShort = "7N44 HP";
        ammo = "FA_o_545x39_7N44_HP";
        initSpeed = 925;
        tracersEvery = 0;
    };
    class FA_rearma_200Rnd_545x39_7N44_HP_T_Red: FA_rearma_200Rnd_545x39_7N44_HP { displayName = "[JMSB] 200Rnd 5.45mm 7N44 HP - Red Tracer"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Red"; tracersEvery = 4; };
    class FA_rearma_200Rnd_545x39_7N44_HP_T_Yellow: FA_rearma_200Rnd_545x39_7N44_HP { displayName = "[JMSB] 200Rnd 5.45mm 7N44 HP - Yellow Tracer"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_200Rnd_545x39_7N44_HP_T_Green: FA_rearma_200Rnd_545x39_7N44_HP { displayName = "[JMSB] 200Rnd 5.45mm 7N44 HP - Green Tracer"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Green"; tracersEvery = 4; };
    class FA_rearma_200Rnd_545x39_7N44_HP_T_White: FA_rearma_200Rnd_545x39_7N44_HP { displayName = "[JMSB] 200Rnd 5.45mm 7N44 HP - White Tracer"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_White"; tracersEvery = 4; };
    class FA_rearma_200Rnd_545x39_7N44_HP_T_Blue: FA_rearma_200Rnd_545x39_7N44_HP { displayName = "[JMSB] 200Rnd 5.45mm 7N44 HP - Blue Tracer"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Blue"; tracersEvery = 4; };
    class FA_rearma_200Rnd_545x39_7N44_HP_T_Orange: FA_rearma_200Rnd_545x39_7N44_HP { displayName = "[JMSB] 200Rnd 5.45mm 7N44 HP - Orange Tracer"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_Orange"; tracersEvery = 4; };
    class FA_rearma_200Rnd_545x39_7N44_HP_T_IR: FA_rearma_200Rnd_545x39_7N44_HP { displayName = "[JMSB] 200Rnd 5.45mm 7N44 HP - IR Tracer"; descriptionShort = "7N44 HP"; ammo = "FA_o_545x39_7N44_HP_T_IR"; tracersEvery = 4; };
    class FA_rearma_200Rnd_545x39_7N48_CT: 200Rnd_545x39_RPL_Reload_Tracer_Green_Mag {
        author = QAUTHOR;
        displayName = "[JMSB] 200Rnd 5.45mm 7N48 CT";
        displayNameShort = "7N48 CT";
        descriptionShort = "7N48 CT";
        ammo = "FA_o_545x39_7N48_CT";
        initSpeed = 950;
        tracersEvery = 0;
    };
    class FA_rearma_200Rnd_545x39_7N48_CT_T_Red: FA_rearma_200Rnd_545x39_7N48_CT { displayName = "[JMSB] 200Rnd 5.45mm 7N48 CT - Red Tracer"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Red"; tracersEvery = 4; };
    class FA_rearma_200Rnd_545x39_7N48_CT_T_Yellow: FA_rearma_200Rnd_545x39_7N48_CT { displayName = "[JMSB] 200Rnd 5.45mm 7N48 CT - Yellow Tracer"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_200Rnd_545x39_7N48_CT_T_Green: FA_rearma_200Rnd_545x39_7N48_CT { displayName = "[JMSB] 200Rnd 5.45mm 7N48 CT - Green Tracer"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Green"; tracersEvery = 4; };
    class FA_rearma_200Rnd_545x39_7N48_CT_T_White: FA_rearma_200Rnd_545x39_7N48_CT { displayName = "[JMSB] 200Rnd 5.45mm 7N48 CT - White Tracer"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_White"; tracersEvery = 4; };
    class FA_rearma_200Rnd_545x39_7N48_CT_T_Blue: FA_rearma_200Rnd_545x39_7N48_CT { displayName = "[JMSB] 200Rnd 5.45mm 7N48 CT - Blue Tracer"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Blue"; tracersEvery = 4; };
    class FA_rearma_200Rnd_545x39_7N48_CT_T_Orange: FA_rearma_200Rnd_545x39_7N48_CT { displayName = "[JMSB] 200Rnd 5.45mm 7N48 CT - Orange Tracer"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_Orange"; tracersEvery = 4; };
    class FA_rearma_200Rnd_545x39_7N48_CT_T_IR: FA_rearma_200Rnd_545x39_7N48_CT { displayName = "[JMSB] 200Rnd 5.45mm 7N48 CT - IR Tracer"; descriptionShort = "7N48 CT"; ammo = "FA_o_545x39_7N48_CT_T_IR"; tracersEvery = 4; };
    class FA_rearma_200Rnd_545x39_7N55_HEAB: 200Rnd_545x39_RPL_Reload_Tracer_Green_Mag {
        author = QAUTHOR;
        displayName = "[JMSB] 200Rnd 5.45mm 7N55 HEAB";
        displayNameShort = "7N55 HEAB";
        descriptionShort = "7N55 HEAB airburst, counter-UAS";
        ammo = "FA_o_545x39_7N55_HEAB";
        initSpeed = 925;
        tracersEvery = 0;
    };
    class FA_rearma_200Rnd_545x39_7N55_HEAB_T_Red: FA_rearma_200Rnd_545x39_7N55_HEAB { displayName = "[JMSB] 200Rnd 5.45mm 7N55 HEAB - Red Tracer"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_Red"; tracersEvery = 4; };
    class FA_rearma_200Rnd_545x39_7N55_HEAB_T_Yellow: FA_rearma_200Rnd_545x39_7N55_HEAB { displayName = "[JMSB] 200Rnd 5.45mm 7N55 HEAB - Yellow Tracer"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_200Rnd_545x39_7N55_HEAB_T_Green: FA_rearma_200Rnd_545x39_7N55_HEAB { displayName = "[JMSB] 200Rnd 5.45mm 7N55 HEAB - Green Tracer"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_Green"; tracersEvery = 4; };
    class FA_rearma_200Rnd_545x39_7N55_HEAB_T_White: FA_rearma_200Rnd_545x39_7N55_HEAB { displayName = "[JMSB] 200Rnd 5.45mm 7N55 HEAB - White Tracer"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_White"; tracersEvery = 4; };
    class FA_rearma_200Rnd_545x39_7N55_HEAB_T_Blue: FA_rearma_200Rnd_545x39_7N55_HEAB { displayName = "[JMSB] 200Rnd 5.45mm 7N55 HEAB - Blue Tracer"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_Blue"; tracersEvery = 4; };
    class FA_rearma_200Rnd_545x39_7N55_HEAB_T_Orange: FA_rearma_200Rnd_545x39_7N55_HEAB { displayName = "[JMSB] 200Rnd 5.45mm 7N55 HEAB - Orange Tracer"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_Orange"; tracersEvery = 4; };
    class FA_rearma_200Rnd_545x39_7N55_HEAB_T_IR: FA_rearma_200Rnd_545x39_7N55_HEAB { displayName = "[JMSB] 200Rnd 5.45mm 7N55 HEAB - IR Tracer"; descriptionShort = "7N55 HEAB airburst, counter-UAS"; ammo = "FA_o_545x39_7N55_HEAB_T_IR"; tracersEvery = 4; };

    // ===== 100Rnd 7.62x54R belt - PKP Bullpup - body 100Rnd_762x54_PK_Reload_Tracer_Green_Mag =====
    class FA_rearma_100Rnd_762x54R_Ball_HV: 100Rnd_762x54_PK_Reload_Tracer_Green_Mag {
        author = QAUTHOR;
        displayName = "[JMSB] 100Rnd 7.62x54mmR Ball HV";
        displayNameShort = "7.62x54R Ball HV";
        descriptionShort = "7.62x54R Ball HV";
        ammo = "FA_o_762x54R_Ball_HV";
        initSpeed = 855;
        tracersEvery = 0;
    };
    class FA_rearma_100Rnd_762x54R_Ball_HV_T_Red: FA_rearma_100Rnd_762x54R_Ball_HV { displayName = "[JMSB] 100Rnd 7.62x54mmR Ball HV - Red Tracer"; descriptionShort = "7.62x54R Ball HV"; ammo = "FA_o_762x54R_Ball_HV_T_Red"; tracersEvery = 4; };
    class FA_rearma_100Rnd_762x54R_Ball_HV_T_Yellow: FA_rearma_100Rnd_762x54R_Ball_HV { displayName = "[JMSB] 100Rnd 7.62x54mmR Ball HV - Yellow Tracer"; descriptionShort = "7.62x54R Ball HV"; ammo = "FA_o_762x54R_Ball_HV_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_100Rnd_762x54R_Ball_HV_T_Green: FA_rearma_100Rnd_762x54R_Ball_HV { displayName = "[JMSB] 100Rnd 7.62x54mmR Ball HV - Green Tracer"; descriptionShort = "7.62x54R Ball HV"; ammo = "FA_o_762x54R_Ball_HV_T_Green"; tracersEvery = 4; };
    class FA_rearma_100Rnd_762x54R_Ball_HV_T_White: FA_rearma_100Rnd_762x54R_Ball_HV { displayName = "[JMSB] 100Rnd 7.62x54mmR Ball HV - White Tracer"; descriptionShort = "7.62x54R Ball HV"; ammo = "FA_o_762x54R_Ball_HV_T_White"; tracersEvery = 4; };
    class FA_rearma_100Rnd_762x54R_Ball_HV_T_Blue: FA_rearma_100Rnd_762x54R_Ball_HV { displayName = "[JMSB] 100Rnd 7.62x54mmR Ball HV - Blue Tracer"; descriptionShort = "7.62x54R Ball HV"; ammo = "FA_o_762x54R_Ball_HV_T_Blue"; tracersEvery = 4; };
    class FA_rearma_100Rnd_762x54R_Ball_HV_T_Orange: FA_rearma_100Rnd_762x54R_Ball_HV { displayName = "[JMSB] 100Rnd 7.62x54mmR Ball HV - Orange Tracer"; descriptionShort = "7.62x54R Ball HV"; ammo = "FA_o_762x54R_Ball_HV_T_Orange"; tracersEvery = 4; };
    class FA_rearma_100Rnd_762x54R_Ball_HV_T_IR: FA_rearma_100Rnd_762x54R_Ball_HV { displayName = "[JMSB] 100Rnd 7.62x54mmR Ball HV - IR Tracer"; descriptionShort = "7.62x54R Ball HV"; ammo = "FA_o_762x54R_Ball_HV_T_IR"; tracersEvery = 4; };
    class FA_rearma_100Rnd_762x54R_7N49_AP: 100Rnd_762x54_PK_Reload_Tracer_Green_Mag {
        author = QAUTHOR;
        displayName = "[JMSB] 100Rnd 7.62x54mmR 7N49 AP";
        displayNameShort = "7N49 AP";
        descriptionShort = "7N49 AP - 7.62x54R tungsten armour piercer";
        ammo = "FA_o_762x54R_7N49_AP";
        initSpeed = 830;
        tracersEvery = 0;
    };
    class FA_rearma_100Rnd_762x54R_7N49_AP_T_Red: FA_rearma_100Rnd_762x54R_7N49_AP { displayName = "[JMSB] 100Rnd 7.62x54mmR 7N49 AP - Red Tracer"; descriptionShort = "7N49 AP - 7.62x54R tungsten armour piercer"; ammo = "FA_o_762x54R_7N49_AP_T_Red"; tracersEvery = 4; };
    class FA_rearma_100Rnd_762x54R_7N49_AP_T_Yellow: FA_rearma_100Rnd_762x54R_7N49_AP { displayName = "[JMSB] 100Rnd 7.62x54mmR 7N49 AP - Yellow Tracer"; descriptionShort = "7N49 AP - 7.62x54R tungsten armour piercer"; ammo = "FA_o_762x54R_7N49_AP_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_100Rnd_762x54R_7N49_AP_T_Green: FA_rearma_100Rnd_762x54R_7N49_AP { displayName = "[JMSB] 100Rnd 7.62x54mmR 7N49 AP - Green Tracer"; descriptionShort = "7N49 AP - 7.62x54R tungsten armour piercer"; ammo = "FA_o_762x54R_7N49_AP_T_Green"; tracersEvery = 4; };
    class FA_rearma_100Rnd_762x54R_7N49_AP_T_White: FA_rearma_100Rnd_762x54R_7N49_AP { displayName = "[JMSB] 100Rnd 7.62x54mmR 7N49 AP - White Tracer"; descriptionShort = "7N49 AP - 7.62x54R tungsten armour piercer"; ammo = "FA_o_762x54R_7N49_AP_T_White"; tracersEvery = 4; };
    class FA_rearma_100Rnd_762x54R_7N49_AP_T_Blue: FA_rearma_100Rnd_762x54R_7N49_AP { displayName = "[JMSB] 100Rnd 7.62x54mmR 7N49 AP - Blue Tracer"; descriptionShort = "7N49 AP - 7.62x54R tungsten armour piercer"; ammo = "FA_o_762x54R_7N49_AP_T_Blue"; tracersEvery = 4; };
    class FA_rearma_100Rnd_762x54R_7N49_AP_T_Orange: FA_rearma_100Rnd_762x54R_7N49_AP { displayName = "[JMSB] 100Rnd 7.62x54mmR 7N49 AP - Orange Tracer"; descriptionShort = "7N49 AP - 7.62x54R tungsten armour piercer"; ammo = "FA_o_762x54R_7N49_AP_T_Orange"; tracersEvery = 4; };
    class FA_rearma_100Rnd_762x54R_7N49_AP_T_IR: FA_rearma_100Rnd_762x54R_7N49_AP { displayName = "[JMSB] 100Rnd 7.62x54mmR 7N49 AP - IR Tracer"; descriptionShort = "7N49 AP - 7.62x54R tungsten armour piercer"; ammo = "FA_o_762x54R_7N49_AP_T_IR"; tracersEvery = 4; };

    // ===== 10Rnd 7.62x54R - SVCh / SV-98M - body 10Rnd_762X54R_SVCh =====
    class FA_rearma_10Rnd_762x54R_Ball_HV: 10Rnd_762X54R_SVCh {
        author = QAUTHOR;
        displayName = "[JMSB] 10Rnd 7.62x54mmR Ball HV [Rearma]";
        displayNameShort = "7.62x54R Ball HV";
        descriptionShort = "7.62x54R Ball HV";
        ammo = "FA_o_762x54R_Ball_HV";
        initSpeed = 855;
    };
    class FA_rearma_10Rnd_762x54R_Ball_HV_T_Red: FA_rearma_10Rnd_762x54R_Ball_HV { displayName = "[JMSB] 10Rnd 7.62x54mmR Ball HV [Rearma] - Red Tracer"; descriptionShort = "7.62x54R Ball HV"; ammo = "FA_o_762x54R_Ball_HV_T_Red"; tracersEvery = 4; };
    class FA_rearma_10Rnd_762x54R_Ball_HV_T_Yellow: FA_rearma_10Rnd_762x54R_Ball_HV { displayName = "[JMSB] 10Rnd 7.62x54mmR Ball HV [Rearma] - Yellow Tracer"; descriptionShort = "7.62x54R Ball HV"; ammo = "FA_o_762x54R_Ball_HV_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_10Rnd_762x54R_Ball_HV_T_Green: FA_rearma_10Rnd_762x54R_Ball_HV { displayName = "[JMSB] 10Rnd 7.62x54mmR Ball HV [Rearma] - Green Tracer"; descriptionShort = "7.62x54R Ball HV"; ammo = "FA_o_762x54R_Ball_HV_T_Green"; tracersEvery = 4; };
    class FA_rearma_10Rnd_762x54R_Ball_HV_T_White: FA_rearma_10Rnd_762x54R_Ball_HV { displayName = "[JMSB] 10Rnd 7.62x54mmR Ball HV [Rearma] - White Tracer"; descriptionShort = "7.62x54R Ball HV"; ammo = "FA_o_762x54R_Ball_HV_T_White"; tracersEvery = 4; };
    class FA_rearma_10Rnd_762x54R_Ball_HV_T_Blue: FA_rearma_10Rnd_762x54R_Ball_HV { displayName = "[JMSB] 10Rnd 7.62x54mmR Ball HV [Rearma] - Blue Tracer"; descriptionShort = "7.62x54R Ball HV"; ammo = "FA_o_762x54R_Ball_HV_T_Blue"; tracersEvery = 4; };
    class FA_rearma_10Rnd_762x54R_Ball_HV_T_Orange: FA_rearma_10Rnd_762x54R_Ball_HV { displayName = "[JMSB] 10Rnd 7.62x54mmR Ball HV [Rearma] - Orange Tracer"; descriptionShort = "7.62x54R Ball HV"; ammo = "FA_o_762x54R_Ball_HV_T_Orange"; tracersEvery = 4; };
    class FA_rearma_10Rnd_762x54R_Ball_HV_T_IR: FA_rearma_10Rnd_762x54R_Ball_HV { displayName = "[JMSB] 10Rnd 7.62x54mmR Ball HV [Rearma] - IR Tracer"; descriptionShort = "7.62x54R Ball HV"; ammo = "FA_o_762x54R_Ball_HV_T_IR"; tracersEvery = 4; };
    class FA_rearma_10Rnd_762x54R_7N49_AP: 10Rnd_762X54R_SVCh {
        author = QAUTHOR;
        displayName = "[JMSB] 10Rnd 7.62x54mmR 7N49 AP";
        displayNameShort = "7N49 AP";
        descriptionShort = "7N49 AP - 7.62x54R tungsten armour piercer";
        ammo = "FA_o_762x54R_7N49_AP";
        initSpeed = 830;
    };
    class FA_rearma_10Rnd_762x54R_7N49_AP_T_Red: FA_rearma_10Rnd_762x54R_7N49_AP { displayName = "[JMSB] 10Rnd 7.62x54mmR 7N49 AP - Red Tracer"; descriptionShort = "7N49 AP - 7.62x54R tungsten armour piercer"; ammo = "FA_o_762x54R_7N49_AP_T_Red"; tracersEvery = 4; };
    class FA_rearma_10Rnd_762x54R_7N49_AP_T_Yellow: FA_rearma_10Rnd_762x54R_7N49_AP { displayName = "[JMSB] 10Rnd 7.62x54mmR 7N49 AP - Yellow Tracer"; descriptionShort = "7N49 AP - 7.62x54R tungsten armour piercer"; ammo = "FA_o_762x54R_7N49_AP_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_10Rnd_762x54R_7N49_AP_T_Green: FA_rearma_10Rnd_762x54R_7N49_AP { displayName = "[JMSB] 10Rnd 7.62x54mmR 7N49 AP - Green Tracer"; descriptionShort = "7N49 AP - 7.62x54R tungsten armour piercer"; ammo = "FA_o_762x54R_7N49_AP_T_Green"; tracersEvery = 4; };
    class FA_rearma_10Rnd_762x54R_7N49_AP_T_White: FA_rearma_10Rnd_762x54R_7N49_AP { displayName = "[JMSB] 10Rnd 7.62x54mmR 7N49 AP - White Tracer"; descriptionShort = "7N49 AP - 7.62x54R tungsten armour piercer"; ammo = "FA_o_762x54R_7N49_AP_T_White"; tracersEvery = 4; };
    class FA_rearma_10Rnd_762x54R_7N49_AP_T_Blue: FA_rearma_10Rnd_762x54R_7N49_AP { displayName = "[JMSB] 10Rnd 7.62x54mmR 7N49 AP - Blue Tracer"; descriptionShort = "7N49 AP - 7.62x54R tungsten armour piercer"; ammo = "FA_o_762x54R_7N49_AP_T_Blue"; tracersEvery = 4; };
    class FA_rearma_10Rnd_762x54R_7N49_AP_T_Orange: FA_rearma_10Rnd_762x54R_7N49_AP { displayName = "[JMSB] 10Rnd 7.62x54mmR 7N49 AP - Orange Tracer"; descriptionShort = "7N49 AP - 7.62x54R tungsten armour piercer"; ammo = "FA_o_762x54R_7N49_AP_T_Orange"; tracersEvery = 4; };
    class FA_rearma_10Rnd_762x54R_7N49_AP_T_IR: FA_rearma_10Rnd_762x54R_7N49_AP { displayName = "[JMSB] 10Rnd 7.62x54mmR 7N49 AP - IR Tracer"; descriptionShort = "7N49 AP - 7.62x54R tungsten armour piercer"; ammo = "FA_o_762x54R_7N49_AP_T_IR"; tracersEvery = 4; };
    class FA_rearma_10Rnd_762x54R_7U18_SUB: 10Rnd_762X54R_SVCh {
        author = QAUTHOR;
        displayName = "[JMSB] 10Rnd 7.62x54mmR 7U18 SUB";
        displayNameShort = "7U18 SUB";
        descriptionShort = "7U18 SUB - 7.62x54R subsonic";
        ammo = "FA_o_762x54R_7U18_SUB";
        initSpeed = 310;
    };
    class FA_rearma_10Rnd_762x54R_7U18_SUB_T_Red: FA_rearma_10Rnd_762x54R_7U18_SUB { displayName = "[JMSB] 10Rnd 7.62x54mmR 7U18 SUB - Red Tracer"; descriptionShort = "7U18 SUB - 7.62x54R subsonic"; ammo = "FA_o_762x54R_7U18_SUB_T_Red"; tracersEvery = 4; };
    class FA_rearma_10Rnd_762x54R_7U18_SUB_T_Yellow: FA_rearma_10Rnd_762x54R_7U18_SUB { displayName = "[JMSB] 10Rnd 7.62x54mmR 7U18 SUB - Yellow Tracer"; descriptionShort = "7U18 SUB - 7.62x54R subsonic"; ammo = "FA_o_762x54R_7U18_SUB_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_10Rnd_762x54R_7U18_SUB_T_Green: FA_rearma_10Rnd_762x54R_7U18_SUB { displayName = "[JMSB] 10Rnd 7.62x54mmR 7U18 SUB - Green Tracer"; descriptionShort = "7U18 SUB - 7.62x54R subsonic"; ammo = "FA_o_762x54R_7U18_SUB_T_Green"; tracersEvery = 4; };
    class FA_rearma_10Rnd_762x54R_7U18_SUB_T_White: FA_rearma_10Rnd_762x54R_7U18_SUB { displayName = "[JMSB] 10Rnd 7.62x54mmR 7U18 SUB - White Tracer"; descriptionShort = "7U18 SUB - 7.62x54R subsonic"; ammo = "FA_o_762x54R_7U18_SUB_T_White"; tracersEvery = 4; };
    class FA_rearma_10Rnd_762x54R_7U18_SUB_T_Blue: FA_rearma_10Rnd_762x54R_7U18_SUB { displayName = "[JMSB] 10Rnd 7.62x54mmR 7U18 SUB - Blue Tracer"; descriptionShort = "7U18 SUB - 7.62x54R subsonic"; ammo = "FA_o_762x54R_7U18_SUB_T_Blue"; tracersEvery = 4; };
    class FA_rearma_10Rnd_762x54R_7U18_SUB_T_Orange: FA_rearma_10Rnd_762x54R_7U18_SUB { displayName = "[JMSB] 10Rnd 7.62x54mmR 7U18 SUB - Orange Tracer"; descriptionShort = "7U18 SUB - 7.62x54R subsonic"; ammo = "FA_o_762x54R_7U18_SUB_T_Orange"; tracersEvery = 4; };
    class FA_rearma_10Rnd_762x54R_7U18_SUB_T_IR: FA_rearma_10Rnd_762x54R_7U18_SUB { displayName = "[JMSB] 10Rnd 7.62x54mmR 7U18 SUB - IR Tracer"; descriptionShort = "7U18 SUB - 7.62x54R subsonic"; ammo = "FA_o_762x54R_7U18_SUB_T_IR"; tracersEvery = 4; };

    // ===== 10Rnd .338 LM - SVCh / SV-98M - body 10Rnd_338_SVCh =====
    class FA_rearma_10Rnd_338_Mk371_250gr: 10Rnd_338_SVCh {
        author = QAUTHOR;
        displayName = "[JMSB] 10Rnd .338 Mk371 250gr [Rearma]";
        displayNameShort = "Mk371 250gr";
        descriptionShort = "Mk371 250gr";
        ammo = "FA_b_338_Mk371_250gr";
        initSpeed = 905;
    };
    class FA_rearma_10Rnd_338_Mk371_250gr_T_Red: FA_rearma_10Rnd_338_Mk371_250gr { displayName = "[JMSB] 10Rnd .338 Mk371 250gr [Rearma] - Red Tracer"; descriptionShort = "Mk371 250gr"; ammo = "FA_b_338_Mk371_250gr_T_Red"; tracersEvery = 4; };
    class FA_rearma_10Rnd_338_Mk371_250gr_T_Yellow: FA_rearma_10Rnd_338_Mk371_250gr { displayName = "[JMSB] 10Rnd .338 Mk371 250gr [Rearma] - Yellow Tracer"; descriptionShort = "Mk371 250gr"; ammo = "FA_b_338_Mk371_250gr_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_10Rnd_338_Mk371_250gr_T_Green: FA_rearma_10Rnd_338_Mk371_250gr { displayName = "[JMSB] 10Rnd .338 Mk371 250gr [Rearma] - Green Tracer"; descriptionShort = "Mk371 250gr"; ammo = "FA_b_338_Mk371_250gr_T_Green"; tracersEvery = 4; };
    class FA_rearma_10Rnd_338_Mk371_250gr_T_White: FA_rearma_10Rnd_338_Mk371_250gr { displayName = "[JMSB] 10Rnd .338 Mk371 250gr [Rearma] - White Tracer"; descriptionShort = "Mk371 250gr"; ammo = "FA_b_338_Mk371_250gr_T_White"; tracersEvery = 4; };
    class FA_rearma_10Rnd_338_Mk371_250gr_T_Blue: FA_rearma_10Rnd_338_Mk371_250gr { displayName = "[JMSB] 10Rnd .338 Mk371 250gr [Rearma] - Blue Tracer"; descriptionShort = "Mk371 250gr"; ammo = "FA_b_338_Mk371_250gr_T_Blue"; tracersEvery = 4; };
    class FA_rearma_10Rnd_338_Mk371_250gr_T_Orange: FA_rearma_10Rnd_338_Mk371_250gr { displayName = "[JMSB] 10Rnd .338 Mk371 250gr [Rearma] - Orange Tracer"; descriptionShort = "Mk371 250gr"; ammo = "FA_b_338_Mk371_250gr_T_Orange"; tracersEvery = 4; };
    class FA_rearma_10Rnd_338_Mk371_250gr_T_IR: FA_rearma_10Rnd_338_Mk371_250gr { displayName = "[JMSB] 10Rnd .338 Mk371 250gr [Rearma] - IR Tracer"; descriptionShort = "Mk371 250gr"; ammo = "FA_b_338_Mk371_250gr_T_IR"; tracersEvery = 4; };
    class FA_rearma_10Rnd_338_Mk371_285gr: 10Rnd_338_SVCh {
        author = QAUTHOR;
        displayName = "[JMSB] 10Rnd .338 Mk371 285gr [Rearma]";
        displayNameShort = "Mk371 285gr";
        descriptionShort = "Mk371 285gr";
        ammo = "FA_b_338_Mk371_285gr";
        initSpeed = 870;
    };
    class FA_rearma_10Rnd_338_Mk371_285gr_T_Red: FA_rearma_10Rnd_338_Mk371_285gr { displayName = "[JMSB] 10Rnd .338 Mk371 285gr [Rearma] - Red Tracer"; descriptionShort = "Mk371 285gr"; ammo = "FA_b_338_Mk371_285gr_T_Red"; tracersEvery = 4; };
    class FA_rearma_10Rnd_338_Mk371_285gr_T_Yellow: FA_rearma_10Rnd_338_Mk371_285gr { displayName = "[JMSB] 10Rnd .338 Mk371 285gr [Rearma] - Yellow Tracer"; descriptionShort = "Mk371 285gr"; ammo = "FA_b_338_Mk371_285gr_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_10Rnd_338_Mk371_285gr_T_Green: FA_rearma_10Rnd_338_Mk371_285gr { displayName = "[JMSB] 10Rnd .338 Mk371 285gr [Rearma] - Green Tracer"; descriptionShort = "Mk371 285gr"; ammo = "FA_b_338_Mk371_285gr_T_Green"; tracersEvery = 4; };
    class FA_rearma_10Rnd_338_Mk371_285gr_T_White: FA_rearma_10Rnd_338_Mk371_285gr { displayName = "[JMSB] 10Rnd .338 Mk371 285gr [Rearma] - White Tracer"; descriptionShort = "Mk371 285gr"; ammo = "FA_b_338_Mk371_285gr_T_White"; tracersEvery = 4; };
    class FA_rearma_10Rnd_338_Mk371_285gr_T_Blue: FA_rearma_10Rnd_338_Mk371_285gr { displayName = "[JMSB] 10Rnd .338 Mk371 285gr [Rearma] - Blue Tracer"; descriptionShort = "Mk371 285gr"; ammo = "FA_b_338_Mk371_285gr_T_Blue"; tracersEvery = 4; };
    class FA_rearma_10Rnd_338_Mk371_285gr_T_Orange: FA_rearma_10Rnd_338_Mk371_285gr { displayName = "[JMSB] 10Rnd .338 Mk371 285gr [Rearma] - Orange Tracer"; descriptionShort = "Mk371 285gr"; ammo = "FA_b_338_Mk371_285gr_T_Orange"; tracersEvery = 4; };
    class FA_rearma_10Rnd_338_Mk371_285gr_T_IR: FA_rearma_10Rnd_338_Mk371_285gr { displayName = "[JMSB] 10Rnd .338 Mk371 285gr [Rearma] - IR Tracer"; descriptionShort = "Mk371 285gr"; ammo = "FA_b_338_Mk371_285gr_T_IR"; tracersEvery = 4; };
    class FA_rearma_10Rnd_338_Mk371_300gr: 10Rnd_338_SVCh {
        author = QAUTHOR;
        displayName = "[JMSB] 10Rnd .338 Mk371 300gr [Rearma]";
        displayNameShort = "Mk371 300gr";
        descriptionShort = "Mk371 300gr";
        ammo = "FA_b_338_Mk371_300gr";
        initSpeed = 830;
    };
    class FA_rearma_10Rnd_338_Mk371_300gr_T_Red: FA_rearma_10Rnd_338_Mk371_300gr { displayName = "[JMSB] 10Rnd .338 Mk371 300gr [Rearma] - Red Tracer"; descriptionShort = "Mk371 300gr"; ammo = "FA_b_338_Mk371_300gr_T_Red"; tracersEvery = 4; };
    class FA_rearma_10Rnd_338_Mk371_300gr_T_Yellow: FA_rearma_10Rnd_338_Mk371_300gr { displayName = "[JMSB] 10Rnd .338 Mk371 300gr [Rearma] - Yellow Tracer"; descriptionShort = "Mk371 300gr"; ammo = "FA_b_338_Mk371_300gr_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_10Rnd_338_Mk371_300gr_T_Green: FA_rearma_10Rnd_338_Mk371_300gr { displayName = "[JMSB] 10Rnd .338 Mk371 300gr [Rearma] - Green Tracer"; descriptionShort = "Mk371 300gr"; ammo = "FA_b_338_Mk371_300gr_T_Green"; tracersEvery = 4; };
    class FA_rearma_10Rnd_338_Mk371_300gr_T_White: FA_rearma_10Rnd_338_Mk371_300gr { displayName = "[JMSB] 10Rnd .338 Mk371 300gr [Rearma] - White Tracer"; descriptionShort = "Mk371 300gr"; ammo = "FA_b_338_Mk371_300gr_T_White"; tracersEvery = 4; };
    class FA_rearma_10Rnd_338_Mk371_300gr_T_Blue: FA_rearma_10Rnd_338_Mk371_300gr { displayName = "[JMSB] 10Rnd .338 Mk371 300gr [Rearma] - Blue Tracer"; descriptionShort = "Mk371 300gr"; ammo = "FA_b_338_Mk371_300gr_T_Blue"; tracersEvery = 4; };
    class FA_rearma_10Rnd_338_Mk371_300gr_T_Orange: FA_rearma_10Rnd_338_Mk371_300gr { displayName = "[JMSB] 10Rnd .338 Mk371 300gr [Rearma] - Orange Tracer"; descriptionShort = "Mk371 300gr"; ammo = "FA_b_338_Mk371_300gr_T_Orange"; tracersEvery = 4; };
    class FA_rearma_10Rnd_338_Mk371_300gr_T_IR: FA_rearma_10Rnd_338_Mk371_300gr { displayName = "[JMSB] 10Rnd .338 Mk371 300gr [Rearma] - IR Tracer"; descriptionShort = "Mk371 300gr"; ammo = "FA_b_338_Mk371_300gr_T_IR"; tracersEvery = 4; };
    class FA_rearma_10Rnd_338_Mk373_PAB: 10Rnd_338_SVCh {
        author = QAUTHOR;
        displayName = "[JMSB] 10Rnd .338 Mk373 PAB [Rearma]";
        displayNameShort = "Mk373 PAB";
        descriptionShort = "Mk373 PAB airburst, counter-UAS";
        ammo = "FA_b_338_Mk373_PAB";
        initSpeed = 900;
    };
    class FA_rearma_10Rnd_338_Mk373_PAB_T_Red: FA_rearma_10Rnd_338_Mk373_PAB { displayName = "[JMSB] 10Rnd .338 Mk373 PAB [Rearma] - Red Tracer"; descriptionShort = "Mk373 PAB airburst, counter-UAS"; ammo = "FA_b_338_Mk373_PAB_T_Red"; tracersEvery = 4; };
    class FA_rearma_10Rnd_338_Mk373_PAB_T_Yellow: FA_rearma_10Rnd_338_Mk373_PAB { displayName = "[JMSB] 10Rnd .338 Mk373 PAB [Rearma] - Yellow Tracer"; descriptionShort = "Mk373 PAB airburst, counter-UAS"; ammo = "FA_b_338_Mk373_PAB_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_10Rnd_338_Mk373_PAB_T_Green: FA_rearma_10Rnd_338_Mk373_PAB { displayName = "[JMSB] 10Rnd .338 Mk373 PAB [Rearma] - Green Tracer"; descriptionShort = "Mk373 PAB airburst, counter-UAS"; ammo = "FA_b_338_Mk373_PAB_T_Green"; tracersEvery = 4; };
    class FA_rearma_10Rnd_338_Mk373_PAB_T_White: FA_rearma_10Rnd_338_Mk373_PAB { displayName = "[JMSB] 10Rnd .338 Mk373 PAB [Rearma] - White Tracer"; descriptionShort = "Mk373 PAB airburst, counter-UAS"; ammo = "FA_b_338_Mk373_PAB_T_White"; tracersEvery = 4; };
    class FA_rearma_10Rnd_338_Mk373_PAB_T_Blue: FA_rearma_10Rnd_338_Mk373_PAB { displayName = "[JMSB] 10Rnd .338 Mk373 PAB [Rearma] - Blue Tracer"; descriptionShort = "Mk373 PAB airburst, counter-UAS"; ammo = "FA_b_338_Mk373_PAB_T_Blue"; tracersEvery = 4; };
    class FA_rearma_10Rnd_338_Mk373_PAB_T_Orange: FA_rearma_10Rnd_338_Mk373_PAB { displayName = "[JMSB] 10Rnd .338 Mk373 PAB [Rearma] - Orange Tracer"; descriptionShort = "Mk373 PAB airburst, counter-UAS"; ammo = "FA_b_338_Mk373_PAB_T_Orange"; tracersEvery = 4; };

    // ===== 17Rnd 9x19 - MP-443 / MP-446 S - body 17Rnd_9x19_MP443_Mag_F =====
    class FA_rearma_17Rnd_9x19_7N53_AP: 17Rnd_9x19_MP443_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 17Rnd 9mm 7N53 AP";
        displayNameShort = "7N53 AP";
        descriptionShort = "7N53 AP";
        ammo = "FA_o_9x19_7N53_AP";
        initSpeed = 470;
    };
    class FA_rearma_17Rnd_9x19_7U17_SUB: 17Rnd_9x19_MP443_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 17Rnd 9mm 7U17 SUB";
        displayNameShort = "7U17 SUB";
        descriptionShort = "7U17 SUB";
        ammo = "FA_o_9x19_7U17_SUB";
        initSpeed = 295;
    };

    // ===== 5Rnd 23mm shot - KS-23 - body 5Rnd_23mm_Pellets =====
    class FA_rearma_5Rnd_23mm_ShrapnelAD50: 5Rnd_23mm_Pellets {
        author = QAUTHOR;
        displayName = "[JMSB] 5Rnd 23mm ShrapnelAD50";
        displayNameShort = "Shrapnel-AD50";
        descriptionShort = "Shrapnel-AD50 anti-drone shot, 24 pellets, eff. 50 m";
        ammo = "FA_o_23mm_ShrapnelAD50";
        initSpeed = 400;
        tracersEvery = 0;
        lastRoundsTracer = 0;
    };
    class FA_rearma_5Rnd_23mm_ShrapnelAD100: 5Rnd_23mm_Pellets {
        author = QAUTHOR;
        displayName = "[JMSB] 5Rnd 23mm ShrapnelAD100";
        displayNameShort = "Shrapnel-AD100";
        descriptionShort = "Shrapnel-AD100 anti-drone shot, 14 tungsten pellets, eff. 100 m";
        ammo = "FA_o_23mm_ShrapnelAD100";
        initSpeed = 380;
        tracersEvery = 0;
        lastRoundsTracer = 0;
    };

    // ===== 5Rnd 23mm slug - KS-23 - body 5Rnd_23mm_Slug =====
    class FA_rearma_5Rnd_23mm_BarrikadaAB: 5Rnd_23mm_Slug {
        author = QAUTHOR;
        displayName = "[JMSB] 5Rnd 23mm BarrikadaAB";
        displayNameShort = "Barrikada-AB";
        descriptionShort = "Barrikada-AB proximity airburst slug, counter-UAS";
        ammo = "FA_o_23mm_BarrikadaAB";
        initSpeed = 420;
        tracersEvery = 0;
        lastRoundsTracer = 0;
    };

    // ===== RPG-26 72.5mm - FA disposable variants, body RPG26_M =====
    class FA_rearma_RPG26M2_TNDM: RPG26_M {
        author = QAUTHOR;
        scope = 1;
        displayName = "[JMSB] RPG26M2 TNDM";
        descriptionShort = "72.5mm RPG-26M2 TNDM (2040)<br/>Tandem HEAT - ~600 mm RHA, 250 m";
        ammo = "FA_R_RPG26M2_TNDM";
    };
    class FA_rearma_RPG26_AB26: RPG26_M {
        author = QAUTHOR;
        scope = 1;
        displayName = "[JMSB] RPG26 AB26";
        descriptionShort = "72.5mm AB-26 PROX (2040)<br/>C-UAS proximity airburst - scripted fuze, 200 m";
        ammo = "FA_R_RPG26_AB26";
    };

    // ===== RShG-2 72.5mm - FA disposable variants, body RSHG2_M =====
    class FA_rearma_RShG2M2_TBX: RSHG2_M {
        author = QAUTHOR;
        scope = 1;
        displayName = "[JMSB] RShG2M2 TBX";
        descriptionShort = "72.5mm RShG-2M2 TBX (2040)<br/>Thermobaric, anti-structure / anti-personnel - 250 m";
        ammo = "FA_R_RShG2M2_TBX";
    };
};
