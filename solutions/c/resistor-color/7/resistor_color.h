#pragma once

#include <stdint.h>

//
// For C23, we can consider setting backing data type to uint16_t
//
typedef enum _resistor_band_t {
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

const resistor_band_t* colors();
