#include "..\script_component.hpp"
/*
 * Author: JMSB
 * The proximity fuse (F1), every frame, for every interceptor in flight.
 *
 * Inside the fuse distance - the interceptor ammo's own blast radius - both go:
 * the interceptor detonates, and a munition target detonates where it is, in
 * the air, short of what it was falling on. An aircraft is left to the game's
 * own damage from the interceptor's blast. This is jmfsb_aps' intercept, which
 * already kills rockets and missiles short of a hull, done on the way in.
 *
 * A GUN ROUND that passes its target is measured: where it went past, as a
 * vector, folded into the gun's aim correction (F7) - so the next burst leads
 * by what this one actually missed by.
 *
 * Arguments: None
 *
 * Return Value: None
 *
 * Public: No
 */

if (GVAR(inFlight) isEqualTo []) exitWith {};

private _keep = [];
{
    _x params ["_proj", "_target", "_fuse", "_t0", "_siteId", "_veh", "_gun", ["_closest", 1e9], ["_vec", [0, 0, 0]]];

    if (isNull _proj || {!alive _target} || {time - _t0 > ADS_FUSE_TIMEOUT}) then {
        // a MISSILE gone without a kill frees its commitment for another weapon;
        // a gun's rounds do not - the gun is still on the target until FUNC(engage) ends
        if (!_gun && {alive _target}) then {
            private _site = GVAR(sites) getOrDefault [_siteId, createHashMap];
            private _c = _site getOrDefault ["committed", createHashMap];
            private _key = hashValue _target;
            _c set [_key, (_c getOrDefault [_key, []]) - [_veh]];
        };
        // a gun round's pass, if it got close enough to say anything
        if (_gun && _closest < 200 && {!isNull _veh}) then {
            private _fix = _veh getVariable [QGVAR(aimFix), [0, 0, 0]];
            _veh setVariable [QGVAR(aimFix), (_fix vectorMultiply 0.5) vectorDiff (_vec vectorMultiply 0.5)];
        };
        continue;
    };

    private _rel = (getPosASL _target) vectorDiff (getPosASL _proj);
    private _d = vectorMagnitude _rel;

    if (_d <= _fuse) then {
        triggerAmmo _proj;
        if !(_target isKindOf "AllVehicles") then { triggerAmmo _target };
        INFO_3("intercept: %1 on %2 at %3 m",typeOf _proj,typeOf _target,round _d);
        continue;
    };

    if (_gun) then {
        // still closing: remember the nearest pass and where it was
        if (_d < _closest) then {
            _x set [7, _d];
            _x set [8, _rel vectorMultiply -1];
            _keep pushBack _x;
        } else {
            // opening again: it has passed - measured above on the next look
            _x set [3, -1e9];
            _keep pushBack _x;
        };
        continue;
    };
    _keep pushBack _x;
} forEach GVAR(inFlight);
GVAR(inFlight) = _keep;
