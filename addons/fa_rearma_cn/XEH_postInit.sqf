#include "script_component.hpp"
/*
 * Registers rearma_cn's scripted rounds. Runs after jmfsbfa_antidrone's and
 * jmfsbfa_grenade_40mm's postInit (requiredAddons ordering).
 *  - Counter-UAS rounds join the antidrone proximity fuze: the DBJ PAB bullets
 *    (5.8 / 8.6 / 12.7x108), the QLU-11 DFK-135, the QN-205D and the PF-89K.
 *  - The airburst natures (DFK-135, DFP-135 HE-P, QN-205B) join the shared
 *    programmable-airburst dial (Mk364 keybind / ACE self-menu).
 *  - The QLU-11 DFZ-13x carriers join the Mk380 deploy registry at ~0.75x the
 *    lifetime and radius of the 40mm rounds.
 * Anything whose component is absent flies as a plain round.
 *
 * Public: No
 */

if (!isNil QEGVAR(fa_antidrone,AD_params)) then {
    // [trigger radius (m), lethal radius (m), max damage, effective range (m)]
    private _tracers = ["", "_T_Red", "_T_Yellow", "_T_Green", "_T_White", "_T_Blue", "_T_Orange", "_T_IR"];
    {
        _x params ["_ammo", "_params"];
        {
            EGVAR(fa_antidrone,AD_params) set [_ammo + _x, _params];
        } forEach _tracers;
    } forEach [
        // 5.8x42 DBJ-39 - the 5.56 Mk361 envelope, a touch larger for the heavier bullet
        ["FA_o_580_DBJ39_PAB",      [0.9, 0.65, 0.25, 520]],
        // 8.6x39 DBJ-41 - the .300 BLK Mk363 scaled up to the heavier bullet
        ["FA_o_86x39_DBJ41_PAB",    [2, 1.5, 0.25, 350]],
        // 12.7x108 DBJ-127 - same as the 12.7x99 Mk366
        ["FA_o_127x108_DBJ127_PAB", [2.5, 1.75, 0.25, 1500]]
    ];

    // QLU-11 DFK-135 PAB - the 40mm Mk364 envelope (6 / 4.5 m, 0.5) at ~0.75x the
    // radius and 0.7x the damage; the QLU-11's 450 m/s round reaches further.
    EGVAR(fa_antidrone,AD_params) set ["FA_o_35mm_DFK135_PAB", [4.5, 3.4, 0.35, 600]];
    // DFP-135 HE-P and QN-205B TBX - programmable airburst only: trigger radius 0
    // disables the drone proximity check while the dialled burst range still
    // detonates the round in flight.
    EGVAR(fa_antidrone,AD_params) set ["FA_o_35mm_DFP135_HEP", [0, 6.5, 0.5, 1200]];
    EGVAR(fa_antidrone,AD_params) set ["FA_M_QN205B_TBX", [0, 9, 0.8, 3000]];
    {
        EGVAR(fa_antidrone,programmableAB) pushBackUnique _x;
    } forEach ["FA_o_35mm_DFK135_PAB", "FA_o_35mm_DFP135_HEP", "FA_M_QN205B_TBX"];
    // QN-205D C-UAS - IR-guided proximity burst
    EGVAR(fa_antidrone,AD_params) set ["FA_M_QN205D_CUAS", [8, 6, 0.8, 1500]];
    // PF-89K PROX - between the RPG-7 AB-7 and the RPG-32 AB-32
    EGVAR(fa_antidrone,AD_params) set ["FA_R_PF89K_PROX", [9, 7, 0.75, 250]];
};

if (!isNil QEGVAR(fa_grenade_40mm,registry)) then {
    // [deploy mode, effect function, lifetime (s), radius (m)] - the 40mm Mk380
    // block values x ~0.75 (NRP 1800 / 5000, EMP 8 / 60, MSmoke 60 / 25,
    // Decoy 120 / 300, UGS 1800 / 150, Jammer 900 / 400).
    {
        EGVAR(fa_grenade_40mm,registry) set _x;
    } forEach [
        ["FA_o_35mm_DFZ130_NRP",    ["CHUTE", EFUNC(fa_grenade_40mm,relay),  1350, 3750]],
        ["FA_o_35mm_DFZ133_EMP",    ["CHUTE", EFUNC(fa_grenade_40mm,emp),       6,   45]],
        ["FA_o_35mm_DFZ134_MSmoke", ["CHUTE", EFUNC(fa_grenade_40mm,msmoke),   45,   19]],
        ["FA_o_35mm_DFZ135_Decoy",  ["CHUTE", EFUNC(fa_grenade_40mm,decoy),    90,  225]],
        ["FA_o_35mm_DFZ136_UGS",    ["CHUTE", EFUNC(fa_grenade_40mm,ugs),    1350,  110]],
        ["FA_o_35mm_DFZ138_Jammer", ["CHUTE", EFUNC(fa_grenade_40mm,jammer),  675,  300]]
    ];
};
