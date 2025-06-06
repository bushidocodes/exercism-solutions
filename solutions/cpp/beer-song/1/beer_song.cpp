#include "beer_song.h"

#include <sstream>

namespace beer_song
{

    /* I don't think DRYing this up further is worth the complexity of a bunch of utility functions for bottle(s) and such. */
    std::string verse(int verse_number)
    {
        std::stringstream ss;

        if (verse_number > 2)
        {

            ss << verse_number << " bottles of beer on the wall, " << verse_number << " bottles of beer.\nTake one down and pass it around, " << verse_number - 1 << " bottles of beer on the wall.\n";
        }

        else if (verse_number == 2)
        {

            ss << "2 bottles of beer on the wall, 2 bottles of beer.\nTake one down and pass it around, 1 bottle of beer on the wall.\n";
        }
        else if (verse_number == 1)
        {
            ss << "1 bottle of beer on the wall, 1 bottle of beer.\nTake it down and pass it around, no more bottles of beer on the wall.\n";
        }
        else if (verse_number == 0)
        {
            ss << "No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, 99 bottles of beer on the wall.\n";
        }

        return ss.str();
    }

    std::string sing(int start, int end)
    {
        std::string song;
        for (int i = start; i >= end; i--)
        {
            if (i != start)
                song += "\n";
            song += verse(i);
        }

        return song;
    }

} // namespace beer_song
