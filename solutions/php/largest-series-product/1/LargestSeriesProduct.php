<?php

declare(strict_types=1);

class Series
{
    private $digits = [];
    private $digits_len = 0;

    function __construct(string $digits)
    {
        if (strlen($digits) > 0){
            $chars = str_split($digits);
            foreach($chars as $char){
                if (!ctype_digit($char)) throw new InvalidArgumentException();
            }
    
            $this->digits = array_map(function($e){return intval($e);}, $chars);
            $this->digits_len = count($this->digits);
        }
    }

    public function largestProduct(int $span): int
    {
        if ($span > $this->digits_len || $span < 0) throw new InvalidArgumentException();

        $largest = PHP_INT_MIN;
        for ($i = 0; $i + $span - 1 < count($this->digits); $i++){
            $sum = array_product(array_slice($this->digits, $i, $span));
            if ($sum > $largest) $largest = $sum;
        }

        return $largest;
    }
}
