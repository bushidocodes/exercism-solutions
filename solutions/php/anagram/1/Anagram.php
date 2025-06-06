<?php

declare(strict_types=1);

function detectAnagrams(string $word, array $anagrams): array
{
    $lowerWord = strtolower($word);
    $chars = str_split($lowerWord);
    sort($chars, SORT_STRING);

    return array_values(array_filter($anagrams, function($v, $k) use($chars, $lowerWord) {
        $vLower = strtolower($v);
        if ($vLower == $lowerWord) return false;

        $temp = str_split($vLower);
        sort($temp, SORT_STRING);
        return $temp == $chars;
    }, ARRAY_FILTER_USE_BOTH));
}
