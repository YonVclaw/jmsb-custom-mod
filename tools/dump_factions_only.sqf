// FACTION DUMP, CHOSEN FACTIONS ONLY - tools/dump_orbat.sqf cut down to the
// factions named in _factions below, in the same line formats, so
// tools/gen_orbat_from_rpt.py reads it like the full dump.
//
//   Edit _factions, paste the whole file into the debug console (Eden,
//   in-mission or Zeus), Local Exec, wait for the "FACTION DUMP DONE" chat line.
//
// THE LINE FORMATS (as dump_orbat.sqf):
//   FPROP;faction;own;num|txt|arr;;name;value       (CfgFactionClasses)
//   UNIT;class;faction;parent;side;scope            (men and vehicles, scope > 0)
//   UPROP;class;own;num|txt|arr;;name;value         (unit property)
//   GROUP;gid;Side;faction;category;class;name
//   GPROP;gid;own;num|txt|arr;;name;value           (group property)
//   GMAN;gid;i;vehicle;rank;[x,y,z]                 (one slot)
//   WEAPON;class;parent;type;displayName;muzzleLinked;[compatible muzzle items]
//     (only the rifles, pistols and launchers these factions' men carry)
//   FMISSING;faction                                (named but not loaded)

[] spawn {
    private _factions = ["OPF_CD_F", "OPF_T_F"];

    private _want = _factions apply {toLower _x};
    private _uprops = [
        ["displayName", "txt"], ["vehicleClass", "txt"], ["editorSubcategory", "txt"],
        ["crew", "txt"], ["uniformClass", "txt"], ["backpack", "txt"],
        ["scopeCurator", "num"], ["side", "num"], ["isUav", "num"],
        ["linkedItems", "arr"], ["weapons", "arr"], ["magazines", "arr"],
        ["identityTypes", "arr"], ["hiddenSelections", "arr"], ["hiddenSelectionsTextures", "arr"]
    ];
    private _fprops = [
        ["displayName", "txt"], ["author", "txt"], ["icon", "txt"], ["flag", "txt"],
        ["side", "num"], ["priority", "num"]
    ];
    private _gprops = [["name", "txt"], ["icon", "txt"], ["rarityGroup", "num"]];

    private _val = {
        params ["_cfg", "_name", "_typ"];
        switch (_typ) do {
            case "num": {str getNumber (_cfg >> _name)};
            case "arr": {str getArray (_cfg >> _name)};
            default {getText (_cfg >> _name)};
        };
    };
    private _props = {
        params ["_tag", "_key", "_cfg", "_list"];
        {
            _x params ["_name", "_typ"];
            if (isNumber (_cfg >> _name) || {isText (_cfg >> _name)} || {isArray (_cfg >> _name)}) then {
                diag_log text format ["%1;%2;own;%3;;%4;%5", _tag, _key, _typ, _name, [_cfg, _name, _typ] call _val];
            };
        } forEach _list;
    };

    diag_log text format [">>>> FACTION DUMP BEGIN <<<< %1", _factions];

    // ---- factions -------------------------------------------------------
    {
        private _cfg = configFile >> "CfgFactionClasses" >> _x;
        if (isClass _cfg) then {
            ["FPROP", configName _cfg, _cfg, _fprops] call _props;
        } else {
            diag_log text format ["FMISSING;%1", _x];
        };
    } forEach _factions;

    // ---- units ----------------------------------------------------------
    private _n = 0;
    private _carried = [];
    {
        private _cfg = _x;
        private _scope = getNumber (_cfg >> "scope");
        if (_scope > 0 && {(toLower getText (_cfg >> "faction")) in _want}) then {
            private _cls = configName _cfg;
            diag_log text format ["UNIT;%1;%2;%3;%4;%5", _cls, getText (_cfg >> "faction"),
                configName (inheritsFrom _cfg), getNumber (_cfg >> "side"), _scope];
            ["UPROP", _cls, _cfg, _uprops] call _props;
            {_carried pushBackUnique toLower _x} forEach getArray (_cfg >> "weapons");
            _n = _n + 1;
        };
    } forEach ("true" configClasses (configFile >> "CfgVehicles"));

    // ---- groups ---------------------------------------------------------
    // CfgGroups files a faction under its side, by its own class name
    private _gid = 0;
    {
        private _sideCfg = _x;
        private _sideName = configName _sideCfg;
        if ((toLower _sideName) in ["west", "east", "indep", "guer", "civ", "civilian"]) then {
            {
                private _facCfg = _x;
                private _fac = configName _facCfg;
                if ((toLower _fac) in _want) then {
                    {
                        private _catCfg = _x;
                        private _cat = configName _catCfg;
                        {
                            private _grp = _x;
                            _gid = _gid + 1;
                            diag_log text format ["GROUP;%1;%2;%3;%4;%5;%6", _gid, _sideName, _fac, _cat, configName _grp, getText (_grp >> "name")];
                            ["GPROP", _gid, _grp, _gprops] call _props;
                            private _i = 0;
                            {
                                diag_log text format ["GMAN;%1;%2;%3;%4;%5", _gid, _i, getText (_x >> "vehicle"), getText (_x >> "rank"), str getArray (_x >> "position")];
                                _i = _i + 1;
                            } forEach ("true" configClasses _grp);
                        } forEach ("true" configClasses _catCfg);
                    } forEach ("true" configClasses _facCfg);
                };
            } forEach ("true" configClasses _sideCfg);
        };
    } forEach ("true" configClasses (configFile >> "CfgGroups"));

    // ---- weapons the men carry -------------------------------------------
    private _nw = 0;
    {
        private _cfg = configFile >> "CfgWeapons" >> _x;
        if (isClass _cfg && {getNumber (_cfg >> "type") in [1, 2, 4]}) then {
            private _ms = _cfg >> "WeaponSlotsInfo" >> "MuzzleSlot";
            private _compat = [];
            if (isClass _ms) then {
                if (isArray (_ms >> "compatibleItems")) then {
                    _compat = getArray (_ms >> "compatibleItems");
                } else {
                    // CBA Joint Rails writes the slot's items as a class of numbers
                    _compat = (configProperties [_ms >> "compatibleItems", "isNumber _x", true]) apply {configName _x};
                };
            };
            private _linked = "";
            {
                if ((toLower getText (_x >> "slot")) find "muzzle" >= 0) then {_linked = getText (_x >> "item")};
            } forEach (configProperties [_cfg >> "LinkedItems", "isClass _x", true]);
            diag_log text format ["WEAPON;%1;%2;%3;%4;%5;%6", configName _cfg, configName (inheritsFrom _cfg),
                getNumber (_cfg >> "type"), getText (_cfg >> "displayName"), _linked, str _compat];
            _nw = _nw + 1;
        };
    } forEach _carried;

    diag_log text format [">>>> FACTION DUMP END <<<< %1 unit(s), %2 group(s), %3 weapon(s)", _n, _gid, _nw];
    systemChat format ["FACTION DUMP DONE %1: %2 units, %3 groups, %4 weapons", _factions, _n, _gid, _nw];
};
