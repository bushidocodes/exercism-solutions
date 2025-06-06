export class ResistorColor {
  static COLOR_VALUES: Record<string, number> = {
    black: 0,
    brown: 1,
    red: 2,
    orange: 3,
    yellow: 4,
    green: 5,
    blue: 6,
    violet: 7,
    grey: 8,
    white: 9,
  };
  static MIN_COLORS: number = 2;
  static MAX_COLORS: number = 2;

  private colors: string[];

  constructor(colors: string[]) {
    if (colors.length < ResistorColor.MIN_COLORS)
      throw new Error("At least two colors need to be present");
    this.colors = colors;
  }

  value = (): number => {
    return this.colors
      .slice(0, ResistorColor.MAX_COLORS)
      .map((e) => ResistorColor.COLOR_VALUES[e])
      .reduce((acc, val) => acc * 10 + val, 0);
  };
}
