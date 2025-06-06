#include <cmath>
#include <cctype>

#include "hexadecimal.h"

namespace hexadecimal
{
    const int HEX_BASE = 16;

    int convert(std::string hex_string)
    {
        int hex_value = 0;

        /* 
         * This position is the power in 16^n 
         * We are going from most to least significant
         */
        size_t xdigit_position = hex_string.length() - 1;
        for (char c : hex_string)
        {
            /* Immediately return 0 if invalid hex char */
            if (!isxdigit(c))
                return 0;

            /* 
             * 0-9 and a-f are not adjacent on the ASCI table
             * So we need to adjust a-f values beyond just an offset
             */
            int digit = isdigit(c) ? c - '0' : 10 + c - 'a';
            hex_value += digit * pow(HEX_BASE, xdigit_position);
            xdigit_position--;
        }

        return hex_value;
    }

} // namespace hexadecimal
