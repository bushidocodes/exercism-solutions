<?php

declare(strict_types=1);

function pascalsTriangleRows($rowCount)
{
    if ($rowCount < 0 || is_null($rowCount)) return -1;

    if ($rowCount == 0) return [];

    $triangle = [[1]];
    for ($row = 1; $row < $rowCount; $row++){
        $newRow = $triangle[$row - 1];
        for($cell = count($newRow) - 1; $cell > 0; $cell--){
            $newRow[$cell] += $newRow[$cell - 1];
        }
        array_push($newRow, 1);
        array_push($triangle, $newRow);
    }

    return $triangle;
}
