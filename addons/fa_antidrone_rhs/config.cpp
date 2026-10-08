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
            "rhsusf_c_weapons"
        };
        skipWhenMissingDependencies = 1;
        author = QAUTHOR;
        VERSION_CONFIG;
        magazines[] = {
            "FA_rhsusf_100Rnd_556x45_M200_soft_pouch_Mk361_PAB",
            "FA_rhsusf_100Rnd_556x45_M200_soft_pouch_Mk361_PAB_T_Red",
            "FA_rhsusf_100Rnd_556x45_M200_soft_pouch_Mk361_PAB_T_Yellow",
            "FA_rhsusf_100Rnd_556x45_M200_soft_pouch_Mk361_PAB_T_Green",
            "FA_rhsusf_100Rnd_556x45_M200_soft_pouch_Mk361_PAB_T_White",
            "FA_rhsusf_100Rnd_556x45_M200_soft_pouch_Mk361_PAB_T_Blue",
            "FA_rhsusf_100Rnd_556x45_M200_soft_pouch_Mk361_PAB_T_Orange",
            "FA_rhsusf_100Rnd_556x45_M200_soft_pouch_coyote_Mk361_PAB",
            "FA_rhsusf_100Rnd_556x45_M200_soft_pouch_coyote_Mk361_PAB_T_Red",
            "FA_rhsusf_100Rnd_556x45_M200_soft_pouch_coyote_Mk361_PAB_T_Yellow",
            "FA_rhsusf_100Rnd_556x45_M200_soft_pouch_coyote_Mk361_PAB_T_Green",
            "FA_rhsusf_100Rnd_556x45_M200_soft_pouch_coyote_Mk361_PAB_T_White",
            "FA_rhsusf_100Rnd_556x45_M200_soft_pouch_coyote_Mk361_PAB_T_Blue",
            "FA_rhsusf_100Rnd_556x45_M200_soft_pouch_coyote_Mk361_PAB_T_Orange",
            "FA_rhs_mag_30Rnd_556x45_M855A1_PMAG_Tan_Mk361_PAB",
            "FA_rhs_mag_30Rnd_556x45_M855A1_PMAG_Tan_Mk361_PAB_T_Red",
            "FA_rhs_mag_30Rnd_556x45_M855A1_PMAG_Tan_Mk361_PAB_T_Yellow",
            "FA_rhs_mag_30Rnd_556x45_M855A1_PMAG_Tan_Mk361_PAB_T_Green",
            "FA_rhs_mag_30Rnd_556x45_M855A1_PMAG_Tan_Mk361_PAB_T_White",
            "FA_rhs_mag_30Rnd_556x45_M855A1_PMAG_Tan_Mk361_PAB_T_Blue",
            "FA_rhs_mag_30Rnd_556x45_M855A1_PMAG_Tan_Mk361_PAB_T_Orange",
            "FA_rhs_mag_30Rnd_556x45_M855A1_PMAG_Mk361_PAB",
            "FA_rhs_mag_30Rnd_556x45_M855A1_PMAG_Mk361_PAB_T_Red",
            "FA_rhs_mag_30Rnd_556x45_M855A1_PMAG_Mk361_PAB_T_Yellow",
            "FA_rhs_mag_30Rnd_556x45_M855A1_PMAG_Mk361_PAB_T_Green",
            "FA_rhs_mag_30Rnd_556x45_M855A1_PMAG_Mk361_PAB_T_White",
            "FA_rhs_mag_30Rnd_556x45_M855A1_PMAG_Mk361_PAB_T_Blue",
            "FA_rhs_mag_30Rnd_556x45_M855A1_PMAG_Mk361_PAB_T_Orange",
            "FA_rhsusf_200rnd_556x45_M855_box_Mk361_PAB",
            "FA_rhsusf_200rnd_556x45_M855_box_Mk361_PAB_T_Red",
            "FA_rhsusf_200rnd_556x45_M855_box_Mk361_PAB_T_Yellow",
            "FA_rhsusf_200rnd_556x45_M855_box_Mk361_PAB_T_Green",
            "FA_rhsusf_200rnd_556x45_M855_box_Mk361_PAB_T_White",
            "FA_rhsusf_200rnd_556x45_M855_box_Mk361_PAB_T_Blue",
            "FA_rhsusf_200rnd_556x45_M855_box_Mk361_PAB_T_Orange",
            "FA_rhsusf_200Rnd_556x45_M855_soft_pouch_Mk361_PAB",
            "FA_rhsusf_200Rnd_556x45_M855_soft_pouch_Mk361_PAB_T_Red",
            "FA_rhsusf_200Rnd_556x45_M855_soft_pouch_Mk361_PAB_T_Yellow",
            "FA_rhsusf_200Rnd_556x45_M855_soft_pouch_Mk361_PAB_T_Green",
            "FA_rhsusf_200Rnd_556x45_M855_soft_pouch_Mk361_PAB_T_White",
            "FA_rhsusf_200Rnd_556x45_M855_soft_pouch_Mk361_PAB_T_Blue",
            "FA_rhsusf_200Rnd_556x45_M855_soft_pouch_Mk361_PAB_T_Orange",
            "FA_rhs_mag_762x51_M240_Mk362_PAB",
            "FA_rhs_mag_762x51_M240_Mk362_PAB_T_Red",
            "FA_rhs_mag_762x51_M240_Mk362_PAB_T_Yellow",
            "FA_rhs_mag_762x51_M240_Mk362_PAB_T_Green",
            "FA_rhs_mag_762x51_M240_Mk362_PAB_T_White",
            "FA_rhs_mag_762x51_M240_Mk362_PAB_T_Blue",
            "FA_rhs_mag_762x51_M240_Mk362_PAB_T_Orange",
            "FA_rhs_mag_1100Rnd_762x51_M240_Mk362_PAB",
            "FA_rhs_mag_1100Rnd_762x51_M240_Mk362_PAB_T_Red",
            "FA_rhs_mag_1100Rnd_762x51_M240_Mk362_PAB_T_Yellow",
            "FA_rhs_mag_1100Rnd_762x51_M240_Mk362_PAB_T_Green",
            "FA_rhs_mag_1100Rnd_762x51_M240_Mk362_PAB_T_White",
            "FA_rhs_mag_1100Rnd_762x51_M240_Mk362_PAB_T_Blue",
            "FA_rhs_mag_1100Rnd_762x51_M240_Mk362_PAB_T_Orange",
            "FA_rhs_mag_762x51_M240_200_Mk362_PAB",
            "FA_rhs_mag_762x51_M240_200_Mk362_PAB_T_Red",
            "FA_rhs_mag_762x51_M240_200_Mk362_PAB_T_Yellow",
            "FA_rhs_mag_762x51_M240_200_Mk362_PAB_T_Green",
            "FA_rhs_mag_762x51_M240_200_Mk362_PAB_T_White",
            "FA_rhs_mag_762x51_M240_200_Mk362_PAB_T_Blue",
            "FA_rhs_mag_762x51_M240_200_Mk362_PAB_T_Orange"
        };
    };
};

#include "CfgMagazines.hpp"
#include "CfgMagazinewells.hpp"
