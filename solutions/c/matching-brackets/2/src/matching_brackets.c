#include <stdio.h>
#include <string.h>

#include "matching_brackets.h"
#define MAX_STACK 50

bool is_paired(const char *input)
{
    if (input == NULL)
        return false;

    // Simple Stack. If top is -1, stack is empty
    char stack[MAX_STACK];
    int stack_top = -1;

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
                return false;
            }
            stack_top--;
            break;
        case ')':
            if (stack[stack_top] != '(')
            {
                return false;
            }
            stack_top--;
            break;
        case '}':
            if (stack[stack_top] != '{')
            {
                return false;
            }
            stack_top--;
            break;
        default:
            break;
        }
    }
    return stack_top == -1;
}