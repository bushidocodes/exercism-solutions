import java.util.HashMap;

class IsogramChecker {

    private HashMap<Character, Integer> charCount;

    IsogramChecker() {
        this.charCount = new HashMap<>();
        for (char c = 'a'; c <= 'z'; c++) {
            this.charCount.put(c, 0);
        }
    }

    boolean isIsogram(String phrase) {

        phrase.chars().filter(i -> Character.isLetter(i)).map(i -> Character.toLowerCase(i))
                .forEach(i -> this.charCount.put((char) i, this.charCount.get((char) i) + 1));

        return this.charCount.values().stream().allMatch(i -> i < 2);
    }

}
