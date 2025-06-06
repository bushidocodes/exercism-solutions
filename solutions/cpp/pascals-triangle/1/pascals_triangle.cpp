#include "pascals_triangle.h"

namespace pascals_triangle
{
    std::vector<std::vector<int>> generate_rows(int row_count)
    {
        std::vector<std::vector<int>> results{};

        if (row_count == 0)
            return results;

        for (int row = 0; row < row_count; row++)
        {
            std::vector<int> new_row{};
            for (int cell = 0; cell <= row; cell++)
            {
                if (row == 0)
                {
                    new_row.push_back(1);
                }
                else
                {
                    if (cell == 0) /* left hand */
                    {
                        new_row.push_back(results[row - 1][cell]);
                    }
                    else if (cell == row) /* right hand */
                    {
                        new_row.push_back(results[row - 1][cell - 1]);
                    }
                    else /* middle */
                    {
                        new_row.push_back(results[row - 1][cell - 1] + results[row - 1][cell]);
                    }
                }
            }
            results.push_back(new_row);
        }

        return results;
    }

} // namespace pascals_triangle
