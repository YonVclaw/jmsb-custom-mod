#include "..\script_component.hpp"
/*
 * Author: JMSB
 * A Site member's Fired event: the interceptor is caught as it leaves.
 *
 * A missile fired at a munition is steered onto it (setMissileTarget - A0-1 of
 * the design: whether the engine flies a SAM at a shell is what the probe
 * answers; if it does not, the fuse still catches the round on the predicted
 * course). Every interceptor goes to the fuse (FUNC(fuze)) with its target, so
 * it detonates by proximity, and is marked so no Site ever tracks its own shot
 * as a threat.
 *
 * Arguments: the Fired event's own
 *
 * Return Value: None
 *
 * Public: No
 */

params ["_veh", "_weapon", "", "", "_ammo", "", "_proj"];

private _pending = _veh getVariable QGVAR(pending);
if (isNil "_pending" || {isNull _proj}) exitWith {};
_pending params ["_target", "_fuse", "_siteId", "_kind"];
if (!alive _target) exitWith {};

_proj setVariable [QGVAR(interceptor), true];
private _sim = toLower getText (configFile >> "CfgAmmo" >> _ammo >> "simulation");

if (_sim in ["shotmissile", "shotrocket"]) then {
    if (_kind isEqualTo "munition") then { _proj setMissileTarget _target };
    GVAR(inFlight) pushBack [_proj, _target, _fuse, time, _siteId, _veh, false];
    // one missile per order
    _veh setVariable [QGVAR(pending), nil];
} else {
    // a gun round: measured for the CIWS correction, and a kill only on a near pass
    GVAR(inFlight) pushBack [_proj, _target, _fuse, time, _siteId, _veh, true, 1e9, [0, 0, 0]];
};
