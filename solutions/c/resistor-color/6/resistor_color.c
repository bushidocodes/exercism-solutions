#include "resistor_color.h"

resistor_band_t resistor_bands[RESISTOR_BAND_LENGTH] = {
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

uint16_t color_code(resistor_band_t color) {
    if (color >= RESISTOR_BAND_LENGTH) return -1;
    
    return color;
}

resistor_band_t *colors() {
    return resistor_bands;
}