<?php

declare(strict_types=1);

class PhoneNumber
{
    private string $clean = "";
    
    function __construct(string $dirty) {
        $digitCount = 0;
        $clean = "";

        for ($i = 0; $i < strlen($dirty); $i++){
            if (ctype_digit($dirty[$i])){
                $digitCount++;
                $clean = $clean . $dirty[$i];
            } else if (ctype_alpha($dirty[$i])) {
                throw new \InvalidArgumentException('letters not permitted');
            } else if ($dirty[$i] != '(' && $dirty[$i] != ')' && $dirty[$i] != ' ' && $dirty[$i] != '+' && $dirty[$i] != '-' && $dirty[$i] != '.'  ) {
                throw new \InvalidArgumentException('punctuations not permitted');
            }
        }

        if ($digitCount > 11)
            throw new \InvalidArgumentException('more than 11 digits');
        if ($digitCount < 10)
            throw new \InvalidArgumentException('incorrect number of digits');

        if ($digitCount == 11 && substr($clean, 0, 1) != '1')
            throw new \InvalidArgumentException('11 digits must start with 1');

        $areaCode = $digitCount == 11 ? substr($clean, 1, 3) : substr($clean, 0, 3);
        $exchangeCode = $digitCount == 11 ? substr($clean, 4, 3) : substr($clean, 3, 3);

        if (substr($areaCode, 0, 1) == '0')
            throw new \InvalidArgumentException('area code cannot start with zero');
        if (substr($areaCode, 0, 1) == '1')
            throw new \InvalidArgumentException('area code cannot start with one');
        if (substr($exchangeCode, 0, 1) == '0')
            throw new \InvalidArgumentException('exchange code cannot start with zero');
        if (substr($exchangeCode, 0, 1) == '1')
            throw new \InvalidArgumentException('exchange code cannot start with one');
      
        $this->clean = substr($clean, 0, 1) == '1' ? substr($clean, 1) : $clean;
    }

    public function number(): string
    {
        return $this->clean;
    }
}
