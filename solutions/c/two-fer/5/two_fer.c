#include "two_fer.h"
#include <assert.h>
#include <stdio.h>

// TODO: This API should be changed to pass the size of buffer
void two_fer(char *buffer, const char *name) {
    assert(buffer != NULL);
    
    int rc = sprintf(buffer, "One for %s, one for me.", name == NULL ? "you" : name);
    if (rc < 0) perror("sprintf");
}