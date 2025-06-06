module Yacht (yacht, Category(..)) where

import Data.List
import Data.Maybe

data Category = Ones
              | Twos
              | Threes
              | Fours
              | Fives
              | Sixes
              | FullHouse
              | FourOfAKind
              | LittleStraight
              | BigStraight
              | Choice
              | Yacht

yacht :: Category -> [Int] -> Int
yacht Ones           dice = sum $ filter (== 1) dice
yacht Twos           dice = sum $ filter (== 2) dice
yacht Threes         dice = sum $ filter (== 3) dice
yacht Fours          dice = sum $ filter (== 4) dice
yacht Fives          dice = sum $ filter (== 5) dice
yacht Sixes          dice = sum $ filter (== 6) dice
yacht FullHouse      dice = 
  if maximum (map length (group (sort dice))) == 3 
    then sum dice
    else 0
yacht FourOfAKind    dice = do
  let candidate = Data.List.find (\g -> length g >= 4) (Data.List.group . Data.List.sort $ dice)
  if isJust candidate then sum (take 4 $ fromJust candidate) else 0
yacht LittleStraight dice = if (sort dice) == [1,2,3,4,5] then 30 else 0
yacht BigStraight    dice = if (sort dice) == [2,3,4,5,6] then 30 else 0
yacht Choice         dice = sum dice
yacht Yacht          dice = if length (nub dice) == 1 then 50 else 0