class CfgWeapons {
    class InventoryOpticsItem_Base_F;
    // EF MBS-remote optics (base + colour variants) from the Expeditionary Force
    // characters mod (A3_EFA_characters_f); we inherit their physical scope model
    // and graft ACE's XM157 fire-control system over the top.
    class ef_optic_mbs_remote;
    class ef_optic_mbs_remote_coy;
    class ef_optic_mbs_remote_khk;
    class ef_optic_mbs_remote_sand;
    // The same four, on EF's plain (non-remote) MBS body - the switch is the
    // only thing the two bodies differ in, so the XM157 graft is identical.
    class ef_optic_mbs;
    class ef_optic_mbs_coy;
    class ef_optic_mbs_khk;
    class ef_optic_mbs_sand;


    class GVAR(optic_mbs_remote_157): ef_optic_mbs_remote {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        author = QAUTHOR;
        displayName = "[JMSB] MBS Remote XM157";
        // --- ACE XM157 fire-control system grafted onto the EF MBS-remote body ---
        inertia = 0.3;
        ACE_ScopeHeightAboveRail = 5.52874;
        class CBA_ScriptedOptic {
            bodyTexture = "\z\ace\addons\xm157\data\ace_vector_body_co.paa";
            bodyTextureSize = 1;
            hideMagnification = 1;
            disableTilt = 0;
        };
        weaponInfoType = "ace_xm157_info";
        class ItemInfo: InventoryOpticsItem_Base_F {
            mass = 14;
            optics = 1;
            modelOptics = "\x\cba\addons\optics\cba_optic_big_100.p3d";
            class OpticsModes {
                class lpvo {
                    opticsID = 1;
                    useModelOptics = 1;
                    opticsPPEffects[] = {"OpticsCHAbera1", "OpticsBlur1"};
                    opticsZoomMin = "8 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
                    opticsZoomMax = "1 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
                    opticsZoomInit = "1 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
                    discreteDistance[] = {100};
                    discreteDistanceInitIndex = 0;
                    distanceZoomMin = 100;
                    distanceZoomMax = 100;
                    memoryPointCamera = "opticView";
                    visionMode[] = {"Normal"};
                    opticsFlare = 1;
                    opticsDisablePeripherialVision = 1;
                    cameraDir = "";
                };
                // EF's own secondary and third channels, restored from an
                // in-game config dump (the CDLC data is encrypted on disk).
                // Redeclaring ItemInfo severed them along with everything else;
                // values below are EF's, opticsID renumbered behind the XM157.
                class MBSCollimator {
                    opticsID = 2;
                    useModelOptics = 0;
                    opticsPPEffects[] = {};
                    opticsFlare = 0;
                    opticsDisablePeripherialVision = 0;
                    opticsZoomMin = 0.25;
                    opticsZoomMax = 1.25;
                    opticsZoomInit = 0.75;
                    memoryPointCamera = "eye";
                    visionMode[] = {"Normal"};
                    distanceZoomMin = 200;
                    distanceZoomMax = 200;
                };
                class MBSScope {
                    opticsID = 3;
                    // The third mode is the BACKUP IRON SIGHT, not a third
                    // magnified scope: you flick to it when the glass is
                    // useless - close, or dead battery - so it is 1x down the
                    // weapon's own sights with full peripheral vision. It was
                    // carrying the magnified scope's numbers (0.042 zoom,
                    // blur, peripheral vision off), which is why it read as
                    // nothing but a big zoom.
                    //
                    // useModelOptics stays 0: with 1 this mode renders through
                    // the ItemInfo's modelOptics, which here is CBA's
                    // scripted-optic model - the XM157's screen, not a sight -
                    // and the mode came up dead.
                    useModelOptics = 0;
                    opticsPPEffects[] = {};
                    opticsFlare = 0;
                    opticsDisablePeripherialVision = 0;
                    opticsZoomMin = 0.375;
                    opticsZoomMax = 1.1;
                    opticsZoomInit = 0.75;
                    memoryPointCamera = "eye";
                    visionMode[] = {"Normal"};
                    distanceZoomMin = 100;
                    distanceZoomMax = 100;
                    cameraDir = "";
                };
            };
        };
    };
    class GVAR(optic_mbs_remote_157_coy): ef_optic_mbs_remote_coy {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        author = QAUTHOR;
        displayName = "[JMSB] MBS Remote XM157 (Coyote)";
        // --- ACE XM157 fire-control system grafted onto the EF MBS-remote body ---
        inertia = 0.3;
        ACE_ScopeHeightAboveRail = 5.52874;
        class CBA_ScriptedOptic {
            bodyTexture = "\z\ace\addons\xm157\data\ace_vector_body_co.paa";
            bodyTextureSize = 1;
            hideMagnification = 1;
            disableTilt = 0;
        };
        weaponInfoType = "ace_xm157_info";
        class ItemInfo: InventoryOpticsItem_Base_F {
            mass = 14;
            optics = 1;
            modelOptics = "\x\cba\addons\optics\cba_optic_big_100.p3d";
            class OpticsModes {
                class lpvo {
                    opticsID = 1;
                    useModelOptics = 1;
                    opticsPPEffects[] = {"OpticsCHAbera1", "OpticsBlur1"};
                    opticsZoomMin = "8 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
                    opticsZoomMax = "1 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
                    opticsZoomInit = "1 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
                    discreteDistance[] = {100};
                    discreteDistanceInitIndex = 0;
                    distanceZoomMin = 100;
                    distanceZoomMax = 100;
                    memoryPointCamera = "opticView";
                    visionMode[] = {"Normal"};
                    opticsFlare = 1;
                    opticsDisablePeripherialVision = 1;
                    cameraDir = "";
                };
                // EF's own secondary and third channels, restored from an
                // in-game config dump (the CDLC data is encrypted on disk).
                // Redeclaring ItemInfo severed them along with everything else;
                // values below are EF's, opticsID renumbered behind the XM157.
                class MBSCollimator {
                    opticsID = 2;
                    useModelOptics = 0;
                    opticsPPEffects[] = {};
                    opticsFlare = 0;
                    opticsDisablePeripherialVision = 0;
                    opticsZoomMin = 0.25;
                    opticsZoomMax = 1.25;
                    opticsZoomInit = 0.75;
                    memoryPointCamera = "eye";
                    visionMode[] = {"Normal"};
                    distanceZoomMin = 200;
                    distanceZoomMax = 200;
                };
                class MBSScope {
                    opticsID = 3;
                    // The third mode is the BACKUP IRON SIGHT, not a third
                    // magnified scope: you flick to it when the glass is
                    // useless - close, or dead battery - so it is 1x down the
                    // weapon's own sights with full peripheral vision. It was
                    // carrying the magnified scope's numbers (0.042 zoom,
                    // blur, peripheral vision off), which is why it read as
                    // nothing but a big zoom.
                    //
                    // useModelOptics stays 0: with 1 this mode renders through
                    // the ItemInfo's modelOptics, which here is CBA's
                    // scripted-optic model - the XM157's screen, not a sight -
                    // and the mode came up dead.
                    useModelOptics = 0;
                    opticsPPEffects[] = {};
                    opticsFlare = 0;
                    opticsDisablePeripherialVision = 0;
                    opticsZoomMin = 0.375;
                    opticsZoomMax = 1.1;
                    opticsZoomInit = 0.75;
                    memoryPointCamera = "eye";
                    visionMode[] = {"Normal"};
                    distanceZoomMin = 100;
                    distanceZoomMax = 100;
                    cameraDir = "";
                };
            };
        };
    };
    class GVAR(optic_mbs_remote_157_khk): ef_optic_mbs_remote_khk {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        author = QAUTHOR;
        displayName = "[JMSB] MBS Remote XM157 (Khaki)";
        // --- ACE XM157 fire-control system grafted onto the EF MBS-remote body ---
        inertia = 0.3;
        ACE_ScopeHeightAboveRail = 5.52874;
        class CBA_ScriptedOptic {
            bodyTexture = "\z\ace\addons\xm157\data\ace_vector_body_co.paa";
            bodyTextureSize = 1;
            hideMagnification = 1;
            disableTilt = 0;
        };
        weaponInfoType = "ace_xm157_info";
        class ItemInfo: InventoryOpticsItem_Base_F {
            mass = 14;
            optics = 1;
            modelOptics = "\x\cba\addons\optics\cba_optic_big_100.p3d";
            class OpticsModes {
                class lpvo {
                    opticsID = 1;
                    useModelOptics = 1;
                    opticsPPEffects[] = {"OpticsCHAbera1", "OpticsBlur1"};
                    opticsZoomMin = "8 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
                    opticsZoomMax = "1 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
                    opticsZoomInit = "1 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
                    discreteDistance[] = {100};
                    discreteDistanceInitIndex = 0;
                    distanceZoomMin = 100;
                    distanceZoomMax = 100;
                    memoryPointCamera = "opticView";
                    visionMode[] = {"Normal"};
                    opticsFlare = 1;
                    opticsDisablePeripherialVision = 1;
                    cameraDir = "";
                };
                // EF's own secondary and third channels, restored from an
                // in-game config dump (the CDLC data is encrypted on disk).
                // Redeclaring ItemInfo severed them along with everything else;
                // values below are EF's, opticsID renumbered behind the XM157.
                class MBSCollimator {
                    opticsID = 2;
                    useModelOptics = 0;
                    opticsPPEffects[] = {};
                    opticsFlare = 0;
                    opticsDisablePeripherialVision = 0;
                    opticsZoomMin = 0.25;
                    opticsZoomMax = 1.25;
                    opticsZoomInit = 0.75;
                    memoryPointCamera = "eye";
                    visionMode[] = {"Normal"};
                    distanceZoomMin = 200;
                    distanceZoomMax = 200;
                };
                class MBSScope {
                    opticsID = 3;
                    // The third mode is the BACKUP IRON SIGHT, not a third
                    // magnified scope: you flick to it when the glass is
                    // useless - close, or dead battery - so it is 1x down the
                    // weapon's own sights with full peripheral vision. It was
                    // carrying the magnified scope's numbers (0.042 zoom,
                    // blur, peripheral vision off), which is why it read as
                    // nothing but a big zoom.
                    //
                    // useModelOptics stays 0: with 1 this mode renders through
                    // the ItemInfo's modelOptics, which here is CBA's
                    // scripted-optic model - the XM157's screen, not a sight -
                    // and the mode came up dead.
                    useModelOptics = 0;
                    opticsPPEffects[] = {};
                    opticsFlare = 0;
                    opticsDisablePeripherialVision = 0;
                    opticsZoomMin = 0.375;
                    opticsZoomMax = 1.1;
                    opticsZoomInit = 0.75;
                    memoryPointCamera = "eye";
                    visionMode[] = {"Normal"};
                    distanceZoomMin = 100;
                    distanceZoomMax = 100;
                    cameraDir = "";
                };
            };
        };
    };
    class GVAR(optic_mbs_remote_157_sand): ef_optic_mbs_remote_sand {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        author = QAUTHOR;
        displayName = "[JMSB] MBS Remote XM157 (Sand)";
        // --- ACE XM157 fire-control system grafted onto the EF MBS-remote body ---
        inertia = 0.3;
        ACE_ScopeHeightAboveRail = 5.52874;
        class CBA_ScriptedOptic {
            bodyTexture = "\z\ace\addons\xm157\data\ace_vector_body_co.paa";
            bodyTextureSize = 1;
            hideMagnification = 1;
            disableTilt = 0;
        };
        weaponInfoType = "ace_xm157_info";
        class ItemInfo: InventoryOpticsItem_Base_F {
            mass = 14;
            optics = 1;
            modelOptics = "\x\cba\addons\optics\cba_optic_big_100.p3d";
            class OpticsModes {
                class lpvo {
                    opticsID = 1;
                    useModelOptics = 1;
                    opticsPPEffects[] = {"OpticsCHAbera1", "OpticsBlur1"};
                    opticsZoomMin = "8 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
                    opticsZoomMax = "1 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
                    opticsZoomInit = "1 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
                    discreteDistance[] = {100};
                    discreteDistanceInitIndex = 0;
                    distanceZoomMin = 100;
                    distanceZoomMax = 100;
                    memoryPointCamera = "opticView";
                    visionMode[] = {"Normal"};
                    opticsFlare = 1;
                    opticsDisablePeripherialVision = 1;
                    cameraDir = "";
                };
                // EF's own secondary and third channels, restored from an
                // in-game config dump (the CDLC data is encrypted on disk).
                // Redeclaring ItemInfo severed them along with everything else;
                // values below are EF's, opticsID renumbered behind the XM157.
                class MBSCollimator {
                    opticsID = 2;
                    useModelOptics = 0;
                    opticsPPEffects[] = {};
                    opticsFlare = 0;
                    opticsDisablePeripherialVision = 0;
                    opticsZoomMin = 0.25;
                    opticsZoomMax = 1.25;
                    opticsZoomInit = 0.75;
                    memoryPointCamera = "eye";
                    visionMode[] = {"Normal"};
                    distanceZoomMin = 200;
                    distanceZoomMax = 200;
                };
                class MBSScope {
                    opticsID = 3;
                    // The third mode is the BACKUP IRON SIGHT, not a third
                    // magnified scope: you flick to it when the glass is
                    // useless - close, or dead battery - so it is 1x down the
                    // weapon's own sights with full peripheral vision. It was
                    // carrying the magnified scope's numbers (0.042 zoom,
                    // blur, peripheral vision off), which is why it read as
                    // nothing but a big zoom.
                    //
                    // useModelOptics stays 0: with 1 this mode renders through
                    // the ItemInfo's modelOptics, which here is CBA's
                    // scripted-optic model - the XM157's screen, not a sight -
                    // and the mode came up dead.
                    useModelOptics = 0;
                    opticsPPEffects[] = {};
                    opticsFlare = 0;
                    opticsDisablePeripherialVision = 0;
                    opticsZoomMin = 0.375;
                    opticsZoomMax = 1.1;
                    opticsZoomInit = 0.75;
                    memoryPointCamera = "eye";
                    visionMode[] = {"Normal"};
                    distanceZoomMin = 100;
                    distanceZoomMax = 100;
                    cameraDir = "";
                };
            };
        };
    };
    class GVAR(optic_mbs_157): ef_optic_mbs {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        author = QAUTHOR;
        displayName = "[JMSB] MBS XM157";
        // --- ACE XM157 fire-control system grafted onto the EF MBS body ---
        inertia = 0.3;
        ACE_ScopeHeightAboveRail = 5.52874;
        class CBA_ScriptedOptic {
            bodyTexture = "\z\ace\addons\xm157\data\ace_vector_body_co.paa";
            bodyTextureSize = 1;
            hideMagnification = 1;
            disableTilt = 0;
        };
        weaponInfoType = "ace_xm157_info";
        class ItemInfo: InventoryOpticsItem_Base_F {
            mass = 14;
            optics = 1;
            modelOptics = "\x\cba\addons\optics\cba_optic_big_100.p3d";
            class OpticsModes {
                class lpvo {
                    opticsID = 1;
                    useModelOptics = 1;
                    opticsPPEffects[] = {"OpticsCHAbera1", "OpticsBlur1"};
                    opticsZoomMin = "8 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
                    opticsZoomMax = "1 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
                    opticsZoomInit = "1 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
                    discreteDistance[] = {100};
                    discreteDistanceInitIndex = 0;
                    distanceZoomMin = 100;
                    distanceZoomMax = 100;
                    memoryPointCamera = "opticView";
                    visionMode[] = {"Normal"};
                    opticsFlare = 1;
                    opticsDisablePeripherialVision = 1;
                    cameraDir = "";
                };
                // EF's own secondary and third channels, restored from an
                // in-game config dump (the CDLC data is encrypted on disk).
                // Redeclaring ItemInfo severed them along with everything else;
                // values below are EF's, opticsID renumbered behind the XM157.
                class MBSCollimator {
                    opticsID = 2;
                    useModelOptics = 0;
                    opticsPPEffects[] = {};
                    opticsFlare = 0;
                    opticsDisablePeripherialVision = 0;
                    opticsZoomMin = 0.25;
                    opticsZoomMax = 1.25;
                    opticsZoomInit = 0.75;
                    memoryPointCamera = "eye";
                    visionMode[] = {"Normal"};
                    distanceZoomMin = 200;
                    distanceZoomMax = 200;
                };
                class MBSScope {
                    opticsID = 3;
                    // The third mode is the BACKUP IRON SIGHT, not a third
                    // magnified scope: you flick to it when the glass is
                    // useless - close, or dead battery - so it is 1x down the
                    // weapon's own sights with full peripheral vision. It was
                    // carrying the magnified scope's numbers (0.042 zoom,
                    // blur, peripheral vision off), which is why it read as
                    // nothing but a big zoom.
                    //
                    // useModelOptics stays 0: with 1 this mode renders through
                    // the ItemInfo's modelOptics, which here is CBA's
                    // scripted-optic model - the XM157's screen, not a sight -
                    // and the mode came up dead.
                    useModelOptics = 0;
                    opticsPPEffects[] = {};
                    opticsFlare = 0;
                    opticsDisablePeripherialVision = 0;
                    opticsZoomMin = 0.375;
                    opticsZoomMax = 1.1;
                    opticsZoomInit = 0.75;
                    memoryPointCamera = "eye";
                    visionMode[] = {"Normal"};
                    distanceZoomMin = 100;
                    distanceZoomMax = 100;
                    cameraDir = "";
                };
            };
        };
    };
    class GVAR(optic_mbs_157_coy): ef_optic_mbs_coy {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        author = QAUTHOR;
        displayName = "[JMSB] MBS XM157 (Coyote)";
        // --- ACE XM157 fire-control system grafted onto the EF MBS body ---
        inertia = 0.3;
        ACE_ScopeHeightAboveRail = 5.52874;
        class CBA_ScriptedOptic {
            bodyTexture = "\z\ace\addons\xm157\data\ace_vector_body_co.paa";
            bodyTextureSize = 1;
            hideMagnification = 1;
            disableTilt = 0;
        };
        weaponInfoType = "ace_xm157_info";
        class ItemInfo: InventoryOpticsItem_Base_F {
            mass = 14;
            optics = 1;
            modelOptics = "\x\cba\addons\optics\cba_optic_big_100.p3d";
            class OpticsModes {
                class lpvo {
                    opticsID = 1;
                    useModelOptics = 1;
                    opticsPPEffects[] = {"OpticsCHAbera1", "OpticsBlur1"};
                    opticsZoomMin = "8 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
                    opticsZoomMax = "1 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
                    opticsZoomInit = "1 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
                    discreteDistance[] = {100};
                    discreteDistanceInitIndex = 0;
                    distanceZoomMin = 100;
                    distanceZoomMax = 100;
                    memoryPointCamera = "opticView";
                    visionMode[] = {"Normal"};
                    opticsFlare = 1;
                    opticsDisablePeripherialVision = 1;
                    cameraDir = "";
                };
                // EF's own secondary and third channels, restored from an
                // in-game config dump (the CDLC data is encrypted on disk).
                // Redeclaring ItemInfo severed them along with everything else;
                // values below are EF's, opticsID renumbered behind the XM157.
                class MBSCollimator {
                    opticsID = 2;
                    useModelOptics = 0;
                    opticsPPEffects[] = {};
                    opticsFlare = 0;
                    opticsDisablePeripherialVision = 0;
                    opticsZoomMin = 0.25;
                    opticsZoomMax = 1.25;
                    opticsZoomInit = 0.75;
                    memoryPointCamera = "eye";
                    visionMode[] = {"Normal"};
                    distanceZoomMin = 200;
                    distanceZoomMax = 200;
                };
                class MBSScope {
                    opticsID = 3;
                    // The third mode is the BACKUP IRON SIGHT, not a third
                    // magnified scope: you flick to it when the glass is
                    // useless - close, or dead battery - so it is 1x down the
                    // weapon's own sights with full peripheral vision. It was
                    // carrying the magnified scope's numbers (0.042 zoom,
                    // blur, peripheral vision off), which is why it read as
                    // nothing but a big zoom.
                    //
                    // useModelOptics stays 0: with 1 this mode renders through
                    // the ItemInfo's modelOptics, which here is CBA's
                    // scripted-optic model - the XM157's screen, not a sight -
                    // and the mode came up dead.
                    useModelOptics = 0;
                    opticsPPEffects[] = {};
                    opticsFlare = 0;
                    opticsDisablePeripherialVision = 0;
                    opticsZoomMin = 0.375;
                    opticsZoomMax = 1.1;
                    opticsZoomInit = 0.75;
                    memoryPointCamera = "eye";
                    visionMode[] = {"Normal"};
                    distanceZoomMin = 100;
                    distanceZoomMax = 100;
                    cameraDir = "";
                };
            };
        };
    };
    class GVAR(optic_mbs_157_khk): ef_optic_mbs_khk {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        author = QAUTHOR;
        displayName = "[JMSB] MBS XM157 (Khaki)";
        // --- ACE XM157 fire-control system grafted onto the EF MBS body ---
        inertia = 0.3;
        ACE_ScopeHeightAboveRail = 5.52874;
        class CBA_ScriptedOptic {
            bodyTexture = "\z\ace\addons\xm157\data\ace_vector_body_co.paa";
            bodyTextureSize = 1;
            hideMagnification = 1;
            disableTilt = 0;
        };
        weaponInfoType = "ace_xm157_info";
        class ItemInfo: InventoryOpticsItem_Base_F {
            mass = 14;
            optics = 1;
            modelOptics = "\x\cba\addons\optics\cba_optic_big_100.p3d";
            class OpticsModes {
                class lpvo {
                    opticsID = 1;
                    useModelOptics = 1;
                    opticsPPEffects[] = {"OpticsCHAbera1", "OpticsBlur1"};
                    opticsZoomMin = "8 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
                    opticsZoomMax = "1 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
                    opticsZoomInit = "1 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
                    discreteDistance[] = {100};
                    discreteDistanceInitIndex = 0;
                    distanceZoomMin = 100;
                    distanceZoomMax = 100;
                    memoryPointCamera = "opticView";
                    visionMode[] = {"Normal"};
                    opticsFlare = 1;
                    opticsDisablePeripherialVision = 1;
                    cameraDir = "";
                };
                // EF's own secondary and third channels, restored from an
                // in-game config dump (the CDLC data is encrypted on disk).
                // Redeclaring ItemInfo severed them along with everything else;
                // values below are EF's, opticsID renumbered behind the XM157.
                class MBSCollimator {
                    opticsID = 2;
                    useModelOptics = 0;
                    opticsPPEffects[] = {};
                    opticsFlare = 0;
                    opticsDisablePeripherialVision = 0;
                    opticsZoomMin = 0.25;
                    opticsZoomMax = 1.25;
                    opticsZoomInit = 0.75;
                    memoryPointCamera = "eye";
                    visionMode[] = {"Normal"};
                    distanceZoomMin = 200;
                    distanceZoomMax = 200;
                };
                class MBSScope {
                    opticsID = 3;
                    // The third mode is the BACKUP IRON SIGHT, not a third
                    // magnified scope: you flick to it when the glass is
                    // useless - close, or dead battery - so it is 1x down the
                    // weapon's own sights with full peripheral vision. It was
                    // carrying the magnified scope's numbers (0.042 zoom,
                    // blur, peripheral vision off), which is why it read as
                    // nothing but a big zoom.
                    //
                    // useModelOptics stays 0: with 1 this mode renders through
                    // the ItemInfo's modelOptics, which here is CBA's
                    // scripted-optic model - the XM157's screen, not a sight -
                    // and the mode came up dead.
                    useModelOptics = 0;
                    opticsPPEffects[] = {};
                    opticsFlare = 0;
                    opticsDisablePeripherialVision = 0;
                    opticsZoomMin = 0.375;
                    opticsZoomMax = 1.1;
                    opticsZoomInit = 0.75;
                    memoryPointCamera = "eye";
                    visionMode[] = {"Normal"};
                    distanceZoomMin = 100;
                    distanceZoomMax = 100;
                    cameraDir = "";
                };
            };
        };
    };
    class GVAR(optic_mbs_157_sand): ef_optic_mbs_sand {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        author = QAUTHOR;
        displayName = "[JMSB] MBS XM157 (Sand)";
        // --- ACE XM157 fire-control system grafted onto the EF MBS body ---
        inertia = 0.3;
        ACE_ScopeHeightAboveRail = 5.52874;
        class CBA_ScriptedOptic {
            bodyTexture = "\z\ace\addons\xm157\data\ace_vector_body_co.paa";
            bodyTextureSize = 1;
            hideMagnification = 1;
            disableTilt = 0;
        };
        weaponInfoType = "ace_xm157_info";
        class ItemInfo: InventoryOpticsItem_Base_F {
            mass = 14;
            optics = 1;
            modelOptics = "\x\cba\addons\optics\cba_optic_big_100.p3d";
            class OpticsModes {
                class lpvo {
                    opticsID = 1;
                    useModelOptics = 1;
                    opticsPPEffects[] = {"OpticsCHAbera1", "OpticsBlur1"};
                    opticsZoomMin = "8 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
                    opticsZoomMax = "1 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
                    opticsZoomInit = "1 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
                    discreteDistance[] = {100};
                    discreteDistanceInitIndex = 0;
                    distanceZoomMin = 100;
                    distanceZoomMax = 100;
                    memoryPointCamera = "opticView";
                    visionMode[] = {"Normal"};
                    opticsFlare = 1;
                    opticsDisablePeripherialVision = 1;
                    cameraDir = "";
                };
                // EF's own secondary and third channels, restored from an
                // in-game config dump (the CDLC data is encrypted on disk).
                // Redeclaring ItemInfo severed them along with everything else;
                // values below are EF's, opticsID renumbered behind the XM157.
                class MBSCollimator {
                    opticsID = 2;
                    useModelOptics = 0;
                    opticsPPEffects[] = {};
                    opticsFlare = 0;
                    opticsDisablePeripherialVision = 0;
                    opticsZoomMin = 0.25;
                    opticsZoomMax = 1.25;
                    opticsZoomInit = 0.75;
                    memoryPointCamera = "eye";
                    visionMode[] = {"Normal"};
                    distanceZoomMin = 200;
                    distanceZoomMax = 200;
                };
                class MBSScope {
                    opticsID = 3;
                    // The third mode is the BACKUP IRON SIGHT, not a third
                    // magnified scope: you flick to it when the glass is
                    // useless - close, or dead battery - so it is 1x down the
                    // weapon's own sights with full peripheral vision. It was
                    // carrying the magnified scope's numbers (0.042 zoom,
                    // blur, peripheral vision off), which is why it read as
                    // nothing but a big zoom.
                    //
                    // useModelOptics stays 0: with 1 this mode renders through
                    // the ItemInfo's modelOptics, which here is CBA's
                    // scripted-optic model - the XM157's screen, not a sight -
                    // and the mode came up dead.
                    useModelOptics = 0;
                    opticsPPEffects[] = {};
                    opticsFlare = 0;
                    opticsDisablePeripherialVision = 0;
                    opticsZoomMin = 0.375;
                    opticsZoomMax = 1.1;
                    opticsZoomInit = 0.75;
                    memoryPointCamera = "eye";
                    visionMode[] = {"Normal"};
                    distanceZoomMin = 100;
                    distanceZoomMax = 100;
                    cameraDir = "";
                };
            };
        };
    };

};
