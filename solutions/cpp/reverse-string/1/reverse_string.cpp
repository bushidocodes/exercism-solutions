#include "reverse_string.h"
#include <algorithm>

using namespace std;

namespace reverse_string
{
    string reverse_string(const string input)
    {
        string result;
        result.resize(input.length());
        reverse_copy(input.begin(), input.end(), result.begin());
        return result;
    }
} // namespace reverse_string
