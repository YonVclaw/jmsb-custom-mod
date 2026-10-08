class CfgMagazines {
    class 60Rnd_30mm_APFSDS_shells;
    class 140Rnd_30mm_MP_shells;
    class 250Rnd_30mm_HE_shells;
    class 680Rnd_35mm_AA_shells;

    // =========================================================
    // 30mm APFSDS-T
    // =========================================================
    class FA_60Rnd_30mm_APFSDS: 60Rnd_30mm_APFSDS_shells {
        author = QAUTHOR;
        displayName = "[JMSB] 30mm APFSDS-T";
        descriptionShort = "30x173mm APFSDS-T (2033)<br/>Tungsten long-rod penetrator";
        ammo = "FA_B_30mm_APFSDS";
    };
    // Red-FACTION performance gradient (not a tracer color)
    class FA_60Rnd_30mm_APFSDS_Red: FA_60Rnd_30mm_APFSDS {
        displayName = "[JMSB] 30mm APFSDS-T (Red — OPFOR)";
        descriptionShort = "30x173mm APFSDS-T (2033)<br/>Tungsten long-rod penetrator — Red faction gradient";
        ammo = "FA_B_30mm_APFSDS_Red";
    };
    class FA_60Rnd_30mm_APFSDS_T_Red: FA_60Rnd_30mm_APFSDS { ammo = "FA_B_30mm_APFSDS_T_Red"; displayName = "[JMSB] 30mm APFSDS-T (Red Tracer)"; tracersEvery = 1; };
    class FA_60Rnd_30mm_APFSDS_T_Yellow: FA_60Rnd_30mm_APFSDS { ammo = "FA_B_30mm_APFSDS_T_Yellow"; displayName = "[JMSB] 30mm APFSDS-T (Yellow Tracer)"; tracersEvery = 1; };
    class FA_60Rnd_30mm_APFSDS_T_Green: FA_60Rnd_30mm_APFSDS { ammo = "FA_B_30mm_APFSDS_T_Green"; displayName = "[JMSB] 30mm APFSDS-T (Green Tracer)"; tracersEvery = 1; };
    class FA_60Rnd_30mm_APFSDS_T_White: FA_60Rnd_30mm_APFSDS { ammo = "FA_B_30mm_APFSDS_T_White"; displayName = "[JMSB] 30mm APFSDS-T (White Tracer)"; tracersEvery = 1; };
    class FA_60Rnd_30mm_APFSDS_T_Blue: FA_60Rnd_30mm_APFSDS { ammo = "FA_B_30mm_APFSDS_T_Blue"; displayName = "[JMSB] 30mm APFSDS-T (Blue Tracer)"; tracersEvery = 1; };
    class FA_60Rnd_30mm_APFSDS_T_Orange: FA_60Rnd_30mm_APFSDS { ammo = "FA_B_30mm_APFSDS_T_Orange"; displayName = "[JMSB] 30mm APFSDS-T (Orange Tracer)"; tracersEvery = 1; };
    class FA_60Rnd_30mm_APFSDS_T_IR: FA_60Rnd_30mm_APFSDS { ammo = "FA_B_30mm_APFSDS_T_IR"; displayName = "[JMSB] 30mm APFSDS-T (IR Tracer)"; tracersEvery = 1; };

    // =========================================================
    // 30mm API-T
    // =========================================================
    class FA_140Rnd_30mm_API: 140Rnd_30mm_MP_shells {
        author = QAUTHOR;
        displayName = "[JMSB] 30mm API-T";
        descriptionShort = "30x173mm API-T (2033)<br/>Armor-piercing incendiary, multi-purpose body";
        ammo = "FA_B_30mm_API";
    };
    class FA_140Rnd_30mm_API_T_Red: FA_140Rnd_30mm_API { ammo = "FA_B_30mm_API_T_Red"; displayName = "[JMSB] 30mm API-T (Red Tracer)"; tracersEvery = 1; };
    class FA_140Rnd_30mm_API_T_Yellow: FA_140Rnd_30mm_API { ammo = "FA_B_30mm_API_T_Yellow"; displayName = "[JMSB] 30mm API-T (Yellow Tracer)"; tracersEvery = 1; };
    class FA_140Rnd_30mm_API_T_Green: FA_140Rnd_30mm_API { ammo = "FA_B_30mm_API_T_Green"; displayName = "[JMSB] 30mm API-T (Green Tracer)"; tracersEvery = 1; };
    class FA_140Rnd_30mm_API_T_White: FA_140Rnd_30mm_API { ammo = "FA_B_30mm_API_T_White"; displayName = "[JMSB] 30mm API-T (White Tracer)"; tracersEvery = 1; };
    class FA_140Rnd_30mm_API_T_Blue: FA_140Rnd_30mm_API { ammo = "FA_B_30mm_API_T_Blue"; displayName = "[JMSB] 30mm API-T (Blue Tracer)"; tracersEvery = 1; };
    class FA_140Rnd_30mm_API_T_Orange: FA_140Rnd_30mm_API { ammo = "FA_B_30mm_API_T_Orange"; displayName = "[JMSB] 30mm API-T (Orange Tracer)"; tracersEvery = 1; };
    class FA_140Rnd_30mm_API_T_IR: FA_140Rnd_30mm_API { ammo = "FA_B_30mm_API_T_IR"; displayName = "[JMSB] 30mm API-T (IR Tracer)"; tracersEvery = 1; };

    // =========================================================
    // 30mm HE family — HEI-T / ABM / PROX
    // =========================================================
    class FA_250Rnd_30mm_HEI: 250Rnd_30mm_HE_shells {
        author = QAUTHOR;
        displayName = "[JMSB] 30mm HEI-T";
        descriptionShort = "30x173mm HEI-T (2033)<br/>High-explosive incendiary";
        ammo = "FA_B_30mm_HEI";
    };
    class FA_250Rnd_30mm_HEI_T_Red: FA_250Rnd_30mm_HEI { ammo = "FA_B_30mm_HEI_T_Red"; displayName = "[JMSB] 30mm HEI-T (Red Tracer)"; tracersEvery = 1; };
    class FA_250Rnd_30mm_HEI_T_Yellow: FA_250Rnd_30mm_HEI { ammo = "FA_B_30mm_HEI_T_Yellow"; displayName = "[JMSB] 30mm HEI-T (Yellow Tracer)"; tracersEvery = 1; };
    class FA_250Rnd_30mm_HEI_T_Green: FA_250Rnd_30mm_HEI { ammo = "FA_B_30mm_HEI_T_Green"; displayName = "[JMSB] 30mm HEI-T (Green Tracer)"; tracersEvery = 1; };
    class FA_250Rnd_30mm_HEI_T_White: FA_250Rnd_30mm_HEI { ammo = "FA_B_30mm_HEI_T_White"; displayName = "[JMSB] 30mm HEI-T (White Tracer)"; tracersEvery = 1; };
    class FA_250Rnd_30mm_HEI_T_Blue: FA_250Rnd_30mm_HEI { ammo = "FA_B_30mm_HEI_T_Blue"; displayName = "[JMSB] 30mm HEI-T (Blue Tracer)"; tracersEvery = 1; };
    class FA_250Rnd_30mm_HEI_T_Orange: FA_250Rnd_30mm_HEI { ammo = "FA_B_30mm_HEI_T_Orange"; displayName = "[JMSB] 30mm HEI-T (Orange Tracer)"; tracersEvery = 1; };
    class FA_250Rnd_30mm_HEI_T_IR: FA_250Rnd_30mm_HEI { ammo = "FA_B_30mm_HEI_T_IR"; displayName = "[JMSB] 30mm HEI-T (IR Tracer)"; tracersEvery = 1; };

    class FA_250Rnd_30mm_ABM: 250Rnd_30mm_HE_shells {
        author = QAUTHOR;
        displayName = "[JMSB] 30mm ABM";
        descriptionShort = "30x173mm ABM (2036)<br/>Programmable airburst — defilade defeat";
        ammo = "FA_B_30mm_ABM";
    };
    class FA_250Rnd_30mm_ABM_T_Red: FA_250Rnd_30mm_ABM { ammo = "FA_B_30mm_ABM_T_Red"; displayName = "[JMSB] 30mm ABM (Red Tracer)"; tracersEvery = 1; };
    class FA_250Rnd_30mm_ABM_T_Yellow: FA_250Rnd_30mm_ABM { ammo = "FA_B_30mm_ABM_T_Yellow"; displayName = "[JMSB] 30mm ABM (Yellow Tracer)"; tracersEvery = 1; };
    class FA_250Rnd_30mm_ABM_T_Green: FA_250Rnd_30mm_ABM { ammo = "FA_B_30mm_ABM_T_Green"; displayName = "[JMSB] 30mm ABM (Green Tracer)"; tracersEvery = 1; };
    class FA_250Rnd_30mm_ABM_T_White: FA_250Rnd_30mm_ABM { ammo = "FA_B_30mm_ABM_T_White"; displayName = "[JMSB] 30mm ABM (White Tracer)"; tracersEvery = 1; };
    class FA_250Rnd_30mm_ABM_T_Blue: FA_250Rnd_30mm_ABM { ammo = "FA_B_30mm_ABM_T_Blue"; displayName = "[JMSB] 30mm ABM (Blue Tracer)"; tracersEvery = 1; };
    class FA_250Rnd_30mm_ABM_T_Orange: FA_250Rnd_30mm_ABM { ammo = "FA_B_30mm_ABM_T_Orange"; displayName = "[JMSB] 30mm ABM (Orange Tracer)"; tracersEvery = 1; };
    class FA_250Rnd_30mm_ABM_T_IR: FA_250Rnd_30mm_ABM { ammo = "FA_B_30mm_ABM_T_IR"; displayName = "[JMSB] 30mm ABM (IR Tracer)"; tracersEvery = 1; };

    class FA_250Rnd_30mm_PROX: 250Rnd_30mm_HE_shells {
        author = QAUTHOR;
        displayName = "[JMSB] 30mm PROX";
        descriptionShort = "30x173mm PROX (2036)<br/>Counter-UAS proximity airburst";
        ammo = "FA_B_30mm_PROX";
    };
    class FA_250Rnd_30mm_PROX_T_Red: FA_250Rnd_30mm_PROX { ammo = "FA_B_30mm_PROX_T_Red"; displayName = "[JMSB] 30mm PROX (Red Tracer)"; tracersEvery = 1; };
    class FA_250Rnd_30mm_PROX_T_Yellow: FA_250Rnd_30mm_PROX { ammo = "FA_B_30mm_PROX_T_Yellow"; displayName = "[JMSB] 30mm PROX (Yellow Tracer)"; tracersEvery = 1; };
    class FA_250Rnd_30mm_PROX_T_Green: FA_250Rnd_30mm_PROX { ammo = "FA_B_30mm_PROX_T_Green"; displayName = "[JMSB] 30mm PROX (Green Tracer)"; tracersEvery = 1; };
    class FA_250Rnd_30mm_PROX_T_White: FA_250Rnd_30mm_PROX { ammo = "FA_B_30mm_PROX_T_White"; displayName = "[JMSB] 30mm PROX (White Tracer)"; tracersEvery = 1; };
    class FA_250Rnd_30mm_PROX_T_Blue: FA_250Rnd_30mm_PROX { ammo = "FA_B_30mm_PROX_T_Blue"; displayName = "[JMSB] 30mm PROX (Blue Tracer)"; tracersEvery = 1; };
    class FA_250Rnd_30mm_PROX_T_Orange: FA_250Rnd_30mm_PROX { ammo = "FA_B_30mm_PROX_T_Orange"; displayName = "[JMSB] 30mm PROX (Orange Tracer)"; tracersEvery = 1; };
    class FA_250Rnd_30mm_PROX_T_IR: FA_250Rnd_30mm_PROX { ammo = "FA_B_30mm_PROX_T_IR"; displayName = "[JMSB] 30mm PROX (IR Tracer)"; tracersEvery = 1; };

    // =========================================================
    // 35mm AHEAD
    // =========================================================
    class FA_680Rnd_35mm_AHEAD: 680Rnd_35mm_AA_shells {
        author = QAUTHOR;
        displayName = "[JMSB] 35mm AHEAD";
        descriptionShort = "35x228mm AHEAD (2033)<br/>Timed tungsten sub-projectile airburst";
        ammo = "FA_B_35mm_AHEAD";
    };
    class FA_680Rnd_35mm_AHEAD_T_Red: FA_680Rnd_35mm_AHEAD { ammo = "FA_B_35mm_AHEAD_T_Red"; displayName = "[JMSB] 35mm AHEAD (Red Tracer)"; tracersEvery = 1; };
    class FA_680Rnd_35mm_AHEAD_T_Yellow: FA_680Rnd_35mm_AHEAD { ammo = "FA_B_35mm_AHEAD_T_Yellow"; displayName = "[JMSB] 35mm AHEAD (Yellow Tracer)"; tracersEvery = 1; };
    class FA_680Rnd_35mm_AHEAD_T_Green: FA_680Rnd_35mm_AHEAD { ammo = "FA_B_35mm_AHEAD_T_Green"; displayName = "[JMSB] 35mm AHEAD (Green Tracer)"; tracersEvery = 1; };
    class FA_680Rnd_35mm_AHEAD_T_White: FA_680Rnd_35mm_AHEAD { ammo = "FA_B_35mm_AHEAD_T_White"; displayName = "[JMSB] 35mm AHEAD (White Tracer)"; tracersEvery = 1; };
    class FA_680Rnd_35mm_AHEAD_T_Blue: FA_680Rnd_35mm_AHEAD { ammo = "FA_B_35mm_AHEAD_T_Blue"; displayName = "[JMSB] 35mm AHEAD (Blue Tracer)"; tracersEvery = 1; };
    class FA_680Rnd_35mm_AHEAD_T_Orange: FA_680Rnd_35mm_AHEAD { ammo = "FA_B_35mm_AHEAD_T_Orange"; displayName = "[JMSB] 35mm AHEAD (Orange Tracer)"; tracersEvery = 1; };
    class FA_680Rnd_35mm_AHEAD_T_IR: FA_680Rnd_35mm_AHEAD { ammo = "FA_B_35mm_AHEAD_T_IR"; displayName = "[JMSB] 35mm AHEAD (IR Tracer)"; tracersEvery = 1; };

    // =========================================================
    // 50mm — DORMANT (no confirmed 50mm platform in this modset; documented
    // flagship rounds, not wired to any weapon — no tracer sets until a
    // platform exists)
    // =========================================================
    class FA_60Rnd_50mm_HEAB: 250Rnd_30mm_HE_shells {
        author = QAUTHOR;
        displayName = "[JMSB] 50mm HEAB (Flagship — dormant)";
        descriptionShort = "50x228mm HEAB (2039)<br/>XM913-class airburst; no confirmed 50mm platform in this modset";
        ammo = "FA_B_50mm_HEAB";
        count = 60;
    };
    class FA_60Rnd_50mm_APFSDS: 60Rnd_30mm_APFSDS_shells {
        author = QAUTHOR;
        displayName = "[JMSB] 50mm APFSDS-T (Flagship — dormant)";
        descriptionShort = "50x228mm APFSDS-T (2039)<br/>XM913-class kinetic; no confirmed 50mm platform in this modset";
        ammo = "FA_B_50mm_APFSDS";
        count = 60;
    };
};
