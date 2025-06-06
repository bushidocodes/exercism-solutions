#include "resistor_color_duo.h"

#include "stdio.h"
#include "stdlib.h"

int single_color_code(resistor_band_t color) {
	switch (color) {
		case BLACK:
			return 0;
		case BROWN:
			return 1;
		case RED:
			return 2;
		case ORANGE:
			return 3;
		case YELLOW:
			return 4;
		case GREEN:
			return 5;
		case BLUE:
			return 6;
		case VIOLET:
			return 7;
		case GREY:
			return 8;
		case WHITE:
			return 9;
		default:
			printf("Err!\n");
			return 0;
	}
}

int color_code(resistor_band_t color[]) {
	int result = 0;
	result += single_color_code(color[0]) * 10;
	result += single_color_code(color[1]);
	return result;
}
