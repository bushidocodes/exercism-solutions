#pragma once

#include <stddef.h>

char **annotate(const char **minefield, const size_t rows);
void free_annotation(char **annotation);
