#include "square_root.h"

// From https://en.wikipedia.org/wiki/Methods_of_computing_square_roots
short squareRoot(int num)
{
    int res = 0;
    int bit = 1 << 30;

    while (bit > num)
        bit >>= 2;

    while (bit != 0)
    {
        if (num >= res + bit)
        {
            num -= res + bit;
            res = (res >> 1) + bit;
        }
        else
            res >>= 1;
        bit >>= 2;
    }
    return res;
}