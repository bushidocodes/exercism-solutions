#include "pangram.h"

#include <cctype>
#include <set>

using namespace std;

namespace pangram {
    const int16_t ASCII_LOWER_COUNT = 26;

    bool is_pangram(const string &text) {
        set<char> char_used{};

        for (char c : text) {
            if (isalpha(c)) char_used.insert(tolower(c));
        }

        return char_used.size() == ASCII_LOWER_COUNT;
    }
}
