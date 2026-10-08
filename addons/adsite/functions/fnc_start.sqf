#include "..\script_component.hpp"
/*
 * Author: JMSB
 * Starts the three handlers the system runs on, once: the beat (every Site
 * looks, decides and engages), the fuse (every interceptor in flight, every
 * frame) and the board (what the tacpad panels draw).
 *
 * Arguments: None
 *
 * Return Value: None
 *
 * Example:
 * [] call jmfsb_adsite_fnc_start
 *
 * Public: No
 */

if (!isServer || GVAR(running)) exitWith {};
GVAR(running) = true;

[{ [] call FUNC(tick) }, ADS_BEAT, []] call CBA_fnc_addPerFrameHandler;
[{ [] call FUNC(fuze) }, 0, []] call CBA_fnc_addPerFrameHandler;
[{ [] call FUNC(board) }, ADS_BOARD_EVERY, []] call CBA_fnc_addPerFrameHandler;

INFO("air defence running");
