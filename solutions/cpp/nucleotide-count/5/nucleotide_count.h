#pragma once

#include <map>
#include <string_view>

namespace nucleotide_count {

using nucleotide_counts_t = std::map<char, int>;

class counter {
public:
    counter(std::string_view strand);
    auto nucleotide_counts() const -> const nucleotide_counts_t&;
    auto count(char nucleotide) const -> int;

private:
    auto validate_nucleotide(char nucleotide) const -> void;
    nucleotide_counts_t counts;
};

} // namespace nucleotide_count
