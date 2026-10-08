#include "script_component.hpp"
/*
 * Registers rearma_us's counter-UAS rounds with the antidrone component's
 * proximity fuze: the 6.8x51 Mk402 and 6x38 Mk407 PAB bullets and the M72A12
 * PROX rocket. Runs after jmfsbfa_antidrone's postInit (requiredAddons
 * ordering). The rounds fly as plain ammo if the antidrone component is absent.
 * Tracer variants share the base ammo's fuze.
 *
 * Public: No
 */

if (isNil QEGVAR(fa_antidrone,AD_params)) exitWith {};

// [trigger radius (m), lethal radius (m), max damage, effective range (m)]
private _tracers = ["", "_T_Red", "_T_Yellow", "_T_Green", "_T_White", "_T_Blue", "_T_Orange", "_T_IR"];
{
    _x params ["_ammo", "_params"];
    {
        EGVAR(fa_antidrone,AD_params) set [_ammo + _x, _params];
    } forEach _tracers;
} forEach [
    // 6.8x51 Mk402 - same envelope as the 7.62 Mk362
    ["FA_b_680_Mk402_PAB", [1, 0.75, 0.25, 800]],
    // 6x38 Mk407 - between the 5.56 Mk361 and the 6.5 Mk367
    ["FA_b_6x38_Mk407_PAB", [1.3, 0.95, 0.25, 550]]
];

// M72A12 PROX - smallest launcher airburst in the set, level with the RPG-7 AB-7
EGVAR(fa_antidrone,AD_params) set ["FA_R_M72A12_PROX", [7, 5, 0.65, 200]];
