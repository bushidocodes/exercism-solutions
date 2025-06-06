<?php

declare(strict_types=1);

function isVowel(string $c): bool
{
    return ($c == 'a' || $c == 'e' || $c == 'i' || $c == 'o' || $c == 'u');
}

function translateWord(string $text): string
{
    // Special case weird prefixes
    $first = substr($text, 0, 1);
    $firstTwo = substr($text, 0, 2);
    if ($firstTwo == 'xy' || $firstTwo == 'xr' || $firstTwo == 'yt') {
        return $text . "ay";
    }

    $i = 0;
    for ($i = 0; $i < strlen($text) && ( 
        !isVowel($text[$i]) 
        || ($i > 0 && $text[$i] == 'y')
        || ($i > 0 && $text[$i] == 'u' && $text[$i - 1] == 'q')) /* Rule 3 */
    ; $i++)
        ;

    return substr($text, $i) . substr($text, 0, $i) . "ay";
}

function translate(string $text): string
{
    return implode(" ", array_map('translateWord', explode(" ", $text)));
}
