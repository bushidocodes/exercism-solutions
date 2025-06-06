#include "roman_numerals.h"

#include <vector>
#include <tuple>

using namespace std;

namespace roman_numerals {
    vector<tuple<int, string>> numerals {
        {1000, "M"}, {900, "CM"}, {500, "D"},
        {400, "CD"}, {100, "C"},  {90, "XC"},
        {50, "L"},   {40, "XL"},  {10, "X"},
        {9, "IX"},   {5, "V"},    {4, "IV"},
        {1, "I"}};

    string convert(int arabic) {
        
        string result{};
        for (auto& [first, second]: numerals) {
            while (arabic >= first) {
                result.append(second);
                arabic -= first;
            }
        }

        return result;
    }

} // namespace roman_numerals
