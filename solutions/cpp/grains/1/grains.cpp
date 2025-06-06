#include "grains.h"

#include <stdexcept>

using namespace std;

namespace grains
{
    const uint_fast8_t CHESSBOARD_SQUARE_COUNT = 64;

    uint64_t square(uint_fast8_t chessboard_square)
    {
        if (chessboard_square == 0 || chessboard_square > CHESSBOARD_SQUARE_COUNT)
            throw std::invalid_argument{"Must be a square between 1 and 64"};

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
