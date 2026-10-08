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
            "jmfsb_fa_ammo",
            "lot_aaf_m1014",
            "cba_main"
        };
        author = QAUTHOR;
        VERSION_CONFIG;
        skipWhenMissingDependencies = 1;
        ammo[] = {};
        magazines[] = {
            "FA_lot_6Rnd_12G_Mk350_TBS",
            "FA_lot_8Rnd_12G_Mk350_TBS",
            "FA_lot_6Rnd_12G_Mk351_FLE",
            "FA_lot_8Rnd_12G_Mk351_FLE",
            "FA_lot_6Rnd_12G_Mk352_APS",
            "FA_lot_8Rnd_12G_Mk352_APS",
            "FA_lot_6Rnd_12G_Mk353_BRC",
            "FA_lot_8Rnd_12G_Mk353_BRC",
            "FA_lot_6Rnd_12G_Mk360_AD",
            "FA_lot_8Rnd_12G_Mk360_AD",
            "FA_lot_6Rnd_12G_Mk363_PABS",
            "FA_lot_8Rnd_12G_Mk363_PABS"
        };
    };
};

#include "CfgMagazines.hpp"
#include "CfgMagazinewells.hpp"
