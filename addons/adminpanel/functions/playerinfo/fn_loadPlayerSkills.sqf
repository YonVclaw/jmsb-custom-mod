/*
    Author: TheTimidShade

    Description:
        Updates the player skill boxes when a player is selected - what he holds now, permanent and for this mission

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

// The tags PAC puts on him (jmfsb_pac_skillTags) name the skills he holds.
private _tags = _player getVariable ["jmfsb_pac_skillTags", []];
private _medicSkill = _player getVariable ["ace_medical_medicClass", parseNumber (_player getUnitTrait "Medic")];
private _engineerSkill = _player getVariable ["ACE_IsEngineer", parseNumber (_player getUnitTrait "Engineer")];
private _brcSkill = _player getVariable ["ACE_isEOD", _player getUnitTrait "ExplosiveSpecialist"];
private _draSkill = _player getVariable ["draWhitelisted", false];
private _isrSkill = _player getVariable ["isISR", false];
private _jfoSkill = _player getVariable ["isJFO", false];
private _uavSkill = _player getVariable ["UAVHacker", _player getUnitTrait "UAVHacker"];
private _mksSkill = "MKS" in _tags;
private _snpSkill = "SNP" in _tags;

if (isNull _player) then {
    _medicSkill = 0;
    _engineerSkill = 0;
    _brcSkill = false;
    _draSkill = false;
    _isrSkill = false;
    _jfoSkill = false;
    _uavSkill = false;
    _mksSkill = false;
    _snpSkill = false;
};

_medic_combo lbSetCurSel _medicSkill;
_engineer_combo lbSetCurSel _engineerSkill;
_brc_checkbox cbSetChecked (_brcSkill isEqualTo true);
_dra_checkbox cbSetChecked (_draSkill isEqualTo true);
_isr_checkbox cbSetChecked (_isrSkill isEqualTo true);
_jfo_checkbox cbSetChecked (_jfoSkill isEqualTo true);
_uav_checkbox cbSetChecked (_uavSkill isEqualTo true);
_mks_checkbox cbSetChecked _mksSkill;
_snp_checkbox cbSetChecked _snpSkill;
