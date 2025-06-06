#include "beer_song.h"

#include <sstream>

namespace beer_song
{

    std::string verse(int verse_number)
    {
        std::stringstream ss;

        if (verse_number > 2)
        {
            ss << verse_number << " bottles of beer on the wall, " << verse_number << " bottles of beer.\n";
            ss << "Take one down and pass it around, " << verse_number - 1 << " bottles of beer on the wall.\n";
        }

        else if (verse_number == 2)
        {
            ss << "2 bottles of beer on the wall, 2 bottles of beer.\n";
            ss << "Take one down and pass it around, 1 bottle of beer on the wall.\n";
        }
        else if (verse_number == 1)
        {
            ss << "1 bottle of beer on the wall, 1 bottle of beer.\n";
            ss << "Take it down and pass it around, no more bottles of beer on the wall.\n";
        }
        else if (verse_number == 0)
        {
            ss << "No more bottles of beer on the wall, no more bottles of beer.\n";
            ss << "Go to the store and buy some more, 99 bottles of beer on the wall.\n";
        }

        return ss.str();
    }

    std::string sing(int start, int end)
    {
        std::string song;
        for (int i = start; i >= end; i--)
        {
            song += verse(i);
            if (i != end)
                song += "\n";
        }

        return song;
    }

} // namespace beer_song
