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

-- Started with this... This seems to be redundant based on enum
-- I haven't yet read the algebraic data types chapter, so not sort of just guessing what's going on
-- It seems that Haskell enums default to starting at 1
-- bandvalue:: Color -> Int
-- bandvalue Black  = 0
-- bandvalue Brown  = 1
-- bandvalue Red    = 2
-- bandvalue Orange = 3
-- bandvalue Yellow = 4
-- bandvalue Green  = 5
-- bandvalue Blue   = 6
-- bandvalue Violet = 7
-- bandvalue Grey   = 8
-- bandvalue White  = 9
-- bandbalue _      = error "Invalid Color"

value :: (Color, Color) -> Int
value (a, b) = (10 * fromEnum a) + fromEnum b
