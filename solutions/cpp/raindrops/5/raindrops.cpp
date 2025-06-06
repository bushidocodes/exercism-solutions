#include "raindrops.h"

#include <array>
#include <numeric>
#include <utility>

using namespace std;

namespace {
const array<pair<int32_t, string>, 3> sounds {{{3, "Pling"},{5, "Plang"},{7, "Plong"}}};
}

string raindrops::convert(int32_t number) {
    string raindrop_sounds = accumulate(cbegin(sounds), cend(sounds), string{}, 
    [number](auto& acc, const auto& sound){
        if (number % sound.first == 0) acc += sound.second;
        return acc;
        }
    );

    return !raindrop_sounds.empty() ? raindrop_sounds : to_string(number);
}
