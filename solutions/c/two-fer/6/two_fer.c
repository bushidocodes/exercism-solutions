#include "two_fer.h"
#include <assert.h>
#include <stdio.h>

#define OUT
#define IN

void two_fer (
    OUT char* result, 
    IN const char *const name
) {
    assert(result != NULL);
    
    int rc = sprintf(result, "One for %s, one for me.", name == NULL ? "you" : name);
    if (rc < 0) perror("sprintf");
}