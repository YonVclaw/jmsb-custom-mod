// The vanilla Vorona has no magazine well — it is fed via the
// launch_Vorona_base_F patch in CfgWeapons.hpp (vanilla tubes stay listed in
// the launcher's magazines[]). Other addons can extend it with their own key.
class CfgMagazineWells {
    class FA_Vorona {
        ADDON[] = {
            "FA_Vorona_9M135M",
            "FA_Vorona_9M135F2",
            "FA_Vorona_9M135PVO"
        };
    };
};
