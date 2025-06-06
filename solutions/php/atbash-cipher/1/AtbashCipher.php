<?php

declare(strict_types=1);

function encode(string $text): string
{
    $result = "";
    $counter = 0;
    foreach(str_split(strtolower($text)) as $c){
        if (ctype_alnum($c) && $counter == 5){
            $result = $result . ' ';
            $counter = 0;
        }

        if (ctype_lower($c)){
            $result = $result . chr(ord('z') - (ord($c) - ord('a')));
            $counter = $counter + 1;
        } else if (ctype_digit($c)){
            $result = $result . $c;
            $counter = $counter + 1;
        }
    }

    return $result;
}
