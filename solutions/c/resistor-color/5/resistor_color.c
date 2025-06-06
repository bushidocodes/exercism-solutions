#include "resistor_color.h"
#include "stdlib.h"
#include "stdio.h"

resistor_band_t resistor_bands[] = {
    BLACK,
    BROWN,
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    GREY,
    WHITE
};

int color_code(resistor_band_t color) {
    if (color >= RESISTOR_BAND_LENGTH) return -1;
    
    return color;
}

resistor_band_t *colors() {
    return resistor_bands;
}