module Pangram (isPangram) where

import Data.Char
import Data.List

isPangram :: String -> Bool
isPangram text = (length . nub . (map toLower) . (filter isAscii) . (filter isAlpha) $ text) == 26
