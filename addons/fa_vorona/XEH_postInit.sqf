#include "script_component.hpp"
/*
 * Author: YonV
 * Registers the Vorona 2040 rounds with the antidrone component's registries.
 * Runs after jmfsbfa_antidrone's postInit (requiredAddons ordering), so the
 * registry hashmap already exists.
 *
 * Public: No
 */

if (isNil QEGVAR(fa_antidrone,AD_params)) exitWith {};

// [trigger radius (m), lethal radius (m), max damage, effective range (m)]
// 9M135F-2 Oskol — programmable airburst only: trigger radius 0 disables the
// drone proximity check while the dialled burst range (shared Mk364 keybind /
// ACE self-menu) still detonates the missile in flight.
EGVAR(fa_antidrone,AD_params) set ["FA_M_Vorona_9M135F2", [0, 12, 0.85, 1600]];
EGVAR(fa_antidrone,programmableAB) pushBackUnique "FA_M_Vorona_9M135F2";
