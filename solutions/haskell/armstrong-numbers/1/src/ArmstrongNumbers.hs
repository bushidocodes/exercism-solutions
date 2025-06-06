module ArmstrongNumbers (armstrong) where

to_digits :: Integral x => x -> [x]
to_digits 0 = []
to_digits x = x `mod` 10 : to_digits (x `div` 10)

armstrong :: Integral a => a -> Bool
armstrong a = do
  let digits = to_digits a
  let number_of_digits = length digits
  a == sum [d ^ number_of_digits | d <- digits]
  
