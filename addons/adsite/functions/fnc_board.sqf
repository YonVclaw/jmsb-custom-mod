#include "..\script_component.hpp"
/*
 * Author: JMSB
 * Publishes what the tacpad panels draw, every ADS_BOARD_EVERY seconds. One row
 * per Site:
 *
 *   [id, name, side, centre ASL, radius, automation, emcon, access,
 *    members [[netId, name, roles, rounds left, radar lit, holding], ...],
 *    tracks  [[key, kind, class name, position ASL, seconds, weapons on it], ...],
 *    link, engageAir, engageMunitions, shotsPerThreat, reserveLong, reaction]
 *
 * Every client gets every Site; the panel shows its own side's only.
 *
 * Arguments: None
 *
 * Return Value: None
 *
 * Public: No
 */

private _rows = [];
{
    private _site = _y;
    private _committed = _site get "committed";
    private _members = (_site get "members") apply {
        private _veh = _x;
        ([_veh] call FUNC(profile)) params ["_entries", "_radar", "_roles"];
        private _rounds = 0;
        { _rounds = _rounds + (_veh magazineTurretAmmo [_x # 2, _x # 0]) } forEach (_entries select {(_x # 7) isNotEqualTo ROLE_SURFACE});
        [netId _veh, getText (configOf _veh >> "displayName"), _roles, _rounds, isVehicleRadarOn _veh, _veh getVariable [QGVAR(hold), false]]
    };
    private _tracks = (values (_site get "tracks")) apply {
        _x params ["_obj", "_kind", "_cls", "_at", "_tti"];
        private _name = getText (([configFile >> "CfgAmmo" >> _cls, configOf _obj] select (_kind isEqualTo "air")) >> "displayName");
        if (_name isEqualTo "") then { _name = _cls };
        [hashValue _obj, _kind, _name, [_at, getPosASL _obj] select (_kind isEqualTo "air"), _tti, count (_committed getOrDefault [hashValue _obj, []])]
    };
    _rows pushBack [
        _x, _site get "name", _site get "side", _site get "centre", _site get "radius",
        _site get "automation", _site get "emcon", _site get "access", _members, _tracks,
        _site get "link", _site get "engageAir", _site get "engageMunitions",
        _site get "shotsPerThreat", _site get "reserveLong", _site get "reaction"
    ];
} forEach GVAR(sites);

missionNamespace setVariable [QGVAR(board), _rows, true];
