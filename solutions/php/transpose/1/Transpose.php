<?php

declare(strict_types=1);

function transpose(array $input): array
{
    $result = [];

    $longest_row = 0;
    for ($i = 0; $i < count($input); $i++){
        $row_len = strlen($input[$i]);
        $longest_row = $row_len > $longest_row ? $row_len : $longest_row;
    }

    for ($i = 0; $i < count($input); $i++){
        $row_len = strlen($input[$i]);
        $row = str_split($input[$i]);
        if (!array_key_exists(0, $result)) $result[0] = "";
        for ($j = 0; $j < $longest_row; $j++){
            echo "$i, $j\n";
            if (!array_key_exists($j, $result)) $result[$j] = "";
            if ($j < $row_len){
                $result[$j] = $result[$j] . $row[$j];
            } else {
                $result[$j] = $result[$j] . ' ';
            }
        }
    }

    if (count($result) > 0)
        $result[count($result) - 1] = rtrim($result[count($result) - 1]);

    return $result;
}
