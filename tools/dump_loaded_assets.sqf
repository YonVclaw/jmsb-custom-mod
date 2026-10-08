// LOADED ASSETS - everything the running game offers to build factions from,
// written to the RPT with the mod each class comes from. Paste into the debug
// console (Eden, in-mission or Zeus), Local Exec, wait for the chat line.
//
// Only what a mission can place or issue: scope 2 (public) classes.
//
//   FACTION;class;side;displayName;mod
//   ASSET;kind;class;side;faction;displayName;mod
//     kind: Man, Car, Tank, Helicopter, Plane, Ship, Static, UAV, Backpack, Object (CfgVehicles)
//           Rifle, Pistol, Launcher, Optic, Muzzle, Pointer, Bipod, Uniform, Vest, Headgear,
//           NVG, Binocular, Item (CfgWeapons)
//           Magazine (CfgMagazines), Facewear (CfgGlasses)
//   ASSETS DONE;count
//
// Pull them out of the RPT with: grep -E "^[0-9:]+ (FACTION|ASSET);" <rpt>

[] spawn {
    private _sideName = {
        params ["_n"];
        ["East", "West", "Independent", "Civilian"] param [_n, str _n]
    };
    private _mod = {
        params ["_cfg"];
        private _m = configSourceMod _cfg;
        ["Arma 3", _m] select (_m isNotEqualTo "")
    };
    private _clean = {
        params ["_s"];
        (_s splitString ";") joinString ","
    };
    private _n = 0;

    diag_log text ">>>> LOADED ASSETS BEGIN <<<<";

    {
        if (getNumber (_x >> "side") in [0, 1, 2, 3]) then {
            diag_log text format ["FACTION;%1;%2;%3;%4", configName _x, [getNumber (_x >> "side")] call _sideName,
                [getText (_x >> "displayName")] call _clean, [_x] call _mod];
        };
    } forEach ("true" configClasses (configFile >> "CfgFactionClasses"));

    // ---- men, vehicles, statics, backpacks -------------------------------
    {
        private _cfg = _x;
        if (getNumber (_cfg >> "scope") == 2) then {
            private _cls = configName _cfg;
            private _kind = switch (true) do {
                case (getNumber (_cfg >> "isBackpack") == 1): {"Backpack"};
                case (getNumber (_cfg >> "isUav") == 1): {"UAV"};
                case (_cls isKindOf "CAManBase"): {"Man"};
                case (_cls isKindOf "Tank"): {"Tank"};
                case (_cls isKindOf "Car"): {"Car"};
                case (_cls isKindOf "Helicopter"): {"Helicopter"};
                case (_cls isKindOf "Plane"): {"Plane"};
                case (_cls isKindOf "Ship"): {"Ship"};
                case (_cls isKindOf "StaticWeapon"): {"Static"};
                default {"Object"};
            };
            // buildings and props are thousands of lines nobody builds a faction from
            if (_kind != "Object") then {
                diag_log text format ["ASSET;%1;%2;%3;%4;%5;%6", _kind, _cls, [getNumber (_cfg >> "side")] call _sideName,
                    getText (_cfg >> "faction"), [getText (_cfg >> "displayName")] call _clean, [_cfg] call _mod];
                _n = _n + 1;
            };
        };
    } forEach ("true" configClasses (configFile >> "CfgVehicles"));

    // ---- weapons, attachments, wearables, items --------------------------
    {
        private _cfg = _x;
        if (getNumber (_cfg >> "scope") == 2) then {
            private _type = getNumber (_cfg >> "type");
            private _info = getNumber (_cfg >> "ItemInfo" >> "type");
            private _kind = switch (true) do {
                case (_type == 1): {"Rifle"};
                case (_type == 2): {"Pistol"};
                case (_type == 4): {"Launcher"};
                case (_type == 4096): {"Binocular"};
                case (_info == 201): {"Optic"};
                case (_info == 101): {"Muzzle"};
                case (_info == 301): {"Pointer"};
                case (_info == 302): {"Bipod"};
                case (_info == 801): {"Uniform"};
                case (_info == 701): {"Vest"};
                case (_info == 605): {"Headgear"};
                case (_info == 616): {"NVG"};
                default {"Item"};
            };
            diag_log text format ["ASSET;%1;%2;;;%3;%4", _kind, configName _cfg,
                [getText (_cfg >> "displayName")] call _clean, [_cfg] call _mod];
            _n = _n + 1;
        };
    } forEach ("true" configClasses (configFile >> "CfgWeapons"));

    {
        if (getNumber (_x >> "scope") == 2) then {
            diag_log text format ["ASSET;Magazine;%1;;;%2;%3", configName _x, [getText (_x >> "displayName")] call _clean, [_x] call _mod];
            _n = _n + 1;
        };
    } forEach ("true" configClasses (configFile >> "CfgMagazines"));

    {
        if (getNumber (_x >> "scope") == 2) then {
            diag_log text format ["ASSET;Facewear;%1;;;%2;%3", configName _x, [getText (_x >> "displayName")] call _clean, [_x] call _mod];
            _n = _n + 1;
        };
    } forEach ("true" configClasses (configFile >> "CfgGlasses"));

    diag_log text format [">>>> LOADED ASSETS END <<<< %1", _n];
    systemChat format ["LOADED ASSETS DONE: %1 classes written to the RPT", _n];
};
