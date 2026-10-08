#include "script_component.hpp"
/*
 * Author: YonV
 * Sets the local player's Mk364 programmable-airburst slant range, read at fire
 * time by fnc_trackAD. 0 = off: the round reverts to a pure proximity fuze that
 * still delivers HE on impact.
 *
 * Arguments:
 * 0: Burst range in metres (0 = off) <NUMBER>
 *
 * Return Value:
 * None
 *
 * Public: No
 */
params [["_range", 0, [0]]];

ACE_player setVariable [QGVAR(burstRange), _range];

private _msg = if (_range <= 0) then {
    "OFF - proximity fuze, HE on impact"
} else {
    format ["Range: %1 m", _range]
};
["Mk364 Airburst", _msg, [0.871, 0.361, 0.188, 1]] call EFUNC(notify,notify);
