#include "pangram.h"

#include <cctype>
#include <set>

using namespace std;

namespace pangram {
    const int ascii_letter_count = 26;

    bool is_pangram(const string &text) {
        set<char> char_used{};

        for (char c : text) {
            if (isalpha(c)) char_used.insert(tolower(c));
        }

        return char_used.size() == ascii_letter_count;
    }
}
