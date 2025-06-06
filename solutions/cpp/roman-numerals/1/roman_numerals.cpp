#include "roman_numerals.h"

#include <map>

namespace roman_numerals
{
    std::map<int, std::string> arabic_to_roman{
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}};

    std::string convert(int arabic)
    {
        std::string result = "";

        std::map<int, std::string>::reverse_iterator it;
        for (it = arabic_to_roman.rbegin(); it != arabic_to_roman.rend(); it++)
        {
            while (arabic >= it->first)
            {
                result.append(it->second);
                arabic -= it->first;
            }
        }

        return result;
    }

} // namespace roman_numerals
