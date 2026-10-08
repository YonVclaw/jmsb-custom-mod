#include "..\script_component.hpp"
/*
 * Author: JMSB
 * `#jmfsb adsite.probe`: Phase 0 of docs/DESIGN_AIR_DEFENCE.md, driven in front
 * of whoever runs it. Code built on an unverified engine guess runs, logs
 * success and does the opposite - so these are asked of the engine, not assumed:
 *
 *   A0-3  does the server see a round in flight (nearObjects), so a Site can track it?
 *   A0-2  does fireAtTarget fire a Site's SAM at an object that is not a vehicle?
 *   A0-1  does setMissileTarget turn that SAM onto the round?
 *
 * Needs a Site with a missile launcher. A mortar round is dropped from 900 m
 * over the Site's centre and the nearest launcher is ordered onto it; the
 * answers are printed as they come.
 *
 * Arguments:
 * 0: Command arguments <ARRAY>
 * 1: Who asked <OBJECT>
 *
 * Return Value: None
 *
 * Public: No
 */

params [["_args", [], [[]]], ["_caller", objNull, [objNull]]];

[_caller] spawn {
    params ["_caller"];
    private _say = { [format ["adsite.probe: %1", _this], _caller] call EFUNC(common,debugReply); INFO_1("probe: %1",_this) };

    private _pick = [];
    {
        private _site = _y;
        {
            private _veh = _x;
            private _e = (([_veh] call FUNC(profile)) # 0) select {(_x # 7) in [ROLE_SHORT, ROLE_LONG]};
            if (_e isNotEqualTo [] && {_pick isEqualTo []}) then { _pick = [_veh, _e # 0, _site] };
        } forEach (_site get "members");
    } forEach GVAR(sites);
    if (_pick isEqualTo []) exitWith { "no Site has a missile launcher - place one and sync it" call _say };
    _pick params ["_veh", "_entry", "_site"];
    _entry params ["_path", "_weapon"];

    // the round: a mortar shell falling from 900 m on the Site's centre
    private _c = ASLToAGL (_site get "centre");
    private _shell = createVehicle ["Sh_82mm_AMOS", _c vectorAdd [0, 0, 900], [], 0, "CAN_COLLIDE"];
    _shell setVelocity [0, 0, -60];
    sleep 0.3;

    // A0-3
    private _seen = _shell in (_c nearObjects ["ShellCore", 2000]);
    format ["A0-3 server sees the round in flight: %1", ["NO - Sites cannot track munitions this way", "yes"] select _seen] call _say;

    // A0-2 and A0-1, through the system's own engagement path
    private _auto = _site get "automation";
    _site set ["automation", false];
    _veh setVariable [QGVAR(pending), [_shell, 12, _site get "id", "munition"]];
    private _man = _veh turretUnit _path;
    _man doWatch _shell;
    _man doTarget _shell;
    sleep 1;
    private _fired = _veh fireAtTarget [_shell, _weapon];
    format ["A0-2 fireAtTarget at a round: %1", ["returned false - FUNC(engage) falls back to forceWeaponFire", "fired"] select _fired] call _say;
    sleep 1;
    private _missile = (GVAR(inFlight) select {(_x # 1) isEqualTo _shell}) param [0, []] param [0, objNull];
    if (isNull _missile) then {
        "A0-1 no missile was caught leaving the launcher - FUNC(fired) did not see it" call _say;
    } else {
        format ["A0-1 setMissileTarget onto the round: %1", ["NO - the fuse alone has to catch it", "yes"] select ((missileTarget _missile) isEqualTo _shell)] call _say;
    };
    sleep 12;
    format ["result: the round was %1", ["intercepted", "NOT intercepted"] select (alive _shell)] call _say;
    if (alive _shell) then { deleteVehicle _shell };
    _site set ["automation", _auto];
};
