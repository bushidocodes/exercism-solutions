<?php

declare(strict_types=1);

class BeerSong
{
    public function verse(int $number): string
    {
        if ($number > 2){
            $oneLess = $number - 1;
            return <<<"END"
            $number bottles of beer on the wall, $number bottles of beer.
            Take one down and pass it around, $oneLess bottles of beer on the wall.

            END;
        } else if ($number == 2) {
            $oneLess = $number - 1;
            return <<<"END"
            $number bottles of beer on the wall, $number bottles of beer.
            Take one down and pass it around, $oneLess bottle of beer on the wall.

            END;
        } else if ($number == 1) {
            return <<<"END"
            $number bottle of beer on the wall, $number bottle of beer.
            Take it down and pass it around, no more bottles of beer on the wall.

            END;
        } else {
            return <<<'END'
            No more bottles of beer on the wall, no more bottles of beer.
            Go to the store and buy some more, 99 bottles of beer on the wall.
            END;
        }
    }

    public function verses(int $start, int $finish): string
    {
        return implode("\n", array_map(array($this, 'verse'), range($start, $finish)));
    }

    public function lyrics(): string
    {
        return $this->verses(99, 0);
    }
}
