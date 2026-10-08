#include "script_component.hpp"
/*
 * Author: JMSB
 * Lights one radar or takes it dark. THE ONLY PLACE setVehicleRadar IS CALLED.
 *
 * ONE CALLER FOR THE ENGINE STATE, so the three numbers behind IADS_RADAR_OFF
 * and IADS_RADAR_ON are named once - see script_component.hpp - and a wrong
 * guess about them is one line to correct rather than a hunt.
 *
 * DARK IS SILENT, NOT BLIND, AND NOTHING HERE PRETENDS TO KNOW WHICH. The
 * design's first open question is whether a set with its radar forced off still
 * contributes passive detections. Its IR and visual sensors are separate
 * components and are never touched here: if the engine keeps them alive a dark
 * site still sees what comes close, and if it does not a dark site is blind.
 * This addon fakes neither answer - it forces the radar and leaves the rest of
 * the sensor suite exactly where the engine put it. The probe command says
 * which of the two this build gives you.
 *
 * LOCALITY. The vehicle may be local to a client - a player-crewed launcher, or
 * a headless client's - and a command run in the wrong place is a command that
 * quietly does nothing. Server-side AI hardware takes the direct path, which is
 * every case that matters.
 *
 * Arguments:
 * 0: The radar <OBJECT>
 * 1: Radiating <BOOL>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_radar, false] call jmfsb_iads_fnc_emit
 *
 * Public: No
 */

params [["_veh", objNull, [objNull]], ["_on", true, [true]]];

if (isNull _veh) exitWith {};

private _state = [IADS_RADAR_OFF, IADS_RADAR_ON] select _on;

if (local _veh) then {
    _veh setVehicleRadar _state;
} else {
    [_veh, _state] remoteExec ["setVehicleRadar", _veh];
};

_veh setVariable [QGVAR(radiating), _on];
// When the state last changed. The duty-cycle floor reads it to bring the set
// that has been quiet LONGEST back up, which spreads the floor around the net
// instead of pinning the same unlucky radar every tick.
_veh setVariable [QGVAR(since), CBA_missionTime];

if (GVAR(debugMarkers)) then {
    [_veh] call FUNC(marker);
};
