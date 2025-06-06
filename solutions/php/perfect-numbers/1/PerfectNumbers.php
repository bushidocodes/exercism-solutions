<?php

declare(strict_types=1);

function factorize(int $number): array
{
    $factors = [];

    if ($number > 1) array_push($factors, 1);

    $buffer = $number;
    for ($i = 2; $i <= $buffer / 2; $i++){
        if ($buffer % $i == 0) {
            array_push($factors, $i);
            $second = $buffer / $i;
            if (!in_array($second, $factors)){
                array_push($factors, $second);
            }
        }
    }
    return array_unique($factors);
}


function getClassification(int $number): string
{
    if ($number <= 0) throw new \InvalidArgumentException();

    $factors = factorize($number);
    $aliquotSum = array_sum($factors);

    if ($number == $aliquotSum) return "perfect";
    else if ($aliquotSum > $number) return "abundant";
    else if ($aliquotSum < $number) return "deficient";
}
