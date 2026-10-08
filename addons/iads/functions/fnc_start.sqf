#include "script_component.hpp"
/*
 * Author: JMSB
 * Finds what is on the map and starts the beats.
 *
 * Called by FUNC(moduleController) - never on its own.
 *
 * THREE TICKS, THREE RATES, AND THEY ARE DELIBERATELY NOT ONE. The scheduler
 * runs every few seconds because that is the resolution a blink needs. The scan
 * runs every few minutes because a sweep of every vehicle on the map is the
 * expensive one and new radars do not appear by the second. The reveal runs on
 * the mission maker interval because how often the rest of the mod hears about
 * the air picture is a design choice, not a performance one. Folding all three
 * into one handler would mean running the expensive one at the fast one rate.
 *
 * NOTHING WAITS FOR ALiVE. This addon manages what is standing, whoever put it
 * there - so there is no readiness event to hang on, and a mission with no
 * ALiVE at all works exactly the same.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * [] call jmfsb_iads_fnc_start
 *
 * Public: No
 */

if (!isServer) exitWith {};

[] call FUNC(scan);

[LINKFUNC(tick), IADS_TICK, []] call CBA_fnc_addPerFrameHandler;

if (GVAR(rescan) > 0) then {
    [LINKFUNC(scan), GVAR(rescan) * 60, []] call CBA_fnc_addPerFrameHandler;
};

if (GVAR(revealEvery) > 0) then {
    [LINKFUNC(reveal), GVAR(revealEvery), []] call CBA_fnc_addPerFrameHandler;
};

INFO_3("armed - blink %1-%2 s, floor %3 emitter(s) per side",GVAR(blinkMin),GVAR(blinkMax),GVAR(minEmitters));
