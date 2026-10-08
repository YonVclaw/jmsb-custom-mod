#include "script_component.hpp"
/*
 * Author: JMSB
 * Plans and builds every commander's air defence, once.
 *
 * Called by FUNC(moduleController) when ALiVE is up - never on its own. The
 * one tick this addon keeps is the rearm loop below; everything else is built
 * once and left standing.
 *
 * Arguments: None
 *
 * Return Value: None
 *
 * Example:
 * [] call jmfsb_airdefence_fnc_start
 */

if (!isServer) exitWith {};

[] call FUNC(plan);

// The rearm loop - the one tick this addon keeps. A SAM site that fired its
// tubes dry and sat quiet for the rest of the mission read as broken, not
// empty; every interval the surviving pieces come back to full.
if (GVAR(rearmEvery) > 0) then {
    [{
        {
            if (!isNull _x && {alive _x}) then { _x setVehicleAmmo 1 };
        } forEach GVAR(hardware);
    }, GVAR(rearmEvery) * 60, []] call CBA_fnc_addPerFrameHandler;
};
