#include "script_component.hpp"

if (!isServer) exitWith {};

// THE MODULE IS THE ENABLE. This file only sets up state and the report
// command; FUNC(moduleController) is what arms the system, so a mission with no
// module placed gets nothing from this addon. GVAR(moduleUp) is declared in
// XEH_preInit, NOT here - see there for why.

// [centre, side] per site. NO object references: profiling deletes the hardware
// and ALiVE makes new objects later, so a site is a PLACE.
GVAR(sites) = [];
// the physical pieces, for the rearm loop - null entries are profiled or dead
GVAR(hardware) = [];
GVAR(teams) = [];

["jmfsbaa", {
    [QGVAR(report), []] call CBA_fnc_serverEvent;
}, "all"] call CBA_fnc_registerChatCommand;

[QGVAR(report), {
    private _txt = format ["%1 batter(y/ies), %2 MANPAD team(s) | %3",
        count GVAR(sites), count GVAR(teams),
        GVAR(sites) apply {
            _x params ["_pos", "_side"];
            format ["%1@%2", _side, mapGridPosition _pos]
        }];
    diag_log text format ["[jmfsb_airdefence] %1", _txt];
    [format ["AIR DEFENCE: %1", _txt]] remoteExec ["systemChat", 0];
}] call CBA_fnc_addEventHandler;
