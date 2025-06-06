module Hamming (distance) where

distance :: String -> String -> Maybe Int
distance xs ys = if length xs /= length ys 
  then Nothing
  else Just ( sum [ if fst p /= snd p then 1 else 0 | p <- zip xs ys ] )
