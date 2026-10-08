#include "script_component.hpp"
/*
 * Author: YonV
 * True if the local player is carrying or has loaded a 40mm Mk364 PAB magazine.
 * Gates the ACE self-interaction airburst-range menu (CfgVehicles.hpp).
 *
 * Arguments:
 * None
 *
 * Return Value:
 * Has a Mk364 magazine <BOOL>
 *
 * Public: No
 */
// FA_MRAWS_HE448_AB (maaws component) shares the programmable fuze, so it also
// unlocks the menu; harmless string if that addon is not loaded.
private _mags = ["FA_b_1Rnd_40mm_Mk364_PAB", "FA_b_3Rnd_40mm_Mk364_PAB", "FA_MRAWS_HE448_AB"];
(magazinesAmmoFull ACE_player findIf {(_x select 0) in _mags}) > -1
