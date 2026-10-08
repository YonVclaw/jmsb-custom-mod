class CfgUnitInsignia {
    // THE BATTALION PATCH - the 1st JMSB crossed arrows. Put on every player's
    // uniform by jmfsb_init_fnc_unitPatch while the Insignia setting is on.
    class GVAR(patch) {
        displayName = "1st JMSB";
        author = QAUTHOR;
        texture = QPATHTOF(images\patches\jmsb_patch_ca.paa);
        textureVehicle = "";
    };
    class gbpmed {
        displayName = "Medic";        // Name displayed in Arsenal
        author = QAUTHOR;              // Author displayed in Arsenal
        texture = "z\jmfsb\addons\media\images\patches\pmed.paa";   // Image path
        textureVehicle = "";             // Does nothing, reserved for future use
    };
    class gbpeod {
        displayName = "EOD";        // Name displayed in Arsenal
        author = QAUTHOR;              // Author displayed in Arsenal
        texture = "z\jmfsb\addons\media\images\patches\peod.paa";   // Image path
        textureVehicle = "";             // Does nothing, reserved for future use
    };
    class gbpjfire {
        displayName = "JFIRE";        // Name displayed in Arsenal
        author = QAUTHOR;              // Author displayed in Arsenal
        texture = "z\jmfsb\addons\media\images\patches\pjfire.paa";   // Image path
        textureVehicle = "";             // Does nothing, reserved for future use
    };
};
