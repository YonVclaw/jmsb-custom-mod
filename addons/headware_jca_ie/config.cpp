#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {
            QGVAR(JCA_H_HelmetHBK_black_F),
            QGVAR(JCA_H_HelmetHBK_chops_black_F),
            QGVAR(JCA_H_HelmetHBK_ear_black_F),
            QGVAR(JCA_H_HelmetHBK_headset_black_F),
            QGVAR(JCA_H_HelmetHBK_olive_F),
            QGVAR(JCA_H_HelmetHBK_chops_olive_F),
            QGVAR(JCA_H_HelmetHBK_headset_olive_F),
            QGVAR(JCA_H_HelmetHBK_sand_F),
            QGVAR(JCA_H_HelmetHBK_chops_sand_F),
            QGVAR(JCA_H_HelmetHBK_ear_sand_F),
            QGVAR(JCA_H_HelmetHBK_headset_sand_F),
            QGVAR(JCA_H_HelmetHBK_ear_olive_F)
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "jmfsb_main",
            "Headwear_F_JCA_IE",
            "ace_hearing"
        };
        skipWhenMissingDependencies = 1;
        authorUrl = "https://github.com/Joint-Multi-Functional-Strike-Battalion/";
        author = QAUTHOR;
        authors[] = {""};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
#include "XtdGear.hpp"
