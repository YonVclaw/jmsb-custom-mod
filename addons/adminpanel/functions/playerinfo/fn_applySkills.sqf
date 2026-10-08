/*
    Author: TheTimidShade

    Description:
        Gives the selected player skills for THIS mission only

    Parameters:
        NONE

    Returns:
        NONE
*/

#include "\z\jmfsb\addons\adminpanel\script_component.hpp"

disableSerialization;


private _admp_display = uiNamespace getVariable ['admp_displayVar', displayNull];
if (isNull _admp_display) exitWith {}; // check display exists

private _admp_playerlist_listbox = _admp_display displayCtrl IDC_ADMINPANEL_PLAYERLIST_LISTBOX;
private _medic_combo = _admp_display displayCtrl IDC_ADMINPANEL_PLAYER_SKILLS_MEDICAL_COMBO;
private _engineer_combo = _admp_display displayCtrl IDC_ADMINPANEL_PLAYER_SKILLS_ENGINEER_COMBO;
private _brc_checkbox = _admp_display displayCtrl IDC_ADMINPANEL_PLAYER_SKILLS_EOD_CHECKBOX;
private _dra_checkbox = _admp_display displayCtrl IDC_ADMINPANEL_PLAYER_SKILLS_DRA_CHECKBOX;
private _isr_checkbox = _admp_display displayCtrl IDC_ADMINPANEL_PLAYER_SKILLS_ISR_CHECKBOX;
private _jfo_checkbox = _admp_display displayCtrl IDC_ADMINPANEL_PLAYER_SKILLS_JFO_CHECKBOX;
private _uav_checkbox = _admp_display displayCtrl IDC_ADMINPANEL_PLAYER_SKILLS_UAV_CHECKBOX;
private _mks_checkbox = _admp_display displayCtrl IDC_ADMINPANEL_PLAYER_SKILLS_MKS_CHECKBOX;
private _snp_checkbox = _admp_display displayCtrl IDC_ADMINPANEL_PLAYER_SKILLS_SNP_CHECKBOX;

private _player = [_admp_playerlist_listbox] call admp_fnc_playerFromSelection; // get selected player
if (isNull _player) exitWith {["Admin Panel", "No target found!", [0.831, 0.267, 0.267, 1]] call EFUNC(notify,notify); playSound "addItemFailed";}; // if there is no selected target exit

private _medicSkill = _medic_combo lbValue (lbCurSel _medic_combo);
private _engineerSkill = _engineer_combo lbValue (lbCurSel _engineer_combo);
private _brcSkill = cbChecked _brc_checkbox;
private _draSkill = cbChecked _dra_checkbox;
private _isrSkill = cbChecked _isr_checkbox;
private _jfoSkill = cbChecked _jfo_checkbox;
private _uavSkill = cbChecked _uav_checkbox;
private _mksSkill = cbChecked _mks_checkbox;
private _snpSkill = cbChecked _snp_checkbox;

// THIS MISSION ONLY (user, 2026-10-07: "whats done in admin is for that
// op/game only ... for it to be permanent it needs to be in pac"). With
// TAC//PAC loaded these are PAC SKILLS held for the rest of the mission -
// their ACE abilities, their arsenal lists and their tags, through respawns
// and rejoins - kept on the server and never stored (jmfsb_pac_fnc_sessionSkills).
// Ticking a box adds to the player's permanent skills; it cannot take one away.
// Leader is not here: it is a role.
if (!isNil "jmfsb_pac_fnc_sessionSkills") exitWith {
    private _skills = [];
    if (_medicSkill isEqualTo 1) then {_skills pushBack "skill:cls"};
    if (_medicSkill isEqualTo 2) then {_skills pushBack "skill:medic"};
    if (_engineerSkill > 0) then {_skills pushBack "skill:eng"};
    if (_engineerSkill isEqualTo 2) then {_skills pushBack "engineer:2"};
    if (_brcSkill) then {_skills pushBack "skill:breacher"};
    if (_draSkill) then {_skills pushBack "var:draWhitelisted=true"};
    if (_isrSkill) then {_skills pushBack "skill:isr"};
    if (_jfoSkill) then {_skills pushBack "skill:jfo"};
    if (_uavSkill) then {_skills pushBack "skill:uav"};
    if (_mksSkill) then {_skills pushBack "skill:marksman"};
    if (_snpSkill) then {_skills pushBack "skill:sniper"};
    [player, _player, _skills] remoteExec ["jmfsb_pac_fnc_sessionSkills", 2];
    ["Admin Panel", format ["Gave %1 these skills for this mission. Permanent skills are set in TAC//PAC.", name _player], [0.4, 0.702, 0.4, 1]] call EFUNC(notify,notify);
    playSound "3DEN_notificationDefault";
};

// Without TAC//PAC: the bare variables, as before.
_player setVariable ["ace_medical_medicClass", _medicSkill, true];
_player setVariable ["ACE_IsEngineer", _engineerSkill, true];
_player setVariable ["ACE_isEOD", _brcSkill, true];
_player setVariable ["draWhitelisted", _draSkill, true];
_player setVariable ["isISR", _isrSkill, true];
_player setVariable ["isJFO", _jfoSkill, true];
_player setVariable ["UAVHacker", _uavSkill, true];

// setUnitTrait needs the unit local, so run on the unit's machine
[_player, ["Medic", _medicSkill > 0]] remoteExecCall ["setUnitTrait", _player];
[_player, ["Engineer", _engineerSkill > 0]] remoteExecCall ["setUnitTrait", _player];
[_player, ["ExplosiveSpecialist", _brcSkill]] remoteExecCall ["setUnitTrait", _player];
[_player, ["UAVHacker", _uavSkill]] remoteExecCall ["setUnitTrait", _player];

["Admin Panel", format ["Applied skills to %1!", name _player], [0.4, 0.702, 0.4, 1]] call EFUNC(notify,notify);
playSound "3DEN_notificationDefault";
