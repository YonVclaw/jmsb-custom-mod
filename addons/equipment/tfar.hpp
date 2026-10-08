/*
 * Author: <author>
 * Function description
 *
 * Arguments:
 * 0: Objects <ARRAY>
 * 1: All <BOOL>
 *
 * Return Value:
 * None
 *
 * Example:
 * [[bob, ted], false] call jmfsb_main_fnc_example
 *
 * Public: No
 */


class RscBackPicture;

// class anprc152_radio_dialog {
//     onLoad = QUOTE(if (sunOrMoon < 0.2) then {((_this select 0) displayCtrl TF_IDD_BACKGROUND) ctrlSetText 'PATHTOF(data\152_n.paa)';};);
//     class background: RscBackPicture {
//         text = QPATHTOF(data\152.paa);
//     };
// };

class rt1523g_radio_dialog {
    onLoad = QUOTE(if (sunOrMoon < 0.2) then {((_this select 0) displayCtrl TF_IDD_BACKGROUND) ctrlSetText 'PATHTOF(data\rt1523g_n.paa)';};);
    class background: RscBackPicture {
        text = QPATHTOF(data\rt1523g.paa);
    };
};

class anarc210_radio_dialog {
    class background: RscBackPicture {
        text = QPATHTOF(data\anarc210.paa);
    };
};


class rf7800str_radio_dialog {
    onLoad = QUOTE(if (sunOrMoon < 0.2) then {((_this select 0) displayCtrl TF_IDD_BACKGROUND) ctrlSetText 'PATHTOF(data\rf7800str_n.paa)';};);
    class background: RscBackPicture {
        text = QPATHTOF(data\rf7800str.paa);
    };
};
