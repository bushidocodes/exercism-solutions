def saddle_points(matrix: list[list[int]]) -> list[dict[str, int]]:
    if not matrix:
        return []
    
    len_of_first_row = len(matrix[0])
    if any(len(row) != len_of_first_row for row in matrix):
        raise ValueError("irregular matrix")

    max_value_in_row = [max(row) for row in matrix]
    min_value_in_col = [min(row[col_id] for row in matrix) for col_id in range(len_of_first_row)]

    return [
        {"row": row_id + 1, "column": col_id + 1}
        for row_id, row in enumerate(matrix)
        for col_id, el in enumerate(row)
        if max_value_in_row[row_id] == el == min_value_in_col[col_id]
    ]
