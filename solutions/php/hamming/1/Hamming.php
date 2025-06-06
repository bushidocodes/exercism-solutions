<?php

declare(strict_types=1);

function distance(string $strandA, string $strandB): int
{
    $distance = 0;
    $len = strlen($strandA);

    if ($len != strlen($strandB))
        throw new \InvalidArgumentException("DNA strands must be of equal length.");

    for ($i = 0; $i < $len; $i++) {
        if ($strandA[$i] != $strandB[$i]) $distance++;
    }

    return $distance;
}
