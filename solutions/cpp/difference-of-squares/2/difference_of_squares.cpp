#include "difference_of_squares.h"
#include <numeric>
#include <algorithm>
#include <vector>

using namespace std;

namespace difference_of_squares
{

    uint64_t square_of_sum(uint32_t n)
    {
        vector<uint32_t> sequence(n);
        iota(begin(sequence), end(sequence), 1);

        auto sum = accumulate(begin(sequence), end(sequence), 0);

        return sum * sum;
    }

    uint64_t sum_of_squares(uint32_t n)
    {
        vector<uint32_t> sequence(n);
        iota(begin(sequence), end(sequence), 1);

        transform(
            begin(sequence), end(sequence), begin(sequence),
            [](auto value) { return value * value; });

        return accumulate(begin(sequence), end(sequence), 0);
    }

    uint64_t difference(uint32_t n)
    {
        return square_of_sum(n) - sum_of_squares(n);
    }

} // namespace difference_of_squares
