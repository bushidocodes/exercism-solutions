<?php

declare(strict_types=1);

class Robot
{
    const DIRECTION_NORTH = 0;
    const DIRECTION_EAST = 1;
    const DIRECTION_SOUTH = 2;
    const DIRECTION_WEST = 3;

    /**
     *
     * @var int[]
     */
    public $position;

    /**
     *
     * @var string
     */
    public $direction;

    public function __construct(array $position, int $direction)
    {
        $this->position = $position;
        $this->direction = $direction;
    }

    public function turnRight(): self
    {
        $this->direction = ($this->direction + 1) % 4;
        return $this;
    }

    public function turnLeft(): self
    {
        $this->direction = ($this->direction + 3) % 4;
        return $this;
    }

    public function advance(): self
    {
        switch($this->direction){
            case Robot::DIRECTION_NORTH:
                $this->position[1]++;
                break;
            case Robot::DIRECTION_EAST:
                $this->position[0]++;
                break;
            case Robot::DIRECTION_SOUTH:
                $this->position[1]--;
                break;
            case Robot::DIRECTION_WEST:
                $this->position[0]--;
                break;
        }

        return $this;
    }

    public function instructions(string $input): self
    {
        foreach (str_split($input) as $c) {
            switch($c){
                case 'R':
                    $this->turnRight();
                    break;
                case 'L':
                    $this->turnLeft();
                    break;
                case 'A':
                    $this->advance();
                    break;
                default:
                    throw new \InvalidArgumentException("Instructions should only contain L, R, or A characters");
            }
        }

        return $this;
    }
}
