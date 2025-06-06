<?php

declare(strict_types=1);

function squareOfSum(int $max): int
{
    $sum = array_sum(range(1, $max));
    return $sum ** 2;
}

function sumOfSquares(int $max): int
{
    return array_sum(array_map(function($a){return $a ** 2;}, range(1, $max)));
}

function difference(int $max): int
{
    return squareOfSum($max) - sumOfSquares($max);
}
