#include "allergies.h"
#include <map>

static_assert(__cplusplus >= 201703);
// C++20: std::adjacent_difference
using namespace std;

namespace allergies {
/*
 * Note: This could be potentially DRYed up via Boost Bimap, which allows
 * bidirectional use. However, I found the API a bit more challenging than
 * my patience allowed at the time of working on this!
 * https://www.boost.org/doc/libs/1_73_0/libs/bimap/doc/html/
 */
const map<string, uint32_t> allergy_to_bitflag = {
    {"eggs", 0},     {"peanuts", 1},   {"shellfish", 2}, {"strawberries", 3},
    {"tomatoes", 4}, {"chocolate", 5}, {"pollen", 6},    {"cats", 7}};

const array<string, 8> bitflag_to_allergy = {"eggs", "peanuts", "shellfish", "strawberries", "tomatoes", "chocolate", "pollen", "cats"};

allergy_test::allergy_test(uint32_t score) :allergies{score} {}

auto allergy_test::is_allergic_to(const string &allergy) -> bool {
	return allergies[allergy_to_bitflag.at(allergy)];
}

auto allergy_test::get_allergies() -> unordered_set<string> {
	unordered_set<string> allergies_set{};

	for (uint32_t i = 0; i < bitflag_to_allergy.size(); i++) {
		if (allergies[i]) {
			allergies_set.insert(bitflag_to_allergy.at(i));
		}
	}

	return allergies_set;
}

}  // namespace allergies
