#include "isogram.h"

#include <cctype>
#include <set>
#include <utility>

static_assert(__cplusplus >= 201703);
// C++20: Consider std::set::contains
// C++20: Consider std::ranges::views::split

namespace isogram
{
    bool is_isogram(std::string_view candidate)
    {
        std::set<char> chars;

        for (char c: candidate) {
            if (!std::isalpha(c)) {
                continue;
            }

            char key = std::tolower(c);
            if (chars.find(key) == chars.end()) {
                chars.insert(key);
            } else {
                return false;
            }
        }
        return true;
    }

} // namespace isogram
