
class EMM_mainMenu_CfgMenus {
    class VN {
        class menus {
            class MainMenu;
            class MultiplayerVN: MainMenu {
                items[] = {"jmfsb", "ServerBrowser", "SOGPrairieFire", "MikeForce", "Exit"};

                class ServerBrowser;
                class jmfsb: ServerBrowser {
                    action = QUOTE(call (uiNamespace getVariable QQFUNC(join)));
                    text = "1st Joint Multi-Functional Strike Battalion";
                };
            };
        };
    };
};
