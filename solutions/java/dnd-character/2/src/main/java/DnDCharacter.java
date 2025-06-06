import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.stream.IntStream;

class DnDCharacter {
    static private int rollD6() {
        return Double.valueOf(Math.floor(Math.random() * 6) + 1).intValue();
    }

    static int ability() {
        return IntStream.of(DnDCharacter.rollD6(), DnDCharacter.rollD6(), DnDCharacter.rollD6(), DnDCharacter.rollD6())
            .sorted()
            .skip(1)
            .sum();
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
