#include "roman_numerals.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct numeral {
	char *roman;
	unsigned int arabic;
};

char *to_roman_numeral(unsigned int number) {
	unsigned int remaining = number;
	char buffer[100];
	strcpy((char *)&buffer, "");

	struct numeral numerals[] = {
	    {.roman = "M", .arabic = 1000}, {.roman = "CM", .arabic = 900},
	    {.roman = "D", .arabic = 500},  {.roman = "CD", .arabic = 400},
	    {.roman = "C", .arabic = 100},  {.roman = "XC", .arabic = 90},
	    {.roman = "L", .arabic = 50},   {.roman = "XL", .arabic = 40},
	    {.roman = "X", .arabic = 10},   {.roman = "IX", .arabic = 9},
	    {.roman = "V", .arabic = 5},    {.roman = "IV", .arabic = 4},
	    {.roman = "I", .arabic = 1},
	};

	unsigned int numeral_count = sizeof(numerals) / sizeof(numerals[0]);

	for (unsigned int i = 0; i < numeral_count; i++) {
		while (remaining >= numerals[i].arabic) {
			strcat((char *)&buffer, numerals[i].roman);
			remaining -= numerals[i].arabic;
		}
	}

	char *result = malloc(sizeof(char) * strlen((char *)&buffer) + 1);
	strcpy(result, (char *)&buffer);
	return result;
}