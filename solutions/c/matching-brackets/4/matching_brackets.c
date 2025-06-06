#include "matching_brackets.h"

#define MAX_STACK 50

bool is_paired(const char *input) {
	// Simple Stack. If top is -1, stack is empty
	char stack[MAX_STACK];
	int stack_top = -1;

	for (char *c = (char *)input; *c != '\0'; c++) {
		switch (*c) {
			case '[':
			case '{':
			case '(':
				stack[++stack_top] = *c;
				break;
			case ']':
				if (stack[stack_top--] != '[') return false;
				break;
			case ')':
				if (stack[stack_top--] != '(') return false;
				break;
			case '}':
				if (stack[stack_top--] != '{') return false;
				break;
			default:
				break;
		}
	}

	return stack_top == -1;
}
