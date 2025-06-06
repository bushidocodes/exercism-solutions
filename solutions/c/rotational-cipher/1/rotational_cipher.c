#include "rotational_cipher.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char *rotate(const char *text, int shift_key){
    size_t text_size = strlen(text);
    char *result = malloc(text_size + 1);
    result[text_size] = '\0';

    char *dest = result;
    for (const char *it = text; *it; ++it, ++dest){
        if (isupper(*it)){
            *dest = 'A' + (*it - 'A' + shift_key) % 26;
        } else if (islower(*it)){
            *dest = 'a' + (*it - 'a' + shift_key) % 26;
        } else {
            *dest = *it;
        }
    }

    return result;
}