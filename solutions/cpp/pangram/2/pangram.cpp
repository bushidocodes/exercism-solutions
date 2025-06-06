#include "pangram.h"

#include <algorithm>
#include <cctype>
#include <cstdint>
#include <set>

namespace pangram
{
    const std::int16_t ASCII_LOWER_COUNT = 26;

    bool is_pangram(const std::string &text)
    {
        std::set<char> char_used{};

        for (char c : text)
        {
            if (std::isalpha(c))
            {
                char_used.insert(std::tolower(c));
            }
        }

        return char_used.size() == ASCII_LOWER_COUNT;
    }
} // namespace pangram
