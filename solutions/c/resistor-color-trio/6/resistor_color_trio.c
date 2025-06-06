#include "resistor_color_trio.h"

#include <assert.h>

static uint32_t ipow(uint32_t base, uint32_t exponent) {
    uint32_t product = 1;
    for (uint32_t i = 0; i < exponent; ++i) {
        assert( ((uint64_t)(product) * base) <= UINT32_MAX);
        product *= base;
    }
    return product;
}

resistor_value_t color_code(const resistor_band_t color[static 3]) {
	uint64_t ohms =  (uint64_t)(color[0] * 10 + color[1]) * ipow(10, color[2]);

    if (ohms > 1000000000) {
        return (resistor_value_t){
    		.value = (uint16_t)(ohms / 1000000000),
		    .unit = GIGAOHMS
        };
    } else if (ohms > 1000000) {
        return (resistor_value_t){
    		.value = (uint16_t)(ohms / 1000000),
		    .unit = MEGAOHMS
        };
	} else if (ohms > 1000) {
        return (resistor_value_t){
    		.value = (uint16_t)(ohms / 1000),
		    .unit = KILOOHMS
        };
	} else {
        return (resistor_value_t){
    		.value = (uint16_t)(ohms),
		    .unit = OHMS
        };
	}
}
