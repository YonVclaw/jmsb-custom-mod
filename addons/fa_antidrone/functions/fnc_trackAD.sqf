#include "script_component.hpp"
/*
 * Author: YonV
 * Installs a per-frame proximity check for a PAB projectile. Detonates when
 * a UAV enters the proximity radius. Self-removes on round expiry, detonation,
 * or once the round has flown past its caliber's effective range (the
 * proximity fuze disarms past that point, same as it would with a real
 * anti-aircraft proximity fuze's limited engagement window).
 *
 * Arguments:
 * 0: Projectile <OBJECT>
 * 1: Ammo class name <STRING>
 * 2: Firer <OBJECT>
 *
 * Return Value:
 * None
 *
 * Public: No
 */

params [
    ["_proj", objNull, [objNull]],
    ["_ammo", "",      [""]],
    ["_unit", objNull, [objNull]]
];

(GVAR(AD_params) getOrDefault [_ammo, [4, 3, 0.5, 500]]) params ["_prox", "_lethal", "_dmg", "_range"];
_prox = _prox * GVAR(triggerRadiusMultiplier);
_lethal = _lethal * GVAR(lethalRadiusMultiplier);
_dmg = _dmg * GVAR(damageMultiplier);

// Programmable-airburst rounds (GVAR(programmableAB)): if the firer dialled a
// slant range (ACE self-menu / CBA keybind), the round bursts at that distance
// from the muzzle even with no drone present. 0 = off (pure proximity + HE on
// impact). Clamped to the caliber's effective range so it can never out-reach
// the fuze window.
private _burst = 0;
if (_ammo in GVAR(programmableAB) && {!isNull _unit}) then {
    _burst = (_unit getVariable [QGVAR(burstRange), 0]) max 0 min _range;
};

private _origin = getPosASL _proj;

[{
    params ["_args", "_h"];
    _args params ["_proj", "_prox", "_lethal", "_dmg", "_origin", "_range", "_burst", "_lastPos"];

    if (isNull _proj) exitWith {
        _h call CBA_fnc_removePerFrameHandler;
    };

    private _curPos = getPosASL _proj;
    private _travelled = _origin distance _curPos;

    // Programmed airburst: detonate at the dialled slant range, drone or not.
    // Interpolate the exact point on this frame's segment so a fast round can't
    // overshoot the dialled range by a frame's worth of travel.
    if (_burst > 0 && _travelled >= _burst) exitWith {
        private _burstPos = _curPos;
        private _prev = _origin distance _lastPos;
        private _span = _travelled - _prev;
        if (_span > 0) then {
            private _f = 0 max (((_burst - _prev) / _span) min 1);
            _burstPos = _lastPos vectorAdd ((_curPos vectorDiff _lastPos) vectorMultiply _f);
        };
        [_proj, _lethal, _dmg, _burstPos] call FUNC(detonateAD);
        _h call CBA_fnc_removePerFrameHandler;
    };

    if (_travelled > _range) exitWith {
        _h call CBA_fnc_removePerFrameHandler;
    };

    // Swept proximity test. These rounds fly at 1050-1176 m/s, so at 60 fps they
    // cover ~18 m between frames while the trigger radius is only 10-12 m - a
    // point-sphere check at the frame position steps clean over targets. Test the
    // whole segment flown since the last frame, and burst at the closest point of
    // approach rather than wherever the round sits when the check finally fires
    // (which can be a frame's travel past the target, outside _lethal entirely).
    private _seg = _curPos vectorDiff _lastPos;
    private _segLen2 = _seg vectorDotProduct _seg;
    private _mid = _lastPos vectorAdd (_seg vectorMultiply 0.5);
    private _search = (sqrt _segLen2) / 2 + _prox;

    private _best = -1;
    private _burstPos = _curPos;

    {
        private _p = getPosASL _x;
        private _t = if (_segLen2 > 0) then {
            0 max ((((_p vectorDiff _lastPos) vectorDotProduct _seg) / _segLen2) min 1)
        } else {
            0
        };
        private _closest = _lastPos vectorAdd (_seg vectorMultiply _t);
        private _d = _closest distance _p;
        if (_d <= _prox && {_best < 0 || _d < _best}) then {
            _best = _d;
            _burstPos = _closest;
        };
    } forEach (((ASLToAGL _mid) nearEntities [["Air", "UAV"], _search]) select {
        unitIsUAV _x
    });

    if (_best >= 0) exitWith {
        [_proj, _lethal, _dmg, _burstPos] call FUNC(detonateAD);
        _h call CBA_fnc_removePerFrameHandler;
    };

    _args set [7, _curPos];
}, 0, [_proj, _prox, _lethal, _dmg, _origin, _range, _burst, _origin]] call CBA_fnc_addPerFrameHandler;
