#include "grade_school.h"
#include <string.h>
#include <stdio.h>

static roster_t roster = {0};

roster_t get_roster()
{
    return roster;
}

bool add_student(char *name, uint8_t grade)
{
    if (roster.count >= MAX_STUDENTS)
        return false;

    size_t index_to_insert = 0;

    if (roster.count > 0)
    {

        // Figure out index where we want to store
        while (index_to_insert < roster.count && (grade > roster.students[index_to_insert].grade                                                                    // if in a higher grade
                                                  || (grade == roster.students[index_to_insert].grade && strcmp(name, roster.students[index_to_insert].name) > 0))) // or in the same grade with a later name in the alphabet
            index_to_insert++;

        // Shift existing values up
        for (size_t i = roster.count; i != 0 && i >= index_to_insert; i--)
            memcpy(&roster.students[i], &roster.students[i - 1], sizeof(student_t));
    }

    // Overwrite target value
    roster.students[index_to_insert] = (student_t){
        .name = name,
        .grade = grade};
    roster.count++;

    return true;
}

roster_t
get_grade(int grade_level)
{
    roster_t grade = {0};
    grade.count = 0;
    for (size_t i = 0; i < roster.count; i++)
    {
        if (roster.students[i].grade == grade_level)
            memcpy(&grade.students[grade.count++], &roster.students[i], sizeof(student_t));
    }
    return grade;
}

void clear_roster()
{
    roster = (roster_t){0};
}