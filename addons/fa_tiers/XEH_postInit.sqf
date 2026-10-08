#include "script_component.hpp"

if (!isServer) exitWith {};

// THE TIER 2 FLOOR, CHECKED WHERE VANILLA'S NUMBERS EXIST. A text editor
// cannot read the base game's CfgAmmo; a running mission can.
["fa.tiers", "check every tier 2 round against its base game ancestor", {
    [] call FUNC(checkFloor)
}] call EFUNC(common,addDebugCommand);
