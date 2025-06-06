#include "series.h"

#include <cctype>
#include <stdexcept>

namespace series
{

    std::vector<int> digits(std::string number_string)
    {
        std::vector<int> results;

        for (char c : number_string)
        {
            if (std::isdigit(c))
            {
                results.push_back(c - '0');
            }
        }
        return results;
    }

    /* This might be a candidate for use of C++ ranges for each sequence in the series */
    std::vector<std::vector<int>> slice(std::string number_string, size_t slice_size)
    {
        if (slice_size > number_string.size())
            throw std::domain_error("Not enough digits for slice!");

        std::vector<std::vector<int>> results;

        for (size_t i = 0; i < number_string.size() - (slice_size - 1); i++)
        {
            std::vector<int> slice;
            for (size_t j = 0; j < slice_size; j++)
            {
                slice.push_back(number_string[i + j] - '0');
            }
            results.push_back(slice);
        }
        return results;
    }

} // namespace series
