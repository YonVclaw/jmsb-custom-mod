#include "..\script_component.hpp"
/*
 * Author: JMSB
 * Zeus (F11): with Zeus Enhanced loaded, right-click a Site's vehicle for "Air
 * Defence Site..." - every operation value of its Site, and this vehicle's own
 * override (hold fire), edited live. The edit is an order like any other
 * (FUNC(order)); a curator is always allowed.
 *
 * Optional: called only when ZEN's context menu is loaded (XEH_postInit).
 *
 * Arguments: None
 *
 * Return Value: None
 *
 * Public: No
 */

private _action = [
    QGVAR(zen), "Air Defence Site...", "\a3\ui_f\data\map\markers\nato\b_antiair.paa",
    {
        params ["", "", "", "", "", "_hovered"];
        private _id = _hovered getVariable [QGVAR(site), ""];
        private _row = (missionNamespace getVariable [QGVAR(board), []]) param [(missionNamespace getVariable [QGVAR(board), []]) findIf {(_x # 0) isEqualTo _id}, []];
        if (_row isEqualTo []) exitWith {};
        _row params ["", "_name", "", "", "_radius", "_auto", "_emcon", "", "", "", "", "_air", "_mun", "_shots", "_reserve", "_reaction"];
        private _modes = ["auto", "silent", "burst"];
        [format ["Air Defence - %1", _name], [
            ["CHECKBOX", "Automation", _auto],
            ["CHECKBOX", "Engage aircraft", _air],
            ["CHECKBOX", "Engage munitions", _mun],
            ["COMBO", "Radar emission", [_modes, ["Automatic", "Silent until cued", "Burst search"], (_modes find _emcon) max 0]],
            ["SLIDER", "Protected radius (m)", [50, 10000, _radius, 0]],
            ["SLIDER", "Shots per threat", [1, 6, _shots, 0]],
            ["SLIDER", "Long-range reserve", [0, 1, _reserve, 2]],
            ["SLIDER", "Crew reaction (s)", [0, 15, _reaction, 1]],
            ["CHECKBOX", "This vehicle holds fire", _hovered getVariable [QGVAR(hold), false]]
        ], {
            params ["_values", "_args"];
            _args params ["_id", "_veh"];
            _values params ["_auto", "_air", "_mun", "_emcon", "_radius", "_shots", "_reserve", "_reaction", "_hold"];
            private _o = { [QGVAR(order), [_id, _this # 0, _this # 1, player]] call CBA_fnc_serverEvent };
            ["automation", [_auto]] call _o;
            ["set", ["engageAir", _air]] call _o;
            ["set", ["engageMunitions", _mun]] call _o;
            ["set", ["emcon", _emcon]] call _o;
            ["set", ["radius", _radius]] call _o;
            ["set", ["shotsPerThreat", _shots]] call _o;
            ["set", ["reserveLong", _reserve]] call _o;
            ["set", ["reaction", _reaction]] call _o;
            ["hold", [netId _veh, _hold]] call _o;
        }, {}, [_id, _hovered]] call zen_dialog_fnc_create;
    },
    {
        params ["", "", "", "", "", "_hovered"];
        _hovered isEqualType objNull && {(_hovered getVariable [QGVAR(site), ""]) isNotEqualTo ""}
    }
] call zen_context_menu_fnc_createAction;

[_action, [], 0] call zen_context_menu_fnc_addAction;
