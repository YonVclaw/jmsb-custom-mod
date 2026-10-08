#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            QGVAR(CombatUniformNCU_01_mcam_F),
            QGVAR(CombatUniformNCU_02_mcam_F),
            QGVAR(CombatUniformNCU_01_mcam_wdl_F),
            QGVAR(CombatUniformNCU_02_mcam_wdl_F),
            QGVAR(CombatUniformNCU_01_ocp_F),
            QGVAR(CombatUniformNCU_02_ocp_F)
        };
        weapons[] = {
            QGVAR(U_CombatUniformNCU_01_mcam_F),
            QGVAR(U_CombatUniformNCU_02_mcam_F),
            QGVAR(U_CombatUniformNCU_01_mcam_wdl_F),
            QGVAR(U_CombatUniformNCU_02_mcam_wdl_F),
            QGVAR(U_CombatUniformNCU_01_ocp_F),
            QGVAR(U_CombatUniformNCU_02_ocp_F)
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "jmfsb_main", "A3_Characters_F", "A3_Data_F_Decade_Loadorder"
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
