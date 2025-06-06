#pragma once

#include <string>
#include <utility>

namespace queen_attack
{
    using pos_t = std::pair<int, int>;

    class chess_board
    {
    private:
        pos_t _white;
        pos_t _black;

    public:
        chess_board(pos_t white = {0, 3}, pos_t black = {7, 3});
        pos_t white() const;
        pos_t black() const;
        bool can_attack() const;
        operator std::string() const;
    };

} // namespace queen_attack
