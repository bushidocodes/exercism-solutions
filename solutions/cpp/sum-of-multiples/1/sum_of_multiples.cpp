#include "sum_of_multiples.h"

namespace sum_of_multiples
{

    uint32_t to(const std::set<uint32_t> &multiples_of, uint32_t exclusive_upper_bound)
    {
        std::set<uint32_t> multiples{};

        for (uint32_t base : multiples_of)
        {
            for (uint32_t multiple = base; multiple < exclusive_upper_bound; multiple += base)
            {
                multiples.insert(multiple);
            }
        }

        uint32_t sum = 0;
        for (uint32_t multiple : multiples)
        {
            sum += multiple;
        }

        return sum;
    }

} // namespace sum_of_multiples
