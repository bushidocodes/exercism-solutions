export function count(phrase: string): Map<string,number> {
  return phrase.trim().split(/\s+/).map(word => word.toLowerCase()).reduce((acc: Map<string,number>, cur) => {
    acc.set(cur, (acc.get(cur) ?? 0) + 1);
    return acc;
  }, new Map())
}
