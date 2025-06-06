module ResistorColors (Color(..), value) where

data Color =
    Black
  | Brown
  | Red
  | Orange
  | Yellow
  | Green
  | Blue
  | Violet
  | Grey
  | White
  deriving (Eq, Show, Enum, Bounded)

bandvalue:: Color -> Int
bandvalue Black  = 0
bandvalue Brown  = 1
bandvalue Red    = 2
bandvalue Orange = 3
bandvalue Yellow = 4
bandvalue Green  = 5
bandvalue Blue   = 6
bandvalue Violet = 7
bandvalue Grey   = 8
bandvalue White  = 9
bandbalue _      = error "Invalid Color"

value :: (Color, Color) -> Int
value (a, b) = (10 * bandvalue a) + bandvalue b
