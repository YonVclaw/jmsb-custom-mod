#include "script_component.hpp"
/*
 * Registers rearma_rus's counter-UAS rounds with the antidrone component's
 * proximity fuze: the 5.45x39 7N55 HEAB bullet, the KS-23 Barrikada-AB slug
 * and the RPG-26 AB PROX rocket. Runs after jmfsbfa_antidrone's postInit
 * (requiredAddons ordering). The rounds fly as plain ammo if the antidrone
 * component is absent. Tracer variants share the base ammo's fuze.
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
    // 5.45x39 7N55 - the 5.56 Mk361 envelope, a touch smaller for the lighter bullet
    ["FA_o_545x39_7N55_HEAB", [0.8, 0.575, 0.22, 450]]
];

// KS-23 Barrikada-AB - the 12 ga Mk363 PAB-S scaled up to the 23mm shell
EGVAR(fa_antidrone,AD_params) set ["FA_o_23mm_BarrikadaAB", [3, 2.25, 0.35, 250]];
// RPG-26 AB PROX - same envelope as the RPG-7 AB-7
EGVAR(fa_antidrone,AD_params) set ["FA_R_RPG26_AB26", [8, 6, 0.7, 200]];
