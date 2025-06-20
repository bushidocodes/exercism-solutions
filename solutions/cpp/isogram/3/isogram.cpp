#include "isogram.h"

#include <cctype>
#include <set>
#include <utility>

namespace isogram
{
    bool is_isogram(std::string candidate)
    {
        std::set<char> chars;

        for (char c: candidate)
        {
            if (!std::isalpha(c))
                continue;

            char key = std::tolower(c);
            if (chars.find(key) == chars.end())
                chars.insert(key);
            else
                return false;
        }
        return true;
    }

} // namespace isogram
