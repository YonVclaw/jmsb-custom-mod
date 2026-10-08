#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        // THE ROUNDS THAT ARE ALWAYS THERE. Not one addon below can skip
        // itself, so this states its dependencies honestly and loads
        // cleanly on any mod set. The mod-sourced tiers live in
        // jmfsb_fa_tiers_mods, which is allowed to disappear.
        //
        // Splitting them is what ended two failures at once: one tier
        // addon requiring fa_rhs either cascaded a skip - deleting every
        // tier magazine when RHS was absent - or warned about an unmet
        // dependency on every start.
        requiredAddons[] = {"cba_xeh", "jmfsb_fa_ammo", "jmfsb_fa_antidrone", "jmfsb_fa_csat62", "jmfsb_fa_extracal", "jmfsb_fa_main", "jmfsb_main"};
        author = QAUTHOR;
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgMagazineWells.hpp"
