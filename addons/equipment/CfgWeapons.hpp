class CfgWeapons {
    class CBA_MiscItem;
    class ACE_Vector;
    class Uniform_Base;
    class VestItem;
    class V_RebreatherB;
    class ItemCore;
    class UniformItem;
    class U_B_CTRG_Soldier_F: Uniform_Base {};
    class U_B_Wetsuit;
    class Binocular;
    class Laserdesignator: Binocular {
            visionMode[] = {"Normal","NVG","TI"};
    };
    class GVAR(Vector_Designator): ACE_Vector {
        author = "NemesisRE";
        displayName = "[JMSB] ACE Vector Designator (NVG/TI)";
        descriptionShort = "Rangefinder/Designator";
        simulation = "weapon";
        magazines[] = {"Laserbatteries"};
        cursor = "laserDesignator";
        cursorAim = "EmptyCursor";
        cursorAimOn = "CursorAimOn";
        showSwitchAction = 1;
        weaponInfoType = "jmfsb_RscOptics_vector";
        class WeaponSlotsInfo {
            mass = 18;
        };
        Laser = 1;
        visionMode[] = {"Normal","NVG","TI"};
        thermalMode[] = {0};
        opticsZoomMin = 0.0099999998;
        opticsZoomMax = 0.050000001;
        opticsZoomInit = 0.050000001;
        distanceZoomMin = 100;
        distanceZoomMax = 2300;
        minRange = 150;
        midRange = 500;
        maxRange = 5000;
    };
    class GVAR(Vector_Designator_NVG): GVAR(Vector_Designator) {
        displayName = "[JMSB] ACE Vector Designator (NVG)";
        visionMode[] = {"Normal","NVG"};
        thermalMode[] = {};
    };
    class GVAR(rebreather): V_RebreatherB {
        author = QAUTHOR;
        displayName = "[JMSB] Rebreather";
        class ItemInfo: VestItem {
            uniformModel = "\A3\Characters_F\Common\equip_rebreather";
            vestType = "Rebreather";
            mass = 10;
            passThrough = 0.8;
            hiddenSelections[] = {"camo"};
            containerClass = "Supply180";
            class HitpointsProtectionInfo {
                class Neck {
                    hitpointName = "HitNeck";
                    armor = 69;
                    passThrough = 0.2;
                };
                class Chest {
                    hitpointName = "HitChest";
                    armor = 69;
                    passThrough = 0.2;
                };
                class Diaphragm {
                    hitpointName = "HitDiaphragm";
                    armor = 69;
                    passThrough = 0.2;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 69;
                    passThrough = 0.2;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.2;
                };
            };
        };
    };
    class GVAR(Wetsuit): U_B_Wetsuit {
        author = QAUTHOR;
        displayName = "[JMSB] Wetsuit";
        picture = "\A3\characters_f\data\ui\icon_U_B_Wetsuit_CA.paa";
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_original_F.p3d";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {"A3\Characters_F\Common\Data\diver_suit_nato_co.paa"};
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = "B_diver_F";
            containerClass = "Supply80";
            uniformType = "Neopren";
            mass = 40;
        };
    };
    // class tsp_paperclip: CBA_MiscItem {
    //     ACE_isTool = 1;
    //     scope = 2;
    // };
    // class tsp_lockpick: tsp_paperclip {
    //     ACE_isTool = 1;
    // };
    class sps_black_hornet_01_Static_F {
        ACE_isTool = 1;
    };
    class ItemMicroDAGRMisc: CBA_MiscItem {
        ACE_isTool = 1;
    };
    class optic_MRD : ItemCore {};
};
