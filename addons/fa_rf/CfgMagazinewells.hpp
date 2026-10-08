// The RF ASh-12 reads the CBA CBA_127x55_ASh12 magazine well, so the FA 12.7x55
// magazines are injected there (they appear on every ASh-12 variant with no
// weapon patching).
class CfgMagazineWells {
    class CBA_127x55_ASh12 {
        ADDON[] += {
            "FA_rf_20Rnd_127x55_7N52",
            "FA_20Rnd_127x55_7N52",
            "FA_rf_20Rnd_127x55_7U13",
            "FA_20Rnd_127x55_7U13",
            "FA_rf_20Rnd_127x55_7U14",
            "FA_20Rnd_127x55_7U14",
            "FA_rf_10Rnd_127x55_7N52",
            "FA_10Rnd_127x55_7N52",
            "FA_rf_10Rnd_127x55_7U13",
            "FA_10Rnd_127x55_7U13",
            "FA_rf_10Rnd_127x55_7U14",
            "FA_10Rnd_127x55_7U14"
        };
    };

    // RC40 rides the standard CBA 40mm GL wells (same as RF's own RC40 shells),
    // so the rounds appear on the ASh-12 GL (and any 40mm GL using these wells).
    class CBA_40mm_3GL {
        ADDON[] += {
            "FA_1Rnd_RC40_HEP", "FA_1Rnd_RC40_MS", "FA_1Rnd_RC40_AD", "FA_1Rnd_RC40_DP"
        };
    };
    class CBA_40mm_M203 {
        ADDON[] += {
            "FA_1Rnd_RC40_HEP", "FA_1Rnd_RC40_MS", "FA_1Rnd_RC40_AD", "FA_1Rnd_RC40_DP"
        };
    };

    // FA 5.56 on the RF STANAG-AP bodies ride the standard 5.56 STANAG well,
    // so they appear on every STANAG rifle (same well the ammo addon feeds).
    class STANAG_556x45 {
        ADDON[] += {
            "FA_30Rnd_556x45_AP_Stanag_RF",
            "FA_30Rnd_556x45_AP_Stanag_RF_T_Red",
            "FA_30Rnd_556x45_AP_Stanag_RF_T_Yellow",
            "FA_30Rnd_556x45_AP_Stanag_RF_T_Green",
            "FA_30Rnd_556x45_AP_Stanag_RF_T_White",
            "FA_30Rnd_556x45_AP_Stanag_RF_T_Blue",
            "FA_30Rnd_556x45_AP_Stanag_RF_T_Orange",
            "FA_30Rnd_556x45_AP_Stanag_RF_T_IR",
            "FA_30Rnd_556x45_AP_Stanag_RF_Mk332_AP",
            "FA_30Rnd_556x45_AP_Stanag_RF_Mk332_AP_T_Red",
            "FA_30Rnd_556x45_AP_Stanag_RF_Mk332_AP_T_Yellow",
            "FA_30Rnd_556x45_AP_Stanag_RF_Mk332_AP_T_Green",
            "FA_30Rnd_556x45_AP_Stanag_RF_Mk332_AP_T_White",
            "FA_30Rnd_556x45_AP_Stanag_RF_Mk332_AP_T_Blue",
            "FA_30Rnd_556x45_AP_Stanag_RF_Mk332_AP_T_Orange",
            "FA_30Rnd_556x45_AP_Stanag_RF_Mk332_AP_T_IR",
            "FA_30Rnd_556x45_AP_Stanag_RF_XM891_CTEP",
            "FA_30Rnd_556x45_AP_Stanag_RF_XM891_CTEP_T_Red",
            "FA_30Rnd_556x45_AP_Stanag_RF_XM891_CTEP_T_Yellow",
            "FA_30Rnd_556x45_AP_Stanag_RF_XM891_CTEP_T_Green",
            "FA_30Rnd_556x45_AP_Stanag_RF_XM891_CTEP_T_White",
            "FA_30Rnd_556x45_AP_Stanag_RF_XM891_CTEP_T_Blue",
            "FA_30Rnd_556x45_AP_Stanag_RF_XM891_CTEP_T_Orange",
            "FA_30Rnd_556x45_AP_Stanag_RF_XM891_CTEP_T_IR",
            "FA_30Rnd_556x45_AP_Stanag_khk_RF",
            "FA_30Rnd_556x45_AP_Stanag_khk_RF_T_Red",
            "FA_30Rnd_556x45_AP_Stanag_khk_RF_T_Yellow",
            "FA_30Rnd_556x45_AP_Stanag_khk_RF_T_Green",
            "FA_30Rnd_556x45_AP_Stanag_khk_RF_T_White",
            "FA_30Rnd_556x45_AP_Stanag_khk_RF_T_Blue",
            "FA_30Rnd_556x45_AP_Stanag_khk_RF_T_Orange",
            "FA_30Rnd_556x45_AP_Stanag_khk_RF_T_IR",
            "FA_30Rnd_556x45_AP_Stanag_khk_RF_Mk332_AP",
            "FA_30Rnd_556x45_AP_Stanag_khk_RF_Mk332_AP_T_Red",
            "FA_30Rnd_556x45_AP_Stanag_khk_RF_Mk332_AP_T_Yellow",
            "FA_30Rnd_556x45_AP_Stanag_khk_RF_Mk332_AP_T_Green",
            "FA_30Rnd_556x45_AP_Stanag_khk_RF_Mk332_AP_T_White",
            "FA_30Rnd_556x45_AP_Stanag_khk_RF_Mk332_AP_T_Blue",
            "FA_30Rnd_556x45_AP_Stanag_khk_RF_Mk332_AP_T_Orange",
            "FA_30Rnd_556x45_AP_Stanag_khk_RF_Mk332_AP_T_IR",
            "FA_30Rnd_556x45_AP_Stanag_khk_RF_XM891_CTEP",
            "FA_30Rnd_556x45_AP_Stanag_khk_RF_XM891_CTEP_T_Red",
            "FA_30Rnd_556x45_AP_Stanag_khk_RF_XM891_CTEP_T_Yellow",
            "FA_30Rnd_556x45_AP_Stanag_khk_RF_XM891_CTEP_T_Green",
            "FA_30Rnd_556x45_AP_Stanag_khk_RF_XM891_CTEP_T_White",
            "FA_30Rnd_556x45_AP_Stanag_khk_RF_XM891_CTEP_T_Blue",
            "FA_30Rnd_556x45_AP_Stanag_khk_RF_XM891_CTEP_T_Orange",
            "FA_30Rnd_556x45_AP_Stanag_khk_RF_XM891_CTEP_T_IR",
            "FA_30Rnd_556x45_AP_Stanag_Tan_RF",
            "FA_30Rnd_556x45_AP_Stanag_Tan_RF_T_Red",
            "FA_30Rnd_556x45_AP_Stanag_Tan_RF_T_Yellow",
            "FA_30Rnd_556x45_AP_Stanag_Tan_RF_T_Green",
            "FA_30Rnd_556x45_AP_Stanag_Tan_RF_T_White",
            "FA_30Rnd_556x45_AP_Stanag_Tan_RF_T_Blue",
            "FA_30Rnd_556x45_AP_Stanag_Tan_RF_T_Orange",
            "FA_30Rnd_556x45_AP_Stanag_Tan_RF_T_IR",
            "FA_30Rnd_556x45_AP_Stanag_Tan_RF_Mk332_AP",
            "FA_30Rnd_556x45_AP_Stanag_Tan_RF_Mk332_AP_T_Red",
            "FA_30Rnd_556x45_AP_Stanag_Tan_RF_Mk332_AP_T_Yellow",
            "FA_30Rnd_556x45_AP_Stanag_Tan_RF_Mk332_AP_T_Green",
            "FA_30Rnd_556x45_AP_Stanag_Tan_RF_Mk332_AP_T_White",
            "FA_30Rnd_556x45_AP_Stanag_Tan_RF_Mk332_AP_T_Blue",
            "FA_30Rnd_556x45_AP_Stanag_Tan_RF_Mk332_AP_T_Orange",
            "FA_30Rnd_556x45_AP_Stanag_Tan_RF_Mk332_AP_T_IR",
            "FA_30Rnd_556x45_AP_Stanag_Tan_RF_XM891_CTEP",
            "FA_30Rnd_556x45_AP_Stanag_Tan_RF_XM891_CTEP_T_Red",
            "FA_30Rnd_556x45_AP_Stanag_Tan_RF_XM891_CTEP_T_Yellow",
            "FA_30Rnd_556x45_AP_Stanag_Tan_RF_XM891_CTEP_T_Green",
            "FA_30Rnd_556x45_AP_Stanag_Tan_RF_XM891_CTEP_T_White",
            "FA_30Rnd_556x45_AP_Stanag_Tan_RF_XM891_CTEP_T_Blue",
            "FA_30Rnd_556x45_AP_Stanag_Tan_RF_XM891_CTEP_T_Orange",
            "FA_30Rnd_556x45_AP_Stanag_Tan_RF_XM891_CTEP_T_IR"
        };
    };
    // The Glock 19X's own well. RF is encrypted, so the wells its pistols name are unknown; a well of ours, added to
    // hgun_Glock19_RF in CfgWeapons.hpp, reaches every Glock 19X variant (all descend from it - work/orbat dump).
    class jmfsb_fa_Glock19_RF {
        ADDON[] = {"FA_rf_17Rnd_9x19_Mk422_AP", "FA_rf_33Rnd_9x19_Mk422_AP"};
    };
};
