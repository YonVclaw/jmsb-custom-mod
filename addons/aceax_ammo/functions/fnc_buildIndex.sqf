#include "..\script_component.hpp"
/*
 * Read the generated XtdGearInfos / XtdGearModels data into hashmaps, once.
 *
 * Walking config on every panel fill would be a config lookup per row on a
 * list that can hold a thousand of them. This runs at preInit and the collapse
 * then costs one hashmap read per row.
 *
 * Builds:
 *   GVAR(model)    magazine class (lowercase) -> family name
 *   GVAR(values)   magazine class (lowercase) -> [[axis, value], ...]
 *   GVAR(members)  family -> [magazine classes], in config order
 *   GVAR(axes)     family -> [[axis, axis label, [value, ...], [label, ...]], ...]
 *
 * Class names are lowercased throughout: config class names are
 * case-insensitive and the arsenal hands back whatever spelling the config
 * that defined the magazine used, which is not always the spelling here.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * Number of magazines indexed <NUMBER>
 */

GVAR(model) = createHashMap;
GVAR(values) = createHashMap;
GVAR(members) = createHashMap;
GVAR(axes) = createHashMap;
GVAR(rowName) = createHashMap;

// ---- the families and their axes ----
private _models = configFile >> "XtdGearModels" >> "CfgMagazines";
{
    private _family = configName _x;
    private _options = getArray (_x >> "options");
    private _built = [];

    {
        private _axis = _x;
        private _cfg = (_models >> _family >> _axis);
        if (!isClass _cfg) then { continue };

        private _values = getArray (_cfg >> "values") apply { toLower _x };
        private _labels = _values apply {
            private _l = getText (_cfg >> _x >> "label");
            // a value with no label of its own falls back to its own key
            [_l, _x] select (_l isEqualTo "")
        };
        _built pushBack [_axis, getText (_cfg >> "label"), _values, _labels];
    } forEach _options;

    if (_built isNotEqualTo []) then {
        GVAR(axes) set [_family, _built];
        GVAR(members) set [_family, []];
    };
} forEach configProperties [_models, "isClass _x", true];

// ---- every magazine, and where it sits ----
private _count = 0;
{
    private _class = configName _x;
    private _family = getText (_x >> "model");
    private _low = toLower _class;

    // The row's name, for every magazine whose family has one - a lone magazine
    // included, which has no axes and so no place in the rest of the index.
    private _rowName = getText (_models >> _family >> "rowName");
    if (_rowName isNotEqualTo "") then { GVAR(rowName) set [_low, _rowName] };

    if !(_family in GVAR(axes)) then { continue };

    private _vals = [];
    {
        _x params ["_axis"];
        private _v = getText ((configFile >> "XtdGearInfos" >> "CfgMagazines" >> _class) >> _axis);
        if (_v isNotEqualTo "") then { _vals pushBack [_axis, toLower _v] };
    } forEach (GVAR(axes) get _family);

    GVAR(model) set [_low, _family];
    GVAR(values) set [_low, _vals];
    (GVAR(members) get _family) pushBack _class;
    _count = _count + 1;
} forEach configProperties [configFile >> "XtdGearInfos" >> "CfgMagazines", "isClass _x", true];

// A family whose members all vanished (a mod removed them) would leave an
// empty dropdown behind, so drop it here rather than guard for it every frame.
{
    if ((GVAR(members) get _x) isEqualTo []) then {
        GVAR(axes) deleteAt _x;
        GVAR(members) deleteAt _x;
    };
} forEach keys GVAR(members);

TRACE_2("indexed",count GVAR(axes),_count);
_count
