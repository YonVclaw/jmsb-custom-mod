#define MAINPREFIX z
#define PREFIX jmfsb
#define QPREFIX "jmfsb"

#define AUTHOR JMSB
#define QAUTHOR QUOTE(AUTHOR)
#define LOGO_PATH QUOTE(z\jmfsb\addons\fa_media\images\logo_256.paa)
#define URL "https://github.com/Joint-Multi-Functional-Strike-Battalion/"

#include "\z\jmfsb\addons\main\script_version.hpp"

#define VERSION     MAJOR.MINOR
#define VERSION_STR MAJOR.MINOR.PATCH
#define VERSION_AR  MAJOR,MINOR,PATCH

#define REQUIRED_VERSION 2.14

#ifdef COMPONENT_BEAUTIFIED
    #define COMPONENT_NAME QUOTE(1st Joint Multi-Functional Strike Battalion - COMPONENT_BEAUTIFIED)
#else
    #define COMPONENT_NAME QUOTE(1st Joint Multi-Functional Strike Battalion - COMPONENT)
#endif
