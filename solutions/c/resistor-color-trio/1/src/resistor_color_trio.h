#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H

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

typedef enum resistor_unit_t
{
    OHMS,
    KILOOHMS
} resistor_unit_t;

typedef struct
{
    unsigned short value;
    resistor_unit_t unit;
} resistor_value_t;

resistor_value_t color_code(resistor_band_t color[]);

#endif
