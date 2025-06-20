// @ts-check

/**
 * Calculates the sum of the two input arrays.
 *
 * @param {number[]} array1
 * @param {number[]} array2
 * @returns {number} sum of the two arrays
 */
export function twoSum(array1, array2) {
  return Number(array1.map(e => String(e)).join("")) + Number(array2.map(e => String(e)).join(""))
}

/**
 * Checks whether a number is a palindrome.
 *
 * @param {number} value
 * @returns {boolean}  whether the number is a palindrome or not
 */
export function luckyNumber(value) {
  let digitsAsChars = String(value).split("");
  digitsAsChars.reverse();
  let reversedValue = Number(digitsAsChars.join(""));
  return value === reversedValue;
}

/**
 * Determines the error message that should be shown to the user
 * for the given input value.
 *
 * @param {string|null|undefined} input
 * @returns {string} error message
 */
export function errorMessage(input) {
  if (!input) {
    return "Required field";
  } else if (Number(input) == 0 || Number.isNaN(Number(input))) {
    return "Must be a number besides 0";
  }
  
  return "";
}
