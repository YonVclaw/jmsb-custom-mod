#include "script_component.hpp"

// ATTACHMENT MERGING FOR THE ACE ARSENAL. ACE3 Arsenal Extended groups similar
// items behind dropdowns, but only in its ten LEFT-panel tabs; attachments sit
// in the right panel and are skipped, so every optic, laser, can and bipod
// gets its own row. The @aceaxatt extension supplies the missing runtime; this
// addon supplies the DATA - which attachments are variants of which.
//
// Covers what the mission arsenal lists (config\arsenal\common\items_optics,
// _muzzles, _pointers_lights, _bipods): 58 entries over 233 classes, base
// game, JCA, ACE, the CDLCs and this mod's own optics.
//
// GENERATED from an in-game ITEM dump (tools\dump_orbat.sqf) - the CDLC
// configs are encrypted, so the game itself is the only source of their
// display names. Everything under XtdGearModels\ and XtdGearInfos\ is
// generated; the grouping rules are hand-written. Do not edit the trees.
//
// aceax_gearinfo is the ONLY hard requirement, and it is soft-guarded on top:
// without ACEAX the data is inert, and without @aceaxatt nothing reads the
// attachment half at all. Neither is an error.
class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"jmfsb_main", "aceax_gearinfo"};
        skipWhenMissingDependencies = 1;
        author = QAUTHOR;
        VERSION_CONFIG;
    };
};

#include "XtdGearModels.hpp"
#include "XtdGearInfos.hpp"
