#include "..\script_component.hpp"
/*
 * Author: JMSB
 * `#jmfsb adsite`: every Site - members and their roles, rounds, radars, what is
 * tracked and what is committed - to whoever asked, and to the RPT.
 *
 * Arguments:
 * 0: Who asked <OBJECT>
 *
 * Return Value: None
 *
 * Public: No
 */

params [["_caller", objNull, [objNull]]];

if (count GVAR(sites) == 0) exitWith { ["air defence: no Sites", _caller] call EFUNC(common,debugReply) };

{
    private _site = _y;
    private _sid = _x;
    private _members = (_site get "members") apply {
        private _p = [_x] call FUNC(profile);
        format ["%1 %2%3", typeOf _x, (_p # 2) joinString "/", ["", " RADAR"] select (isVehicleRadarOn _x)]
    };
    private _tracks = values (_site get "tracks");
    private _air = {(_x # 1) isEqualTo "air"} count _tracks;
    private _line = format ["%1 %2 (%3, %4, link '%5'): %6 | tracking %7 air, %8 rounds | %9 committed | %10 in flight",
        _sid, _site get "name", _site get "side", ["MANUAL", "AUTO"] select (_site get "automation"), _site get "link",
        _members joinString ", ", _air, count _tracks - _air, count (_site get "committed"),
        {(_x # 4) isEqualTo _sid} count GVAR(inFlight)];
    INFO_1("%1",_line);
    [_line, _caller] call EFUNC(common,debugReply);
} forEach GVAR(sites);
