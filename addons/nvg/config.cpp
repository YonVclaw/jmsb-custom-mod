#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "jmfsb_common",
            "cba_main",
            "ace_nightvision",
            // The four LP NVGs inherit EF's own sets - see CfgWeapons.hpp. With
            // that mod absent this addon skips rather than erroring, which is
            // what skipWhenMissingDependencies is for and why it must stay.
            "A3_EFA_characters_f"
        };
        skipWhenMissingDependencies = 1;
        author = QAUTHOR;
        authors[] = {"YONV"};
        VERSION_CONFIG;
    };
};


#include "CfgEventHandlers.hpp"
#include "CfgEffects.hpp"
#include "CfgWeapons.hpp"
#include "XtdGear.hpp"
