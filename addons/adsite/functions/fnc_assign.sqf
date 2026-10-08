#include "..\script_component.hpp"
/*
 * Author: JMSB
 * Coordinated, layered defence (F3) for one group of linked Sites.
 *
 * Threats are taken soonest-impact first. Each gets the best weapon that can
 * still reach it, up to the Site's shots per threat:
 *
 *   a munition   CIWS, then guns - the inner layer - then short-range missiles,
 *                which take the bulk of a salvo; long-range missiles only while
 *                their rounds are below the Site's reserve, or when nothing
 *                else can reach it
 *   an aircraft  short-range missiles inside their reach, long-range beyond
 *                it, guns last
 *
 * Nothing is engaged while a Site's automation is off - orders from the tacpad
 * go through FUNC(order) instead, onto the same commitments.
 *
 * Arguments:
 * 0: The group's Sites <ARRAY>
 *
 * Return Value: None
 *
 * Public: No
 */

params [["_sites", [], [[]]]];

private _lead = _sites # 0;
private _committed = _lead get "committed";
private _busy = _lead get "busy";

// every threat the group can see, one entry per object, soonest impact first
private _threats = createHashMap;
{
    private _site = _x;
    {
        private _old = _threats get _x;
        if (isNil "_old" || {(_y # 4) < (_old # 0 # 4)}) then { _threats set [_x, [_y, _site]] };
    } forEach (_site get "tracks");
} forEach _sites;

// commitments to what is gone are dropped
{
    if !(_x in _threats) then { _committed deleteAt _x };
} forEach (keys _committed);

private _order = (keys _threats) apply {[(_threats get _x) # 0 # 4, _x]};
_order sort true;

{
    _x params ["", "_key"];
    (_threats get _key) params ["_track", "_site"];
    if !(_site get "automation") then { continue };
    _track params ["_target", "_kind"];
    if (!alive _target) then { continue };

    private _on = (_committed getOrDefault [_key, []]) select {alive _x};
    if (count _on >= (_site get "shotsPerThreat")) then { continue };

    private _best = [_site, _target, _kind, _busy, _sites] call {
        params ["_site", "_target", "_kind", "_busy", "_sites"];
        private _pick = [];
        private _bestScore = 1e9;
        {
            private _owner = _x;
            {
                private _veh = _x;
                if (_veh getVariable [QGVAR(hold), false]) then { continue };
                if ((hashValue _veh) in _busy) then { continue };
                private _dist = _veh distance _target;
                {
                    _x params ["_path", "_weapon", "_mag", "", "", "_max", "_min", "_role"];
                    if (_role in [ROLE_SURFACE, ROLE_SENSOR]) then { continue };
                    if (_dist > _max || _dist < _min) then { continue };
                    if ((_veh magazineTurretAmmo [_mag, _path]) <= 0) then { continue };
                    if (isNull (_veh turretUnit _path) && {_path isNotEqualTo [-1]}) then { continue };

                    // the layers, as a score: lower is preferred
                    private _rank = if (_kind isEqualTo "munition") then {
                        switch (_role) do {
                            case ROLE_CIWS: {0};
                            case ROLE_GUN: {1};
                            case ROLE_SHORT: {2};
                            default {
                                // LONG: held while above the reserve
                                private _full = _veh getVariable [format ["%1_%2", QGVAR(full), _mag], 1];
                                private _left = ({_x isEqualTo _mag} count (_veh magazinesTurret _path)) max 0;
                                [3, 9] select ((_left / (_full max 1)) > (_owner get "reserveLong"))
                            };
                        }
                    } else {
                        switch (_role) do {
                            case ROLE_SHORT: {0};
                            case ROLE_LONG: {1};
                            case ROLE_GUN: {2};
                            default {3};
                        }
                    };
                    private _score = _rank * 1e6 + _dist;
                    if (_score < _bestScore) then {
                        _bestScore = _score;
                        _pick = [_veh, _x, _owner];
                    };
                } forEach (([_veh] call FUNC(profile)) # 0);
            } forEach (_owner get "members");
        } forEach _sites;
        _pick
    };
    if (_best isEqualTo []) then { continue };
    _best params ["_veh", "_entry", "_owner"];

    _on pushBack _veh;
    _committed set [_key, _on];
    _busy set [hashValue _veh, _target];
    [_veh, _entry, _target, _kind, _owner get "id"] spawn FUNC(engage);
} forEach _order;
