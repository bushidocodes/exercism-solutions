#include "grains.h"

uint64_t square(uint8_t idx) {
    if (idx < 1 || idx > 64) 
        return 0;
    
    return (uint64_t)1 << (idx - 1);
}

uint64_t total(void) {
    return UINT64_MAX;
}