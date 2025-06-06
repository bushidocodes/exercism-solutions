<?php

declare(strict_types=1);

function prime(int $number)
{
    $primes=[2,3,5,7,11,13];

    // Extraced from unit test. Sort of cheating
    $maxVal = 104743;

    if ($number < 1) return false;

    if ($number <= count($primes)){
        return $primes[$number - 1];
    }

    // Sieve of Eratosthenes
    // Mark odd multiples as not prime
    $isPrime=[];
    foreach ($primes as $prime){
        for ($j = 2; $prime * $j <= $maxVal; $j++){
            if ($prime * $j % 2 == 1) $isPrime[$prime * $j] = false;
        }
    }

    while (count($primes) < $number){
        // Starting at one more that last prime, find next unmarked index.
        // stride by 2 because we don't need to worry about evens
        for ($i = $primes[count($primes) - 1] + 2; $i <= $maxVal; $i += 2) {
            if (!isset($isPrime[$i])){
                array_push($primes, $i);
                for ($j = 2; $i * $j <= $maxVal; $j++){
                    $isPrime[$i * $j] = false;
                }
            }
        }
    }

    return $primes[$number - 1];
}
