<?php

declare(strict_types=1);

function raindrops(int $number): string
{
    $result = "";

    if ($number % 3 == 0) $result = $result . 'Pling';
    if ($number % 5 == 0) $result = $result . 'Plang';
    if ($number % 7 == 0) $result = $result . 'Plong';
    if (strlen($result) == 0) $result = "$number";

    return $result;
}
