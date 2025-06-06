#include <stdexcept>
#include "nucleotide_count.h"

using namespace std;

namespace nucleotide_count {

auto count (string_view strand) -> map<char, int> {
    map<char, int> counts{{'A', 0},{'T', 0},{'C', 0},{'G', 0}};
    
    for (char nucleotide : strand) {
        if (nucleotide != 'A' && nucleotide != 'C' && nucleotide != 'G' && nucleotide != 'T') {
            throw invalid_argument{"Character is not a valid nucleotide"};
        }
        counts.at(nucleotide)++;
    }

    return counts;
}

} // namespace nucleotide_count
