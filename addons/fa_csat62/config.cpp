#include "script_component.hpp"

// =====================================================================
//  6.2x40 CASELESS - CSAT / PLA next-gen 2040  (DBP-25 family)
//  Requires: CBA, ace_ballistics (Advanced Ballistics ON)
//  Metric ACE units: caliber/length MM, mass GRAMS.
//
//  LORE: the real 6.2x40 (DBP-10/DBP-88) is CASED. This projects the
//  PLA's own caseless successor - CSAT going caseless independently of
//  NATO, on their own caliber. Separate logistics chain:
//     6.2x40 caseless -> 12.7x108 -> 125mm   (none of it NATO)
//
//  CASELESS => same heat-retention problem as the MX. Weapons firing
//  these want ~+18% ace_overheating_barrelMass (no case to eject heat).
//
//  Fielded on the Katiba (CBA_65x39_Katiba well) via green caseless mag
//  bodies; the DBP-88B belt rides the Mk200 well. Base bullet class is
//  the vanilla 6.5 caseless projectile (structural placeholder).
// =====================================================================

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "jmfsb_fa_main",
            "cba_main",
            "ace_ballistics",
            "A3_Weapons_F",
            // DBJ-25 PAB hooks the antidrone proximity-fuze registry
            "jmfsb_fa_antidrone"
        };
        author = QAUTHOR;
        VERSION_CONFIG;
        ammo[] = {
            "FA_o_ammo_62_DBP25",
            "FA_o_ammo_62_DBP26_AP",
            "FA_o_ammo_62_DBP88B",
            "FA_o_ammo_62_DBJ25_PAB"
        };
        magazines[] = {
            "FA_o_30Rnd_62_DBP25",
            "FA_o_30Rnd_62_DBP26_AP",
            "FA_o_30Rnd_62_DBP88B",
            "FA_o_30Rnd_62_DBJ25_PAB"
        };
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgMagazinewells.hpp"
