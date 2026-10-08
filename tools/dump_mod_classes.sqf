// Dump a mod's CfgVehicles to the RPT and the clipboard, for a mod whose
// PBOs cannot be read on disk (RKSL's are Mikero-obfuscated).
//
//   RUN IN THE DEBUG CONSOLE (Eden or in-mission, Zeus works too) with the
//   mod loaded. Edit the prefix list on the first line, paste the whole
//   file, execute. One line per class goes to the RPT as
//
//     MODCLASS;class;parent;scope;side;faction;displayName;isUav;crew;vehicleClass;kind
//
//   and the same text lands on the clipboard - paste it into a file under
//   D:\work\ (for example D:\work\rksl_classes.txt). Only scope 1 and 2
//   classes are listed; scope 0 bases are noise.
//
// WHY THE RPT AND THE CLIPBOARD BOTH: the clipboard is the quick way, the
// RPT is the one that survives a crash and the one tools/ already read.

private _prefixes = ["rksla3"];

private _out = [];
{
    private _cls = configName _x;
    private _lc = toLower _cls;
    if (_prefixes findIf {(_lc find toLower _x) == 0} > -1) then {
        private _scope = getNumber (_x >> "scope");
        if (_scope > 0) then {
            private _kind = "other";
            if (_cls isKindOf "UAV") then {_kind = "uav"};
            if (_cls isKindOf "UGV_01_base_F" || {_cls isKindOf "UGV_02_base_F"}) then {_kind = "ugv"};
            if (_cls isKindOf "StaticWeapon") then {_kind = "static"};
            if (_cls isKindOf "CAManBase") then {_kind = "man"};
            if (_cls isKindOf "Bag_Base") then {_kind = "backpack"};
            if (_cls isKindOf "Car") then {_kind = "car"};
            if (_cls isKindOf "Air" && {_kind == "other"}) then {_kind = "air"};
            _out pushBack (format ["MODCLASS;%1;%2;%3;%4;%5;%6;%7;%8;%9;%10",
                _cls,
                configName (inheritsFrom _x),
                _scope,
                getNumber (_x >> "side"),
                getText (_x >> "faction"),
                getText (_x >> "displayName"),
                getNumber (_x >> "isUav"),
                getText (_x >> "crew"),
                getText (_x >> "vehicleClass"),
                _kind
            ]);
        };
    };
} forEach ("true" configClasses (configFile >> "CfgVehicles"));

{diag_log text _x} forEach _out;
copyToClipboard (_out joinString endl);
systemChat format ["%1 class(es) dumped to RPT and clipboard", count _out];
