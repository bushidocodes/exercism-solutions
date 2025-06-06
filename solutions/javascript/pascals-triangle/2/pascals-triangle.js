export const rows = (count) => {
  const triangle = [];
  
  if (count > 0) triangle.push([1]);
  
  for (let rowIdx = 1; rowIdx < count; rowIdx++) {
    const row = [];
    for (let cellIdx = 0; cellIdx <= rowIdx; cellIdx++) {
      if (cellIdx == 0 || cellIdx == rowIdx) row.push(1);
      else {
        row.push(
          triangle[rowIdx - 1][cellIdx - 1] + triangle[rowIdx - 1][cellIdx]
        );
      }
    }
    triangle.push(row);
  }

  return triangle;
};