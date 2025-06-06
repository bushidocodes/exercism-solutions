
// Uses backtracking to count squares clockwise from a start coordinate
function countFromTopLeft(rows, startX, startY) {
  let squareCount = 0;

  // Right
  for (let x = startX + 1; x < rows[startY].length && ['-', '+'].includes(rows[startY].charAt(x)); x++) {
    if (rows[startY].charAt(x) === '+') {
      // Down
      for (let y = startY + 1; y < rows.length && ['|', '+'].includes(rows[y].charAt(x)); y++) {
        if (rows[y].charAt(x) === '+') {
          // Left
          for (let backX = x - 1; backX >= startX && ['-', '+'].includes(rows[y].charAt(backX)); backX--) {
            if (backX == startX && rows[y].charAt(backX) === '+') {
              // Up
              for (let backY = y - 1; backY >= startY && ['|', '+'].includes(rows[backY].charAt(backX)); backY--) {
                // We can assume that the top left is '+' or we wouldn't have called this function
                if (backY == startY) {
                  squareCount++;
                }
              }
            }
          }
        }
      }
    }
  }
  
  return squareCount;
}

export function count(rows) {
  if (!rows || rows.length === 0) return 0;

  let count = 0;

  for (let y = 0; y < rows.length; y++){
    for (let x = 0; x < rows[y].length; x++) {
      if (rows[y].charAt(x) === '+') {
        count += countFromTopLeft(rows, x, y);
      }
    }
  }

  return count;
}
