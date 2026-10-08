#include "script_component.hpp"
/*
 * Author: YonV
 * Registers the MAAWS C-UAS rounds with the antidrone component's proximity
 * fuze. Runs after jmfsbfa_antidrone's postInit (requiredAddons ordering), so
 * the registry hashmap already exists.
 *
 * Public: No
 */

if (isNil QEGVAR(fa_antidrone,AD_params)) exitWith {};

// [trigger radius (m), lethal radius (m), max damage, effective range (m)]
// ADM 484 PROX — single-drone proximity frag.
EGVAR(fa_antidrone,AD_params) set ["FA_R_MRAWS_ADM484", [14, 12, 0.85, 600]];

// HE 448 AB — programmable airburst only: trigger radius 0 disables the drone
// proximity check while the dialled burst range (shared Mk364 keybind /
// ACE self-menu) still detonates the round in flight.
EGVAR(fa_antidrone,AD_params) set ["FA_R_MRAWS_HE448_AB", [0, 10, 0.8, 1500]];
EGVAR(fa_antidrone,programmableAB) pushBackUnique "FA_R_MRAWS_HE448_AB";
