module SecretHandshake (handshake) where

import Data.Bits

handshake :: Int -> [String]
handshake n
  | n .&. 0x10 == 0x10 = reverse (handshake $ n `xor` 0x10) -- Must be outmost call
  | n .&. 0x1 == 0x1 = "wink" : (handshake $ n `xor` 0x1)
  | n .&. 0x2 == 0x2 = "double blink" : (handshake $ n `xor` 0x2)
  | n .&. 0x4 == 0x4 = "close your eyes" : (handshake $ n `xor` 0x4)
  | n .&. 0x8 == 0x8 = "jump" : (handshake $ n `xor` 0x8)
  | otherwise = []
