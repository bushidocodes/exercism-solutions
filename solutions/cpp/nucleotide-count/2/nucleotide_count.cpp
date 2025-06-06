#include <stdexcept>
#include <utility>

#include "nucleotide_count.h"

namespace nucleotide_count
{

    bool counter::validate_nucleotide(char nucleotide) const
    {
        return nucleotide == 'A' || nucleotide == 'C' || nucleotide == 'G' || nucleotide == 'T';
    }

    counter::counter(const std::string &strand)
    {
        for (char nucleotide : strand)
        {
            if (validate_nucleotide(nucleotide) == false)
            {
                throw std::invalid_argument{"Character is not a valid nucleotide"};
            }

            counts.at(nucleotide)++;
        }
    };

    const std::map<char, int> &counter::nucleotide_counts() const
    {
        return counts;
    };

    int counter::count(char nucleotide) const
    {
        if (validate_nucleotide(nucleotide) == false)
        {
            throw std::invalid_argument{"Character is not a valid nucleotide"};
        }

        return counts.at(nucleotide);
    }
} // namespace nucleotide_count
