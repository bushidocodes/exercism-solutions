<?php

declare(strict_types=1);

function steps(int $number): int
{
    if ($number < 1) {
        throw new \InvalidArgumentException('Only positive numbers are allowed');
    }

    $steps = 0;
    while ($number != 1){
        if ($number % 2 == 0) {
            $number /= 2;
            $steps++;
        } else {
            $number = (3 * $number) + 1;
            $steps++;
        }
    }

    return $steps;
}
