#include "raindrops.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

// TODO: Add size of result
char *convert(char result[], int drops) {
    assert(result != NULL);
    
    *result = '\0';

    int rc = 0;

    if (drops % 3 == 0) strcat(result, "Pling");
    if (drops % 5 == 0) strcat(result, "Plang");
    if (drops % 7 == 0) strcat(result, "Plong");
    if (strlen(result) == 0) rc = sprintf(result, "%d", drops);
    if (rc < 0) perror("sprintf");
        
    return result;
}
