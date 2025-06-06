import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;

class Anagram {
    private String word;
    private String letters;
    
    public Anagram(String word){
        this.word = word;
        var charArr = word.toLowerCase().toCharArray();
        Arrays.sort(charArr);
        letters = new String(charArr);
    }

    public List<String> match(List<String> candidates){
        List<String> matches = new ArrayList<String>();

        for(var candidate: candidates){
            var candidateLetters = candidate.toLowerCase().toCharArray();
            Arrays.sort(candidateLetters);
            if (!this.word.equalsIgnoreCase(candidate) && this.letters.equals(new String(candidateLetters))) {
                matches.add(candidate);
			}
        }

        return matches;
    }
}