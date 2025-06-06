<?php

declare(strict_types=1);

class Game
{
    private $throws = [];
    private $isComplete = false;

    public function score(): int
    {
        if (!$this->isComplete) {
            throw new \Exception("Game not yet complete");
        }

        $frame_score = [];

        for ($frame = 9; $frame >= 0; $frame--){
            if ($this->throws[$frame * 2] == 10 && $this->throws[$frame * 2 + 2] == 10){
                $frame_score[$frame] = 10 + $this->throws[$frame * 2 + 2] + $this->throws[$frame * 2 + 4];
            } else if ($this->throws[$frame * 2] == 10){
                $frame_score[$frame] = 10 + $this->throws[$frame * 2 + 2] + $this->throws[$frame * 2 + 3];
            } else if ($this->throws[$frame * 2] + $this->throws[$frame * 2 + 1] == 10){
                // Spare
                $frame_score[$frame] = 10 + $this->throws[$frame * 2 + 2];
            } else {
                $frame_score[$frame] = $this->throws[$frame * 2] + $this->throws[$frame * 2 + 1];
            }
        }

        return array_sum($frame_score);
    }

    public function roll(int $pins): void
    {
        if ($pins < 0 || $pins > 10) throw new \Exception("Invalid pin count");

        if ($this->isComplete) {
            print_r($this->throws);
            throw new \Exception("Cannot throw when game complete");
        }

        array_push($this->throws, $pins);
        $throwCount = count($this->throws);

        // pad throw if strike
        if ($pins == 10 && $throwCount % 2 == 1) {
            $throwCount++;
            array_push($this->throws, 0);
        }

        // Validate that frame totals do not exceed 10 pins
        if ($throwCount > 0 && $throwCount % 2 == 0){
            if ($this->throws[$throwCount - 1] + $this->throws[$throwCount - 2] > 10) 
                throw new Exception("A frame cannot score more than 10 points");
        }

        // Check if game is over
        if ($throwCount == 20 ) {
            if ($this->throws[18] + $this->throws[19] < 10) $this->isComplete = true;
        } else if ($throwCount == 21){
            if ($this->throws[18] != 10) $this->isComplete = true;
        } else if ($throwCount == 22){
            if ($this->throws[18] != 10 || $this->throws[20] != 10) $this->isComplete = true;
        } else if ($throwCount == 24){
            $this->isComplete = true;
        }
    }
}
