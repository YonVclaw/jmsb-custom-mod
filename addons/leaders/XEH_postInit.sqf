#include "script_component.hpp"

if (!isServer) exitWith {};

// THE MODULE IS THE ENABLE. This file only sets up state and the report
// command; FUNC(moduleController) is what arms the system, so a mission with
// no module placed gets nothing from this addon. GVAR(moduleUp) is declared in
// XEH_preInit, NOT here - see there for why.
// One record per leader: [unit, houseIndex, state, tier]. state is "up",
// "dead" or "captured". FINITE - this array never grows.
GVAR(leaders) = [];
GVAR(houses) = [];
GVAR(asymSide) = sideUnknown;
// leader index -> the house his intel currently points at. Set BEFORE he
// moves, so intel found in the old house points where he is going.
GVAR(nextHouse) = createHashMap;

["jmfsbleaders", {
    [QGVAR(report), []] call CBA_fnc_serverEvent;
}, "all"] call CBA_fnc_registerChatCommand;

[QGVAR(report), {
    private _txt = format ["side=%1 houses=%2 | %3", GVAR(asymSide), count GVAR(houses),
        GVAR(leaders) apply {
            _x params ["_u", "_h", "_s"];
            format ["%1:%2@h%3", ["?", name _u] select (!isNull _u), _s, _h]
        }];
    diag_log text format ["[jmfsb_leaders] %1", _txt];
    [format ["LEADERS: %1", _txt]] remoteExec ["systemChat", 0];
}] call CBA_fnc_addEventHandler;
