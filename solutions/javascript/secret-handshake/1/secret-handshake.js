export const commands = (input) => {
  let result = [];
  if (input & 1) result.push("wink");
  if (input & 2) result.push("double blink");
  if (input & 4) result.push("close your eyes");
  if (input & 8) result.push("jump");
  if (input & 16) result.reverse();

  return result;
};
