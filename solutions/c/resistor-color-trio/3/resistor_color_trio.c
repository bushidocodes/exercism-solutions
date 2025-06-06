#include "resistor_color_trio.h"

#include <assert.h>
#include <limits.h>
#include <math.h>

resistor_value_t color_code(resistor_band_t color[]) {
	resistor_value_t result;

	unsigned int buffer = 0;
	buffer += color[0] * 10;
	buffer += color[1];
	buffer *= pow(10, color[2]);

	if (buffer > 1000) {
		assert(buffer / 1000 <= USHRT_MAX);
		result.value = (unsigned short)(buffer / 1000);
		result.unit = KILOOHMS;
	} else {
		assert(buffer <= USHRT_MAX);
		result.value = (unsigned short)(buffer);
		result.unit = OHMS;
	}

	return result;
}