<?php

declare(strict_types=1);


function diamondRow(int $cc, int $startCC, int $endCC): string{
    $row = "";
    for ($j = 0; $j < $endCC - $cc; $j++) $row .= ' ';
    $row = $row . chr($cc);
    if ($cc > $startCC){
        $midSpaces = 2 * ($cc - $startCC) - 1;
        for ($j = 0; $j < $midSpaces; $j++) $row .= ' ';
        $row .= chr($cc);
    }
    for ($j = 0; $j < $endCC - $cc; $j++) $row .= ' ';
    return $row;
}

function diamond(string $letter): array
{
    $startCC = ord('A');
    $endCC = ord($letter);

    $result = [];

    for ($cc = $startCC; $cc <= $endCC; $cc++){
        array_push($result, diamondRow($cc, $startCC, $endCC));
    }
    for ($cc = $endCC - 1; $cc >= $startCC; $cc--){
        array_push($result, diamondRow($cc, $startCC, $endCC));
    }

    return $result;
}
