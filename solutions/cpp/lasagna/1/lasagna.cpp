// ovenTime returns the amount in minutes that the lasagna should stay in the
// oven.
constexpr auto ovenTime() noexcept {
    return 40;
}

/* remainingOvenTime returns the remaining
   minutes based on the actual minutes already in the oven.
*/
constexpr auto remainingOvenTime(int actualMinutesInOven) noexcept {
    return ovenTime() - actualMinutesInOven;
}

constexpr auto preparationTimePerLayer = 2; 

/* preparationTime returns an estimate of the preparation time based on the
   number of layers and the necessary time per layer.
*/
constexpr auto preparationTime(int numberOfLayers) noexcept {
    return preparationTimePerLayer * numberOfLayers;
}

// elapsedTime calculates the total time spent to create and bake the lasagna so
// far.
constexpr auto elapsedTime(int numberOfLayers, int actualMinutesInOven) noexcept {
    return preparationTime(numberOfLayers) + actualMinutesInOven;
}
