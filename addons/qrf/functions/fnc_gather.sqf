#include "script_component.hpp"
/*
 * Author: JMSB
 * Builds the watch list: every commander's objectives, plus any jmfsb_qrf*
 * marker.
 *
 * Markers first and markers win: a mission maker who drew one meant it, and
 * an ALiVE objective under the same marker is the same piece of ground at the
 * size they chose. De-duplicated by position for exactly that reason.
 *
 * Held and streak state carries across rebuilds, so a capture already in
 * progress is not forgotten when the adapter comes up mid-hold.
 *
 * Arguments: None
 *
 * Return Value:
 * Watch count <NUMBER>
 *
 * Public: No
 */

private _old = GVAR(watches);
private _out = [];

private _push = {
    params ["_name", "_pos", "_radius"];
    if ((_out findIf {(_x get "pos") distance2D _pos < 50}) > -1) exitWith {};

    private _w = createHashMapFromArray [
        ["name", _name],
        ["pos", +_pos],
        ["radius", _radius max 10],
        ["streak", -1],
        ["held", false],
        ["last", -1e9]
    ];

    private _i = _old findIf {(_x get "pos") distance2D _pos < 50};
    if (_i > -1) then {
        private _o = _old select _i;
        { _w set [_x, _o get _x] } forEach ["streak", "held", "last"];
    };
    _out pushBack _w;
};

{
    private _m = _x;
    if ((toLower _m) find QRF_MARKER_PREFIX == 0) then {
        private _size = markerSize _m;
        private _r = (_size select 0) max (_size select 1);
        if (_r <= 1) then { _r = QRF_DEFAULT_RADIUS };
        [_m, getMarkerPos _m, _r] call _push;
    };
} forEach allMapMarkers;

if (!isNil "jmfsb_adapter_alive_fnc_commanders") then {
    {
        _x params ["_side"];
        {
            _x params ["_id", "_pos", "_size"];
            [_id, _pos, _size] call _push;
        } forEach ([_side] call jmfsb_adapter_alive_fnc_objectivesFor);
    } forEach (call jmfsb_adapter_alive_fnc_commanders);
};

GVAR(watches) = _out;
INFO_1("watching %1 objective(s)",count _out);

count _out
