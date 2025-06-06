function findSlice(haystack: number[], needle: number, start: number = 0, end: number = haystack.length): number {
  let mid: number = start + Math.floor((end - start) / 2);
  if (needle === haystack[mid]) return mid;
  else if (mid === start) throw new Error("Value not in array");
  else if (needle < haystack[mid]) return findSlice(haystack, needle, start, mid);
  else return findSlice(haystack, needle, mid + 1, end);
}

export function find(haystack: number[], needle: number): number | never {
  return findSlice(haystack, needle);
}
