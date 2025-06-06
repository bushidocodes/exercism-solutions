#include "armstrong_numbers.h"

#include <algorithm>
#include <cmath>
#include <vector>

namespace armstrong_numbers
{

    bool is_armstrong_number(std::int32_t original_number)
    {
        /* Assumption: Negatives cannot be Armstrong numbers */
        if (original_number < 0)
            return false;

        /* Extract all digits into a collection */
        std::vector<std::int32_t> digits{};
        std::int32_t buffer = original_number;
        while (buffer > 0)
        {
            digits.push_back(buffer % 10);
            buffer /= 10;
        }

        /* Raise each digit to the power of the number of digits */
        std::int32_t number_of_digits = digits.size();
        std::transform(
            digits.begin(),
            digits.end(),
            digits.begin(),
            [number_of_digits](std::int32_t digit) { return pow(digit, number_of_digits); });

        /* Sum the resulting powers */
        std::int32_t sum_of_digits_power = 0;
        for (std::int32_t digit_squared : digits)
        {
            sum_of_digits_power += digit_squared;
        }

        /* And compare the result with the original number */
        return original_number == sum_of_digits_power;
    }

} // namespace armstrong_numbers
