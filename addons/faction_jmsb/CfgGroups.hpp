// ONE GROUP, SIXTY-FOUR STRONG - the company, as player slots.
//
// THE 1ST JMSB IS A PLAYER FACTION, so the group is not a squad the AI composes: it is
// the slot list a mission is built from. Sixty-four is the whole company in one
// group, and a mission deletes down to whatever it actually needs rather than
// stitching four-man teams together.
//
// A FACTION WITH NO GROUPS IS INVISIBLE to Zeus's group list and to anything
// that asks a faction what it can field, so this is also what makes the
// faction real to the rest of the game.
//
// RANK IS THE COMMAND CHAIN, not decoration: a captain, a sergeant at the head
// of each eight, and privates. Arma hands command down that order, so a company
// that loses its captain still has seven men who can lead an element.
//
// Laid out eight by eight at five metres - a parade block, not a formation. The
// mission moves them; this only has to not stack sixty-four men on one spot.

class CfgGroups {
    class West {

        class GVAR(ocp) {
            name = "2040 1st JMSB";

            class Infantry {
                name = "Infantry";

                class GVAR(ocp_Company) {
                    name = "1st JMSB Alpha Company (64)";
                    side = 1;
                    faction = QGVAR(ocp);
                    icon = "\A3\ui_f\data\map\markers\nato\b_recon.paa";
                    rarityGroup = 1;

                    class Unit0 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "CAPTAIN";
                        position[] = {0, 0, 0};
                    };
                    class Unit1 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {5, 0, 0};
                    };
                    class Unit2 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {10, 0, 0};
                    };
                    class Unit3 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {15, 0, 0};
                    };
                    class Unit4 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {20, 0, 0};
                    };
                    class Unit5 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {25, 0, 0};
                    };
                    class Unit6 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {30, 0, 0};
                    };
                    class Unit7 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {35, 0, 0};
                    };
                    class Unit8 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "SERGEANT";
                        position[] = {0, -5, 0};
                    };
                    class Unit9 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {5, -5, 0};
                    };
                    class Unit10 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {10, -5, 0};
                    };
                    class Unit11 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {15, -5, 0};
                    };
                    class Unit12 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {20, -5, 0};
                    };
                    class Unit13 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {25, -5, 0};
                    };
                    class Unit14 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {30, -5, 0};
                    };
                    class Unit15 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {35, -5, 0};
                    };
                    class Unit16 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "SERGEANT";
                        position[] = {0, -10, 0};
                    };
                    class Unit17 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {5, -10, 0};
                    };
                    class Unit18 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {10, -10, 0};
                    };
                    class Unit19 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {15, -10, 0};
                    };
                    class Unit20 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {20, -10, 0};
                    };
                    class Unit21 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {25, -10, 0};
                    };
                    class Unit22 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {30, -10, 0};
                    };
                    class Unit23 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {35, -10, 0};
                    };
                    class Unit24 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "SERGEANT";
                        position[] = {0, -15, 0};
                    };
                    class Unit25 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {5, -15, 0};
                    };
                    class Unit26 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {10, -15, 0};
                    };
                    class Unit27 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {15, -15, 0};
                    };
                    class Unit28 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {20, -15, 0};
                    };
                    class Unit29 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {25, -15, 0};
                    };
                    class Unit30 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {30, -15, 0};
                    };
                    class Unit31 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {35, -15, 0};
                    };
                    class Unit32 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "SERGEANT";
                        position[] = {0, -20, 0};
                    };
                    class Unit33 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {5, -20, 0};
                    };
                    class Unit34 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {10, -20, 0};
                    };
                    class Unit35 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {15, -20, 0};
                    };
                    class Unit36 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {20, -20, 0};
                    };
                    class Unit37 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {25, -20, 0};
                    };
                    class Unit38 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {30, -20, 0};
                    };
                    class Unit39 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {35, -20, 0};
                    };
                    class Unit40 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "SERGEANT";
                        position[] = {0, -25, 0};
                    };
                    class Unit41 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {5, -25, 0};
                    };
                    class Unit42 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {10, -25, 0};
                    };
                    class Unit43 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {15, -25, 0};
                    };
                    class Unit44 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {20, -25, 0};
                    };
                    class Unit45 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {25, -25, 0};
                    };
                    class Unit46 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {30, -25, 0};
                    };
                    class Unit47 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {35, -25, 0};
                    };
                    class Unit48 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "SERGEANT";
                        position[] = {0, -30, 0};
                    };
                    class Unit49 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {5, -30, 0};
                    };
                    class Unit50 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {10, -30, 0};
                    };
                    class Unit51 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {15, -30, 0};
                    };
                    class Unit52 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {20, -30, 0};
                    };
                    class Unit53 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {25, -30, 0};
                    };
                    class Unit54 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {30, -30, 0};
                    };
                    class Unit55 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {35, -30, 0};
                    };
                    class Unit56 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "SERGEANT";
                        position[] = {0, -35, 0};
                    };
                    class Unit57 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {5, -35, 0};
                    };
                    class Unit58 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {10, -35, 0};
                    };
                    class Unit59 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {15, -35, 0};
                    };
                    class Unit60 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {20, -35, 0};
                    };
                    class Unit61 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {25, -35, 0};
                    };
                    class Unit62 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {30, -35, 0};
                    };
                    class Unit63 {
                        side = 1;
                        vehicle = QGVAR(ocp_ReconScout);
                        rank = "PRIVATE";
                        position[] = {35, -35, 0};
                    };
                };
            };
        };
    };
};
