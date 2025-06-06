import java.util.stream.Collectors;
import java.util.stream.IntStream;

class House {
    public String verse(int verseNumber) {
        if (verseNumber < 1 || verseNumber > 12)
            return "";

        String result = "This is ";

        switch (verseNumber) {
            case 12:
                result += "the horse and the hound and the horn that belonged to ";
            case 11:
                result += "the farmer sowing his corn that kept ";
            case 10:
                result += "the rooster that crowed in the morn that woke ";
            case 9:
                result += "the priest all shaven and shorn that married ";
            case 8:
                result += "the man all tattered and torn that kissed ";
            case 7:
                result += "the maiden all forlorn that milked ";
            case 6:
                result += "the cow with the crumpled horn that tossed ";
            case 5:
                result += "the dog that worried ";
            case 4:
                result += "the cat that killed ";
            case 3:
                result += "the rat that ate ";
            case 2:
                result += "the malt that lay in ";
            case 1:
                result += "the house that Jack built.";
        }
        return result;
    }

    public String verses(int startVerse, int endVerse) {
        return IntStream.range(startVerse, endVerse + 1).mapToObj(i -> this.verse(i)).collect(Collectors.joining("\n"));
    }

    public String sing() {
        return this.verses(1, 12);
    }
}