#include "..\script_component.hpp"
/*
 * Author: JMSB
 * Refreshes one Site's picture: the hostile aircraft it can see and the
 * munitions coming down inside its protected area (F1, F4).
 *
 * AIRCRAFT are hostile by the sides' own relations, never a side setting, and
 * have to be SEEN: the Site's side knows about it, or a member's lit radar
 * holds it inside its range.
 *
 * MUNITIONS are found the way jmfsb_aps finds them - nearObjects on the server,
 * which sees a remote shooter's rounds as well as its own - and are a threat
 * only while their predicted impact (FUNC(impact)) is inside the protected
 * area. A round fired by a friendly side is never one; a shell landing clear
 * is not one either, and costs nothing.
 *
 * Arguments:
 * 0: Site <HASHMAP>
 *
 * Return Value: None
 *
 * Public: No
 */

params [["_site", createHashMap, [createHashMap]]];

private _side = _site get "side";
private _centre = _site get "centre";
private _here = ASLToAGL _centre;
private _radius = _site get "radius";
private _tracks = _site get "tracks";
private _now = CBA_missionTime;

private _members = (_site get "members") select {!isNull _x && {alive _x}};
_site set ["members", _members];
if (_members isEqualTo []) exitWith { { _tracks deleteAt _x } forEach (keys _tracks) };

// how far this Site can reach at all, and what its radars can hold
private _reach = 0;
private _radars = [];
{
    ([_x] call FUNC(profile)) params ["_entries", "_radar"];
    { _reach = _reach max (_x # 5) } forEach (_entries select {(_x # 7) isNotEqualTo ROLE_SURFACE});
    if (_radar > 0) then { _radars pushBack [_x, _radar] };
} forEach _members;

private _seen = [];

// ---- aircraft ----------------------------------------------------------------
if ((_site get "engageAir") && _reach > 0) then {
    {
        private _t = _x;
        if (!alive _t || {isTouchingGround _t && {speed _t < 15}}) then { continue };
        if !([_side, side group _t] call BIS_fnc_sideIsEnemy) then { continue };
        private _held = (_side knowsAbout _t) > 1 || {
            _radars findIf {
                _x params ["_r", "_range"];
                isVehicleRadarOn _r && {(_r distance _t) <= _range}
            } > -1
        };
        if (!_held) then { continue };
        private _key = hashValue _t;
        private _old = _tracks getOrDefault [_key, []];
        _tracks set [_key, [_t, "air", typeOf _t, getPosASL _t, (_t distance _here) / ((speed _t / 3.6) max 1), _old param [5, _now]]];
        _seen pushBack _key;
    } forEach (_here nearEntities [["Air"], _reach]);
};

// ---- munitions ---------------------------------------------------------------
if (_site get "engageMunitions") then {
    private _found = [];
    { _found append (_here nearObjects [_x, _reach + ADS_TRACK_MARGIN]) } forEach ADS_MUNITIONS;
    {
        private _p = _x;
        if (_p getVariable [QGVAR(interceptor), false]) then { continue };
        (getShotParents _p) params [["_from", objNull], ["_by", objNull]];
        private _shooter = [_from, _by] select (isNull _from);
        if (!isNull _shooter && {!([_side, side group _shooter] call BIS_fnc_sideIsEnemy)}) then { continue };

        private _hit = [_p, _centre] call FUNC(impact);
        if (_hit isEqualTo []) then { continue };
        _hit params ["_at", "_tti"];
        if (_tti <= 0 || {(_at distance2D _centre) > _radius + ADS_IMPACT_MARGIN}) then { continue };

        private _key = hashValue _p;
        private _old = _tracks getOrDefault [_key, []];
        _tracks set [_key, [_p, "munition", typeOf _p, _at, _tti, _old param [5, _now]]];
        _seen pushBack _key;
    } forEach _found;
};

// what is gone, landed, or no longer coming here leaves the picture
{
    if !(_x in _seen) then { _tracks deleteAt _x };
} forEach (keys _tracks);
