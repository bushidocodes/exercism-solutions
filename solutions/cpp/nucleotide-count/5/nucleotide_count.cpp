#include <stdexcept>
#include <utility>

#include "nucleotide_count.h"

using namespace std;

namespace nucleotide_count {

counter::counter(string_view strand) : counts{{'A', 0},{'T', 0},{'C', 0},{'G', 0}} {
    for (char nucleotide : strand) {
        validate_nucleotide(nucleotide);
        counts.at(nucleotide)++;
    }
}

auto counter::nucleotide_counts() const -> const nucleotide_counts_t&{
    return counts;
}

inline auto counter::validate_nucleotide(char nucleotide) const -> void {
    if (nucleotide != 'A' && nucleotide != 'C' && nucleotide != 'G' && nucleotide != 'T') {
        throw invalid_argument{"Character is not a valid nucleotide"};
    }
}

auto counter::count(char nucleotide) const -> int {
    validate_nucleotide(nucleotide);
    return counts.at(nucleotide);
}

} // namespace nucleotide_count
