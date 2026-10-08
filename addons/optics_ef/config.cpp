#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {
            QGVAR(optic_mbs_remote_157),
            QGVAR(optic_mbs_remote_157_coy),
            QGVAR(optic_mbs_remote_157_khk),
            QGVAR(optic_mbs_remote_157_sand),
            QGVAR(optic_mbs_157),
            QGVAR(optic_mbs_157_coy),
            QGVAR(optic_mbs_157_khk),
            QGVAR(optic_mbs_157_sand)
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "jmfsb_main",
            "ace_xm157",
            "A3_EFA_characters_f",
            "cba_jr"
        };
        skipWhenMissingDependencies = 1;
        authorUrl = "https://github.com/Joint-Multi-Functional-Strike-Battalion/";
        author = QAUTHOR;
        authors[] = {""};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgWeapons.hpp"
#include "jr_classes.hpp"
