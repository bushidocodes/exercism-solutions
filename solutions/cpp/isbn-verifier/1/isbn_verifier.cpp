#include "isbn_verifier.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <cctype>

namespace isbn_verifier {

bool is_valid(std::string_view isbn)
{
    int digit_count = std::accumulate(
        isbn.cbegin(), isbn.cend(), 
        0, [](int acc, char elem){ 
            if (elem == '-')
                return acc;
            else if (std::isdigit(elem) || (acc == 9 && elem == 'X')) 
                return acc + 1;
            else 
                return 11;
        });

    if (digit_count != 10) {
        return false;
    }

    int sum = std::accumulate(
        isbn.cbegin(), isbn.cend(), 
        0, [count=10](int acc, char c) mutable { 
            if (count == 1 && c == 'X') 
                return acc + (10 * count--);
            else if (std::isdigit(c)) 
                return acc + ((int)(c - '0') * count--);
            else 
                return acc;
        });
   
    return sum % 11 == 0;
}

}  // namespace isbn_verifier