#include "etl.h"

#include <cctype>
#include <iostream>

namespace etl
{
    new_t transform(const old_t &legacy_data)
    {
        new_t transformed{};

        for (auto point_letters : legacy_data)
        {
            int point_value = point_letters.first;
            for (char letter : point_letters.second)
            {
                transformed[std::tolower(letter)] = point_value;
            }
        }
        return transformed;
    }

} // namespace etl
