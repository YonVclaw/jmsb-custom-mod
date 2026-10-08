#include "..\script_component.hpp"
/*
 * Author: JMSB
 * An order from a tacpad or from Zeus, on the server. The sender is checked
 * (FUNC(canControl)) before anything moves; a refusal is said back to them.
 *
 *   "automation" [bool]             the Site engages by itself, or waits for orders
 *   "set"        [key, value]       one operation value (radius, shotsPerThreat, reserveLong,
 *                                   reaction, fumble, burstSeconds, engageAir, engageMunitions, emcon)
 *   "radar"      [netId, "on"|"off"|"auto"]   one radar pinned lit, held dark, or back to the Site
 *   "hold"       [netId, bool]      a member holds fire (a vehicle override)
 *   "engage"     [track key, netId] a chosen weapon onto a chosen track - the manual intercept
 *   "strike"     [position ASL, netId]  a member's surface weapon onto a ground point
 *
 * Arguments:
 * 0: Site id <STRING>
 * 1: Action <STRING>
 * 2: Arguments <ARRAY>
 * 3: Sender <OBJECT>
 *
 * Return Value: None
 *
 * Public: No
 */

params [["_id", "", [""]], ["_action", "", [""]], ["_args", [], [[]]], ["_from", objNull, [objNull]]];

if (!isServer) exitWith {};
private _site = GVAR(sites) get _id;
if (isNil "_site") exitWith {};
private _row = (missionNamespace getVariable [QGVAR(board), []]) param [(missionNamespace getVariable [QGVAR(board), []]) findIf {(_x # 0) isEqualTo _id}, []];
if !([_from, _row] call FUNC(canControl)) exitWith {
    [format ["%1: not yours to command", _site get "name"], _from] call EFUNC(common,debugReply);
};

private _say = { [format ["%1: %2", _site get "name", _this], _from] call EFUNC(common,debugReply) };

switch (_action) do {
    case "automation": {
        _site set ["automation", _args param [0, true]];
        format ["automation %1", ["off", "on"] select (_site get "automation")] call _say;
    };
    case "set": {
        _args params [["_key", ""], ["_value", 0]];
        private _ok = switch (_key) do {
            case "radius": { _site set [_key, (_value max 50) min 20000]; true };
            case "shotsPerThreat": { _site set [_key, round ((_value max 1) min 6)]; true };
            case "reserveLong";
            case "fumble": { _site set [_key, (_value max 0) min 1]; true };
            case "reaction": { _site set [_key, (_value max 0) min 15]; true };
            case "burstSeconds": { _site set [_key, (_value max 3) min 300]; true };
            case "engageAir";
            case "engageMunitions": { _site set [_key, _value isEqualTo true]; true };
            case "emcon": { if (_value in ["auto", "silent", "burst"]) then { _site set [_key, _value]; true } else { false } };
            default { false };
        };
        if (_ok) then { format ["%1 set", _key] call _say };
    };
    case "radar": {
        _args params [["_net", ""], ["_mode", "auto"]];
        private _r = objectFromNetId _net;
        if !(_r in (_site get "members")) exitWith {};
        _r setVariable [QEGVAR(iads,heldOff), _mode isEqualTo "off"];
        _r setVariable [QEGVAR(iads,pinned), _mode isEqualTo "on"];
        if (_mode isNotEqualTo "auto") then { [_r, _mode isEqualTo "on"] call EFUNC(iads,emit) };
        // a radar the crew has set by hand is not the Site's to move until set back to auto
        _r setVariable [QGVAR(manualRadar), _mode isNotEqualTo "auto"];
        format ["radar %1", _mode] call _say;
    };
    case "hold": {
        _args params [["_net", ""], ["_hold", true]];
        private _v = objectFromNetId _net;
        if !(_v in (_site get "members")) exitWith {};
        _v setVariable [QGVAR(hold), _hold, true];
    };
    case "engage": {
        _args params [["_key", ""], ["_net", ""]];
        private _track = (_site get "tracks") get _key;
        private _veh = objectFromNetId _net;
        if (isNil "_track" || {!(_veh in (_site get "members"))}) exitWith { "that track or weapon is gone" call _say };
        _track params ["_target", "_kind"];
        private _dist = _veh distance _target;
        private _entries = (([_veh] call FUNC(profile)) # 0) select {
            !((_x # 7) in [ROLE_SURFACE, ROLE_SENSOR]) && {_dist <= (_x # 5)} && {_dist >= (_x # 6)} && {(_veh magazineTurretAmmo [_x # 2, _x # 0]) > 0}
        };
        if (_entries isEqualTo []) exitWith { "that weapon cannot reach it" call _say };
        private _c = _site get "committed";
        _c set [_key, (_c getOrDefault [_key, []]) + [_veh]];
        (_site get "busy") set [hashValue _veh, _target];
        [_veh, _entries # 0, _target, _kind, _id] spawn FUNC(engage);
        "engaging" call _say;
    };
    case "strike": {
        _args params [["_pos", [], [[]]], ["_net", ""]];
        private _veh = objectFromNetId _net;
        if (_pos isEqualTo [] || {!(_veh in (_site get "members"))}) exitWith {};
        ([_veh, _pos] call FUNC(strike)) call _say;
    };
};
