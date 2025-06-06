import java.util.List;
import java.util.Map;
import java.util.HashMap;

class Etl {
    Map<String, Integer> transform(Map<Integer, List<String>> old) {
        Map<String, Integer> result = new HashMap<String, Integer>();
        
        for (Map.Entry<Integer,List<String>> entry : old.entrySet()) {
            Integer score = entry.getKey();
            for (String letter: entry.getValue()) {
                result.put(letter.toLowerCase(), score);
            }
        }

        return result;
    }
}
