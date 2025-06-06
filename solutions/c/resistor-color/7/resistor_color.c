#include "resistor_color.h"
#include <assert.h>

//
// Derived state. I don't understand the rationale for this specific
// representation, but a similar pattern that does make sense to me
// is an array of strings indexed by the value of the enums. That
// could be used to provide a reverse lookup that would enable
// color_code to take a const char* in place of a register_band_t
//
// Note: I've made this static in order to help justify the reason
// for colors() existing (it's a getter!)
//
static const resistor_band_t resistor_bands[RESISTOR_BAND_LENGTH] = {
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

//
// Dumb wrapper around resistor_band_t that asserts color is valid
//
uint16_t color_code(resistor_band_t color) {
    assert(color >= 0);
    assert(color < RESISTOR_BAND_LENGTH);
    return color;
}

//
// Effectively a getter for resistor_bands. I've modified this to
// point to a const array. I've also modified 
//
const resistor_band_t* colors() {
    return resistor_bands;
}