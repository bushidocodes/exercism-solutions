#include "hamming.h"
#include <stdexcept>

static_assert(__cplusplus >= 201703);
// C++20: std::adjacent_difference

using namespace std;

namespace hamming {
    uint32_t compute(const string_view first, const string_view second) {
        if (first.length() != second.length()) {
            throw std::domain_error{"String do not have the same length"};
        }

        uint32_t total_differences = 0;

        for (size_t i = 0; i < first.length(); i++) {
            if (first.at(i) != second.at(i)) {
                total_differences++;
            }
        }

        return total_differences;
    }

} // namespace hamming
