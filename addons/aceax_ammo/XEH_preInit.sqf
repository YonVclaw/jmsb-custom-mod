#include "script_component.hpp"

ADDON = false;
LOG(MSG_INIT);

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

// THE OPTION PANEL'S STATE, per arsenal session: the family + members it was
// last built for (so a row click only moves the marks), the axes it drew, the
// controls it made, and its height in grid units.
GVAR(built) = "";
GVAR(drawn) = [];
GVAR(controls) = [];
GVAR(adjusted) = 0;

// family -> the variant the player last picked, lowercase. It is what survives
// the next collapse when the highlighted row is not in the family, so moving
// to another weapon and back keeps the tracer colour that was chosen.
GVAR(choice) = createHashMap;

// family -> the members that were in the panel before the last collapse. It
// is all the dropdown may ever offer: ACE had already filtered the list by
// what the weapon takes and what the arsenal carries, and the family's whole
// roster from config would let a player pick a magazine that fails both.
GVAR(present) = createHashMap;

// The whole index, once. Building it here rather than on first use keeps the
// cost off the frame the arsenal opens on.
private _indexed = call FUNC(buildIndex);
INFO_2("%1 magazine(s) in %2 famil(ies)",_indexed,count GVAR(axes));

// NAMES THE TWO TABS IT ACTUALLY AFFECTS. The weapon-magazine tabs are
// @aceaxatt's since 1.1.0.0 and have their own switch; a checkbox here still
// called "ammunition variants" would read as the one that turns those off too.
[QGVAR(enabled), "CHECKBOX", ["Collapse grenade and explosive variants",
    "Folds throwables that differ only in colour - smoke, chemlights, hand flares - into one arsenal row on the Grenades and Explosives tabs, with a dropdown to pick the variant. Off shows every one on its own row. The weapon magazine tabs are folded by ACE Arsenal Extended - Attachments and are not affected by this."],
    ["ACE Arsenal", "Ammunition"], true, false] call CBA_fnc_addSetting;

[QGVAR(debug), "CHECKBOX", ["Log the ammunition collapse",
    "Writes what every collapse saw and did to the RPT: which control held the rows, how many there were, which families folded and which row each kept. For finding out why the panel did not fold."],
    ["ACE Arsenal", "Ammunition"], false, false] call CBA_fnc_addSetting;

// ACE raises this from fnc_fillRightPanel once the list is built.
[QACEGVAR(arsenal,rightPanelFilled), {_this call FUNC(onRightPanelFilled)}] call CBA_fnc_addEventHandler;

// The panel's controls go with the display; the bookkeeping must not outlive
// them, or the next arsenal would think its panel was already built.
[QACEGVAR(arsenal,displayClosed), {
    GVAR(built) = "";
    GVAR(drawn) = [];
    GVAR(controls) = [];
    GVAR(present) = createHashMap;
}] call CBA_fnc_addEventHandler;

ADDON = true;
