#include "trinary.h"

#include <cmath>

namespace trinary
{
    const int trinary_base = 3;

    int to_decimal(const std::string &trinary_string)
    {
        int value = 0;

        /* 0-based position of digit, from left to right */
        int position = trinary_string.length() - 1;

        for (char trinary_char : trinary_string)
        {
            /* Validate */
            if (trinary_char != '0' && trinary_char != '1' && trinary_char != '2')
            {
                return 0;
            }

            /* Accumulate */
            int trinary_digit = trinary_char - '0';
            value += (trinary_digit * std::pow(trinary_base, position));
            position--;
        }

        return value;
    }

} // namespace trinary
