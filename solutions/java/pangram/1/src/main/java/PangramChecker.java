import java.util.HashMap;

public class PangramChecker {
    private HashMap<Character, Integer> letterCount;

    public PangramChecker() {
        this.letterCount = new HashMap<Character, Integer>();
        for (char i = 'a'; i <= 'z'; i++) {
            this.letterCount.put((char) i, 0);
        }
    }

    public boolean isPangram(String input) {
        input.chars().map(c -> Character.toLowerCase(c)).filter(c -> this.letterCount.containsKey((char) c))
                .forEach(c -> {
                    this.letterCount.put((char) c, this.letterCount.get((char) c) + 1);
                });

        long numberOfZeros = this.letterCount.values().stream().filter(v -> v == 0).count();
        return numberOfZeros == 0;
    }

}
