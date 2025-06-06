#include "luhn.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int ASCII_NUM_OFFSET = 48;

bool luhn(const char *num)
{
    size_t len = strlen(num);
    int digit_count = 0, sum = 0;
    for (size_t i = 1; i <= len; i++)
    {
        if (num[len - i] == ' ')
            continue;
        else if (!isdigit(num[len - i]))
            return false;
        else
        {
            digit_count++;
            int digit = num[len - i] - ASCII_NUM_OFFSET;
            if (digit_count % 2 == 0)
            {
                digit *= 2;
                if (digit > 9)
                    digit -= 9;
            }
            sum += digit;
        }
    }

    if (digit_count < 2)
        return false;

    return sum % 10 == 0;
}