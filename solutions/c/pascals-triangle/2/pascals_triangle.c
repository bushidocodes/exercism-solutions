#include "pascals_triangle.h"

#include <stdio.h>
#include <stdlib.h>

void free_triangle(uint8_t **r, size_t rows) {
	for (size_t i = 0; i < rows; i++) free(r[i]);
	free(r);
}

uint8_t **create_triangle(size_t rows) {
	// Treat degenerate of 0 rows as 1 with value of 0
	if (rows == 0) {
		rows++;
		uint8_t **result = calloc(rows, sizeof(uint8_t *));
		for (size_t i = 0; i < rows; i++)
			result[i] = calloc(rows, sizeof(uint8_t));
		return result;
	}

	uint8_t **result = calloc(rows, sizeof(uint8_t *));
	for (size_t i = 0; i < rows; i++) result[i] = calloc(rows, sizeof(uint8_t));

	if (rows == 1) {
		result[0][0] = 1;
	}

	if (rows > 1) {
		for (size_t i = 0; i < rows; i++) {
			for (size_t j = 0; j < rows; j++) {
				if (i != 0 && j != 0) /* Look Up Triangle */
					result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
				else if (j <= i) /* Set Edge to 0 */
					result[i][j] = 1;
			}
		}
	}

	return result;
}