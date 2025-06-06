<?php

declare(strict_types=1);

function maskify(string $cc): string
{
    if (strlen($cc) < 6) return $cc;

    // Count digits
    $digit_count = 0;
    foreach(str_split($cc) as $c) {
        if (is_numeric($c)) $digit_count++;
    }

    // Generate Result
    $masked = "";
    $current_digit = 0;
    foreach(str_split($cc) as $c) {
        if (is_numeric($c)) {
            if ($current_digit > 0 && $current_digit < $digit_count - 4){
                $masked = $masked . '#';
            } else {
                $masked = $masked . $c;
            }
            $current_digit++;
        } else {
            $masked = $masked . $c;
        }
    }

    return $masked;
}
