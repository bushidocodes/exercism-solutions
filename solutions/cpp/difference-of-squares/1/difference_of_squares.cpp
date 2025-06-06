#include "difference_of_squares.h"
#include <numeric>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

namespace difference_of_squares
{
    uint64_t square_of_sum(uint32_t n)
    {
        uint32_t sum = 0;
        for (uint32_t i = 1; i <= n; i++)
            sum += i;

        return sum * sum;
    }

    uint64_t sum_of_squares(uint32_t n)
    {
        vector<uint32_t> sequence(n);
        vector<uint32_t> squares(n);
        iota(begin(sequence), end(sequence), 1);

        transform(
            begin(sequence), end(sequence), begin(squares),
            [](auto value) -> auto { return value * value; });

        uint32_t sum = 0;
        for (uint32_t square : squares)
            sum += square;

        return sum;
    }

    uint64_t difference(uint32_t n)
    {
        return square_of_sum(n) - sum_of_squares(n);
    }

} // namespace difference_of_squares
