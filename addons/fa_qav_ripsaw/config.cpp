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
            "jmfsb_fa_ammo",           // .50 + 7.62 vehicle belts
            "jmfsb_fa_mediumcaliber",  // 30mm natures
            "QAV_Ripsaw",             // target vehicle weapons
            "cba_main"
        };
        author = QAUTHOR;
        VERSION_CONFIG;
        skipWhenMissingDependencies = 1;
        // Pure wiring compat: appends existing FA magazines onto the QAV Ripsaw
        // weapons. Defines no new magazines/ammo of its own.
        ammo[] = {};
        magazines[] = {};
    };
};

#include "CfgWeapons.hpp"
