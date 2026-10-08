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
            "cba_main",
            // AB rounds register into the antidrone proximity-fuze registry
            "jmfsb_fa_antidrone",
            // vanilla RPG-32 (base game) and RPG-7 (Apex platform content)
            "A3_Weapons_F_Launchers_RPG32",
            "A3_Weapons_F_Exp_Launchers_RPG7"
        };
        author = QAUTHOR;
        VERSION_CONFIG;
        ammo[] = {
            "FA_R_RPG32_PG32V2",
            "FA_R_RPG32_TBG32V2",
            "FA_R_RPG32_AB32",
            "FA_R_RPG7_PG7VR2",
            "FA_R_RPG7_TBG7V2",
            "FA_R_RPG7_AB7",
            "FA_ammo_Penetrator_RPG32V2",
            "FA_ammo_Penetrator_PG7VR2"
        };
        magazines[] = {
            "FA_RPG32_PG32V2",
            "FA_RPG32_TBG32V2",
            "FA_RPG32_AB32",
            "FA_RPG7_PG7VR2",
            "FA_RPG7_TBG7V2",
            "FA_RPG7_AB7"
        };
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgMagazinewells.hpp"
