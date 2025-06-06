function rolld6(): number {
  return 1 + Math.floor(Math.random() * 6);
} 

export class DnDCharacter {
  strength = DnDCharacter.generateAbilityScore();
  dexterity = DnDCharacter.generateAbilityScore();
  constitution = DnDCharacter.generateAbilityScore();
  intelligence = DnDCharacter.generateAbilityScore();
  wisdom = DnDCharacter.generateAbilityScore();
  charisma = DnDCharacter.generateAbilityScore();
  hitpoints = 10 + DnDCharacter.getModifierFor(this.constitution);
  
  public static generateAbilityScore(): number {
    return [rolld6(), rolld6(), rolld6(), rolld6()]
      .sort()
      .slice(0,3)
      .reduce((sum, roll) => sum + roll, 0);
  }

  public static getModifierFor(abilityValue: number): number {
    return Math.floor((abilityValue - 10) / 2);
  }
}
