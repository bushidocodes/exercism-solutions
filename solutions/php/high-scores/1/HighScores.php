<?php

declare(strict_types=1);

class HighScores
{
    public array $scores;
    public int $latest;
    public int $personalBest;
    public array $personalTopThree;

    public function __construct(array $scores)
    {
        $this->scores = $scores;
        $this->latest = $scores[array_key_last($scores)];

        $sorted = $scores;
        rsort($sorted);

        $this->personalBest = $sorted[0];
        $this->personalTopThree = array_slice($sorted, 0, 3, false);
    }
}
