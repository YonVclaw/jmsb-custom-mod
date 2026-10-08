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
            "cba_main"
        };
        author = QAUTHOR;
        VERSION_CONFIG;
        ammo[] = {
            // 30mm APFSDS-T (base + Red faction gradient + tracer colors)
            "FA_B_30mm_APFSDS",
            "FA_B_30mm_APFSDS_Red",
            "FA_B_30mm_APFSDS_T_Red",
            "FA_B_30mm_APFSDS_T_Yellow",
            "FA_B_30mm_APFSDS_T_Green",
            "FA_B_30mm_APFSDS_T_White",
            "FA_B_30mm_APFSDS_T_Blue",
            "FA_B_30mm_APFSDS_T_Orange",
            "FA_B_30mm_APFSDS_T_IR",
            // 30mm API-T
            "FA_B_30mm_API",
            "FA_B_30mm_API_T_Red",
            "FA_B_30mm_API_T_Yellow",
            "FA_B_30mm_API_T_Green",
            "FA_B_30mm_API_T_White",
            "FA_B_30mm_API_T_Blue",
            "FA_B_30mm_API_T_Orange",
            "FA_B_30mm_API_T_IR",
            // 30mm HEI-T
            "FA_B_30mm_HEI",
            "FA_B_30mm_HEI_T_Red",
            "FA_B_30mm_HEI_T_Yellow",
            "FA_B_30mm_HEI_T_Green",
            "FA_B_30mm_HEI_T_White",
            "FA_B_30mm_HEI_T_Blue",
            "FA_B_30mm_HEI_T_Orange",
            "FA_B_30mm_HEI_T_IR",
            // 30mm ABM
            "FA_B_30mm_ABM",
            "FA_B_30mm_ABM_T_Red",
            "FA_B_30mm_ABM_T_Yellow",
            "FA_B_30mm_ABM_T_Green",
            "FA_B_30mm_ABM_T_White",
            "FA_B_30mm_ABM_T_Blue",
            "FA_B_30mm_ABM_T_Orange",
            "FA_B_30mm_ABM_T_IR",
            // 30mm PROX
            "FA_B_30mm_PROX",
            "FA_B_30mm_PROX_T_Red",
            "FA_B_30mm_PROX_T_Yellow",
            "FA_B_30mm_PROX_T_Green",
            "FA_B_30mm_PROX_T_White",
            "FA_B_30mm_PROX_T_Blue",
            "FA_B_30mm_PROX_T_Orange",
            "FA_B_30mm_PROX_T_IR",
            // 35mm AHEAD
            "FA_B_35mm_AHEAD",
            "FA_B_35mm_AHEAD_T_Red",
            "FA_B_35mm_AHEAD_T_Yellow",
            "FA_B_35mm_AHEAD_T_Green",
            "FA_B_35mm_AHEAD_T_White",
            "FA_B_35mm_AHEAD_T_Blue",
            "FA_B_35mm_AHEAD_T_Orange",
            "FA_B_35mm_AHEAD_T_IR",
            // 50mm (dormant)
            "FA_B_50mm_HEAB",
            "FA_B_50mm_APFSDS"
        };
        magazines[] = {
            // 30mm APFSDS-T (base + Red faction gradient + tracer colors)
            "FA_60Rnd_30mm_APFSDS",
            "FA_60Rnd_30mm_APFSDS_Red",
            "FA_60Rnd_30mm_APFSDS_T_Red",
            "FA_60Rnd_30mm_APFSDS_T_Yellow",
            "FA_60Rnd_30mm_APFSDS_T_Green",
            "FA_60Rnd_30mm_APFSDS_T_White",
            "FA_60Rnd_30mm_APFSDS_T_Blue",
            "FA_60Rnd_30mm_APFSDS_T_Orange",
            "FA_60Rnd_30mm_APFSDS_T_IR",
            // 30mm API-T
            "FA_140Rnd_30mm_API",
            "FA_140Rnd_30mm_API_T_Red",
            "FA_140Rnd_30mm_API_T_Yellow",
            "FA_140Rnd_30mm_API_T_Green",
            "FA_140Rnd_30mm_API_T_White",
            "FA_140Rnd_30mm_API_T_Blue",
            "FA_140Rnd_30mm_API_T_Orange",
            "FA_140Rnd_30mm_API_T_IR",
            // 30mm HEI-T
            "FA_250Rnd_30mm_HEI",
            "FA_250Rnd_30mm_HEI_T_Red",
            "FA_250Rnd_30mm_HEI_T_Yellow",
            "FA_250Rnd_30mm_HEI_T_Green",
            "FA_250Rnd_30mm_HEI_T_White",
            "FA_250Rnd_30mm_HEI_T_Blue",
            "FA_250Rnd_30mm_HEI_T_Orange",
            "FA_250Rnd_30mm_HEI_T_IR",
            // 30mm ABM
            "FA_250Rnd_30mm_ABM",
            "FA_250Rnd_30mm_ABM_T_Red",
            "FA_250Rnd_30mm_ABM_T_Yellow",
            "FA_250Rnd_30mm_ABM_T_Green",
            "FA_250Rnd_30mm_ABM_T_White",
            "FA_250Rnd_30mm_ABM_T_Blue",
            "FA_250Rnd_30mm_ABM_T_Orange",
            "FA_250Rnd_30mm_ABM_T_IR",
            // 30mm PROX
            "FA_250Rnd_30mm_PROX",
            "FA_250Rnd_30mm_PROX_T_Red",
            "FA_250Rnd_30mm_PROX_T_Yellow",
            "FA_250Rnd_30mm_PROX_T_Green",
            "FA_250Rnd_30mm_PROX_T_White",
            "FA_250Rnd_30mm_PROX_T_Blue",
            "FA_250Rnd_30mm_PROX_T_Orange",
            "FA_250Rnd_30mm_PROX_T_IR",
            // 35mm AHEAD
            "FA_680Rnd_35mm_AHEAD",
            "FA_680Rnd_35mm_AHEAD_T_Red",
            "FA_680Rnd_35mm_AHEAD_T_Yellow",
            "FA_680Rnd_35mm_AHEAD_T_Green",
            "FA_680Rnd_35mm_AHEAD_T_White",
            "FA_680Rnd_35mm_AHEAD_T_Blue",
            "FA_680Rnd_35mm_AHEAD_T_Orange",
            "FA_680Rnd_35mm_AHEAD_T_IR",
            // 50mm (dormant)
            "FA_60Rnd_50mm_HEAB",
            "FA_60Rnd_50mm_APFSDS"
        };
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgWeapons.hpp"
