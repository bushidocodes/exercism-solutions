<?php

declare(strict_types=1);

function parse_binary(string $binary): int
{
    $decimal = 0;
    $place = 0;

    for ($i = strlen($binary) - 1, $place = 0; $i >= 0; $i--, $place++){
        if ($binary[$i] == "1"){
            $decimal += (2 ** $place);
        } else if ($binary[$i] != "0") {
            throw new \InvalidArgumentException;
        }
    }

    return $decimal;
}
