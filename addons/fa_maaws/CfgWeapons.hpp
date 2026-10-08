// Patch the vanilla MAAWS Mk4 base class: feed it the FA_MRAWS well and allow
// locking (canLock 2). Lock only actually engages when the loaded round's ammo
// carries lock params — the vanilla HEAT/HE natures have none, so they stay
// unguided. weaponLockSystem 2+4+16 = IR (seekers) + laser (GM 841) + passive.
class CfgWeapons {
    class Launcher;
    class Launcher_Base_F: Launcher {};
    class launch_MRAWS_base_F: Launcher_Base_F {
        magazineWell[] = {"FA_MRAWS"};
        canLock = 2;
        weaponLockDelay = 3;
        weaponLockSystem = 2 + 4 + 16;
    };
};
