#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "cba_main",
            "ace_ballistics",
            "jmfsb_fa_ammo",
            // base Expeditionary Forces mod — provides EF_*_65x39_caseless_coy_mag
            // (Aegis EF, weapons_f_aegis_ef, is a reskin layered on top of this)
            "EF_Weapons"
        };
        skipWhenMissingDependencies = 1;
        author = QAUTHOR;
        VERSION_CONFIG;
        magazines[] = {
            // EF 30Rnd coyote tracer variants
            "FA_EF_30Rnd_65x39_caseless_coy_mag_Tracer_T_Red",
            "FA_EF_30Rnd_65x39_caseless_coy_mag_Tracer_T_Yellow",
            "FA_EF_30Rnd_65x39_caseless_coy_mag_Tracer_T_Green",
            "FA_EF_30Rnd_65x39_caseless_coy_mag_Tracer_T_White",
            "FA_EF_30Rnd_65x39_caseless_coy_mag_Tracer_T_Blue",
            "FA_EF_30Rnd_65x39_caseless_coy_mag_Tracer_T_Orange",
            "FA_EF_30Rnd_65x39_caseless_coy_mag_Tracer_T_IR",
            // EF 100Rnd coyote tracer variants
            "FA_EF_100Rnd_65x39_caseless_coy_mag_T_Red",
            "FA_EF_100Rnd_65x39_caseless_coy_mag_T_Yellow",
            "FA_EF_100Rnd_65x39_caseless_coy_mag_T_Green",
            "FA_EF_100Rnd_65x39_caseless_coy_mag_T_White",
            "FA_EF_100Rnd_65x39_caseless_coy_mag_T_Blue",
            "FA_EF_100Rnd_65x39_caseless_coy_mag_T_Orange",
            "FA_EF_100Rnd_65x39_caseless_coy_mag_T_IR",
            // EPR non-tracer coyote
            "FA_EF_30Rnd_65x39_caseless_coy_mag",
            "FA_EF_100Rnd_65x39_caseless_coy_mag"
        };
    };
};

#include "CfgMagazines.hpp"
#include "CfgMagazinewells.hpp"
