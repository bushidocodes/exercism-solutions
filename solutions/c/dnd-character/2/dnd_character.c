#include "dnd_character.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int ability(void){
    static bool didSeed = false;
    if (!didSeed){
        srand(time(NULL));
        didSeed = true;
    }
    
    char rolls[4] = {
        (rand() % 6) + 1,
        (rand() % 6) + 1,
        (rand() % 6) + 1,
        (rand() % 6) + 1,
    };

    int sum = 0, min_value = 7;
    for (int i = 0; i < 4; ++i){
        sum += rolls[i];
        if (rolls[i] < min_value){
            min_value = rolls[i];
        }
    }

    return sum - min_value;
}

int modifier(int score){
    return (score / 2) - 5;
}

dnd_character_t make_dnd_character(void){
    dnd_character_t result = (dnd_character_t){
        .strength = ability(),
        .dexterity = ability(),
        .constitution = ability(),
        .intelligence = ability(),
        .wisdom = ability(),
        .charisma = ability(),
        .hitpoints = 0
    };
    result.hitpoints = 10 + modifier(result.constitution);
    return result;
}