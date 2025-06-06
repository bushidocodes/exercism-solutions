#include <stdexcept>
#include <utility>

#include "nucleotide_count.h"

namespace nucleotide_count
{

    void counter::validate_nucleotide(char nucleotide) const
    {
        if (nucleotide != 'A' && nucleotide != 'C' && nucleotide != 'G' && nucleotide != 'T')
        {
            throw std::invalid_argument{"Character is not a valid nucleotide"};
        };
    }

    counter::counter(const std::string &strand)
    {
        for (char nucleotide : strand)
        {
            validate_nucleotide(nucleotide);

            counts.at(nucleotide)++;
        }
    };

    const std::map<char, int> &counter::nucleotide_counts() const noexcept
    {
        return counts;
    };

    int counter::count(char nucleotide) const
    {
        validate_nucleotide(nucleotide);

        return counts.at(nucleotide);
    }
} // namespace nucleotide_count
