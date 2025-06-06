#include "two_fer.h"
#include <string.h>

void two_fer(char *buffer, const char *name)
{
    strcpy(buffer, "One for ");
    strcat(buffer, name == NULL ? "you" : name);
    strcat(buffer, ", one for me.");
}