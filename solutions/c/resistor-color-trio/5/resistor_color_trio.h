#pragma once

#include <stdint.h>

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
	uint16_t value;
	enum { OHMS, KILOOHMS } unit;
} resistor_value_t;

resistor_value_t color_code(const resistor_band_t color[static 3]);
