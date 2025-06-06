#include <stdio.h>
#include <string.h>

#include "matching_brackets.h"
#define MAX_STACK 50

static char stack[MAX_STACK];
static int stack_top = -1;

bool is_paired(const char *input)
{
    bool result;
    for (unsigned int i = 0; i < strlen(input); i++)
    {
        switch (input[i])
        {
        case '[':
        case '{':
        case '(':
            stack[++stack_top] = input[i];
            break;
        case ']':
            if (stack[stack_top] != '[')
            {
                result = false;
                goto finally;
            }
            stack_top--;
            break;
        case ')':
            if (stack[stack_top] != '(')
            {
                result = false;
                goto finally;
            }
            stack_top--;
            break;
        case '}':
            if (stack[stack_top] != '{')
            {
                result = false;
                goto finally;
            }
            stack_top--;
            break;
        default:
            break;
        }
    }
    result = stack_top == -1;
finally:
    stack_top = -1;
    return result;
}