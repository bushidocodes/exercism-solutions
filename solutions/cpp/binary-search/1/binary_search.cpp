#include <cmath>
#include <stdexcept>

#include "binary_search.h"

namespace binary_search
{

    std::size_t find(std::vector<int> data, int value)
    {
        if (data.empty())
        {
            throw std::domain_error("Value not found!");
        }

        /* Initialize Bounds */
        int low = 0;
        int high = data.size() - 1;

        int mid = low + std::floor((high - low) / 2);
        int at_mid = data.at(mid);

        while (value != at_mid)
        {
            if (high <= low)
            {
                throw std::domain_error("Value not found!");
            }
            else if (value > at_mid && mid)
            {
                low = mid + 1;
            }
            else if (value < at_mid)
            {
                high = mid - 1;
            }

            mid = low + std::floor((high - low) / 2);
            at_mid = data.at(mid);
        }
        return mid;
    }

} // namespace binary_search
