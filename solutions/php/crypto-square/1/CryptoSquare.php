<?php

declare(strict_types=1);

function crypto_square(string $plaintext): string
{
    $normalized = implode(array_filter(str_split(strtoLower($plaintext)), function($c){return ctype_alnum($c);}));
    $normalized_len = strlen($normalized);

    $c = 1;
    while ($c * $c < $normalized_len) $c++;
    $r = $c * $c > $normalized_len? $c - 1 : $c;

    $square = [];
    for ($i = 0; $i < $c; $i++) array_push($square, '');

    for ($i = 0; $i < $normalized_len; $i += $c){
        for ($j = 0; $j < $c; $j++){
            if ($i + $j < $normalized_len)
                $square[$j] .= substr($normalized, $i + $j, 1);
            else 
                $square[$j] .= ' ';
        } 
    }

    return implode(' ', $square);
}
