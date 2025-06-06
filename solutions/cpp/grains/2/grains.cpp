#include "grains.h"

#include <stdexcept>

namespace grains
{
    /* 
     * As I understand it, the fast data types express that I am only using the smaller data 
     * type to bound the acceptable values of the variable, but that I favor speed over 
     * compact representation if the compiler has to make a tradeoff
    */
    const uint_fast8_t CHESSBOARD_SQUARE_COUNT = 64;

    uint64_t square(uint_fast8_t chessboard_square)
    {
        if (chessboard_square == 0 || chessboard_square > CHESSBOARD_SQUARE_COUNT)
            throw std::invalid_argument{"Must be a square between 1 and 64"};

        /* 
         * Because computers use a base-2 number system, shifting the digits left one
         * position is equivalent to multiplying by two 
         * 
         * Thus
         * 0001 = 1
         * 0010 = 2
         * 0100 = 4
         * 1000 = 8
         * 
         * This allows the chessboard to be modeled as a 64 element bit array
         */
        return 1ULL << (chessboard_square - 1);
    }

    uint64_t total()
    {
        uint64_t sum = 0;
        for (size_t i = 1; i <= CHESSBOARD_SQUARE_COUNT; i++)
        {
            sum += square(i);
        }

        return sum;
    };

} // namespace grains
