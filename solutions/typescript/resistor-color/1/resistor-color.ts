enum ResistorColor {
  Black = "black",
  Brown = "brown",
  Red = "red",
  Orange = "orange",
  Yellow = "yellow",
  Green = "green",
  Blue = "blue",
  Violet = "violet",
  Grey = "grey",
  White = "white",
}

const resistorValues: Record<ResistorColor, number> = {
  [ResistorColor.Black]: 0,
  [ResistorColor.Brown]: 1,
  [ResistorColor.Red]: 2,
  [ResistorColor.Orange]: 3,
  [ResistorColor.Yellow]: 4,
  [ResistorColor.Green]: 5,
  [ResistorColor.Blue]: 6,
  [ResistorColor.Violet]: 7,
  [ResistorColor.Grey]: 8,
  [ResistorColor.White]: 9,
};

export const colorCode = (color: ResistorColor) => resistorValues[color];

export const COLORS = Object.values(ResistorColor);
