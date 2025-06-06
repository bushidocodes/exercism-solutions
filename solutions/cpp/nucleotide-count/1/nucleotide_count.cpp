#include <utility>

#include "nucleotide_count.h"

using namespace std;

namespace nucleotide_count
{

    counter::counter(string strand)
    {
        this->strand = strand;

        for (char c : strand)
        {
            switch (c)
            {
            case 'A':
            case 'C':
            case 'G':
            case 'T':
                counts.at(c)++;
                break;
            default:
                throw std::invalid_argument{""};
            }
        }
    };

    const std::map<char, int> counter::nucleotide_counts() const
    {
        return counts;
    };

    int counter::count(char c) const
    {
        switch (c)
        {
        case 'A':
        case 'C':
        case 'G':
        case 'T':
            return counts.at(c);
            break;
        default:
            throw std::invalid_argument{""};
        }
    }
} // namespace nucleotide_count
