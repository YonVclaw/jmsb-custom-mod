// Merge third-party addons into the release addons folder before archiving.
let addons = HEMTT_OUT.join("addons");
if !addons.exists() {
    addons.create_dir_all();
}
HEMTT_RFS.join("3rdparty").join("addons").copy(addons);

// Merge third-party keys into the release keys folder before archiving.
let keys = HEMTT_OUT.join("keys");
if !keys.exists() {
    keys.create_dir_all();
}
HEMTT_RFS.join("3rdparty").join("keys").copy(keys);
