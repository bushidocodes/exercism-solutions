export function verse(index: number): string {
  if (index > 2){
    return `${index} bottles of beer on the wall, ${index} bottles of beer.
Take one down and pass it around, ${index - 1} bottles of beer on the wall.
`;
  } else if (index == 2){
    return `${index} bottles of beer on the wall, ${index} bottles of beer.
Take one down and pass it around, 1 bottle of beer on the wall.
`;
  } else if (index == 1) {
        return `${index} bottle of beer on the wall, ${index} bottle of beer.
Take it down and pass it around, no more bottles of beer on the wall.
`;
  } else {
    return `No more bottles of beer on the wall, no more bottles of beer.
Go to the store and buy some more, 99 bottles of beer on the wall.
`;
  }
}

export function sing(
  initialBottlesCount: number = 99,
  takeDownCount: number = 0
): string {
  return new Array(initialBottlesCount - takeDownCount + 1)
    .fill(takeDownCount)
    .map((e: number, i) => e + i)
    .reverse()
    .map(e => verse(e))
    .join("\n");
}
