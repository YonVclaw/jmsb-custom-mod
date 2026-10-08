#include "..\script_component.hpp"
#include "\z\jmfsb\addons\tacpad\shared.inc.hpp"
/*
 * Author: JMSB
 * The AIR DEFENCE panel on the tacpad - the Site terminal (F10, user,
 * 2026-10-07: "integrate into the ui"). Drawn from the board the server
 * publishes (FUNC(board)); every press is an order the server checks
 * (FUNC(order)), so the panel only greys out what would be refused.
 *
 *   STATUS     the Site's members: roles, rounds, radar, hold - and the switches
 *              for each (hold fire, radar on / off / auto)
 *   INTERCEPT  what it is tracking, soonest first; pick a track, then a member
 *              to put on it. AUTOMATION on / off. STRIKE: pick a member, then
 *              click the map
 *   SETTINGS   the Site's operation values, stepped
 *
 * The map itself shows every own-side Site's protected area and its tracks
 * (a Draw handler added once to the map control).
 *
 * Arguments:
 * 0: Panel body <CONTROL>
 * 1: Panel id <STRING>
 *
 * Return Value: None
 *
 * Public: No
 */

params [["_body", controlNull, [controlNull]], ["_id", "", [""]]];

if (isNull _body) exitWith {};
{ ctrlDelete _x } forEach (allControls (ctrlParent _body) select { (ctrlParentControlsGroup _x) isEqualTo _body });

([] call EFUNC(tacpad,theme)) params ["_ground", "_ink", "_accent", "_line"];
private _w = (ctrlPosition _body) # 2;
private _pad = PAD * safeZoneW;
private _padY = PAD * safeZoneH;
private _rowH = ROW_H * EGVAR(tacpad,textScale) * EGVAR(tacpad,uiScale) * safeZoneH;
private _mute = [_ink # 0, _ink # 1, _ink # 2, 0.62];
private _dim = [_ink # 0, _ink # 1, _ink # 2, 0.42];

// ---- the map overlay, once ------------------------------------------------------
private _map = (findDisplay 12) displayCtrl 51;
if (!isNull _map && {isNil {_map getVariable QGVAR(drawEh)}}) then {
    _map setVariable [QGVAR(drawEh), _map ctrlAddEventHandler ["Draw", {
        params ["_m"];
        {
            _x params ["", "_name", "_side", "_centre", "_radius", "", "", "", "", "_tracks"];
            if (_side isNotEqualTo playerSide) then { continue };
            _m drawEllipse [ASLToAGL _centre, _radius, _radius, 0, [0.2, 0.6, 1, 0.8], ""];
            _m drawIcon ["\a3\ui_f\data\map\markers\nato\b_antiair.paa", [0.2, 0.6, 1, 1], ASLToAGL _centre, 20, 20, 0, _name, 1, 0.04, "PuristaMedium", "right"];
            {
                _x params ["", "_kind", "_tname", "_at", "_tti"];
                private _icon = ["\a3\ui_f\data\map\markers\military\dot_ca.paa", "\a3\ui_f\data\map\markers\nato\o_plane.paa"] select (_kind isEqualTo "air");
                _m drawIcon [_icon, [0.871, 0.2, 0.15, 1], ASLToAGL _at, 16, 16, 0, format ["%1 %2s", _tname, ceil _tti], 1, 0.035, "PuristaMedium", "right"];
            } forEach _tracks;
        } forEach (missionNamespace getVariable [QGVAR(board), []]);
    }]];
    // STRIKE: the next click on the map after a member was picked
    _map ctrlAddEventHandler ["MouseButtonClick", {
        params ["_m", "_button", "_x", "_y"];
        private _with = missionNamespace getVariable [QGVAR(strikeWith), []];
        if (_button != 0 || {_with isEqualTo []}) exitWith {};
        GVAR(strikeWith) = [];
        _with params ["_site", "_net"];
        [QGVAR(order), [_site, "strike", [AGLToASL (_m ctrlMapScreenToWorld [_x, _y]), _net], player]] call CBA_fnc_serverEvent;
    }];
};

// ---- which Site ------------------------------------------------------------------
private _rows = (missionNamespace getVariable [QGVAR(board), []]) select {(_x # 2) isEqualTo playerSide};
private _rowY = _padY;
if (_rows isEqualTo []) exitWith {
    [_body, [_pad, _rowY, _w - 2 * _pad, _rowH], "NO AIR DEFENCE SITE ON YOUR SIDE", _dim, 0.75, true, "left", true] call EFUNC(tacpad,drawText);
    [_id, 0, (_rowY + _rowH + _padY) / safeZoneH] call EFUNC(tacpad,fit);
};
private _sel = (missionNamespace getVariable [QGVAR(panelSite), 0]) mod (count _rows);
private _row = _rows # _sel;
_row params ["_siteId", "_name", "", "_centre", "_radius", "_auto", "_emcon", "", "_members", "_tracks", "_link",
    "_air", "_mun", "_shots", "_reserve", "_reaction"];
private _can = [player, _row] call FUNC(canControl);
private _view = missionNamespace getVariable [QGVAR(panelView), "status"];

// a button: [x, y, w, label, lit, enabled, code run on press with [control]]
private _button = {
    params ["_bx", "_by", "_bw", "_label", "_lit", "_on", "_code"];
    [_body, [_bx, _by, _bw, _rowH], [_line, _accent] select _lit, RULE_THIN] call EFUNC(tacpad,drawFrame);
    [_body, [_bx, _by, _bw, _rowH], _label, [[_dim, _ink] select _on, _accent] select _lit, 0.62, true, "center", true] call EFUNC(tacpad,drawText);
    if (_on) then {
        private _hit = [_body, [_bx, _by, _bw, _rowH], _code] call EFUNC(tacpad,drawHit);
        _hit setVariable [QGVAR(site), _siteId];
        _hit
    } else { controlNull };
};

// title row: the Site, and a NEXT when there are several
[_body, [_pad, _rowY, _w * 0.62, _rowH], format ["%1%2", _name, ["", format ["  [%1]", _link]] select (_link isNotEqualTo "")], _ink, 0.8, true] call EFUNC(tacpad,drawText);
[_body, [_w * 0.62, _rowY, _w * 0.38 - _pad, _rowH], format ["%1  %2", ["MANUAL", "AUTO"] select _auto, toUpper _emcon], [_accent, _mute] select _auto, 0.62, true, "right", true] call EFUNC(tacpad,drawText);
_rowY = _rowY + _rowH;
if (count _rows > 1) then {
    [_pad, _rowY, _w * 0.3, format ["SITE %1/%2 >", _sel + 1, count _rows], false, true, {
        GVAR(panelSite) = (missionNamespace getVariable [QGVAR(panelSite), 0]) + 1;
        { ["adsite"] call EFUNC(tacpad,rebuild) } call CBA_fnc_execNextFrame;
    }] call _button;
    _rowY = _rowY + _rowH + _padY;
};

// tabs
private _tw = (_w - 4 * _pad) / 3;
{
    _x params ["_v", "_label"];
    private _h = [_pad + _forEachIndex * (_tw + _pad), _rowY, _tw, _label, _v isEqualTo _view, true, {
        params ["_c"];
        GVAR(panelView) = _c getVariable [QGVAR(view), "status"];
        { ["adsite"] call EFUNC(tacpad,rebuild) } call CBA_fnc_execNextFrame;
    }] call _button;
    _h setVariable [QGVAR(view), _v];
} forEach [["status", "STATUS"], ["intercept", "INTERCEPT"], ["settings", "SETTINGS"]];
_rowY = _rowY + _rowH + _padY * 2;

switch (_view) do {
    // ---- STATUS ----------------------------------------------------------------
    case "status": {
        {
            _x params ["_net", "_mname", "_roles", "_rounds", "_lit", "_hold"];
            [_body, [_pad, _rowY, _w * 0.55, _rowH], toUpper _mname, _ink, 0.66, true] call EFUNC(tacpad,drawText);
            [_body, [_w * 0.55, _rowY, _w * 0.45 - _pad, _rowH], format ["%1  %2 RDS%3", toUpper (_roles joinString "/"), _rounds, ["", "  RADAR"] select _lit], _mute, 0.6, true, "right", true] call EFUNC(tacpad,drawText);
            _rowY = _rowY + _rowH;
            private _bw = (_w - 4 * _pad) / 3;
            private _h = [_pad, _rowY, _bw, ["HOLD FIRE", "HOLDING"] select _hold, _hold, _can, {
                params ["_c"];
                (_c getVariable [QGVAR(args), []]) params ["_n", "_hold"];
                [QGVAR(order), [_c getVariable [QGVAR(site), ""], "hold", [_n, !_hold], player]] call CBA_fnc_serverEvent;
                { ["adsite"] call EFUNC(tacpad,rebuild) } call CBA_fnc_execNextFrame;
            }] call _button;
            if (!isNull _h) then { _h setVariable [QGVAR(args), [_net, _hold]] };
            if ("sensor" in _roles) then {
                {
                    _x params ["_mode", "_label"];
                    private _hb = [_pad + (_forEachIndex + 1) * (_bw + _pad), _rowY, _bw, _label, false, _can, {
                        params ["_c"];
                        (_c getVariable [QGVAR(args), []]) params ["_n", "_m"];
                        [QGVAR(order), [_c getVariable [QGVAR(site), ""], "radar", [_n, _m], player]] call CBA_fnc_serverEvent;
                    }] call _button;
                    if (!isNull _hb) then { _hb setVariable [QGVAR(args), [_net, _mode]] };
                } forEach [[["on", "RADAR ON"], ["off", "RADAR OFF"]] select _lit, ["auto", "RADAR AUTO"]];
            };
            _rowY = _rowY + _rowH + _padY * 2;
        } forEach _members;
    };

    // ---- INTERCEPT ---------------------------------------------------------------
    case "intercept": {
        private _bw = (_w - 3 * _pad) / 2;
        private _ha = [_pad, _rowY, _bw, ["AUTOMATION OFF", "AUTOMATION ON"] select _auto, _auto, _can, {
            params ["_c"];
            [QGVAR(order), [_c getVariable [QGVAR(site), ""], "automation", [!(_c getVariable [QGVAR(args), true])], player]] call CBA_fnc_serverEvent;
            { ["adsite"] call EFUNC(tacpad,rebuild) } call CBA_fnc_execNextFrame;
        }] call _button;
        if (!isNull _ha) then { _ha setVariable [QGVAR(args), _auto] };
        private _picking = missionNamespace getVariable [QGVAR(strikeWith), []];
        [_body, [_pad * 2 + _bw, _rowY, _bw, _rowH], ["STRIKE: PICK A MEMBER", "STRIKE: CLICK THE MAP"] select (_picking isNotEqualTo []), [_mute, _accent] select (_picking isNotEqualTo []), 0.6, true, "center", true] call EFUNC(tacpad,drawText);
        _rowY = _rowY + _rowH + _padY * 2;

        // soonest impact first
        private _sorted = _tracks apply {[_x # 4, _x]};
        _sorted sort true;
        _sorted = _sorted apply {_x # 1};
        private _picked = missionNamespace getVariable [QGVAR(pickTrack), ""];
        if (_sorted isEqualTo []) then {
            [_body, [_pad, _rowY, _w, _rowH], "NOTHING TRACKED", _dim, 0.66, true, "left", true] call EFUNC(tacpad,drawText);
            _rowY = _rowY + _rowH;
        };
        {
            _x params ["_key", "_kind", "_tname", "", "_tti", "_on"];
            private _h = [_pad, _rowY, _w - 2 * _pad, format ["%1  %2  %3s  [%4]", toUpper _kind, toUpper _tname, ceil _tti, _on], _key isEqualTo _picked, true, {
                params ["_c"];
                GVAR(pickTrack) = _c getVariable [QGVAR(args), ""];
                { ["adsite"] call EFUNC(tacpad,rebuild) } call CBA_fnc_execNextFrame;
            }] call _button;
            _h setVariable [QGVAR(args), _key];
            _rowY = _rowY + _rowH + _padY;
        } forEach (_sorted select [0, 8]);
        _rowY = _rowY + _padY;

        // the members: FIRE onto the picked track, STRIKE to pick for the map
        {
            _x params ["_net", "_mname", "_roles"];
            [_body, [_pad, _rowY, _w * 0.5, _rowH], toUpper _mname, _ink, 0.6, true] call EFUNC(tacpad,drawText);
            private _fw = (_w * 0.5 - 3 * _pad) / 2;
            private _hf = [_w * 0.5, _rowY, _fw, "FIRE", false, _can && _picked isNotEqualTo "", {
                params ["_c"];
                [QGVAR(order), [_c getVariable [QGVAR(site), ""], "engage", [missionNamespace getVariable [QGVAR(pickTrack), ""], _c getVariable [QGVAR(args), ""]], player]] call CBA_fnc_serverEvent;
            }] call _button;
            if (!isNull _hf) then { _hf setVariable [QGVAR(args), _net] };
            private _hs = [_w * 0.5 + _fw + _pad, _rowY, _fw, "STRIKE", false, _can && {"surface" in _roles}, {
                params ["_c"];
                GVAR(strikeWith) = [_c getVariable [QGVAR(site), ""], _c getVariable [QGVAR(args), ""]];
                { ["adsite"] call EFUNC(tacpad,rebuild) } call CBA_fnc_execNextFrame;
            }] call _button;
            if (!isNull _hs) then { _hs setVariable [QGVAR(args), _net] };
            _rowY = _rowY + _rowH + _padY;
        } forEach _members;
    };

    // ---- SETTINGS ------------------------------------------------------------------
    case "settings": {
        if (!_can) then {
            [_body, [_pad, _rowY, _w, _rowH], "READ ONLY - NOT YOURS TO COMMAND", _accent, 0.6, true, "left", true] call EFUNC(tacpad,drawText);
            _rowY = _rowY + _rowH + _padY;
        };
        {
            _x params ["_key", "_label", "_value", "_step", "_shown"];
            [_body, [_pad, _rowY, _w * 0.5, _rowH], _label, _mute, 0.62, true, "left", true] call EFUNC(tacpad,drawText);
            [_body, [_w * 0.5, _rowY, _w * 0.2, _rowH], _shown, _ink, 0.66, true, "center", true] call EFUNC(tacpad,drawText);
            {
                _x params ["_sign", "_bx"];
                private _h = [_bx, _rowY, _w * 0.12, ["-", "+"] select (_sign > 0), false, _can, {
                    params ["_c"];
                    (_c getVariable [QGVAR(args), []]) params ["_k", "_v"];
                    [QGVAR(order), [_c getVariable [QGVAR(site), ""], "set", [_k, _v], player]] call CBA_fnc_serverEvent;
                }] call _button;
                if (!isNull _h) then {
                    // a switch flips; a number steps (both branches cannot be built - SQF evaluates the whole array)
                    private _new = if (_value isEqualType true) then { !_value } else { _value + _sign * _step };
                    _h setVariable [QGVAR(args), [_key, _new]];
                };
            } forEach [[-1, _w * 0.72], [1, _w * 0.86 - _pad]];
            _rowY = _rowY + _rowH + _padY;
        } forEach [
            ["radius", "PROTECTED RADIUS", _radius, 100, format ["%1 M", _radius]],
            ["shotsPerThreat", "SHOTS PER THREAT", _shots, 1, str _shots],
            ["reserveLong", "LONG-RANGE RESERVE", _reserve, 0.1, format ["%1%%", round (_reserve * 100)]],
            ["reaction", "CREW REACTION", _reaction, 0.5, format ["%1 S", _reaction]],
            ["engageAir", "ENGAGE AIRCRAFT", _air, 0, ["NO", "YES"] select _air],
            ["engageMunitions", "ENGAGE MUNITIONS", _mun, 0, ["NO", "YES"] select _mun]
        ];
        // emission: a cycle
        [_body, [_pad, _rowY, _w * 0.5, _rowH], "RADAR EMISSION", _mute, 0.62, true, "left", true] call EFUNC(tacpad,drawText);
        private _next = ["auto", "silent", "burst"] select ((((["auto", "silent", "burst"] find _emcon) max 0) + 1) mod 3);
        private _h = [_w * 0.5, _rowY, _w * 0.5 - _pad, toUpper _emcon, false, _can, {
            params ["_c"];
            [QGVAR(order), [_c getVariable [QGVAR(site), ""], "set", ["emcon", _c getVariable [QGVAR(args), "auto"]], player]] call CBA_fnc_serverEvent;
        }] call _button;
        if (!isNull _h) then { _h setVariable [QGVAR(args), _next] };
        _rowY = _rowY + _rowH + _padY;
    };
};

[_id, 0, (_rowY + _padY) / safeZoneH] call EFUNC(tacpad,fit);
