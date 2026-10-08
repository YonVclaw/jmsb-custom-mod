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
            "jmfsb_notify",
            "cba_main",
            "A3_Weapons_F"
        };
        author = QAUTHOR;
        VERSION_CONFIG;
        ammo[] = {
            "FA_40mm_Carrier_Base",
            "FA_40mm_Mk380_NRP",
            "FA_40mm_Mk383_EMP",
            "FA_40mm_Mk384_MSmoke",
            "FA_40mm_Mk385_Decoy",
            "FA_40mm_Mk386_UGS",
            "FA_40mm_Mk388_Jammer"
        };
        magazines[] = {
            "FA_1Rnd_40mm_Mk380_NRP",
            "FA_1Rnd_40mm_Mk383_EMP",
            "FA_1Rnd_40mm_Mk384_MSmoke",
            "FA_1Rnd_40mm_Mk385_Decoy",
            "FA_1Rnd_40mm_Mk386_UGS",
            "FA_1Rnd_40mm_Mk388_Jammer",
            "FA_3Rnd_40mm_Mk380_NRP",
            "FA_3Rnd_40mm_Mk383_EMP",
            "FA_3Rnd_40mm_Mk384_MSmoke",
            "FA_3Rnd_40mm_Mk385_Decoy",
            "FA_3Rnd_40mm_Mk386_UGS",
            "FA_3Rnd_40mm_Mk388_Jammer"
        };
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgMagazinewells.hpp"
