module Luhn (isValid) where

import Data.Char

isValid' :: [Int] -> Bool
isValid' n = (
  sum . 
  map (\v -> if v > 9 then v - 9 else v) $ 
    map (\(b, v) -> if b then 2 * v else v) $ 
      (zip (cycle [False, True]) (reverse n))) `rem` 10 == 0


isValid :: String -> Bool
isValid n = 
  let digits = (map (\x -> (ord x - ord '0')) $ filter isDigit n)
  in length digits > 1 && isValid' digits

