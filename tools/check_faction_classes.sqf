// FACTION CLASS CHECK - run in the debug console with the load order the
// factions are meant for. Goes through EVERY faction the game has loaded (or
// only the ones named in _only) and logs to the RPT what the running game
// cannot find:
//
//   FCHECK;PARENT;faction;class;parent          built on a class that is not defined
//   FCHECK;GEAR;faction;class;property;item     a uniform, item, weapon or magazine that is not defined
//   FCHECK;GROUPVEH;faction;group;vehicle       a group slot naming a class that is not defined
//   FCHECK;FACTION;faction;side;displayName;mod;units;groups;problems   one line per faction
//   FCHECK;DONE;factions;units;problems
//
// An offline check (reading config.bin out of the PBOs) cannot read creator DLC
// (.ebo) or obfuscated mods - this one asks the game itself.
//
// Pull it out of the RPT with: grep "FCHECK;" <rpt>

[] spawn {
    // empty = every faction; or e.g. ["jmfsb_faction_russia", "OPF_T_F"]
    private _only = [];

    private _factions = ("getNumber (_x >> 'side') in [0, 1, 2, 3]" configClasses (configFile >> "CfgFactionClasses")) apply {configName _x};
    if (_only isNotEqualTo []) then {
        private _o = _only apply {toLower _x};
        _factions = _factions select {(toLower _x) in _o};
    };
    // per faction: [units, groups, problems]
    private _stats = createHashMap;
    {_stats set [toLower _x, [0, 0, 0]]} forEach _factions;

    private _exists = {
        params ["_name"];
        isClass (configFile >> "CfgWeapons" >> _name) || {isClass (configFile >> "CfgMagazines" >> _name)}
            || {isClass (configFile >> "CfgVehicles" >> _name)} || {isClass (configFile >> "CfgGlasses" >> _name)}
    };
    private _bump = {
        params ["_fac", "_i"];
        private _s = _stats get (toLower _fac);
        _s set [_i, (_s select _i) + 1];
    };

    // ---- units and vehicles ------------------------------------------------
    {
        private _cfg = _x;
        private _fac = getText (_cfg >> "faction");
        if (getNumber (_cfg >> "scope") > 0 && {(toLower _fac) in _stats}) then {
            [_fac, 0] call _bump;
            private _cls = configName _cfg;
            // a parent that never got a body leaves an empty class with no model
            private _parent = inheritsFrom _cfg;
            if (isNull _parent || {getText (_cfg >> "model") isEqualTo ""}) then {
                diag_log text format ["FCHECK;PARENT;%1;%2;%3", _fac, _cls, configName _parent];
                [_fac, 2] call _bump;
            };
            {
                private _prop = _x;
                {
                    if (_x isNotEqualTo "" && {!([_x] call _exists)}) then {
                        diag_log text format ["FCHECK;GEAR;%1;%2;%3;%4", _fac, _cls, _prop, _x];
                        [_fac, 2] call _bump;
                    };
                } forEach ((getArray (_cfg >> _prop)) - ["Throw", "Put"]);
            } forEach ["weapons", "magazines", "linkedItems", "items"];
            {
                private _v = getText (_cfg >> _x);
                if (_v isNotEqualTo "" && {!([_v] call _exists)}) then {
                    diag_log text format ["FCHECK;GEAR;%1;%2;%3;%4", _fac, _cls, _x, _v];
                    [_fac, 2] call _bump;
                };
            } forEach ["uniformClass", "backpack", "crew"];
        };
    } forEach ("true" configClasses (configFile >> "CfgVehicles"));

    // ---- groups --------------------------------------------------------------
    {
        {
            private _facCfg = _x;
            private _fac = configName _facCfg;
            if ((toLower _fac) in _stats) then {
                {
                    {
                        private _grp = _x;
                        [_fac, 1] call _bump;
                        {
                            private _v = getText (_x >> "vehicle");
                            if !(isClass (configFile >> "CfgVehicles" >> _v)) then {
                                diag_log text format ["FCHECK;GROUPVEH;%1;%2;%3", _fac, configName _grp, _v];
                                [_fac, 2] call _bump;
                            };
                        } forEach ("true" configClasses _grp);
                    } forEach ("true" configClasses _x);
                } forEach ("true" configClasses _facCfg);
            };
        } forEach ("true" configClasses _x);
    } forEach ("true" configClasses (configFile >> "CfgGroups"));

    // ---- one line per faction --------------------------------------------------
    private _units = 0;
    private _bad = 0;
    {
        private _cfg = configFile >> "CfgFactionClasses" >> _x;
        (_stats get (toLower _x)) params ["_u", "_g", "_p"];
        private _mod = configSourceMod _cfg;
        diag_log text format ["FCHECK;FACTION;%1;%2;%3;%4;%5;%6;%7", _x, getNumber (_cfg >> "side"),
            ((getText (_cfg >> "displayName")) splitString ";") joinString ",",
            ["Arma 3", _mod] select (_mod isNotEqualTo ""), _u, _g, _p];
        _units = _units + _u;
        _bad = _bad + _p;
    } forEach _factions;

    diag_log text format ["FCHECK;DONE;%1;%2;%3", count _factions, _units, _bad];
    systemChat format ["FACTION CHECK DONE: %1 factions, %2 units and vehicles, %3 problems - grep the RPT for FCHECK", count _factions, _units, _bad];
};
