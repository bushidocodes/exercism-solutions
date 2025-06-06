#pragma once

#include <string_view>

namespace hamming
{
    uint32_t compute(std::string_view first, std::string_view second);
} // namespace hamming
