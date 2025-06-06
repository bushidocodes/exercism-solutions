#include "two_fer.h"
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE (100)

void two_fer(char *buffer, const char *name)
{
    sprintf(buffer, "One for %s, one for me.", name == NULL ? "you" : name);
}