import java.util.Arrays;
import java.util.Collections;
import java.util.List;

class ReverseString {
    String reverse(String inputString) {
        List<String> listOfChars = Arrays.asList(inputString.split(""));
        Collections.reverse(listOfChars);
        return String.join("", listOfChars);
    }
}