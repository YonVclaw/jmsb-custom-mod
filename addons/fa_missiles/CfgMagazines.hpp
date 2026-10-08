// Vehicle missile magazines — vanilla vehicle/pylon magazine bodies with FA
// natures. Vehicle turrets receive them via the CfgWeapons.hpp magazines[]
// patches (mediumcaliber pattern); the Pylon* variants inherit their vanilla
// parent's hardpoints[] + pylonWeapon, so they appear in the dynamic-loadout
// (pylon) editor with no vehicle patching at all.
class CfgMagazines {
    // Ground Titan bodies (Kamysh-style 2-tube, Cheetah-style 4-tube)
    class 2Rnd_GAT_missiles;
    class 4Rnd_Titan_long_missiles;
    // Scalpel bodies (Kajman 8-rail + dynamic loadout racks)
    class 8Rnd_LG_scalpel;
    class PylonRack_1Rnd_LG_scalpel;
    class PylonRack_3Rnd_LG_scalpel;
    // DAGR bodies
    class 12Rnd_PG_missiles;
    class 24Rnd_PG_missiles;
    class PylonRack_12Rnd_PG_missiles;
    // Macer bodies (CAS jets)
    class 6Rnd_Missile_AGM_02_F;
    class PylonMissile_1Rnd_Missile_AGM_02_F;

    // =========================================================
    // BGM-185 Broadsword — ground-vehicle ATGM
    // =========================================================
    class FA_2Rnd_BGM185_Broadsword: 2Rnd_GAT_missiles {
        author = QAUTHOR;
        displayName = "[JMSB] 2x BGM-185 Broadsword";
        descriptionShort = "BGM-185 Broadsword (2040)<br/>Tandem F&F top-attack ATGM, NLOS-capable — 1300mm RHA, 10 km";
        ammo = "FA_M_BGM185_Broadsword";
    };
    class FA_4Rnd_BGM185_Broadsword: FA_2Rnd_BGM185_Broadsword {
        displayName = "[JMSB] 4x BGM-185 Broadsword";
        count = 4;
    };

    // =========================================================
    // AGM-190 Wraith — attack-helo / UCAV ATGM
    // =========================================================
    class FA_8Rnd_AGM190_Wraith: 8Rnd_LG_scalpel {
        author = QAUTHOR;
        displayName = "[JMSB] 8x AGM-190 Wraith";
        descriptionShort = "AGM-190 Wraith (2040)<br/>Tri-mode tandem HEAT + frag sleeve, LOAL — 1200mm RHA, 12 km";
        ammo = "FA_M_AGM190_Wraith";
    };
    class FA_PylonRack_1Rnd_AGM190_Wraith: PylonRack_1Rnd_LG_scalpel {
        author = QAUTHOR;
        displayName = "[JMSB] 1x AGM-190 Wraith";
        descriptionShort = "AGM-190 Wraith (2040)<br/>Tri-mode tandem HEAT + frag sleeve, LOAL — 1200mm RHA, 12 km";
        ammo = "FA_M_AGM190_Wraith";
    };
    class FA_PylonRack_3Rnd_AGM190_Wraith: PylonRack_3Rnd_LG_scalpel {
        author = QAUTHOR;
        displayName = "[JMSB] 3x AGM-190 Wraith";
        descriptionShort = "AGM-190 Wraith (2040)<br/>Tri-mode tandem HEAT + frag sleeve, LOAL — 1200mm RHA, 12 km";
        ammo = "FA_M_AGM190_Wraith";
    };

    // =========================================================
    // AGM-205 Warhammer — fixed-wing standoff AGM
    // =========================================================
    class FA_2Rnd_AGM205_Warhammer: 6Rnd_Missile_AGM_02_F {
        author = QAUTHOR;
        displayName = "[JMSB] 2x AGM-205 Warhammer";
        descriptionShort = "AGM-205 Warhammer (2040)<br/>Standoff penetrating blast-frag, anti-structure / anti-ship — 25 km";
        ammo = "FA_M_AGM205_Warhammer";
        count = 2;
    };
    class FA_PylonMissile_1Rnd_AGM205_Warhammer: PylonMissile_1Rnd_Missile_AGM_02_F {
        author = QAUTHOR;
        displayName = "[JMSB] 1x AGM-205 Warhammer";
        descriptionShort = "AGM-205 Warhammer (2040)<br/>Standoff penetrating blast-frag, anti-structure / anti-ship — 25 km";
        ammo = "FA_M_AGM205_Warhammer";
    };

    // =========================================================
    // MIM-165 Sentry — SPAAG / AA-vehicle SAM
    // =========================================================
    class FA_4Rnd_MIM165_Sentry: 4Rnd_Titan_long_missiles {
        author = QAUTHOR;
        displayName = "[JMSB] 4x MIM-165 Sentry";
        descriptionShort = "MIM-165 Sentry (2040)<br/>Dual-seeker SAM, proximity prefrag — jets to drones, 12 km";
        ammo = "FA_M_MIM165_Sentry";
    };

    // =========================================================
    // AGR-40 Hydra-P — laser-guided rocket pod
    // =========================================================
    class FA_12Rnd_AGR40_HydraP: 12Rnd_PG_missiles {
        author = QAUTHOR;
        displayName = "[JMSB] 12x AGR-40 Hydra-P";
        descriptionShort = "AGR-40 Hydra-P (2040)<br/>SAL multipurpose guided rocket, C-UAS proximity mode — 600mm RHA, 8 km";
        ammo = "FA_M_AGR40_HydraP";
    };
    class FA_24Rnd_AGR40_HydraP: 24Rnd_PG_missiles {
        author = QAUTHOR;
        displayName = "[JMSB] 24x AGR-40 Hydra-P";
        descriptionShort = "AGR-40 Hydra-P (2040)<br/>SAL multipurpose guided rocket, C-UAS proximity mode — 600mm RHA, 8 km";
        ammo = "FA_M_AGR40_HydraP";
    };
    class FA_PylonRack_12Rnd_AGR40_HydraP: PylonRack_12Rnd_PG_missiles {
        author = QAUTHOR;
        displayName = "[JMSB] 12x AGR-40 Hydra-P";
        descriptionShort = "AGR-40 Hydra-P (2040)<br/>SAL multipurpose guided rocket, C-UAS proximity mode — 600mm RHA, 8 km";
        ammo = "FA_M_AGR40_HydraP";
    };

    // =========================================================
    // XM1200 Copperhead — loitering munition (2-round vehicle canister)
    // =========================================================
    class FA_2Rnd_XM1200_Copperhead: 2Rnd_GAT_missiles {
        author = QAUTHOR;
        displayName = "[JMSB] 2x XM1200 Copperhead";
        descriptionShort = "XM1200 Copperhead (2040)<br/>Loitering munition — launch unlocked to loiter + autonomous terminal, or lock before launch — 800mm RHA, 40 km";
        ammo = "FA_M_XM1200_Copperhead";
    };

    // =========================================================
    // MIM-166 Roadrunner — C-UAS missile (4-round vehicle rack)
    // =========================================================
    class FA_4Rnd_MIM166_Roadrunner: 4Rnd_Titan_long_missiles {
        author = QAUTHOR;
        displayName = "[JMSB] 4x MIM-166 Roadrunner";
        descriptionShort = "MIM-166 Roadrunner (2040)<br/>C-UAS hard-kill, proximity prefrag — drones and loitering munitions, 4 km";
        ammo = "FA_M_MIM166_Roadrunner";
    };

    // =========================================================
    // Single-round variants — for 1-tube launchers (e.g. VVE Titan rack) whose
    // reload granularity is one missile per tube. Same ammo, count = 1.
    // =========================================================
    class FA_1Rnd_BGM185_Broadsword: FA_2Rnd_BGM185_Broadsword { displayName = "[JMSB] 1x BGM-185 Broadsword"; count = 1; };
    class FA_1Rnd_XM1200_Copperhead: FA_2Rnd_XM1200_Copperhead { displayName = "[JMSB] 1x XM1200 Copperhead"; count = 1; };
    class FA_1Rnd_MIM165_Sentry: FA_4Rnd_MIM165_Sentry { displayName = "[JMSB] 1x MIM-165 Sentry"; count = 1; };
    class FA_1Rnd_MIM166_Roadrunner: FA_4Rnd_MIM166_Roadrunner { displayName = "[JMSB] 1x MIM-166 Roadrunner"; count = 1; };

    // =========================================================
    // Man-portable (shoulder Titan MPRL) magazines — single-round infantry
    // launcher bodies (Titan_AT / Titan_AA), so they chamber in the shoulder
    // launcher instead of a vehicle turret. Same ammo as the vehicle variants,
    // so they keep their full range/guidance profile. Wired to the launchers in
    // CfgWeapons.hpp.
    // =========================================================
    class Titan_AA;
    class Titan_AT;
    class FA_Titan_AT_BGM185_Broadsword: Titan_AT {
        author = QAUTHOR;
        displayName = "[JMSB] BGM-185 Broadsword";
        displayNameShort = "BGM-185";
        descriptionShort = "BGM-185 Broadsword (2040)<br/>Man-portable tandem F&F top-attack ATGM, NLOS-capable — 1300mm RHA, 10 km";
        ammo = "FA_M_BGM185_Broadsword";
    };
    class FA_Titan_AT_XM1200_Copperhead: Titan_AT {
        author = QAUTHOR;
        displayName = "[JMSB] XM1200 Copperhead";
        displayNameShort = "XM1200";
        descriptionShort = "XM1200 Copperhead (2040)<br/>Man-portable loitering munition — launch unlocked to loiter + autonomous terminal, or lock before launch — 800mm RHA, 40 km";
        ammo = "FA_M_XM1200_Copperhead";
    };
    class FA_Titan_AA_MIM165_Sentry: Titan_AA {
        author = QAUTHOR;
        displayName = "[JMSB] MIM-165 Sentry";
        displayNameShort = "MIM-165";
        descriptionShort = "MIM-165 Sentry (2040)<br/>Man-portable dual-seeker SAM, proximity prefrag — jets to drones, 12 km";
        ammo = "FA_M_MIM165_Sentry";
    };
    class FA_Titan_AA_MIM166_Roadrunner: Titan_AA {
        author = QAUTHOR;
        displayName = "[JMSB] MIM-166 Roadrunner";
        displayNameShort = "MIM-166";
        descriptionShort = "MIM-166 Roadrunner (2040)<br/>Man-portable C-UAS hard-kill, proximity prefrag — drones + loitering munitions, 4 km";
        ammo = "FA_M_MIM166_Roadrunner";
    };

    // =========================================================
    // Fixed-wing aircraft missiles — 2040 pylon magazines. Inherit the vanilla
    // pylon body (so they get its hardpoints[] + pylonWeapon and appear in the
    // dynamic-loadout editor on the same pylons). Tri-side: _B West (US AIM/AGM),
    // _O East (Russian R-/Kh-), _I Ind (AAF European export). See CfgAmmo.hpp.
    // =========================================================
    class PylonMissile_1Rnd_Missile_AA_04_F;
    class PylonMissile_1Rnd_Missile_AA_03_F;
    class PylonRack_1Rnd_Missile_AGM_02_F;

    // Short-range IR AA
    class FA_Pylon_1Rnd_aair_B: PylonMissile_1Rnd_Missile_AA_04_F { author = QAUTHOR; ammo = "FA_M_AIM9X3"; displayName = "[JMSB] AIM-9X Blk III"; descriptionShort = "Short-range IR AA (2040)<br/>Imaging IR, high off-boresight — 35 km"; };
    class FA_Pylon_1Rnd_aair_O: PylonMissile_1Rnd_Missile_AA_04_F { author = QAUTHOR; ammo = "FA_M_R74M"; displayName = "[JMSB] R-74M"; descriptionShort = "Short-range IR AA (2040)<br/>Imaging IR, high off-boresight — 35 km"; };
    class FA_Pylon_1Rnd_aair_I: PylonMissile_1Rnd_Missile_AA_04_F { author = QAUTHOR; ammo = "FA_M_IRIST"; displayName = "[JMSB] IRIS-T"; descriptionShort = "Short-range IR AA (2040)<br/>Imaging IR, high off-boresight — 35 km"; };

    // Medium-range radar AA
    class FA_Pylon_1Rnd_aamed_B: PylonMissile_1Rnd_Missile_AA_03_F { author = QAUTHOR; ammo = "FA_M_AIM120E"; displayName = "[JMSB] AIM-120E"; descriptionShort = "Medium-range radar AA (2040)<br/>Active radar + datalink — 160 km"; };
    class FA_Pylon_1Rnd_aamed_O: PylonMissile_1Rnd_Missile_AA_03_F { author = QAUTHOR; ammo = "FA_M_R77M"; displayName = "[JMSB] R-77M"; descriptionShort = "Medium-range radar AA (2040)<br/>Active radar + datalink — 160 km"; };
    class FA_Pylon_1Rnd_aamed_I: PylonMissile_1Rnd_Missile_AA_03_F { author = QAUTHOR; ammo = "FA_M_MICANG"; displayName = "[JMSB] MICA-NG"; descriptionShort = "Medium-range radar AA (2040)<br/>Active radar + datalink — 160 km"; };

    // Long-range AA
    class FA_Pylon_1Rnd_aalong_B: PylonMissile_1Rnd_Missile_AA_03_F { author = QAUTHOR; ammo = "FA_M_AIM260"; displayName = "[JMSB] AIM-260 JATM"; descriptionShort = "Long-range AA (2040)<br/>Active radar, two-way datalink, networked BVR — 300 km"; };
    class FA_Pylon_1Rnd_aalong_O: PylonMissile_1Rnd_Missile_AA_03_F { author = QAUTHOR; ammo = "FA_M_R37M"; displayName = "[JMSB] R-37M"; descriptionShort = "Long-range AA (2040)<br/>Active radar, two-way datalink, networked BVR — 300 km"; };
    class FA_Pylon_1Rnd_aalong_I: PylonMissile_1Rnd_Missile_AA_03_F { author = QAUTHOR; ammo = "FA_M_Meteor"; displayName = "[JMSB] Meteor"; descriptionShort = "Long-range AA (2040)<br/>Active radar, two-way datalink, networked BVR — 300 km"; };

    // SEAD anti-radiation
    class FA_Pylon_1Rnd_sead_B: PylonRack_1Rnd_Missile_AGM_02_F { author = QAUTHOR; ammo = "FA_M_sead"; displayName = "[JMSB] AGM-88G AARGM-ER"; descriptionShort = "SEAD anti-radiation (2040)<br/>Homes on emitting radars, mmW terminal — 300 km"; };
    class FA_Pylon_1Rnd_sead_O: PylonRack_1Rnd_Missile_AGM_02_F { author = QAUTHOR; ammo = "FA_M_sead"; displayName = "[JMSB] Kh-31PD"; descriptionShort = "SEAD anti-radiation (2040)<br/>Homes on emitting radars, mmW terminal — 300 km"; };
    class FA_Pylon_1Rnd_sead_I: PylonRack_1Rnd_Missile_AGM_02_F { author = QAUTHOR; ammo = "FA_M_sead"; displayName = "[JMSB] AARGM-E"; descriptionShort = "SEAD anti-radiation (2040)<br/>Homes on emitting radars, mmW terminal — 300 km"; };

    // Standoff cruise
    class FA_Pylon_1Rnd_cruise_B: PylonRack_1Rnd_Missile_AGM_02_F { author = QAUTHOR; ammo = "FA_M_cruise"; displayName = "[JMSB] AGM-158D JASSM-XR"; descriptionShort = "Standoff cruise (2040)<br/>INS/GPS + IIR terminal, terrain-following, low-obs — 900 km"; };
    class FA_Pylon_1Rnd_cruise_O: PylonRack_1Rnd_Missile_AGM_02_F { author = QAUTHOR; ammo = "FA_M_cruise"; displayName = "[JMSB] Kh-101"; descriptionShort = "Standoff cruise (2040)<br/>INS/GPS + IIR terminal, terrain-following, low-obs — 900 km"; };
    class FA_Pylon_1Rnd_cruise_I: PylonRack_1Rnd_Missile_AGM_02_F { author = QAUTHOR; ammo = "FA_M_cruise"; displayName = "[JMSB] SCALP-EG"; descriptionShort = "Standoff cruise (2040)<br/>INS/GPS + IIR terminal, terrain-following, low-obs — 900 km"; };

    // Anti-ship
    class FA_Pylon_1Rnd_antiship_B: PylonRack_1Rnd_Missile_AGM_02_F { author = QAUTHOR; ammo = "FA_M_antiship"; displayName = "[JMSB] AGM-158C LRASM"; descriptionShort = "Anti-ship (2040)<br/>INS/GPS + terminal radar/IIR, sea-skimming — 500 km"; };
    class FA_Pylon_1Rnd_antiship_O: PylonRack_1Rnd_Missile_AGM_02_F { author = QAUTHOR; ammo = "FA_M_antiship"; displayName = "[JMSB] Kh-35UE"; descriptionShort = "Anti-ship (2040)<br/>INS/GPS + terminal radar/IIR, sea-skimming — 500 km"; };
    class FA_Pylon_1Rnd_antiship_I: PylonRack_1Rnd_Missile_AGM_02_F { author = QAUTHOR; ammo = "FA_M_antiship"; displayName = "[JMSB] RBS-15 Mk4"; descriptionShort = "Anti-ship (2040)<br/>INS/GPS + terminal radar/IIR, sea-skimming — 500 km"; };
};
