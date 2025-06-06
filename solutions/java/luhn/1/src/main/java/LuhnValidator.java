class LuhnValidator {

    static final int ASCII_DIGIT_OFFSET = 48;
    static final int MINIMUM_LUHN_DIGITS = 2;

    boolean isValid(final String candidate) {

        // If the candidate contains an invalid character, false
        int invalidDigitCount = candidate.chars().filter(i -> (char) i != ' ' && ((char) i < '0' || (char) i > '9'))
                .sum();
        if (invalidDigitCount > 0)
            return false;

        // Strip out all spaces and convert to ints
        final int[] digits = candidate.chars().filter(i -> ((char) i >= '0' && (char) i <= '9'))
                .map(i -> i - ASCII_DIGIT_OFFSET).toArray();

        if (digits.length < MINIMUM_LUHN_DIGITS)
            return false;

        int checksum = 0;
        for (int i = 0; i < digits.length; i++) {
            if ((digits.length - i) % 2 == 0) {
                digits[i] *= 2;
                if (digits[i] > 9)
                    digits[i] -= 9;
            }
            checksum += digits[i];
        }

        return checksum % 10 == 0;
    }

}
