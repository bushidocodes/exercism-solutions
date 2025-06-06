<?php

declare(strict_types=1);

class SimpleCipher
{
    public string $key;

    public function __construct(string $key = null)
    {
        if ($key === '') throw new InvalidArgumentException("Keys must be lowercase ASCII characters");

        if ($key == null){
            for ($i = 0; $i < 100; $i++){
                $key = $key . chr(rand(ord('a'), ord('z')));
            }
        }

        // Validate that all key characters are lowercase
        $key_len = strlen($key);
        for ($i = 0; $i < $key_len; $i++){
            if (!ctype_lower($key[$i])) throw new InvalidArgumentException("Keys must be lowercase ASCII characters");
        }

        $this->key = $key;
    }

    public function encode(string $plainText): string
    {
        $cipherText = '';
        $plainTextLen = strlen($plainText);
        for ($i = 0; $i < $plainTextLen; $i++){
            $cipherText = $cipherText . chr( ord('a') + ((ord($plainText[$i]) - ord('a') + (ord($this->key[$i]) - ord('a'))) % 26));
        }

        return $cipherText;
    }

    public function decode(string $cipherText): string
    {
        $plainText = '';
        $cipherTextLen = strlen($cipherText);
        for ($i = 0; $i < $cipherTextLen; $i++){
            $offset = ord('z') - ord($this->key[$i]) + 1;
            $plainText = $plainText . chr( ord('a') + ((ord($cipherText[$i]) - ord('a') + $offset) % 26));
        }

        return $plainText;
    }
}
