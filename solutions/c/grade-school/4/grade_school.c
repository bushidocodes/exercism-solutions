#include "grade_school.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

void init_roster(roster_t *roster)
{
    roster->count = 0;
    memset(roster->students, 0, MAX_STUDENTS * sizeof(student_t));
}

bool add_student(roster_t *roster, char *name, uint8_t grade)
{
    assert(roster != NULL);
    assert(name != NULL);

    if (roster->count == MAX_STUDENTS)
        return false;

    // Names must be unique
    for (size_t i = 0; i < roster->count; i++)
    {
        assert(roster->students[i].name != NULL);
        if (strcmp(name, roster->students[i].name) == 0)
            return false;
    }

    size_t i = 0;
    for (; i < roster->count; i++)
    {
        student_t student = roster->students[i];
        if (student.grade > grade)
            break;
        if (student.grade == grade && strcmp(student.name, name) > 0)
            break;
    }

    // Move Students if we didn't iterate to end
    if (i != roster->count)
        memmove(&roster->students[i + 1], &roster->students[i], sizeof(student_t) * (roster->count - i));

    // Insert
    roster->students[i].name = name;
    roster->students[i].grade = grade;
    roster->count++;

    return true;
}

roster_t
get_grade(roster_t *roster, uint8_t grade)
{
    roster_t grade_roster;
    init_roster(&grade_roster);

    for (size_t i = 0; i < roster->count; i++)
    {
        if (roster->students[i].grade == grade)
            add_student(&grade_roster, roster->students[i].name, roster->students[i].grade);
    }

    return grade_roster;
}
