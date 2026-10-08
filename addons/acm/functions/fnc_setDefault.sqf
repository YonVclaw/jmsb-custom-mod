#include "script_component.hpp"
/*
 * Author: YonV
 * Changes the DEFAULT of a CBA setting another addon has already registered,
 * keeping everything else about it - its title, tooltip, category, value list,
 * labels, who may change it and its on-change script.
 *
 * A DEFAULT, NOT A VALUE. CBA re-registers a setting in place when it is added
 * a second time, so this adds it again from CBA's own record with one thing
 * different. Anything a server, a mission or a player has set still wins over
 * it, exactly as it would over the owner's default - which is the point: the
 * unit gets JMSB's tiers out of the box and can still change any of them in
 * the settings menu.
 *
 * Must run after the owner's preInit, which is what requiredAddons orders.
 *
 * Arguments:
 * 0: Setting name <STRING>
 * 1: New default <ANY> - for a LIST, one of its values
 *
 * Return Value:
 * Whether the default was changed <BOOL>
 *
 * Example:
 * ["ACM_airway_allowOPA", SKILL_CLS] call jmfsb_acm_fnc_setDefault
 *
 * Public: No
 */

params [["_setting", "", [""]], "_default"];

private _info = cba_settings_default getVariable _setting;
if (isNil "_info") exitWith {
    WARNING_1("%1 is not registered - the loaded ACM has no such setting",_setting);
    false
};

_info params ["", "", "_type", "_data", "_category", "_displayName", "_tooltip", "_isGlobal", "_script", "_subCategory"];

private _valueInfo = switch (_type) do {
    case "LIST": {
        _data params ["_values", "_labels", ["_tooltips", []]];
        private _index = _values find _default;
        if (_index < 0) exitWith {nil};
        // labels with their tooltips, as CBA_fnc_addSetting takes them
        private _pairs = [];
        {
            _pairs pushBack [_x, _tooltips param [_forEachIndex, ""]];
        } forEach _labels;
        [_values, _pairs, _index]
    };
    case "CHECKBOX";
    case "EDITBOX": {_default};
    default {nil};
};

if (isNil "_valueInfo") exitWith {
    WARNING_3("%1 (%2) cannot take %3 as its default - left as it was",_setting,_type,_default);
    false
};

[_setting, _type, [_displayName, _tooltip], [_category, _subCategory], _valueInfo, _isGlobal, _script] call CBA_fnc_addSetting;
true
