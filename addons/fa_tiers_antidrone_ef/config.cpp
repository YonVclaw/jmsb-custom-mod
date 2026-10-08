#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        // THE ROUNDS WHOSE SOURCE CAN VANISH. Its one source addon drops
        // itself when its mod or DLC is absent, so this one drops with
        // it, and takes only the tiers for rounds that are not there either.
        requiredAddons[] = {"cba_xeh", "jmfsb_fa_antidrone_ef", "jmfsb_fa_main", "jmfsb_fa_tiers", "jmfsb_main"};
        skipWhenMissingDependencies = 1;
        author = QAUTHOR;
        VERSION_CONFIG;
    };
};

#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgMagazineWells.hpp"
