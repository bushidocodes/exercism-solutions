<?php

declare(strict_types=1);

class Robot
{
    static $issuedNames = [];
    private $name = null;

    static function getRandomLetter(): string
    {
        return chr(rand(ord('A'), ord('Z')));
    }

    public function getName(): string
    {
        if ($this->name == null) {
            do {
                $candidate = sprintf("%s%s%'.03d", Robot::getRandomLetter(), Robot::getRandomLetter(), rand(0, 999));
            } while (in_array($candidate, Robot::$issuedNames));

            $this->name = $candidate;
            array_push(Robot::$issuedNames, $candidate);
        }

        return $this->name;
    }

    public function reset(): void
    {
        $this->name = null;
    }
}
