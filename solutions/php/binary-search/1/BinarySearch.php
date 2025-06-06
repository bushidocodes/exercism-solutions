<?php

declare(strict_types=1);

function _find(int $needle, array $haystack, int $left, int $rightEx): int
{
    if ($left == $rightEx) return -1;

    $mid = $left + intval(floor(($rightEx - $left) / 2));

    if ($needle == $haystack[$mid]) return $mid;
    else if ($needle < $haystack[$mid]) 
        return _find($needle, $haystack, $left, $mid);
    else if ($needle > $haystack[$mid]) 
        return _find($needle, $haystack, $mid + 1, $rightEx);
}

function find(int $needle, array $haystack): int
{
    return _find($needle, $haystack, 0, count($haystack));
}
