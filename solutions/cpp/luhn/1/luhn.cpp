#include "luhn.h"

#include <algorithm>
#include <cctype>

namespace luhn
{
    bool valid(std::string luhn_candidate)
    {
        /* Erase all spaces */
        luhn_candidate.erase(
            std::remove(luhn_candidate.begin(), luhn_candidate.end(), ' '),
            luhn_candidate.end());

        /* Single Digits are invalid */
        if (luhn_candidate.length() < 2)
            return false;

        /* Accumulate Checksum */
        int checksum = 0;
        int luhn_candidate_last_idx = luhn_candidate.length() - 1;
        for (int i = luhn_candidate_last_idx; i >= 0; i--)
        {
            if (!std::isdigit(luhn_candidate.at(i)))
                return false;

            int digit = luhn_candidate[i] - '0';

            /* 
             * From RTL, every double every 2nd digit
             * and subtract 9 if result greater than 9
             */
            if ((luhn_candidate_last_idx - i) % 2 == 1)
            {
                digit *= 2;

                if (digit > 9)
                    digit -= 9;
            }
            checksum += digit;
        }

        /* Confirm 10 is factor of checksum */
        return checksum % 10 == 0;
    }

} // namespace luhn
