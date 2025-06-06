#pragma once

#include <vector>

namespace all_your_base
{
    using digit_vec_t = std::vector<unsigned int>;

    digit_vec_t convert(int input_base, digit_vec_t input, int output_base);
} // namespace all_your_base
