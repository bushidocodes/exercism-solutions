#include "reverse_string.h"
#include <algorithm>

using namespace std;

namespace reverse_string {
    string reverse_string(string input) {
        reverse(input.begin(), input.end());
        return input;
    }
}
