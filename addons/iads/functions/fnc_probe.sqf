#include "script_component.hpp"
/*
 * Author: JMSB
 * PHASE 0 OF THE PLAN, AS ONE COMMAND: the engine questions this design is
 * gated on, driven in front of you.
 *
 * WHY THIS EXISTS RATHER THAN A PARAGRAPH IN A DESIGN DOC. Four decisions in
 * the IADS plan rest on engine behaviour that cannot be read out of a config or
 * a wiki page. Every one of them was written down as "unverified", and code
 * built on an unverified guess does not fail loudly - it runs, logs success,
 * and does the opposite of what it says. Ten minutes in the editor answers all
 * four; this is those ten minutes, minus the typing.
 *
 * WHAT IT CAN AND CANNOT ANSWER. It asks the engine which commands exist
 * (P0-1), prints the shape listRemoteTargets really returns (P0-2), and drives
 * one radar through forced-on, forced-off and back to default while telling you
 * what to watch (P0-1 again, and P0-4). It CANNOT read a sensor display, so the
 * half of P0-4 that needs eyes says so plainly instead of guessing. P0-3 needs
 * two vehicles and a target and is a recipe, not a script.
 *
 * IT DRIVES THE ADDON PATH, NOT A SHORTCUT. The two forced states go through
 * FUNC(emit), which is what a mission actually runs - so a pass here is a pass
 * for the real thing, locality and all, rather than for a command typed in a
 * debug console next to it.
 *
 * Arguments:
 * 0: Command arguments <ARRAY of STRING>
 * 1: The admin who typed it <OBJECT>
 *
 * Return Value:
 * First line of the report <STRING>
 *
 * Example:
 * [[], player] call jmfsb_iads_fnc_probe
 *
 * Public: No
 */

params [["_args", [], [[]]], ["_caller", objNull, [objNull]]];

// The caller is passed in rather than closed over: a code block deferred by
// CBA_fnc_waitAndExecute runs in its own scope, so anything it needs has to
// travel with it.
private _fnc_say = {
    params ["_msg", ["_to", objNull, [objNull]]];
    diag_log text format ["[jmfsb_iads] probe: %1", _msg];
    // The mod's own reply path rather than a remoteExec written out again -
    // it already knows how to answer an admin who is the server, a client, or
    // not there at all.
    [format ["IADS PROBE: %1", _msg], _to] call EFUNC(common,debugReply);
};

// --- P0-1, and what else this build has ------------------------------------
private _has = call FUNC(engine);

if ((_has getOrDefault ["detector", 0]) isEqualTo 0) then {
    ["command detection is unreliable on this build - every answer below is unknown", _caller] call _fnc_say;
} else {
    {
        private _state = _has getOrDefault [_x, -1];
        [format ["%1: %2", _x, ["UNKNOWN", "MISSING", "present"] select (_state + 1)], _caller] call _fnc_say;
    } forEach ["setVehicleRadar", "listRemoteTargets", "confirmSensorTarget", "enableVehicleSensor", "isVehicleSensorEnabled"];
};

// --- P0-2, the datalink element shape --------------------------------------
{
    private _raw = listRemoteTargets _x;
    if (_raw isEqualTo []) then {
        [format ["%1 datalink: empty - fly something hostile past a radar and run this again", _x], _caller] call _fnc_say;
    } else {
        [format ["%1 datalink: %2 element(s), first is a %3: %4", _x, count _raw, typeName (_raw select 0), _raw select 0], _caller] call _fnc_say;
    };
} forEach [east, west, independent];

// --- P0-1 and P0-4, driven on a real set -----------------------------------
private _radar = objNull;
private _best = 1e9;

if (!isNull _caller) then {
    private _pool = GVAR(radars) select {!isNull _x && {alive _x}};
    if (_pool isEqualTo []) then {
        _pool = vehicles select {alive _x && {[typeOf _x] call FUNC(isEmitter)}};
    };

    {
        private _d = _x distance _caller;
        if (_d < _best) then {
            _best = _d;
            _radar = _x;
        };
    } forEach _pool;
};

if (isNull _radar) exitWith {
    ["no radar found to drive - put one on the map, or stand near one, and run this again", _caller] call _fnc_say;
    "probe: engine answers logged, no radar available to drive - see the RPT"
};

[format ["driving %1 at %2, %3 m away - WATCH ITS DISH AND YOUR RADAR WARNING", typeOf _radar, mapGridPosition _radar, round _best], _caller] call _fnc_say;
["forced ON for 10 s", _caller] call _fnc_say;
[_radar, true] call FUNC(emit);

[{
    params ["_radar", "_caller", "_fnc_say"];

    ["forced OFF for 10 s - anything the set still DETECTS now is this build answering dark-but-watching (P0-4)", _caller] call _fnc_say;
    [_radar, false] call FUNC(emit);

    [{
        params ["_radar", "_caller", "_fnc_say"];

        // THE ONE PLACE THE SWITCH GOES BACK TO THE AI. FUNC(emit) only ever
        // forces one of the two states, because a scheduler that hands control
        // back has stopped being a scheduler - but a probe has to leave the map
        // the way it found it.
        if (local _radar) then {
            _radar setVehicleRadar IADS_RADAR_AUTO;
        } else {
            [_radar, IADS_RADAR_AUTO] remoteExec ["setVehicleRadar", _radar];
        };

        ["back to default, the AI has the switch again. If ON and OFF looked the SAME, the two numbers in script_component.hpp are the wrong way round", _caller] call _fnc_say;
        ["P0-3 is the one nobody can script: park a radarless launcher and a search radar on the same side, fly a target in, and watch whether the launcher FIRES on the shared track or only draws it", _caller] call _fnc_say;
    }, [_radar, _caller, _fnc_say], 10] call CBA_fnc_waitAndExecute;
}, [_radar, _caller, _fnc_say], 10] call CBA_fnc_waitAndExecute;

"probe running - 20 s of driving, answers in chat and in the RPT"
