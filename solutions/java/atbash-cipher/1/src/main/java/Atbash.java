import java.util.ArrayList;
import java.util.List;
import static java.util.stream.Collectors.toList;

class Atbash {

    public String encode(String plaintext){
        return plaintext.toLowerCase().chars()
            .filter(c -> Character.isLetterOrDigit(c))
            .map(c -> Character.isLetter(c) ? 'z' - (c - 'a') : c)
            .collect(StringBuilder::new, StringBuilder::appendCodePoint, StringBuilder::append)
            .toString()
            .replaceAll(".....", "$0 ")
            .trim();
    }

    public String decode(String ciphertext){
        return ciphertext.chars()
            .filter(c -> Character.isLetterOrDigit(c))
            .map(c -> Character.isLetter(c) ? 'z' - (c - 'a') : c)
            .collect(StringBuilder::new, StringBuilder::appendCodePoint, StringBuilder::append)
            .toString();
    }
}