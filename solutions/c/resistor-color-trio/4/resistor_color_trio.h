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
	WHITE
} resistor_band_t;

typedef struct {
	unsigned short value;
	enum { OHMS, KILOOHMS } unit;
} resistor_value_t;

resistor_value_t color_code(resistor_band_t color[]);
