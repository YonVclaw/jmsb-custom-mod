#include "script_component.hpp"
/*
 * Author: JMSB
 * Builds one battery: a radar, and launchers set back from it.
 *
 * Everything is crewed and PROFILED. An uncrewed static is scenery - a SAM
 * with nobody on it never fires - and an unprofiled one is a live AI sitting
 * on the server for the whole mission whether anybody is near it or not.
 *
 * The site is recorded by POSITION, not by object. Profiling deletes the
 * hardware and ALiVE makes new objects when a player comes near, so anything
 * holding object references would be pointing at deleted vehicles within
 * minutes. A site is a place.
 *
 * Arguments:
 * 0: Where <ARRAY>
 * 1: Owning side <SIDE>
 * 2: [radar, launchers, manpad, mag] <ARRAY>
 * 3: The side's TAOR markers <ARRAY>
 * 4: Markers never to build on <ARRAY>
 * 5: Man classes for the security groups <ARRAY>
 *
 * Return Value:
 * It was built <BOOL>
 *
 * Public: No
 */

params [["_pos", [], [[]]], ["_side", sideUnknown, [sideUnknown]], ["_kit", [], [[]]],
        ["_taor", [], [[]]], ["_black", [], [[]]], ["_kinds", [], [[]]]];

_kit params ["_radarCls", "_launchers"];

// The common pre-spawn gate, against the markers the planner handed over -
// whatever upstream computed, nothing of this side's stands up outside them.
// FALSE, not nothing - the planner negates this return, and `!nil` is a
// type error that killed the whole side's planning loop on first refusal.
if (!([_side, _pos, "AA battery", _taor, _black] call EFUNC(common,taorGate))) exitWith {false};

if (_pos isEqualTo [] || _radarCls isEqualTo "") exitWith {false};

private _made = [];

private _radar = createVehicle [_radarCls, _pos, [], 0, "CAN_COLLIDE"];
if (isNull _radar) exitWith {
    WARNING_1("radar '%1' would not create",_radarCls);
    false
};
_radar setDir random 360;
_radar setVectorUp surfaceNormal (getPosATL _radar);
_made pushBack _radar;

// Launchers stand off the radar, on their own patch of open ground.
private _clear = 6 max GVAR(openGround);
private _spots = [[], round GVAR(launchers), createHashMapFromArray [
    ["centre", _pos],
    ["minRange", AD_LAUNCH_MIN],
    ["maxRange", AD_LAUNCH_MAX],
    ["footprint", 10],
    ["clearRadius", _clear],
    ["maxSlope", 0.12],
    ["separation", 60],
    ["avoid", [_pos]],
    ["avoidRadius", AD_LAUNCH_MIN],
    ["blacklist", _black]
]] call EFUNC(common,findSite);

// The launchers reach up to AD_LAUNCH_MAX from the radar, so a battery legally
// inside the TAOR can still throw hardware over the boundary. Same rule.
if (_taor isNotEqualTo []) then {
    _spots = _spots select {
        private _spot = _x;
        (_taor findIf {_spot inArea _x}) > -1
    };
};

{
    private _cls = selectRandom _launchers;
    private _l = createVehicle [_cls, _x, [], 0, "CAN_COLLIDE"];
    if (isNull _l) then {continue};
    _l setDir (_x getDir _pos);
    _l setVectorUp surfaceNormal (getPosATL _l);
    _made pushBack _l;
} forEach _spots;

// Crew, then profile. An empty static never fires - and the crew DIFFERS BY
// KIND. The vanilla SAM and radar systems are AUTONOMOUS DRONE TURRETS
// (isUav): createVehicleCrew seats their own UAV AI, and that AI must STAY
// IN ITS OWN GROUP - joining it to an infantry group is what switched the
// autonomous systems off and left "batteries without crew". Only manned
// statics get men, and only their crews join the site's group.
private _grp = createGroup [_side, true];
{
    createVehicleCrew _x;
} forEach _made;

// A frame later: createVehicleCrew's units are not queryable in the same frame,
// and profiling a crewless vehicle hands ALiVE nothing to virtualise.
[{
    params ["_made", "_grp", "_side", "_pos", "_kinds"];

    private _live = _made select {!isNull _x};
    if (_live isEqualTo []) exitWith {};

    // Crews are only queryable here, a frame on. A DRONE turret (isUav) that
    // is still empty gets another createVehicleCrew - its own AI crewman is
    // the only thing that can run it, and a soldier pushed into a UAV seat is
    // exactly the wrong fix. A MANNED static that is still empty gets a man:
    // the faction's own when the site has any, the side's plain soldier
    // otherwise. Drone crews stay in their own groups; only men join the
    // site's group.
    private _crewed = 0;
    {
        private _isDrone = getNumber (configOf _x >> "isUav") > 0;
        if ((crew _x) isEqualTo []) then {
            if (_isDrone) then {
                createVehicleCrew _x;
            } else {
                private _man = if (_kinds isNotEqualTo []) then {selectRandom _kinds} else {
                    switch (_side) do {
                        case west: {"B_Soldier_F"};
                        case independent: {"I_Soldier_F"};
                        default {"O_Soldier_F"};
                    }
                };
                private _g = _grp createUnit [_man, getPos _x, [], 0, "CAN_COLLIDE"];
                _g moveInGunner _x;
            };
        };
        if (!_isDrone) then { (crew _x) joinSilent _grp };
        if ((crew _x) isNotEqualTo []) then { _crewed = _crewed + 1 };
    } forEach _live;
    INFO_3("battery for %1: %2 of %3 pieces crewed",_side,_crewed,count _live);

    // NEVER OFFERED TO THE PROFILER. THIS IS THE "AA SITE WITH NO AI".
    //
    // The log said "4 of 4 pieces crewed" and then "would not profile - it
    // stays live", and the site stood there empty anyway. That warning was
    // reading an empty return as "nothing happened", which is the same
    // mistake that was eating the drones: ALIVE_fnc_createProfilesFromUnitsRuntime
    // does deleteVehicle to what it is handed unless every unit is on ALiVE's
    // own blacklist. A profile REPLACES the object - that is what
    // virtualisation is. Static air defence has nowhere to walk to and no
    // reason to be a record, so it is never handed over.
    //
    // ALiVE's own opt-out, asked for through the adapter - the variable is
    // ALiVE's name and this addon is not allowed to know it. Hardware, crews
    // and their groups, so any OTHER ALiVE pass over the map leaves the site
    // alone too; without it, "it stays live" was a claim nothing had actually
    // told ALiVE about.
    {[_x] call EFUNC(adapter_alive,profileIgnore)} forEach _live;
    [_grp] call EFUNC(adapter_alive,profileIgnore);

    INFO_2("battery up for %1 at %2",_side,mapGridPosition _pos);
    // jmfsb_adsite makes it a Site: one picture, layered engagement, notices,
    // the tacpad panel. A local event - adsite listens on the server, where this runs.
    [QGVAR(batteryUp), [_live, _side, AGLToASL _pos]] call CBA_fnc_localEvent;
}, [_made, _grp, _side, _pos, _kinds]] call CBA_fnc_execNextFrame;

// Guards, if the mission asked for any. Their own faction's men, so they look
// like the force that owns the site.
[_pos, _side, _kinds, _black] call FUNC(buildSecurity);

// The pieces themselves join the rearm pool - a battery that goes silent
// after its first salvo is a one-round site nobody meant to build.
GVAR(hardware) append _made;

// Place, not objects - see the docblock.
GVAR(sites) pushBack [+_pos, _side];
missionNamespace setVariable [QGVAR(sites), GVAR(sites), true];

true
