<?php

declare(strict_types=1);

function toDecimal(string $number): int
{
    $decimal = 0;

    for ($i = strlen($number) - 1, $place = 0; $i >= 0; $i--, $place++){
        if ($number[$i] == "2" || $number[$i] == "1"){
            $decimal += ($number[$i] * (3 ** $place));
        } else if ($number[$i] != "0") {
            // Return 0 on error
            return 0;
        }
    }

    return $decimal;
}
