<?php


declare(strict_types=1);

use Ds\Set;

function isIsogram(string $word): bool
{
    $no_hyphens_or_spaces = preg_replace('/[ -]/', '', $word);
    $lower = mb_strtolower($no_hyphens_or_spaces);

    $letters = new Set();

    foreach (mb_str_split($lower) as $char) {
        if ($letters->contains($char)) return false;
        else $letters->add($char);
    }

    return true;
}
