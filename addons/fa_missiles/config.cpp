#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "ace_ballistics",
            "jmfsb_fa_main",
            "cba_main",
            // Hydra-P C-UAS mode registers into the mediumcaliber airburst
            // registry (its postInit must create the hashmap first)
            "jmfsb_fa_mediumcaliber"
        };
        author = QAUTHOR;
        VERSION_CONFIG;
        ammo[] = {
            "FA_M_BGM185_Broadsword",
            "FA_M_AGM190_Wraith",
            "FA_M_AGM205_Warhammer",
            "FA_M_MIM165_Sentry",
            "FA_M_AGR40_HydraP",
            "FA_M_XM1200_Copperhead",
            "FA_M_MIM166_Roadrunner",
            "FA_ammo_Penetrator_BGM185",
            "FA_ammo_Penetrator_AGM190",
            "FA_ammo_Penetrator_AGR40",
            "FA_ammo_Penetrator_XM1200",
            // fixed-wing aircraft missiles — AA per-side, strike shared
            "FA_M_AIM9X3", "FA_M_R74M", "FA_M_IRIST",
            "FA_M_AIM120E", "FA_M_R77M", "FA_M_MICANG",
            "FA_M_AIM260", "FA_M_R37M", "FA_M_Meteor",
            "FA_M_sead", "FA_M_cruise", "FA_M_antiship"
        };
        magazines[] = {
            "FA_2Rnd_BGM185_Broadsword",
            "FA_4Rnd_BGM185_Broadsword",
            "FA_8Rnd_AGM190_Wraith",
            "FA_PylonRack_1Rnd_AGM190_Wraith",
            "FA_PylonRack_3Rnd_AGM190_Wraith",
            "FA_2Rnd_AGM205_Warhammer",
            "FA_PylonMissile_1Rnd_AGM205_Warhammer",
            "FA_4Rnd_MIM165_Sentry",
            "FA_12Rnd_AGR40_HydraP",
            "FA_24Rnd_AGR40_HydraP",
            "FA_PylonRack_12Rnd_AGR40_HydraP",
            "FA_2Rnd_XM1200_Copperhead",
            "FA_4Rnd_MIM166_Roadrunner",
            "FA_1Rnd_BGM185_Broadsword",
            "FA_1Rnd_XM1200_Copperhead",
            "FA_1Rnd_MIM165_Sentry",
            "FA_1Rnd_MIM166_Roadrunner",
            // man-portable Titan MPRL rounds
            "FA_Titan_AT_BGM185_Broadsword",
            "FA_Titan_AT_XM1200_Copperhead",
            "FA_Titan_AA_MIM165_Sentry",
            "FA_Titan_AA_MIM166_Roadrunner",
            // fixed-wing aircraft missile pylons (tri-side)
            "FA_Pylon_1Rnd_aair_B", "FA_Pylon_1Rnd_aair_O", "FA_Pylon_1Rnd_aair_I",
            "FA_Pylon_1Rnd_aamed_B", "FA_Pylon_1Rnd_aamed_O", "FA_Pylon_1Rnd_aamed_I",
            "FA_Pylon_1Rnd_aalong_B", "FA_Pylon_1Rnd_aalong_O", "FA_Pylon_1Rnd_aalong_I",
            "FA_Pylon_1Rnd_sead_B", "FA_Pylon_1Rnd_sead_O", "FA_Pylon_1Rnd_sead_I",
            "FA_Pylon_1Rnd_cruise_B", "FA_Pylon_1Rnd_cruise_O", "FA_Pylon_1Rnd_cruise_I",
            "FA_Pylon_1Rnd_antiship_B", "FA_Pylon_1Rnd_antiship_O", "FA_Pylon_1Rnd_antiship_I"
        };
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgWeapons.hpp"
#include "CfgMagazinewells.hpp"
