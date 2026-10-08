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
            "jmfsb_fa_antidrone",
            "Weapons_F_JCA_IA_Rifles_M4A1",
            "Weapons_F_JCA_IA_Rifles_HK437",
            "Weapons_F_JCA_IA_Rifles_HK433",
            "Weapons_F_JCA_IA_Rifles_SR10"
        };
        skipWhenMissingDependencies = 1;
        author = QAUTHOR;
        VERSION_CONFIG;
        magazines[] = {
            "FA_JCA_30Rnd_556x45_Green_PMAG_Mk361_PAB",
            "FA_JCA_30Rnd_556x45_Green_PMAG_Mk361_PAB_T_Red",
            "FA_JCA_30Rnd_556x45_Green_PMAG_Mk361_PAB_T_Yellow",
            "FA_JCA_30Rnd_556x45_Green_PMAG_Mk361_PAB_T_Green",
            "FA_JCA_30Rnd_556x45_Green_PMAG_Mk361_PAB_T_White",
            "FA_JCA_30Rnd_556x45_Green_PMAG_Mk361_PAB_T_Blue",
            "FA_JCA_30Rnd_556x45_Green_PMAG_Mk361_PAB_T_Orange",
            "FA_JCA_30Rnd_556x45_EMAG_Mk361_PAB",
            "FA_JCA_30Rnd_556x45_EMAG_Mk361_PAB_T_Red",
            "FA_JCA_30Rnd_556x45_EMAG_Mk361_PAB_T_Yellow",
            "FA_JCA_30Rnd_556x45_EMAG_Mk361_PAB_T_Green",
            "FA_JCA_30Rnd_556x45_EMAG_Mk361_PAB_T_White",
            "FA_JCA_30Rnd_556x45_EMAG_Mk361_PAB_T_Blue",
            "FA_JCA_30Rnd_556x45_EMAG_Mk361_PAB_T_Orange",
            "FA_JCA_30Rnd_556x45_sand_EMAG_Mk361_PAB",
            "FA_JCA_30Rnd_556x45_sand_EMAG_Mk361_PAB_T_Red",
            "FA_JCA_30Rnd_556x45_sand_EMAG_Mk361_PAB_T_Yellow",
            "FA_JCA_30Rnd_556x45_sand_EMAG_Mk361_PAB_T_Green",
            "FA_JCA_30Rnd_556x45_sand_EMAG_Mk361_PAB_T_White",
            "FA_JCA_30Rnd_556x45_sand_EMAG_Mk361_PAB_T_Blue",
            "FA_JCA_30Rnd_556x45_sand_EMAG_Mk361_PAB_T_Orange",
            "FA_JCA_30Rnd_556x45_PMAG_Mk361_PAB",
            "FA_JCA_30Rnd_556x45_PMAG_Mk361_PAB_T_Red",
            "FA_JCA_30Rnd_556x45_PMAG_Mk361_PAB_T_Yellow",
            "FA_JCA_30Rnd_556x45_PMAG_Mk361_PAB_T_Green",
            "FA_JCA_30Rnd_556x45_PMAG_Mk361_PAB_T_White",
            "FA_JCA_30Rnd_556x45_PMAG_Mk361_PAB_T_Blue",
            "FA_JCA_30Rnd_556x45_PMAG_Mk361_PAB_T_Orange",
            "FA_JCA_30Rnd_556x45_sand_PMAG_Mk361_PAB",
            "FA_JCA_30Rnd_556x45_sand_PMAG_Mk361_PAB_T_Red",
            "FA_JCA_30Rnd_556x45_sand_PMAG_Mk361_PAB_T_Yellow",
            "FA_JCA_30Rnd_556x45_sand_PMAG_Mk361_PAB_T_Green",
            "FA_JCA_30Rnd_556x45_sand_PMAG_Mk361_PAB_T_White",
            "FA_JCA_30Rnd_556x45_sand_PMAG_Mk361_PAB_T_Blue",
            "FA_JCA_30Rnd_556x45_sand_PMAG_Mk361_PAB_T_Orange",
            "FA_JCA_20Rnd_762x51_PMAG_Mk362_PAB",
            "FA_JCA_20Rnd_762x51_PMAG_Mk362_PAB_T_Red",
            "FA_JCA_20Rnd_762x51_PMAG_Mk362_PAB_T_Yellow",
            "FA_JCA_20Rnd_762x51_PMAG_Mk362_PAB_T_Green",
            "FA_JCA_20Rnd_762x51_PMAG_Mk362_PAB_T_White",
            "FA_JCA_20Rnd_762x51_PMAG_Mk362_PAB_T_Blue",
            "FA_JCA_20Rnd_762x51_PMAG_Mk362_PAB_T_Orange",
            "FA_JCA_20Rnd_762x51_Sand_PMAG_Mk362_PAB",
            "FA_JCA_20Rnd_762x51_Sand_PMAG_Mk362_PAB_T_Red",
            "FA_JCA_20Rnd_762x51_Sand_PMAG_Mk362_PAB_T_Yellow",
            "FA_JCA_20Rnd_762x51_Sand_PMAG_Mk362_PAB_T_Green",
            "FA_JCA_20Rnd_762x51_Sand_PMAG_Mk362_PAB_T_White",
            "FA_JCA_20Rnd_762x51_Sand_PMAG_Mk362_PAB_T_Blue",
            "FA_JCA_20Rnd_762x51_Sand_PMAG_Mk362_PAB_T_Orange",
            "FA_JCA_30Rnd_300BLK_EMAG_Mk363_PAB",
            "FA_JCA_30Rnd_300BLK_EMAG_Mk363_PAB_T_Red",
            "FA_JCA_30Rnd_300BLK_EMAG_Mk363_PAB_T_Yellow",
            "FA_JCA_30Rnd_300BLK_EMAG_Mk363_PAB_T_Green",
            "FA_JCA_30Rnd_300BLK_EMAG_Mk363_PAB_T_White",
            "FA_JCA_30Rnd_300BLK_EMAG_Mk363_PAB_T_Blue",
            "FA_JCA_30Rnd_300BLK_EMAG_Mk363_PAB_T_Orange",
            "FA_JCA_30Rnd_300BLK_sand_EMAG_Mk363_PAB",
            "FA_JCA_30Rnd_300BLK_sand_EMAG_Mk363_PAB_T_Red",
            "FA_JCA_30Rnd_300BLK_sand_EMAG_Mk363_PAB_T_Yellow",
            "FA_JCA_30Rnd_300BLK_sand_EMAG_Mk363_PAB_T_Green",
            "FA_JCA_30Rnd_300BLK_sand_EMAG_Mk363_PAB_T_White",
            "FA_JCA_30Rnd_300BLK_sand_EMAG_Mk363_PAB_T_Blue",
            "FA_JCA_30Rnd_300BLK_sand_EMAG_Mk363_PAB_T_Orange",
            // Mk368/Mk369 AD buckshot (K short / L long)
            "FA_JCA_30Rnd_556x45_EMAG_Mk368K_AD",
            "FA_JCA_30Rnd_556x45_EMAG_Mk368L_AD",
            "FA_JCA_30Rnd_556x45_sand_EMAG_Mk368K_AD",
            "FA_JCA_30Rnd_556x45_sand_EMAG_Mk368L_AD",
            "FA_JCA_30Rnd_556x45_PMAG_Mk368K_AD",
            "FA_JCA_30Rnd_556x45_PMAG_Mk368L_AD",
            "FA_JCA_30Rnd_556x45_sand_PMAG_Mk368K_AD",
            "FA_JCA_30Rnd_556x45_sand_PMAG_Mk368L_AD",
            "FA_JCA_30Rnd_556x45_Green_PMAG_Mk368K_AD",
            "FA_JCA_30Rnd_556x45_Green_PMAG_Mk368L_AD",
            "FA_JCA_20Rnd_762x51_PMAG_Mk369K_AD",
            "FA_JCA_20Rnd_762x51_PMAG_Mk369L_AD",
            "FA_JCA_20Rnd_762x51_Sand_PMAG_Mk369K_AD",
            "FA_JCA_20Rnd_762x51_Sand_PMAG_Mk369L_AD"
        };
    };
};

#include "CfgMagazines.hpp"
#include "CfgMagazinewells.hpp"
