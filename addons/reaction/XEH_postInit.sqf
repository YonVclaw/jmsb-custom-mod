#include "script_component.hpp"

if (hasInterface) then {
    [] call FUNC(radioInit);
};

if (!isServer) exitWith {};

// netId -> flagged-until, and netId -> last major. The two pieces of state
// the whole ladder runs on.
// THE MODULE IS THE ENABLE. This file only sets up state and the report
// command; FUNC(moduleController) is what arms the system, so a mission with
// no module placed gets nothing from this addon. GVAR(moduleUp) is declared in
// XEH_preInit, NOT here - see there for why.

GVAR(flags) = createHashMap;
GVAR(majors) = createHashMap;

// THE ONE PATH. A failed hack, a drone that saw somebody, and a detectable
// transmission all arrive here and roll the same degrees (new.md section 2).
[QGVAR(event), {
    params [["_unit", objNull, [objNull]], ["_source", "?", [""]]];
    if (isNull _unit) exitWith {};
    [_unit, _source] call FUNC(roll);
}] call CBA_fnc_addEventHandler;

["jmfsbreact", {
    [QGVAR(report), [player]] call CBA_fnc_serverEvent;
}, "all"] call CBA_fnc_registerChatCommand;

[QGVAR(report), {
    params ["_who"];
    private _txt = format ["flagged=%1 majors=%2 | you: %3",
        count GVAR(flags), count GVAR(majors),
        ["clean", "FLAGGED"] select ([_who] call FUNC(flagged) select 0)];
    diag_log text format ["[jmfsb_reaction] %1", _txt];
    [format ["REACTION: %1", _txt]] remoteExec ["systemChat", 0];
}] call CBA_fnc_addEventHandler;

// "THE ENEMY HAS YOUR POSITION." The enemy commander files spot reports on
// the players like on anyone else, and the adapter reads them back off the
// COP (jmfsb_adapter_alive_fnc_enemyKnowledge). When a report lands within
// REACT_SPOTTED_RANGE of a player, that player's group is told once, then
// left alone for REACT_SPOTTED_COOLDOWN - the point is the warning, not a
// ticker. Server-side, so one read serves everyone.
if (isServer) then {
    GVAR(spottedUntil) = createHashMap;
    [{
        if (isNil "jmfsb_adapter_alive_fnc_enemyKnowledge") exitWith {};
        private _bySide = createHashMap;
        {
            private _grp = group _x;
            if (isNull _grp || {!alive _x}) then {continue};
            private _side = side _grp;
            if (isNil {_bySide get (str _side)}) then {
                _bySide set [str _side, [_side] call jmfsb_adapter_alive_fnc_enemyKnowledge];
            };
            private _known = _bySide get (str _side);
            if (_known isEqualTo []) then {continue};
            private _gid = str _grp;
            if (CBA_missionTime < (GVAR(spottedUntil) getOrDefault [_gid, -1])) then {continue};
            private _at = getPosATL _x;
            private _hit = _known findIf {(_x select 0) distance2D _at <= REACT_SPOTTED_RANGE};
            if (_hit < 0) then {continue};
            GVAR(spottedUntil) set [_gid, CBA_missionTime + REACT_SPOTTED_COOLDOWN];
            (_known select _hit) params ["", "", "", "", "_by"];
            {
                [QEGVAR(notify,post), ["SPOTTED", format ["%1 has your position.", _by], NOTE_BAD, sideUnknown, getPosATL _x], _x] call CBA_fnc_targetEvent;
            } forEach (units _grp select {isPlayer _x});
        } forEach allPlayers;
    }, REACT_SPOTTED_TICK, []] call CBA_fnc_addPerFrameHandler;
};

