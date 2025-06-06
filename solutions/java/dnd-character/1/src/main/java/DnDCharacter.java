import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.ArrayList;

class DnDCharacter {
    static private int D6 = 6;

    static int ability() {
        ArrayList<Integer> rolls = new ArrayList<Integer>();

        // Roll 4 D6
        final int ROLLS = 4;
        for (int i = 0; i < ROLLS; i++) {
            rolls.add(Double.valueOf(Math.floor((Math.random() * D6) + 1)).intValue());
        }

        // Drop the Lowest
        int smallest = Integer.MAX_VALUE;
        int smallestIndex = -1;
        for (int i = 0; i < ROLLS; i++) {
            if (rolls.get(i) < smallest) {
                smallest = rolls.get(i);
                smallestIndex = i;
            }
        }
        rolls.remove(smallestIndex);

        // Return the remaining three largest
        return rolls.stream().mapToInt(Integer::intValue).sum();
    }

    static int modifier(int input) {
        return BigDecimal.valueOf(Math.floor((input - 10) / 2f)).setScale(0, RoundingMode.FLOOR).intValue();
    }

    private int strength = DnDCharacter.ability();
    private int dexterity = DnDCharacter.ability();
    private int constitution = DnDCharacter.ability();
    private int intelligence = DnDCharacter.ability();
    private int wisdom = DnDCharacter.ability();
    private int charisma = DnDCharacter.ability();
    private int hitPoints = 10 + DnDCharacter.modifier(this.constitution);

    int getStrength() {
        return this.strength;
    }

    int getDexterity() {
        return this.dexterity;
    }

    int getConstitution() {
        return this.constitution;
    }

    int getIntelligence() {
        return this.intelligence;
    }

    int getWisdom() {
        return this.wisdom;
    }

    int getCharisma() {
        return this.charisma;
    }

    int getHitpoints() {
        return this.hitPoints;
    }

}
