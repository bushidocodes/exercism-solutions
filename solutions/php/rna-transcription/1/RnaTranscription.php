<?php

declare(strict_types=1);

const dnaToRna = [
    "G" => "C",
    "C" => "G",
    "T" => "A",
    "A" => "U",
];

function toRna(string $dna): string
{
    $len = strlen($dna);
    $rna = "";

    for ($i = 0; $i < $len; $i++){
        $rna .= dnaToRna[$dna[$i]];
    }

    return $rna;
}
