export const compute = (left, right) => {
  // Spec specifically checks this degenerate case.
  // IMO, this is inconsistent given the fact that empty strands can throw errors
  if (left.length == 0 && right.length == 0) return 0;

  if (left.length == 0) throw new Error("left strand must not be empty");
  if (right.length == 0) throw new Error("right strand must not be empty");
  if (right.length != left.length)
    throw new Error("left and right strands must be of equal length");

  return left
    .split("")
    .map((v, i) => (v != right[i] ? 1 : 0))
    .reduce((acc, cur) => acc + cur, 0);
};
