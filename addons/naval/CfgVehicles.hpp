class CfgVehicles {
    // Ancestry, restated so the override below has something real to inherit.
    // Each link keeps its own parent: a colon-less `class X {}` on a class that
    // already exists severs it from ITS parent, and severing StaticMGWeapon
    // would take the gunner position, the optics and the hit points with it.
    //
    // The chain stops at MainTurret rather than reaching inside it. Declaring
    // nested classes deeper than you need hides the ones you did not declare -
    // that is how an earlier turret edit in this mod silently removed a
    // commander's optics from every vehicle in the game that shared the parent.
    // That includes Turrets itself: StaticMGWeapon's is `Turrets: Turrets` in
    // the game (parent declared on StaticWeapon), and a bare `class Turrets {`
    // rebinds it - RPT "Updating base class 'Turrets'->''".
    class LandVehicle;
    class StaticWeapon: LandVehicle {
        class Turrets;
    };
    class StaticMGWeapon: StaticWeapon {
        class Turrets: Turrets {
            class MainTurret;
        };
    };
    class B_Ship_MRLS_01_base_F: StaticMGWeapon {
        class Turrets: Turrets {
            class MainTurret: MainTurret {};
        };
    };
    class B_Ship_MRLS_01_F: B_Ship_MRLS_01_base_F {
        class Turrets: Turrets {
            class MainTurret: MainTurret {};
        };
    };

    // The destroyer's VLS, loaded for air defence instead of land attack.
    //
    // MIM-145 Defender: at 16 km it is the longest-ranged surface-to-air weapon
    // in the game, tied only with the S-750 - whose missile literally inherits
    // from this one. Everything else is medium range: RIM-162 and Titan AA have
    // less than half the reach.
    //
    // Stock loadout for reference: weapon_VLS_01 firing
    // magazine_Missiles_Cruise_01_x18 - land attack, replaced wholesale here.
    class GVAR(vlsAA): B_Ship_MRLS_01_F {
        author = QAUTHOR;
        scope = 2;
        scopeCurator = 2;
        displayName = "Destroyer VLS (MIM-145 Defender)";

        class Turrets: Turrets {
            class MainTurret: MainTurret {
                weapons[] = {"weapon_mim145Launcher"};
                // 24 rounds, matching the stock cell count closely enough that
                // it still reads as the same launcher.
                magazines[] = {
                    "magazine_Missile_mim145_x4",
                    "magazine_Missile_mim145_x4",
                    "magazine_Missile_mim145_x4",
                    "magazine_Missile_mim145_x4",
                    "magazine_Missile_mim145_x4",
                    "magazine_Missile_mim145_x4"
                };
            };
        };
    };
};
