#include "beer_song.h"
#include <string.h>
#include <stdio.h>

void verse(char *buffer, unsigned int verse_number)
{
    if (verse_number >= 2)
    {
        sprintf(buffer, "%d bottles of beer on the wall, %d bottles of beer.\n"
                        "Take one down and pass it around, %d %s of beer on the wall.\n",
                verse_number, verse_number, verse_number - 1, (verse_number - 1 == 1 ? "bottle" : "bottles"));
    }
    else if (verse_number == 1)
    {
        sprintf(buffer, "1 bottle of beer on the wall, 1 bottle of beer.\n"
                        "Take it down and pass it around, no more bottles of beer on the wall.\n");
    }
    else
    {
        sprintf(buffer, "No more bottles of beer on the wall, no more bottles of beer.\n"
                        "Go to the store and buy some more, 99 bottles of beer on the wall.\n");
    }
}
void sing(char *buffer, unsigned int starting_verse_number,
          unsigned int ending_verse_number)
{
    strcpy(buffer, "");
    for (int i = (int)starting_verse_number; i >= (int)ending_verse_number; i--)
    {
        char verse_buffer[200] = "";
        verse((char *)&verse_buffer, i);
        strcat(buffer, (char *)&verse_buffer);
        if (i > (int)ending_verse_number)
            strcat(buffer, "\n");
    }
}