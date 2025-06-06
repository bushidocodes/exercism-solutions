<?php

declare(strict_types=1);

date_default_timezone_set('UTC');

function get_day(DateTime $dt): string
{
    return date("l", $dt->getTimestamp());
}

function meetup_day(int $year, string $month, string $which, string $weekday): DateTimeImmutable
{
    $date = new DateTime();
    $date = $date->setTime(0,0);
    $month_int = intval($month);

    switch($which){
        case "first":
            $date->setDate($year, $month_int, 1);
            break;
        case "second":
            $date->setDate($year, $month_int, 8);
            break;
        case "third":
            $date->setDate($year, $month_int, 15);
            break;
        case "fourth":
            $date->setDate($year, $month_int, 22);
            break;
        case "fifth":
            $date->setDate($year, $month_int, 29);
            break;
        case "last":
            $date->setDate($year, $month_int, 1);
            $date->setDate($year, $month_int, date("t", $date->getTimestamp()) - 6);
            break;
        case "teenth":
            $date->setDate($year, $month_int, 13);
            break;
    }

    while (get_day($date) != $weekday){
        $date->add(DateInterval::createFromDateString('1 day'));
    }

    return DateTimeImmutable::createFromMutable($date);
}
