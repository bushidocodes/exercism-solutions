#include "say.h"

#include <map>
#include <stdexcept>

namespace say
{

    std::map<std::uint64_t, std::string> base_number = {
        {0, "zero"},
        {1, "one"},
        {2, "two"},
        {3, "three"},
        {4, "four"},
        {5, "five"},
        {6, "six"},
        {7, "seven"},
        {8, "eight"},
        {9, "nine"},
        {10, "ten"},
        {11, "eleven"},
        {12, "twelve"},
        {13, "thirteen"},
        {14, "fourteen"},
        {15, "fifteen"},
        {16, "sixteen"},
        {17, "seventeen"},
        {18, "eightteen"},
        {19, "nineteen"}};

    std::map<std::uint64_t, std::string> tens = {
        {10, "ten"},
        {20, "twenty"},
        {30, "thirty"},
        {40, "forty"},
        {50, "fifty"},
        {60, "sixty"},
        {70, "seventy"},
        {80, "eighty"},
        {90, "ninety"}};

    std::map<std::uint64_t, std::string> place = {
        {100, "hundred"},
        {1000, "thousand"},
        {1000000, "million"},
        {1000000000, "billion"}};

    std::string
    sub_thousand(std::uint64_t number)
    {
        if (number == 0 || number >= 1000)
            throw std::domain_error("");

        std::string result = "";

        if (number >= 100 && number < 1000)
        {
            int number_of_hundreds = number / 100;
            result += base_number[number_of_hundreds];
            result += " ";
            result += place[100];
            number %= 100;
            if (number > 0)
                result += " ";
        }
        if (number >= 20 && number < 100)
        {
            result += tens[number / 10 * 10];
            number %= 10;
            if (number > 0)
                result += "-";
        }

        if (number >= 1 && number < 20)
        {
            result += base_number[number];
        }
        return result;
    }

    std::string complex_place(std::uint64_t *number, std::uint64_t place_num)
    {
        std::string result = "";
        result += sub_thousand(*number / place_num);
        result += " ";
        result += place[place_num];
        *number %= place_num;

        if (*number != 0)
            result += " ";

        return result;
    }

    std::string
    in_english(std::uint64_t number)
    {
        if (number >= 1'000'000'000'000)
        {
            throw std::domain_error("");
        }

        if (number == 0)
        {
            return "zero";
        }

        std::string result = "";

        if (number >= 1000000000)
        {
            result += complex_place(&number, 1000000000);
        }
        if (number >= 1000000)
        {
            result += complex_place(&number, 1000000);
        }
        if (number >= 1000)
        {
            result += complex_place(&number, 1000);
        }
        if (number > 0)
        {
            result += sub_thousand(number);
        }

        return result;
    }

} // namespace say
