#include "script_component.hpp"
/*
 * Registers the 14.5x114 7N62 HEAB round with the antidrone component's
 * proximity fuze (makes the KPV a drone-killer). Runs after jmfsbfa_antidrone's
 * postInit. Flies as a plain ball round if the antidrone component is absent.
 *
 * Public: No
 */

if (isNil QEGVAR(fa_antidrone,AD_params)) exitWith {};

// [trigger radius (m), lethal radius (m), max damage, effective range (m)]
EGVAR(fa_antidrone,AD_params) set ["FA_o_ammo_145_7N62", [3, 2.5, 0.35, 2000]];   // halved 2026-08 (PAB rebalance)
