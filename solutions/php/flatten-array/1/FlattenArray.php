<?php

declare(strict_types=1);

function flatten(array $input): array
{
    $result = [];
    foreach($input as $value){
        if (gettype($value) == "array"){
            $result = array_merge($result, flatten($value));
        } else if (gettype($value) != "NULL"){
            array_push($result, $value);
        }
    }

    return $result;
}

