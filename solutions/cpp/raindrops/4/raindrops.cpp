#include "raindrops.h"

#include <array>
#include <utility>

using namespace std;

namespace raindrops {
    const array<pair<int32_t, string>, 3> sounds {
        {{3, "Pling"},
         {5, "Plang"},
         {7, "Plong"}}};

    string convert(int32_t number) {
        string raindrop_sounds = "";

        for (auto &sound : sounds) {
            if (number % sound.first == 0) {
                raindrop_sounds += sound.second;
            }
        }

        if (raindrop_sounds.empty()) {
            raindrop_sounds = to_string(number);
        }

        return raindrop_sounds;
    }

}
