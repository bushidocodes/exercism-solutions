from enum import Enum

class Direction(Enum):
    NORTH = 0
    EAST = 1
    SOUTH = 2
    WEST = 3

# expose constants for backwards compatibility and immutability
NORTH = Direction.NORTH
EAST = Direction.EAST
SOUTH = Direction.SOUTH
WEST = Direction.WEST


class Robot:
    def __init__(self, direction=NORTH, x_pos=0, y_pos=0):
        self.direction_idx = direction.value
        self.x_pos = x_pos
        self.y_pos = y_pos

    directions = [NORTH, EAST, SOUTH, WEST]

    @property
    def direction(self):
        return Robot.directions[self.direction_idx]

    @property
    def coordinates(self):
        return (self.x_pos, self.y_pos)

    def move(self, instructions):
        for instruction in instructions:
            if instruction == "R":
                self.direction_idx = (self.direction_idx + 1) % 4
            elif instruction == "L":
                self.direction_idx = (self.direction_idx - 1) % 4
            elif instruction == "A":
                match Robot.directions[self.direction_idx]:
                    case Direction.NORTH:
                        self.y_pos += 1
                    case Direction.SOUTH:
                        self.y_pos -= 1
                    case Direction.EAST:
                        self.x_pos += 1
                    case Direction.WEST:
                        self.x_pos -= 1
                    case _:
                        pass
            else:
                raise ValueError("Invalid instruction")