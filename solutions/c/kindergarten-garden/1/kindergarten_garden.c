#include "kindergarten_garden.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

static const char *students[] = {"Alice",  "Bob",    "Charlie", "David",
                                 "Eve",    "Fred",   "Ginny",   "Harriet",
                                 "Ileana", "Joseph", "Kincaid", "Larry"};

enum { num_students = sizeof(students) / sizeof(students[0]) };

static plant_t plant_from_char(char c) {
  switch (c) {
  case 'C':
    return CLOVER;
  case 'G':
    return GRASS;
  case 'R':
    return RADISHES;
  case 'V':
    return VIOLETS;
  default:
    return INVALID_PLANT;
  }
}

plants_t plants(const char *diagram, const char *student) {
  assert(diagram != NULL);
  assert(student != NULL);
  plants_t result = {
      .plants = {INVALID_PLANT, INVALID_PLANT, INVALID_PLANT, INVALID_PLANT}};

  // Parse strings into Matrix
  char matrix[2][2 * num_students];
  memset(matrix, 0, sizeof(matrix));
  size_t first_idx = 0;
  size_t second_idx = 0;
  size_t diagram_len = strlen(diagram);
  for (size_t i = 0; i < diagram_len; ++i) {
    if (diagram[i] == '\n') {
      second_idx = 0;
      ++first_idx;
    } else {
      matrix[first_idx][second_idx] = diagram[i];
      ++second_idx;
    }
  }

  // Lookup student index
  int student_index = -1;
  for (size_t i = 0; i < num_students; ++i) {
    if (strcmp(students[i], student) == 0) {
      student_index = i;
      break;
    }
  }
  if (student_index == -1) {
    return result;
  }

  // Calculate the coordinates of the student's plots in the grid
  // Using the student_index
  const int start = student_index * 2;
  int plants_idx = 0;
  for (int row = 0; row < 2; ++row) {
    for (int col = 0; col < 2; ++col) {
      result.plants[plants_idx++] = plant_from_char(matrix[row][start + col]);
    }
  }

  return result;
}
