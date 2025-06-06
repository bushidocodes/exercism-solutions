
#include "grade_school.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

void init_roster(roster_t* roster) {
	roster->count = 0;
	memset(&roster->students, 0, sizeof(student_t));
}

bool add_student(roster_t* roster, char* name, uint8_t grade) {
	if (roster->count >= MAX_STUDENTS) return false;

	// Cannot add a student if a student with the same name is in any grade
	for (size_t i = 0; i < roster->count; i++) {
		if (strcmp(name, roster->students[i].name) == 0) {
			return false;
		}
	}

	// Find Index to insert at
	size_t i = 0;
	for (; i < roster->count; i++) {
		student_t student = roster->students[i];
		if (student.grade > grade) break;
		if (student.grade == grade &&
		    strncmp(name, student.name, MAX_NAME_LENGTH) < 0)
			break;
	}

	// Shift Students Right
	if (roster->count - i > 0) {
		memmove(&roster->students[i + 1], &roster->students[i],
		        sizeof(student_t) * (roster->count - i));
	}

	// Overwrite
	strncpy(roster->students[i].name, name, MAX_NAME_LENGTH);
	roster->students[i].grade = grade;
	roster->count++;

	return true;
}

roster_t get_grade(roster_t* roster, uint8_t grade_level) {
	roster_t grade = {0};
	init_roster(&grade);

	for (size_t i = 0; i < roster->count; i++) {
		if (roster->students[i].grade == grade_level)
			memcpy(&grade.students[grade.count++], &roster->students[i],
			       sizeof(student_t));
	}

	return grade;
}
