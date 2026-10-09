// ACE Arsenal Extended: the Russia set folded into one arsenal entry per piece,
// with the camo (and the cut, where there is one) as options - the same shape
// headware and vests give their own kit. Hand-kept beside CfgWeapons.hpp and
// arctic_CfgWeapons.hpp; a new camo is one value here and one entry below.
// Single pieces with no variant (the green tactical vest and chest rig, the
// boonie with headset, the pilot coveralls) stay as they are: there is nothing
// to fold.

class XtdGearModels {
    class CfgWeapons {
        class GVAR(Luchnik) {
            label = "Luchnik Fatigues [RU]";
            options[] = {"camo", "type"};
            class camo {
                alwaysSelectable = 1;
                values[] = {"Taiga", "Arid", "Arctic"};
                class Taiga { label = "Taiga"; };
                class Arid { label = "Arid"; };
                class Arctic { label = "Arctic"; };
            };
            class type {
                alwaysSelectable = 1;
                values[] = {"Full", "RolledUp", "Officer"};
                class Full { label = "Full"; };
                class RolledUp { label = "Rolled"; };
                class Officer { label = "Officer"; };
            };
        };
        class GVAR(CombatUniform) {
            label = "Fatigues [RU]";
            options[] = {"camo"};
            class camo {
                alwaysSelectable = 1;
                values[] = {"Taiga", "Arid", "Arctic"};
                class Taiga { label = "Taiga"; };
                class Arid { label = "Arid"; };
                class Arctic { label = "Arctic"; };
            };
        };
        class GVAR(GhillieSuit) {
            label = "Ghillie Suit [RU]";
            options[] = {"camo"};
            class camo {
                alwaysSelectable = 1;
                values[] = {"Taiga", "Arid", "Arctic"};
                class Taiga { label = "Taiga"; };
                class Arid { label = "Arid"; };
                class Arctic { label = "Arctic"; };
            };
        };
        class GVAR(FullGhillie) {
            label = "Full Ghillie [RU]";
            options[] = {"camo"};
            class camo {
                alwaysSelectable = 1;
                values[] = {"Arid", "Lush", "SemiArid", "Woodland"};
                class Arid { label = "Arid"; };
                class Lush { label = "Lush"; };
                class SemiArid { label = "Semi-Arid"; };
                class Woodland { label = "Woodland"; };
            };
        };
        class GVAR(ChestrigEast) {
            label = "Lifchik-M Rig";
            options[] = {"camo"};
            class camo {
                alwaysSelectable = 1;
                values[] = {"Taiga", "Arid", "Arctic"};
                class Taiga { label = "Taiga"; };
                class Arid { label = "Arid"; };
                class Arctic { label = "Arctic"; };
            };
        };
        class GVAR(Bandolier) {
            label = "Slash Bandolier";
            options[] = {"camo"};
            class camo {
                alwaysSelectable = 1;
                values[] = {"Taiga", "Arctic"};
                class Taiga { label = "Taiga"; };
                class Arctic { label = "Arctic"; };
            };
        };
        class GVAR(BattleBelt) {
            label = "Battle Belt";
            options[] = {"camo"};
            class camo {
                alwaysSelectable = 1;
                values[] = {"Taiga", "Arctic"};
                class Taiga { label = "Taiga"; };
                class Arctic { label = "Arctic"; };
            };
        };
        class GVAR(Smersh) {
            label = "Smersh Vest (Plates)";
            options[] = {"type"};
            class type {
                alwaysSelectable = 1;
                values[] = {"Plates", "Radio"};
                class Plates { label = "Plates"; };
                class Radio { label = "Radio"; };
            };
        };
        class GVAR(LuchnikHelmet) {
            label = "Luchnik Helmet (Cover)";
            options[] = {"camo"};
            class camo {
                alwaysSelectable = 1;
                values[] = {"Taiga", "Arid", "Arctic"};
                class Taiga { label = "Taiga"; };
                class Arid { label = "Arid"; };
                class Arctic { label = "Arctic"; };
            };
        };
    };
};

class XtdGearInfos {
    class CfgWeapons {
        // Luchnik fatigues
        class GVAR(U_O_Luchnik_taiga_F) { model = QGVAR(Luchnik); camo = "Taiga"; type = "Full"; };
        class GVAR(U_O_Luchnik_arid_F) { model = QGVAR(Luchnik); camo = "Arid"; type = "Full"; };
        class GVAR(U_O_Luchnik_arctic_F) { model = QGVAR(Luchnik); camo = "Arctic"; type = "Full"; };
        class GVAR(U_O_Luchnik_RolledUp_taiga_F) { model = QGVAR(Luchnik); camo = "Taiga"; type = "RolledUp"; };
        class GVAR(U_O_Luchnik_RolledUp_arid_F) { model = QGVAR(Luchnik); camo = "Arid"; type = "RolledUp"; };
        class GVAR(U_O_Luchnik_RolledUp_arctic_F) { model = QGVAR(Luchnik); camo = "Arctic"; type = "RolledUp"; };
        class GVAR(U_O_Luchnik_officer_taiga_F) { model = QGVAR(Luchnik); camo = "Taiga"; type = "Officer"; };
        class GVAR(U_O_Luchnik_officer_arid_F) { model = QGVAR(Luchnik); camo = "Arid"; type = "Officer"; };
        class GVAR(U_O_Luchnik_officer_arctic_F) { model = QGVAR(Luchnik); camo = "Arctic"; type = "Officer"; };
        // fatigues
        class GVAR(U_O_R_CombatUniform_taiga_F) { model = QGVAR(CombatUniform); camo = "Taiga"; };
        class GVAR(U_O_R_CombatUniform_arid_F) { model = QGVAR(CombatUniform); camo = "Arid"; };
        class GVAR(U_O_R_CombatUniform_arctic_F) { model = QGVAR(CombatUniform); camo = "Arctic"; };
        // ghillies
        class GVAR(U_O_R_GhillieSuit_taiga_F) { model = QGVAR(GhillieSuit); camo = "Taiga"; };
        class GVAR(U_O_R_GhillieSuit_arid_F) { model = QGVAR(GhillieSuit); camo = "Arid"; };
        class GVAR(U_O_R_GhillieSuit_arctic_F) { model = QGVAR(GhillieSuit); camo = "Arctic"; };
        class GVAR(U_O_R_FullGhillie_ard_F) { model = QGVAR(FullGhillie); camo = "Arid"; };
        class GVAR(U_O_R_FullGhillie_lsh_F) { model = QGVAR(FullGhillie); camo = "Lush"; };
        class GVAR(U_O_R_FullGhillie_sard_F) { model = QGVAR(FullGhillie); camo = "SemiArid"; };
        class GVAR(U_O_R_FullGhillie_wdl_F) { model = QGVAR(FullGhillie); camo = "Woodland"; };
        // vests and belts
        class GVAR(V_ChestrigEast_RUtaiga_F) { model = QGVAR(ChestrigEast); camo = "Taiga"; };
        class GVAR(V_ChestrigEast_RUarid_F) { model = QGVAR(ChestrigEast); camo = "Arid"; };
        class GVAR(V_ChestrigEast_ruarctic_F) { model = QGVAR(ChestrigEast); camo = "Arctic"; };
        class GVAR(V_BandollierB_taiga_F) { model = QGVAR(Bandolier); camo = "Taiga"; };
        class GVAR(V_BandollierB_arctic_F) { model = QGVAR(Bandolier); camo = "Arctic"; };
        class GVAR(V_Rangemaster_belt_taiga_F) { model = QGVAR(BattleBelt); camo = "Taiga"; };
        class GVAR(V_Rangemaster_belt_arctic_F) { model = QGVAR(BattleBelt); camo = "Arctic"; };
        class GVAR(V_SmershVest_01_F) { model = QGVAR(Smersh); type = "Plates"; };
        class GVAR(V_SmershVest_01_radio_F) { model = QGVAR(Smersh); type = "Radio"; };
        // helmets
        class GVAR(H_HelmetLuchnik_cover_rutaiga_F) { model = QGVAR(LuchnikHelmet); camo = "Taiga"; };
        class GVAR(H_HelmetLuchnik_cover_ruarid_F) { model = QGVAR(LuchnikHelmet); camo = "Arid"; };
        class GVAR(H_HelmetLuchnik_cover_ruarctic_F) { model = QGVAR(LuchnikHelmet); camo = "Arctic"; };
    };
};
