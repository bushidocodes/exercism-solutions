<?php

declare(strict_types=1);

function acronym(string $text): string
{
    $res = "";

    $text_len = strlen($text);
    for ($i = 0; $i + 1 < $text_len; $i++){
        // replace - with space
        if ($text[$i] == "-"){
            $text = substr_replace($text, " ", $i, 1);
        }

        // insert space between camel case
        if (ctype_lower($text[$i]) && ctype_upper($text[$i + 1])){
            $text = substr_replace($text, " ", $i + 1, 0);
        }
    }

    $words = mb_split(" ", ucwords($text));

    foreach($words as $word) {
        $res .= mb_convert_case(mb_substr($word, 0, 1), MB_CASE_UPPER);
    }

    return strlen($res) > 1 ? $res : "";
}
