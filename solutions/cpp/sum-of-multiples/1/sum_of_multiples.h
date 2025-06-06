#pragma once

#include <cstdint>
#include <set>

namespace sum_of_multiples
{

    uint32_t to(const std::set<uint32_t> &multiples_of, uint32_t exclusive_upper_bound);
} // namespace sum_of_multiples
