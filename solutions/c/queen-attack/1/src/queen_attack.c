#include "queen_attack.h"
#include <stdbool.h>
#include <math.h>

const int LAST_VALID_ROW_COLUMN = 7;

static inline bool is_off_board(position_t queen)
{
    return queen.row > LAST_VALID_ROW_COLUMN ||
           queen.column > LAST_VALID_ROW_COLUMN;
}

static inline bool is_same_space(position_t queen_1, position_t queen_2)
{
    return queen_1.row == queen_2.row && queen_1.column == queen_2.column;
}

static inline bool can_attack_diagonally(position_t queen_1, position_t queen_2)
{
    // Diagonal can be determined by the rows and columns have the same unsigned difference
    int diff_cols = queen_2.column - queen_1.column;
    if (diff_cols < 0)
        diff_cols *= -1;
    int diff_rows = queen_2.row - queen_1.row;
    if (diff_rows < 0)
        diff_rows *= -1;
    return diff_cols == diff_rows;
}

attack_status_t can_attack(position_t queen_1, position_t queen_2)
{
    if (is_same_space(queen_1, queen_2) ||
        is_off_board(queen_1) ||
        is_off_board(queen_2))
        return INVALID_POSITION;

    return (queen_1.column == queen_2.column ||
            queen_1.row == queen_2.row ||
            can_attack_diagonally(queen_1, queen_2))
               ? CAN_ATTACK
               : CAN_NOT_ATTACK;
}