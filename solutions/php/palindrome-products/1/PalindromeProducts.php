<?php

declare(strict_types=1);

function isPalindrome(int $candidate): bool
{
    $candidateStr = strval($candidate);
    return $candidateStr == strrev($candidateStr);
}

function factorize(int $number): array
{
    $factors = [];
    $buffer = $number;
    for ($i = 1; $i <= $buffer; $i++){
        if ($number % $i == 0 && $i <= $number / $i) {
            array_push($factors, [$i, $number / $i]);
            $buffer = $number / $i;
        }
    }

    return $factors;
}

function smallest(int $min, int $max): array
{
    $value = PHP_INT_MAX;

    for ($i = $min; $i <= $max; $i++) {
        for ($j = $min; $j <= $max; $j++) {
            $product = $i * $j;
            if ($product >= $value) break;
            if (isPalindrome($product)) $value = $product;
        }
    }

    if ($value == PHP_INT_MAX) throw new \Exception("No palindromes found");

    $factors = factorize($value);
    $factorsInRange = array_values(array_filter(factorize($value), 
        function($v) use ($min, $max) {
            [$first, $second] = $v;
            return $first >= $min && $first <= $max && $second >= $min && $second <= $max;
        }
    ));

    return [$value, $factorsInRange];
}

function largest(int $min, int $max): array
{
    $value = PHP_INT_MIN;

    for ($i = $max; $i >= $min; $i--) {
        for ($j = $max; $j >= $min; $j--) {
            $product = $i * $j;
            if ($product <= $value) break;
            if (isPalindrome($product)) $value = $product;
        }
    }

    if ($value == PHP_INT_MIN) throw new \Exception("No palindromes found");

    $factors = factorize($value);
    $factorsInRange = array_values(array_filter(factorize($value), 
        function($v) use ($min, $max) {
            [$first, $second] = $v;
            return $first >= $min && $first <= $max && $second >= $min && $second <= $max;
        }
    ));

    return [$value, $factorsInRange];
}
