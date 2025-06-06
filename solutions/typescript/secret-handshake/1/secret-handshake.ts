export function commands(input: number): string[] {
  let result = []
  
  input &= 0b00011111;
  if ((input & 0b1) === 0b1) result.push("wink");
  if ((input & 0b10) === 0b10) result.push("double blink");
  if ((input & 0b100) === 0b100) result.push("close your eyes");
  if ((input & 0b1000) === 0b1000) result.push("jump");
  if ((input & 0b10000) === 0b10000) result.reverse();
  
  return result;
}
