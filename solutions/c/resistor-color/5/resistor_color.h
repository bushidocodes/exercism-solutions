#pragma once

typedef enum resistor_band_t {
    BLACK,
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

int color_code(resistor_band_t color);

resistor_band_t *colors();
