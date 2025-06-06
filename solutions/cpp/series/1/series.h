#pragma once

#include <string>
#include <vector>

namespace series
{
    std::vector<int> digits(std::string number_string);
    std::vector<std::vector<int>> slice(std::string number_string, size_t slice_size);

} // namespace series
