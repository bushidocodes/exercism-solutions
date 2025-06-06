<?php

declare(strict_types=1);

class Darts
{
    public int $score = 0;
    private const INNER_RADIUS = 1;
    private const INNER_SCORE = 10;
    private const MIDDLE_RADIUS = 5;
    private const MIDDLE_SCORE = 5;
    private const OUTER_RADIUS = 10;
    private const OUTER_SCORE = 1;

    public function __construct(float $xAxis, float $yAxis)
    {
        $distance = sqrt($xAxis ** 2 + $yAxis ** 2);

        $this->score = match (true) {
            $distance <= self::INNER_RADIUS => self::INNER_SCORE,
            $distance <= self::MIDDLE_RADIUS => self::MIDDLE_SCORE,
            $distance <= self::OUTER_RADIUS => self::OUTER_SCORE,
            default => 0,
        };
    }

}
