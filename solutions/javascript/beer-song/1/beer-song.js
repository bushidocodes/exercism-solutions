const bottleCountPhrase = (bottleCount) => {
  switch (bottleCount) {
    case 0:
      return "no more bottles";
    case 1:
      return "1 bottle";
    default:
      return `${bottleCount} bottles`;
  }
}

export const recite = (initialBottlesCount, takeDownCount) => {
  let stanzas = [];

  for (let i = 0; i < takeDownCount; i++){
    let verse = initialBottlesCount - i;

    if (verse == 0) {
      stanzas.push("No more bottles of beer on the wall, no more bottles of beer.");
      stanzas.push("Go to the store and buy some more, 99 bottles of beer on the wall.");
    } else {
      stanzas.push(`${bottleCountPhrase(verse)} of beer on the wall, ${bottleCountPhrase(verse)} of beer.`);
      stanzas.push( `Take ${verse == 1 ? "it" : "one"} down and pass it around, ${bottleCountPhrase(verse - 1)} of beer on the wall.`);
    }
    if (i < takeDownCount - 1) stanzas.push("");  
  }
  return stanzas;
};
