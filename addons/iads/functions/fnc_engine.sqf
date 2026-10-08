#include "script_component.hpp"
/*
 * Author: JMSB
 * What this build of the engine actually has, asked rather than assumed.
 *
 * PHASE 0 OF THE PLAN IS AN ENGINE QUESTION, AND THIS IS THE HALF OF IT A
 * SCRIPT CAN ANSWER. The design rests on commands whose presence and behaviour
 * were never verified against a running game, and code that assumes them and is
 * wrong fails SILENTLY - a scheduler calling a command that does not exist
 * blinks nothing at all while every log line says it did.
 *
 * THE CONTROL TEST IS WHY THIS CAN BE TRUSTED. supportInfo's query syntax is
 * itself something this mod has never leaned on, so the sweep starts by asking
 * for a command that certainly exists. If THAT comes back empty the detector is
 * what is broken, not the engine, and every answer is reported as UNKNOWN
 * rather than as missing - because disarming a working system on the word of a
 * broken detector is the worse failure of the two.
 *
 * Cached: the answer cannot change inside a mission.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * Hash of command name -> 1 present, 0 absent, -1 unknown <HASHMAP>
 *
 * Example:
 * private _has = call jmfsb_iads_fnc_engine
 *
 * Public: No
 */

private _cached = missionNamespace getVariable [QGVAR(engineCache), createHashMap];
if (count _cached > 0) exitWith {_cached};

private _fnc_present = {
    params ["_cmd"];
    count (supportInfo format ["i:%1", _cmd])
};

private _out = createHashMap;

// The control. setDamage has been in the engine since before this mod existed;
// if the query cannot find it, the query is what is wrong.
private _detector = (["setDamage"] call _fnc_present) > 0;

{
    private _cmd = _x;
    private _answer = -1;
    if (_detector) then {
        _answer = parseNumber (([_cmd] call _fnc_present) > 0);
    };
    _out set [_cmd, _answer];
} forEach ["setVehicleRadar", "listRemoteTargets", "confirmSensorTarget", "enableVehicleSensor", "isVehicleSensorEnabled"];

_out set ["detector", parseNumber _detector];

missionNamespace setVariable [QGVAR(engineCache), _out];
_out
