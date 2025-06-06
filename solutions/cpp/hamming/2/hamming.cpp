#include "hamming.h"

#include <stdexcept>

namespace hamming
{
    uint32_t compute(const std::string &first, const std::string &second)
    {
        if (first.length() != second.length())
            throw std::domain_error{"String do not have the same length"};

        uint32_t total_differences = 0;

        for (size_t i = 0; i < first.length(); i++)
        {
            if (first[i] != second[i])
                total_differences++;
        }

        return total_differences;
    }

} // namespace hamming
