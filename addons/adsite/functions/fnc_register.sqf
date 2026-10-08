#include "..\script_component.hpp"
/*
 * Author: JMSB
 * Makes a Site out of vehicles and starts the system if it is not running.
 *
 * A Site is a hashmap on the server:
 *   id, name, side, centre (ASL), radius, link,
 *   members      [vehicle, ...] - alive ones; the dead are pruned each beat
 *   tracks       hashValue -> [object, kind ("air"|"munition"), class, impact/position ASL, time to impact, first seen]
 *   committed    hashValue of the target -> [vehicle, ...] already engaging it
 *   busy         hashValue of the vehicle -> the object it is engaging
 *   (an object cannot be a hashmap key - hashValue is its key, and the object rides in the value)
 *   automation, engageAir, engageMunitions, emcon, burstSeconds, shotsPerThreat,
 *   reserveLong, reaction, fumble, notices, access   (the module's operation values)
 *   live         radiating notice given
 *   lastIncoming time of the last incoming notice
 *   cuedUntil    silent-mode radars lit until
 *
 * Arguments:
 * 0: Member vehicles <ARRAY>
 * 1: Side <SIDE>
 * 2: Centre, ASL <ARRAY>
 * 3: Operation values from the module <HASHMAP> (missing keys take the defaults)
 *
 * Return Value:
 * Site id <STRING>
 *
 * Example:
 * [[_radar, _launcher], east, getPosASL _radar, createHashMap] call jmfsb_adsite_fnc_register
 *
 * Public: Yes
 */

params [["_members", [], [[]]], ["_side", sideUnknown, [sideUnknown]], ["_centre", [], [[]]], ["_opts", createHashMap, [createHashMap]]];

if (!isServer) exitWith {""};
_members = _members select {!isNull _x && {alive _x}};
if (_members isEqualTo []) exitWith {""};

GVAR(nextSite) = GVAR(nextSite) + 1;
private _id = format ["S%1", GVAR(nextSite)];
private _name = _opts getOrDefault ["siteName", ""];
if (_name isEqualTo "") then { _name = format ["SITE %1", mapGridPosition ASLToAGL _centre] };

private _site = createHashMapFromArray [
    ["id", _id], ["name", toUpper _name], ["side", _side], ["centre", _centre],
    ["radius", _opts getOrDefault ["radius", 800]],
    ["link", _opts getOrDefault ["link", ""]],
    ["members", _members],
    ["tracks", createHashMap], ["committed", createHashMap], ["busy", createHashMap],
    ["automation", _opts getOrDefault ["automation", true]],
    ["engageAir", _opts getOrDefault ["engageAir", true]],
    ["engageMunitions", _opts getOrDefault ["engageMunitions", true]],
    ["emcon", _opts getOrDefault ["emcon", "auto"]],
    ["burstSeconds", _opts getOrDefault ["burstSeconds", 20]],
    ["shotsPerThreat", (_opts getOrDefault ["shotsPerThreat", 2]) max 1],
    ["reserveLong", ((_opts getOrDefault ["reserveLong", 0.5]) max 0) min 1],
    ["reaction", (_opts getOrDefault ["reaction", 2]) max 0],
    ["fumble", ((_opts getOrDefault ["fumble", 0.1]) max 0) min 1],
    ["notices", _opts getOrDefault ["notices", true]],
    ["access", _opts getOrDefault ["access", "near"]],
    ["live", false], ["lastIncoming", -1e9], ["cuedUntil", -1e9], ["burstAt", -1e9], ["burstIndex", 0]
];

{
    private _veh = _x;
    // the long-range reserve is a fraction of what each launcher STARTED with
    {
        _x params ["_path", "", "_mag", "", "", "", "", "_role"];
        if (_role isEqualTo ROLE_LONG) then {
            _veh setVariable [format ["%1_%2", QGVAR(full), _mag], {_x isEqualTo _mag} count (_veh magazinesTurret _path)];
        };
    } forEach (([_veh] call FUNC(profile)) # 0);
    // public: Zeus's context action and the tacpad look it up on the client
    _veh setVariable [QGVAR(site), _id, true];
    // The interceptor is caught as it leaves the tube (FUNC(fired)). Server-side:
    // the Site's vehicles are server AI.
    if (isNil {_x getVariable QGVAR(firedEh)}) then {
        _x setVariable [QGVAR(firedEh), _x addEventHandler ["Fired", {_this call FUNC(fired)}]];
    };
} forEach _members;

GVAR(sites) set [_id, _site];
INFO_4("Site %1 (%2) up for %3 with %4 member(s)",_id,_site get "name",_side,count _members);

[] call FUNC(start);
_id
