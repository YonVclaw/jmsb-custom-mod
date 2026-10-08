#define LOADING_SCREEN_CLASS(className,authorName) \
    class className { \
        author = QUOTE(authorName); \
        path = QPATHTOF(ui\loading\##className##.paa); \
        class Noise { \
            text="\A3\Ui_f\data\GUI\Cfg\LoadingScreens\LoadingNoise_ca.paa"; \
        }; \
    }

class GVAR(CfgLoadingScreen) {
    class Backgrounds {
        LOADING_SCREEN_CLASS(269676636,1st Joint Multi-Functional Strike Battalion);
        LOADING_SCREEN_CLASS(269676677,1st Joint Multi-Functional Strike Battalion);
        LOADING_SCREEN_CLASS(271859839,1st Joint Multi-Functional Strike Battalion);
        LOADING_SCREEN_CLASS(285905473,1st Joint Multi-Functional Strike Battalion);
        LOADING_SCREEN_CLASS(296841733,1st Joint Multi-Functional Strike Battalion);
        LOADING_SCREEN_CLASS(297308106,1st Joint Multi-Functional Strike Battalion);
        LOADING_SCREEN_CLASS(298480575,1st Joint Multi-Functional Strike Battalion);
        LOADING_SCREEN_CLASS(361616315,1st Joint Multi-Functional Strike Battalion);
        LOADING_SCREEN_CLASS(287796119,1st Joint Multi-Functional Strike Battalion);
        LOADING_SCREEN_CLASS(288887578,1st Joint Multi-Functional Strike Battalion);
        LOADING_SCREEN_CLASS(319048089,1st Joint Multi-Functional Strike Battalion);
        LOADING_SCREEN_CLASS(maxresdefault,1st Joint Multi-Functional Strike Battalion);
        LOADING_SCREEN_CLASS(269677107,1st Joint Multi-Functional Strike Battalion);
        LOADING_SCREEN_CLASS(272813407,1st Joint Multi-Functional Strike Battalion);
        LOADING_SCREEN_CLASS(275306051,1st Joint Multi-Functional Strike Battalion);
        LOADING_SCREEN_CLASS(283924597,1st Joint Multi-Functional Strike Battalion);
        LOADING_SCREEN_CLASS(371890417,1st Joint Multi-Functional Strike Battalion);
        LOADING_SCREEN_CLASS(400370807,1st Joint Multi-Functional Strike Battalion);
        LOADING_SCREEN_CLASS(254754921,1st Joint Multi-Functional Strike Battalion);
        LOADING_SCREEN_CLASS(273347491,1st Joint Multi-Functional Strike Battalion);
        LOADING_SCREEN_CLASS(275458856,1st Joint Multi-Functional Strike Battalion);
        LOADING_SCREEN_CLASS(286142395,1st Joint Multi-Functional Strike Battalion);
        LOADING_SCREEN_CLASS(298331323,1st Joint Multi-Functional Strike Battalion);
        LOADING_SCREEN_CLASS(356376886,1st Joint Multi-Functional Strike Battalion);
        LOADING_SCREEN_CLASS(S291207115895,1st Joint Multi-Functional Strike Battalion);
    };
};
