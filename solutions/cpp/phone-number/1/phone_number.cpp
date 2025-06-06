#include "phone_number.h"

#include <cctype>
#include <set>
#include <sstream>
#include <stdexcept>

namespace phone_number
{
    const std::set<char> valid_formatting_characters = {' ', '-', '+', '.', '+', '(', ')'};

    phone_number::phone_number(const std::string &raw)
    {
        normalized = "";
        bool is_first_digit = true;

        for (char c : raw)
        {
            if (std::isdigit(c))
            {
                /* Ignore the first leading 1 */
                if (is_first_digit)
                {
                    is_first_digit = false;
                    if (c == '1')
                    {
                        continue;
                    }
                }

                /* Validate leading digit of area code */
                if (normalized.length() == 0 && (c == '0' || c == '1'))
                {
                    throw std::domain_error("Area code cannot start with 0 or 1");
                }

                /* Validate leading digit of exchange code */
                else if (normalized.length() == 3 && (c == '0' || c == '1'))
                {
                    throw std::domain_error("Area code cannot start with 0 or 1");
                }

                normalized.push_back(c);
            }
            /* Validate that non-numerics are part of a sane representation */
            else if (valid_formatting_characters.count(c) == 0)
            {
                throw std::domain_error("Contained invalid characters");
            }
        }

        /* Validate Length */
        if (normalized.length() != 10)
        {
            throw std::domain_error("Invalid number of digits in phone number");
        }
    } // namespace phone_number

    std::string phone_number::number()
    {
        return normalized;
    }

    std::string phone_number::area_code()
    {
        return normalized.substr(0, 3);
    }

    phone_number::
    operator std::string() const
    {
        std::stringstream formatted;
        formatted << '(' << normalized.substr(0, 3) << ") "
                  << normalized.substr(3, 3) << '-' << normalized.substr(6, 4);

        return formatted.str();
    }

} // namespace phone_number
