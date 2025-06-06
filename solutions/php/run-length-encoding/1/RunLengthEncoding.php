<?php

declare(strict_types=1);

function encode(string $input): string
{
    $result = "";

    $prev = null;
    $count = 0;

    foreach(str_split($input) as $c) {
        if ($prev == null){
            $prev = $c;
            $count = 1;
        } else if ($prev == $c){
            $count++;
        } else {
            if ($count > 1) {
                $result = $result . "$count$prev";
            } else {
                $result = $result . $prev;
            }
            $prev = $c;
            $count = 1;
        }
    }

    if ($count > 1) $result = $result . "$count$prev";
    else $result = $result . $prev;

    return $result;
}

function decode(string $input): string
{
    $result = "";
    preg_match_all('/(\d*[a-zA-Z ])/', $input, $matches);

    foreach($matches[0] as $match){
        if (is_numeric(substr($match, 0, 1))){
            list ($count, $char) = sscanf($match, "%d%[^\d]");
            foreach (range(1, $count) as $letter){
                $result = $result . $char;
            }
        } else {
            $result = $result . $match;
        }
    }

    return $result;
}
