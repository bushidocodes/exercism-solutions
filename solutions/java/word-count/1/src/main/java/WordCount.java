import java.util.HashMap;

class WordCount {
    HashMap<String, Integer> wordCount = new HashMap();
    
    HashMap<String, Integer> phrase (String input){
        String[] words = input.split("[ .,\n!&@$%^&=:]+");
        
        for (var word: words){
            if (word == "" || word == "'" || word == "''") continue;
            if (word.charAt(0) == '\'') word = word.substring(1, word.length());
            if (word.charAt(word.length() - 1) == '\'') word = word.substring(0, word.length() - 1);

            word = word.toLowerCase();

            var count = this.wordCount.get(word);
            if (count == null){
                this.wordCount.put(word, 1);
            } else {
                this.wordCount.put(word, count + 1);
            }
        }

        return this.wordCount;
    }
}