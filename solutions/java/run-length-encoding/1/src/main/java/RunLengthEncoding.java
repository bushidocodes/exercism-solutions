import java.util.Optional;

class RunLengthEncoding {
    public static String encode(String plaintext){
        StringBuilder result = new StringBuilder();
        Optional<Character> lastChar = Optional.empty();
        int lastCharCount = 0;

        for (char c: plaintext.toCharArray()){
            if (!lastChar.isPresent()) {
                lastChar = Optional.of(c);
                lastCharCount = 1;
            } else if (lastChar.isPresent() && lastChar.get() == c) {
                lastCharCount++;
            } else if (lastChar.isPresent()) {
                if (lastCharCount > 1) result.append(lastCharCount);
                result.append(lastChar.get());
                lastChar = Optional.of(c);
                lastCharCount = 1;
            }
        }

        if (lastChar.isPresent()) {
            if (lastCharCount > 1) result.append(lastCharCount);
            result.append(lastChar.get());
        }

        return result.toString();
    }

    public static String decode(String encoded){
        StringBuilder result = new StringBuilder();

        int count = 0;
        for (char c: encoded.toCharArray()){
            if (Character.isDigit(c)) {
                count = 10 * count + Integer.parseInt(Character.toString(c));
            } else {
                if (count == 0) count = 1;
                for (int i = 0; i < count; i++){
                    result.append(c);
                }
                count = 0;
            }
        }

        return result.toString();
    }
}