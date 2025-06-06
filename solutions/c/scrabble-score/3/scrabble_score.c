#include "scrabble_score.h"

#include <ctype.h>
#include <string.h>

#define ASCII_COUNT 26

//
// Scrabble has 100 tiles, and the game is for 2-4 players.
//
#define TILE_COUNT_PER_PLAYER 50

const uint8_t SCRABBLE_SCORE[ASCII_COUNT] = {
    1,   // A
    3,   // B
    3,   // C
    2,   // D
    1,   // E
    4,   // F
    2,   // G
    4,   // H
    1,   // I
    8,   // J
    5,   // K
    1,   // L
    3,   // M
    1,   // N
    1,   // O
    3,   // P
    10,  // Q
    1,   // R
    1,   // S
    1,   // T
    1,   // U
    4,   // V
    4,   // W
    8,   // X
    4,   // Y
    10   // Z
};

uint32_t score(const char *const word) {
	if (word == NULL) return 0;

    const size_t word_len_ = strlen(word);
    if (word_len_ > TILE_COUNT_PER_PLAYER) {
        return 0;
    }
    const uint8_t word_len = (uint8_t)word_len_;
    
	uint32_t result = 0;
	for (uint32_t i = 0; i < word_len; i++) {
		result += SCRABBLE_SCORE[toupper(word[i]) - 'A'];
    }

	return result;
}