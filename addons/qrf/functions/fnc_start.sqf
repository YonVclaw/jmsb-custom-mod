#include "script_component.hpp"
/*
 * Author: JMSB
 * Gathers the objectives worth watching and starts the capture check.
 *
 * Called by FUNC(moduleController) once ALiVE is up - never on its own. The
 * module is the enable, so a mission with no module never reaches here.
 *
 * Arguments: None
 *
 * Return Value: None
 *
 * Example:
 * [] call jmfsb_qrf_fnc_start
 */

if (!isServer) exitWith {};

[] call FUNC(gather);

// Re-gathered whenever ALiVE reports in again: commanders can be added to a
// running mission, and an objective nobody is watching cannot be taken.
[QEGVAR(adapter_alive,ready), { [] call FUNC(gather) }] call CBA_fnc_addEventHandler;

[LINKFUNC(check), QRF_TICK, []] call CBA_fnc_addPerFrameHandler;
