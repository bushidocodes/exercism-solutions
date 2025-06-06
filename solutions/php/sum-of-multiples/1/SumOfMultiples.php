<?php

declare(strict_types=1);

function sumOfMultiples(int $number, array $multiples): int
{
    if ($number < 2) return 0;
    $multiplesInRange = array_filter(range(1, $number - 1), function($v, $k) use ($multiples) {
        $isMultiple = false;
        foreach($multiples as $multiple){
            if ($multiple > 0 && $v % $multiple == 0) {
                $isMultiple = true;
                break;
            }
        }
        return $isMultiple;
    }, ARRAY_FILTER_USE_BOTH);

    return array_sum($multiplesInRange);
}
