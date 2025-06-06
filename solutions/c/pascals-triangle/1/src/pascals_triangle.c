#include "pascals_triangle.h"
#include <stdlib.h>

void free_triangle(size_t **r, size_t rows)
{
    for (size_t i = 0; i < rows; i++)
        free(r[i]);
    free(r);
}

size_t **create_triangle(const int rows_raw)
{
    // Handle invalid rows
    if (rows_raw < 0)
        return NULL;

    // Treat degenerate of 0 rows as 1 with value of 0
    int rows = rows_raw == 0 ? 1 : rows_raw;

    size_t **result = malloc(rows * sizeof(size_t *));
    for (int i = 0; i < rows; i++)
        result[i] = calloc(rows, sizeof(size_t));

    // If not degenerate, build triangle
    if (rows_raw > 0)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                if (i != 0 && j != 0) /* Look Up Triangle */
                    result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
                else if (j <= i) /* Set Edge to 0 */
                    result[i][j] = 1;
            }
        }
    }

    return (size_t **)result;
}