const allergyFlags = {
  eggs: 1,
  peanuts: 2,
  shellfish: 4,
  strawberries: 8,
  tomatoes: 16,
  chocolate: 32,
  pollen: 64,
  cats: 128,
};

export class Allergies {
  #flags = 0;
  constructor(flags) {
    this.#flags = flags;
  }

  list() {
    return Object.keys(allergyFlags).filter((allergen) =>
      this.allergicTo(allergen)
    );
  }

  allergicTo(allergen) {
    return !!(allergyFlags[allergen] & this.#flags);
  }
}
