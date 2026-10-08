#include "script_component.hpp"

// ---- every machine with a screen: the tacpad panel, and Zeus -----------------
if (hasInterface) then {
    // The Site terminal IS the tacpad (user, 2026-10-07: "integrate into the
    // ui"). The panel exists only when the player's side has a Site.
    if (!isNil "jmfsb_tacpad_fnc_register") then {
        ["adsite", "AIR DEFENCE", DEFAULT_ADSITE, LINKFUNC(panel), LINKFUNC(panel), 2, true, {
            (missionNamespace getVariable [QGVAR(board), []]) findIf {(_x # 2) isEqualTo playerSide} > -1
        }] call EFUNC(tacpad,register);
    };
    // Zeus Enhanced is optional: its context action is added only when it is loaded.
    if (isClass (configFile >> "CfgPatches" >> "zen_context_menu")) then {
        [] call FUNC(zen);
    };
};

if (!isServer) exitWith {};

// Orders from the tacpad and from Zeus come here, and only here - the server
// checks who sent them (FUNC(canControl)) before anything moves.
[QGVAR(order), {_this call FUNC(order)}] call CBA_fnc_addEventHandler;

// jmfsb_airdefence's batteries become Sites, with the module's defaults. The
// placer raises this when a battery is crewed and standing.
[QEGVAR(airdefence,batteryUp), {
    params ["_vehicles", "_side", "_pos"];
    [_vehicles, _side, _pos, createHashMap] call FUNC(register);
}] call CBA_fnc_addEventHandler;

["adsite", "air defence Sites: members, tracks, what is committed where", {
    params ["_args", "_caller"];
    [_caller] call FUNC(report)
}] call EFUNC(common,addDebugCommand);

// PHASE 0 AS A COMMAND (docs/DESIGN_AIR_DEFENCE.md). The engine behaviour the
// engagement code is gated on, driven in front of whoever runs it.
["adsite.probe", "run the engine probes the air defence design depends on (A0-1..A0-3)", {
    params ["_args", "_caller"];
    [_args, _caller] call FUNC(probe)
}] call EFUNC(common,addDebugCommand);
