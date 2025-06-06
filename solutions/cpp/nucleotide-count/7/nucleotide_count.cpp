#include <numeric>
#include <stdexcept>
#include "nucleotide_count.h"

using namespace std;

namespace nucleotide_count {

auto count (string_view strand) -> map<char, int> {
    return accumulate(begin(strand), end(strand), map<char, int>{{'A', 0},{'T', 0},{'C', 0},{'G', 0}}, 
        [](auto &acc, char n){
            if (n != 'A' && n != 'C' && n != 'G' && n != 'T') {
                throw invalid_argument{"Character is not a valid nucleotide"};
            }
            acc.at(n)++;
            return acc;
        }
    );
}
} // namespace nucleotide_count
