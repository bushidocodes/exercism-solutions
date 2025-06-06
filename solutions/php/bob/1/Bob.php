<?php

declare(strict_types=1);

class Bob
{
    static private function isAQuestion(string $str): bool
    {
        return str_ends_with(rtrim($str), '?');
    }

    static private function isSilent(string $str): bool
    {
        return strlen(rtrim($str)) == 0;
    }

    static private function isYelling(string $str): bool
    {
        $str_len = strlen($str);
        $has_letter = false;

        for($i = 0; $i < $str_len; $i++){
            if (ctype_lower($str[$i])) return false;
            else if (ctype_alpha($str[$i])) $has_letter = true;
        }

        return $has_letter;
    }

    public function respondTo(string $str): string
    {
        if (Bob::isAQuestion($str) && Bob::isYelling($str)) {
            return 'Calm down, I know what I\'m doing!';
        } else if (Bob::isAQuestion($str)) {
            return 'Sure.';
        } else if (Bob::isYelling($str)) {
            return  'Whoa, chill out!';
        } else if (Bob::isSilent($str)) {
            return 'Fine. Be that way!';
        } else {
            return 'Whatever.';
        }
    }
}
