export const transform = (pointToLetterList) => {
  let letterToPoint = {};

  for (let point of Object.keys(pointToLetterList)) {
    for (let letter of pointToLetterList[point]) {
      letterToPoint[letter.toLowerCase()] = Number(point);
    }
  }

  return letterToPoint;
};
