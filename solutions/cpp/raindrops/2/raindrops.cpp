#include "raindrops.h"

#include <array>
#include <utility>

namespace raindrops
{
    std::array<std::pair<int32_t, std::string>, 3> sounds{
        {{3, "Pling"},
         {5, "Plang"},
         {7, "Plong"}}};

    std::string
    convert(std::int32_t number)
    {
        std::string raindrop_sounds = "";

        for (auto sound : sounds)
        {
            if (number % sound.first == 0)
            {
                raindrop_sounds += sound.second;
            }
        }

        if (raindrop_sounds.empty())
        {
            raindrop_sounds = std::to_string(number);
        }

        return raindrop_sounds;
    }

} // namespace raindrops
