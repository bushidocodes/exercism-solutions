export const annotate = (input) => {
  let matrix = input.map(row => row.split(""));

  if (matrix.some(row => row.length != matrix[0].length)) throw new Error("All rows expected to be of equal length");

  for (let i = 0; i < matrix.length; i++){
    for (let j = 0; j < matrix[i].length; j++){
      if (matrix[i][j] == ' '){
        let mines = 0;
        let hasUp = i - 1 >= 0;
        let hasDown = i + 1 < matrix.length;      
        let hasLeft = j - 1 >= 0;
        let hasRight = j + 1 < matrix[0].length;
        
        if (hasUp && hasLeft && matrix[i-1][j-1] == '*') mines++;
        if (hasUp && matrix[i-1][j] == '*') mines++;
        if (hasUp && hasRight && matrix[i-1][j+1] == '*') mines++;
        if (hasLeft && matrix[i][j-1] == '*') mines++;
        if (hasRight && matrix[i][j+1] == '*') mines++;
        if (hasDown && hasLeft && matrix[i+1][j-1] == '*') mines++;
        if (hasDown && matrix[i+1][j] == '*') mines++;
        if (hasDown && hasRight && matrix[i+1][j+1] == '*') mines++;

        if (mines > 0) matrix[i][j]=mines;
      }
    }
  }

  return matrix.map(row => row.join(""));
};
