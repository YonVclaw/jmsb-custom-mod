// One missile per tube, vanilla Vorona tube bodies. initSpeed stays at the
// vanilla 150 — the ground natures are SACLOS manual-steer and a faster
// launch would leave no time to gather the missile onto the crosshair.
class CfgMagazines {
    class Vorona_HEAT;
    class Vorona_HE;

    class FA_Vorona_9M135M: Vorona_HEAT {
        author = QAUTHOR;
        displayName = "[JMSB] Vorona 9M135M";
        descriptionShort = "9M135M Grom (2040)<br/>Tandem shaped charge, SACLOS — 800mm RHA, 1800 m";
        ammo = "FA_M_Vorona_9M135M";
        mass = 102;
    };
    class FA_Vorona_9M135F2: Vorona_HE {
        author = QAUTHOR;
        displayName = "[JMSB] Vorona 9M135F2";
        descriptionShort = "9M135F-2 Oskol (2040)<br/>Thermobaric + prefrag, programmable airburst (Mk364 airburst keybind dials the range) — 1600 m";
        ammo = "FA_M_Vorona_9M135F2";
        mass = 100;
    };
    class FA_Vorona_9M135PVO: Vorona_HE {
        author = QAUTHOR;
        displayName = "[JMSB] Vorona 9M135PVO";
        descriptionShort = "9M135PVO Osa (2040)<br/>IR lock-on vs helos, low/slow aircraft and drones — 1200 m";
        ammo = "FA_M_Vorona_9M135PVO";
        mass = 100;
    };
};
