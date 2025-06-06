#include "prime_factors.h"

namespace prime_factors
{
    std::vector<int> of(int number)
    {
        std::vector<int> result = {};

        for (int i = 2; i <= number; i++)
        {
            while (number % i == 0)
            {
                result.push_back(i);
                number /= i;
            }
        }

        return result;
    }

} // namespace prime_factors
