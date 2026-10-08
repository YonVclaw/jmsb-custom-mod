class CfgVehicles {
    class Logic;
    class Module_F: Logic {
        class AttributesBase {
            class Edit;
        };
        class ModuleDescription;
    };

    // --- the module ----------------------------------------------------------
    // BACK, AND UNDER ITS OLD NAME (user, 2026-10-03: "the module was meant to
    // find clean shore line to place anti ship launcher and radar so the
    // mission maker does not know where they are"). DIVINER dropped it because
    // DIVINER has no TAORs; jmfsb runs ALiVE, which has them. Same class name,
    // so missions that already carry it load it again.
    //
    // NO SIDE ON IT. Every ALiVE commander the players are not on gets its
    // batteries, inside its own TAOR - who the enemy is comes from the mission,
    // not from a field (D59). Placing the module is the switch.
    //
    // OPERATION VALUES ONLY - how many. Where comes from ALiVE: the radar on the
    // coast where it sees the sea, the launchers inland where they cannot.
    class jmfsb_moduleAntiShip: Module_F {
        scope = 2;
        scopeCurator = 0;
        displayName = "JMSB - Anti-Ship Batteries";
        author = QAUTHOR;
        category = "jmfsb_modules";
        function = QFUNC(moduleAntiShip);
        functionPriority = 1;
        isGlobal = 0;
        isTriggerActivated = 0;
        isDisposable = 1;
        is3DEN = 0;
        canSetArea = 1;
        icon = "\a3\ui_f\data\map\markers\nato\o_art.paa";

        class Attributes: AttributesBase {
            class batteriesPerSide: Edit {
                property = QGVAR(batteriesPerSide);
                displayName = "Batteries Per Side";
                tooltip = "How many coastal batteries each enemy commander gets, each sited on its own stretch of coast inside that commander's TAOR. A side whose TAOR has no coast gets none, and the RPT says so.";
                typeName = "NUMBER";
                defaultValue = "1";
                expression = QUOTE(_this setVariable [ARR_2('batteriesPerSide',_value)]);
            };
            class launchersPerBattery: Edit {
                property = QGVAR(launchersPerBattery);
                displayName = "Launchers Per Battery";
                tooltip = "Launchers in each battery, sited inland behind the radar where they cannot see the sea. Each one is its own tube on its own clock.";
                typeName = "NUMBER";
                defaultValue = "2";
                expression = QUOTE(_this setVariable [ARR_2('launchersPerBattery',_value)]);
            };
            class radarsPerBattery: Edit {
                property = QGVAR(radarsPerBattery);
                displayName = "Radars Per Battery";
                tooltip = "Surface search radars on the shoreline, seeing for the launchers. Kill them and the battery is blind. 0 leaves the launchers to search for themselves.";
                typeName = "NUMBER";
                defaultValue = "1";
                expression = QUOTE(_this setVariable [ARR_2('radarsPerBattery',_value)]);
            };
        };

        class ModuleDescription: ModuleDescription {
            description = "Sites coastal anti-ship batteries for every ALiVE commander the players are not on, inside its own TAOR: a surface search radar on the shoreline and launchers inland behind it. Nobody placing the mission knows where. Without ALiVE, the module's own area is the ground and the battery belongs to the side opposing the players. How they fire is under CBA settings, Anti-Ship.";
        };
    };

    // --- the launcher --------------------------------------------------------
    // Ancestry restated so the turret override below has something real to
    // inherit (same pattern as the naval addon). Each link keeps its own
    // parent, and the chain stops at MainTurret without reaching inside it.
    //
    // This is a MERGE, not a replacement: a class body here annotates the
    // vanilla class rather than overwriting it, which is why restating the
    // chain is safe and why the override below has a base to name. Deleting it
    // and reaching for a parentless nested reopen instead severs the turret and
    // strips primaryGunner - that has been tried.
    //
    // DO NOT CHASE the "Duplicate HitPoint name 'HitGun'/'HitTurret'" warnings
    // to this file. VERIFIED, not assumed: a3\static_f_sams\sam_system_04
    // declares HitTurret at line 203 and HitGun at 207 under HitPoints, then
    // declares both again at 451 and 474 inside the turret - and adds a
    // differently-cased `Hitpoints: HitPoints` at 228 on top.
    //
    // The proof it is not ours is in any RPT that spawns statics: the same two
    // lines appear for the untouched vanilla O_T_SAM_System_04_F and
    // O_T_Radar_System_02_F, and for other mods' classes on the same chassis.
    // Ours is named only because ours is the leaf being spawned. It fires once
    // per class at first spawn, not per frame.
    //
    // Silencing it means restating BI's whole damage model on our leaf, which
    // is a real behaviour change to remove two cosmetic lines. Not worth it -
    // unlike the CM_ warnings below, which ARE ours to answer and now are.
    // StaticMGWeapon's Turrets is `Turrets: Turrets` in the game, so it is
    // restated with that parent (declared on StaticWeapon); a bare
    // `class Turrets {` rebinds it - RPT "Updating base class 'Turrets'->''".
    class LandVehicle;
    class StaticWeapon: LandVehicle {
        class Turrets;
    };
    class StaticMGWeapon: StaticWeapon {
        class Turrets: Turrets {
            class MainTurret;
        };
    };
    class SAM_System_04_base_F: StaticMGWeapon {
        class Turrets: Turrets {
            class MainTurret: MainTurret {};
        };
    };
    class O_SAM_System_04_F: SAM_System_04_base_F {
        class Turrets: Turrets {
            class MainTurret: MainTurret {};
        };
    };

    class GVAR(launcher): O_SAM_System_04_F {
        author = QAUTHOR;
        scope = 2;

        // "Cannot evaluate 'CM_none'" / "'CM_Missile'", fixed at the leaf.
        //
        // BI SHIPPED THE MACRO NAMES, NOT THE NUMBERS. a3\static_f_sams\
        // sam_system_04 line 162 reads lockDetectionSystem="CM_none" and 163
        // incomingMissileDetectionSystem="CM_Missile" - strings where the engine
        // wants a number, because the #defines never expanded when the config
        // was built. radar_system_02 has the identical pair at 161-162.
        //
        // Every vehicle on either chassis reports it, ours included, and it is
        // the one part of this that IS ours to answer: restating the two
        // properties with the values the macros stand for costs nothing and
        // takes our two lines out of the log. 0 and 16 are what comparable
        // vanilla statics carry for the same pair.
        lockDetectionSystem = 0;
        incomingMissileDetectionSystem = 16;
        scopeCurator = 2;
        displayName = "3K72 Burevestnik (Anti-Ship)";
        // The SAM chassis is vehicleClass "Autonomous", which Eden maps to the
        // Drones category - land it under Turrets with the other statics instead
        vehicleClass = "Static";
        editorSubcategory = "EdSubcat_Turrets";

        // It fires by script, on the battery's schedule. Leaving the parent's SAM
        // armament on would give it a second job it was never meant to have -
        // and an anti-ship battery that also swats aircraft is an air defence
        // site wearing the wrong name.
        //
        // The missiles live on MainTurret, and the override must colon-inherit
        // (Turrets: Turrets, MainTurret: MainTurret) - a parentless
        // redeclaration shadows the inherited turret instead, which strips the
        // gunner config and floods the RPT with
        // "No entry ... MainTurret.primaryGunner".
        //
        // ONLY the turret is emptied. The vehicle's own weapons[] are left
        // alone - clearing them was once blamed for the CM warnings below and
        // that was wrong; see the two properties above, which are the real
        // cause and are now overridden.
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                weapons[] = {};
                magazines[] = {};
            };
        };
    };

    // --- the decoy -----------------------------------------------------------
    // A missile is not a target Arma's AI can engage, so a crewed vehicle rides
    // along with it and the AI engages that instead. Same technique the CIWS
    // uses; declared here rather than borrowed so this addon stands alone and a
    // mission can have anti-ship fire without loading a point-defence addon.
    class B_UAV_01_F;


    // --- the eyes ------------------------------------------------------------
    // A surface search radar, on the CSAT air-defence set's chassis. It exists
    // so the launchers do not have to see anything: they sit inland behind
    // terrain, and THIS is the thing on the headland with a view of the water -
    // findable, killable, and the difference between a battery that shoots and
    // one that is blind.
    //
    // Only a forward declaration is needed. The turrets are not touched here
    // (the parent's air-search sensor is left exactly as it is; surface search
    // is scripted on top), so there is nothing to reach inside and restate.
    class O_Radar_System_02_F;
    class GVAR(radar): O_Radar_System_02_F {
        author = QAUTHOR;
        scope = 2;
        scopeCurator = 2;
        displayName = "Surface Search Radar";
        // Eden's category comes from vehicleClass, not editorSubcategory - the
        // parent is Autonomous, which files a radar under Drones.
        vehicleClass = "Static";
        editorSubcategory = "EdSubcat_Turrets";

        // Same unexpanded macros as the launcher - radar_system_02 lines
        // 161-162 carry the identical pair. See the note on the launcher.
        lockDetectionSystem = 0;
        incomingMissileDetectionSystem = 16;
    };


    class GVAR(decoyBase): B_UAV_01_F {
        author = QAUTHOR;
        scope = 1;
        scopeCurator = 0;
        displayName = "Inbound Missile";
        model = "\A3\Structures_F\Training\InvisibleTarget_F.p3d";
        icon = "iconExplosiveAT";
        isUav = 0;
        sensitivity = 0;
        sensitivityEar = 0;
        audible = 0;
        camouflage = 0;
        cost = 10000000;
        threat[] = {1, 1, 0};
        armor = 6;
        textSingular = "inbound missile";
        textPlural = "inbound missiles";
    };
    class GVAR(decoy_west): GVAR(decoyBase) { side = 1; faction = "BLU_F"; crew = "B_UAV_AI"; };
    class GVAR(decoy_east): GVAR(decoyBase) { side = 0; faction = "OPF_F"; crew = "O_UAV_AI"; };
    class GVAR(decoy_guer): GVAR(decoyBase) { side = 2; faction = "IND_F"; crew = "I_UAV_AI"; };

    // THE MODULE IS GONE. jmfsb_moduleAntiShip sited batteries for you - switch a
    // side on and it found coastal ground inside that side's ALiVE TAOR markers
    // and put a crewed battery on it. There are no TAORs and no commanders to own
    // them, so the siting had nothing to read; the replacement is not a smaller
    // module but placing the launcher where you want it. Both units bring
    // themselves on line when they are created - see CfgEventHandlers.
};
