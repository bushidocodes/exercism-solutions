export function transpose(rows: string[]) {
  let transposed: string[] = [];

  let longestRow = rows.reduce((largest, cur) => cur.length > largest ? cur.length : largest, 0);

  for (let i = 0; i < longestRow; i++){
    for (let j = 0; j < rows.length; j++){
      if (!transposed[i]) transposed[i] = "";
      let char = rows[j].charAt(i);
      if (char == "") char = " ";
      transposed[i] += char;
    }
  }

  if (transposed.length > 0){
    transposed[transposed.length - 1] = transposed[transposed.length - 1].trimEnd();
  }

  return transposed;
}
