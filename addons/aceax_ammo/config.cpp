#include "script_component.hpp"

// THE AMMO PANEL, COLLAPSED. The mission arsenal lists over a thousand
// magazines and a large share of them differ from a neighbour only in the
// colour the tracer burns or the colour of the magazine body. Those are the
// same item in a different paint, and they cost a row each.
//
// This folds each such family to ONE row with a dropdown under the panel, the
// way ACE Arsenal Extended folds uniforms and helmets in its left-hand tabs.
//
// WHAT THIS OWNS NOW (2026-09-01). It was written when ACEAX had no concept of
// a magazine at all: its toolchain knew primary/handgun/launcher, the six
// worn-gear tabs and the four attachment slots over CfgWeapons, CfgVehicles and
// CfgGlasses, and @aceaxatt returned "not my slot" for every magazine panel. The
// data was written in ACEAX's own XtdGearModels / XtdGearInfos schema anyway, on
// the reasoning that it would be correct already if ACEAX ever grew magazine
// support.
//
// IT DID. @aceaxatt 1.1.0.0 (2026-08-30) answers "CfgMagazines" for the four
// weapon-magazine panels and collapses them off exactly this data - the
// aceax_gearinfo API was always parameterised by config root, so nothing in
// ACEAX core needed changing. That bet paid off, and the split is now:
//
//   THE DATA IS THE PRODUCT. XtdGearModels.hpp and XtdGearInfos.hpp are the only
//   XtdGearInfos >> CfgMagazines in the load order. @aceaxatt's magazine support
//   folds nothing without them, so they cover every magazine, not just the
//   panels below.
//
//   THE RUNTIME IS THE REMAINDER. It collapses only Throw and Put - the grenade
//   and explosive tabs, which @aceaxatt declines because its own toolchain
//   writes no data for them. See AMMO_PANEL_IDCS in defines.hpp.
//
// GENERATED: XtdGearModels.hpp and XtdGearInfos.hpp come from
// tools/gen_aceax_ammo.py, which reads the mission's own magazine list. Re-run
// it rather than editing them.
//
// ACE is the only hard requirement - without ace_arsenal there is no panel to
// collapse. Without this addon the arsenal behaves exactly as it did.
class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"jmfsb_main", "ace_arsenal", "cba_settings"};
        skipWhenMissingDependencies = 1;
        author = QAUTHOR;
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "defines.hpp"
#include "gui.hpp"
#include "XtdGearModels.hpp"
#include "XtdGearInfos.hpp"
