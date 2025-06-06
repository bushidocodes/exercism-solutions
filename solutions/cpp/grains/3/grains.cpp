#include "grains.h"

#include <stdexcept>

namespace grains
{
    const std::uint64_t CHESSBOARD_SQUARE_COUNT = 64;

    std::uint64_t square(std::uint64_t chessboard_square)
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

    std::uint64_t total()
    {
        /* 
         * Because grains double like the base-2 number system and a chessboard
         * is the same size as a 64-bit unsigned integer, the total value is 64 consecutive
         * 1s or 0xFFFFFFFFFFFFFFFF. In cstdint or stdint.h, this is also expressed as 
         * the macro UINT64_MAX
         */
        return UINT64_MAX;
    };

} // namespace grains
