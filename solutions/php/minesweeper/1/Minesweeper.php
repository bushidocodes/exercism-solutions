<?php

declare(strict_types=1);

function solve(string $minesweeperBoard): string
{
    $lines = explode("\n", trim($minesweeperBoard));
    $matrix = array_map(
        function($arr){ return str_split(trim($arr)); }, 
        $lines
    );

    $squareCount = 0;

    foreach ($matrix as $i => $row) {
        if ($i + 1 != count($matrix) && count($matrix[$i + 1]) != count($matrix[0])){
            throw new \InvalidArgumentException("rows were unequal");
        }

        foreach ($row as $j => $cell) {
            if ($i == 0 || $i == count($matrix) - 1) {
                if ($j == 0 || $j == count($row) -1){
                    if ($cell != '+') throw new \InvalidArgumentException("Expected corner");
                } else {
                    if ($cell != '-') throw new \InvalidArgumentException("Expected horizontal border");
                }
            } else {
                if ($j == 0 || $j == count($row) -1){
                    if ($cell != '|') throw new \InvalidArgumentException("Expected vertical border");
                } else {                   
                    if ($cell == ' ') {
                        $squareCount++;
                        $mines = 0;
                        if ($matrix[$i - 1][$j - 1] == '*') $mines++;
                        if ($matrix[$i - 1][$j] == '*') $mines++;
                        if ($matrix[$i - 1][$j + 1] == '*') $mines++;
                        if ($matrix[$i][$j - 1] == '*') $mines++;
                        if ($matrix[$i][$j + 1] == '*') $mines++;
                        if ($matrix[$i + 1][$j - 1] == '*') $mines++;
                        if ($matrix[$i + 1][$j] == '*') $mines++;
                        if ($matrix[$i + 1][$j + 1] == '*') $mines++;
                        if ($mines > 0) $matrix[$i][$j] = $mines;
                    } else if ($cell == '*') {
                        $squareCount++;
                    } else {
                        throw new \InvalidArgumentException("not mine or space");
                    }
                }
            }
        }
    }

    if ($squareCount < 2) throw new \InvalidArgumentException();

    array_unshift($matrix, array());
    array_push($matrix, array());

    return implode(
        "\n",
        array_map(
            function($arr){ return implode("", $arr); }, 
            $matrix
        ), 
    );  
}
