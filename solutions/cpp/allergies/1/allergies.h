#pragma once

#include <bitset>
#include <cstdint>
#include <unordered_set>

namespace allergies
{

    class allergy_test
    {
    private:
        std::bitset<32> allergies;

    public:
        allergy_test(std::uint32_t score);
        bool is_allergic_to(const std::string &allergy);
        std::unordered_set<std::string> get_allergies();
    };

} // namespace allergies
