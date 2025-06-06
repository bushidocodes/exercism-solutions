#include <ctype.h>
#include <stddef.h>
#include <stdint.h>

#include "isogram.h"

bool is_isogram(const char phrase[]) {
    if (phrase == NULL) return false;

    // Use bits to indicate if char was found
    uint32_t letters = 0;
    
    for (char *c = (char *)phrase; *c != '\0'; c++) {
        if (isalpha(*c)) {
            uint32_t mask = 1 << (toupper(*c) - 'A');
            if ((letters & mask) == mask)
                return false;
            letters |= mask;
        }
    }

    return true;
}
