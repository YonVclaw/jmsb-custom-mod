// The module, once per placement - this system allows MANY.
PREP(moduleController);

// The support-page provider trio. One entity per module; the seam that lists
// and drives them is neutral, so TAC//SUPPORT shows these beside ALiVE's own
// assets without either side of that knowing the other's name.
PREP(assets);
PREP(task);
PREP(sitrep);

// The run itself.
PREP(request);
PREP(acquire);
PREP(fireAt);
PREP(killed);

// Shared reads, so the provider and the run cannot disagree about what a
// module is offering or whether it has anything left to offer.
PREP(entityRow);
PREP(stores);
PREP(available);
PREP(nearestTo);
