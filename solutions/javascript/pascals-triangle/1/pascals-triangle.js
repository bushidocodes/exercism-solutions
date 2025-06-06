export const rows = (count) => {
  const triangle = [];

  for (let rowIdx = 0; rowIdx < count; rowIdx++) {
    if (rowIdx == 0) triangle.push([1]);
    else {
      let buffer = [];
      for (let cellIdx = 0; cellIdx <= rowIdx; cellIdx++) {
        if (cellIdx == 0 || cellIdx == rowIdx) buffer.push(1);
        else {
          buffer.push(
            triangle[rowIdx - 1][cellIdx - 1] + triangle[rowIdx - 1][cellIdx]
          );
        }
      }
      triangle.push(buffer);
    }
  }
  return triangle;
};
