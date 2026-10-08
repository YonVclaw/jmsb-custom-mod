#include "..\script_component.hpp"
/*

 * \jmfsb_medical\supplies\functions\fn_doUnpackFirstAid.sqf
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
 * [player] call jmfsb_medbags_fnc_doUnpackFirstAid;
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
        playSound QGVAR(Medical_FirstAid_Open_1);
    } else {
        playSound3D ["z\jmfsb\addons\medbags\data\sounds\FirstAid_Open_1.ogg", _unit];
    };

    jmfsb_MEDICAL_SUPPLIES_UNPACK_SUCCESS = false;
    jmfsb_MEDICAL_SUPPLIES_UNPACK_FAILURE = false;

    [
        2,
        [],
        { jmfsb_MEDICAL_SUPPLIES_UNPACK_SUCCESS = true; },
        { jmfsb_MEDICAL_SUPPLIES_UNPACK_FAILURE = true; },
        "Unpacking Boo Boo Bag....",
        {true},
        ["isNotInside", "isNotSitting", "isNotSwimming"]
    ] call ACE_common_fnc_progressBar;

    waitUntil {if ((jmfsb_MEDICAL_SUPPLIES_UNPACK_SUCCESS) || (jmfsb_MEDICAL_SUPPLIES_UNPACK_FAILURE)) exitWith {true}; false};

    if (jmfsb_MEDICAL_SUPPLIES_UNPACK_SUCCESS) exitWith {

        _unit removeItem "jmfsb_medbags_FirstAid";

        [_unit, GVAR(contentsFirstAid)] call FUNC(issueContents);
    };

    if (jmfsb_MEDICAL_SUPPLIES_UNPACK_FAILURE) exitWith {};
};
