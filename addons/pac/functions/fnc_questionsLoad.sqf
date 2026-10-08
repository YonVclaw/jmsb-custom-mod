#include "script_component.hpp"
/*
    File: fnc_questionsLoad.sqf
    Author: YonV
    Description: The application questions, in order - the website's
        jmfsbd_questions: <unit>.web.questions, items keyed by id with
        {label, type, required, help, options, order}, turned into an
        ordered list of hashmaps each carrying its id. Server only,
        scheduled; read once into GVAR(docCache) and published as
        GVAR(applyQuestions) for the tacpad's APPLICATION tab.

    Parameters:
        0: Read the database again <BOOL> (optional)

    Returns:
        The questions <ARRAY of HASHMAP>
*/

params [["_fresh", false, [false]]];

if (!isServer) exitWith {[]};
private _unit = GVAR(settings) getOrDefault ["unitId", ""];
private _key = _unit + ".web.questions";
if (isNil QGVAR(docCache)) then {GVAR(docCache) = createHashMap};
if (_fresh) then {GVAR(docCache) deleteAt _key};

private _doc = GVAR(docCache) get _key;
if (isNil "_doc") then {
    ([_key] call FUNC(svcLoad)) params ["_d", "_s"];
    _doc = [createHashMap, _d] select (_s isEqualTo "ok");
    if (_s isEqualTo "ok") then {GVAR(docCache) set [_key, _d]};
};

private _items = _doc getOrDefault ["items", []];
private _out = [];
if (_items isEqualType createHashMap) then {
    {
        private _q = +_y;
        if (_q isEqualType createHashMap) then {
            _q set ["id", _x];
            _out pushBack _q;
        };
    } forEach _items;
    {_x set ["_ord", format ["%1", 1000000 + (_x getOrDefault ["order", 0])]]} forEach _out;
    _out = [_out, "_ord", true] call FUNC(docsSort);
    {_x deleteAt "_ord"} forEach _out;
} else {
    if (_items isEqualType []) then {_out = _items select {_x isEqualType createHashMap}};
};

GVAR(applyQuestions) = _out;
publicVariable QGVAR(applyQuestions);
_out
