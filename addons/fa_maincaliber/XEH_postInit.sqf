#include "script_component.hpp"
/*
 * Registers this addon's airburst-capable tank rounds into the shared
 * jmfsbfa_mediumcaliber params hashmap. That addon's fired-event-handler
 * engine (installed on "AllVehicles", which covers tanks) picks these up the
 * same way it does its own 30mm/35mm airburst natures — this addon carries no
 * engine code of its own.
 *
 * requiredAddons guarantees jmfsbfa_mediumcaliber's own postInit (which builds
 * the hashmap) has already run by the time this fires, since postInit
 * execution respects the same dependency order as preInit.
 */

// [trigger radius (m), lethal radius (m), max damage, effective range (m)]
private _p105mm = [12, 8, 0.7, 2500];
private _p120mm = [15, 10, 0.8, 3000];
private _p125mm = [15, 10, 0.8, 3000];

// Register each airburst-capable base nature AND its tracer-color variants —
// the fired-EH engine keys on the exact ammo classname, so every _T_<color>
// projectile needs its own entry (same base+color expansion the mediumcaliber
// initEngine does for its own natures).
{
    _x params ["_base", "_params"];
    EGVAR(fa_mediumcaliber,params) set [_base, _params];
    {
        EGVAR(fa_mediumcaliber,params) set [format ["%1_T_%2", _base, _x], _params];
    } forEach ["Red", "Yellow", "Green", "White", "Blue", "Orange", "IR"];
} forEach [
    ["FA_Sh_105mm_HEATMP", _p105mm],
    ["FA_Sh_105mm_HEOB",   _p105mm],
    ["FA_Sh_120mm_AMP",   _p120mm],
    ["FA_Sh_120mm_HEAB",  _p120mm],
    ["FA_Sh_125mm_AMP",   _p125mm],
    ["FA_Sh_125mm_3OF82", _p125mm]
];
