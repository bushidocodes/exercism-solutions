#include "yacht.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static void count_face_values(const dice_t *const restrict dice, int (*const restrict result)[7]) {
    memset(*result, 0, 7 * sizeof(int));

    for (int i = 0; i < 5; ++i){
        assert(1 <= dice->faces[i] && dice->faces[i] <= 6);
        ++(*result)[dice->faces[i]]; 
    }
}

static int sum(const dice_t *const dice) {
    int result = 0;
    for (int i = 0; i < 5; ++i) result += dice->faces[i]; 
    return result;
}

int score(const dice_t dice, const category_t category) {
    int face_count[7] = {0};
    count_face_values(&dice, &face_count);
    
    switch (category) {
        case ONES: return face_count[1] * 1;
        case TWOS: return face_count[2] * 2;
        case THREES: return face_count[3] * 3;
        case FOURS: return face_count[4] * 4;
        case FIVES: return face_count[5] * 5;
        case SIXES: return face_count[6] * 6;
        case FULL_HOUSE:{
            bool has_2 = false;
            bool has_3 = false;
            for (int i = 1; i <= 6; ++i){
                if (face_count[i] == 3) has_3 = true;
                else if (face_count[i] == 2) has_2 = true;
            }

            if (!has_3 || !has_2) return 0;

            return sum(&dice);
        }
        case FOUR_OF_A_KIND: {
            for (int i = 1; i <= 6; ++i){
                if (face_count[i] >= 4) return 4 * i;
            }
            
            return 0;
        }
        case LITTLE_STRAIGHT: {
            bool is_straight = true;
            for (int i = 1; i <= 5; ++i){
                if (face_count[i] != 1) {
                    is_straight = false;
                    break;
                }
            }

            return is_straight ? 30 : 0;
        }
        case BIG_STRAIGHT: {
            bool is_straight = true;
            for (int i = 2; i <= 6; ++i){
                if (face_count[i] != 1) {
                    is_straight = false;
                    break;
                }
            }

            return is_straight ? 30 : 0;
        }
        case CHOICE: return sum(&dice);
        case YACHT: {
            for (int i = 1; i <= 6; ++i) {
                if (face_count[i] == 5) return 50;
            }
            
            return 0;
        }
    }
    assert(false);
}