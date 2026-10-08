class CfgWeapons {
    // ACE overheating - explicit barrelMass override on the JCA Gen4 rifle base classes.
    // Set on the *_base_F bases; all camo/attachment variants inherit via the config tree.
    // (ACE's default barrelMass = 0.55 x WeaponSlotsInfo.mass/22; shown for reference only -
    //  once barrelMass is set explicitly, inventory mass no longer affects overheating.)
    class Rifle_Base_F;                               // vanilla base (JCA parent)

    class JCA_arifle_M4A4_base_F: Rifle_Base_F {      // mass 70 -> ACE default 1.75
        ace_overheating_barrelMass = 4.43;
    };

    class JCA_arifle_SR10_base_F: Rifle_Base_F {      // mass 120 -> ACE default 3.00
        ace_overheating_barrelMass = 3.72;
    };

    class JCA_arifle_SR25_base_F: Rifle_Base_F {      // mass 140 -> ACE default 3.50
        ace_overheating_barrelMass = 3.91;
    };
};
