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
            "jmfsb_fa_ammo",           // .50 / .338 / 7.62 vehicle belts
            "jmfsb_fa_mediumcaliber",  // 30mm natures
            "jmfsb_fa_maincaliber",    // 120mm natures
            "QAV_AbramsX",            // target vehicle weapons
            "cba_main"
        };
        author = QAUTHOR;
        VERSION_CONFIG;
        skipWhenMissingDependencies = 1;
        // Pure wiring compat: appends existing FA magazines onto QAV AbramsX
        // weapons. Defines no new magazines/ammo of its own.
        ammo[] = {};
        magazines[] = {};
    };
};

#include "CfgWeapons.hpp"
