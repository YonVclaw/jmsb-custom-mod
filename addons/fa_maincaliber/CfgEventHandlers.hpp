// No preInit hook needed — this addon has no compiled functions of its own,
// it only registers its ammo classes into jmfsbfa_mediumcaliber's shared
// params hashmap once that addon's engine exists (guaranteed by requiredAddons
// to have already run its own postInit by the time this one fires).
class Extended_PostInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_SCRIPT(XEH_postInit));
    };
};
