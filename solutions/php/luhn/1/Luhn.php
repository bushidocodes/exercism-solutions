<?php

declare(strict_types=1);

function isValid(string $number): bool
{
    // Can only contain spaces and digits
    if (preg_match('/^[0-9 ]+$/', $number) == 0) return false;

    // Split by digit
    $chars = str_split("$number");

    // Filter out spaces, and regenerate list keys
    $chars = array_values(array_filter($chars, function($v, $k) {
        if ($v == ' ') return false;
        return true;
    }, ARRAY_FILTER_USE_BOTH));

    // Validate at least 2 digits
    $chars_len = count($chars);
    if ($chars_len <= 1) return false;

    // Double every second digit, starting from the right
    $digits = array_map(function($e, $idx) use ($chars_len) {
        if (($chars_len - 1 - $idx) % 2 == 0) return $e;
        $digit = intval($e, 10);
        $digit *= 2;
        if ($digit > 9) $digit -= 9;
        return $digit;
    }, $chars, array_keys($chars));

    return array_sum($digits) % 10 == 0;
}
