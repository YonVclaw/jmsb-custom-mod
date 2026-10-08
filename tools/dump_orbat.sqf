// ORBAT DUMP - every faction, unit, group and property the faction generators
// read, written to the RPT in the format tools/gen_orbat_from_rpt.py parses.
//
//   RUN IN THE DEBUG CONSOLE (Eden, in-mission or Zeus) WITH THE LOAD ORDER
//   THE FACTIONS ARE BUILT FOR. Paste the whole file, Exec, wait for the
//   "ORBAT DUMP DONE" chat line (a minute or so - it walks every class in
//   CfgVehicles). Then, on this machine:
//
//     python tools/gen_us_factions.py        # newest RPT is found on its own
//
// WHY THIS EXISTS. The generators were written against a dump like this one
// and the RPT that held it rolled off; everything since has been patched on
// disk with tools/strip_faction_mods.py and tools/apply_faction_extras.py.
// A fresh dump puts regeneration back on the table for every faction at once,
// old and new. Mods that are gone are filtered by DROP_MODS at build time, so
// the load order does not have to be clean - it has to be COMPLETE: a faction
// not loaded is a faction not dumped.
//
// THE LINE FORMATS (gen_orbat_from_rpt.RE_*):
//   UNIT;class;faction;parent;side;scope
//   UPROP;class;own|inh;num|txt|arr;;name;value      (unit property)
//   FPROP;faction;own|inh;num|txt|arr;;name;value    (CfgFactionClasses)
//   GROUP;gid;Side;faction;category;class;name
//   GPROP;gid;own|inh;num|txt|arr;;name;value        (group property)
//   GMAN;gid;i;vehicle;rank;[x,y,z]                  (one slot)
//   WEAPON;class;parent;type;displayName;muzzleLinked;[compatible muzzle items]
//     (every visible rifle, pistol and launcher, PRESETS INCLUDED: what its
//      MuzzleSlot takes,
//      under CBA Joint Rails, and the muzzle item it already links)
//   ITEM;class;parent;itemType;scope;scopeArsenal;displayName;model;picture;[hiddenSelectionsTextures]
//     (every optic, muzzle device, pointer/light and bipod - ItemInfo type
//      201/101/301/302 - for the ACEAX attachment compat,
//      D:\Git\AceArsenalExtended-2040 tools/dump_arsenal.py --rpt)
// Arrays are logged as their SQF text ("[""a"",""b""]" style is fine - the
// reader only looks for the quoted names inside). The fifth field, the
// property path, is always empty: only top-level properties are wanted.

[] spawn {
    // EVERY SIDE THAT HAS FACTIONS (user, 2026-08-30: "dump all factions").
    // Civilian was left out until then, which quietly meant no civilian
    // faction, unit or group ever reached the generators - and
    // docs/FACTIONS_CIV.md is written from this dump like the rest.
    private _sides = [0, 1, 2, 3];   // East, West, Independent, Civilian
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
    private _own = {
        params ["_cfg", "_name"];
        if (isNumber (_cfg >> _name) || {isText (_cfg >> _name)} || {isArray (_cfg >> _name)}) then {
            ["inh", "own"] select (configName (inheritsFrom _cfg) == "" || {!(isClass (inheritsFrom _cfg >> _name)) && {(_cfg >> _name) isNotEqualTo (inheritsFrom _cfg >> _name)}})
        } else {"inh"};
    };

    private _n = 0;
    // ---- factions -------------------------------------------------------
    {
        private _cfg = _x;
        private _f = configName _cfg;
        if ((getNumber (_cfg >> "side")) in _sides) then {
            {
                _x params ["_name", "_typ"];
                if (isNumber (_cfg >> _name) || {isText (_cfg >> _name)} || {isArray (_cfg >> _name)}) then {
                    diag_log text format ["FPROP;%1;own;%2;;%3;%4", _f, _typ, _name, [_cfg, _name, _typ] call _val];
                };
            } forEach _fprops;
        };
    } forEach ("true" configClasses (configFile >> "CfgFactionClasses"));

    // ---- units ----------------------------------------------------------
    {
        private _cfg = _x;
        private _scope = getNumber (_cfg >> "scope");
        if (_scope > 0) then {
            private _side = getNumber (_cfg >> "side");
            private _fac = getText (_cfg >> "faction");
            if (_side in _sides && {_fac != ""}) then {
                private _cls = configName _cfg;
                diag_log text format ["UNIT;%1;%2;%3;%4;%5", _cls, _fac, configName (inheritsFrom _cfg), _side, _scope];
                {
                    _x params ["_name", "_typ"];
                    if (isNumber (_cfg >> _name) || {isText (_cfg >> _name)} || {isArray (_cfg >> _name)}) then {
                        diag_log text format ["UPROP;%1;own;%2;;%3;%4", _cls, _typ, _name, [_cfg, _name, _typ] call _val];
                    };
                } forEach _uprops;
                _n = _n + 1;
            };
        };
    } forEach ("true" configClasses (configFile >> "CfgVehicles"));

    // ---- groups ---------------------------------------------------------
    private _gid = 0;
    {
        private _sideCfg = _x;
        private _sideName = configName _sideCfg;
        // "Empty" holds building compositions, not troops - everything else
        // CfgGroups files by side is wanted, civilians included.
        if ((toLower _sideName) in ["west", "east", "indep", "guer", "civ", "civilian"]) then {
            {
                private _facCfg = _x;
                private _fac = configName _facCfg;
                {
                    private _catCfg = _x;
                    private _cat = configName _catCfg;
                    {
                        private _grp = _x;
                        _gid = _gid + 1;
                        diag_log text format ["GROUP;%1;%2;%3;%4;%5;%6", _gid, _sideName, _fac, _cat, configName _grp, getText (_grp >> "name")];
                        {
                            _x params ["_name", "_typ"];
                            if (isNumber (_grp >> _name) || {isText (_grp >> _name)} || {isArray (_grp >> _name)}) then {
                                diag_log text format ["GPROP;%1;own;%2;;%3;%4", _gid, _typ, _name, [_grp, _name, _typ] call _val];
                            };
                        } forEach _gprops;
                        private _i = 0;
                        {
                            diag_log text format ["GMAN;%1;%2;%3;%4;%5", _gid, _i, getText (_x >> "vehicle"), getText (_x >> "rank"), str getArray (_x >> "position")];
                            _i = _i + 1;
                        } forEach ("true" configClasses _grp);
                    } forEach ("true" configClasses _catCfg);
                } forEach ("true" configClasses _facCfg);
            } forEach ("true" configClasses _sideCfg);
        };
    } forEach ("true" configClasses (configFile >> "CfgGroups"));

    // ---- weapons (the suppressor pass, gen_us_factions SUPPRESS) ------------
    private _nw = 0;
    {
        private _cfg = _x;
        private _type = getNumber (_cfg >> "type");
        // scope > 0, NOT == 2. The weapon a man actually carries is usually a
        // PRESET - optics and pointer baked in, scope 1, baseWeapon naming the
        // plain one - and a scope-2 filter missed 42% of everything carried
        // (every JCA M4A4 and E22 AK-12 among them), so those factions got no
        // suppressors at all.
        if (getNumber (_cfg >> "scope") > 0 && {_type in [1, 2, 4]}) then {
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
                if ((toLower getText (_x >> "slot")) find "muzzle" >= 0) then { _linked = getText (_x >> "item"); };
            } forEach (configProperties [_cfg >> "LinkedItems", "isClass _x", true]);
            diag_log text format ["WEAPON;%1;%2;%3;%4;%5;%6", configName _cfg, configName (inheritsFrom _cfg), _type, getText (_cfg >> "displayName"), _linked, str _compat];
            _nw = _nw + 1;
        };
    } forEach ("true" configClasses (configFile >> "CfgWeapons"));

    // ---- attachments (the ACEAX compat, dump_arsenal.py) ---------------------
    private _ni = 0;
    {
        private _cfg = _x;
        private _it = getNumber (_cfg >> "ItemInfo" >> "type");
        if (_it in [101, 201, 301, 302] && {getNumber (_cfg >> "scope") > 0}) then {
            private _sa = if (isNumber (_cfg >> "scopeArsenal")) then {getNumber (_cfg >> "scopeArsenal")} else {-1};
            diag_log text format ["ITEM;%1;%2;%3;%4;%5;%6;%7;%8;%9", configName _cfg, configName (inheritsFrom _cfg), _it,
                getNumber (_cfg >> "scope"), _sa, getText (_cfg >> "displayName"), getText (_cfg >> "model"),
                getText (_cfg >> "picture"), str getArray (_cfg >> "hiddenSelectionsTextures")];
            _ni = _ni + 1;
        };
    } forEach ("true" configClasses (configFile >> "CfgWeapons"));

    diag_log text format ["ORBAT DUMP DONE: %1 unit(s), %2 group(s), %3 weapon(s), %4 attachment(s)", _n, _gid, _nw, _ni];
    systemChat format ["ORBAT DUMP DONE: %1 units, %2 groups, %3 weapons, %4 attachments - now run tools/gen_us_factions.py", _n, _gid, _nw, _ni];
};
