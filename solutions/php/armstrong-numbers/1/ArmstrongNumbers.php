<?php

declare(strict_types=1);

function isArmstrongNumber(int $number): bool
{
    $digits = str_split("$number");
    $digitsLen = count($digits);

    return array_sum(array_map(function($e) use ($digitsLen) { return intval($e) ** $digitsLen;}, $digits)) == $number;
}
