export const findInSlice = (haystack, start, end, needle) => {
  if (start > end) throw new Error('Value not in array');
  
  let mid = start + Math.floor((end - start) / 2);
  
  /* Base Case */
  if (needle === haystack[mid]) return mid;
  
  /* Recurse */
  if (needle < haystack[mid]) {
    return findInSlice(haystack, start, mid - 1, needle);
  }
  else if (needle > haystack[mid]) {
    return findInSlice(haystack, mid + 1, end, needle);
  }
}

export const find = (haystack, needle) => findInSlice(haystack, 0, haystack.length - 1, needle);
