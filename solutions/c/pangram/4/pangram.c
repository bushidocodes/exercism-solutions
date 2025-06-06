#include <ctype.h>
#include <stdint.h>
#include <string.h>
#include "pangram.h"

#define LETTER_OFFSET ((size_t)'A')

bool is_pangram(const char *const sentence)
{
    if (!sentence) return false;

    // bitset for 26 chars
    uint32_t letter_bitset = 0;
    size_t sentence_len = strlen(sentence);

    for (size_t i = 0; i < sentence_len; i++) {
        if (isalpha(sentence[i])) {
            letter_bitset |= (1 << (toupper(sentence[i]) - LETTER_OFFSET));
        }
    }

    // 0b00000011111111111111111111111111;
    return letter_bitset == 0x3FFFFFF;
}