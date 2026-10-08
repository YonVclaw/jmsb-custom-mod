// Patch the vanilla Vorona base class: feed it the FA_Vorona well and allow
// locking (canLock 2) for the Osa. Lock only actually engages when the loaded
// missile's ammo carries lock params — the SACLOS natures (vanilla and Grom /
// Oskol) have none, so they keep manual guidance. The vanilla Vorona already
// defines the Titan locking/locked tones, so the Osa's lock UX comes free.
// weaponLockSystem 2 + 16 = IR + passive.
class CfgWeapons {
    class Launcher;
    class Launcher_Base_F: Launcher {};
    class launch_Vorona_base_F: Launcher_Base_F {
        magazineWell[] = {"FA_Vorona"};
        canLock = 2;
        weaponLockSystem = 2 + 16;
    };
};
