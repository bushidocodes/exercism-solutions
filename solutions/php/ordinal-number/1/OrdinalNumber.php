<?php

declare(strict_types=1);

function toOrdinal(int $number): string
{
    if ($number == 0){
        return "$number";
    } else if ($number >= 11 && $number <= 13){
        return "${number}th";
    } else if ($number % 10 == 1){
        return "${number}st";
    } else if ($number % 10 == 2){
        return "${number}nd";
    } else if ($number % 10 == 3){
        return "${number}rd";
    } else {
        return "${number}th";
    }
}
