#include "script_component.hpp"

if (!isServer) exitWith {};
// THE MODULE IS THE ENABLE. This file only sets up state and the report
// command; FUNC(moduleController) is what arms the system, so a mission with
// no module placed gets nothing from this addon. GVAR(moduleUp) is declared in
// XEH_preInit, NOT here - see there for why.

GVAR(watches) = [];

// The capture event is the product. Anything else that wants to answer a
// capture listens here rather than being wired into the detector.
[QGVAR(captured), {
    _this call FUNC(onCaptured);
}] call CBA_fnc_addEventHandler;

["jmfsbqrf", {
    [QGVAR(report), []] call CBA_fnc_serverEvent;
}, "all"] call CBA_fnc_registerChatCommand;

// THE FRONT LINE MOVES AND EVERYBODY HEARS IT. ALiVE's OPCOM logs every
// objective it takes; the adapter re-raises that the moment it happens
// (jmfsb_adapter_alive_capture: [sideText, objectiveID, pos, size]). A
// hostile commander taking ground is news the players should get as the
// commander gets it, not when they walk into it.
if (isServer) then {
    [QEGVAR(adapter_alive,capture), {
        params ["_sideText", "_objId", "_pos", "_size"];
        if (_pos isEqualTo []) exitWith {};
        private _taker = [_sideText, sideUnknown] call EFUNC(common,sideFromText);
        if (_taker isEqualTo sideUnknown) exitWith {};
        private _playerSides = (allPlayers apply {side group _x}) arrayIntersect [west, east, independent];
        if ((_playerSides findIf {_taker getFriend _x < 0.6}) < 0) exitWith {};
        ["FRONT", format ["%1 has taken the ground at %2.", _sideText, mapGridPosition _pos], [0.831, 0.267, 0.267, 1], sideUnknown, _pos] call EFUNC(notify,broadcast);
    }] call CBA_fnc_addEventHandler;
};

[QGVAR(report), {
    private _txt = format ["%1 objective(s): %2", count GVAR(watches),
        GVAR(watches) apply {
            format ["%1@%2%3", _x get "name", mapGridPosition (_x get "pos"),
                ["", " HELD"] select (_x get "held")]
        }];
    diag_log text format ["[jmfsb_qrf] %1", _txt];
    [format ["QRF: %1", _txt]] remoteExec ["systemChat", 0];
}] call CBA_fnc_addEventHandler;
