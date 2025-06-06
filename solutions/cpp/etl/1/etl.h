#pragma once

#include <map>
#include <vector>

namespace etl
{
    using old_t = std::map<int, std::vector<char>>;
    using new_t = std::map<char, int>;

    new_t transform(const old_t &legacy_data);

} // namespace etl
