export const proverb = (...args) => {
  let qualifier = "";
  if (typeof args[args.length - 1] == "object") {
    qualifier = args[args.length - 1].qualifier + " ";
    args.pop();
  }
  return args
    .map((elem, idx, arr) => {
      if (idx != arr.length - 1)
        return `For want of a ${elem} the ${arr[idx + 1]} was lost.`;
      else return `And all for the want of a ${qualifier}${args[0]}.`;
    })
    .join("\n");
};
