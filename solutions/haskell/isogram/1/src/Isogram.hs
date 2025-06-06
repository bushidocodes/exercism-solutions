module Isogram (isIsogram) where

import Data.Char
import Data.List 

isIsogram :: String -> Bool
isIsogram text = 
  let lowerLetters = (map toLower) . (filter isLetter) $ text
  in length lowerLetters == (length . nub $ lowerLetters)