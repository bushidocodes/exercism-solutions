module Hamming (distance) where

distance :: String -> String -> Maybe Int
distance xs ys = if length xs /= length ys 
  then Nothing
  else Just ( sum [ if x /= y then 1 else 0 | (x, y) <- zip xs ys ] )
