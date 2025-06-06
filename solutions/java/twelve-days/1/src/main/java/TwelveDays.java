import java.util.ArrayList;
import java.util.HashMap;

class TwelveDays {

    private static HashMap<Integer, String> possessive;
    private static ArrayList<String> gifts;

    static {
        TwelveDays.possessive = new HashMap<Integer, String>();
        TwelveDays.possessive.put(1, "first");
        TwelveDays.possessive.put(2, "second");
        TwelveDays.possessive.put(3, "third");
        TwelveDays.possessive.put(4, "fourth");
        TwelveDays.possessive.put(5, "fifth");
        TwelveDays.possessive.put(6, "sixth");
        TwelveDays.possessive.put(7, "seventh");
        TwelveDays.possessive.put(8, "eighth");
        TwelveDays.possessive.put(9, "ninth");
        TwelveDays.possessive.put(10, "tenth");
        TwelveDays.possessive.put(11, "eleventh");
        TwelveDays.possessive.put(12, "twelfth");

        TwelveDays.gifts = new ArrayList<String>();
        TwelveDays.gifts.add("twelve Drummers Drumming");
        TwelveDays.gifts.add("eleven Pipers Piping");
        TwelveDays.gifts.add("ten Lords-a-Leaping");
        TwelveDays.gifts.add("nine Ladies Dancing");
        TwelveDays.gifts.add("eight Maids-a-Milking");
        TwelveDays.gifts.add("seven Swans-a-Swimming");
        TwelveDays.gifts.add("six Geese-a-Laying");
        TwelveDays.gifts.add("five Gold Rings");
        TwelveDays.gifts.add("four Calling Birds");
        TwelveDays.gifts.add("three French Hens");
        TwelveDays.gifts.add("two Turtle Doves");
        TwelveDays.gifts.add("a Partridge in a Pear Tree");
    }

    String listGifts(int verseNumber) {
        String result = "";
        if (verseNumber == 1) {
            result = TwelveDays.gifts.get(11);
        } else if (verseNumber >= 2) {
            String[] gifts = (String[]) TwelveDays.gifts.subList(12 - verseNumber, 11)
                    .toArray(new String[verseNumber - 1]);
            result = String.join(", ", gifts);
            String[] lastTwo = { result, TwelveDays.gifts.get(11) };
            result = String.join(", and ", lastTwo);
        }
        return result;
    }

    String verse(int verseNumber) {
        return "On the " + TwelveDays.possessive.get(verseNumber) + " day of Christmas my true love gave to me: "
                + listGifts(verseNumber) + ".\n";
    }

    String verses(int startVerse, int endVerse) {
        String result = "";
        for (int i = startVerse; i <= endVerse; i++) {
            result = result.concat(this.verse(i));
            if (i != endVerse)
                result = result.concat("\n");
        }
        return result;
    }

    String sing() {
        return verses(1, 12);
    }
}
