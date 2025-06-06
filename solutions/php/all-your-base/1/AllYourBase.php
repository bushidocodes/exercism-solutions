<?php

declare(strict_types=1);

function rebase(int $number, array $sequence, int $base)
{
    if ($number <= 1) return null;
    if ($base <= 1) return null;
    if (count($sequence) == 0) return null;
    if ($sequence[0] == 0) return null;

    $rtl = array_values(array_reverse($sequence, false));

    $sum = 0;
    foreach ($rtl as $place => $digit) {
        if ($digit < 0 || $digit >= $number) return null;
        $sum += ($digit * ($number ** $place));
    }

    if ($sum == 0) return null;

    $place = 0;
    $reversedResult = [];
    for($buffer = $sum; $buffer >= 1; $buffer = $buffer / $base) {
        array_push($reversedResult, $buffer % ($base));
    }

    return array_values(array_reverse($reversedResult));
}
