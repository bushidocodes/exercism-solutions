import java.util.HashSet;

class IsbnVerifier {

    private static HashSet<Character> validChars;
    private static int ASCII_INT_OFFSET = 48;

    static {
        IsbnVerifier.validChars = new HashSet<Character>();
        for (char c = '0'; c <= '9'; c++) {
            IsbnVerifier.validChars.add(c);
        }
        IsbnVerifier.validChars.add('X');
    }

    boolean isValid(String stringToVerify) {

        int[] quantifiedString = stringToVerify.chars().filter(i -> validChars.contains((char) i))
                .map(i -> i == 'X' ? 10 : i - ASCII_INT_OFFSET).toArray();

        if (quantifiedString.length != 10)
            return false;

        // Confirm there isn't an X (here mapped to 10) in the first nine digits
        for (int i = 0; i < quantifiedString.length - 1; i++) {
            if (quantifiedString[i] == 10)
                return false;
        }

        return (quantifiedString[0] * 10 + quantifiedString[1] * 9 + quantifiedString[2] * 8 + quantifiedString[3] * 7
                + quantifiedString[4] * 6 + quantifiedString[5] * 5 + quantifiedString[6] * 4 + quantifiedString[7] * 3
                + quantifiedString[8] * 2 + quantifiedString[9] * 1) % 11 == 0;
    }

}
