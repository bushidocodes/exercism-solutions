#include "raindrops.h"

namespace raindrops
{

    std::string convert(unsigned int number)
    {
        std::string raindrop_sounds = "";

        if (number % 3 == 0)
        {
            raindrop_sounds.append("Pling");
        }

        if (number % 5 == 0)
        {
            raindrop_sounds.append("Plang");
        }

        if (number % 7 == 0)
        {
            raindrop_sounds.append("Plong");
        }

        if (raindrop_sounds.length() == 0)
        {
            raindrop_sounds = std::to_string(number);
        }

        return raindrop_sounds;
    }

} // namespace raindrops
