#include "raindrops.h"
#include <string.h>
#include <stdio.h>

char *convert(char result[], int drops)
{
    strncpy(result, "", 1);

    if (drops % 3 == 0)
        strcat(result, "Pling");

    if (drops % 5 == 0)
        strcat(result, "Plang");

    if (drops % 7 == 0)
        strcat(result, "Plong");

    if (strlen(result) == 0)
        sprintf(result, "%d", drops);

    return result;
}
