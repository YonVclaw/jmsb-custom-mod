#include "script_component.hpp"

// ON THE SUPPORT PAGE, THROUGH THE REGISTRY RATHER THAN BY NAME. The page has
// one way in - the adapter's supportAssets - and it now merges whatever
// providers have published themselves under a prefix. "jmfsbcas" is ours, and
// the ids FUNC(entityRow) hands out carry it, so an order comes back to this
// addon without the page or the adapter ever holding its name.
//
// Registered on EVERY machine, not only the server: the page is drawn on the
// client and reads its rows locally.
private _providers = missionNamespace getVariable [QEGVAR(adapter_alive,providers), createHashMap];
_providers set ["jmfsbcas", [FUNC(assets), FUNC(task), FUNC(sitrep)]];
missionNamespace setVariable [QEGVAR(adapter_alive,providers), _providers];

// THE SERVER FLIES THE RUNS. A request raised on a client lands here.
if (isServer) then {
    [QGVAR(request), {_this call FUNC(request)}] call CBA_fnc_addEventHandler;

    // Recall is a flag rather than a direct delete: the run watch owns the
    // aircraft's life, and two things deleting one airframe is how a
    // <NULL-object> ends up in a ledger.
    [QGVAR(abort), {
        params [["_logic", objNull, [objNull]]];
        if (isNull _logic) exitWith {};
        _logic setVariable [QGVAR(abort), true, true];
    }] call CBA_fnc_addEventHandler;
};

if (!hasInterface) exitWith {};

// WHAT THE MAN ON THE RADIO HEARS. The run is flown on the server and every
// word of it is said here, so a strike is not a thing that silently happens
// somewhere - it is called inbound, and its terminal guidance is read back so
// the JTAC knows whether his smoke was seen.
[QGVAR(inbound), {
    params [["_logic", objNull, [objNull]], ["_pos", [], [[]]], ["_delay", 0, [0]], ["_mode", "strike", [""]]];
    if (isNull _logic) exitWith {};
    if ((_logic getVariable [QGVAR(side), sideUnknown]) isNotEqualTo (side group player)) exitWith {};

    ["SUPPORT", format [
        "%1 %2 %3, %4 sec",
        _logic getVariable [QGVAR(callsign), "CAS"],
        ["inbound to", "moving to hold over"] select (_mode isEqualTo "loiter"),
        mapGridPosition _pos,
        round _delay
    ], "high"] call EFUNC(messaging,notify);
}] call CBA_fnc_addEventHandler;

// THE HANDOVER. A loitering drone is an ISR asset, not a strike, and the thing
// that makes it one is a man in the gunner's seat: the aircraft holds its own
// orbit and the drone controller gets the optics, the sensors and whatever the
// airframe is hung with. Nothing on the server decides what that ordnance is
// for any more - he does.
//
// THE MAN WHO ASKED FOR IT GETS IT, AND ONLY IF HE IS ISR. A terminal
// connection is exclusive - it drops whatever else that player was flying - so
// connecting every drone controller on the side to a new airframe would take
// the last one out from under someone mid-task. Everyone else on the side is
// told it is up there; the aircraft is on their terminal list and they can
// take it themselves when the man who called it is done.
[QGVAR(onStation), {
    params [["_logic", objNull, [objNull]], ["_veh", objNull, [objNull]], ["_caller", objNull, [objNull]]];
    if (isNull _logic || {isNull _veh}) exitWith {};
    if ((_logic getVariable [QGVAR(side), sideUnknown]) isNotEqualTo (side group player)) exitWith {};

    private _callsign = _logic getVariable [QGVAR(callsign), "CAS"];

    if (player isNotEqualTo _caller) exitWith {
        ["SUPPORT", format ["%1 on station over %2 - holding", _callsign, mapGridPosition _veh], "normal"] call EFUNC(messaging,notify);
    };

    // A DRONE IS FLOWN BY A DRONE CONTROLLER. The ISR flag is the mission's own
    // - one variable, set on the man whose job this is, and the same one the
    // hacking tablet gates on - so a rifleman who calls a loiter gets an
    // aircraft holding overhead and his ISR gets the seat.
    if !([player] call EFUNC(common,isISR)) exitWith {
        ["SUPPORT", format ["%1 on station - your ISR operator can take the feed from his terminal", _callsign], "high"] call EFUNC(messaging,notify);
    };

    // The terminal first: without it there is no feed and no seat, and the man
    // is told which of the two things he is missing rather than nothing.
    if !(player connectTerminalToUAV _veh) exitWith {
        WARNING_3("%1 could not be connected to %2's terminal - no UAV terminal, or '%3' is not a UAV",_callsign,name player,typeOf _veh);
        ["SUPPORT", format ["%1 on station - you have no UAV terminal to take it with", _callsign], "high"] call EFUNC(messaging,notify);
    };

    ["SUPPORT", format ["%1 on station - you have the gunner", _callsign], "high"] call EFUNC(messaging,notify);

    // THE SEAT ONE SECOND LATER. Connecting the terminal is what moves the
    // aircraft's crew onto this machine; asking for the seat in the same frame
    // asks an AI that is still somebody else's.
    [{
        params ["_veh", "_callsign"];
        if (isNull _veh) exitWith {};

        private _gunner = gunner _veh;
        if (isNull _gunner) then {_gunner = _veh turretUnit [0]};
        if (isNull _gunner) exitWith {
            WARNING_2("'%1' has no gunner's seat - %2 keeps the feed and nothing else",typeOf _veh,_callsign);
        };

        player remoteControl _gunner;
    }, [_veh, _callsign], 1] call CBA_fnc_waitAndExecute;
}] call CBA_fnc_addEventHandler;

// THE SEAT IS GIVEN BACK BEFORE THE AIRFRAME GOES. Recalled, shot down or out
// of patience, the run watch says so here first and deletes a beat later - a
// controller left in the turret of a vehicle that is deleted under him is a
// black screen he cannot get out of.
[QGVAR(offStation), {
    params [["_veh", objNull, [objNull]]];
    if (isNull _veh) exitWith {};
    if ((getConnectedUAV player) isNotEqualTo _veh) exitWith {};

    player remoteControl objNull;
    player connectTerminalToUAV objNull;
}] call CBA_fnc_addEventHandler;

[QGVAR(release), {
    params [["_logic", objNull, [objNull]], ["_aim", [], [[]]], ["_by", "grid", [""]]];
    if (isNull _logic) exitWith {};
    if ((_logic getVariable [QGVAR(side), sideUnknown]) isNotEqualTo (side group player)) exitWith {};

    // The word for what guided it, in the JTAC's own vocabulary - "spot" is a
    // laser, and a man who lit one wants to know it was the thing used.
    private _word = switch (_by) do {
        case "laser": {"on your spot"};
        case "smoke": {"on your smoke"};
        default {"on the grid"};
    };

    ["SUPPORT", format [
        "%1 in hot %2 - %3",
        _logic getVariable [QGVAR(callsign), "CAS"],
        _word,
        mapGridPosition _aim
    ], "high"] call EFUNC(messaging,notify);
}] call CBA_fnc_addEventHandler;
