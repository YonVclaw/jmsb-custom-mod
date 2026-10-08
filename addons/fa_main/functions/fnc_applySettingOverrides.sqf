#include "..\script_component.hpp"
/*
 * Author: YonV
 * Applies config-declared setting overrides on top of the live CBA settings.
 *
 * A faction mod (or any other addon) declares the values it wants in its own
 * config.cpp. Anyone running FA without that mod keeps full CBA control; as
 * soon as the mod is loaded its values win:
 *
 *     class JMFSBFA_SettingOverrides {
 *         class MyFactionPack {
 *             priority = 10;                              // optional, highest wins on a clash
 *             lock = 1;                                   // optional, 1 (default) = re-apply if changed
 *             jmfsb_fa_mediumcaliber_redFraction  = 0.95;
 *             jmfsb_fa_mediumcaliber_cuasCeiling  = 1.10;
 *             jmfsb_fa_antidrone_damageMultiplier = 1.25;
 *             jmfsb_fa_ammo_enableBreaching       = 0;    // checkbox: 0/1
 *
 * NOTE THE PREFIX. Ported into jmfsb these settings are jmfsb_fa_<component>_,
 * not the jmfsbfa_ of the standalone mod - a name from the wrong side of the
 * port sets a variable nothing reads, and does so silently.
 *         };
 *     };
 *
 * The config table is built once and cached in GVAR(settingOverrides).
 *
 * Arguments:
 * 0: Only re-apply overrides flagged as locked <BOOL> (optional, default: false)
 *
 * Return Value:
 * None
 *
 * Public: No
 */

params [["_lockedOnly", false, [false]]];

// Config can't change at runtime, so the table is built exactly once.
if (isNil QGVAR(settingOverrides)) then {
    private _table = createHashMap;
    private _blocks = configProperties [configFile >> "JMFSBFA_SettingOverrides", "isClass _x", false];

    // Sort ascending on priority so the highest-priority block is applied last and wins.
    private _order = [];
    {
        _order pushBack [getNumber (_x >> "priority"), _forEachIndex];
    } forEach _blocks;
    _order sort true;

    {
        private _block = _blocks select (_x select 1);
        private _source = configName _block;
        private _locked = [true, getNumber (_block >> "lock") > 0] select (isNumber (_block >> "lock"));

        {
            private _name = configName _x;
            if !(toLowerANSI _name in ["priority", "lock"]) then {
                private _value = switch (true) do {
                    case (isNumber _x): {getNumber _x};
                    case (isText _x):   {getText _x};
                    case (isArray _x):  {getArray _x};
                    default {nil};
                };

                if (isNil "_value") then {
                    ERROR_2("Setting override '%1' in '%2' has an unreadable value - skipped",_name,_source);
                } else {
                    // Key on lowercase: config property names are case-insensitive.
                    _table set [toLowerANSI _name, [_name, _value, _locked, _source]];
                };
            };
        } forEach configProperties [_block, "!isClass _x", false];
    } forEach _order;

    GVAR(settingOverrides) = _table;

    if (count _table > 0) then {
        INFO_1("%1 config setting override(s) registered",count _table);
    };
};

if (count GVAR(settingOverrides) == 0) exitWith {};

{
    _y params ["_name", "_value", "_locked", "_source"];

    if (_locked || {!_lockedOnly}) then {
        // Variable lookup is case-insensitive, so whatever casing the mod author
        // used in config resolves to the real setting variable.
        private _current = missionNamespace getVariable _name;

        if (isNil "_current") then {
            ERROR_2("Setting override '%1' from '%2' matches no registered setting - skipped",_name,_source);
        } else {
            // Coerce to the type the setting was registered with (CHECKBOX wants a BOOL).
            private _new = _value;
            if (_current isEqualType false && {!(_value isEqualType false)}) then {
                _new = switch (true) do {
                    case (_value isEqualType 0):  {_value > 0};
                    case (_value isEqualType ""): {toLowerANSI _value in ["1", "true", "yes", "on"]};
                    default {_current};
                };
            };
            if (_current isEqualType 0 && _value isEqualType "") then {
                _new = parseNumber _value;
            };

            if (_new isNotEqualTo _current) then {
                missionNamespace setVariable [_name, _new];
                INFO_3("Setting '%1' overridden to %2 by '%3'",_name,_new,_source);
            };
        };
    };
} forEach GVAR(settingOverrides);
