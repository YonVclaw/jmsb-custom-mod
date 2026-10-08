class CfgMagazines {
    class CA_Magazine;
    class ATMine_Range_Mag;
    class DemoCharge_Remote_Mag;
    class SatchelCharge_Remote_Mag : CA_Magazine {
        class ACE_Triggers {
            SupportedTriggers[]={"Timer", "Command", "MK16_Transmitter", "DeadmanSwitch", "Shock", "ShockShort"};
            class Shock {
                FuseTime=3;
            };
            class ShockShort {
                FuseTime=2;
            };
        };
    };
    class SLAMDirectionalMine_Wire_Mag : ATMine_Range_Mag {
        class ACE_Triggers {
            SupportedTriggers[]={"IRSensor", "PressurePlate", "Command", "Timer", "MK16_Transmitter", "Shock", "ShockShort"};
            class Shock {
                FuseTime=3;
            };
            class ShockShort {
                FuseTime=2;
            };
        };
    };
    class IEDUrbanSmall_Remote_Mag : DemoCharge_Remote_Mag {
        class ACE_Triggers {
            SupportedTriggers[]={"Cellphone", "PressurePlate", "Command", "DeadmanSwitch", "Shock", "ShockShort"};
            class Shock {
                FuseTime=3;
            };
            class ShockShort {
                FuseTime=2;
            };
        };
    };
    class IEDUrbanBig_Remote_Mag : DemoCharge_Remote_Mag {
        class ACE_Triggers {
            SupportedTriggers[]={"Cellphone", "PressurePlate", "Command", "DeadmanSwitch", "Shock", "ShockShort"};
            class Shock {
                FuseTime=3;
            };
            class ShockShort {
                FuseTime=2;
            };
        };
    };
};

