#include "pangram.h"

#include <cctype>
#include <set>
#include <numeric>
#include <string_view>

using namespace std;

namespace pangram {
    constexpr int16_t ASCII_LOWER_COUNT = 26;

    bool is_pangram(string_view text) {
        const auto char_used = accumulate(
            text.cbegin(), text.cend(), set<char>{}, 
            [](auto& acc, auto c){ 
                if (isalpha(c)) { acc.insert(tolower(c)); } 
                return acc; 
            }
        );
        
        return char_used.size() == ASCII_LOWER_COUNT;
    }
}
