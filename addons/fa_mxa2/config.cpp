#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "jmfsb_fa_main",
            "weapons_MXA2_f"            // Frogtop's MXA2 (workshop: Alternative MX - MXA2)
        };
        author = QAUTHOR;
        VERSION_CONFIG;
        skipWhenMissingDependencies = 1;
        // Pure compat: gives the MXA2's two barrels ACE's barrel figures, so the FA 6.5 mm
        // muzzle-velocity tables read the right length. Defines no weapons of its own.
        ammo[] = {};
        magazines[] = {};
    };
};

#include "CfgWeapons.hpp"
