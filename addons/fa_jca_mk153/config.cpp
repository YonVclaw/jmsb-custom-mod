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
            // C-UAS / airburst rounds hook the antidrone proximity-fuze registry
            "jmfsb_fa_antidrone",
            // JCA Mk153 SMAW launcher — its magazine bodies + JCA_MK153 well.
            // Requiring it (with skipWhenMissingDependencies) keeps this a clean
            // standalone PBO: it self-skips when the launcher pack is absent,
            // and never affects the jmfsbfa_jca rifle magazines.
            "Weapons_F_JCA_IA_Launchers_Mk153"
        };
        skipWhenMissingDependencies = 1;
        author = QAUTHOR;
        VERSION_CONFIG;
        ammo[] = {
            "FA_ammo_Penetrator_smaw_HEAA",
            "FA_ammo_Penetrator_smaw_CS",
            "FA_ammo_Penetrator_smaw_GS",
            "FA_ammo_Penetrator_smaw_HEDP",
            "FA_R_smaw_Mk6Mod2_HEAA",
            "FA_R_smaw_Mk3Mod2_HEDP",
            "FA_R_smaw_Mk80Mod1_NE",
            "FA_R_smaw_Mk7_CS",
            "FA_smaw_FTG_grenade",
            "FA_R_smaw_Mk85_FTG",
            "FA_M_smaw_Mk22_GS",
            "FA_R_smaw_Mk18_ADM"
        };
        magazines[] = {
            "FA_JCA_MK153_Mk6Mod2_HEAA",
            "FA_JCA_MK153_Mk3Mod2_HEDP",
            "FA_JCA_MK153_Mk80Mod1_NE",
            "FA_JCA_MK153_Mk7_CS",
            "FA_JCA_MK153_Mk85_FTG",
            "FA_JCA_MK153_Mk22_GS",
            "FA_JCA_MK153_Mk18_ADM"
        };
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgMagazinewells.hpp"
