#include "allergies.h"

#include <map>

namespace allergies
{
    /* 
     * Note: This could be potentially DRYed up via Boost Bimap, which allows
     * bidirectional use. However, I found the API a bit more challenging than
     * my patience allowed at the time of working on this!
     * https://www.boost.org/doc/libs/1_73_0/libs/bimap/doc/html/
     */
    const std::map<std::string, std::uint32_t> allergy_to_bitflag = {
        {"eggs", 0},
        {"peanuts", 1},
        {"shellfish", 2},
        {"strawberries", 3},
        {"tomatoes", 4},
        {"chocolate", 5},
        {"pollen", 6},
        {"cats", 7}};

    const std::map<std::uint32_t, std::string> bitflag_to_allergy = {
        {0, "eggs"},
        {1, "peanuts"},
        {2, "shellfish"},
        {3, "strawberries"},
        {4, "tomatoes"},
        {5, "chocolate"},
        {6, "pollen"},
        {7, "cats"}};

    allergy_test::allergy_test(std::uint32_t score)
    {
        allergies = score;
    }

    bool allergy_test::is_allergic_to(const std::string &allergy)
    {
        return allergies[allergy_to_bitflag.at(allergy)];
    }

    std::unordered_set<std::string> allergy_test::get_allergies()
    {
        std::unordered_set<std::string> allergies_set{};

        for (std::uint32_t i = 0; i < bitflag_to_allergy.size(); i++)
        {
            if (allergies[i])
            {
                allergies_set.insert(bitflag_to_allergy.at(i));
            }
        }

        return allergies_set;
    };

} // namespace allergies
