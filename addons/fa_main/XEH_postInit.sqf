#include "script_component.hpp"

// Settings may or may not already be up when postInit runs, so cover both
// orderings. Applying twice is idempotent.
["CBA_settingsInitialized", {call FUNC(applySettingOverrides)}] call CBA_fnc_addEventHandler;
call FUNC(applySettingOverrides);
