#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "cba_main",
            "ace_ballistics",
            "jmfsb_fa_ammo",
            "EF_Weapons"
        };
        skipWhenMissingDependencies = 1;
        author = QAUTHOR;
        VERSION_CONFIG;
        magazines[] = {
            "FA_EF_30Rnd_65x39_caseless_coy_mag_Mk367_PAB",
            "FA_EF_30Rnd_65x39_caseless_coy_mag_Mk367_PAB_T_Red",
            "FA_EF_30Rnd_65x39_caseless_coy_mag_Mk367_PAB_T_Yellow",
            "FA_EF_30Rnd_65x39_caseless_coy_mag_Mk367_PAB_T_Green",
            "FA_EF_30Rnd_65x39_caseless_coy_mag_Mk367_PAB_T_White",
            "FA_EF_30Rnd_65x39_caseless_coy_mag_Mk367_PAB_T_Blue",
            "FA_EF_30Rnd_65x39_caseless_coy_mag_Mk367_PAB_T_Orange",
            "FA_EF_100Rnd_65x39_caseless_coy_mag_Mk367_PAB",
            "FA_EF_100Rnd_65x39_caseless_coy_mag_Mk367_PAB_T_Red",
            "FA_EF_100Rnd_65x39_caseless_coy_mag_Mk367_PAB_T_Yellow",
            "FA_EF_100Rnd_65x39_caseless_coy_mag_Mk367_PAB_T_Green",
            "FA_EF_100Rnd_65x39_caseless_coy_mag_Mk367_PAB_T_White",
            "FA_EF_100Rnd_65x39_caseless_coy_mag_Mk367_PAB_T_Blue",
            "FA_EF_100Rnd_65x39_caseless_coy_mag_Mk367_PAB_T_Orange"
        };
    };
};

#include "CfgMagazines.hpp"
#include "CfgMagazinewells.hpp"
