export const square = (space) => {
  if (space < 1 || space > 64) throw "square must be between 1 and 64";
  return BigInt.asUintN(64, 1n << (BigInt(space) - 1n));
};

export const total = () => BigInt.asUintN(64, ~0n);
