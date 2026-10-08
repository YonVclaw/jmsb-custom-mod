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
            // the imported Aegis weapons and magazines (tools/aegis_port --seeds), not the Aegis mod
            // (user, 2026-10-04: the Aegis family leaves the load order). The SR25, SLR, WF50 and
            // SCAR entries below only take effect if a mod defining those classes loads.
            "jmfsb_weapons"
        };
        skipWhenMissingDependencies = 1;
        author = QAUTHOR;
        VERSION_CONFIG;
        magazines[] = {
            // 7.62x54R SVD — Ball HV
            "FA_Aegis_10Rnd_762x54_SVD_HV",
            "FA_Aegis_10Rnd_762x54_SVD_HV_T_Red",
            "FA_Aegis_10Rnd_762x54_SVD_HV_T_Yellow",
            "FA_Aegis_10Rnd_762x54_SVD_HV_T_Green",
            "FA_Aegis_10Rnd_762x54_SVD_HV_T_White",
            "FA_Aegis_10Rnd_762x54_SVD_HV_T_Blue",
            "FA_Aegis_10Rnd_762x54_SVD_HV_T_Orange",
            "FA_Aegis_10Rnd_762x54_SVD_HV_T_IR",
            // .50 WF50 — Mk258 LRP
            "FA_Aegis_5Rnd_127x99_Mk258",
            "FA_Aegis_5Rnd_127x99_Mk258_T_Red",
            "FA_Aegis_5Rnd_127x99_Mk258_T_Yellow",
            "FA_Aegis_5Rnd_127x99_Mk258_T_Green",
            "FA_Aegis_5Rnd_127x99_Mk258_T_White",
            "FA_Aegis_5Rnd_127x99_Mk258_T_Blue",
            "FA_Aegis_5Rnd_127x99_Mk258_T_Orange",
            "FA_Aegis_5Rnd_127x99_Mk258_T_IR",
            // .50 WF50 — Mk211 Mod 0 HEIAP
            "FA_Aegis_5Rnd_127x99_Mk211Mod0",
            "FA_Aegis_5Rnd_127x99_Mk211Mod0_T_Red",
            "FA_Aegis_5Rnd_127x99_Mk211Mod0_T_Yellow",
            "FA_Aegis_5Rnd_127x99_Mk211Mod0_T_Green",
            "FA_Aegis_5Rnd_127x99_Mk211Mod0_T_White",
            "FA_Aegis_5Rnd_127x99_Mk211Mod0_T_Blue",
            "FA_Aegis_5Rnd_127x99_Mk211Mod0_T_Orange",
            "FA_Aegis_5Rnd_127x99_Mk211Mod0_T_IR",
            // 5.45x39 7N44 Osa — 30 / 45 / 60
            "FA_Aegis_30Rnd_545x39_7N44",
            "FA_Aegis_30Rnd_545x39_7N44_T_Red",
            "FA_Aegis_30Rnd_545x39_7N44_T_Yellow",
            "FA_Aegis_30Rnd_545x39_7N44_T_Green",
            "FA_Aegis_30Rnd_545x39_7N44_T_White",
            "FA_Aegis_30Rnd_545x39_7N44_T_Blue",
            "FA_Aegis_30Rnd_545x39_7N44_T_Orange",
            "FA_Aegis_30Rnd_545x39_7N44_T_IR",
            "FA_Aegis_45Rnd_545x39_7N44",
            "FA_Aegis_45Rnd_545x39_7N44_T_Red",
            "FA_Aegis_45Rnd_545x39_7N44_T_Yellow",
            "FA_Aegis_45Rnd_545x39_7N44_T_Green",
            "FA_Aegis_45Rnd_545x39_7N44_T_White",
            "FA_Aegis_45Rnd_545x39_7N44_T_Blue",
            "FA_Aegis_45Rnd_545x39_7N44_T_Orange",
            "FA_Aegis_45Rnd_545x39_7N44_T_IR",
            "FA_Aegis_60Rnd_545x39_7N44",
            "FA_Aegis_60Rnd_545x39_7N44_T_Red",
            "FA_Aegis_60Rnd_545x39_7N44_T_Yellow",
            "FA_Aegis_60Rnd_545x39_7N44_T_Green",
            "FA_Aegis_60Rnd_545x39_7N44_T_White",
            "FA_Aegis_60Rnd_545x39_7N44_T_Blue",
            "FA_Aegis_60Rnd_545x39_7N44_T_Orange",
            "FA_Aegis_60Rnd_545x39_7N44_T_IR",
            // 5.45x39 7N48 Osa-2 — 30 / 45
            "FA_Aegis_30Rnd_545x39_7N48",
            "FA_Aegis_30Rnd_545x39_7N48_T_Red",
            "FA_Aegis_30Rnd_545x39_7N48_T_Yellow",
            "FA_Aegis_30Rnd_545x39_7N48_T_Green",
            "FA_Aegis_30Rnd_545x39_7N48_T_White",
            "FA_Aegis_30Rnd_545x39_7N48_T_Blue",
            "FA_Aegis_30Rnd_545x39_7N48_T_Orange",
            "FA_Aegis_30Rnd_545x39_7N48_T_IR",
            "FA_Aegis_45Rnd_545x39_7N48",
            "FA_Aegis_45Rnd_545x39_7N48_T_Red",
            "FA_Aegis_45Rnd_545x39_7N48_T_Yellow",
            "FA_Aegis_45Rnd_545x39_7N48_T_Green",
            "FA_Aegis_45Rnd_545x39_7N48_T_White",
            "FA_Aegis_45Rnd_545x39_7N48_T_Blue",
            "FA_Aegis_45Rnd_545x39_7N48_T_Orange",
            "FA_Aegis_45Rnd_545x39_7N48_T_IR",
            // 5.45x39 7U5 Tishina-5 — 30 (subsonic)
            "FA_Aegis_30Rnd_545x39_7U5",
            "FA_Aegis_30Rnd_545x39_7U5_T_Red",
            "FA_Aegis_30Rnd_545x39_7U5_T_Yellow",
            "FA_Aegis_30Rnd_545x39_7U5_T_Green",
            "FA_Aegis_30Rnd_545x39_7U5_T_White",
            "FA_Aegis_30Rnd_545x39_7U5_T_Blue",
            "FA_Aegis_30Rnd_545x39_7U5_T_Orange",
            "FA_Aegis_30Rnd_545x39_7U5_T_IR"
        };
    };
};

#include "CfgMagazines.hpp"
#include "CfgMagazinewells.hpp"
#include "CfgWeapons.hpp"
