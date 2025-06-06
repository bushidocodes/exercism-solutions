#pragma once

#include <map>
#include <string_view>

namespace nucleotide_count {

auto count(std::string_view) -> std::map<char, int>;

} // namespace nucleotide_count
