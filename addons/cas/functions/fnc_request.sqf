#include "script_component.hpp"
/*
 * Author: JMSB
 * One CAS run, server side: the aircraft appears on the ingress heading, flies
 * the target, releases, and leaves on the egress heading.
 *
 * THE GEOMETRY IS THE PLAYER'S AND IT IS THE WHOLE FEATURE. Ingress and egress
 * are POINTS ON THE MAP - the aircraft appears at the one and leaves towards
 * the other - so a section puts the run-in behind the ridge they are looking
 * at rather than converting it into a heading first. Either may be unset:
 * ingress then comes from the caller's side of the target, egress carries
 * straight on through.
 *
 * THE RUN-IN DISTANCE IS A FLOOR, NOT A FIXED RANGE. An ingress point dropped
 * two hundred metres off the target is an aircraft that appears already on top
 * of it with no room to level off or line up, so a point closer than the
 * module's run-in distance is pushed back along its own bearing until there
 * is. The player still chooses the DIRECTION the strike comes from, which is
 * what he actually cared about.
 *
 * THE AI IS NOT FLYING THIS AND IS NOT SHOOTING IT. CARELESS, BLUE, targeting
 * off, driver locked: the group follows two MOVE waypoints and nothing else,
 * and FUNC(fireAt) is the only thing that pulls a trigger. Arma's air AI given
 * a SAD waypoint orbits an objective without engaging often enough that every
 * support mod in existence has stopped asking it - Simplex included, for the
 * same reason and by the same means.
 *
 * A LOITER IS THE SAME FLIGHT WITH A DIFFERENT ENDING. Ingress is flown the
 * same way and for the same reason, but instead of two MOVEs through the
 * target the aircraft holds an orbit over it, nothing is released, and the
 * gunner's seat is handed to the drone controller who asked for it - see the
 * on-station event and XEH_postInit. A drone told to hold overhead used to fly
 * a strike and leave, which is neither of the things the word means.
 *
 * IT IS A REAL AIRCRAFT AND IT CAN BE LOST. Killed is wired to FUNC(killed),
 * which is what makes the module's airframe count mean anything and what makes
 * the air defence on the ridge worth putting there.
 *
 * Arguments:
 * 0: The module logic <OBJECT>
 * 1: Target grid <ARRAY> - ATL
 * 2: Ingress position, [] for auto <ARRAY> - ATL
 * 3: Egress position, [] for auto <ARRAY> - ATL
 * 4: Who asked <OBJECT>
 * 5: Store to use, "" for the heaviest thing aboard <STRING> (optional, default "")
 * 6: "strike" or "loiter" <STRING> (optional, default "strike")
 *
 * Return Value: None
 *
 * Public: No
 */

params [["_logic", objNull, [objNull]], ["_pos", [], [[]]], ["_ingress", [], [[]]], ["_egress", [], [[]]], ["_caller", objNull, [objNull]], ["_mag", "", [""]], ["_mode", "strike", [""]]];

if (!isServer || {isNull _logic} || {_pos isEqualTo []}) exitWith {};

private _callsign = _logic getVariable [QGVAR(callsign), "CAS"];
private _delay = _logic getVariable [QGVAR(spawnDelay), 30];

_logic setVariable [QGVAR(status), "inbound", true];

private _fromText = ["auto", mapGridPosition _ingress] select (_ingress isNotEqualTo []);
INFO_4("%1 tasked to %2 (%3), ingress %4",_callsign,mapGridPosition _pos,_mode,_fromText);
[QGVAR(inbound), [_logic, _pos, _delay, _mode]] call CBA_fnc_globalEvent;

[{
    params ["_logic", "_pos", "_ingress", "_egress", "_caller", "_mag", "_mode"];

    // The module may have been deleted, or the asset expended by another
    // request, while the response delay was running.
    if (isNull _logic) exitWith {};

    private _cls = _logic getVariable [QGVAR(cls), ""];
    private _side = _logic getVariable [QGVAR(side), west];
    private _dist = _logic getVariable [QGVAR(spawnDistance), 4000];
    private _alt = _logic getVariable [QGVAR(altitude), 700];
    private _radius = _logic getVariable [QGVAR(searchRadius), 300];
    private _callsign = _logic getVariable [QGVAR(callsign), "CAS"];

    // Capped at what the airframe can actually do, so a module asking 900 km/h
    // of a loitering UCAV gets the UCAV's best rather than a velocity write the
    // flight model spends the whole run fighting.
    private _speed = ((_logic getVariable [QGVAR(speed), 400]) / 3.6)
        min (getNumber (configFile >> "CfgVehicles" >> _cls >> "maxSpeed") / 3.6);

    // WHERE IT COMES FROM. An unset ingress point puts the aircraft on the
    // caller's side of the target - the direction a man in contact would ask
    // for without being asked, and the one that does not fly the strike over
    // his own head. A caller who has since died or disconnected falls back to
    // due north, which is arbitrary but never null.
    private _start = if (_ingress isNotEqualTo []) then {+_ingress} else {
        private _bearing = if (isNull _caller) then {0} else {_pos getDir _caller};
        _pos getPos [_dist, _bearing]
    };

    // The run-in floor: a point too close leaves no room to line up, so it is
    // pushed back along its own bearing rather than refused. Direction is what
    // the player chose; distance is what the airframe needs.
    if (_start distance2D _pos < _dist) then {
        _start = _pos getPos [_dist, _pos getDir _start];
    };

    // WHERE IT GOES. Unset egress carries straight on through the target on
    // the ingress line, which is what an aircraft does when nobody has told it
    // otherwise.
    private _end = if (_egress isNotEqualTo []) then {+_egress} else {
        _pos getPos [_dist, (_start getDir _pos)]
    };

    // Far enough out that the aircraft is clear of the target area before it
    // despawns - an egress point picked just past the objective would have it
    // vanish in front of the section that called it.
    if (_end distance2D _pos < _dist) then {
        _end = _pos getPos [_dist, _pos getDir _end];
    };

    // ATL THROUGHOUT, AND THAT IS THE RULE FOR THIS WHOLE ADDON. Attack
    // Altitude means height above the ground under the aircraft, which is the
    // only reading of it a man on the radio would expect - "come in at seven
    // hundred" over a ridge means seven hundred over the ridge, not seven
    // hundred over the sea with the ridge at six-fifty. Every position that
    // crosses a function boundary here is ATL: these two, the aim point out of
    // FUNC(acquire), and the dummy FUNC(fireAt) hangs on it.
    _start set [2, _alt];
    _end set [2, _alt];

    private _ingressHdg = _start getDir _pos;

    private _grp = createGroup [_side, true];
    private _veh = createVehicle [_cls, _start, [], 0, "FLY"];

    if (isNull _veh) exitWith {
        WARNING_2("%1 could not put '%2' in the air - run abandoned",_callsign,_cls);
        _logic setVariable [QGVAR(status), "idle", true];
        if (!isNull _grp) then {deleteGroup _grp};
    };

    _veh setDir _ingressHdg;
    _veh setPosATL _start;
    _veh setVectorUp [0, 0, 1];
    _veh setVelocityModelSpace [0, _speed, 0];
    // flyInHeight, not flyInHeightASL. The ASL form pins the aircraft to one
    // height above SEA for the whole run, which over rising ground is an
    // aircraft that flies into the hill it was sent to bomb the far side of.
    _veh flyInHeight _alt;
    _veh lockDriver true;
    _grp createVehicleCrew _veh;

    // A UAV that comes out crewless flies nowhere - the same fault the patrol
    // drones had, and the same fix.
    if ((crew _veh) isEqualTo []) then {createVehicleCrew _veh};

    _logic setVariable [QGVAR(vehicle), _veh, true];
    // THE WORD THE SUPPORT PAGE DRAWS ON THE ROW. A loiter says so from the
    // moment it launches, because a row reading MISSION for an aircraft that
    // is going to sit overhead for an hour tells the next man nothing about
    // whether he can have it.
    _logic setVariable [QGVAR(status), ["mission", "loiter"] select (_mode isEqualTo "loiter"), true];
    _veh setVariable [QGVAR(owner), _logic, true];

    // WHAT IT WAS ASKED TO SHOOT WITH, and WHO ASKED. FUNC(fireAt) reads the
    // store off the airframe rather than being handed it, because the release
    // happens minutes later from the acquire loop and threading a parameter
    // through that is one more signature that has to stay in step. The caller
    // rides along for the same reason - a loiter hands him the gunner's seat
    // when the aircraft gets there, which is minutes after he asked.
    _veh setVariable [QGVAR(ordnance), _mag];
    _veh setVariable [QGVAR(caller), _caller, true];

    // Nothing about this aircraft is the AI's to decide.
    _grp allowFleeing 0;
    _grp setBehaviour "CARELESS";
    _grp setCombatMode "BLUE";
    {
        _x disableAI "TARGET";
        _x disableAI "AUTOTARGET";
        _x disableAI "AUTOCOMBAT";
    } forEach units _grp;
    [_veh] call EFUNC(common,lambsOff);

    // ALiVE virtualises what it is handed and deletes the object behind it. An
    // aircraft mid-run is exactly the thing that must not happen to. Asked
    // through the adapter because the variable is ALiVE's name and this addon
    // is not allowed to know it.
    [_veh] call EFUNC(adapter_alive,profileIgnore);

    _veh addEventHandler ["Killed", {
        params ["_u", "_k", "_i"];
        private _owner = _u getVariable [QGVAR(owner), objNull];
        [_owner, [_k, _i] select (!isNull _i)] call FUNC(killed);
    }];

    // WHAT IT IS UP THERE TO DO, WRITTEN AS WAYPOINTS. A strike is two MOVEs -
    // in through the target and out the far side, because an aircraft that
    // stops over what it just bombed is an aircraft on the wreck of its own
    // ordnance. A loiter is the same run-in and then an orbit held over the
    // point: it is not leaving until the man watching its feed is done or it
    // is recalled.
    private _wp1 = _grp addWaypoint [_pos, 0];
    _wp1 setWaypointType "MOVE";
    _wp1 setWaypointSpeed "FULL";

    if (_mode isEqualTo "loiter") then {
        private _wp2 = _grp addWaypoint [_pos, 0];
        _wp2 setWaypointType "LOITER";
        _wp2 setWaypointLoiterRadius CAS_LOITER_RADIUS;
        _wp2 setWaypointSpeed "NORMAL";
    } else {
        private _wp2 = _grp addWaypoint [_end, 0];
        _wp2 setWaypointType "MOVE";
        _wp2 setWaypointSpeed "FULL";
    };

    INFO_4("%1 airborne: %2 inbound on %3 deg to %4",_callsign,_cls,round _ingressHdg,_mode);

    // THE RUN WATCH. Terminal guidance is re-asked every second rather than
    // resolved once at spawn, because a designator comes on late far more often
    // than early - a section throws smoke when they hear the motor, not four
    // minutes before. Release is at a ring rather than a point: the aircraft
    // covers a hundred metres a tick and would step straight over a point.
    //
    // A LOITER IS WATCHED BY THE SAME TICK. It never releases and it is not
    // finished by arriving anywhere; what it is watching for is the moment the
    // aircraft reaches the point, which is when the gunner's seat changes
    // hands. Everything else - shot down, recalled, out of patience - ends it
    // exactly as it ends a run.
    [{
        params ["_args", "_handle"];
        _args params ["_veh", "_logic", "_pos", "_radius", "_side", "_end", "_until", "_callsign", "_mode"];

        private _done = {
            [_handle] call CBA_fnc_removePerFrameHandler;
            if (!isNull _logic) then {
                _logic setVariable [QGVAR(status), "idle", true];
                _logic setVariable [QGVAR(vehicle), objNull, true];
                _logic setVariable [QGVAR(readyAt), CBA_missionTime + (_logic getVariable [QGVAR(cooldown), 300]), true];
            };
        };

        // THE SEAT IS GIVEN BACK BEFORE THE AIRCRAFT IS TAKEN AWAY. A drone
        // controller whose airframe is deleted out from under him is a man
        // looking at a dead camera with no way out of it, so every ending goes
        // through here: the off-station event first, the delete a beat later.
        // It costs two seconds and it is the difference between a recall and a
        // bug report.
        private _sweep = {
            [QGVAR(offStation), [_veh]] call CBA_fnc_globalEvent;

            // AND THE AIRFRAME IS TAKEN BACK OFF HIS MACHINE FIRST. A UAV goes
            // LOCAL to whoever is flying it, and a delete only lands where the
            // object lives - so an aircraft a controller was holding would be
            // deleted on the server, stay alive on his client, and hold the
            // module's ledger busy for the rest of the mission.
            if (!local _veh) then {_veh setOwner 2};

            [{
                params ["_veh"];
                if (isNull _veh) exitWith {};
                deleteVehicleCrew _veh;
                deleteVehicle _veh;
            }, [_veh], 3] call CBA_fnc_waitAndExecute;
        };

        // Shot down: FUNC(killed) has already counted it against the module.
        // The cooldown still runs - an asset is not instantly ready again just
        // because it lost the last one.
        if (isNull _veh || {!alive _veh}) exitWith {
            call _done;
            if (!isNull _veh) then {call _sweep};
        };

        // Recalled, or the run has outlasted its patience.
        if ((_logic getVariable [QGVAR(abort), false]) || CBA_missionTime > _until) exitWith {
            call _done;
            if (!isNull _logic) then {_logic setVariable [QGVAR(abort), false, true]};
            INFO_1("%1 off task - clearing the area",_callsign);
            call _sweep;
        };

        // ON STATION IS WHERE A LOITER HANDS OVER. The orbit is a kilometre
        // across and the aircraft never crosses the point itself, so the ring
        // is wide. Nothing is released and nothing is acquired: what happens
        // over that grid from here is a man on a terminal, not a script with a
        // target list.
        if (_mode isEqualTo "loiter") exitWith {
            if (_veh getVariable [QGVAR(onStation), false]) exitWith {};
            if (_veh distance2D _pos > CAS_STATION_RING) exitWith {};

            _veh setVariable [QGVAR(onStation), true, true];
            if (!isNull _logic) then {_logic setVariable [QGVAR(status), "station", true]};
            INFO_2("%1 on station over %2 - the gunner is the drone controller's",_callsign,mapGridPosition _pos);
            [QGVAR(onStation), [_logic, _veh, _veh getVariable [QGVAR(caller), objNull]]] call CBA_fnc_globalEvent;
        };

        // Outbound and clear: the run is over.
        if (_veh getVariable [QGVAR(released), false] && {_veh distance2D _end < CAS_RELEASE_RING}) exitWith {
            call _done;
            INFO_1("%1 egressed",_callsign);
            call _sweep;
        };

        if (_veh getVariable [QGVAR(released), false]) exitWith {};
        if (_veh distance2D _pos > CAS_RELEASE_RING) exitWith {};

        // In the ring: one last look for a spot or smoke, then shoot.
        ([_pos, _radius, _side] call FUNC(acquire)) params ["_aim", "_by", "_track"];
        _veh setVariable [QGVAR(released), true];
        INFO_3("%1 releasing on %2 (%3)",_callsign,mapGridPosition _aim,_by);
        [QGVAR(release), [_logic, _aim, _by]] call CBA_fnc_globalEvent;
        [_veh, _aim, _track] call FUNC(fireAt);
    }, CAS_ACQUIRE_STEP, [_veh, _logic, _pos, _radius, _side, _end, CBA_missionTime + ([CAS_RUN_TIMEOUT, CAS_LOITER_TIMEOUT] select (_mode isEqualTo "loiter")), _callsign, _mode]] call CBA_fnc_addPerFrameHandler;

}, [_logic, _pos, _ingress, _egress, _caller, _mag, _mode], _delay] call CBA_fnc_waitAndExecute;
