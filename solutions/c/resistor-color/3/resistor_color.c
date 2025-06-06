#include "resistor_color.h"
#include "stdlib.h"
#include "stdio.h"

int color_code(resistor_band_t color) {
    return color;
}

resistor_band_t *colors() {
    resistor_band_t *resistor_bands = calloc(RESISTOR_BAND_LENGTH, sizeof(resistor_band_t));
    if (resistor_bands == NULL) {
        perror("calloc");
        return NULL;
    }
    
    resistor_bands[0] = BLACK;
    resistor_bands[1] = BROWN;
    resistor_bands[2] = RED;
    resistor_bands[3] = ORANGE;
    resistor_bands[4] = YELLOW;
    resistor_bands[5] = GREEN;
    resistor_bands[6] = BLUE;
    resistor_bands[7] = VIOLET;
    resistor_bands[8] = GREY;
    resistor_bands[9] = WHITE;
    return resistor_bands;
}