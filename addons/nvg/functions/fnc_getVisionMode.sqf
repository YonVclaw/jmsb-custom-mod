#include "..\script_component.hpp"

/*
 * Author: PDT
 * Checks the player's vision mode.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * <BOOL> - true if player is using NVGs; false if not
 *
 * Example:
 * call Pjmfsb_EnhancedNVG_fnc_getVisionMode;
 */

// currentVisionMode is always 0 in Zeus
private _visionMode = currentVisionMode player;

if (_visionMode isNotEqualTo 1) exitWith {false};

true
