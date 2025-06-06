<?php

declare(strict_types=1);

function nucleotideCount(string $input): array
{
    $count = [
        'a' => 0,
        'c' => 0,
        't' => 0,
        'g' => 0
    ];

    if (strlen($input) > 0){
        foreach(str_split(strtolower($input)) as $nucleotide){
            switch($nucleotide){
                case 'a':
                case 'c':
                case 't':
                case 'g':
                    $count[$nucleotide]++;
                    break;
                default:
                    throw new Exception();
            }
        }
    }

    return $count;
}
