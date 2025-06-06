<?php

declare(strict_types=1);

function coprime(int $a, int $b): bool {
    $smaller = $a < $b? $a : $b;

    for ($i = 2; $i <= $smaller; $i++){
        if ($a % $i == 0 && $b % $i == 0) return false;
    }

    return true;
}

function mmi(int $a, int $b): int {
    $result = 1;
    while ($a * $result % $b != 1)
        $result++;

    return $result;
}

function encode(string $text, int $a, int $b): string
{
    if (!coprime($a, 26)) throw new \Exception("Error: a and m must be coprime.");

    $filtered_text = array_values(array_filter(str_split(strtolower($text)), function($x) { return ctype_alnum($x);}));
    
    $encoded_no_spaces = array_map( function($x) use ($a, $b) { 
        if (!ctype_alnum($x)) return "";
        else if (ctype_digit($x)) return $x;
        else return chr(ord('a') + (($a * (ord($x) - ord('a')) + $b) % 26)); 
    }, $filtered_text);

    $result = "";
    for($i = 0; $i < count($encoded_no_spaces); $i++) {
        if ($i > 0 && $i < count($encoded_no_spaces) - 1 && $i % 5 == 0){
            $result = $result . ' ' . $encoded_no_spaces[$i];
        } else {
            $result = $result . $encoded_no_spaces[$i];
        }
    }

    return $result;
}

function decode(string $text, int $a, int $b): string
{
    if (!coprime($a, 26)) throw new \Exception("Error: a and m must be coprime.");

    $filtered_text = array_values(array_filter(str_split($text), function($x) { return ctype_alnum($x);}));

    $_mmi = mmi($a, 26);

    $decoded = array_map( function($y) use ($a, $b, $_mmi) {
        if (!ctype_alnum($y)) return "";
        else if (ctype_digit($y)) return $y;
        else {
            $offset = (($_mmi * (ord($y) - ord('a') - $b)) % 26);
            if ($offset < 0) $offset += 26;
            return chr(ord('a') + $offset);
        }
    }, $filtered_text);

    return join($decoded);
}
