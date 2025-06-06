#pragma once

#include <map>
#include <string_view>

namespace word_count
{
    std::map<std::string, int> words(const std::string &phrase);
} // namespace word_count
