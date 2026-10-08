// FA rounds on rearma's own Chinese magazine bodies, so the arsenal and the
// weapon show the right model. Every magazine joins the rearma well its body
// already lives in (CfgMagazinewells.hpp). Rifle / MG loads carry the full
// tracer set; shot, SMG, pistol, grenade and missile loads have none. The
// QJS-201 belt body fires a tracer every third round, so FA's base belts reset
// that and tracers only come from the _T_ variants.
class CfgMagazines {
    class 30Rnd_58x42_Mag_F;
    class 30Rnd_58x42_TP_Mag_F;
    class 30Rnd_58x42_AP_Mag_F;
    class 30Rnd_58x42_AP_TP_Mag_F;
    class 30Rnd_58x42SG_Mag_F;
    class 30Rnd_58x42SG_TP_Mag_F;
    class 150Rnd_58x42_Mag_F;
    class 20Rnd_86x39_Mag_F;
    class 5Rnd_338_SN_Mag;
    class 5Rnd_127x108_Mag;
    class CA_Magazine;
    class 15Rnd_9x21_Mag;
    class 2Rnd_12Gauge_Pellets;
    class 2Rnd_12Gauge_Slug;
    class 7Rnd_HE_35mm;
    class QN205_HEAT;
    class M_PF89_F;
    // rearma's WPF-89 rocket is 35, so the loaded tube (20, CfgWeapons.hpp) plus the
    // rocket came to 55 against the launcher's 65 and CBA's disposable check warned.
    // 45 keeps the arsenal weight rearma gives it. The FA TBX round inherits this.
    class M_WPF89_F: M_PF89_F {
        mass = 45;
    };

    // ===== 30Rnd 5.8x42 - QBZ-191 / QBZ-192 / QBU-191 / QJS-201 - body 30Rnd_58x42_Mag_F =====
    class FA_rearma_30Rnd_580x42_Ball_HV: 30Rnd_58x42_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 5.8mm Ball HV [Rearma]";
        displayNameShort = "5.8x42mm Ball HV";
        descriptionShort = "5.8x42mm Ball HV";
        ammo = "FA_o_580_Ball_HV";
        initSpeed = 940;
    };
    class FA_rearma_30Rnd_580x42_Ball_HV_T_Red: FA_rearma_30Rnd_580x42_Ball_HV { displayName = "[JMSB] 30Rnd 5.8mm Ball HV [Rearma] - Red Tracer"; descriptionShort = "5.8x42mm Ball HV"; ammo = "FA_o_580_Ball_HV_T_Red"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_Ball_HV_T_Yellow: FA_rearma_30Rnd_580x42_Ball_HV { displayName = "[JMSB] 30Rnd 5.8mm Ball HV [Rearma] - Yellow Tracer"; descriptionShort = "5.8x42mm Ball HV"; ammo = "FA_o_580_Ball_HV_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_Ball_HV_T_Green: FA_rearma_30Rnd_580x42_Ball_HV { displayName = "[JMSB] 30Rnd 5.8mm Ball HV [Rearma] - Green Tracer"; descriptionShort = "5.8x42mm Ball HV"; ammo = "FA_o_580_Ball_HV_T_Green"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_Ball_HV_T_White: FA_rearma_30Rnd_580x42_Ball_HV { displayName = "[JMSB] 30Rnd 5.8mm Ball HV [Rearma] - White Tracer"; descriptionShort = "5.8x42mm Ball HV"; ammo = "FA_o_580_Ball_HV_T_White"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_Ball_HV_T_Blue: FA_rearma_30Rnd_580x42_Ball_HV { displayName = "[JMSB] 30Rnd 5.8mm Ball HV [Rearma] - Blue Tracer"; descriptionShort = "5.8x42mm Ball HV"; ammo = "FA_o_580_Ball_HV_T_Blue"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_Ball_HV_T_Orange: FA_rearma_30Rnd_580x42_Ball_HV { displayName = "[JMSB] 30Rnd 5.8mm Ball HV [Rearma] - Orange Tracer"; descriptionShort = "5.8x42mm Ball HV"; ammo = "FA_o_580_Ball_HV_T_Orange"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_Ball_HV_T_IR: FA_rearma_30Rnd_580x42_Ball_HV { displayName = "[JMSB] 30Rnd 5.8mm Ball HV [Rearma] - IR Tracer"; descriptionShort = "5.8x42mm Ball HV"; ammo = "FA_o_580_Ball_HV_T_IR"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_DBP39_CT: 30Rnd_58x42_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 5.8mm DBP39 CT [Rearma]";
        displayNameShort = "DBP-39 CT";
        descriptionShort = "DBP-39 CT";
        ammo = "FA_o_580_DBP39_CT";
        initSpeed = 950;
    };
    class FA_rearma_30Rnd_580x42_DBP39_CT_T_Red: FA_rearma_30Rnd_580x42_DBP39_CT { displayName = "[JMSB] 30Rnd 5.8mm DBP39 CT [Rearma] - Red Tracer"; descriptionShort = "DBP-39 CT"; ammo = "FA_o_580_DBP39_CT_T_Red"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_DBP39_CT_T_Yellow: FA_rearma_30Rnd_580x42_DBP39_CT { displayName = "[JMSB] 30Rnd 5.8mm DBP39 CT [Rearma] - Yellow Tracer"; descriptionShort = "DBP-39 CT"; ammo = "FA_o_580_DBP39_CT_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_DBP39_CT_T_Green: FA_rearma_30Rnd_580x42_DBP39_CT { displayName = "[JMSB] 30Rnd 5.8mm DBP39 CT [Rearma] - Green Tracer"; descriptionShort = "DBP-39 CT"; ammo = "FA_o_580_DBP39_CT_T_Green"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_DBP39_CT_T_White: FA_rearma_30Rnd_580x42_DBP39_CT { displayName = "[JMSB] 30Rnd 5.8mm DBP39 CT [Rearma] - White Tracer"; descriptionShort = "DBP-39 CT"; ammo = "FA_o_580_DBP39_CT_T_White"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_DBP39_CT_T_Blue: FA_rearma_30Rnd_580x42_DBP39_CT { displayName = "[JMSB] 30Rnd 5.8mm DBP39 CT [Rearma] - Blue Tracer"; descriptionShort = "DBP-39 CT"; ammo = "FA_o_580_DBP39_CT_T_Blue"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_DBP39_CT_T_Orange: FA_rearma_30Rnd_580x42_DBP39_CT { displayName = "[JMSB] 30Rnd 5.8mm DBP39 CT [Rearma] - Orange Tracer"; descriptionShort = "DBP-39 CT"; ammo = "FA_o_580_DBP39_CT_T_Orange"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_DBP39_CT_T_IR: FA_rearma_30Rnd_580x42_DBP39_CT { displayName = "[JMSB] 30Rnd 5.8mm DBP39 CT [Rearma] - IR Tracer"; descriptionShort = "DBP-39 CT"; ammo = "FA_o_580_DBP39_CT_T_IR"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_DBP40_AP: 30Rnd_58x42_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 5.8mm DBP40 AP [Rearma]";
        displayNameShort = "DBP-40 AP";
        descriptionShort = "DBP-40 AP";
        ammo = "FA_o_580_DBP40_AP";
        initSpeed = 915;
    };
    class FA_rearma_30Rnd_580x42_DBP40_AP_T_Red: FA_rearma_30Rnd_580x42_DBP40_AP { displayName = "[JMSB] 30Rnd 5.8mm DBP40 AP [Rearma] - Red Tracer"; descriptionShort = "DBP-40 AP"; ammo = "FA_o_580_DBP40_AP_T_Red"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_DBP40_AP_T_Yellow: FA_rearma_30Rnd_580x42_DBP40_AP { displayName = "[JMSB] 30Rnd 5.8mm DBP40 AP [Rearma] - Yellow Tracer"; descriptionShort = "DBP-40 AP"; ammo = "FA_o_580_DBP40_AP_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_DBP40_AP_T_Green: FA_rearma_30Rnd_580x42_DBP40_AP { displayName = "[JMSB] 30Rnd 5.8mm DBP40 AP [Rearma] - Green Tracer"; descriptionShort = "DBP-40 AP"; ammo = "FA_o_580_DBP40_AP_T_Green"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_DBP40_AP_T_White: FA_rearma_30Rnd_580x42_DBP40_AP { displayName = "[JMSB] 30Rnd 5.8mm DBP40 AP [Rearma] - White Tracer"; descriptionShort = "DBP-40 AP"; ammo = "FA_o_580_DBP40_AP_T_White"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_DBP40_AP_T_Blue: FA_rearma_30Rnd_580x42_DBP40_AP { displayName = "[JMSB] 30Rnd 5.8mm DBP40 AP [Rearma] - Blue Tracer"; descriptionShort = "DBP-40 AP"; ammo = "FA_o_580_DBP40_AP_T_Blue"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_DBP40_AP_T_Orange: FA_rearma_30Rnd_580x42_DBP40_AP { displayName = "[JMSB] 30Rnd 5.8mm DBP40 AP [Rearma] - Orange Tracer"; descriptionShort = "DBP-40 AP"; ammo = "FA_o_580_DBP40_AP_T_Orange"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_DBP40_AP_T_IR: FA_rearma_30Rnd_580x42_DBP40_AP { displayName = "[JMSB] 30Rnd 5.8mm DBP40 AP [Rearma] - IR Tracer"; descriptionShort = "DBP-40 AP"; ammo = "FA_o_580_DBP40_AP_T_IR"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_DBJ39_PAB: 30Rnd_58x42_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 5.8mm DBJ39 PAB";
        displayNameShort = "DBJ-39 PAB";
        descriptionShort = "DBJ-39 PAB airburst, counter-UAS";
        ammo = "FA_o_580_DBJ39_PAB";
        initSpeed = 940;
    };
    class FA_rearma_30Rnd_580x42_DBJ39_PAB_T_Red: FA_rearma_30Rnd_580x42_DBJ39_PAB { displayName = "[JMSB] 30Rnd 5.8mm DBJ39 PAB - Red Tracer"; descriptionShort = "DBJ-39 PAB airburst, counter-UAS"; ammo = "FA_o_580_DBJ39_PAB_T_Red"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_DBJ39_PAB_T_Yellow: FA_rearma_30Rnd_580x42_DBJ39_PAB { displayName = "[JMSB] 30Rnd 5.8mm DBJ39 PAB - Yellow Tracer"; descriptionShort = "DBJ-39 PAB airburst, counter-UAS"; ammo = "FA_o_580_DBJ39_PAB_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_DBJ39_PAB_T_Green: FA_rearma_30Rnd_580x42_DBJ39_PAB { displayName = "[JMSB] 30Rnd 5.8mm DBJ39 PAB - Green Tracer"; descriptionShort = "DBJ-39 PAB airburst, counter-UAS"; ammo = "FA_o_580_DBJ39_PAB_T_Green"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_DBJ39_PAB_T_White: FA_rearma_30Rnd_580x42_DBJ39_PAB { displayName = "[JMSB] 30Rnd 5.8mm DBJ39 PAB - White Tracer"; descriptionShort = "DBJ-39 PAB airburst, counter-UAS"; ammo = "FA_o_580_DBJ39_PAB_T_White"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_DBJ39_PAB_T_Blue: FA_rearma_30Rnd_580x42_DBJ39_PAB { displayName = "[JMSB] 30Rnd 5.8mm DBJ39 PAB - Blue Tracer"; descriptionShort = "DBJ-39 PAB airburst, counter-UAS"; ammo = "FA_o_580_DBJ39_PAB_T_Blue"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_DBJ39_PAB_T_Orange: FA_rearma_30Rnd_580x42_DBJ39_PAB { displayName = "[JMSB] 30Rnd 5.8mm DBJ39 PAB - Orange Tracer"; descriptionShort = "DBJ-39 PAB airburst, counter-UAS"; ammo = "FA_o_580_DBJ39_PAB_T_Orange"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_DBJ39_PAB_T_IR: FA_rearma_30Rnd_580x42_DBJ39_PAB { displayName = "[JMSB] 30Rnd 5.8mm DBJ39 PAB - IR Tracer"; descriptionShort = "DBJ-39 PAB airburst, counter-UAS"; ammo = "FA_o_580_DBJ39_PAB_T_IR"; tracersEvery = 4; };

    // ===== 30Rnd 5.8x42 transparent - body 30Rnd_58x42_TP_Mag_F =====
    class FA_rearma_30Rnd_580x42_TP_Ball_HV: 30Rnd_58x42_TP_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 5.8mm TP Ball HV";
        displayNameShort = "5.8x42mm Ball HV";
        descriptionShort = "5.8x42mm Ball HV";
        ammo = "FA_o_580_Ball_HV";
        initSpeed = 940;
    };
    class FA_rearma_30Rnd_580x42_TP_Ball_HV_T_Red: FA_rearma_30Rnd_580x42_TP_Ball_HV { displayName = "[JMSB] 30Rnd 5.8mm TP Ball HV - Red Tracer"; descriptionShort = "5.8x42mm Ball HV"; ammo = "FA_o_580_Ball_HV_T_Red"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_TP_Ball_HV_T_Yellow: FA_rearma_30Rnd_580x42_TP_Ball_HV { displayName = "[JMSB] 30Rnd 5.8mm TP Ball HV - Yellow Tracer"; descriptionShort = "5.8x42mm Ball HV"; ammo = "FA_o_580_Ball_HV_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_TP_Ball_HV_T_Green: FA_rearma_30Rnd_580x42_TP_Ball_HV { displayName = "[JMSB] 30Rnd 5.8mm TP Ball HV - Green Tracer"; descriptionShort = "5.8x42mm Ball HV"; ammo = "FA_o_580_Ball_HV_T_Green"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_TP_Ball_HV_T_White: FA_rearma_30Rnd_580x42_TP_Ball_HV { displayName = "[JMSB] 30Rnd 5.8mm TP Ball HV - White Tracer"; descriptionShort = "5.8x42mm Ball HV"; ammo = "FA_o_580_Ball_HV_T_White"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_TP_Ball_HV_T_Blue: FA_rearma_30Rnd_580x42_TP_Ball_HV { displayName = "[JMSB] 30Rnd 5.8mm TP Ball HV - Blue Tracer"; descriptionShort = "5.8x42mm Ball HV"; ammo = "FA_o_580_Ball_HV_T_Blue"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_TP_Ball_HV_T_Orange: FA_rearma_30Rnd_580x42_TP_Ball_HV { displayName = "[JMSB] 30Rnd 5.8mm TP Ball HV - Orange Tracer"; descriptionShort = "5.8x42mm Ball HV"; ammo = "FA_o_580_Ball_HV_T_Orange"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_TP_Ball_HV_T_IR: FA_rearma_30Rnd_580x42_TP_Ball_HV { displayName = "[JMSB] 30Rnd 5.8mm TP Ball HV - IR Tracer"; descriptionShort = "5.8x42mm Ball HV"; ammo = "FA_o_580_Ball_HV_T_IR"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_TP_DBP39_CT: 30Rnd_58x42_TP_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 5.8mm TP DBP39 CT";
        displayNameShort = "DBP-39 CT";
        descriptionShort = "DBP-39 CT";
        ammo = "FA_o_580_DBP39_CT";
        initSpeed = 950;
    };
    class FA_rearma_30Rnd_580x42_TP_DBP39_CT_T_Red: FA_rearma_30Rnd_580x42_TP_DBP39_CT { displayName = "[JMSB] 30Rnd 5.8mm TP DBP39 CT - Red Tracer"; descriptionShort = "DBP-39 CT"; ammo = "FA_o_580_DBP39_CT_T_Red"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_TP_DBP39_CT_T_Yellow: FA_rearma_30Rnd_580x42_TP_DBP39_CT { displayName = "[JMSB] 30Rnd 5.8mm TP DBP39 CT - Yellow Tracer"; descriptionShort = "DBP-39 CT"; ammo = "FA_o_580_DBP39_CT_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_TP_DBP39_CT_T_Green: FA_rearma_30Rnd_580x42_TP_DBP39_CT { displayName = "[JMSB] 30Rnd 5.8mm TP DBP39 CT - Green Tracer"; descriptionShort = "DBP-39 CT"; ammo = "FA_o_580_DBP39_CT_T_Green"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_TP_DBP39_CT_T_White: FA_rearma_30Rnd_580x42_TP_DBP39_CT { displayName = "[JMSB] 30Rnd 5.8mm TP DBP39 CT - White Tracer"; descriptionShort = "DBP-39 CT"; ammo = "FA_o_580_DBP39_CT_T_White"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_TP_DBP39_CT_T_Blue: FA_rearma_30Rnd_580x42_TP_DBP39_CT { displayName = "[JMSB] 30Rnd 5.8mm TP DBP39 CT - Blue Tracer"; descriptionShort = "DBP-39 CT"; ammo = "FA_o_580_DBP39_CT_T_Blue"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_TP_DBP39_CT_T_Orange: FA_rearma_30Rnd_580x42_TP_DBP39_CT { displayName = "[JMSB] 30Rnd 5.8mm TP DBP39 CT - Orange Tracer"; descriptionShort = "DBP-39 CT"; ammo = "FA_o_580_DBP39_CT_T_Orange"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_TP_DBP39_CT_T_IR: FA_rearma_30Rnd_580x42_TP_DBP39_CT { displayName = "[JMSB] 30Rnd 5.8mm TP DBP39 CT - IR Tracer"; descriptionShort = "DBP-39 CT"; ammo = "FA_o_580_DBP39_CT_T_IR"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_TP_DBP40_AP: 30Rnd_58x42_TP_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 5.8mm TP DBP40 AP";
        displayNameShort = "DBP-40 AP";
        descriptionShort = "DBP-40 AP";
        ammo = "FA_o_580_DBP40_AP";
        initSpeed = 915;
    };
    class FA_rearma_30Rnd_580x42_TP_DBP40_AP_T_Red: FA_rearma_30Rnd_580x42_TP_DBP40_AP { displayName = "[JMSB] 30Rnd 5.8mm TP DBP40 AP - Red Tracer"; descriptionShort = "DBP-40 AP"; ammo = "FA_o_580_DBP40_AP_T_Red"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_TP_DBP40_AP_T_Yellow: FA_rearma_30Rnd_580x42_TP_DBP40_AP { displayName = "[JMSB] 30Rnd 5.8mm TP DBP40 AP - Yellow Tracer"; descriptionShort = "DBP-40 AP"; ammo = "FA_o_580_DBP40_AP_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_TP_DBP40_AP_T_Green: FA_rearma_30Rnd_580x42_TP_DBP40_AP { displayName = "[JMSB] 30Rnd 5.8mm TP DBP40 AP - Green Tracer"; descriptionShort = "DBP-40 AP"; ammo = "FA_o_580_DBP40_AP_T_Green"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_TP_DBP40_AP_T_White: FA_rearma_30Rnd_580x42_TP_DBP40_AP { displayName = "[JMSB] 30Rnd 5.8mm TP DBP40 AP - White Tracer"; descriptionShort = "DBP-40 AP"; ammo = "FA_o_580_DBP40_AP_T_White"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_TP_DBP40_AP_T_Blue: FA_rearma_30Rnd_580x42_TP_DBP40_AP { displayName = "[JMSB] 30Rnd 5.8mm TP DBP40 AP - Blue Tracer"; descriptionShort = "DBP-40 AP"; ammo = "FA_o_580_DBP40_AP_T_Blue"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_TP_DBP40_AP_T_Orange: FA_rearma_30Rnd_580x42_TP_DBP40_AP { displayName = "[JMSB] 30Rnd 5.8mm TP DBP40 AP - Orange Tracer"; descriptionShort = "DBP-40 AP"; ammo = "FA_o_580_DBP40_AP_T_Orange"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_TP_DBP40_AP_T_IR: FA_rearma_30Rnd_580x42_TP_DBP40_AP { displayName = "[JMSB] 30Rnd 5.8mm TP DBP40 AP - IR Tracer"; descriptionShort = "DBP-40 AP"; ammo = "FA_o_580_DBP40_AP_T_IR"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_TP_DBJ39_PAB: 30Rnd_58x42_TP_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 5.8mm TP DBJ39 PAB";
        displayNameShort = "DBJ-39 PAB";
        descriptionShort = "DBJ-39 PAB airburst, counter-UAS";
        ammo = "FA_o_580_DBJ39_PAB";
        initSpeed = 940;
    };
    class FA_rearma_30Rnd_580x42_TP_DBJ39_PAB_T_Red: FA_rearma_30Rnd_580x42_TP_DBJ39_PAB { displayName = "[JMSB] 30Rnd 5.8mm TP DBJ39 PAB - Red Tracer"; descriptionShort = "DBJ-39 PAB airburst, counter-UAS"; ammo = "FA_o_580_DBJ39_PAB_T_Red"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_TP_DBJ39_PAB_T_Yellow: FA_rearma_30Rnd_580x42_TP_DBJ39_PAB { displayName = "[JMSB] 30Rnd 5.8mm TP DBJ39 PAB - Yellow Tracer"; descriptionShort = "DBJ-39 PAB airburst, counter-UAS"; ammo = "FA_o_580_DBJ39_PAB_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_TP_DBJ39_PAB_T_Green: FA_rearma_30Rnd_580x42_TP_DBJ39_PAB { displayName = "[JMSB] 30Rnd 5.8mm TP DBJ39 PAB - Green Tracer"; descriptionShort = "DBJ-39 PAB airburst, counter-UAS"; ammo = "FA_o_580_DBJ39_PAB_T_Green"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_TP_DBJ39_PAB_T_White: FA_rearma_30Rnd_580x42_TP_DBJ39_PAB { displayName = "[JMSB] 30Rnd 5.8mm TP DBJ39 PAB - White Tracer"; descriptionShort = "DBJ-39 PAB airburst, counter-UAS"; ammo = "FA_o_580_DBJ39_PAB_T_White"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_TP_DBJ39_PAB_T_Blue: FA_rearma_30Rnd_580x42_TP_DBJ39_PAB { displayName = "[JMSB] 30Rnd 5.8mm TP DBJ39 PAB - Blue Tracer"; descriptionShort = "DBJ-39 PAB airburst, counter-UAS"; ammo = "FA_o_580_DBJ39_PAB_T_Blue"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_TP_DBJ39_PAB_T_Orange: FA_rearma_30Rnd_580x42_TP_DBJ39_PAB { displayName = "[JMSB] 30Rnd 5.8mm TP DBJ39 PAB - Orange Tracer"; descriptionShort = "DBJ-39 PAB airburst, counter-UAS"; ammo = "FA_o_580_DBJ39_PAB_T_Orange"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_TP_DBJ39_PAB_T_IR: FA_rearma_30Rnd_580x42_TP_DBJ39_PAB { displayName = "[JMSB] 30Rnd 5.8mm TP DBJ39 PAB - IR Tracer"; descriptionShort = "DBJ-39 PAB airburst, counter-UAS"; ammo = "FA_o_580_DBJ39_PAB_T_IR"; tracersEvery = 4; };

    // ===== 30Rnd 5.8x42 AP-marked - body 30Rnd_58x42_AP_Mag_F =====
    class FA_rearma_30Rnd_580x42_AP_DBP40_AP: 30Rnd_58x42_AP_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 5.8mm AP DBP40";
        displayNameShort = "DBP-40 AP";
        descriptionShort = "DBP-40 AP";
        ammo = "FA_o_580_DBP40_AP";
        initSpeed = 915;
    };
    class FA_rearma_30Rnd_580x42_AP_DBP40_AP_T_Red: FA_rearma_30Rnd_580x42_AP_DBP40_AP { displayName = "[JMSB] 30Rnd 5.8mm AP DBP40 - Red Tracer"; descriptionShort = "DBP-40 AP"; ammo = "FA_o_580_DBP40_AP_T_Red"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_AP_DBP40_AP_T_Yellow: FA_rearma_30Rnd_580x42_AP_DBP40_AP { displayName = "[JMSB] 30Rnd 5.8mm AP DBP40 - Yellow Tracer"; descriptionShort = "DBP-40 AP"; ammo = "FA_o_580_DBP40_AP_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_AP_DBP40_AP_T_Green: FA_rearma_30Rnd_580x42_AP_DBP40_AP { displayName = "[JMSB] 30Rnd 5.8mm AP DBP40 - Green Tracer"; descriptionShort = "DBP-40 AP"; ammo = "FA_o_580_DBP40_AP_T_Green"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_AP_DBP40_AP_T_White: FA_rearma_30Rnd_580x42_AP_DBP40_AP { displayName = "[JMSB] 30Rnd 5.8mm AP DBP40 - White Tracer"; descriptionShort = "DBP-40 AP"; ammo = "FA_o_580_DBP40_AP_T_White"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_AP_DBP40_AP_T_Blue: FA_rearma_30Rnd_580x42_AP_DBP40_AP { displayName = "[JMSB] 30Rnd 5.8mm AP DBP40 - Blue Tracer"; descriptionShort = "DBP-40 AP"; ammo = "FA_o_580_DBP40_AP_T_Blue"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_AP_DBP40_AP_T_Orange: FA_rearma_30Rnd_580x42_AP_DBP40_AP { displayName = "[JMSB] 30Rnd 5.8mm AP DBP40 - Orange Tracer"; descriptionShort = "DBP-40 AP"; ammo = "FA_o_580_DBP40_AP_T_Orange"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_AP_DBP40_AP_T_IR: FA_rearma_30Rnd_580x42_AP_DBP40_AP { displayName = "[JMSB] 30Rnd 5.8mm AP DBP40 - IR Tracer"; descriptionShort = "DBP-40 AP"; ammo = "FA_o_580_DBP40_AP_T_IR"; tracersEvery = 4; };

    // ===== 30Rnd 5.8x42 AP-marked transparent - body 30Rnd_58x42_AP_TP_Mag_F =====
    class FA_rearma_30Rnd_580x42_APTP_DBP40_AP: 30Rnd_58x42_AP_TP_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 5.8mm APTP DBP40 AP";
        displayNameShort = "DBP-40 AP";
        descriptionShort = "DBP-40 AP";
        ammo = "FA_o_580_DBP40_AP";
        initSpeed = 915;
    };
    class FA_rearma_30Rnd_580x42_APTP_DBP40_AP_T_Red: FA_rearma_30Rnd_580x42_APTP_DBP40_AP { displayName = "[JMSB] 30Rnd 5.8mm APTP DBP40 AP - Red Tracer"; descriptionShort = "DBP-40 AP"; ammo = "FA_o_580_DBP40_AP_T_Red"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_APTP_DBP40_AP_T_Yellow: FA_rearma_30Rnd_580x42_APTP_DBP40_AP { displayName = "[JMSB] 30Rnd 5.8mm APTP DBP40 AP - Yellow Tracer"; descriptionShort = "DBP-40 AP"; ammo = "FA_o_580_DBP40_AP_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_APTP_DBP40_AP_T_Green: FA_rearma_30Rnd_580x42_APTP_DBP40_AP { displayName = "[JMSB] 30Rnd 5.8mm APTP DBP40 AP - Green Tracer"; descriptionShort = "DBP-40 AP"; ammo = "FA_o_580_DBP40_AP_T_Green"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_APTP_DBP40_AP_T_White: FA_rearma_30Rnd_580x42_APTP_DBP40_AP { displayName = "[JMSB] 30Rnd 5.8mm APTP DBP40 AP - White Tracer"; descriptionShort = "DBP-40 AP"; ammo = "FA_o_580_DBP40_AP_T_White"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_APTP_DBP40_AP_T_Blue: FA_rearma_30Rnd_580x42_APTP_DBP40_AP { displayName = "[JMSB] 30Rnd 5.8mm APTP DBP40 AP - Blue Tracer"; descriptionShort = "DBP-40 AP"; ammo = "FA_o_580_DBP40_AP_T_Blue"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_APTP_DBP40_AP_T_Orange: FA_rearma_30Rnd_580x42_APTP_DBP40_AP { displayName = "[JMSB] 30Rnd 5.8mm APTP DBP40 AP - Orange Tracer"; descriptionShort = "DBP-40 AP"; ammo = "FA_o_580_DBP40_AP_T_Orange"; tracersEvery = 4; };
    class FA_rearma_30Rnd_580x42_APTP_DBP40_AP_T_IR: FA_rearma_30Rnd_580x42_APTP_DBP40_AP { displayName = "[JMSB] 30Rnd 5.8mm APTP DBP40 AP - IR Tracer"; descriptionShort = "DBP-40 AP"; ammo = "FA_o_580_DBP40_AP_T_IR"; tracersEvery = 4; };

    // ===== 30Rnd 5.8x42 pellet mag - body 30Rnd_58x42SG_Mag_F =====
    class FA_rearma_30Rnd_580x42_SG_DBS39K_AD: 30Rnd_58x42SG_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 5.8mm SG DBS39K AD";
        displayNameShort = "DBS-39K AD";
        descriptionShort = "DBS-39K AD 8-pellet shot, eff. 110 m";
        ammo = "FA_o_580_DBS39K_AD";
        initSpeed = 680;
        tracersEvery = 0;
        lastRoundsTracer = 0;
    };
    class FA_rearma_30Rnd_580x42_SG_DBS39L_AD: 30Rnd_58x42SG_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 5.8mm SG DBS39L AD";
        displayNameShort = "DBS-39L AD";
        descriptionShort = "DBS-39L AD 6-pellet shot, eff. 210 m";
        ammo = "FA_o_580_DBS39L_AD";
        initSpeed = 680;
        tracersEvery = 0;
        lastRoundsTracer = 0;
    };

    // ===== 30Rnd 5.8x42 transparent pellet mag - body 30Rnd_58x42SG_TP_Mag_F =====
    class FA_rearma_30Rnd_580x42_SGTP_DBS39K_AD: 30Rnd_58x42SG_TP_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 5.8mm SGTP DBS39K AD";
        displayNameShort = "DBS-39K AD";
        descriptionShort = "DBS-39K AD 8-pellet shot, eff. 110 m";
        ammo = "FA_o_580_DBS39K_AD";
        initSpeed = 680;
        tracersEvery = 0;
        lastRoundsTracer = 0;
    };
    class FA_rearma_30Rnd_580x42_SGTP_DBS39L_AD: 30Rnd_58x42SG_TP_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 5.8mm SGTP DBS39L AD";
        displayNameShort = "DBS-39L AD";
        descriptionShort = "DBS-39L AD 6-pellet shot, eff. 210 m";
        ammo = "FA_o_580_DBS39L_AD";
        initSpeed = 680;
        tracersEvery = 0;
        lastRoundsTracer = 0;
    };

    // ===== 150Rnd 5.8x42 belt - QJS-201 - body 150Rnd_58x42_Mag_F =====
    class FA_rearma_150Rnd_580x42_Ball_HV: 150Rnd_58x42_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 150Rnd 5.8mm Ball HV";
        displayNameShort = "5.8x42mm Ball HV";
        descriptionShort = "5.8x42mm Ball HV";
        ammo = "FA_o_580_Ball_HV";
        initSpeed = 940;
        tracersEvery = 0;
    };
    class FA_rearma_150Rnd_580x42_Ball_HV_T_Red: FA_rearma_150Rnd_580x42_Ball_HV { displayName = "[JMSB] 150Rnd 5.8mm Ball HV - Red Tracer"; descriptionShort = "5.8x42mm Ball HV"; ammo = "FA_o_580_Ball_HV_T_Red"; tracersEvery = 4; };
    class FA_rearma_150Rnd_580x42_Ball_HV_T_Yellow: FA_rearma_150Rnd_580x42_Ball_HV { displayName = "[JMSB] 150Rnd 5.8mm Ball HV - Yellow Tracer"; descriptionShort = "5.8x42mm Ball HV"; ammo = "FA_o_580_Ball_HV_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_150Rnd_580x42_Ball_HV_T_Green: FA_rearma_150Rnd_580x42_Ball_HV { displayName = "[JMSB] 150Rnd 5.8mm Ball HV - Green Tracer"; descriptionShort = "5.8x42mm Ball HV"; ammo = "FA_o_580_Ball_HV_T_Green"; tracersEvery = 4; };
    class FA_rearma_150Rnd_580x42_Ball_HV_T_White: FA_rearma_150Rnd_580x42_Ball_HV { displayName = "[JMSB] 150Rnd 5.8mm Ball HV - White Tracer"; descriptionShort = "5.8x42mm Ball HV"; ammo = "FA_o_580_Ball_HV_T_White"; tracersEvery = 4; };
    class FA_rearma_150Rnd_580x42_Ball_HV_T_Blue: FA_rearma_150Rnd_580x42_Ball_HV { displayName = "[JMSB] 150Rnd 5.8mm Ball HV - Blue Tracer"; descriptionShort = "5.8x42mm Ball HV"; ammo = "FA_o_580_Ball_HV_T_Blue"; tracersEvery = 4; };
    class FA_rearma_150Rnd_580x42_Ball_HV_T_Orange: FA_rearma_150Rnd_580x42_Ball_HV { displayName = "[JMSB] 150Rnd 5.8mm Ball HV - Orange Tracer"; descriptionShort = "5.8x42mm Ball HV"; ammo = "FA_o_580_Ball_HV_T_Orange"; tracersEvery = 4; };
    class FA_rearma_150Rnd_580x42_Ball_HV_T_IR: FA_rearma_150Rnd_580x42_Ball_HV { displayName = "[JMSB] 150Rnd 5.8mm Ball HV - IR Tracer"; descriptionShort = "5.8x42mm Ball HV"; ammo = "FA_o_580_Ball_HV_T_IR"; tracersEvery = 4; };
    class FA_rearma_150Rnd_580x42_DBP39_CT: 150Rnd_58x42_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 150Rnd 5.8mm DBP39 CT";
        displayNameShort = "DBP-39 CT";
        descriptionShort = "DBP-39 CT";
        ammo = "FA_o_580_DBP39_CT";
        initSpeed = 950;
        tracersEvery = 0;
    };
    class FA_rearma_150Rnd_580x42_DBP39_CT_T_Red: FA_rearma_150Rnd_580x42_DBP39_CT { displayName = "[JMSB] 150Rnd 5.8mm DBP39 CT - Red Tracer"; descriptionShort = "DBP-39 CT"; ammo = "FA_o_580_DBP39_CT_T_Red"; tracersEvery = 4; };
    class FA_rearma_150Rnd_580x42_DBP39_CT_T_Yellow: FA_rearma_150Rnd_580x42_DBP39_CT { displayName = "[JMSB] 150Rnd 5.8mm DBP39 CT - Yellow Tracer"; descriptionShort = "DBP-39 CT"; ammo = "FA_o_580_DBP39_CT_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_150Rnd_580x42_DBP39_CT_T_Green: FA_rearma_150Rnd_580x42_DBP39_CT { displayName = "[JMSB] 150Rnd 5.8mm DBP39 CT - Green Tracer"; descriptionShort = "DBP-39 CT"; ammo = "FA_o_580_DBP39_CT_T_Green"; tracersEvery = 4; };
    class FA_rearma_150Rnd_580x42_DBP39_CT_T_White: FA_rearma_150Rnd_580x42_DBP39_CT { displayName = "[JMSB] 150Rnd 5.8mm DBP39 CT - White Tracer"; descriptionShort = "DBP-39 CT"; ammo = "FA_o_580_DBP39_CT_T_White"; tracersEvery = 4; };
    class FA_rearma_150Rnd_580x42_DBP39_CT_T_Blue: FA_rearma_150Rnd_580x42_DBP39_CT { displayName = "[JMSB] 150Rnd 5.8mm DBP39 CT - Blue Tracer"; descriptionShort = "DBP-39 CT"; ammo = "FA_o_580_DBP39_CT_T_Blue"; tracersEvery = 4; };
    class FA_rearma_150Rnd_580x42_DBP39_CT_T_Orange: FA_rearma_150Rnd_580x42_DBP39_CT { displayName = "[JMSB] 150Rnd 5.8mm DBP39 CT - Orange Tracer"; descriptionShort = "DBP-39 CT"; ammo = "FA_o_580_DBP39_CT_T_Orange"; tracersEvery = 4; };
    class FA_rearma_150Rnd_580x42_DBP39_CT_T_IR: FA_rearma_150Rnd_580x42_DBP39_CT { displayName = "[JMSB] 150Rnd 5.8mm DBP39 CT - IR Tracer"; descriptionShort = "DBP-39 CT"; ammo = "FA_o_580_DBP39_CT_T_IR"; tracersEvery = 4; };
    class FA_rearma_150Rnd_580x42_DBJ39_PAB: 150Rnd_58x42_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 150Rnd 5.8mm DBJ39 PAB";
        displayNameShort = "DBJ-39 PAB";
        descriptionShort = "DBJ-39 PAB airburst, counter-UAS";
        ammo = "FA_o_580_DBJ39_PAB";
        initSpeed = 940;
        tracersEvery = 0;
    };
    class FA_rearma_150Rnd_580x42_DBJ39_PAB_T_Red: FA_rearma_150Rnd_580x42_DBJ39_PAB { displayName = "[JMSB] 150Rnd 5.8mm DBJ39 PAB - Red Tracer"; descriptionShort = "DBJ-39 PAB airburst, counter-UAS"; ammo = "FA_o_580_DBJ39_PAB_T_Red"; tracersEvery = 4; };
    class FA_rearma_150Rnd_580x42_DBJ39_PAB_T_Yellow: FA_rearma_150Rnd_580x42_DBJ39_PAB { displayName = "[JMSB] 150Rnd 5.8mm DBJ39 PAB - Yellow Tracer"; descriptionShort = "DBJ-39 PAB airburst, counter-UAS"; ammo = "FA_o_580_DBJ39_PAB_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_150Rnd_580x42_DBJ39_PAB_T_Green: FA_rearma_150Rnd_580x42_DBJ39_PAB { displayName = "[JMSB] 150Rnd 5.8mm DBJ39 PAB - Green Tracer"; descriptionShort = "DBJ-39 PAB airburst, counter-UAS"; ammo = "FA_o_580_DBJ39_PAB_T_Green"; tracersEvery = 4; };
    class FA_rearma_150Rnd_580x42_DBJ39_PAB_T_White: FA_rearma_150Rnd_580x42_DBJ39_PAB { displayName = "[JMSB] 150Rnd 5.8mm DBJ39 PAB - White Tracer"; descriptionShort = "DBJ-39 PAB airburst, counter-UAS"; ammo = "FA_o_580_DBJ39_PAB_T_White"; tracersEvery = 4; };
    class FA_rearma_150Rnd_580x42_DBJ39_PAB_T_Blue: FA_rearma_150Rnd_580x42_DBJ39_PAB { displayName = "[JMSB] 150Rnd 5.8mm DBJ39 PAB - Blue Tracer"; descriptionShort = "DBJ-39 PAB airburst, counter-UAS"; ammo = "FA_o_580_DBJ39_PAB_T_Blue"; tracersEvery = 4; };
    class FA_rearma_150Rnd_580x42_DBJ39_PAB_T_Orange: FA_rearma_150Rnd_580x42_DBJ39_PAB { displayName = "[JMSB] 150Rnd 5.8mm DBJ39 PAB - Orange Tracer"; descriptionShort = "DBJ-39 PAB airburst, counter-UAS"; ammo = "FA_o_580_DBJ39_PAB_T_Orange"; tracersEvery = 4; };
    class FA_rearma_150Rnd_580x42_DBJ39_PAB_T_IR: FA_rearma_150Rnd_580x42_DBJ39_PAB { displayName = "[JMSB] 150Rnd 5.8mm DBJ39 PAB - IR Tracer"; descriptionShort = "DBJ-39 PAB airburst, counter-UAS"; ammo = "FA_o_580_DBJ39_PAB_T_IR"; tracersEvery = 4; };

    // ===== 20Rnd 8.6x39 - QBW-201 - body 20Rnd_86x39_Mag_F =====
    class FA_rearma_20Rnd_86x39_DBP41: 20Rnd_86x39_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 20Rnd 8.6mm DBP41";
        displayNameShort = "DBP-41";
        descriptionShort = "DBP-41 - 8.6x39 supersonic";
        ammo = "FA_o_86x39_DBP41";
        initSpeed = 690;
    };
    class FA_rearma_20Rnd_86x39_DBP41_T_Red: FA_rearma_20Rnd_86x39_DBP41 { displayName = "[JMSB] 20Rnd 8.6mm DBP41 - Red Tracer"; descriptionShort = "DBP-41 - 8.6x39 supersonic"; ammo = "FA_o_86x39_DBP41_T_Red"; tracersEvery = 4; };
    class FA_rearma_20Rnd_86x39_DBP41_T_Yellow: FA_rearma_20Rnd_86x39_DBP41 { displayName = "[JMSB] 20Rnd 8.6mm DBP41 - Yellow Tracer"; descriptionShort = "DBP-41 - 8.6x39 supersonic"; ammo = "FA_o_86x39_DBP41_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_20Rnd_86x39_DBP41_T_Green: FA_rearma_20Rnd_86x39_DBP41 { displayName = "[JMSB] 20Rnd 8.6mm DBP41 - Green Tracer"; descriptionShort = "DBP-41 - 8.6x39 supersonic"; ammo = "FA_o_86x39_DBP41_T_Green"; tracersEvery = 4; };
    class FA_rearma_20Rnd_86x39_DBP41_T_White: FA_rearma_20Rnd_86x39_DBP41 { displayName = "[JMSB] 20Rnd 8.6mm DBP41 - White Tracer"; descriptionShort = "DBP-41 - 8.6x39 supersonic"; ammo = "FA_o_86x39_DBP41_T_White"; tracersEvery = 4; };
    class FA_rearma_20Rnd_86x39_DBP41_T_Blue: FA_rearma_20Rnd_86x39_DBP41 { displayName = "[JMSB] 20Rnd 8.6mm DBP41 - Blue Tracer"; descriptionShort = "DBP-41 - 8.6x39 supersonic"; ammo = "FA_o_86x39_DBP41_T_Blue"; tracersEvery = 4; };
    class FA_rearma_20Rnd_86x39_DBP41_T_Orange: FA_rearma_20Rnd_86x39_DBP41 { displayName = "[JMSB] 20Rnd 8.6mm DBP41 - Orange Tracer"; descriptionShort = "DBP-41 - 8.6x39 supersonic"; ammo = "FA_o_86x39_DBP41_T_Orange"; tracersEvery = 4; };
    class FA_rearma_20Rnd_86x39_DBP41_T_IR: FA_rearma_20Rnd_86x39_DBP41 { displayName = "[JMSB] 20Rnd 8.6mm DBP41 - IR Tracer"; descriptionShort = "DBP-41 - 8.6x39 supersonic"; ammo = "FA_o_86x39_DBP41_T_IR"; tracersEvery = 4; };
    class FA_rearma_20Rnd_86x39_DBP42_SubAP: 20Rnd_86x39_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 20Rnd 8.6mm DBP42 SubAP";
        displayNameShort = "DBP-42 SubAP";
        descriptionShort = "DBP-42 SubAP - 8.6x39 subsonic tungsten";
        ammo = "FA_o_86x39_DBP42_SubAP";
        initSpeed = 315;
    };
    class FA_rearma_20Rnd_86x39_DBP42_SubAP_T_Red: FA_rearma_20Rnd_86x39_DBP42_SubAP { displayName = "[JMSB] 20Rnd 8.6mm DBP42 SubAP - Red Tracer"; descriptionShort = "DBP-42 SubAP - 8.6x39 subsonic tungsten"; ammo = "FA_o_86x39_DBP42_SubAP_T_Red"; tracersEvery = 4; };
    class FA_rearma_20Rnd_86x39_DBP42_SubAP_T_Yellow: FA_rearma_20Rnd_86x39_DBP42_SubAP { displayName = "[JMSB] 20Rnd 8.6mm DBP42 SubAP - Yellow Tracer"; descriptionShort = "DBP-42 SubAP - 8.6x39 subsonic tungsten"; ammo = "FA_o_86x39_DBP42_SubAP_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_20Rnd_86x39_DBP42_SubAP_T_Green: FA_rearma_20Rnd_86x39_DBP42_SubAP { displayName = "[JMSB] 20Rnd 8.6mm DBP42 SubAP - Green Tracer"; descriptionShort = "DBP-42 SubAP - 8.6x39 subsonic tungsten"; ammo = "FA_o_86x39_DBP42_SubAP_T_Green"; tracersEvery = 4; };
    class FA_rearma_20Rnd_86x39_DBP42_SubAP_T_White: FA_rearma_20Rnd_86x39_DBP42_SubAP { displayName = "[JMSB] 20Rnd 8.6mm DBP42 SubAP - White Tracer"; descriptionShort = "DBP-42 SubAP - 8.6x39 subsonic tungsten"; ammo = "FA_o_86x39_DBP42_SubAP_T_White"; tracersEvery = 4; };
    class FA_rearma_20Rnd_86x39_DBP42_SubAP_T_Blue: FA_rearma_20Rnd_86x39_DBP42_SubAP { displayName = "[JMSB] 20Rnd 8.6mm DBP42 SubAP - Blue Tracer"; descriptionShort = "DBP-42 SubAP - 8.6x39 subsonic tungsten"; ammo = "FA_o_86x39_DBP42_SubAP_T_Blue"; tracersEvery = 4; };
    class FA_rearma_20Rnd_86x39_DBP42_SubAP_T_Orange: FA_rearma_20Rnd_86x39_DBP42_SubAP { displayName = "[JMSB] 20Rnd 8.6mm DBP42 SubAP - Orange Tracer"; descriptionShort = "DBP-42 SubAP - 8.6x39 subsonic tungsten"; ammo = "FA_o_86x39_DBP42_SubAP_T_Orange"; tracersEvery = 4; };
    class FA_rearma_20Rnd_86x39_DBP42_SubAP_T_IR: FA_rearma_20Rnd_86x39_DBP42_SubAP { displayName = "[JMSB] 20Rnd 8.6mm DBP42 SubAP - IR Tracer"; descriptionShort = "DBP-42 SubAP - 8.6x39 subsonic tungsten"; ammo = "FA_o_86x39_DBP42_SubAP_T_IR"; tracersEvery = 4; };
    class FA_rearma_20Rnd_86x39_DBJ41_PAB: 20Rnd_86x39_Mag_F {
        author = QAUTHOR;
        displayName = "[JMSB] 20Rnd 8.6mm DBJ41 PAB";
        displayNameShort = "DBJ-41 PAB";
        descriptionShort = "DBJ-41 PAB airburst, counter-UAS";
        ammo = "FA_o_86x39_DBJ41_PAB";
        initSpeed = 690;
    };
    class FA_rearma_20Rnd_86x39_DBJ41_PAB_T_Red: FA_rearma_20Rnd_86x39_DBJ41_PAB { displayName = "[JMSB] 20Rnd 8.6mm DBJ41 PAB - Red Tracer"; descriptionShort = "DBJ-41 PAB airburst, counter-UAS"; ammo = "FA_o_86x39_DBJ41_PAB_T_Red"; tracersEvery = 4; };
    class FA_rearma_20Rnd_86x39_DBJ41_PAB_T_Yellow: FA_rearma_20Rnd_86x39_DBJ41_PAB { displayName = "[JMSB] 20Rnd 8.6mm DBJ41 PAB - Yellow Tracer"; descriptionShort = "DBJ-41 PAB airburst, counter-UAS"; ammo = "FA_o_86x39_DBJ41_PAB_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_20Rnd_86x39_DBJ41_PAB_T_Green: FA_rearma_20Rnd_86x39_DBJ41_PAB { displayName = "[JMSB] 20Rnd 8.6mm DBJ41 PAB - Green Tracer"; descriptionShort = "DBJ-41 PAB airburst, counter-UAS"; ammo = "FA_o_86x39_DBJ41_PAB_T_Green"; tracersEvery = 4; };
    class FA_rearma_20Rnd_86x39_DBJ41_PAB_T_White: FA_rearma_20Rnd_86x39_DBJ41_PAB { displayName = "[JMSB] 20Rnd 8.6mm DBJ41 PAB - White Tracer"; descriptionShort = "DBJ-41 PAB airburst, counter-UAS"; ammo = "FA_o_86x39_DBJ41_PAB_T_White"; tracersEvery = 4; };
    class FA_rearma_20Rnd_86x39_DBJ41_PAB_T_Blue: FA_rearma_20Rnd_86x39_DBJ41_PAB { displayName = "[JMSB] 20Rnd 8.6mm DBJ41 PAB - Blue Tracer"; descriptionShort = "DBJ-41 PAB airburst, counter-UAS"; ammo = "FA_o_86x39_DBJ41_PAB_T_Blue"; tracersEvery = 4; };
    class FA_rearma_20Rnd_86x39_DBJ41_PAB_T_Orange: FA_rearma_20Rnd_86x39_DBJ41_PAB { displayName = "[JMSB] 20Rnd 8.6mm DBJ41 PAB - Orange Tracer"; descriptionShort = "DBJ-41 PAB airburst, counter-UAS"; ammo = "FA_o_86x39_DBJ41_PAB_T_Orange"; tracersEvery = 4; };
    class FA_rearma_20Rnd_86x39_DBJ41_PAB_T_IR: FA_rearma_20Rnd_86x39_DBJ41_PAB { displayName = "[JMSB] 20Rnd 8.6mm DBJ41 PAB - IR Tracer"; descriptionShort = "DBJ-41 PAB airburst, counter-UAS"; ammo = "FA_o_86x39_DBJ41_PAB_T_IR"; tracersEvery = 4; };

    // ===== 5Rnd .338 LM - QBU-202 - body 5Rnd_338_SN_Mag =====
    class FA_rearma_5Rnd_338_Mk371_250gr: 5Rnd_338_SN_Mag {
        author = QAUTHOR;
        displayName = "[JMSB] 5Rnd .338 Mk371 250gr";
        displayNameShort = "Mk371 250gr";
        descriptionShort = "Mk371 250gr";
        ammo = "FA_b_338_Mk371_250gr";
        initSpeed = 905;
    };
    class FA_rearma_5Rnd_338_Mk371_250gr_T_Red: FA_rearma_5Rnd_338_Mk371_250gr { displayName = "[JMSB] 5Rnd .338 Mk371 250gr - Red Tracer"; descriptionShort = "Mk371 250gr"; ammo = "FA_b_338_Mk371_250gr_T_Red"; tracersEvery = 4; };
    class FA_rearma_5Rnd_338_Mk371_250gr_T_Yellow: FA_rearma_5Rnd_338_Mk371_250gr { displayName = "[JMSB] 5Rnd .338 Mk371 250gr - Yellow Tracer"; descriptionShort = "Mk371 250gr"; ammo = "FA_b_338_Mk371_250gr_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_5Rnd_338_Mk371_250gr_T_Green: FA_rearma_5Rnd_338_Mk371_250gr { displayName = "[JMSB] 5Rnd .338 Mk371 250gr - Green Tracer"; descriptionShort = "Mk371 250gr"; ammo = "FA_b_338_Mk371_250gr_T_Green"; tracersEvery = 4; };
    class FA_rearma_5Rnd_338_Mk371_250gr_T_White: FA_rearma_5Rnd_338_Mk371_250gr { displayName = "[JMSB] 5Rnd .338 Mk371 250gr - White Tracer"; descriptionShort = "Mk371 250gr"; ammo = "FA_b_338_Mk371_250gr_T_White"; tracersEvery = 4; };
    class FA_rearma_5Rnd_338_Mk371_250gr_T_Blue: FA_rearma_5Rnd_338_Mk371_250gr { displayName = "[JMSB] 5Rnd .338 Mk371 250gr - Blue Tracer"; descriptionShort = "Mk371 250gr"; ammo = "FA_b_338_Mk371_250gr_T_Blue"; tracersEvery = 4; };
    class FA_rearma_5Rnd_338_Mk371_250gr_T_Orange: FA_rearma_5Rnd_338_Mk371_250gr { displayName = "[JMSB] 5Rnd .338 Mk371 250gr - Orange Tracer"; descriptionShort = "Mk371 250gr"; ammo = "FA_b_338_Mk371_250gr_T_Orange"; tracersEvery = 4; };
    class FA_rearma_5Rnd_338_Mk371_250gr_T_IR: FA_rearma_5Rnd_338_Mk371_250gr { displayName = "[JMSB] 5Rnd .338 Mk371 250gr - IR Tracer"; descriptionShort = "Mk371 250gr"; ammo = "FA_b_338_Mk371_250gr_T_IR"; tracersEvery = 4; };
    class FA_rearma_5Rnd_338_Mk371_285gr: 5Rnd_338_SN_Mag {
        author = QAUTHOR;
        displayName = "[JMSB] 5Rnd .338 Mk371 285gr";
        displayNameShort = "Mk371 285gr";
        descriptionShort = "Mk371 285gr";
        ammo = "FA_b_338_Mk371_285gr";
        initSpeed = 870;
    };
    class FA_rearma_5Rnd_338_Mk371_285gr_T_Red: FA_rearma_5Rnd_338_Mk371_285gr { displayName = "[JMSB] 5Rnd .338 Mk371 285gr - Red Tracer"; descriptionShort = "Mk371 285gr"; ammo = "FA_b_338_Mk371_285gr_T_Red"; tracersEvery = 4; };
    class FA_rearma_5Rnd_338_Mk371_285gr_T_Yellow: FA_rearma_5Rnd_338_Mk371_285gr { displayName = "[JMSB] 5Rnd .338 Mk371 285gr - Yellow Tracer"; descriptionShort = "Mk371 285gr"; ammo = "FA_b_338_Mk371_285gr_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_5Rnd_338_Mk371_285gr_T_Green: FA_rearma_5Rnd_338_Mk371_285gr { displayName = "[JMSB] 5Rnd .338 Mk371 285gr - Green Tracer"; descriptionShort = "Mk371 285gr"; ammo = "FA_b_338_Mk371_285gr_T_Green"; tracersEvery = 4; };
    class FA_rearma_5Rnd_338_Mk371_285gr_T_White: FA_rearma_5Rnd_338_Mk371_285gr { displayName = "[JMSB] 5Rnd .338 Mk371 285gr - White Tracer"; descriptionShort = "Mk371 285gr"; ammo = "FA_b_338_Mk371_285gr_T_White"; tracersEvery = 4; };
    class FA_rearma_5Rnd_338_Mk371_285gr_T_Blue: FA_rearma_5Rnd_338_Mk371_285gr { displayName = "[JMSB] 5Rnd .338 Mk371 285gr - Blue Tracer"; descriptionShort = "Mk371 285gr"; ammo = "FA_b_338_Mk371_285gr_T_Blue"; tracersEvery = 4; };
    class FA_rearma_5Rnd_338_Mk371_285gr_T_Orange: FA_rearma_5Rnd_338_Mk371_285gr { displayName = "[JMSB] 5Rnd .338 Mk371 285gr - Orange Tracer"; descriptionShort = "Mk371 285gr"; ammo = "FA_b_338_Mk371_285gr_T_Orange"; tracersEvery = 4; };
    class FA_rearma_5Rnd_338_Mk371_285gr_T_IR: FA_rearma_5Rnd_338_Mk371_285gr { displayName = "[JMSB] 5Rnd .338 Mk371 285gr - IR Tracer"; descriptionShort = "Mk371 285gr"; ammo = "FA_b_338_Mk371_285gr_T_IR"; tracersEvery = 4; };
    class FA_rearma_5Rnd_338_Mk371_300gr: 5Rnd_338_SN_Mag {
        author = QAUTHOR;
        displayName = "[JMSB] 5Rnd .338 Mk371 300gr";
        displayNameShort = "Mk371 300gr";
        descriptionShort = "Mk371 300gr";
        ammo = "FA_b_338_Mk371_300gr";
        initSpeed = 830;
    };
    class FA_rearma_5Rnd_338_Mk371_300gr_T_Red: FA_rearma_5Rnd_338_Mk371_300gr { displayName = "[JMSB] 5Rnd .338 Mk371 300gr - Red Tracer"; descriptionShort = "Mk371 300gr"; ammo = "FA_b_338_Mk371_300gr_T_Red"; tracersEvery = 4; };
    class FA_rearma_5Rnd_338_Mk371_300gr_T_Yellow: FA_rearma_5Rnd_338_Mk371_300gr { displayName = "[JMSB] 5Rnd .338 Mk371 300gr - Yellow Tracer"; descriptionShort = "Mk371 300gr"; ammo = "FA_b_338_Mk371_300gr_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_5Rnd_338_Mk371_300gr_T_Green: FA_rearma_5Rnd_338_Mk371_300gr { displayName = "[JMSB] 5Rnd .338 Mk371 300gr - Green Tracer"; descriptionShort = "Mk371 300gr"; ammo = "FA_b_338_Mk371_300gr_T_Green"; tracersEvery = 4; };
    class FA_rearma_5Rnd_338_Mk371_300gr_T_White: FA_rearma_5Rnd_338_Mk371_300gr { displayName = "[JMSB] 5Rnd .338 Mk371 300gr - White Tracer"; descriptionShort = "Mk371 300gr"; ammo = "FA_b_338_Mk371_300gr_T_White"; tracersEvery = 4; };
    class FA_rearma_5Rnd_338_Mk371_300gr_T_Blue: FA_rearma_5Rnd_338_Mk371_300gr { displayName = "[JMSB] 5Rnd .338 Mk371 300gr - Blue Tracer"; descriptionShort = "Mk371 300gr"; ammo = "FA_b_338_Mk371_300gr_T_Blue"; tracersEvery = 4; };
    class FA_rearma_5Rnd_338_Mk371_300gr_T_Orange: FA_rearma_5Rnd_338_Mk371_300gr { displayName = "[JMSB] 5Rnd .338 Mk371 300gr - Orange Tracer"; descriptionShort = "Mk371 300gr"; ammo = "FA_b_338_Mk371_300gr_T_Orange"; tracersEvery = 4; };
    class FA_rearma_5Rnd_338_Mk371_300gr_T_IR: FA_rearma_5Rnd_338_Mk371_300gr { displayName = "[JMSB] 5Rnd .338 Mk371 300gr - IR Tracer"; descriptionShort = "Mk371 300gr"; ammo = "FA_b_338_Mk371_300gr_T_IR"; tracersEvery = 4; };
    class FA_rearma_5Rnd_338_Mk373_PAB: 5Rnd_338_SN_Mag {
        author = QAUTHOR;
        displayName = "[JMSB] 5Rnd .338 Mk373 PAB";
        displayNameShort = "Mk373 PAB";
        descriptionShort = "Mk373 PAB airburst, counter-UAS";
        ammo = "FA_b_338_Mk373_PAB";
        initSpeed = 900;
    };
    class FA_rearma_5Rnd_338_Mk373_PAB_T_Red: FA_rearma_5Rnd_338_Mk373_PAB { displayName = "[JMSB] 5Rnd .338 Mk373 PAB - Red Tracer"; descriptionShort = "Mk373 PAB airburst, counter-UAS"; ammo = "FA_b_338_Mk373_PAB_T_Red"; tracersEvery = 4; };
    class FA_rearma_5Rnd_338_Mk373_PAB_T_Yellow: FA_rearma_5Rnd_338_Mk373_PAB { displayName = "[JMSB] 5Rnd .338 Mk373 PAB - Yellow Tracer"; descriptionShort = "Mk373 PAB airburst, counter-UAS"; ammo = "FA_b_338_Mk373_PAB_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_5Rnd_338_Mk373_PAB_T_Green: FA_rearma_5Rnd_338_Mk373_PAB { displayName = "[JMSB] 5Rnd .338 Mk373 PAB - Green Tracer"; descriptionShort = "Mk373 PAB airburst, counter-UAS"; ammo = "FA_b_338_Mk373_PAB_T_Green"; tracersEvery = 4; };
    class FA_rearma_5Rnd_338_Mk373_PAB_T_White: FA_rearma_5Rnd_338_Mk373_PAB { displayName = "[JMSB] 5Rnd .338 Mk373 PAB - White Tracer"; descriptionShort = "Mk373 PAB airburst, counter-UAS"; ammo = "FA_b_338_Mk373_PAB_T_White"; tracersEvery = 4; };
    class FA_rearma_5Rnd_338_Mk373_PAB_T_Blue: FA_rearma_5Rnd_338_Mk373_PAB { displayName = "[JMSB] 5Rnd .338 Mk373 PAB - Blue Tracer"; descriptionShort = "Mk373 PAB airburst, counter-UAS"; ammo = "FA_b_338_Mk373_PAB_T_Blue"; tracersEvery = 4; };
    class FA_rearma_5Rnd_338_Mk373_PAB_T_Orange: FA_rearma_5Rnd_338_Mk373_PAB { displayName = "[JMSB] 5Rnd .338 Mk373 PAB - Orange Tracer"; descriptionShort = "Mk373 PAB airburst, counter-UAS"; ammo = "FA_b_338_Mk373_PAB_T_Orange"; tracersEvery = 4; };

    // ===== 5Rnd 12.7x108 - QBU-201 - body 5Rnd_127x108_Mag =====
    class FA_rearma_5Rnd_127x108_DBJ127_PAB: 5Rnd_127x108_Mag {
        author = QAUTHOR;
        displayName = "[JMSB] 5Rnd 12.7x108mm DBJ127 PAB";
        displayNameShort = "DBJ-127 PAB";
        descriptionShort = "DBJ-127 PAB airburst, counter-UAS";
        ammo = "FA_o_127x108_DBJ127_PAB";
        initSpeed = 870;
    };
    class FA_rearma_5Rnd_127x108_DBJ127_PAB_T_Red: FA_rearma_5Rnd_127x108_DBJ127_PAB { displayName = "[JMSB] 5Rnd 12.7x108mm DBJ127 PAB - Red Tracer"; descriptionShort = "DBJ-127 PAB airburst, counter-UAS"; ammo = "FA_o_127x108_DBJ127_PAB_T_Red"; tracersEvery = 4; };
    class FA_rearma_5Rnd_127x108_DBJ127_PAB_T_Yellow: FA_rearma_5Rnd_127x108_DBJ127_PAB { displayName = "[JMSB] 5Rnd 12.7x108mm DBJ127 PAB - Yellow Tracer"; descriptionShort = "DBJ-127 PAB airburst, counter-UAS"; ammo = "FA_o_127x108_DBJ127_PAB_T_Yellow"; tracersEvery = 4; };
    class FA_rearma_5Rnd_127x108_DBJ127_PAB_T_Green: FA_rearma_5Rnd_127x108_DBJ127_PAB { displayName = "[JMSB] 5Rnd 12.7x108mm DBJ127 PAB - Green Tracer"; descriptionShort = "DBJ-127 PAB airburst, counter-UAS"; ammo = "FA_o_127x108_DBJ127_PAB_T_Green"; tracersEvery = 4; };
    class FA_rearma_5Rnd_127x108_DBJ127_PAB_T_White: FA_rearma_5Rnd_127x108_DBJ127_PAB { displayName = "[JMSB] 5Rnd 12.7x108mm DBJ127 PAB - White Tracer"; descriptionShort = "DBJ-127 PAB airburst, counter-UAS"; ammo = "FA_o_127x108_DBJ127_PAB_T_White"; tracersEvery = 4; };
    class FA_rearma_5Rnd_127x108_DBJ127_PAB_T_Blue: FA_rearma_5Rnd_127x108_DBJ127_PAB { displayName = "[JMSB] 5Rnd 12.7x108mm DBJ127 PAB - Blue Tracer"; descriptionShort = "DBJ-127 PAB airburst, counter-UAS"; ammo = "FA_o_127x108_DBJ127_PAB_T_Blue"; tracersEvery = 4; };
    class FA_rearma_5Rnd_127x108_DBJ127_PAB_T_Orange: FA_rearma_5Rnd_127x108_DBJ127_PAB { displayName = "[JMSB] 5Rnd 12.7x108mm DBJ127 PAB - Orange Tracer"; descriptionShort = "DBJ-127 PAB airburst, counter-UAS"; ammo = "FA_o_127x108_DBJ127_PAB_T_Orange"; tracersEvery = 4; };
    class FA_rearma_5Rnd_127x108_DBJ127_PAB_T_IR: FA_rearma_5Rnd_127x108_DBJ127_PAB { displayName = "[JMSB] 5Rnd 12.7x108mm DBJ127 PAB - IR Tracer"; descriptionShort = "DBJ-127 PAB airburst, counter-UAS"; ammo = "FA_o_127x108_DBJ127_PAB_T_IR"; tracersEvery = 4; };

    // ===== 30Rnd 9x21 - QCQ-171 (body data copied from 30Rnd_9x21_QCQ171_Mag) - parent CA_Magazine =====
    class FA_rearma_30Rnd_9x21_DBP43_AP: CA_Magazine {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        picture = "\A3\weapons_f\data\ui\M_30Rnd_9x21_CA.paa";
        count = 30;
        mass = 5;
        displayName = "[JMSB] 30Rnd 9x21mm DBP43 AP";
        displayNameShort = "DBP-43 AP";
        descriptionShort = "DBP-43 AP";
        ammo = "FA_o_9x21_DBP43_AP";
        initSpeed = 580;
    };
    class FA_rearma_30Rnd_9x21_DBP44_SUB: CA_Magazine {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        picture = "\A3\weapons_f\data\ui\M_30Rnd_9x21_CA.paa";
        count = 30;
        mass = 5;
        displayName = "[JMSB] 30Rnd 9x21mm DBP44 SUB";
        displayNameShort = "DBP-44 SUB";
        descriptionShort = "DBP-44 SUB";
        ammo = "FA_o_9x21_DBP44_SUB";
        initSpeed = 305;
    };

    // ===== 15Rnd 9x21 - QSZ-92A / QSZ-92B - body 15Rnd_9x21_Mag =====
    class FA_rearma_15Rnd_9x21_DBP43_AP: 15Rnd_9x21_Mag {
        author = QAUTHOR;
        displayName = "[JMSB] 15Rnd 9x21mm DBP43 AP";
        displayNameShort = "DBP-43 AP";
        descriptionShort = "DBP-43 AP";
        ammo = "FA_o_9x21_DBP43_AP";
        initSpeed = 470;
    };
    class FA_rearma_15Rnd_9x21_DBP44_SUB: 15Rnd_9x21_Mag {
        author = QAUTHOR;
        displayName = "[JMSB] 15Rnd 9x21mm DBP44 SUB";
        displayNameShort = "DBP-44 SUB";
        descriptionShort = "DBP-44 SUB";
        ammo = "FA_o_9x21_DBP44_SUB";
        initSpeed = 295;
    };

    // ===== 6Rnd 12 gauge shot - QBS-09 (body data copied from 6Rnd_W12Gauge_Pellets) - parent 2Rnd_12Gauge_Pellets =====
    class FA_rearma_6Rnd_12G_Mk350_TBS: 2Rnd_12Gauge_Pellets {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        picture = "\a3\Weapons_F_Enoch\MagazineProxies\data\UI\icon_6Rnd_12Gauge_Pellets_ca.paa";
        count = 6;
        mass = 6;
        displayName = "[JMSB] 6Rnd 12ga Mk350 TBS [Rearma]";
        displayNameShort = "Mk350 TBS";
        descriptionShort = "Tungsten buckshot - holds velocity, harder penetration";
        ammo = "FA_b_12G_Mk350_TBS";
        initSpeed = 400;
        tracersEvery = 0;
        lastRoundsTracer = 0;
    };
    class FA_rearma_6Rnd_12G_Mk351_FLE: 2Rnd_12Gauge_Pellets {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        picture = "\a3\Weapons_F_Enoch\MagazineProxies\data\UI\icon_6Rnd_12Gauge_Pellets_ca.paa";
        count = 6;
        mass = 6;
        displayName = "[JMSB] 6Rnd 12ga Mk351 FLE [Rearma]";
        displayNameShort = "Mk351 FLE";
        descriptionShort = "Tungsten flechette - tight pattern, cover penetration";
        ammo = "FA_b_12G_Mk351_FLE";
        initSpeed = 450;
        tracersEvery = 0;
        lastRoundsTracer = 0;
    };
    class FA_rearma_6Rnd_12G_Mk360_AD: 2Rnd_12Gauge_Pellets {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        picture = "\a3\Weapons_F_Enoch\MagazineProxies\data\UI\icon_6Rnd_12Gauge_Pellets_ca.paa";
        count = 6;
        mass = 6;
        displayName = "[JMSB] 6Rnd 12ga Mk360 AD [Rearma]";
        displayNameShort = "Mk360 AD";
        descriptionShort = "Anti-drone shot - dense tungsten pattern, ~40-50 m";
        ammo = "FA_b_12G_Mk360_AD";
        initSpeed = 410;
        tracersEvery = 0;
        lastRoundsTracer = 0;
    };

    // ===== 6Rnd 12 gauge slug - QBS-09 (body data copied from 6Rnd_W12Gauge_Slug) - parent 2Rnd_12Gauge_Slug =====
    class FA_rearma_6Rnd_12G_Mk352_APS: 2Rnd_12Gauge_Slug {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        picture = "\a3\Weapons_F_Enoch\MagazineProxies\data\UI\icon_6Rnd_12Gauge_Slug_ca.paa";
        count = 6;
        mass = 6;
        displayName = "[JMSB] 6Rnd 12ga Mk352 APS [Rearma]";
        displayNameShort = "Mk352 APS";
        descriptionShort = "Tungsten AP slug - light armor / hard cover defeat";
        ammo = "FA_b_12G_Mk352_APS";
        initSpeed = 450;
        tracersEvery = 0;
        lastRoundsTracer = 0;
    };
    class FA_rearma_6Rnd_12G_Mk353_BRC: 2Rnd_12Gauge_Slug {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        picture = "\a3\Weapons_F_Enoch\MagazineProxies\data\UI\icon_6Rnd_12Gauge_Slug_ca.paa";
        count = 6;
        mass = 6;
        displayName = "[JMSB] 6Rnd 12ga Mk353 BRC [Rearma]";
        displayNameShort = "Mk353 BRC";
        descriptionShort = "Frangible breaching round - defeats lock / hinge, minimal over-pen";
        ammo = "FA_b_12G_Mk353_BRC";
        initSpeed = 320;
        tracersEvery = 0;
        lastRoundsTracer = 0;
    };
    class FA_rearma_6Rnd_12G_Mk363_PABS: 2Rnd_12Gauge_Slug {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        picture = "\a3\Weapons_F_Enoch\MagazineProxies\data\UI\icon_6Rnd_12Gauge_Slug_ca.paa";
        count = 6;
        mass = 6;
        displayName = "[JMSB] 6Rnd 12ga Mk363 PABS [Rearma]";
        displayNameShort = "Mk363 PAB-S";
        descriptionShort = "Anti-drone proximity airburst slug";
        ammo = "FA_b_12G_Mk363_PABS";
        initSpeed = 430;
        tracersEvery = 0;
        lastRoundsTracer = 0;
    };

    // ===== 7Rnd 35mm - QLU-11 - body 7Rnd_HE_35mm =====
    class FA_rearma_7Rnd_35mm_DFK135_PAB: 7Rnd_HE_35mm {
        author = QAUTHOR;
        displayName = "[JMSB] 7Rnd 35mm DFK135 PAB";
        displayNameShort = "DFK-135 PAB";
        descriptionShort = "DFK-135 PAB - proximity + programmable airburst (Mk364 dial), HE on impact";
        ammo = "FA_o_35mm_DFK135_PAB";
        initSpeed = 450;
    };
    class FA_rearma_7Rnd_35mm_DFP135_HEP: 7Rnd_HE_35mm {
        author = QAUTHOR;
        displayName = "[JMSB] 7Rnd 35mm DFP135 HEP";
        displayNameShort = "DFP-135 HE-P";
        descriptionShort = "DFP-135 HE-P - programmable airburst HE (Mk364 dial)";
        ammo = "FA_o_35mm_DFP135_HEP";
        initSpeed = 450;
    };
    class FA_rearma_7Rnd_35mm_DFJ135_DP: 7Rnd_HE_35mm {
        author = QAUTHOR;
        displayName = "[JMSB] 7Rnd 35mm DFJ135 DP";
        displayNameShort = "DFJ-135 DP";
        descriptionShort = "DFJ-135 DP - dual-purpose HEAT + frag, ~40 mm RHA";
        ammo = "FA_o_35mm_DFJ135_DP";
        initSpeed = 450;
    };
    class FA_rearma_7Rnd_35mm_DFB135_TBK: 7Rnd_HE_35mm {
        author = QAUTHOR;
        displayName = "[JMSB] 7Rnd 35mm DFB135 TBK";
        displayNameShort = "DFB-135 TBK";
        descriptionShort = "DFB-135 TBK - tungsten buckshot, 12 pellets, eff. ~150 m";
        ammo = "FA_o_35mm_DFB135_TBK";
        initSpeed = 450;
    };
    class FA_rearma_7Rnd_35mm_DFZ130_NRP: 7Rnd_HE_35mm {
        author = QAUTHOR;
        displayName = "[JMSB] 7Rnd 35mm DFZ130 NRP";
        displayNameShort = "DFZ-130 NRP";
        descriptionShort = "DFZ-130 NRP - network relay, chute at apex";
        ammo = "FA_o_35mm_DFZ130_NRP";
        initSpeed = 450;
    };
    class FA_rearma_7Rnd_35mm_DFZ133_EMP: 7Rnd_HE_35mm {
        author = QAUTHOR;
        displayName = "[JMSB] 7Rnd 35mm DFZ133 EMP";
        displayNameShort = "DFZ-133 EMP";
        descriptionShort = "DFZ-133 EMP - soft-kill EW burst, chute at apex";
        ammo = "FA_o_35mm_DFZ133_EMP";
        initSpeed = 450;
    };
    class FA_rearma_7Rnd_35mm_DFZ134_MSmoke: 7Rnd_HE_35mm {
        author = QAUTHOR;
        displayName = "[JMSB] 7Rnd DFZ-134 MSmoke";
        displayNameShort = "DFZ-134 MSmoke";
        descriptionShort = "DFZ-134 MSmoke - multispectral smoke, chute at apex";
        ammo = "FA_o_35mm_DFZ134_MSmoke";
        initSpeed = 450;
    };
    class FA_rearma_7Rnd_35mm_DFZ135_Decoy: 7Rnd_HE_35mm {
        author = QAUTHOR;
        displayName = "[JMSB] 7Rnd 35mm DFZ135 Decoy";
        displayNameShort = "DFZ-135 Decoy";
        descriptionShort = "DFZ-135 Decoy - RF / IR drone decoy, chute at apex";
        ammo = "FA_o_35mm_DFZ135_Decoy";
        initSpeed = 450;
    };
    class FA_rearma_7Rnd_35mm_DFZ136_UGS: 7Rnd_HE_35mm {
        author = QAUTHOR;
        displayName = "[JMSB] 7Rnd 35mm DFZ136 UGS";
        displayNameShort = "DFZ-136 UGS";
        descriptionShort = "DFZ-136 UGS - ground sensor picket, chute at apex";
        ammo = "FA_o_35mm_DFZ136_UGS";
        initSpeed = 450;
    };
    class FA_rearma_7Rnd_35mm_DFZ138_Jammer: 7Rnd_HE_35mm {
        author = QAUTHOR;
        displayName = "[JMSB] 7Rnd 35mm DFZ138 Jammer";
        displayNameShort = "DFZ-138 Jammer";
        descriptionShort = "DFZ-138 Jammer - area comms / GNSS jammer, chute at apex";
        ammo = "FA_o_35mm_DFZ138_Jammer";
        initSpeed = 450;
    };

    // ===== 4Rnd mini-missiles - QN-205 - body QN205_HEAT =====
    class FA_rearma_4Rnd_QN205_TNDM: QN205_HEAT {
        author = QAUTHOR;
        displayName = "[JMSB] 4Rnd QN205 TNDM";
        displayNameShort = "QN-205T TNDM";
        descriptionShort = "QN-205T - tandem top-attack, ~450 mm RHA";
        ammo = "FA_M_QN205T_TNDM";
        initSpeed = 18;
    };
    class FA_rearma_4Rnd_QN205_TBX: QN205_HEAT {
        author = QAUTHOR;
        displayName = "[JMSB] 4Rnd QN205 TBX";
        displayNameShort = "QN-205B TBX";
        descriptionShort = "QN-205B - thermobaric + prefrag, programmable airburst (Mk364 dial)";
        ammo = "FA_M_QN205B_TBX";
        initSpeed = 18;
    };
    class FA_rearma_4Rnd_QN205_CUAS: QN205_HEAT {
        author = QAUTHOR;
        displayName = "[JMSB] 4Rnd QN205 CUAS";
        displayNameShort = "QN-205D C-UAS";
        descriptionShort = "QN-205D - IR lock vs drones and low air, proximity burst";
        ammo = "FA_M_QN205D_CUAS";
        initSpeed = 18;
    };

    // ===== PF-89A 80mm - FA disposable variants, body M_PF89_F =====
    class FA_rearma_PF89C_TNDM: M_PF89_F {
        author = QAUTHOR;
        scope = 1;
        displayName = "[JMSB] PF89C TNDM";
        descriptionShort = "80mm PF-89C TNDM (2040)<br/>Tandem HEAT - ~675 mm RHA, 300 m";
        ammo = "FA_R_PF89C_TNDM";
    };
    class FA_rearma_PF89K_PROX: M_PF89_F {
        author = QAUTHOR;
        scope = 1;
        displayName = "[JMSB] PF89K PROX";
        descriptionShort = "80mm PF-89K PROX (2040)<br/>C-UAS proximity airburst - scripted fuze, 250 m";
        ammo = "FA_R_PF89K_PROX";
    };

    // ===== WPF-89 80mm - FA disposable variants, body M_WPF89_F =====
    class FA_rearma_WPF89C_TBX: M_WPF89_F {
        author = QAUTHOR;
        scope = 1;
        displayName = "[JMSB] WPF89C TBX";
        descriptionShort = "80mm WPF-89C TBX (2040)<br/>Thermobaric, anti-structure / anti-personnel - 300 m";
        ammo = "FA_R_WPF89C_TBX";
    };
};
