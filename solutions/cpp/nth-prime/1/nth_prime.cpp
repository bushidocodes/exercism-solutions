#include "nth_prime.h"

#include <stdexcept>
#include <cmath>
#include <vector>

namespace nth_prime
{
    int nth(int n)
    {
        if (n < 1)
            throw std::domain_error{"Must be integer 1..n"};

        /* Start at 3, so we can increment by 2 and skip all evens */
        std::vector<int> primes = {2};
        int candidate = 3;

        while (primes.size() < static_cast<size_t>(n))
        {
            bool is_prime = true;
            for (int prime : primes)
            {
                if (candidate % prime == 0)
                {
                    is_prime = false;
                    break;
                }
            }

            if (is_prime)
                primes.push_back(candidate);

            candidate += 2;
        }

        return primes.at(n - 1);
    }

} // namespace nth_prime
