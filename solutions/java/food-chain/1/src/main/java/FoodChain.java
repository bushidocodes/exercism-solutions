import java.util.stream.Collectors;
import java.util.stream.IntStream;

class FoodChain {
    String verse(int verseNumber) {

        if (verseNumber < 0 || verseNumber > 8)
            return "";

        if (verseNumber == 8)
            return "I know an old lady who swallowed a horse.\n" + "She's dead, of course!";

        String[] initialPhrase = { "", "I know an old lady who swallowed a fly.\n",
                "I know an old lady who swallowed a spider.\nIt wriggled and jiggled and tickled inside her.\n",
                "I know an old lady who swallowed a bird.\nHow absurd to swallow a bird!\n",
                "I know an old lady who swallowed a cat.\n" + "Imagine that, to swallow a cat!\n",
                "I know an old lady who swallowed a dog.\n" + "What a hog, to swallow a dog!\n",
                "I know an old lady who swallowed a goat.\n" + "Just opened her throat and swallowed a goat!\n",
                "I know an old lady who swallowed a cow.\n" + "I don't know how she swallowed a cow!\n" };

        String result = initialPhrase[verseNumber];
        switch (verseNumber) {
            case 7:
                result = result.concat("She swallowed the cow to catch the goat.\n");
            case 6:
                result = result.concat("She swallowed the goat to catch the dog.\n");
            case 5:
                result = result.concat("She swallowed the dog to catch the cat.\n");
            case 4:
                result = result.concat("She swallowed the cat to catch the bird.\n");
            case 3:
                result = result.concat(
                        "She swallowed the bird to catch the spider that wriggled and jiggled and tickled inside her.\n");
            case 2:
                result = result.concat("She swallowed the spider to catch the fly.\n");
            case 1:
                result = result.concat("I don't know why she swallowed the fly. Perhaps she'll die.");
        }
        return result;
    }

    String verses(int startVerse, int endVerse) {
        return IntStream.rangeClosed(startVerse, endVerse).mapToObj(i -> this.verse(i))
                .collect(Collectors.joining("\n\n"));
    }

}