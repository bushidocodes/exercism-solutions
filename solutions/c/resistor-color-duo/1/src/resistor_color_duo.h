#ifndef RESISTOR_COLOR_DUO_H
#define RESISTOR_COLOR_DUO_H

typedef enum resistor_band_t
{
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
} resistor_band_t;

int single_color_code(resistor_band_t color);
int color_code(resistor_band_t color[]);

#endif
