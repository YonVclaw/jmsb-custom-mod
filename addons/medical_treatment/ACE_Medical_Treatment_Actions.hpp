class ACEGVAR(medical_treatment,actions) {
    // ACE'S OWN CLASSES, DECLARED SO OUR CHILDREN CAN NAME THEM. A bare
    // reopen of one of these is a definition and strips its parent - the
    // 2026-08-30 RPT had eight of them ("Updating base class
    // 'BasicBandage'->''"). A DECLARATION carries no body and is safe.
    class CheckPulse;
    class FieldDressing;

    class BasicBandage {
        treatmentTime = QUOTE(call ACEFUNC(medical_treatment,getBandageTime));
        medicRequired = 0;
    };

    class ApplyTourniquet: BasicBandage {
        treatmentTime = 2.5;
        medicRequired = 0;
    };
    class RemoveTourniquet: ApplyTourniquet {
        treatmentTime = 1.5;
        medicRequired = 0;
    };

    class Splint: BasicBandage {
        treatmentTime = 5;
        medicRequired = 0;
    };
    class Morphine: FieldDressing {
        medicRequired = 2;
    };

    class EatApap: Morphine {
        allowedSelections[] = {"head"};
        allowSelfTreatment = 1;
        displayName = "Eat Apap";
        displayNameProgress = "Eating Apap...";
        icon = QPATHTOF(ui\icons\apap.paa);
        medicRequired = 0;
        items[] = {"JMFSB_apap"};
        condition = "(_this select 1) isEqualTo player";
        litter[] = { {"All", "", {"JMFSB_MedicalLitter_apap"}} };
    };
    class AdministerApap: EatApap {
        allowSelfTreatment = 0;
        medicRequired = 0;
        displayName = "Administer Apap";
        displayNameProgress = "Administering Apap...";
        condition = "!((_this select 1) getVariable ['ACE_isUnconscious', false])";
    };


    class BloodIV: BasicBandage {
        treatmentTime = 5;
    };
    class PackingBandage: BasicBandage {
        medicRequired = 1;
    };
    class ElasticBandage: BasicBandage {
        medicRequired = 1;
    };
    class QuikClot: BasicBandage {
        medicRequired = 1;
    };
    class CheckBloodPressure: CheckPulse {
        medicRequired = 1;
    };
};
