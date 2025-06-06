<?php

declare(strict_types=1);

function from(DateTimeImmutable $date): DateTimeImmutable
{
    $temp = DateTime::createFromImmutable($date);
    $temp->add(DateInterval::createFromDateString('1000000000 seconds'));
    return DateTimeImmutable::createFromMutable($temp);
}
