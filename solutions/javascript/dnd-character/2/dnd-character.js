export const abilityModifier = (score) => {
  if (score < 3) throw new Error("Ability scores must be at least 3");
  if (score > 18) throw new Error("Ability scores can be at most 18");
  return Math.floor(score / 2) - 5;
};

export class Character {
  static rollAbility() {
    // Roll four dice and sort
    const rolls = [...Array(4)].map((_) => Math.floor(Math.random() * 6) + 1).sort((a,b) => b - a);

    // Drop the lowest roll
    rolls.pop();

    return rolls.reduce((acc, cur) => acc + cur, 0);
  }

  #strength = Character.rollAbility();
  #dexterity = Character.rollAbility();
  #constitution = Character.rollAbility();
  #intelligence = Character.rollAbility();
  #wisdom = Character.rollAbility();
  #charisma = Character.rollAbility();
  #hitpoints = abilityModifier(this.#constitution) + 10;

  get strength() {
    return this.#strength;
  }

  get dexterity() {
    return this.#dexterity;
  }

  get constitution() {
    return this.#constitution;
  }

  get intelligence() {
    return this.#intelligence;
  }

  get wisdom() {
    return this.#wisdom;
  }

  get charisma() {
    return this.#charisma;
  }

  get hitpoints() {
    return this.#hitpoints;
  }
}
