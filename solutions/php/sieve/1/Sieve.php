<?php

declare(strict_types=1);

function sieve(int $number): array
{
    $isNotPrime = [];
    $isNotPrime[1] = true; 
    $isNotPrime[1] = true; 

    if ($number >= 2){
        foreach(range(2,$number) as $cur){
            if (!array_key_exists($cur, $isNotPrime)) $isNotPrime[$cur] = false;

            if (!$isNotPrime[$cur]){
                for ($i = 2; $i * $cur <= $number; $i++){
                    $isNotPrime[$i * $cur] = true;
                }
            }
        }
    }

    return array_keys(array_filter($isNotPrime, function($v, $k){return !$v;}, ARRAY_FILTER_USE_BOTH ));
}
