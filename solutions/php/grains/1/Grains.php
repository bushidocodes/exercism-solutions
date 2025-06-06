<?php

declare(strict_types=1);

function square(int $number): string
{
    if ($number < 1 || $number > 64) throw new \InvalidArgumentException("$number is not on board [1..64]");
    $num = 1 << ($number - 1);

    return sprintf("%lu", $num);
}

function total(): string
{
    return sprintf("%lu", (1 << 64) - 1);
}
