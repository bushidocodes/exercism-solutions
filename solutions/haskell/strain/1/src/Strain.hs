module Strain (keep, discard) where

discard :: (a -> Bool) -> [a] -> [a]
discard p xs = keep (not . p) xs

keep :: (a -> Bool) -> [a] -> [a]
keep _ [] = []
keep p (head:tail)
  | p head    = head : keep p tail 
  | otherwise = keep p tail
