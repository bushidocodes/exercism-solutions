#include "reverse_string.h"
#include <algorithm>

static_assert(__cplusplus >= 201703);
// C++20: std::ranges::views::reverse

using namespace std;

namespace reverse_string {
    string reverse_string(string_view input) {
        std::string result{input};
        reverse(result.begin(), result.end());
        return result;
    }
}
