module Raindrops (convert) where

convert :: Int -> String
convert n = do
  let sounds = (if n `mod` 3  == 0 then "Pling" else "") ++ 
               (if n `mod` 5  == 0 then "Plang" else "") ++ 
               (if n `mod` 7  == 0 then "Plong" else "")
  if sounds /= "" then sounds else show n
