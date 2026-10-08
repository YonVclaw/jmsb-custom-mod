#include "script_component.hpp"
/*
 * Registers the RC40 C-UAS / airburst grenade rounds with the antidrone
 * component's proximity fuze. Runs after jmfsbfa_antidrone's postInit
 * (requiredAddons ordering). Fly as plain HE if the antidrone component is absent.
 *
 * Public: No
 */

if (isNil QEGVAR(fa_antidrone,AD_params)) exitWith {};

// [trigger radius (m), lethal radius (m), max damage, effective range (m)]
// RC40 AD — anti-drone proximity frag.
EGVAR(fa_antidrone,AD_params) set ["FA_ammo_RC40_AD", [6, 6, 0.7, 400]];

// RC40 HE-P — programmable airburst only: trigger radius 0 disables the drone
// proximity check while the dialled burst range (shared Mk364 keybind /
// ACE self-menu) still detonates the round in flight.
EGVAR(fa_antidrone,AD_params) set ["FA_ammo_RC40_HEP", [0, 8, 0.7, 800]];
EGVAR(fa_antidrone,programmableAB) pushBackUnique "FA_ammo_RC40_HEP";
