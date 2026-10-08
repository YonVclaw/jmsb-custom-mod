class CfgMagazines {
    class 30Rnd_120mm_APFSDS_shells;
    class 30Rnd_120mm_HE_shells;
    class 24Rnd_125mm_APFSDS;
    class 12Rnd_125mm_HEAT;
    class 12Rnd_125mm_HE;
    class 4Rnd_125mm_cannon_missiles;

    // =========================================================
    // 105mm — 2040 light-tank / MGS family (20-round magazines)
    // =========================================================
    class FA_20Rnd_105mm_APFSDS: 30Rnd_120mm_APFSDS_shells {
        author = QAUTHOR;
        displayName = "[JMSB] 105mm XM1155 APFSDS-T";
        descriptionShort = "105mm XM1155 APFSDS-T (2040)<br/>Tungsten long-rod penetrator";
        ammo = "FA_Sh_105mm_APFSDS";
        count = 20;
        initSpeed = 1600;
    };
    // 105mm XM1155 APFSDS-T — tracer-color variants
    class FA_20Rnd_105mm_APFSDS_T_Red: FA_20Rnd_105mm_APFSDS { ammo = "FA_Sh_105mm_APFSDS_T_Red"; displayName = "[JMSB] 105mm XM1155 APFSDS-T (Red Tracer)"; tracersEvery = 1; };
    class FA_20Rnd_105mm_APFSDS_T_Yellow: FA_20Rnd_105mm_APFSDS { ammo = "FA_Sh_105mm_APFSDS_T_Yellow"; displayName = "[JMSB] 105mm XM1155 APFSDS-T (Yellow Tracer)"; tracersEvery = 1; };
    class FA_20Rnd_105mm_APFSDS_T_Green: FA_20Rnd_105mm_APFSDS { ammo = "FA_Sh_105mm_APFSDS_T_Green"; displayName = "[JMSB] 105mm XM1155 APFSDS-T (Green Tracer)"; tracersEvery = 1; };
    class FA_20Rnd_105mm_APFSDS_T_White: FA_20Rnd_105mm_APFSDS { ammo = "FA_Sh_105mm_APFSDS_T_White"; displayName = "[JMSB] 105mm XM1155 APFSDS-T (White Tracer)"; tracersEvery = 1; };
    class FA_20Rnd_105mm_APFSDS_T_Blue: FA_20Rnd_105mm_APFSDS { ammo = "FA_Sh_105mm_APFSDS_T_Blue"; displayName = "[JMSB] 105mm XM1155 APFSDS-T (Blue Tracer)"; tracersEvery = 1; };
    class FA_20Rnd_105mm_APFSDS_T_Orange: FA_20Rnd_105mm_APFSDS { ammo = "FA_Sh_105mm_APFSDS_T_Orange"; displayName = "[JMSB] 105mm XM1155 APFSDS-T (Orange Tracer)"; tracersEvery = 1; };
    class FA_20Rnd_105mm_APFSDS_T_IR: FA_20Rnd_105mm_APFSDS { ammo = "FA_Sh_105mm_APFSDS_T_IR"; displayName = "[JMSB] 105mm XM1155 APFSDS-T (IR Tracer)"; tracersEvery = 1; };

    class FA_20Rnd_105mm_HEATMP: 30Rnd_120mm_HE_shells {
        author = QAUTHOR;
        displayName = "[JMSB] 105mm XM1160 HEAT-MP-T";
        descriptionShort = "105mm XM1160 HEAT-MP-T (2040)<br/>Multipurpose, programmable airburst";
        ammo = "FA_Sh_105mm_HEATMP";
        count = 20;
        initSpeed = 1000;
    };
    // 105mm XM1160 HEAT-MP-T — tracer-color variants
    class FA_20Rnd_105mm_HEATMP_T_Red: FA_20Rnd_105mm_HEATMP { ammo = "FA_Sh_105mm_HEATMP_T_Red"; displayName = "[JMSB] 105mm XM1160 HEAT-MP-T (Red Tracer)"; tracersEvery = 1; };
    class FA_20Rnd_105mm_HEATMP_T_Yellow: FA_20Rnd_105mm_HEATMP { ammo = "FA_Sh_105mm_HEATMP_T_Yellow"; displayName = "[JMSB] 105mm XM1160 HEAT-MP-T (Yellow Tracer)"; tracersEvery = 1; };
    class FA_20Rnd_105mm_HEATMP_T_Green: FA_20Rnd_105mm_HEATMP { ammo = "FA_Sh_105mm_HEATMP_T_Green"; displayName = "[JMSB] 105mm XM1160 HEAT-MP-T (Green Tracer)"; tracersEvery = 1; };
    class FA_20Rnd_105mm_HEATMP_T_White: FA_20Rnd_105mm_HEATMP { ammo = "FA_Sh_105mm_HEATMP_T_White"; displayName = "[JMSB] 105mm XM1160 HEAT-MP-T (White Tracer)"; tracersEvery = 1; };
    class FA_20Rnd_105mm_HEATMP_T_Blue: FA_20Rnd_105mm_HEATMP { ammo = "FA_Sh_105mm_HEATMP_T_Blue"; displayName = "[JMSB] 105mm XM1160 HEAT-MP-T (Blue Tracer)"; tracersEvery = 1; };
    class FA_20Rnd_105mm_HEATMP_T_Orange: FA_20Rnd_105mm_HEATMP { ammo = "FA_Sh_105mm_HEATMP_T_Orange"; displayName = "[JMSB] 105mm XM1160 HEAT-MP-T (Orange Tracer)"; tracersEvery = 1; };
    class FA_20Rnd_105mm_HEATMP_T_IR: FA_20Rnd_105mm_HEATMP { ammo = "FA_Sh_105mm_HEATMP_T_IR"; displayName = "[JMSB] 105mm XM1160 HEAT-MP-T (IR Tracer)"; tracersEvery = 1; };

    class FA_20Rnd_105mm_HEOB: 30Rnd_120mm_HE_shells {
        author = QAUTHOR;
        displayName = "[JMSB] 105mm XM1162 HE-OB";
        descriptionShort = "105mm XM1162 HE-OB (2040)<br/>HE airburst — anti-personnel / structure";
        ammo = "FA_Sh_105mm_HEOB";
        count = 20;
        initSpeed = 1000;
    };
    // 105mm XM1162 HE-OB — tracer-color variants
    class FA_20Rnd_105mm_HEOB_T_Red: FA_20Rnd_105mm_HEOB { ammo = "FA_Sh_105mm_HEOB_T_Red"; displayName = "[JMSB] 105mm XM1162 HE-OB (Red Tracer)"; tracersEvery = 1; };
    class FA_20Rnd_105mm_HEOB_T_Yellow: FA_20Rnd_105mm_HEOB { ammo = "FA_Sh_105mm_HEOB_T_Yellow"; displayName = "[JMSB] 105mm XM1162 HE-OB (Yellow Tracer)"; tracersEvery = 1; };
    class FA_20Rnd_105mm_HEOB_T_Green: FA_20Rnd_105mm_HEOB { ammo = "FA_Sh_105mm_HEOB_T_Green"; displayName = "[JMSB] 105mm XM1162 HE-OB (Green Tracer)"; tracersEvery = 1; };
    class FA_20Rnd_105mm_HEOB_T_White: FA_20Rnd_105mm_HEOB { ammo = "FA_Sh_105mm_HEOB_T_White"; displayName = "[JMSB] 105mm XM1162 HE-OB (White Tracer)"; tracersEvery = 1; };
    class FA_20Rnd_105mm_HEOB_T_Blue: FA_20Rnd_105mm_HEOB { ammo = "FA_Sh_105mm_HEOB_T_Blue"; displayName = "[JMSB] 105mm XM1162 HE-OB (Blue Tracer)"; tracersEvery = 1; };
    class FA_20Rnd_105mm_HEOB_T_Orange: FA_20Rnd_105mm_HEOB { ammo = "FA_Sh_105mm_HEOB_T_Orange"; displayName = "[JMSB] 105mm XM1162 HE-OB (Orange Tracer)"; tracersEvery = 1; };
    class FA_20Rnd_105mm_HEOB_T_IR: FA_20Rnd_105mm_HEOB { ammo = "FA_Sh_105mm_HEOB_T_IR"; displayName = "[JMSB] 105mm XM1162 HE-OB (IR Tracer)"; tracersEvery = 1; };

    // =========================================================
    // 120mm APFSDS-T
    // =========================================================
    class FA_30Rnd_120mm_APFSDS: 30Rnd_120mm_APFSDS_shells {
        author = QAUTHOR;
        displayName = "[JMSB] 120mm APFSDS-T";
        descriptionShort = "120x570mm APFSDS-T (2033)<br/>Tungsten long-rod penetrator";
        ammo = "FA_Sh_120mm_APFSDS";
    };
    // Red-FACTION gradient (renamed from _T_Red so _T_ means tracer color only)
    class FA_30Rnd_120mm_APFSDS_Red: FA_30Rnd_120mm_APFSDS {
        displayName = "[JMSB] 120mm APFSDS-T (Red — OPFOR)";
        descriptionShort = "120x570mm APFSDS-T (2033)<br/>Tungsten long-rod penetrator — Red faction gradient";
        ammo = "FA_Sh_120mm_APFSDS_Red";
    };
    // 120mm APFSDS-T — tracer-color variants
    class FA_30Rnd_120mm_APFSDS_T_Red: FA_30Rnd_120mm_APFSDS { ammo = "FA_Sh_120mm_APFSDS_T_Red"; displayName = "[JMSB] 120mm APFSDS-T (Red Tracer)"; tracersEvery = 1; };
    class FA_30Rnd_120mm_APFSDS_T_Yellow: FA_30Rnd_120mm_APFSDS { ammo = "FA_Sh_120mm_APFSDS_T_Yellow"; displayName = "[JMSB] 120mm APFSDS-T (Yellow Tracer)"; tracersEvery = 1; };
    class FA_30Rnd_120mm_APFSDS_T_Green: FA_30Rnd_120mm_APFSDS { ammo = "FA_Sh_120mm_APFSDS_T_Green"; displayName = "[JMSB] 120mm APFSDS-T (Green Tracer)"; tracersEvery = 1; };
    class FA_30Rnd_120mm_APFSDS_T_White: FA_30Rnd_120mm_APFSDS { ammo = "FA_Sh_120mm_APFSDS_T_White"; displayName = "[JMSB] 120mm APFSDS-T (White Tracer)"; tracersEvery = 1; };
    class FA_30Rnd_120mm_APFSDS_T_Blue: FA_30Rnd_120mm_APFSDS { ammo = "FA_Sh_120mm_APFSDS_T_Blue"; displayName = "[JMSB] 120mm APFSDS-T (Blue Tracer)"; tracersEvery = 1; };
    class FA_30Rnd_120mm_APFSDS_T_Orange: FA_30Rnd_120mm_APFSDS { ammo = "FA_Sh_120mm_APFSDS_T_Orange"; displayName = "[JMSB] 120mm APFSDS-T (Orange Tracer)"; tracersEvery = 1; };
    class FA_30Rnd_120mm_APFSDS_T_IR: FA_30Rnd_120mm_APFSDS { ammo = "FA_Sh_120mm_APFSDS_T_IR"; displayName = "[JMSB] 120mm APFSDS-T (IR Tracer)"; tracersEvery = 1; };

    // =========================================================
    // 120mm AMP / HEAT-MP / HE-AB — same physical magazine body (30Rnd HE
    // shells parent; only the wrapped ammo differs, matching how every other
    // addon in this repo wraps magazines)
    // =========================================================
    class FA_30Rnd_120mm_AMP: 30Rnd_120mm_HE_shells {
        author = QAUTHOR;
        displayName = "[JMSB] 120mm AMP";
        descriptionShort = "120x570mm AMP (2033)<br/>Programmable multi-purpose — point-detonate, delay, airburst";
        ammo = "FA_Sh_120mm_AMP";
    };
    // 120mm AMP — tracer-color variants
    class FA_30Rnd_120mm_AMP_T_Red: FA_30Rnd_120mm_AMP { ammo = "FA_Sh_120mm_AMP_T_Red"; displayName = "[JMSB] 120mm AMP (Red Tracer)"; tracersEvery = 1; };
    class FA_30Rnd_120mm_AMP_T_Yellow: FA_30Rnd_120mm_AMP { ammo = "FA_Sh_120mm_AMP_T_Yellow"; displayName = "[JMSB] 120mm AMP (Yellow Tracer)"; tracersEvery = 1; };
    class FA_30Rnd_120mm_AMP_T_Green: FA_30Rnd_120mm_AMP { ammo = "FA_Sh_120mm_AMP_T_Green"; displayName = "[JMSB] 120mm AMP (Green Tracer)"; tracersEvery = 1; };
    class FA_30Rnd_120mm_AMP_T_White: FA_30Rnd_120mm_AMP { ammo = "FA_Sh_120mm_AMP_T_White"; displayName = "[JMSB] 120mm AMP (White Tracer)"; tracersEvery = 1; };
    class FA_30Rnd_120mm_AMP_T_Blue: FA_30Rnd_120mm_AMP { ammo = "FA_Sh_120mm_AMP_T_Blue"; displayName = "[JMSB] 120mm AMP (Blue Tracer)"; tracersEvery = 1; };
    class FA_30Rnd_120mm_AMP_T_Orange: FA_30Rnd_120mm_AMP { ammo = "FA_Sh_120mm_AMP_T_Orange"; displayName = "[JMSB] 120mm AMP (Orange Tracer)"; tracersEvery = 1; };
    class FA_30Rnd_120mm_AMP_T_IR: FA_30Rnd_120mm_AMP { ammo = "FA_Sh_120mm_AMP_T_IR"; displayName = "[JMSB] 120mm AMP (IR Tracer)"; tracersEvery = 1; };
    class FA_30Rnd_120mm_HEATMP: 30Rnd_120mm_HE_shells {
        author = QAUTHOR;
        displayName = "[JMSB] 120mm HEAT-MP";
        descriptionShort = "120x570mm HEAT-MP (2033)<br/>Multi-purpose, point-detonate/delay";
        ammo = "FA_Sh_120mm_HEATMP";
    };
    // 120mm HEAT-MP — tracer-color variants
    class FA_30Rnd_120mm_HEATMP_T_Red: FA_30Rnd_120mm_HEATMP { ammo = "FA_Sh_120mm_HEATMP_T_Red"; displayName = "[JMSB] 120mm HEAT-MP (Red Tracer)"; tracersEvery = 1; };
    class FA_30Rnd_120mm_HEATMP_T_Yellow: FA_30Rnd_120mm_HEATMP { ammo = "FA_Sh_120mm_HEATMP_T_Yellow"; displayName = "[JMSB] 120mm HEAT-MP (Yellow Tracer)"; tracersEvery = 1; };
    class FA_30Rnd_120mm_HEATMP_T_Green: FA_30Rnd_120mm_HEATMP { ammo = "FA_Sh_120mm_HEATMP_T_Green"; displayName = "[JMSB] 120mm HEAT-MP (Green Tracer)"; tracersEvery = 1; };
    class FA_30Rnd_120mm_HEATMP_T_White: FA_30Rnd_120mm_HEATMP { ammo = "FA_Sh_120mm_HEATMP_T_White"; displayName = "[JMSB] 120mm HEAT-MP (White Tracer)"; tracersEvery = 1; };
    class FA_30Rnd_120mm_HEATMP_T_Blue: FA_30Rnd_120mm_HEATMP { ammo = "FA_Sh_120mm_HEATMP_T_Blue"; displayName = "[JMSB] 120mm HEAT-MP (Blue Tracer)"; tracersEvery = 1; };
    class FA_30Rnd_120mm_HEATMP_T_Orange: FA_30Rnd_120mm_HEATMP { ammo = "FA_Sh_120mm_HEATMP_T_Orange"; displayName = "[JMSB] 120mm HEAT-MP (Orange Tracer)"; tracersEvery = 1; };
    class FA_30Rnd_120mm_HEATMP_T_IR: FA_30Rnd_120mm_HEATMP { ammo = "FA_Sh_120mm_HEATMP_T_IR"; displayName = "[JMSB] 120mm HEAT-MP (IR Tracer)"; tracersEvery = 1; };
    class FA_30Rnd_120mm_HEAB: 30Rnd_120mm_HE_shells {
        author = QAUTHOR;
        displayName = "[JMSB] 120mm HE-AB";
        descriptionShort = "120x570mm HE-AB (2036)<br/>Programmable airburst";
        ammo = "FA_Sh_120mm_HEAB";
    };
    // 120mm HE-AB — tracer-color variants
    class FA_30Rnd_120mm_HEAB_T_Red: FA_30Rnd_120mm_HEAB { ammo = "FA_Sh_120mm_HEAB_T_Red"; displayName = "[JMSB] 120mm HE-AB (Red Tracer)"; tracersEvery = 1; };
    class FA_30Rnd_120mm_HEAB_T_Yellow: FA_30Rnd_120mm_HEAB { ammo = "FA_Sh_120mm_HEAB_T_Yellow"; displayName = "[JMSB] 120mm HE-AB (Yellow Tracer)"; tracersEvery = 1; };
    class FA_30Rnd_120mm_HEAB_T_Green: FA_30Rnd_120mm_HEAB { ammo = "FA_Sh_120mm_HEAB_T_Green"; displayName = "[JMSB] 120mm HE-AB (Green Tracer)"; tracersEvery = 1; };
    class FA_30Rnd_120mm_HEAB_T_White: FA_30Rnd_120mm_HEAB { ammo = "FA_Sh_120mm_HEAB_T_White"; displayName = "[JMSB] 120mm HE-AB (White Tracer)"; tracersEvery = 1; };
    class FA_30Rnd_120mm_HEAB_T_Blue: FA_30Rnd_120mm_HEAB { ammo = "FA_Sh_120mm_HEAB_T_Blue"; displayName = "[JMSB] 120mm HE-AB (Blue Tracer)"; tracersEvery = 1; };
    class FA_30Rnd_120mm_HEAB_T_Orange: FA_30Rnd_120mm_HEAB { ammo = "FA_Sh_120mm_HEAB_T_Orange"; displayName = "[JMSB] 120mm HE-AB (Orange Tracer)"; tracersEvery = 1; };
    class FA_30Rnd_120mm_HEAB_T_IR: FA_30Rnd_120mm_HEAB { ammo = "FA_Sh_120mm_HEAB_T_IR"; displayName = "[JMSB] 120mm HE-AB (IR Tracer)"; tracersEvery = 1; };

    // =========================================================
    // 125mm 3BM APFSDS-T
    // =========================================================
    class FA_24Rnd_125mm_APFSDS: 24Rnd_125mm_APFSDS {
        author = QAUTHOR;
        displayName = "[JMSB] 125mm 3BM APFSDS-T";
        descriptionShort = "125x740mm APFSDS-T (2033)<br/>GRAU 3BM-class tungsten long-rod penetrator";
        ammo = "FA_Sh_125mm_APFSDS";
    };
    // 125mm 3BM APFSDS-T — tracer-color variants
    class FA_24Rnd_125mm_APFSDS_T_Red: FA_24Rnd_125mm_APFSDS { ammo = "FA_Sh_125mm_APFSDS_T_Red"; displayName = "[JMSB] 125mm 3BM APFSDS-T (Red Tracer)"; tracersEvery = 1; };
    class FA_24Rnd_125mm_APFSDS_T_Yellow: FA_24Rnd_125mm_APFSDS { ammo = "FA_Sh_125mm_APFSDS_T_Yellow"; displayName = "[JMSB] 125mm 3BM APFSDS-T (Yellow Tracer)"; tracersEvery = 1; };
    class FA_24Rnd_125mm_APFSDS_T_Green: FA_24Rnd_125mm_APFSDS { ammo = "FA_Sh_125mm_APFSDS_T_Green"; displayName = "[JMSB] 125mm 3BM APFSDS-T (Green Tracer)"; tracersEvery = 1; };
    class FA_24Rnd_125mm_APFSDS_T_White: FA_24Rnd_125mm_APFSDS { ammo = "FA_Sh_125mm_APFSDS_T_White"; displayName = "[JMSB] 125mm 3BM APFSDS-T (White Tracer)"; tracersEvery = 1; };
    class FA_24Rnd_125mm_APFSDS_T_Blue: FA_24Rnd_125mm_APFSDS { ammo = "FA_Sh_125mm_APFSDS_T_Blue"; displayName = "[JMSB] 125mm 3BM APFSDS-T (Blue Tracer)"; tracersEvery = 1; };
    class FA_24Rnd_125mm_APFSDS_T_Orange: FA_24Rnd_125mm_APFSDS { ammo = "FA_Sh_125mm_APFSDS_T_Orange"; displayName = "[JMSB] 125mm 3BM APFSDS-T (Orange Tracer)"; tracersEvery = 1; };
    class FA_24Rnd_125mm_APFSDS_T_IR: FA_24Rnd_125mm_APFSDS { ammo = "FA_Sh_125mm_APFSDS_T_IR"; displayName = "[JMSB] 125mm 3BM APFSDS-T (IR Tracer)"; tracersEvery = 1; };

    // =========================================================
    // 125mm Type AMP
    // =========================================================
    class FA_12Rnd_125mm_AMP: 12Rnd_125mm_HEAT {
        author = QAUTHOR;
        displayName = "[JMSB] 125mm Type AMP";
        descriptionShort = "125x740mm Type AMP (2036)<br/>Programmable multi-purpose airburst";
        ammo = "FA_Sh_125mm_AMP";
    };
    // 125mm Type AMP — tracer-color variants
    class FA_12Rnd_125mm_AMP_T_Red: FA_12Rnd_125mm_AMP { ammo = "FA_Sh_125mm_AMP_T_Red"; displayName = "[JMSB] 125mm Type AMP (Red Tracer)"; tracersEvery = 1; };
    class FA_12Rnd_125mm_AMP_T_Yellow: FA_12Rnd_125mm_AMP { ammo = "FA_Sh_125mm_AMP_T_Yellow"; displayName = "[JMSB] 125mm Type AMP (Yellow Tracer)"; tracersEvery = 1; };
    class FA_12Rnd_125mm_AMP_T_Green: FA_12Rnd_125mm_AMP { ammo = "FA_Sh_125mm_AMP_T_Green"; displayName = "[JMSB] 125mm Type AMP (Green Tracer)"; tracersEvery = 1; };
    class FA_12Rnd_125mm_AMP_T_White: FA_12Rnd_125mm_AMP { ammo = "FA_Sh_125mm_AMP_T_White"; displayName = "[JMSB] 125mm Type AMP (White Tracer)"; tracersEvery = 1; };
    class FA_12Rnd_125mm_AMP_T_Blue: FA_12Rnd_125mm_AMP { ammo = "FA_Sh_125mm_AMP_T_Blue"; displayName = "[JMSB] 125mm Type AMP (Blue Tracer)"; tracersEvery = 1; };
    class FA_12Rnd_125mm_AMP_T_Orange: FA_12Rnd_125mm_AMP { ammo = "FA_Sh_125mm_AMP_T_Orange"; displayName = "[JMSB] 125mm Type AMP (Orange Tracer)"; tracersEvery = 1; };
    class FA_12Rnd_125mm_AMP_T_IR: FA_12Rnd_125mm_AMP { ammo = "FA_Sh_125mm_AMP_T_IR"; displayName = "[JMSB] 125mm Type AMP (IR Tracer)"; tracersEvery = 1; };

    // CSAT 125mm East natures
    class FA_24Rnd_125mm_3BM70: 24Rnd_125mm_APFSDS { author = QAUTHOR; ammo = "FA_Sh_125mm_3BM70"; displayName = "[JMSB] 125mm 3BM70 Vacuum-2"; descriptionShort = "125mm APFSDS-T (2040)<br/>Tungsten long-rod, ~700mm@2km"; };
    class FA_12Rnd_125mm_3BK31: 12Rnd_125mm_HEAT { author = QAUTHOR; ammo = "FA_Sh_125mm_3BK31"; displayName = "[JMSB] 125mm 3BK-31 Breza"; descriptionShort = "125mm HEAT-MP (2040)<br/>Multi-purpose shaped charge, ~550mm"; };
    class FA_12Rnd_125mm_3OF82: 12Rnd_125mm_HE { author = QAUTHOR; ammo = "FA_Sh_125mm_3OF82"; displayName = "[JMSB] 125mm 3OF-82 HE-OB"; descriptionShort = "125mm HE-OB airburst (2040)<br/>Programmable airburst, ~22 m lethal"; };
    class FA_4Rnd_125mm_Refleks: 4Rnd_125mm_cannon_missiles { author = QAUTHOR; ammo = "FA_M_125mm_Refleks"; displayName = "[JMSB] 125mm 9M119M2 Refleks-M"; descriptionShort = "125mm gun-launched ATGM (2040)<br/>Laser beam-riding tandem HEAT, ~900mm, 5 km"; };
};
