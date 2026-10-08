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
            "jmfsb_fa_mediumcaliber",    // 30mm natures
            "QAV_EF_AbramsX_Compat",    // load AFTER it so its HighROF redefine
                                        // doesn't wipe our appends
            "cba_main"
        };
        author = QAUTHOR;
        VERSION_CONFIG;
        skipWhenMissingDependencies = 1;
        ammo[] = {};
        magazines[] = {};
    };
};

#include "CfgWeapons.hpp"
