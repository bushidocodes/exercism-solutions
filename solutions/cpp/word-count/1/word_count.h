#pragma once

#include <map>
#include <string>

namespace word_count
{
    using word_count_t = std::map<std::string, int>;

    word_count_t words(const std::string &phrase);

} // namespace word_count
