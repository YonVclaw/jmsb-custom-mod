#include "..\script_component.hpp"
/*
 * Author: JMSB
 * Where a munition is going to come down, and when (F4). Wind- and drag-free -
 * ADS_IMPACT_MARGIN is what covers them.
 *
 * A guided missile goes where its target is. A shell or a bomb falls: its
 * ballistic point at the Site's height. A rocket or an unguided missile flies
 * on along its heading: where its line meets that height, or, while it is
 * still climbing, its closest approach to the Site's centre.
 *
 * Arguments:
 * 0: Munition <OBJECT>
 * 1: Site centre, ASL <ARRAY>
 *
 * Return Value:
 * [impact ASL, seconds to impact], or [] when it is not coming down near anything <ARRAY>
 *
 * Example:
 * [_round, _centre] call jmfsb_adsite_fnc_impact
 *
 * Public: No
 */

params [["_p", objNull, [objNull]], ["_centre", [0, 0, 0], [[]]]];

if (isNull _p) exitWith {[]};
private _pos = getPosASL _p;
private _v = velocity _p;
private _speed = vectorMagnitude _v;
if (_speed < 1) exitWith {[]};

// guided: where its target is
private _target = missileTarget _p;
if (!isNull _target) exitWith {
    private _at = getPosASL _target;
    [_at, (_pos distance _at) / _speed]
};

private _z = _centre # 2;
private _sim = toLower getText (configOf _p >> "simulation");
_v params ["_vx", "_vy", "_vz"];

if (_sim in ["shotshell", "shotsubmunitions"] || {_p isKindOf "BombCore"}) exitWith {
    // falling under gravity from here: z(t) = h + vz t - g t^2 / 2 = 0
    private _g = 9.81;
    private _h = (_pos # 2) - _z;
    private _disc = _vz * _vz + 2 * _g * _h;
    if (_disc < 0) exitWith {[]};
    private _t = (_vz + sqrt _disc) / _g;
    [[(_pos # 0) + _vx * _t, (_pos # 1) + _vy * _t, _z], _t]
};

// powered and unguided: on along its line
if (_vz < -0.5) then {
    private _t = ((_pos # 2) - _z) / (-_vz);
    [[(_pos # 0) + _vx * _t, (_pos # 1) + _vy * _t, _z], _t]
} else {
    // still level or climbing: its closest approach to the centre
    private _rel = _centre vectorDiff _pos;
    private _t = ((_rel vectorDotProduct _v) / (_speed * _speed)) max 0;
    [_pos vectorAdd (_v vectorMultiply _t), _t]
}
