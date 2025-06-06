<?php

declare(strict_types=1);

class DndCharacter
{
    public int $strength;
    public int $dexterity;
    public int $constitution;
    public int $intelligence;
    public int $wisdom;
    public int $charisma;
    public int $hitpoints;

    static function modifier(int $constitution): int
    {
        return intval(floor(($constitution - 10) / 2));
    }

    static function ability(): int {
        $rolls = [];
        foreach (range(1,4) as $_) {
            array_push($rolls, rand(1, 6));
        }
        sort($rolls, SORT_NUMERIC);
        array_shift($rolls);
        return array_sum($rolls);
    }

    static function generate(): DnDCharacter {
        return new DnDCharacter();
    }

    public function __construct()
    {
        $this->strength = DnDCharacter::ability();
        $this->dexterity = DnDCharacter::ability();
        $this->constitution = DnDCharacter::ability();
        $this->intelligence = DnDCharacter::ability();
        $this->wisdom = DnDCharacter::ability();
        $this->charisma = DnDCharacter::ability();
        $this->hitpoints = DnDCharacter::modifier($this->constitution) + 10;
    }
}
