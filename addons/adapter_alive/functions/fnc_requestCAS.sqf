#include "script_component.hpp"
/*
 * Author: JMSB
 * Asks the side's ATO for close air support over a position - the friendly
 * half of the sky, tasked from the tacpad the way the guns already are.
 *
 * ATO_REQUEST is the event ALiVE's own ATO raises for itself (mil_ato
 * fnc_ATO.sqf:5126): [type, sideText, faction, airspace, args] where args is
 * [ROE, altitude, speedMode, minWeaponState, minFuelState, range, duration,
 * targets]. An empty airspace makes the ATO pick its first; a marker name
 * makes it pick that one, and the one whose area holds the target is chosen
 * here when there is one.
 *
 * EXPERIMENTAL. The targets element is what the ATO hands its CAS flight;
 * a position array is the least it can be given. Until this has flown in a
 * live mission the provider says so on its row.
 *
 * Arguments:
 * 0: Side <SIDE>
 * 1: Target position <ARRAY>
 *
 * Return Value:
 * Requested <BOOL>
 *
 * Example:
 * [west, _pos] call jmfsb_adapter_alive_fnc_requestCAS
 *
 * Public: No
 */

params [["_side", sideUnknown, [sideUnknown]], ["_pos", [], [[]]]];

if (!GVAR(ready) || {isNil "ALIVE_eventLog"} || {_side isEqualTo sideUnknown} || {_pos isEqualTo []}) exitWith {false};

private _faction = "";
{
    _x params ["_cside", "", "_cf"];
    if (_cside isEqualTo _side) exitWith { _faction = _cf };
} forEach (call FUNC(commanders));
if (_faction isEqualTo "") exitWith {false};

private _sideText = toUpper str _side;
private _ato = objNull;
{
    if (toUpper (_x getVariable ["side", ""]) isEqualTo _sideText) exitWith { _ato = _x };
} forEach (allMissionObjects ATO_CLASS);
if (isNull _ato) exitWith {false};

// The airspace whose marker holds the target, else let the ATO choose.
private _airspace = "";
private _spaces = _ato getVariable ["airspaceAssets", []];
if (_spaces isEqualType [] && {count _spaces > HASH_KEYS}) then {
    {
        if (_x isEqualType "" && {_pos inArea _x}) exitWith { _airspace = _x };
    } forEach (_spaces select HASH_KEYS);
};

private _args = ["RED", 500, "FULL", 0.3, 0.3, 1500, 10, [+_pos]];
private _event = ["ATO_REQUEST", ["CAS", _sideText, _faction, _airspace, _args, "", ""], "JMFSB"] call ALIVE_fnc_event;
[ALIVE_eventLog, "addEvent", _event] call ALIVE_fnc_eventLog;
INFO_2("ATO_REQUEST CAS for %1 at %2",_side,mapGridPosition _pos);
true
