const earthYearSecs = 31557600;
const planetaryYears = {
  mercury: 0.2408467,
  venus: 0.61519726,
  earth: 1.0,
  mars: 1.8808158,
  jupiter: 11.862615,
  saturn: 29.447498,
  uranus: 84.016846,
  neptune: 164.79132,
};

export const age = (planet, ageSec) => {
  // fixed point is returned as a string
  let resultStr = (ageSec / earthYearSecs / planetaryYears[planet]).toFixed(2);
  // so cast back to a number
  return +resultStr;
};
