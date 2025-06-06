import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;

class BracketChecker{
    private String brackets;
    private Map<Character,Character> closingToOpening;
    
    public BracketChecker(String brackets){
        this.brackets = brackets;
        this.closingToOpening = new HashMap<Character, Character>();
        this.closingToOpening.put(']', '[');
        this.closingToOpening.put('}', '{');
        this.closingToOpening.put(')', '(');
    }

    boolean areBracketsMatchedAndNestedCorrectly(){
        List<Character> stack = new ArrayList();

        boolean didMatch = this.brackets.chars()
            .filter(c -> c == ']' || c == '[' || c == '}' || c == '{' || c == ')' || c == '(')
            .allMatch(c -> {
                if (c == '[' || c == '{' || c == '(') {
                    stack.add((char)c);
                    return true;
                } else {
                    if (stack.size() == 0) return false;
                    return closingToOpening.get((char)c) == stack.remove(stack.size() - 1);
                }
            });

        return didMatch && stack.size() == 0;
    }
}