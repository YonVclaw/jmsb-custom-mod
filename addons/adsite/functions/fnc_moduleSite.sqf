#include "..\script_component.hpp"
/*
 * Author: JMSB
 * The JMSB - Air Defence Site module: its synced vehicles become one Site.
 *
 * WHERE is the module's position and WHAT is its sync - nothing on the module
 * says a side. The Site's side is its members' side, read off the hardware.
 *
 * Arguments:
 * 0: The module logic <OBJECT>
 * 1: Synchronised units <ARRAY>
 * 2: Activated <BOOL>
 *
 * Return Value: None
 *
 * Public: No
 */

params [["_logic", objNull, [objNull]], ["_units", [], [[]]], ["_activated", true, [true]]];

if (!_activated || {isNull _logic} || {!isServer}) exitWith {};

// Synced objects, and the vehicle of any synced man - a mission maker who
// synced a crewman meant his vehicle.
private _members = [];
{
    private _v = vehicle _x;
    if (_v isKindOf "AllVehicles" && {!(_v isKindOf "CAManBase")}) then { _members pushBackUnique _v };
} forEach ((synchronizedObjects _logic) + _units);

if (_members isEqualTo []) exitWith {
    WARNING_1("Air Defence Site at %1 has no vehicles synced - nothing to run",mapGridPosition _logic);
};

private _opts = createHashMap;
{
    _opts set [_x, _logic getVariable _x];
} forEach (["siteName", "radius", "link", "automation", "engageAir", "engageMunitions", "emcon",
    "burstSeconds", "shotsPerThreat", "reserveLong", "reaction", "fumble", "notices", "access"]
    select {!isNil {_logic getVariable _x}});

[_members, side (_members # 0), getPosASL _logic, _opts] call FUNC(register);
