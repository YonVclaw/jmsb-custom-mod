#include "..\script_component.hpp"
// import stuff
#include "macros.hpp"

/*
 * Author: PDT
 * Sets the player's NVG effect; effects are defined in macros.hpp.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * <ARRAY> - [<STRING>, <BOOL>], ["NVG Effect", true if effect was set; false if not]
 *
 * Example:
 * [] spawn Pjmfsb_EnhancedNVG_fnc_setNvgEffect;
 */

// player is not using NVGs, exit
private _nvgMode = call FUNC(getVisionMode);
if (!_nvgMode) exitWith {["", false]};

private _nvgEffect = call FUNC(getNvgEffect);
if (_nvgEffect isEqualTo []) exitWith {["", false]};

private _ppEffect = ppEffectCreate ["ColorCorrections", 16735];

_ppEffect ppEffectAdjust _nvgEffect;
_ppEffect ppEffectForceInNVG true;
_ppEffect ppEffectCommit 0.01;
_ppEffect ppEffectEnable true;

waitUntil {!(call FUNC(getVisionMode)) || !(isNull findDisplay 312)};
_ppEffect ppEffectEnable false;
ppEffectDestroy _ppEffect;

if (!isNull findDisplay 312) exitWith {
    [] spawn {
        waitUntil {isNull findDisplay 312};
        call FUNC(setNvgEffect);
    };
};
