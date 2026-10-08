#define JMFSB_STANDARD_VEST_ITEMINFO \
    class ItemInfo: ItemInfo { \
        class HitpointsProtectionInfo { \
            class Neck { \
                hitpointName = "HitNeck"; \
                armor = 8; \
                passThrough = 0.3; \
            }; \
            class Chest { \
                hitpointName = "HitChest"; \
                armor = 29; \
                passThrough = 0.085; \
            }; \
            class Body { \
                hitpointName = "HitBody"; \
                passThrough = 0.085; \
            }; \
            class Diaphragm { \
                hitpointName = "HitDiaphragm"; \
                armor = 29; \
                passThrough = 0.085; \
            }; \
            class Abdomen { \
                hitpointName = "HitAbdomen"; \
                armor = 19; \
                passThrough = 0.255; \
            }; \
            class Pelvis { \
                hitpointName = "HitPelvis"; \
                armor = 19; \
                passThrough = 0.255; \
            }; \
            class Arms { \
                hitpointName = "HitArms"; \
                armor = 12; \
                passThrough = 0.55; \
            }; \
            class Legs { \
                hitpointName = "HitLegs"; \
                armor = 12; \
                passThrough = 0.55; \
            }; \
        }; \
    };

#define JMFSB_HEAVY_VEST_ITEMINFO \
    class ItemInfo: ItemInfo { \
        class HitpointsProtectionInfo { \
            class Neck { \
                hitpointName = "HitNeck"; \
                armor = 10; \
                passThrough = 0.25; \
            }; \
            class Chest { \
                hitpointName = "HitChest"; \
                armor = 34; \
                passThrough = 0.06; \
            }; \
            class Body { \
                hitpointName = "HitBody"; \
                passThrough = 0.06; \
            }; \
            class Diaphragm { \
                hitpointName = "HitDiaphragm"; \
                armor = 34; \
                passThrough = 0.06; \
            }; \
            class Abdomen { \
                hitpointName = "HitAbdomen"; \
                armor = 24; \
                passThrough = 0.21; \
            }; \
            class Pelvis { \
                hitpointName = "HitPelvis"; \
                armor = 24; \
                passThrough = 0.21; \
            }; \
            class Arms { \
                hitpointName = "HitArms"; \
                armor = 14; \
                passThrough = 0.5; \
            }; \
            class Legs { \
                hitpointName = "HitLegs"; \
                armor = 14; \
                passThrough = 0.5; \
            }; \
        }; \
    };

class CfgWeapons {
    class ItemInfo; // defined for real in jmfsb_main (see its CfgWeapons.hpp)
    class JCA_V_CarrierRigKBT_01_combat_black_F;
    class JCA_V_CarrierRigKBT_01_combat_MTP_alpine_F;
    class JCA_V_CarrierRigKBT_01_combat_MTP_desert_F;
    class JCA_V_CarrierRigKBT_01_combat_MTP_tropic_F;
    class JCA_V_CarrierRigKBT_01_combat_MTP_woodland_F;
    class JCA_V_CarrierRigKBT_01_combat_MTP_arid_F;
    class JCA_V_CarrierRigKBT_01_combat_sand_F;
    class JCA_V_CarrierRigKBT_01_command_black_F;
    class JCA_V_CarrierRigKBT_01_command_MTP_alpine_F;
    class JCA_V_CarrierRigKBT_01_command_MTP_desert_F;
    class JCA_V_CarrierRigKBT_01_command_MTP_woodland_F;
    class JCA_V_CarrierRigKBT_01_command_MTP_arid_F;
    class JCA_V_CarrierRigKBT_01_command_olive_F;
    class JCA_V_CarrierRigKBT_01_command_sand_F;
    class JCA_V_CarrierRigKBT_01_compact_MTP_alpine_F;
    class JCA_V_CarrierRigKBT_01_compact_MTP_desert_F;
    class JCA_V_CarrierRigKBT_01_compact_MTP_tropic_F;
    class JCA_V_CarrierRigKBT_01_compact_MTP_woodland_F;
    class JCA_V_CarrierRigKBT_01_compact_olive_F;
    class JCA_V_CarrierRigKBT_01_compact_sand_F;
    class JCA_V_CarrierRigKBT_01_CQB_black_F;
    class JCA_V_CarrierRigKBT_01_CQB_MTP_alpine_F;
    class JCA_V_CarrierRigKBT_01_CQB_MTP_tropic_F;
    class JCA_V_CarrierRigKBT_01_CQB_MTP_woodland_F;
    class JCA_V_CarrierRigKBT_01_CQB_MTP_arid_F;
    class JCA_V_CarrierRigKBT_01_CQB_sand_F;
    class JCA_V_CarrierRigKBT_01_crew_black_F;
    class JCA_V_CarrierRigKBT_01_crew_MTP_alpine_F;
    class JCA_V_CarrierRigKBT_01_crew_MTP_desert_F;
    class JCA_V_CarrierRigKBT_01_crew_MTP_woodland_F;
    class JCA_V_CarrierRigKBT_01_crew_MTP_arid_F;
    class JCA_V_CarrierRigKBT_01_crew_olive_F;
    class JCA_V_CarrierRigKBT_01_crew_sand_F;
    class JCA_V_CarrierRigKBT_01_heavy_MTP_alpine_F;
    class JCA_V_CarrierRigKBT_01_heavy_MTP_desert_F;
    class JCA_V_CarrierRigKBT_01_heavy_MTP_tropic_F;
    class JCA_V_CarrierRigKBT_01_heavy_MTP_woodland_F;
    class JCA_V_CarrierRigKBT_01_heavy_olive_F;
    class JCA_V_CarrierRigKBT_01_heavy_sand_F;
    class JCA_V_CarrierRigKBT_01_holster_black_F;
    class JCA_V_CarrierRigKBT_01_holster_MTP_alpine_F;
    class JCA_V_CarrierRigKBT_01_holster_MTP_tropic_F;
    class JCA_V_CarrierRigKBT_01_holster_MTP_woodland_F;
    class JCA_V_CarrierRigKBT_01_holster_MTP_arid_F;
    class JCA_V_CarrierRigKBT_01_holster_sand_F;
    class JCA_V_CarrierRigKBT_01_light_black_F;
    class JCA_V_CarrierRigKBT_01_light_MTP_alpine_F;
    class JCA_V_CarrierRigKBT_01_light_MTP_desert_F;
    class JCA_V_CarrierRigKBT_01_light_MTP_woodland_F;
    class JCA_V_CarrierRigKBT_01_light_MTP_arid_F;
    class JCA_V_CarrierRigKBT_01_light_olive_F;
    class JCA_V_CarrierRigKBT_01_light_sand_F;
    class JCA_V_CarrierRigKBT_01_recon_MTP_alpine_F;
    class JCA_V_CarrierRigKBT_01_recon_MTP_desert_F;
    class JCA_V_CarrierRigKBT_01_recon_MTP_tropic_F;
    class JCA_V_CarrierRigKBT_01_recon_MTP_woodland_F;
    class JCA_V_CarrierRigKBT_01_recon_olive_F;
    class JCA_V_CarrierRigKBT_01_recon_sand_F;
    class JCA_V_CarrierRigKBT_01_tactical_black_F;
    class JCA_V_CarrierRigKBT_01_tactical_MTP_alpine_F;
    class JCA_V_CarrierRigKBT_01_tactical_MTP_tropic_F;
    class JCA_V_CarrierRigKBT_01_tactical_MTP_woodland_F;
    class JCA_V_CarrierRigKBT_01_tactical_MTP_arid_F;
    class JCA_V_CarrierRigKBT_01_tactical_sand_F;
    class JCA_V_CarrierRigKBT_01_black_F;
    class JCA_V_CarrierRigKBT_01_MTP_alpine_F;
    class JCA_V_CarrierRigKBT_01_MTP_desert_F;
    class JCA_V_CarrierRigKBT_01_MTP_woodland_F;
    class JCA_V_CarrierRigKBT_01_MTP_arid_F;
    class JCA_V_CarrierRigKBT_01_olive_F;
    class JCA_V_CarrierRigKBT_01_sand_F;
    class JCA_V_CarrierRigKBT_01_MTP_tropic_F;
    class JCA_V_CarrierRigKBT_01_tactical_olive_F;
    class JCA_V_CarrierRigKBT_01_tactical_MTP_desert_F;
    class JCA_V_CarrierRigKBT_01_recon_MTP_arid_F;
    class JCA_V_CarrierRigKBT_01_recon_black_F;
    class JCA_V_CarrierRigKBT_01_light_MTP_tropic_F;
    class JCA_V_CarrierRigKBT_01_holster_olive_F;
    class JCA_V_CarrierRigKBT_01_holster_MTP_desert_F;
    class JCA_V_CarrierRigKBT_01_heavy_MTP_arid_F;
    class JCA_V_CarrierRigKBT_01_heavy_black_F;
    class JCA_V_CarrierRigKBT_01_crew_MTP_tropic_F;
    class JCA_V_CarrierRigKBT_01_CQB_olive_F;
    class JCA_V_CarrierRigKBT_01_CQB_MTP_desert_F;
    class JCA_V_CarrierRigKBT_01_compact_MTP_arid_F;
    class JCA_V_CarrierRigKBT_01_compact_black_F;
    class JCA_V_CarrierRigKBT_01_command_MTP_tropic_F;
    class JCA_V_CarrierRigKBT_01_combat_olive_F;

    class GVAR(JCA_V_CarrierRigKBT_01_combat_black_F): JCA_V_CarrierRigKBT_01_combat_black_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Combat Rig (Black)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_combat_MTP_alpine_F): JCA_V_CarrierRigKBT_01_combat_MTP_alpine_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Combat Rig (MTP-Alpine)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_combat_MTP_desert_F): JCA_V_CarrierRigKBT_01_combat_MTP_desert_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Combat Rig (MTP-Desert)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_combat_MTP_tropic_F): JCA_V_CarrierRigKBT_01_combat_MTP_tropic_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Combat Rig (MTP-Tropic)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_combat_MTP_woodland_F): JCA_V_CarrierRigKBT_01_combat_MTP_woodland_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Combat Rig (MTP-Woodland)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_combat_MTP_arid_F): JCA_V_CarrierRigKBT_01_combat_MTP_arid_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Combat Rig (MTP-Arid)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_combat_sand_F): JCA_V_CarrierRigKBT_01_combat_sand_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Combat Rig (Sand)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_command_black_F): JCA_V_CarrierRigKBT_01_command_black_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Command Rig (Black)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_command_MTP_alpine_F): JCA_V_CarrierRigKBT_01_command_MTP_alpine_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Command Rig (MTP-Alpine)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_command_MTP_desert_F): JCA_V_CarrierRigKBT_01_command_MTP_desert_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Command Rig (MTP-Desert)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_command_MTP_woodland_F): JCA_V_CarrierRigKBT_01_command_MTP_woodland_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Command Rig (MTP-Woodland)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_command_MTP_arid_F): JCA_V_CarrierRigKBT_01_command_MTP_arid_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Command Rig (MTP-Arid)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_command_olive_F): JCA_V_CarrierRigKBT_01_command_olive_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Command Rig (Olive)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_command_sand_F): JCA_V_CarrierRigKBT_01_command_sand_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Command Rig (Sand)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_compact_MTP_alpine_F): JCA_V_CarrierRigKBT_01_compact_MTP_alpine_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Compact Vest (MTP-Alpine)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_compact_MTP_desert_F): JCA_V_CarrierRigKBT_01_compact_MTP_desert_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Compact Vest (MTP-Desert)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_compact_MTP_tropic_F): JCA_V_CarrierRigKBT_01_compact_MTP_tropic_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Compact Vest (MTP-Tropic)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_compact_MTP_woodland_F): JCA_V_CarrierRigKBT_01_compact_MTP_woodland_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Compact Vest (MTP-Woodland)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_compact_olive_F): JCA_V_CarrierRigKBT_01_compact_olive_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Compact Vest (Olive)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_compact_sand_F): JCA_V_CarrierRigKBT_01_compact_sand_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Compact Vest (Sand)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_CQB_black_F): JCA_V_CarrierRigKBT_01_CQB_black_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier CQB Rig (Black)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_CQB_MTP_alpine_F): JCA_V_CarrierRigKBT_01_CQB_MTP_alpine_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier CQB Rig (MTP-Alpine)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_CQB_MTP_tropic_F): JCA_V_CarrierRigKBT_01_CQB_MTP_tropic_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier CQB Rig (MTP-Tropic)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_CQB_MTP_woodland_F): JCA_V_CarrierRigKBT_01_CQB_MTP_woodland_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier CQB Rig (MTP-Woodland)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_CQB_MTP_arid_F): JCA_V_CarrierRigKBT_01_CQB_MTP_arid_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier CQB Rig (MTP-Arid)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_CQB_sand_F): JCA_V_CarrierRigKBT_01_CQB_sand_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier CQB Rig (Sand)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_crew_black_F): JCA_V_CarrierRigKBT_01_crew_black_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Crew Vest (Black)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_crew_MTP_alpine_F): JCA_V_CarrierRigKBT_01_crew_MTP_alpine_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Crew Vest (MTP-Alpine)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_crew_MTP_desert_F): JCA_V_CarrierRigKBT_01_crew_MTP_desert_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Crew Vest (MTP-Desert)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_crew_MTP_woodland_F): JCA_V_CarrierRigKBT_01_crew_MTP_woodland_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Crew Vest (MTP-Woodland)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_crew_MTP_arid_F): JCA_V_CarrierRigKBT_01_crew_MTP_arid_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Crew Vest (MTP-Arid)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_crew_olive_F): JCA_V_CarrierRigKBT_01_crew_olive_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Crew Vest (Olive)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_crew_sand_F): JCA_V_CarrierRigKBT_01_crew_sand_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Crew Vest (Sand)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_heavy_MTP_alpine_F): JCA_V_CarrierRigKBT_01_heavy_MTP_alpine_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier GL Rig (MTP-Alpine)";
        JMFSB_HEAVY_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_heavy_MTP_desert_F): JCA_V_CarrierRigKBT_01_heavy_MTP_desert_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier GL Rig (MTP-Desert)";
        JMFSB_HEAVY_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_heavy_MTP_tropic_F): JCA_V_CarrierRigKBT_01_heavy_MTP_tropic_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier GL Rig (MTP-Tropic)";
        JMFSB_HEAVY_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_heavy_MTP_woodland_F): JCA_V_CarrierRigKBT_01_heavy_MTP_woodland_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier GL Rig (MTP-Woodland)";
        JMFSB_HEAVY_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_heavy_olive_F): JCA_V_CarrierRigKBT_01_heavy_olive_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier GL Rig (Olive)";
        JMFSB_HEAVY_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_heavy_sand_F): JCA_V_CarrierRigKBT_01_heavy_sand_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier GL Rig (Sand)";
        JMFSB_HEAVY_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_holster_black_F): JCA_V_CarrierRigKBT_01_holster_black_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Holster (Black)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_holster_MTP_alpine_F): JCA_V_CarrierRigKBT_01_holster_MTP_alpine_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Holster (MTP-Alpine)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_holster_MTP_tropic_F): JCA_V_CarrierRigKBT_01_holster_MTP_tropic_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Holster (MTP-Tropic)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_holster_MTP_woodland_F): JCA_V_CarrierRigKBT_01_holster_MTP_woodland_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Holster (MTP-Woodland)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_holster_MTP_arid_F): JCA_V_CarrierRigKBT_01_holster_MTP_arid_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Holster (MTP-Arid)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_holster_sand_F): JCA_V_CarrierRigKBT_01_holster_sand_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Holster (Sand)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_light_black_F): JCA_V_CarrierRigKBT_01_light_black_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Lite (Black)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_light_MTP_alpine_F): JCA_V_CarrierRigKBT_01_light_MTP_alpine_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Lite (MTP-Alpine)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_light_MTP_desert_F): JCA_V_CarrierRigKBT_01_light_MTP_desert_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Lite (MTP-Desert)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_light_MTP_woodland_F): JCA_V_CarrierRigKBT_01_light_MTP_woodland_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Lite (MTP-Woodland)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_light_MTP_arid_F): JCA_V_CarrierRigKBT_01_light_MTP_arid_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Lite (MTP-Arid)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_light_olive_F): JCA_V_CarrierRigKBT_01_light_olive_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Lite (Olive)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_light_sand_F): JCA_V_CarrierRigKBT_01_light_sand_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Lite (Sand)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_recon_MTP_alpine_F): JCA_V_CarrierRigKBT_01_recon_MTP_alpine_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Recon Rig (MTP-Alpine)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_recon_MTP_desert_F): JCA_V_CarrierRigKBT_01_recon_MTP_desert_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Recon Rig (MTP-Desert)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_recon_MTP_tropic_F): JCA_V_CarrierRigKBT_01_recon_MTP_tropic_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Recon Rig (MTP-Tropic)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_recon_MTP_woodland_F): JCA_V_CarrierRigKBT_01_recon_MTP_woodland_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Recon Rig (MTP-Woodland)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_recon_olive_F): JCA_V_CarrierRigKBT_01_recon_olive_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Recon Rig (Olive)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_recon_sand_F): JCA_V_CarrierRigKBT_01_recon_sand_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Recon Rig (Sand)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_tactical_black_F): JCA_V_CarrierRigKBT_01_tactical_black_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Tactical Rig (Black)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_tactical_MTP_alpine_F): JCA_V_CarrierRigKBT_01_tactical_MTP_alpine_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Tactical Rig (MTP-Alpine)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_tactical_MTP_tropic_F): JCA_V_CarrierRigKBT_01_tactical_MTP_tropic_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Tactical Rig (MTP-Tropic)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_tactical_MTP_woodland_F): JCA_V_CarrierRigKBT_01_tactical_MTP_woodland_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Tactical Rig (MTP-Woodland)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_tactical_MTP_arid_F): JCA_V_CarrierRigKBT_01_tactical_MTP_arid_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Tactical Rig (MTP-Arid)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_tactical_sand_F): JCA_V_CarrierRigKBT_01_tactical_sand_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Tactical Rig (Sand)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_black_F): JCA_V_CarrierRigKBT_01_black_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Vest (Black)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_MTP_alpine_F): JCA_V_CarrierRigKBT_01_MTP_alpine_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Vest (MTP-Alpine)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_MTP_desert_F): JCA_V_CarrierRigKBT_01_MTP_desert_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Vest (MTP-Desert)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_MTP_woodland_F): JCA_V_CarrierRigKBT_01_MTP_woodland_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Vest (MTP-Woodland)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_MTP_arid_F): JCA_V_CarrierRigKBT_01_MTP_arid_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Vest (MTP-Arid)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_olive_F): JCA_V_CarrierRigKBT_01_olive_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Vest (Olive)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_sand_F): JCA_V_CarrierRigKBT_01_sand_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Vest (Sand)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_MTP_tropic_F): JCA_V_CarrierRigKBT_01_MTP_tropic_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Vest (MTP-Tropic)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_tactical_olive_F): JCA_V_CarrierRigKBT_01_tactical_olive_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Tactical Rig (Olive)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_tactical_MTP_desert_F): JCA_V_CarrierRigKBT_01_tactical_MTP_desert_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Tactical Rig (MTP-Desert)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_recon_MTP_arid_F): JCA_V_CarrierRigKBT_01_recon_MTP_arid_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Recon Rig (MTP-Arid)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_recon_black_F): JCA_V_CarrierRigKBT_01_recon_black_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Recon Rig (Black)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_light_MTP_tropic_F): JCA_V_CarrierRigKBT_01_light_MTP_tropic_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Lite (MTP-Tropic)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_holster_olive_F): JCA_V_CarrierRigKBT_01_holster_olive_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Holster (Olive)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_holster_MTP_desert_F): JCA_V_CarrierRigKBT_01_holster_MTP_desert_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Holster (MTP-Desert)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_heavy_MTP_arid_F): JCA_V_CarrierRigKBT_01_heavy_MTP_arid_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier GL Rig (MTP-Arid)";
        JMFSB_HEAVY_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_heavy_black_F): JCA_V_CarrierRigKBT_01_heavy_black_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier GL Rig (Black)";
        JMFSB_HEAVY_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_crew_MTP_tropic_F): JCA_V_CarrierRigKBT_01_crew_MTP_tropic_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Crew Vest (MTP-Tropic)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_CQB_olive_F): JCA_V_CarrierRigKBT_01_CQB_olive_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier CQB Rig (Olive)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_CQB_MTP_desert_F): JCA_V_CarrierRigKBT_01_CQB_MTP_desert_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier CQB Rig (MTP-Desert)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_compact_MTP_arid_F): JCA_V_CarrierRigKBT_01_compact_MTP_arid_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Compact Vest (MTP-Arid)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_compact_black_F): JCA_V_CarrierRigKBT_01_compact_black_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Compact Vest (Black)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_command_MTP_tropic_F): JCA_V_CarrierRigKBT_01_command_MTP_tropic_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Command Rig (MTP-Tropic)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };
    class GVAR(JCA_V_CarrierRigKBT_01_combat_olive_F): JCA_V_CarrierRigKBT_01_combat_olive_F {
        author = QAUTHOR;
        scope = 2;
        scopeArsenal = 2;
        displayName = "[JMSB] Modular Carrier Combat Rig (Olive)";
        JMFSB_STANDARD_VEST_ITEMINFO
    };

    // ===== OCP retextures (textures from Ample Camo Pack, author Seb) =====
    class GVAR(JCA_V_CarrierRigKBT_01_combat_ocp_F): GVAR(JCA_V_CarrierRigKBT_01_combat_black_F) {
        displayName = "[JMSB] Modular Carrier Combat Rig (OCP)";
        picture = QPATHTOF(data\ui\icon_carrierrigkbt_01_ocp.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\carrierrigkbt_01_us_ocp_co.paa)};
    };
    class GVAR(JCA_V_CarrierRigKBT_01_command_ocp_F): GVAR(JCA_V_CarrierRigKBT_01_command_black_F) {
        displayName = "[JMSB] Modular Carrier Command Rig (OCP)";
        picture = QPATHTOF(data\ui\icon_carrierrigkbt_01_ocp.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\carrierrigkbt_01_us_ocp_co.paa)};
    };
    class GVAR(JCA_V_CarrierRigKBT_01_compact_ocp_F): GVAR(JCA_V_CarrierRigKBT_01_compact_MTP_alpine_F) {
        displayName = "[JMSB] Modular Carrier Compact Vest (OCP)";
        picture = QPATHTOF(data\ui\icon_carrierrigkbt_01_compact_ocp.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\carrierrigkbt_01_us_ocp_co.paa)};
    };
    class GVAR(JCA_V_CarrierRigKBT_01_CQB_ocp_F): GVAR(JCA_V_CarrierRigKBT_01_CQB_black_F) {
        displayName = "[JMSB] Modular Carrier CQB Rig (OCP)";
        picture = QPATHTOF(data\ui\icon_carrierrigkbt_01_cqb_ocp.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\carrierrigkbt_01_us_ocp_co.paa)};
    };
    class GVAR(JCA_V_CarrierRigKBT_01_crew_ocp_F): GVAR(JCA_V_CarrierRigKBT_01_crew_black_F) {
        displayName = "[JMSB] Modular Carrier Crew Vest (OCP)";
        picture = QPATHTOF(data\ui\icon_carrierrigkbt_01_crew_ocp.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\carrierrigkbt_01_us_ocp_co.paa)};
    };
    class GVAR(JCA_V_CarrierRigKBT_01_heavy_ocp_F): GVAR(JCA_V_CarrierRigKBT_01_heavy_MTP_alpine_F) {
        displayName = "[JMSB] Modular Carrier GL Rig (OCP)";
        picture = QPATHTOF(data\ui\icon_carrierrigkbt_01_heavy_ocp.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\carrierrigkbt_01_us_ocp_co.paa)};
    };
    class GVAR(JCA_V_CarrierRigKBT_01_holster_ocp_F): GVAR(JCA_V_CarrierRigKBT_01_holster_black_F) {
        displayName = "[JMSB] Modular Carrier Holster (OCP)";
        picture = QPATHTOF(data\ui\icon_carrierrigkbt_01_holster_ocp.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\carrierrigkbt_01_us_ocp_co.paa)};
    };
    class GVAR(JCA_V_CarrierRigKBT_01_light_ocp_F): GVAR(JCA_V_CarrierRigKBT_01_light_black_F) {
        displayName = "[JMSB] Modular Carrier Lite (OCP)";
        picture = QPATHTOF(data\ui\icon_carrierrigkbt_01_light_ocp.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\carrierrigkbt_01_us_ocp_co.paa)};
    };
    class GVAR(JCA_V_CarrierRigKBT_01_recon_ocp_F): GVAR(JCA_V_CarrierRigKBT_01_recon_MTP_alpine_F) {
        displayName = "[JMSB] Modular Carrier Recon Rig (OCP)";
        picture = QPATHTOF(data\ui\icon_carrierrigkbt_01_recon_ocp.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\carrierrigkbt_01_us_ocp_co.paa)};
    };
    class GVAR(JCA_V_CarrierRigKBT_01_tactical_ocp_F): GVAR(JCA_V_CarrierRigKBT_01_tactical_black_F) {
        displayName = "[JMSB] Modular Carrier Tactical Rig (OCP)";
        picture = QPATHTOF(data\ui\icon_carrierrigkbt_01_tactical_ocp.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\carrierrigkbt_01_us_ocp_co.paa)};
    };
};

#undef JMFSB_STANDARD_VEST_ITEMINFO
#undef JMFSB_HEAVY_VEST_ITEMINFO
