#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            QGVAR(Item_optic_Nightstalker),
            QGVAR(Item_optic_AMS),
            QGVAR(Item_optic_AMS_khk),
            QGVAR(Item_optic_AMS_snd),
            QGVAR(Item_optic_AMSTI),
            QGVAR(Item_optic_AMSTI_khk),
            QGVAR(Item_optic_AMSTI_snd)
        };
        weapons[] = {
            QGVAR(xm157_prototype),
            QGVAR(optic_Nightstalker),
            QGVAR(optic_AMS),
            QGVAR(optic_AMS_khk),
            QGVAR(optic_AMS_snd),
            QGVAR(optic_AMSTI),
            QGVAR(optic_AMSTI_khk),
            QGVAR(optic_AMSTI_snd),
            QGVAR(optic_DMS)
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "jmfsb_main",
            "A3_Weapons_F",
            "A3_Weapons_F_Mark",
            "ace_xm157",
            "cba_jr"
        };
        skipWhenMissingDependencies = 1;
        authorUrl = "https://github.com/Joint-Multi-Functional-Strike-Battalion/";
        author = QAUTHOR;
        authors[] = {"YonV"};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
#include "jr_classes.hpp"
