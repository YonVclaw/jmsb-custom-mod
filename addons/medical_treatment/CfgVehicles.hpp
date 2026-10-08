class CfgVehicles {
    // Apap litter
    class Leaflet_05_F;
    class JMFSB_MedicalLitter_apap: Leaflet_05_F {
        hiddenSelectionsTextures[] = {QPATHTOF(data\apap_litter.paa)};
    };

    // Apap item
    class Item_Base_F;
    class JMFSB_apapItem: Item_Base_F {
        scope = 2;
        scopeCurator = 2;
        displayName = "Apap pastille";
        author = "ArmaForces";
        icon = QPATHTOF(ui\icons\apap.paa);
        model = "\A3\Structures_F_EPA\Items\Medical\PainKillers_F.p3d";
        vehicleClass = "Items";
        class TransportItems {
            MACRO_ADDITEM(JMFSB_apap,1);
        };
    };
};
