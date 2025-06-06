export const transform = (pointToLetterList) => {
  const letterToPoint = {};

  for (const point of Object.keys(pointToLetterList)) {
    for (const letter of pointToLetterList[point]) {
      letterToPoint[letter.toLowerCase()] = Number(point);
    }
  }

  return letterToPoint;
};
