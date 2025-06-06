#include "sieve.h"

#include <boost/iterator/counting_iterator.hpp>
#include <set>

namespace sieve
{
    std::vector<int> primes(int to)
    {

        std::vector<int> primes{};

        if (to < 2)
            return primes;

        std::set<int> candidates{};
        candidates.insert(boost::counting_iterator<int>(2),
                          boost::counting_iterator<int>(to + 1));

        for (int candidate : candidates)
        {
            /* Remove all multiples */
            for (int i = 2; i * candidate <= to; i++)
            {
                candidates.erase(i * candidate);
            }
        }

        for (int candidate : candidates)
        {
            primes.push_back(candidate);
        }

        return primes;
    }

} // namespace sieve
