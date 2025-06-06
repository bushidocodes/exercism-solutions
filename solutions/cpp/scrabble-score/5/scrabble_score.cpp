#include "scrabble_score.h"

#include <cctype>
#include <map>
#include <numeric>

using namespace std;

namespace scrabble_score
{
    const map<char, int> letter_values = {
        {'A', 1},
        {'E', 1},
        {'I', 1},
        {'O', 1},
        {'U', 1},
        {'L', 1},
        {'N', 1},
        {'R', 1},
        {'S', 1},
        {'T', 1},
        {'D', 2},
        {'G', 2},
        {'B', 3},
        {'C', 3},
        {'M', 3},
        {'P', 3},
        {'F', 4},
        {'H', 4},
        {'V', 4},
        {'W', 4},
        {'Y', 4},
        {'K', 5},
        {'J', 8},
        {'X', 8},
        {'Q', 10},
        {'Z', 10}};

    auto score(string_view word) -> int
    {
        return accumulate(word.begin(), word.end(), 0, 
            [](auto acc, auto c){
                return acc + letter_values.at(toupper(c));
            });

        // For loop

        // int total = 0;
        // for (char c: word) {
        //     total += letter_values.at(toupper(c));
        // }
        // return total;
    }

} // namespace scrabble_score
