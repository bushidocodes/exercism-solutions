#include "allergies.h"

#include <stdio.h>

bool is_allergic_to(allergen_t allergen, int score) {
	return ((1 << allergen) & score) > 0;
}

allergen_list_t get_allergens(int score) {
	allergen_list_t results;
	results.count = 0;

	for (allergen_t allergen = ALLERGEN_EGGS; allergen < ALLERGEN_COUNT;
	     allergen++) {
		if (is_allergic_to(allergen, score)) {
			results.allergens[allergen] = true;
			results.count++;
		} else
			results.allergens[allergen] = false;
	}

	return results;
}