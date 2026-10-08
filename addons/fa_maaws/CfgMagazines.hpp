// One round per tube, vanilla MAAWS Mk4 magazine bodies. initSpeed follows the
// muzzle velocity of each nature; mass roughly tracks warhead weight against
// the vanilla HEAT 75 (mass 60) / HE 44 (mass 40) references.
class CfgMagazines {
    class MRAWS_HEAT_F;
    class MRAWS_HEAT55_F;
    class MRAWS_HE_F;

    // =========================================================
    // Anti-tank
    // =========================================================
    class FA_MRAWS_HEAT758_TT: MRAWS_HEAT_F {
        author = QAUTHOR;
        displayName = "[JMSB] MRAWS HEAT758 TT";
        descriptionShort = "84mm HEAT 758 TT (2040)<br/>Tandem shaped charge, fire-and-forget top-attack — 850mm RHA, 1200 m";
        ammo = "FA_R_MRAWS_HEAT758_TT";
        initSpeed = 290;
        mass = 62;
    };
    class FA_MRAWS_HEAT665_CS: MRAWS_HEAT55_F {
        author = QAUTHOR;
        displayName = "[JMSB] MRAWS HEAT665 CS";
        descriptionShort = "84mm HEAT 665 CS (2040)<br/>Heavy tandem HEAT, confined-space (counter-mass, fire from enclosures) — 650mm RHA";
        ammo = "FA_R_MRAWS_HEAT665_CS";
        initSpeed = 350;
        mass = 66;
    };
    class FA_MRAWS_GM841: MRAWS_HEAT_F {
        author = QAUTHOR;
        displayName = "[JMSB] MRAWS GM841";
        descriptionShort = "84mm GM 841 (2040)<br/>Semi-active laser homing, tandem dual-purpose — lase the target, 2000 m";
        ammo = "FA_M_MRAWS_GM841";
        initSpeed = 270;
        mass = 62;
    };

    // =========================================================
    // High-explosive
    // =========================================================
    class FA_MRAWS_HE448_AB: MRAWS_HE_F {
        author = QAUTHOR;
        displayName = "[JMSB] MRAWS HE448 AB";
        descriptionShort = "84mm HE 448 AB (2040)<br/>Prefragmented HE, programmable airburst (Mk364 airburst keybind dials the range) — 1500 m";
        ammo = "FA_R_MRAWS_HE448_AB";
        initSpeed = 350;
        mass = 42;
    };

    // =========================================================
    // Counter-UAS
    // =========================================================
    class FA_MRAWS_ADM484_PROX: MRAWS_HE_F {
        author = QAUTHOR;
        displayName = "[JMSB] MRAWS ADM484 PROX";
        descriptionShort = "84mm ADM 484 PROX (2040)<br/>C-UAS proximity frag, single drone — scripted fuze, 600 m";
        ammo = "FA_R_MRAWS_ADM484";
        initSpeed = 260;
        mass = 40;
    };
    class FA_MRAWS_ADM486_CAN: MRAWS_HE_F {
        author = QAUTHOR;
        displayName = "[JMSB] MRAWS ADM486 CAN";
        descriptionShort = "84mm ADM 486 CAN (2040)<br/>Tungsten flechette canister — wall of darts for a close drone swarm, 150 m";
        ammo = "FA_R_MRAWS_ADM486";
        initSpeed = 290;
        mass = 38;
    };
    class FA_MRAWS_ADM487_SEEK: MRAWS_HEAT_F {
        author = QAUTHOR;
        displayName = "[JMSB] MRAWS ADM487 SEEK";
        descriptionShort = "84mm ADM 487 SEEK (2040)<br/>IR fire-and-forget vs a locked drone — 1000 m";
        ammo = "FA_M_MRAWS_ADM487";
        initSpeed = 270;
        mass = 44;
    };

    // =========================================================
    // Very-short-range AA
    // =========================================================
    class FA_MRAWS_AAM517_SR: MRAWS_HEAT_F {
        author = QAUTHOR;
        displayName = "[JMSB] MRAWS AAM517 SR";
        descriptionShort = "84mm AAM 517 SR (2040)<br/>VSHORAD IR missile — helos, low/slow aircraft, large UAS; half the Titan envelope, 1750 m";
        ammo = "FA_M_MRAWS_AAM517";
        initSpeed = 300;
        mass = 48;
    };
};
