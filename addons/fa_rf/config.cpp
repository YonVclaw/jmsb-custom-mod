#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "RF_Data_Loadorder",
            "ace_ballistics",
            "jmfsb_fa_main",
            "jmfsb_fa_ammo",            // the 12.7x55 and 9x19 Mk422 rounds
            "cba_main",
            // vanilla flare body (IR illum) + ammo_ShipCannon_120mm_* bases,
            // .50 / 40mm bullet+grenade bases for the ASh-12 / RC40 ammo
            "A3_Weapons_F",
            "A3_Weapons_F_Destroyer",
            // RC40 AD / HE-P airburst hook the antidrone proximity-fuze registry
            "jmfsb_fa_antidrone",
            // Reaction Forces 120mm Twin Mortar (weapon + magazine bodies).
            // skipWhenMissingDependencies self-skips this PBO without RF.

        };
        skipWhenMissingDependencies = 1;
        author = QAUTHOR;
        VERSION_CONFIG;
        ammo[] = {
            "FA_ammo_Penetrator_120_strix",
            "FA_120_heer", "FA_120_heer_O", "FA_120_heer_I",
            "FA_120_tb", "FA_120_tb_O", "FA_120_tb_I",
            "FA_120_strix", "FA_120_strix_O", "FA_120_strix_I",
            "FA_120_gps", "FA_120_gps_O", "FA_120_gps_I",
            "FA_120_lgm", "FA_120_lgm_O", "FA_120_lgm_I",
            "FA_120_smk", "FA_120_smk_O", "FA_120_smk_I",
            "FA_120_apmine", "FA_120_apmine_O", "FA_120_apmine_I",
            "FA_120_atmine", "FA_120_atmine_O", "FA_120_atmine_I",
            "FA_120_sfm", "FA_120_sfm_O", "FA_120_sfm_I",
            // ASh-12 12.7x55 + RC40 (magazines/wiring pending RF classnames)
            "FA_rf_ammo_127x55_7N52", "FA_rf_ammo_127x55_7U13", "FA_rf_ammo_127x55_7U14",
            "FA_ammo_RC40_HEP", "FA_ammo_RC40_MS", "FA_ammo_RC40_AD", "FA_ammo_RC40_DP"
        };
        magazines[] = {
            "FA_rf_20Rnd_127x55_7N52", "FA_rf_20Rnd_127x55_7U13", "FA_rf_20Rnd_127x55_7U14",
            "FA_rf_10Rnd_127x55_7N52", "FA_rf_10Rnd_127x55_7U13", "FA_rf_10Rnd_127x55_7U14",
            "FA_1Rnd_RC40_HEP", "FA_1Rnd_RC40_MS", "FA_1Rnd_RC40_AD", "FA_1Rnd_RC40_DP",
            "FA_6Rnd_120mm_heer_B", "FA_6Rnd_120mm_heer_O", "FA_6Rnd_120mm_heer_I",
            "FA_2Rnd_120mm_apmi_B", "FA_2Rnd_120mm_apmi_O", "FA_2Rnd_120mm_apmi_I",
            "FA_2Rnd_120mm_lgm_B", "FA_2Rnd_120mm_lgm_O", "FA_2Rnd_120mm_lgm_I",
            "FA_4Rnd_120mm_smk_B", "FA_4Rnd_120mm_smk_O", "FA_4Rnd_120mm_smk_I",
            "FA_2Rnd_120mm_apmine_B", "FA_2Rnd_120mm_apmine_O", "FA_2Rnd_120mm_apmine_I",
            "FA_4Rnd_120mm_atmine_B", "FA_4Rnd_120mm_atmine_O", "FA_4Rnd_120mm_atmine_I",
            "FA_2Rnd_120mm_sfm_B", "FA_2Rnd_120mm_sfm_O", "FA_2Rnd_120mm_sfm_I",
            "FA_2Rnd_120mm_strix_B", "FA_2Rnd_120mm_strix_O", "FA_2Rnd_120mm_strix_I",
            "FA_6Rnd_120mm_tb_B", "FA_6Rnd_120mm_tb_O", "FA_6Rnd_120mm_tb_I",
            "FA_8Rnd_120mm_ir_B"
        };
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgMagazinewells.hpp"
#include "CfgWeapons.hpp"
