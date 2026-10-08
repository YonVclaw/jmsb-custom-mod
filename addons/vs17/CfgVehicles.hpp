class CBA_Extended_EventHandlers_base;
class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base{};
class CfgVehicles {
    class Man;
    class Helipad_base_F;
    class GVAR(vs17_base): Helipad_base_F {
        scope = 0;
        vehicleclass = "jmfsb";
        mapsize = 1.5;
        class TransportWeapons{};
        class TransportItems{};
        class TransportMagazines{};
        class TransportBackpacks{};
        class EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base{};
        };
    };
    class GVAR(vs17_item): GVAR(vs17_base) {
        scope = 2;
        scopeCurator = 2;
        author = QAUTHOR;
        displayName = "vs17 Panel";
        displayNameShort = "vs17";
        correspondingItem = QGVAR(vs17);
        model = "\A3\Structures_F\Civ\Camping\Ground_sheet_yellow_F.p3d";
        ace_dragging_canCarry = 1;
        ace_dragging_carryPosition[] = {0,1.2,0};
        ace_dragging_carryDirection = 0;
        ace_dragging_canDrag = 1;
        ace_dragging_dragPosition[] = {0,1.2,0};
        ace_dragging_dragDirection = 0;
        class ACE_Actions {
            class ACE_MainActions {
                displayName = "$STR_ACE_interaction_MainAction";
                position = "[0, 0, 0]";
                distance = 4;
                condition = "true";

                class GVAR(vs17Remove) {
                    displayName = "Pick up";
                    condition = QUOTE(call FUNC(vs17canremove));
                    statement = QUOTE(call FUNC(vs17pick));
                    showDisabled = 0;
                    icon = "\a3\ui_f\data\IGUI\Cfg\Actions\getincommander_ca.paa";
                };
            };
        };
    };
    class CAManBase: Man {
        class ACE_SelfActions {
            class ACE_Equipment {
                class vs17 {
                    displayName = "Place Marker Panels";
                    condition = QUOTE([_player] call FUNC(vs17can));
                    statement = QUOTE([_player] call FUNC(vs17place));
                    exceptions[] = {};
                    showDisabled = 0;
                    icon = QPATHTOF(data\vs_yellow.paa);
                };
            };
        };
    };
};
