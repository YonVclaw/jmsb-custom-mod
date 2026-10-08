#include "script_component.hpp"
/*
 * Author: YonV
 * Registers the RPG AB rounds with the antidrone component's proximity fuze.
 * Runs after jmfsbfa_antidrone's postInit (requiredAddons ordering), so the
 * registry hashmap already exists.
 *
 * Public: No
 */

if (isNil QEGVAR(fa_antidrone,AD_params)) exitWith {};

// [trigger radius (m), lethal radius (m), max damage, effective range (m)]
// AB-32 PROX — mid-tier unguided drone airburst.
EGVAR(fa_antidrone,AD_params) set ["FA_R_RPG32_AB32", [10, 8, 0.8, 300]];
// AB-7 PROX — poor-man's counter-drone airburst; smallest radius in the set.
EGVAR(fa_antidrone,AD_params) set ["FA_R_RPG7_AB7", [8, 6, 0.7, 200]];
