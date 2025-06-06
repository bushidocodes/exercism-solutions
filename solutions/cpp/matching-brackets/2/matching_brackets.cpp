#include "matching_brackets.h"

#include <stack>
#include <map>

namespace matching_brackets
{
    std::map<char, char> bracket_pairs{
        {']', '['},
        {')', '('},
        {'}', '{'}};

    bool check(std::string to_check)
    {
        std::stack<char> brackets{};

        for (char c : to_check)
        {
            switch (c)
            {
                case '[':
                case '(':
                case '{':
                    /* If an opening bracket, add to the stack */
                    brackets.push(c);
                    break;
                case ']':
                case ')':
                case '}':
                    /* If closing bracket, confirm corresponding opening bracket on top of stack */
                    if (brackets.empty() || brackets.top() != bracket_pairs.at(c))
                    {
                        return false;
                    }
                    brackets.pop();
                    break;
                default:
                    continue;
            }
        }

        /* Check that all opening brackets were terminated properly */
        return brackets.empty();
    }

} // namespace matching_brackets
