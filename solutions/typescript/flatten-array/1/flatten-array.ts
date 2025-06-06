export function flatten(nested: number[]) : number[] {
  return nested.flat(Infinity).filter(elem => elem !== null && elem !== undefined);
}
