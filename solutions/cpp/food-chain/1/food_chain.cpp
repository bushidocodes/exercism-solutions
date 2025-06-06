#include <vector>

#include "food_chain.h"

using namespace std;

namespace food_chain
{
    vector<string> creatures{
        "",
        "fly",
        "spider",
        "bird",
        "cat",
        "dog",
        "goat",
        "cow",
        "horse"};

    vector<string> creatures_antics{
        "",
        "",
        "It wriggled and jiggled and tickled inside her.\n",
        "How absurd to swallow a bird!\n",
        "Imagine that, to swallow a cat!\n",
        "What a hog, to swallow a dog!\n",
        "Just opened her throat and swallowed a goat!\n",
        "I don't know how she swallowed a cow!\n"};

    string
    verse(int verse_number)
    {
        string verse = "I know an old lady who swallowed a " + creatures.at(verse_number) + ".\n";

        if (verse_number >= 2 && verse_number < 8)
        {
            verse += creatures_antics.at(verse_number);
        }

        /* Using Switch Fallthrough because verses accumulate this portion */
        switch (verse_number)
        {
        case 8:
            verse += "She's dead, of course!\n";
            break;
        case 7:
            verse += "She swallowed the cow to catch the goat.\n";
        case 6:
            verse += "She swallowed the goat to catch the dog.\n";
        case 5:
            verse += "She swallowed the dog to catch the cat.\n";
        case 4:
            verse += "She swallowed the cat to catch the bird.\n";
        case 3:
            verse += "She swallowed the bird to catch the spider that wriggled and jiggled and tickled inside her.\n";
        case 2:
            verse += "She swallowed the spider to catch the fly.\n";
        case 1:
            verse += "I don't know why she swallowed the fly. Perhaps she'll die.\n";
        }

        return verse;
    }

    string verses(int start_verse, int end_verse)
    {
        string verses = "";
        for (int i = start_verse; i <= end_verse; i++)
        {
            verses += verse(i);
            verses += "\n";
        }
        return verses;
    };

    string sing()
    {
        return verses(1, 8);
    };

} // namespace food_chain
