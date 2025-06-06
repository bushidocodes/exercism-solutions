module Triangle (TriangleType(..), triangleType) where

import Data.List

data TriangleType = Equilateral
                  | Isosceles
                  | Scalene
                  | Illegal
                  deriving (Eq, Show)

triangleType :: (Num a, Ord a) => a -> a -> a -> TriangleType
triangleType a b c
  | s + m <= l                 = Illegal
  | a == b && b == c           = Equilateral
  | a == b || b == c || a == c = Isosceles
  | a /= b && b /= c && a /= c = Scalene
  where 
    [s,m,l] = sort [a,b,c]
