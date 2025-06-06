module Robot
    ( Bearing(East,North,South,West)
    , bearing
    , coordinates
    , mkRobot
    , move
    ) where

data Bearing = North
             | East
             | South
             | West
             deriving (Eq, Show)

data Robot = Robot { bearing :: Bearing, coordinates :: (Integer, Integer) } deriving (Show)

mkRobot :: Bearing -> (Integer, Integer) -> Robot
mkRobot direction coor = Robot { bearing=direction, coordinates=coor }

turnRight :: Robot -> Robot
turnRight Robot{bearing = b, coordinates=coor}
  | b == North = Robot {bearing=East,  coordinates=coor}
  | b == East  = Robot {bearing=South, coordinates=coor}
  | b == South = Robot {bearing=West,  coordinates=coor}
  | b == West  = Robot {bearing=North, coordinates=coor}

turnLeft :: Robot -> Robot
turnLeft Robot{bearing = b, coordinates=coor}
  | b == North = Robot {bearing=West, coordinates=coor}
  | b == West = Robot {bearing=South, coordinates=coor}
  | b == South = Robot {bearing=East, coordinates=coor}
  | b == East = Robot {bearing=North, coordinates=coor}

advance :: Robot -> Robot
advance Robot {bearing = b, coordinates = (x,y)}
  | b == North = Robot {bearing=North, coordinates=(x,   y+1)}
  | b == West  = Robot {bearing=West,  coordinates=(x-1, y  )}
  | b == South = Robot {bearing=South, coordinates=(x,   y-1)}
  | b == East  = Robot {bearing=East,  coordinates=(x+1, y)}

moveOne :: Robot -> Char -> Robot
moveOne robot c
  | c == 'R' = turnRight robot
  | c == 'L' = turnLeft robot
  | c == 'A' = advance robot
  | otherwise = error "Invalid command"

move :: Robot -> String -> Robot
move robot [] = robot
move robot (x:xs) = move (moveOne robot x) xs
