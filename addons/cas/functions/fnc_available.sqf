#include "script_component.hpp"
/*
 * Author: JMSB
 * What this asset is doing, as one token - and it is the ONLY place that
 * question is answered.
 *
 * The support page asks it to colour a row, FUNC(task) asks it to refuse an
 * order, and the run asks it on the way out. Three readers of one rule, so a
 * row that says IDLE cannot be a row the tasking then refuses - which is the
 * classic support-panel bug and it is a state duplication every time.
 *
 * EXPENDED IS A STATE, NOT A DISAPPEARANCE. An asset that has burnt its last
 * airframe stays on the page saying so. A row that silently vanishes reads as
 * a broken mod; a row that reads EXPENDED tells the player what happened to
 * the aircraft he watched go down.
 *
 * Arguments:
 * 0: The module logic <OBJECT>
 *
 * Return Value:
 * 0: Can be tasked right now <BOOL>
 * 1: Status token <STRING> - "idle", "expended", "cooldown", or the run's own
 * 2: Why not, "" when it can <STRING>
 *
 * Public: No
 */

params [["_logic", objNull, [objNull]]];

if (isNull _logic) exitWith {[false, "gone", "that asset is gone"]};

private _max = _logic getVariable [QGVAR(airframes), 3];
private _lost = _logic getVariable [QGVAR(lost), 0];

// 0 is unlimited - written that way on the module tooltip, honoured here.
if (_max > 0 && _lost >= _max) exitWith {
    [false, "expended", format ["%1 has no airframes left", _logic getVariable [QGVAR(callsign), "CAS"]]]
};

private _status = _logic getVariable [QGVAR(status), "idle"];
if (_status isNotEqualTo "idle" && _status isNotEqualTo "cooldown") exitWith {
    [false, _status, "that aircraft is already on a task"]
};

private _readyAt = _logic getVariable [QGVAR(readyAt), 0];
if (CBA_missionTime < _readyAt) exitWith {
    [false, "cooldown", format ["%1 is rearming - %2s", _logic getVariable [QGVAR(callsign), "CAS"], ceil (_readyAt - CBA_missionTime)]]
};

[true, "idle", ""]
