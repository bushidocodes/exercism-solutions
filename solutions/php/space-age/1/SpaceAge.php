<?php

declare(strict_types=1);

class SpaceAge
{
    private int $seconds;
    const EARTH_YEAR_SECONDS = 31557600;
    const MERCURY_YEAR = 0.2408467;
    const VENUS_YEAR = 0.61519726;
    const MARS_YEAR = 1.8808158;
    const JUPITER_YEAR = 11.862615;
    const SATURN_YEAR = 29.447498;
    const URANUS_YEAR = 84.016846;
    const NEPTUNE_YEAR = 164.79132;

    public function __construct(int $seconds)
    {
        $this->seconds = $seconds;
    }

    public function seconds(): int
    {
        return $this->seconds;
    }

    public function earth(): float
    {
        return $this->seconds / SpaceAge::EARTH_YEAR_SECONDS;
    }

    public function mercury(): float
    {
        return $this->seconds / SpaceAge::EARTH_YEAR_SECONDS / SpaceAge::MERCURY_YEAR;
    }

    public function venus(): float
    {
        return $this->seconds / SpaceAge::EARTH_YEAR_SECONDS / SpaceAge::VENUS_YEAR;
    }

    public function mars(): float
    {
        return $this->seconds / SpaceAge::EARTH_YEAR_SECONDS / SpaceAge::MARS_YEAR;
    }

    public function jupiter(): float
    {
        return $this->seconds / SpaceAge::EARTH_YEAR_SECONDS / SpaceAge::JUPITER_YEAR;
    }

    public function saturn(): float
    {
        return $this->seconds / SpaceAge::EARTH_YEAR_SECONDS / SpaceAge::SATURN_YEAR;
    }

    public function uranus(): float
    {
        return $this->seconds / SpaceAge::EARTH_YEAR_SECONDS / SpaceAge::URANUS_YEAR;
    }

    public function neptune(): float
    {
        return $this->seconds / SpaceAge::EARTH_YEAR_SECONDS / SpaceAge::NEPTUNE_YEAR;
    }
}
