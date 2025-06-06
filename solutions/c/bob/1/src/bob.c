#include "bob.h"
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

char *hey_bob(char *greeting)
{
    bool has_lower = false;
    bool has_alpha = false;
    bool has_alphanumeric = false;
    for (size_t i = 0; i < strlen(greeting); i++)
    {
        if (isalpha(greeting[i]))
            has_alpha = true;
        if (isalnum(greeting[i]))
            has_alphanumeric = true;
        if (islower(greeting[i]))
            has_lower = true;
    }
    bool is_shouting = has_alpha && !has_lower;
    bool is_silence = has_alphanumeric == false;

    // advance backwards to first non-whitespace
    size_t i;
    for (i = strlen(greeting) - 1; isblank(greeting[i]); i--)
        ;
    bool is_question = greeting[i] == '?';

    if (is_shouting && is_question)
        return "Calm down, I know what I'm doing!";
    else if (is_question)
        return "Sure.";
    else if (is_shouting)
        return "Whoa, chill out!";
    else if (is_silence)
        return "Fine. Be that way!";
    else
        return "Whatever.";
}