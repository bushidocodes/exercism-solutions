<?php

declare(strict_types=1);

const roman_to_arabic = array(
    "M" => 1000,
    "CM" => 900,
    "D" => 500,
    "CD" => 400,
    "C" => 100,
    "XC" => 90,
    "L" => 50,
    "XL" => 40,
    "X" => 10,
    "IX" => 9,
    "V" => 5,
    "IV" => 4,
    "I" => 1
);

const romans_ordered = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"];

function toRoman(int $number): string
{
    if ($number < 1) throw new \BadFunctionCallException("Implement the toRoman function");

    $result = "";
    
    $romans_ordered_len = count(romans_ordered);
    for ($i = 0; $i < $romans_ordered_len; $i++){
        while ($number >= 0 && $number >= roman_to_arabic[romans_ordered[$i]]){
            $number -= roman_to_arabic[romans_ordered[$i]];
            $result = $result . romans_ordered[$i];
        }
    }

    return $result;
}
