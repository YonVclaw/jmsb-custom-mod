#include "script_component.hpp"
/*
 * Author: YonV
 * Wires the vehicle-missile natures into the shared scripted subsystems:
 * - AGR-40 Hydra-P C-UAS mode -> mediumcaliber proximity-fuze registry (its
 *   AllVehicles fired EH already tracks anything in that hashmap; runs after
 *   jmfsbfa_mediumcaliber's postInit via requiredAddons ordering).
 * - XM1200 Copperhead -> loiter handover when fired without a lock.
 *
 * Public: No
 */

// [trigger radius (m), lethal radius (m), max damage, effective range (m)]
if (!isNil QEGVAR(fa_mediumcaliber,params)) then {
    EGVAR(fa_mediumcaliber,params) set ["FA_M_AGR40_HydraP", [12, 15, 0.85, 8000]];
};

// Copperhead fired without an engine lock hands over to the loiter script. The
// projectile is only steerable where it is local (the firing machine).
["AllVehicles", "fired", {
    params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_mag", "_proj"];
    if (_ammo == "FA_M_XM1200_Copperhead" && {local _proj}) then {
        [_proj, _unit] call FUNC(loiterCopperhead);
    };
}] call CBA_fnc_addClassEventHandler;
