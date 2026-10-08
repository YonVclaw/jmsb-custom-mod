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
            // C-UAS rounds register into the antidrone proximity-fuze registry
            "jmfsb_fa_antidrone",
            // vanilla MAAWS Mk4 (Tanks DLC platform content) — patched below
            "A3_Weapons_F_Tank_Launchers_MRAWS"
        };
        author = QAUTHOR;
        VERSION_CONFIG;
        ammo[] = {
            "FA_R_MRAWS_HEAT758_TT",
            "FA_R_MRAWS_HEAT665_CS",
            "FA_R_MRAWS_HE448_AB",
            "FA_M_MRAWS_GM841",
            "FA_R_MRAWS_ADM484",
            "FA_R_MRAWS_ADM486",
            "FA_R_MRAWS_ADM486_flechette",
            "FA_M_MRAWS_ADM487",
            "FA_M_MRAWS_AAM517",
            "FA_ammo_Penetrator_MRAWS_758",
            "FA_ammo_Penetrator_MRAWS_665",
            "FA_ammo_Penetrator_MRAWS_841"
        };
        magazines[] = {
            "FA_MRAWS_HEAT758_TT",
            "FA_MRAWS_HEAT665_CS",
            "FA_MRAWS_HE448_AB",
            "FA_MRAWS_GM841",
            "FA_MRAWS_ADM484_PROX",
            "FA_MRAWS_ADM486_CAN",
            "FA_MRAWS_ADM487_SEEK",
            "FA_MRAWS_AAM517_SR"
        };
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgMagazinewells.hpp"
#include "CfgWeapons.hpp"
