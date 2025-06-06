#include "isbn_verifier.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <cctype>

namespace isbn_verifier {
using namespace std;

bool is_valid(string_view isbn)
{
    if (isbn.size() < 10)
    {
        return false;
    }
    
    // any_of: If any but the last character are not number or '-', return false
    if (any_of(isbn.cbegin(), isbn.cend() - 1, [](char e) { return !isdigit(e) && e != '-'; }))
    {
        return false;
    }

    // if last character is not number or 'X', return false
    auto lastChar = isbn[isbn.size() - 1];
    if (!isdigit(lastChar) && lastChar != 'X')
    {
        return false;
    }

    int digit_count = count_if(
        isbn.cbegin(), isbn.cend(), 
        [](char elem){ return isdigit(elem) || elem == 'X'; });

    if (digit_count != 10) {
        return false;
    }

    int sum = accumulate(
        isbn.cbegin(), isbn.cend(), 
        0, [count=10](int acc, char c) mutable { 
            if (count == 1 && c == 'X') 
                return acc + (10 * count--);
            else if (isdigit(c)) 
                return acc + ((int)(c - '0') * count--);
            else 
                return acc;
        });
   
    return sum % 11 == 0;
}

}  // namespace isbn_verifier