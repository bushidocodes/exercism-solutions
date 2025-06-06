export const flatten = (nested) => {
  return nested.reduce((acc, elem) => {
    if (elem === undefined || elem == null) return acc;
    if (elem instanceof Array == false) acc.push(elem);
    else acc.push(...flatten(elem));
    return acc;
  }, []);
};
