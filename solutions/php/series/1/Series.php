<?php

declare(strict_types=1);

function slices(string $digits, int $series): array
{
    $result = [];
    
    $digits_len = strlen($digits);
    
    if ($series <= 0 || $series > $digits_len) throw new \Exception("series should be between 1 and length of digits string");

    for ($i = 0; $i + $series - 1 < $digits_len; $i++){
        array_push($result, substr($digits, $i, $series));
    }

    return $result;
}
