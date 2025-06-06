import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.stream.Collectors;

class PigLatinTranslator {

    static HashSet<String> leadingVowels;
    static HashSet<Character> vowels;

    static {
        PigLatinTranslator.leadingVowels = new HashSet<String>();
        PigLatinTranslator.leadingVowels.add("^xr.+");
        PigLatinTranslator.leadingVowels.add("^yt.+");
        PigLatinTranslator.vowels = new HashSet<Character>();
        PigLatinTranslator.vowels.add('a');
        PigLatinTranslator.vowels.add('e');
        PigLatinTranslator.vowels.add('i');
        PigLatinTranslator.vowels.add('o');
        PigLatinTranslator.vowels.add('u');
    }

    public String translateWord(String input) {

        // Handle Special Vowel Sounds at start of the word
        for (String vowel : PigLatinTranslator.leadingVowels) {
            if (input.matches(vowel)) {
                return input += "ay";
            }
        }

        // Otherwise rotate all consonants and add AY

        List<Character> buffer = input.chars().mapToObj(i -> (char) i).map(i -> Character.toLowerCase(i))
                .collect(Collectors.toList());

        boolean didRotate = false;
        boolean lastWasQ = false;

        while ((!PigLatinTranslator.vowels.contains((char) buffer.get(0)) && buffer.get(0) != 'y') // Is a consonant
                                                                                                   // other that Y
                || (lastWasQ && buffer.get(0) == 'u') // or is 'Qu'
                || (!didRotate && buffer.get(0) == 'y')) // Or is Y treated as a consonant (not the first letter)
        {
            didRotate = true;
            Character temp = buffer.remove(0);
            lastWasQ = temp == 'q';
            buffer.add(temp);
        }

        return buffer.stream().map(i -> Character.toString(i)).collect(Collectors.joining("")) + "ay";
    }

    public String translate(String input) {
        return Arrays.asList(input.split(" ")).stream().map(word -> this.translateWord(word))
                .collect(Collectors.joining(" "));
    }
}