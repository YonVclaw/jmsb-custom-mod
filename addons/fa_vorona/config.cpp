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
            // Oskol registers into the antidrone airburst registry
            "jmfsb_fa_antidrone",
            // vanilla Vorona (Tanks DLC platform content) — patched below
            "A3_Weapons_F_Tank_Launchers_Vorona"
        };
        author = QAUTHOR;
        VERSION_CONFIG;
        ammo[] = {
            "FA_M_Vorona_9M135M",
            "FA_M_Vorona_9M135F2",
            "FA_M_Vorona_9M135PVO",
            "FA_ammo_Penetrator_Vorona_9M135M"
        };
        magazines[] = {
            "FA_Vorona_9M135M",
            "FA_Vorona_9M135F2",
            "FA_Vorona_9M135PVO"
        };
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgMagazinewells.hpp"
#include "CfgWeapons.hpp"
