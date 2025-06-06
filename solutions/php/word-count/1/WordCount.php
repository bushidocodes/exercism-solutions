<?php

declare(strict_types=1);

function wordCount(string $words): array
{
    $arr = str_word_count(strtolower($words), 1, '0123456789');

    $counts = [];
    foreach ($arr as $elem){
        $counts[$elem] = (isset($counts[$elem]) ? $counts[$elem] : 0)  + 1;
    }

    return $counts;
}
