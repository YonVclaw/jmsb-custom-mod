class CfgWeapons {
    class ItemCore;
    class InventoryOpticsItem_Base_F;
    class ace_xm157_prototype;
    class optic_Nightstalker;

    class GVAR(xm157_prototype): ace_xm157_prototype {
        scope=2;
        scopeCurator=2;
        scopeArsenal=2;
        author = QAUTHOR;
        displayName = "[JMSB] XM157 pre-Alpha";
    };

    class GVAR(optic_Nightstalker): optic_Nightstalker {
        author = QAUTHOR;
        displayName="[JMSB] Nightstalker";
        descriptionShort = "Nightstalker Sight<br />Magnification: 1x-10x";
        class ItemInfo: InventoryOpticsItem_Base_F {
            mass=12;
            opticType=1;
            optics=1;
            modelOptics="\A3\Weapons_f\acc\reticle_nightstalker_F";
            class OpticsModes {
                class NCTALKEP {
                    opticsID = 1;
                    useModelOptics = 1;
                    opticsPPEffects[] = {"OpticsCHAbera1","OpticsBlur1"};
                    opticsZoomMin = 0.25/1;
                    opticsZoomMax = 0.25/10;
                    opticsZoomInit = 0.25/10;
                    distanceZoomMin = 100;
                    distanceZoomMax = 1600;
                    discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600};
                    discreteDistanceInitIndex = 1;
                    discreteFOV[] = {
                        0.25/1,0.25/2,0.25/3,0.25/4,0.25/5,
                        0.25/6,0.25/7,0.25/8,0.25/9,0.25/10
                    };
                    discreteInitIndex = 0;
                    memoryPointCamera = "opticView";
                    visionMode[] = {"Normal","NVG","Ti"};
                    thermalMode[] = {0};
                    opticsFlare = 1;
                    opticsDisablePeripherialVision = 1;
                    cameraDir="";
                };
                class Iron: NCTALKEP {
                    opticsID = 2;
                    useModelOptics = 0;
                    opticsPPEffects[] = {"",""};
                    opticsFlare = 0;
                    opticsDisablePeripherialVision = 0;
                    discreteDistance[] = {200};
                    discreteDistanceInitIndex = 0;
                    opticsZoomMin = 0.25;
                    opticsZoomMax = 1.25;
                    opticsZoomInit = 0.75;
                    memoryPointCamera = "eye";
                    visionMode[] = {};
                };
            };
        };
        inertia=0.2;
    };

    class GVAR(optic_AMS_base): ItemCore {
        author = QAUTHOR;
        displayName="[JMSB] AMS Base";
        descriptionShort="[JMSB] AMS (NVG)";
        _generalMacro="optic_AMS_base";
        scope=0;
        scopeCurator=0;
        scopeArsenal=0;
        model="\A3\Weapons_F_Mark\Acc\acco_ams_F.p3d";
        weaponInfoType="RscWeaponZeroing";
        overviewPicture="\A3\Data_F_Mark\Images\watermarkInfo_page17_ca.paa";
        class ItemInfo: InventoryOpticsItem_Base_F {
            mass=14;
            opticType=2;
            weaponInfoType="RscWeaponRangeZeroingFOV";
            optics=1;
            modelOptics="\A3\Weapons_F_Mark\Acc\reticle_acco_ams_F";
            class OpticsModes {
                class AMS {
                    opticsID=1;
                    opticsDisplayName="WFOV";
                    useModelOptics=1;
                    opticsPPEffects[]= {
                        "OpticsCHAbera2",
                        "OpticsBlur3"
                    };
                    opticsZoomMin = 0.25/1;
                    opticsZoomMax = 0.25/25;
                    opticsZoomInit = 0.25/25;
                    discreteDistance[]={300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000};
                    discreteDistanceInitIndex=2;
                    distanceZoomMin=300;
                    distanceZoomMax=2000;
                    discretefov[]={
                        0.25/1,0.25/2,0.25/3,0.25/4,0.25/5,
                        0.25/6,0.25/7,0.25/8,0.25/9,0.25/10,
                        0.25/11,0.25/12,0.25/13,0.25/14,0.25/15,
                        0.25/16,0.25/17,0.25/18,0.25/19,0.25/20,
                        0.25/21,0.25/22,0.25/23,0.25/24,0.25/25
                    };
                    discreteInitIndex=0;
                    memoryPointCamera="opticView";
                    modelOptics[]= {
                        "\A3\Weapons_F_Mark\Acc\reticle_acco_ams_F",
                        "\A3\Weapons_F_Mark\Acc\reticle_acco_ams_z_F"
                    };
                    visionMode[]= {"Normal","NVG"};
                    opticsFlare=1;
                    opticsDisablePeripherialVision=1;
                    cameraDir="";
                };
                class Iron {
                    opticsID=2;
                    opticsDisplayName="";
                    useModelOptics=0;
                    opticsPPEffects[]={};
                    opticsFlare=0;
                    opticsDisablePeripherialVision=0;
                    opticsZoomMin=0.25;
                    opticsZoomMax=1.25;
                    opticsZoomInit=0.75;
                    memoryPointCamera="eye";
                    visionMode[] = {};
                    discretefov[]={};
                    discreteDistance[]={200};
                    discreteDistanceInitIndex=0;
                    distanceZoomMin=200;
                    distanceZoomMax=200;
                    discreteInitIndex=0;
                    cameraDir="";
                };
            };
        };
        inertia=0.2;
    };

    class GVAR(optic_AMS): GVAR(optic_AMS_base) {
        author = QAUTHOR;
        _generalMacro="optic_AMS";
        scope=2;
        scopeCurator=1;
        scopeArsenal=2;
        displayName="[JMSB] AMS (Black)";
        picture="\a3\Weapons_F_Mark\Data\UI\icon_optic_AMS_ca.paa";
    };

    class GVAR(optic_AMS_khk): GVAR(optic_AMS) {
        author = QAUTHOR;
        _generalMacro="optic_AMS_khk";
        displayName="[JMSB] AMS (Khaki)";
        picture="\a3\Weapons_F_Mark\Data\UI\icon_optic_AMS_khk_ca.paa";
        model="\A3\Weapons_F_Mark\Acc\acco_ams_khk_F.p3d";
    };

    class GVAR(optic_AMS_snd): GVAR(optic_AMS) {
        author = QAUTHOR;
        _generalMacro="optic_AMS_snd";
        displayName="[JMSB] AMS (Sand)";
        picture="\a3\Weapons_F_Mark\Data\UI\icon_optic_AMS_snd_ca.paa";
        model="\A3\Weapons_F_Mark\Acc\acco_ams_snd_F.p3d";
    };

    class GVAR(optic_AMSTI_base): ItemCore {
        author = QAUTHOR;
        displayName="[JMSB] AMS-TI Base";
        descriptionShort="[JMSB] AMS (NVG/TI)";
        _generalMacro="optic_AMSTI_base";
        scope=0;
        scopeCurator=0;
        scopeArsenal=0;
        model="\A3\Weapons_F_Mark\Acc\acco_ams_F.p3d";
        weaponInfoType="RscWeaponZeroing";
        overviewPicture="\A3\Data_F_Mark\Images\watermarkInfo_page17_ca.paa";
        class ItemInfo: InventoryOpticsItem_Base_F {
            mass=14;
            opticType=2;
            weaponInfoType="RscWeaponRangeZeroingFOV";
            optics=1;
            modelOptics="\A3\Weapons_F_Mark\Acc\reticle_acco_ams_F";
            class OpticsModes {
                class AMS {
                    opticsID=1;
                    opticsDisplayName="WFOV";
                    useModelOptics=1;
                    opticsPPEffects[]= {
                        "OpticsCHAbera2",
                        "OpticsBlur3"
                    };
                    opticsZoomMin = 0.25/1;
                    opticsZoomMax = 0.25/25;
                    opticsZoomInit = 0.25/25;
                    discreteDistance[]={300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000};
                    discreteDistanceInitIndex=2;
                    distanceZoomMin=300;
                    distanceZoomMax=2000;
                    discretefov[]={
                        0.25/1,0.25/2,0.25/3,0.25/4,0.25/5,
                        0.25/6,0.25/7,0.25/8,0.25/9,0.25/10,
                        0.25/11,0.25/12,0.25/13,0.25/14,0.25/15,
                        0.25/16,0.25/17,0.25/18,0.25/19,0.25/20,
                        0.25/21,0.25/22,0.25/23,0.25/24,0.25/25
                    };
                    discreteInitIndex=0;
                    memoryPointCamera="opticView";
                    modelOptics[]= {
                        "\A3\Weapons_F_Mark\Acc\reticle_acco_ams_F",
                        "\A3\Weapons_F_Mark\Acc\reticle_acco_ams_z_F"
                    };
                    visionMode[]= {"Normal","NVG","Ti"};
                    thermalMode[] = {0};
                    opticsFlare=1;
                    opticsDisablePeripherialVision=1;
                    cameraDir="";
                };
                class Iron {
                    opticsID=2;
                    opticsDisplayName="";
                    useModelOptics=0;
                    opticsPPEffects[]={};
                    opticsFlare=0;
                    opticsDisablePeripherialVision=0;
                    opticsZoomMin=0.25;
                    opticsZoomMax=1.25;
                    opticsZoomInit=0.75;
                    memoryPointCamera="eye";
                    visionMode[] = {};
                    discretefov[]={};
                    discreteDistance[]={200};
                    discreteDistanceInitIndex=0;
                    distanceZoomMin=200;
                    distanceZoomMax=200;
                    discreteInitIndex=0;
                    cameraDir="";
                };
            };
        };
        inertia=0.2;
    };

    class GVAR(optic_AMSTI): GVAR(optic_AMSTI_base) {
        author = QAUTHOR;
        _generalMacro="optic_AMSTI";
        scope=2;
        scopeCurator=1;
        scopeArsenal=2;
        displayName="[JMSB] AMS-TI (Black)";
        picture="\a3\Weapons_F_Mark\Data\UI\icon_optic_AMS_ca.paa";
    };

    class GVAR(optic_AMSTI_khk):  GVAR(optic_AMSTI) {
        author = QAUTHOR;
        _generalMacro="optic_AMSTI_khk";
        displayName="[JMSB] AMS-TI (Khaki)";
        picture="\a3\Weapons_F_Mark\Data\UI\icon_optic_AMS_khk_ca.paa";
        model="\A3\Weapons_F_Mark\Acc\acco_ams_khk_F.p3d";
    };

    class GVAR(optic_AMSTI_snd):  GVAR(optic_AMSTI) {
        author = QAUTHOR;
        _generalMacro="optic_AMSTI_snd";
        displayName="[JMSB] AMS-TI (Sand)";
        picture="\a3\Weapons_F_Mark\Data\UI\icon_optic_AMS_snd_ca.paa";
        model="\A3\Weapons_F_Mark\Acc\acco_ams_snd_F.p3d";
    };

    class GVAR(optic_DMS): ace_xm157_prototype {
        author = QAUTHOR;
        scope=2;
        scopeCurator=2;
        scopeArsenal=2;
        displayName="[JMSB] XM157 - AMS Base";
        descriptionShort="[JMSB] AMS (NVG)";
        picture = "\a3\Weapons_F\acc\Data\UI\icon_optic_DMS_ca.paa";
        model = "\A3\Weapons_F_EPA\Acc\acco_marksman_F.p3d";
        _generalMacro="optic_AMS_base";
        overviewPicture="\A3\Data_F_Mark\Images\watermarkInfo_page17_ca.paa";
        class CBA_ScriptedOptic {
            bodyTexture = "\z\ace\addons\xm157\data\ace_vector_body_co.paa";
            bodyTextureSize = 1;
            hideMagnification = 1;
            disableTilt = 0;
        };
        class ItemInfo: InventoryOpticsItem_Base_F {
            mass=14;
            opticType=2;
            weaponInfoType = "ace_xm157_info";
            optics = 1;
            inertia=0.2;
            modelOptics = "\x\cba\addons\optics\cba_optic_big_100.p3d";
            class OpticsModes {
                class lpvo {
                    opticsID = 1;
                    useModelOptics = 1;
                    opticsPPEffects[] = { "OpticsCHAbera1", "OpticsBlur1" };
                    opticsZoomMin = "8 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
                    opticsZoomMax = "1 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
                    opticsZoomInit = "1 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
                    discreteDistance[] = {100};
                    discreteDistanceInitIndex = 0;
                    distanceZoomMin = 100;
                    distanceZoomMax = 100;
                    memoryPointCamera = "opticView";
                    visionMode[] = {};
                    opticsFlare = 1;
                    opticsDisablePeripherialVision = 1;
                    cameraDir = "";
                };
                class Iron {
                    opticsID=2;
                    opticsDisplayName="";
                    useModelOptics=0;
                    opticsPPEffects[]={};
                    opticsFlare=0;
                    opticsDisablePeripherialVision=0;
                    opticsZoomMin=0.25;
                    opticsZoomMax=1.25;
                    opticsZoomInit=0.75;
                    memoryPointCamera="eye";
                    visionMode[] = {};
                    discretefov[]={};
                    discreteDistance[]={200};
                    discreteDistanceInitIndex=0;
                    distanceZoomMin=200;
                    distanceZoomMax=200;
                    discreteInitIndex=0;
                    cameraDir="";
                };
            };
        };
    };

};
