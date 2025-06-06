<?php

declare(strict_types=1);

function isPangram(string $string): bool
{
    $char_code_counts = count_chars(strtolower($string), 1);

    foreach(range(ord('a'), ord('z')) as $char_code){
        if (!isset($char_code_counts[$char_code])) return false;
    }

    return true;
}
