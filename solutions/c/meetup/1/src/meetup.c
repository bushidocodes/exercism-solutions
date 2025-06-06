#include "meetup.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

enum Day
{
    Sunday = 0,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

enum Month
{
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December,
};

uint_fast8_t
get_day_of_week(uint_fast8_t d, uint_fast8_t m, uint_fast16_t y);

uint_fast8_t get_days_in_month(uint_fast16_t year, enum Month month);
bool is_leap_year(uint_fast16_t year);
enum Day parse_day(const char *source);

enum Day parse_day(const char *source)
{
    if (strcmp(source, "Sunday") == 0)
        return Sunday;
    else if (strcmp(source, "Monday") == 0)
        return Monday;
    else if (strcmp(source, "Tuesday") == 0)
        return Tuesday;
    else if (strcmp(source, "Wednesday") == 0)
        return Wednesday;
    else if (strcmp(source, "Thursday") == 0)
        return Thursday;
    else if (strcmp(source, "Friday") == 0)
        return Friday;
    else if (strcmp(source, "Saturday") == 0)
        return Saturday;

    return 0;
}

bool is_leap_year(uint_fast16_t year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

uint_fast8_t get_days_in_month(uint_fast16_t year, enum Month month)
{
    switch (month)
    {
    case January:
        return 31;
    case February:
        return is_leap_year(year) ? 29 : 28;
    case March:
        return 31;
    case April:
        return 30;
    case May:
        return 31;
    case June:
        return 30;
    case July:
        return 31;
    case August:
        return 31;
    case September:
        return 30;
    case October:
        return 31;
    case November:
        return 30;
    case December:
        return 31;
    default:
        fprintf(stderr, "Unexpectedly did not match known varients in get_days_in_month. Exiting\n");
        exit(EXIT_FAILURE);
    }
}

// From https://www.geeksforgeeks.org/find-day-of-the-week-for-a-given-date/
uint_fast8_t
get_day_of_week(uint_fast8_t d, uint_fast8_t m, uint_fast16_t y)
{
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}

int meetup_day_of_month(unsigned int year, unsigned int month, const char *week,
                        const char *day_of_week)
{
    int days_in_month = get_days_in_month(year, month);
    // Idea: Translate the week descriptor into a base day
    int base_date;
    if (strcmp(week, "teenth") == 0)
    {
        base_date = 13;
    }
    else if (strcmp(week, "first") == 0)
    {
        base_date = 1;
    }
    else if (strcmp(week, "second") == 0)
    {
        base_date = 8;
    }
    else if (strcmp(week, "third") == 0)
    {
        base_date = 15;
    }
    else if (strcmp(week, "fourth") == 0)
    {
        base_date = 22;
    }
    else if (strcmp(week, "fifth") == 0)
    {
        base_date = 29;
    }
    else if (strcmp(week, "last") == 0)
    {
        // TODO: This needs to know the length of the month
        base_date = days_in_month - 6;
    }
    else
    {
        return 0;
    }
    // Use the string descriptor to figure out a sane base date
    enum Day base_day = get_day_of_week(base_date, month, year);

    // Determine the offset and adjust
    enum Day target_day = parse_day(day_of_week);
    int result = base_date;
    if (base_day > target_day)
    {
        // If the base day is later in the week, we need to rotate around to the next week
        result = base_date + ((7 - base_day) + target_day);
    }
    else
    {
        result = base_date + (target_day - base_day);
    }

    // We need to validate that the date actually exists in this month. If it doesn't return 0 to indicate error.
    return result <= days_in_month ? result : 0;
}