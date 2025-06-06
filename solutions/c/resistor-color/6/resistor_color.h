#pragma once

#include <stdint.h>

typedef enum resistor_band_t {
    BLACK = 0,
    BROWN,
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    GREY,
    WHITE,
    RESISTOR_BAND_LENGTH
} resistor_band_t;

uint16_t color_code(resistor_band_t color);

resistor_band_t *colors();
