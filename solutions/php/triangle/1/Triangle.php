<?php

declare(strict_types=1);

class Triangle
{
    private $sides = [];

    public function __construct(float $a, float $b, float $c)
    {
        if ($a <= 0 || $b <= 0 || $c <= 0) throw new \Exception();

        $this->sides = [$a, $b, $c];
        rsort($this->sides);

        if ($this->sides[0] > ($this->sides[1] + $this->sides[2])) throw new \Exception();
    }

    public function kind(): string
    {
        if ($this->sides[0] == $this->sides[1] && $this->sides[1] == $this->sides[2]) {
            return 'equilateral';
        } else if ($this->sides[0] != $this->sides[1] && $this->sides[1] != $this->sides[2] && $this->sides[0] != $this->sides[2]){
            return 'scalene';
        } else {
            return 'isosceles';
        }
    }
}
