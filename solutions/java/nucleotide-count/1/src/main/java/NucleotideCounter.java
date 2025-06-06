import java.util.HashMap;

class NucleotideCounter {
    private HashMap<Character, Integer> counts;

    public NucleotideCounter() {
        this.counts = new HashMap<Character, Integer>();
        this.counts.put('A', 0);
        this.counts.put('C', 0);
        this.counts.put('G', 0);
        this.counts.put('T', 0);
    }

    public NucleotideCounter(String input) {
        this();
        this.countNucleotides(input);
    }

    public void countNucleotides(String input) {
        input.chars().forEach(i -> {
            if (!this.counts.keySet().contains((char) i))
                throw new IllegalArgumentException();
        });
        input.chars().forEach(i -> this.counts.put((char) i, this.counts.get((char) i) + 1));
    }

    public void clearNucleoTideCounts() {
        this.counts.clear();
    }

    public HashMap<Character, Integer> nucleotideCounts() {
        return this.counts;
    }
}