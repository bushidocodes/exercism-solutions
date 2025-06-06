#include "resistor_color_duo.h"
#include <assert.h>

int color_code(resistor_band_t color[static 2]) {
    assert(color[0] >= 0);
    assert(color[0] < RESISTOR_BAND_COUNT);
    assert(color[1] >= 0);
    assert(color[1] < RESISTOR_BAND_COUNT);
    
	return 10 * color[0] + color[1];
}
