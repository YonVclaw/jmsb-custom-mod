// ONE MAN PER THEATRE, AND THAT IS THE WHOLE FACTION.
//
// MFRC IS A PLAYER FACTION. Almost everything about a player is set in the
// mission - the slot's loadout, its gear, its vehicle - so a config roster of
// thirty specialists would be thirty classes nobody ever spawns. One scout is
// what a slot needs in order to exist; the mission does the rest.
//
// THE LOADOUT IS AN ARRAY, NOT A PILE OF weapons[] LINES. That is the
// authoring loop the faction builder handoff describes (section 9): an arsenal
// export becomes a getUnitLoadout array and a spawn hook applies it. The
// weapons[]/linkedItems[] underneath are what the EDITOR reads for its preview
// and what the man carries before the hook runs - they mirror the array rather
// than competing with it.
//
// ONLY THE UNIFORM CHANGES BETWEEN THE FOUR. Vest and booniehat are the same
// on all of them by call - the camo that reads at fifty metres is the one he
// is wearing, not the one on his hat.

// CBA'S EXTENDED EVENT HANDLERS, DECLARED SO THEY CAN BE KEPT.
// A class that writes its own EventHandlers REPLACES the parent's, and the
// parent's is where CBA put its XEH hooks - so every one of these men was
// reported as "does not support Extended Event Handlers" and dropped out of
// everything built on them. Inheriting the class below inside our own
// EventHandlers keeps both: CBA's hooks and our loadout init.
class CBA_Extended_EventHandlers;

class CfgVehicles {
    // FORWARD DECLARATION, NOT A DEPENDENCY. B_CTRG_Soldier_F is the base
    // game's (Apex), defined in an addon that is not this one; declaring it
    // is what lets this config inherit from it. It replaced Aegis's
    // B_CTRG_Soldier_v2_F when Aegis left the load order - the vest went the
    // same way, from Aegis's holster rig to Contact's light KBT-01 in olive.
    class B_CTRG_Soldier_F;

    class GVAR(tna_ReconScout): B_CTRG_Soldier_F {
        scope = 2;
        scopeCurator = 2;
        author = QAUTHOR;
        displayName = "Recon Scout";
        side = 1;
        faction = QGVAR(tna);
        editorSubcategory = "EdSubcat_Personnel_SpecialForces";

        uniformClass = "jmfsb_uniform_sof_SOF_U_B_SFFatigues_Shortsleeve_tna";
        identityTypes[] = {"Head_NATO","LanguageENG_F","G_NATO_default"};

        // PISTOL ONLY, BY DESIGN. He observes and leaves; the Glock is what
        // he has when leaving stops being an option.
        weapons[] = {"jmfsb_weapons_hgun_G17_khaki_F", "Throw", "Put"};
        respawnWeapons[] = {"jmfsb_weapons_hgun_G17_khaki_F", "Throw", "Put"};
        magazines[] = {"MiniGrenade", "MiniGrenade", "SmokeShell", "SmokeShell"};
        respawnMagazines[] = {"MiniGrenade", "MiniGrenade", "SmokeShell", "SmokeShell"};
        linkedItems[] = {"V_CarrierRigKBT_01_light_Olive_F","H_Booniehat_tna_F","ItemMap","ItemGPS","ItemCompass"};
        respawnLinkedItems[] = {"V_CarrierRigKBT_01_light_Olive_F","H_Booniehat_tna_F","ItemMap","ItemGPS","ItemCompass"};

        ALiVE_orbatCreator_loadout[] = {{},{},{"jmfsb_weapons_hgun_G17_khaki_F","","","",{"jmfsb_weapons_17Rnd_9x21_Mag",17},{},""},{"jmfsb_uniform_sof_SOF_U_B_SFFatigues_Shortsleeve_tna",{{"FirstAidKit",1},{"optic_NVS",1}}},{"V_CarrierRigKBT_01_light_Olive_F",{{"MiniGrenade",2,1},{"SmokeShell",2,1}}},{},"H_Booniehat_tna_F","",{},{"ItemMap","ItemGPS","","ItemCompass","ACE_Altimeter",""}};

        class EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
            class GVAR(loadout) {
                init = "if (local (_this select 0)) then {_apply = {(_this select 0) spawn {sleep 0.2;if !(_this getVariable ['ALiVE_OverrideLoadout',false]) then {_loadout = getArray(configFile >> 'CfgVehicles' >> (typeOf _this) >> 'ALiVE_orbatCreator_loadout'); _this setUnitLoadout _loadout;reload _this}}};_this call _apply;(_this select 0) addMPEventHandler ['MPRespawn', _apply];};";
            };
        };
    };

    class GVAR(ocp_ReconScout): B_CTRG_Soldier_F {
        scope = 2;
        scopeCurator = 2;
        author = QAUTHOR;
        displayName = "Recon Scout";
        side = 1;
        faction = QGVAR(ocp);
        editorSubcategory = "EdSubcat_Personnel_SpecialForces";

        uniformClass = "jmfsb_uniform_sof_SOF_U_B_SFFatigues_Shortsleeve_ocp";
        identityTypes[] = {"Head_NATO","LanguageENG_F","G_NATO_default"};

        // PISTOL ONLY, BY DESIGN. He observes and leaves; the Glock is what
        // he has when leaving stops being an option.
        weapons[] = {"jmfsb_weapons_hgun_G17_khaki_F", "Throw", "Put"};
        respawnWeapons[] = {"jmfsb_weapons_hgun_G17_khaki_F", "Throw", "Put"};
        magazines[] = {"MiniGrenade", "MiniGrenade", "SmokeShell", "SmokeShell"};
        respawnMagazines[] = {"MiniGrenade", "MiniGrenade", "SmokeShell", "SmokeShell"};
        linkedItems[] = {"V_CarrierRigKBT_01_light_Olive_F","jmfsb_headware_H_Booniehat_ocp_F","ItemMap","ItemGPS","ItemCompass"};
        respawnLinkedItems[] = {"V_CarrierRigKBT_01_light_Olive_F","jmfsb_headware_H_Booniehat_ocp_F","ItemMap","ItemGPS","ItemCompass"};

        ALiVE_orbatCreator_loadout[] = {{},{},{"jmfsb_weapons_hgun_G17_khaki_F","","","",{"jmfsb_weapons_17Rnd_9x21_Mag",17},{},""},{"jmfsb_uniform_sof_SOF_U_B_SFFatigues_Shortsleeve_ocp",{{"FirstAidKit",1},{"optic_NVS",1}}},{"V_CarrierRigKBT_01_light_Olive_F",{{"MiniGrenade",2,1},{"SmokeShell",2,1}}},{},"jmfsb_headware_H_Booniehat_ocp_F","",{},{"ItemMap","ItemGPS","","ItemCompass","ACE_Altimeter",""}};

        class EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
            class GVAR(loadout) {
                init = "if (local (_this select 0)) then {_apply = {(_this select 0) spawn {sleep 0.2;if !(_this getVariable ['ALiVE_OverrideLoadout',false]) then {_loadout = getArray(configFile >> 'CfgVehicles' >> (typeOf _this) >> 'ALiVE_orbatCreator_loadout'); _this setUnitLoadout _loadout;reload _this}}};_this call _apply;(_this select 0) addMPEventHandler ['MPRespawn', _apply];};";
            };
        };
    };

    class GVAR(wdl_ReconScout): B_CTRG_Soldier_F {
        scope = 2;
        scopeCurator = 2;
        author = QAUTHOR;
        displayName = "Recon Scout";
        side = 1;
        faction = QGVAR(wdl);
        editorSubcategory = "EdSubcat_Personnel_SpecialForces";

        uniformClass = "jmfsb_uniform_sof_SOF_U_B_SFFatigues_Shortsleeve_wdl";
        identityTypes[] = {"Head_NATO","LanguageENG_F","G_NATO_default"};

        // PISTOL ONLY, BY DESIGN. He observes and leaves; the Glock is what
        // he has when leaving stops being an option.
        weapons[] = {"jmfsb_weapons_hgun_G17_khaki_F", "Throw", "Put"};
        respawnWeapons[] = {"jmfsb_weapons_hgun_G17_khaki_F", "Throw", "Put"};
        magazines[] = {"MiniGrenade", "MiniGrenade", "SmokeShell", "SmokeShell"};
        respawnMagazines[] = {"MiniGrenade", "MiniGrenade", "SmokeShell", "SmokeShell"};
        linkedItems[] = {"V_CarrierRigKBT_01_light_Olive_F","jmfsb_headware_H_Booniehat_Multicam_Woodland_F","ItemMap","ItemGPS","ItemCompass"};
        respawnLinkedItems[] = {"V_CarrierRigKBT_01_light_Olive_F","jmfsb_headware_H_Booniehat_Multicam_Woodland_F","ItemMap","ItemGPS","ItemCompass"};

        ALiVE_orbatCreator_loadout[] = {{},{},{"jmfsb_weapons_hgun_G17_khaki_F","","","",{"jmfsb_weapons_17Rnd_9x21_Mag",17},{},""},{"jmfsb_uniform_sof_SOF_U_B_SFFatigues_Shortsleeve_wdl",{{"FirstAidKit",1},{"optic_NVS",1}}},{"V_CarrierRigKBT_01_light_Olive_F",{{"MiniGrenade",2,1},{"SmokeShell",2,1}}},{},"jmfsb_headware_H_Booniehat_Multicam_Woodland_F","",{},{"ItemMap","ItemGPS","","ItemCompass","ACE_Altimeter",""}};

        class EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
            class GVAR(loadout) {
                init = "if (local (_this select 0)) then {_apply = {(_this select 0) spawn {sleep 0.2;if !(_this getVariable ['ALiVE_OverrideLoadout',false]) then {_loadout = getArray(configFile >> 'CfgVehicles' >> (typeOf _this) >> 'ALiVE_orbatCreator_loadout'); _this setUnitLoadout _loadout;reload _this}}};_this call _apply;(_this select 0) addMPEventHandler ['MPRespawn', _apply];};";
            };
        };
    };

    class GVAR(mtp_ReconScout): B_CTRG_Soldier_F {
        scope = 2;
        scopeCurator = 2;
        author = QAUTHOR;
        displayName = "Recon Scout";
        side = 1;
        faction = QGVAR(mtp);
        editorSubcategory = "EdSubcat_Personnel_SpecialForces";

        uniformClass = "jmfsb_uniform_sof_SOF_U_B_SFFatigues_Shortsleeve_mcam";
        identityTypes[] = {"Head_NATO","LanguageENG_F","G_NATO_default"};

        // PISTOL ONLY, BY DESIGN. He observes and leaves; the Glock is what
        // he has when leaving stops being an option.
        weapons[] = {"jmfsb_weapons_hgun_G17_khaki_F", "Throw", "Put"};
        respawnWeapons[] = {"jmfsb_weapons_hgun_G17_khaki_F", "Throw", "Put"};
        magazines[] = {"MiniGrenade", "MiniGrenade", "SmokeShell", "SmokeShell"};
        respawnMagazines[] = {"MiniGrenade", "MiniGrenade", "SmokeShell", "SmokeShell"};
        linkedItems[] = {"V_CarrierRigKBT_01_light_Olive_F","jmfsb_headware_H_Booniehat_Multicam_F","ItemMap","ItemGPS","ItemCompass"};
        respawnLinkedItems[] = {"V_CarrierRigKBT_01_light_Olive_F","jmfsb_headware_H_Booniehat_Multicam_F","ItemMap","ItemGPS","ItemCompass"};

        ALiVE_orbatCreator_loadout[] = {{},{},{"jmfsb_weapons_hgun_G17_khaki_F","","","",{"jmfsb_weapons_17Rnd_9x21_Mag",17},{},""},{"jmfsb_uniform_sof_SOF_U_B_SFFatigues_Shortsleeve_mcam",{{"FirstAidKit",1},{"optic_NVS",1}}},{"V_CarrierRigKBT_01_light_Olive_F",{{"MiniGrenade",2,1},{"SmokeShell",2,1}}},{},"jmfsb_headware_H_Booniehat_Multicam_F","",{},{"ItemMap","ItemGPS","","ItemCompass","ACE_Altimeter",""}};

        class EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
            class GVAR(loadout) {
                init = "if (local (_this select 0)) then {_apply = {(_this select 0) spawn {sleep 0.2;if !(_this getVariable ['ALiVE_OverrideLoadout',false]) then {_loadout = getArray(configFile >> 'CfgVehicles' >> (typeOf _this) >> 'ALiVE_orbatCreator_loadout'); _this setUnitLoadout _loadout;reload _this}}};_this call _apply;(_this select 0) addMPEventHandler ['MPRespawn', _apply];};";
            };
        };
    };

};
