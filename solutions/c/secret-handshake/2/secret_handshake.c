#include "secret_handshake.h"
#include <assert.h>
#include <stdlib.h>

#define HANDSHAKE_CAPACITY 4

const char **commands(size_t number) {
    const char **handshake = calloc(HANDSHAKE_CAPACITY, sizeof(char *));
    size_t handshake_length = 0;

    if ((number & 16) == 16) {
        if ((number & 8) == 8) handshake[handshake_length++] = "jump";
        if ((number & 4) == 4) handshake[handshake_length++] = "close your eyes";
        if ((number & 2) == 2) handshake[handshake_length++] = "double blink";
        if ((number & 1) == 1) handshake[handshake_length++] = "wink";
    } else {
        if ((number & 1) == 1) handshake[handshake_length++] = "wink";
        if ((number & 2) == 2) handshake[handshake_length++] = "double blink";
        if ((number & 4) == 4) handshake[handshake_length++] = "close your eyes";
        if ((number & 8) == 8) handshake[handshake_length++] = "jump";
    }
    assert(handshake_length <= HANDSHAKE_CAPACITY);

    return handshake;
}