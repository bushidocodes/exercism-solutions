#include "matching_brackets.h"

#include <assert.h>

#define MAX_STACK 50
#define STACK_EMPTY -1

bool is_paired(const char *input) {
	// Simple Stack. If top is -1, stack is empty
	char stack[MAX_STACK];
	int stack_top = STACK_EMPTY;

	for (const char *c = input; *c != '\0'; c++) {
		switch (*c) {
			case '[':
			case '{':
			case '(':
				stack[++stack_top] = *c;
				break;
			case ']':
				if (stack_top == STACK_EMPTY || stack[stack_top--] != '[') return false;
				break;
			case ')':
				if (stack_top == STACK_EMPTY || stack[stack_top--] != '(') return false;
				break;
			case '}':
				if (stack_top == STACK_EMPTY || stack[stack_top--] != '{') return false;
				break;
			default:
				break;
		}
	}

	return stack_top == STACK_EMPTY;
}
