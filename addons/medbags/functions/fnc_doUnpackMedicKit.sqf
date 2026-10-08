#include "..\script_component.hpp"
/*

 * \jmfsb_medical\supplies\functions\fn_doUnpackMedicKit.sqf
 * by YonV
 *
 * unpack medical supplies
 *
 * Arguments:
 * 0: unit - <OBJECT>
 *
 * Return:
 * nothing
 *
 * Example:
 * [player] call jmfsb_medbags_fnc_doUnpackMedicKit;
 *
 */

// -------------------------------------------------------------------------------------------------

private _unit = param [0, objNull, [objNull]];

// -------------------------------------------------------------------------------------------------

if (isNull _unit) exitWith {};

// -------------------------------------------------------------------------------------------------

[_unit] spawn {

    params ["_unit"];

    _unit playAction "Gear";

    if (!isNull objectParent _unit) then {
        playSound QGVAR(Medical_MedicKit_Open_1);
    } else {
        playSound3D ["z\jmfsb\addons\medbags\data\sounds\medickit_open_1.ogg", _unit];
    };

    jmfsb_MEDICAL_SUPPLIES_UNPACK_SUCCESS = false;
    jmfsb_MEDICAL_SUPPLIES_UNPACK_FAILURE = false;

    [
        2,
        [], { jmfsb_MEDICAL_SUPPLIES_UNPACK_SUCCESS = true; }, { jmfsb_MEDICAL_SUPPLIES_UNPACK_FAILURE = true; },
        "Unpacking Medical Kit....",
        {true},
        ["isNotInside", "isNotSitting", "isNotSwimming"]
    ] call ACE_common_fnc_progressBar;

    waitUntil {if ((jmfsb_MEDICAL_SUPPLIES_UNPACK_SUCCESS) || (jmfsb_MEDICAL_SUPPLIES_UNPACK_FAILURE)) exitWith {true}; false};

    if (jmfsb_MEDICAL_SUPPLIES_UNPACK_SUCCESS) exitWith {

        _unit removeItem "jmfsb_medbags_MedicKit";

        [_unit, GVAR(contentsMedicKit)] call FUNC(issueContents);
    };
    if (jmfsb_MEDICAL_SUPPLIES_UNPACK_FAILURE) exitWith {};
};
