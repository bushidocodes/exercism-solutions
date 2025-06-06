#include "pangram.h"

#include <algorithm>
#include <cctype>
#include <map>

namespace pangram
{
    bool is_pangram(const std::string &text)
    {
        /* Initialize map with all values set to false */
        std::map<char, bool> char_used{};
        for (char c = 'a'; c <= 'z'; c++)
        {
            char_used[c] = false;
        }

        /* Flag characters in text as present */
        for (char c : text)
        {
            char_used[std::tolower(c)] = true;
        }

        /* Check for pangram by looking for unused characters */
        auto it = std::find_if(
            char_used.begin(), char_used.end(), [](auto pair) {
                return pair.second == false;
            });

        return it == char_used.end();
    }
} // namespace pangram
