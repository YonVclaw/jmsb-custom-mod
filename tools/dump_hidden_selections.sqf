// Dump hiddenSelections, hiddenSelectionsTextures and TextureSources for a mod whose PBOs cannot be
// read on disk. Creator DLC ships encrypted .ebo, so tools/ can see a class's textures on a sample
// pack but not the ORDER the model's selections take them in - and the game pairs
// hiddenSelectionsTextures[i] with hiddenSelections[i] by index. Guessing that order is what put a
// hull texture on the PGL-625E's wheels, so the camo pipeline refuses to paint these until the real
// order is known. This is how it gets known.
//
//   RUN IN THE DEBUG CONSOLE (Eden or in-mission, Zeus works too) with the mod loaded. Edit the
//   prefix list on the first line if you want other classes, paste the whole file, execute. One line
//   per class goes to the RPT as
//
//     HSEL;class;model;selection1|selection2|...;texture1|texture2|...
//
//   and, for each entry in its appearance menu,
//
//     HSRC;class;entry;displayName;texture1|texture2|...
//
//   The same text lands on the clipboard - paste it into a file under D:\work\ (for example
//   D:\work\ef_selections.txt) and tools/apply_faction_camo.py's map builder can read it.
//
// WHY THE RPT AND THE CLIPBOARD BOTH: the clipboard is the quick way, the RPT is the one that
// survives a crash and the one tools/ already read.

private _prefixes = ["EF_", "lxWS", "O_T_APC_Tracked_02_30mm", "O_UAV_02", "Truck_03_cargo_RF"];

private _out = [];
{
    private _cls = configName _x;
    private _lc = toLower _cls;
    if (_prefixes findIf {(_lc find toLower _x) > -1} > -1) then {
        private _scope = getNumber (_x >> "scope");
        private _sel = getArray (_x >> "hiddenSelections");
        if (_scope > 0 && {count _sel > 0}) then {
            private _tex = getArray (_x >> "hiddenSelectionsTextures");
            _out pushBack format ["HSEL;%1;%2;%3;%4", _cls,
                getText (_x >> "model"),
                (_sel apply {str _x}) joinString "|",
                (_tex apply {str _x}) joinString "|"];

            private _src = _x >> "TextureSources";
            if (isClass _src) then {
                {
                    if (isClass _x) then {
                        _out pushBack format ["HSRC;%1;%2;%3;%4", _cls, configName _x,
                            getText (_x >> "displayName"),
                            ((getArray (_x >> "textures")) apply {str _x}) joinString "|"];
                    };
                } forEach (configProperties [_src, "true", true]);
            };
        };
    };
} forEach ("true" configClasses (configFile >> "CfgVehicles"));

{diag_log text _x} forEach _out;
copyToClipboard (_out joinString endl);
hint format ["%1 lines dumped to the RPT and the clipboard", count _out];
