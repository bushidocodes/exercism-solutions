enum Allergen {
  Eggs = "eggs",
  Peanuts = "peanuts",
  Shellfish = "shellfish",
  Strawberries = "strawberries",
  Tomatoes = "tomatoes",
  Chocolate = "chocolate",
  Pollen = "pollen",
  Cats = "cats"
}

const allergenToBitMask: Record<Allergen,number> = {
  [Allergen.Eggs]:           0b00000001,
  [Allergen.Peanuts]:        0b00000010,
  [Allergen.Shellfish]:      0b00000100,
  [Allergen.Strawberries]:   0b00001000,
  [Allergen.Tomatoes]:       0b00010000,
  [Allergen.Chocolate]:      0b00100000,
  [Allergen.Pollen]:         0b01000000,
  [Allergen.Cats]:           0b10000000,
}

export class Allergies {
  private allergenIndex: number = 0;
  
  constructor(allergenIndex: number) {
    this.allergenIndex = allergenIndex;
  }

  public list(): string[] {
    return Object.keys(allergenToBitMask)
      .filter(allergen => (this.allergenIndex & allergenToBitMask[allergen as Allergen]) === allergenToBitMask[allergen as Allergen])
  }

  public allergicTo(allergen: Allergen): boolean {
    return (this.allergenIndex & allergenToBitMask[allergen]) === allergenToBitMask[allergen];
  }
}
