<?php

declare(strict_types=1);

class Allergies
{
    private $score;

    public function __construct(int $score)
    {
        $this->score = $score;
    }

    public function isAllergicTo(Allergen $allergen): bool
    {
        return ($this->score & $allergen->getScore()) > 0;
    }

    public function getList(): array
    {
        return array_values(array_filter(Allergen::allergenList(), function($allergen, $k) {
            return $this->isAllergicTo($allergen);
        }, ARRAY_FILTER_USE_BOTH));
    }
}

class Allergen
{
    const CATS = 128;
    const POLLEN = 64;
    const CHOCOLATE = 32;
    const TOMATOES = 16;
    const STRAWBERRIES = 8;
    const SHELLFISH = 4;
    const PEANUTS = 2;
    const EGGS = 1;

    private $score;

    public function __construct(int $score)
    {
        $this->score = $score;
    }

    public function getScore(){
        return $this->score;
    }


    public static function allergenList(): array
    {
        return [
            new Allergen(Allergen::CATS),
            new Allergen(Allergen::CHOCOLATE),
            new Allergen(Allergen::EGGS),
            new Allergen(Allergen::PEANUTS),
            new Allergen(Allergen::POLLEN),
            new Allergen(Allergen::SHELLFISH),
            new Allergen(Allergen::STRAWBERRIES),
            new Allergen(Allergen::TOMATOES),
        ];
    }
}
