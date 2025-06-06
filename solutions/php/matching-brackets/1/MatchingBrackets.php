<?php

declare(strict_types=1);

const matching = [
    '[' => ']',
    '(' => ')',
    '{' => '}'
];

function brackets_match(string $input): bool
{
    $stack = [];

    $inputLen = strlen($input);
    for ($i = 0; $i < $inputLen; $i++){
        switch($input[$i]){
            case '[':
            case '{':
            case '(':
                array_push($stack, $input[$i]);
                break;
            case ']':
            case '}':
            case ')':
                if (count($stack) == 0 || matching[array_pop($stack)] != $input[$i]) return false;
                break;
            default:
                continue;
        }
    }

    return count($stack) == 0;
}
