#include "script_component.hpp"
/*
 * Author: JMSB
 * One debug marker for one radar - where it is, what it is, and whether it is
 * radiating right now.
 *
 * FOR TUNING A MISSION, NOT FOR PLAYING ONE, and the module attribute says so:
 * this draws the players a map of exactly the thing they are meant to be
 * hunting for. Off unless somebody turned it on.
 *
 * GLOBAL MARKERS, because the server is what runs this and a marker it creates
 * locally is a marker nobody can see.
 *
 * Updated when the set flips rather than on a timer of its own. A mobile
 * launcher marker will therefore sit where it was when it last changed state,
 * which is the right trade for a debug aid: a second per-frame handler keeping
 * dots in step with vehicles is a cost the mission pays for nothing.
 *
 * Arguments:
 * 0: The radar <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_radar] call jmfsb_iads_fnc_marker
 *
 * Public: No
 */

params [["_veh", objNull, [objNull]]];

if (isNull _veh) exitWith {};

private _name = _veh getVariable [QGVAR(marker), ""];

if (_name isEqualTo "") then {
    GVAR(markerSeq) = GVAR(markerSeq) + 1;
    _name = format ["jmfsb_iads_%1", GVAR(markerSeq)];
    createMarker [_name, getPosATL _veh];
    // ONE GLOBAL UPDATE, AND IT IS THE LAST LINE OF THIS FUNCTION. A global
    // setMarker* pushes the marker's WHOLE state to every machine, so a run of
    // them is the same broadcast several times over. Everything set here is set
    // locally - type and size included - and the setMarkerText at the bottom
    // carries all of it out in one go. That block is unconditional and directly
    // below, so there is no path where a marker is created and never sent.
    _name setMarkerTypeLocal "mil_triangle";
    _name setMarkerSizeLocal [0.7, 0.7];
    _veh setVariable [QGVAR(marker), _name];
};

private _on = _veh getVariable [QGVAR(radiating), false];

_name setMarkerPosLocal (getPosATL _veh);
_name setMarkerColorLocal (["ColorBlack", "ColorGreen"] select _on);
_name setMarkerText format ["%1 %2", typeOf _veh, ["DARK", "LIT"] select _on];
