#include "isogram.h"
#include <set>
#include <utility>

using namespace std;

namespace isogram
{
    bool is_isogram(string candidate)
    {
        set<char> chars;

        for (char c : candidate)
        {
            if (!isalpha(c))
                continue;

            char key = tolower(c);
            if (chars.find(key) == chars.end())
                chars.insert(key);
            else
                return false;
        }
        return true;
    }

} // namespace isogram
