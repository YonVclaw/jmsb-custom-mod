class CfgMagazines {
    class EF_100Rnd_65x39_caseless_coy_mag;
    class EF_30Rnd_65x39_caseless_coy_mag;

    // EF 6.5x39 coyote — ONE base mag; every tracer colour below inherits it,
    // so they all use the single coyote mag model (no separate _Tracer body).
    class FA_EF_30Rnd_65x39_caseless_coy_mag: EF_30Rnd_65x39_caseless_coy_mag {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 6.5mm - Coyote";
        descriptionShort = "Mk330 EPR";
        ammo = "FA_b_65_EPR";
        initSpeed = 950;
    };

    // =========================================================
    // EF 6.5x39 coyote — tracer colours (all inherit the coy_mag above)
    // =========================================================
    class FA_EF_30Rnd_65x39_caseless_coy_mag_Tracer_T_Red : FA_EF_30Rnd_65x39_caseless_coy_mag {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 6.5mm - Red Tracer, Coyote";
        descriptionShort = "Mk330 EPR";
        ammo = "FA_b_65_EPR_T_Red";
        initSpeed = 950;
    tracersEvery = 4; };
    class FA_EF_30Rnd_65x39_caseless_coy_mag_Tracer_T_Yellow : FA_EF_30Rnd_65x39_caseless_coy_mag {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 6.5mm - Yellow Tracer, Coyote";
        descriptionShort = "Mk330 EPR";
        ammo = "FA_b_65_EPR_T_Yellow";
        initSpeed = 950;
    tracersEvery = 4; };
    class FA_EF_30Rnd_65x39_caseless_coy_mag_Tracer_T_Green : FA_EF_30Rnd_65x39_caseless_coy_mag {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 6.5mm - Green Tracer, Coyote";
        descriptionShort = "Mk330 EPR";
        ammo = "FA_b_65_EPR_T_Green";
        initSpeed = 950;
    tracersEvery = 4; };
    class FA_EF_30Rnd_65x39_caseless_coy_mag_Tracer_T_White : FA_EF_30Rnd_65x39_caseless_coy_mag {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 6.5mm - White Tracer, Coyote";
        descriptionShort = "Mk330 EPR";
        ammo = "FA_b_65_EPR_T_White";
        initSpeed = 950;
    tracersEvery = 4; };
    class FA_EF_30Rnd_65x39_caseless_coy_mag_Tracer_T_Blue : FA_EF_30Rnd_65x39_caseless_coy_mag {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 6.5mm - Blue Tracer, Coyote";
        descriptionShort = "Mk330 EPR";
        ammo = "FA_b_65_EPR_T_Blue";
        initSpeed = 950;
    tracersEvery = 4; };
    class FA_EF_30Rnd_65x39_caseless_coy_mag_Tracer_T_Orange : FA_EF_30Rnd_65x39_caseless_coy_mag {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 6.5mm - Orange Tracer, Coyote";
        descriptionShort = "Mk330 EPR";
        ammo = "FA_b_65_EPR_T_Orange";
        initSpeed = 950;
    tracersEvery = 4; };
    class FA_EF_30Rnd_65x39_caseless_coy_mag_Tracer_T_IR : FA_EF_30Rnd_65x39_caseless_coy_mag {
        author = QAUTHOR;
        displayName = "[JMSB] 30Rnd 6.5mm - IR Tracer, Coyote";
        descriptionShort = "Mk330 EPR";
        ammo = "FA_b_65_EPR_T_IR";
        initSpeed = 950;
    tracersEvery = 4; };

    // =========================================================
    // EF 6.5x39 — EF_100Rnd_65x39_caseless_coy_mag
    // =========================================================
    class FA_EF_100Rnd_65x39_caseless_coy_mag_T_Red : EF_100Rnd_65x39_caseless_coy_mag {
        author = QAUTHOR;
        displayName = "[JMSB] 100Rnd 6.5mm [EF] - Red Tracer, Coyote";
        descriptionShort = "Mk330 EPR";
        ammo = "FA_b_65_EPR_T_Red";
        initSpeed = 950;
    tracersEvery = 4; };
    class FA_EF_100Rnd_65x39_caseless_coy_mag_T_Yellow : EF_100Rnd_65x39_caseless_coy_mag {
        author = QAUTHOR;
        displayName = "[JMSB] 100Rnd 6.5mm [EF] - Yellow Tracer, Coyote";
        descriptionShort = "Mk330 EPR";
        ammo = "FA_b_65_EPR_T_Yellow";
        initSpeed = 950;
    tracersEvery = 4; };
    class FA_EF_100Rnd_65x39_caseless_coy_mag_T_Green : EF_100Rnd_65x39_caseless_coy_mag {
        author = QAUTHOR;
        displayName = "[JMSB] 100Rnd 6.5mm [EF] - Green Tracer, Coyote";
        descriptionShort = "Mk330 EPR";
        ammo = "FA_b_65_EPR_T_Green";
        initSpeed = 950;
    tracersEvery = 4; };
    class FA_EF_100Rnd_65x39_caseless_coy_mag_T_White : EF_100Rnd_65x39_caseless_coy_mag {
        author = QAUTHOR;
        displayName = "[JMSB] 100Rnd 6.5mm [EF] - White Tracer, Coyote";
        descriptionShort = "Mk330 EPR";
        ammo = "FA_b_65_EPR_T_White";
        initSpeed = 950;
    tracersEvery = 4; };
    class FA_EF_100Rnd_65x39_caseless_coy_mag_T_Blue : EF_100Rnd_65x39_caseless_coy_mag {
        author = QAUTHOR;
        displayName = "[JMSB] 100Rnd 6.5mm [EF] - Blue Tracer, Coyote";
        descriptionShort = "Mk330 EPR";
        ammo = "FA_b_65_EPR_T_Blue";
        initSpeed = 950;
    tracersEvery = 4; };
    class FA_EF_100Rnd_65x39_caseless_coy_mag_T_Orange : EF_100Rnd_65x39_caseless_coy_mag {
        author = QAUTHOR;
        displayName = "[JMSB] 100Rnd 6.5mm [EF] - Orange Tracer, Coyote";
        descriptionShort = "Mk330 EPR";
        ammo = "FA_b_65_EPR_T_Orange";
        initSpeed = 950;
    tracersEvery = 4; };
    class FA_EF_100Rnd_65x39_caseless_coy_mag_T_IR : EF_100Rnd_65x39_caseless_coy_mag {
        author = QAUTHOR;
        displayName = "[JMSB] 100Rnd 6.5mm [EF] - IR Tracer, Coyote";
        descriptionShort = "Mk330 EPR";
        ammo = "FA_b_65_EPR_T_IR";
        initSpeed = 950;
    tracersEvery = 4; };

    // ===== EPR non-tracer coyote mag (100Rnd) =====
    class FA_EF_100Rnd_65x39_caseless_coy_mag: EF_100Rnd_65x39_caseless_coy_mag {
        author = QAUTHOR;
        displayName = "[JMSB] 100Rnd 6.5mm [EF] - Coyote";
        descriptionShort = "Mk330 EPR";
        ammo = "FA_b_65_EPR";
        initSpeed = 950;
    };
};
