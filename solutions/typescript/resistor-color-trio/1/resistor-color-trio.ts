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

export function decodedResistorValue(resistorColors: ResistorColor[]) {
  let [first, second, third] = resistorColors.map(color => resistorValues[color]);

  let resistorValue = (first * 10 ** (third + 1)) + (second * 10 ** (third));
  
  return  resistorValue >= 1000 ? `${resistorValue / 1000} kiloohms` : `${resistorValue} ohms`;
}
