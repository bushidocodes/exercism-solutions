#include "resistor_color_trio.h"

#include <assert.h>
#include <limits.h>
#include <math.h>

resistor_value_t color_code(resistor_band_t color[]) {
	unsigned int ohms =  (color[0] * 10 + color[1]) * pow(10, color[2]);

	if (ohms > 1000) {
		assert(ohms / 1000 <= USHRT_MAX);
        return (resistor_value_t){
    		.value = (unsigned short)(ohms / 1000),
		    .unit = KILOOHMS
        };
	} else {
		assert(ohms <= USHRT_MAX);
        return (resistor_value_t){
    		.value = (unsigned short)(ohms),
		    .unit = OHMS
        };
	}
}