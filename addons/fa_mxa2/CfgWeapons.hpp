// =====================================================================
//  futureAmmo compat: Frogtop's MXA2 (14in and 10in barrels)
//  The MXA2 sets no ACE barrel figures, so ACE Advanced Ballistics read
//  them as unknown and the FA 6.5 mm ACE_muzzleVelocities / barrelLengths
//  tables (fa_ammo) could not tell the two barrels apart (user, 2026-10-03).
//  Lengths are the barrels' own; the twists are ACE's for the MX (14in)
//  and the MXC (10in), the same barrels' bases.
//  Mass is left alone: the MXA2's 100 / 80 already match the base game's
//  MX and MXC.
// =====================================================================

#define MXA2_14IN_MM 355.6
#define MXA2_10IN_MM 254
#define MX_TWIST_MM 228.6
#define MXC_TWIST_MM 203.2

class CfgWeapons {
    class Rifle_Base_F;
    class arifle_MXA2_14_Base_F: Rifle_Base_F {
        ACE_barrelLength = MXA2_14IN_MM;
        ACE_barrelTwist = MX_TWIST_MM;
    };
    class arifle_MXA2_10_Base_F: arifle_MXA2_14_Base_F {
        ACE_barrelLength = MXA2_10IN_MM;
        ACE_barrelTwist = MXC_TWIST_MM;
    };
};
