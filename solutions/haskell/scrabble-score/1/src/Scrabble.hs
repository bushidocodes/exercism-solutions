module Scrabble (scoreLetter, scoreWord) where

import Data.Char

scoreLetter :: Char -> Integer
scoreLetter c
  | c `elem` "AEIOULNRST" = 1
  | c `elem` "DG" = 2
  | c `elem` "BCMP" = 3
  | c `elem` "FHVWY" = 4
  | c `elem` "K" = 5
  | c `elem` "JX" = 8
  | c `elem` "QZ" = 10
  | isLower c = scoreLetter $ toUpper c
  | otherwise = 0

scoreWord :: String -> Integer
scoreWord word = foldl (+) 0 (map scoreLetter word)
