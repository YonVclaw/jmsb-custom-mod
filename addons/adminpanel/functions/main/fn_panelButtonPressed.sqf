/*
    Author: TheTimidShade

    Description:
        Handles the CBA key press for the admin panel actions

    Parameters:
        0: ARRAY - Keypress info passed by key press event
        
    Returns:
        NOTHING
*/

#include "\z\jmfsb\addons\adminpanel\script_component.hpp"

private _shift = _this#2;

if (player call admp_fnc_isAdmin) then {
    if (_shift) then {
        createDialog "jmfsb_adminpanel_message";
    } else {
        createDialog "jmfsb_adminpanel_console";
    };
} else {
    createDialog "jmfsb_adminpanel_message";
};
