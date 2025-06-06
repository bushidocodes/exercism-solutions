import java.util.stream.Collectors;

class PhoneNumber {
    private String value;

    PhoneNumber(String userInput) {

        boolean hasLetters = userInput.chars().mapToObj(i -> (char) i).anyMatch(c -> Character.isAlphabetic(c));

        if (hasLetters)
            throw new IllegalArgumentException("letters not permitted");

        boolean hasUnexpectedPunctuation = userInput.chars().mapToObj(i -> (char) i)
                .anyMatch(c -> c == ',' || c == ':' || c == ';');

        if (hasUnexpectedPunctuation)
            throw new IllegalArgumentException("punctuations not permitted");

        String cleansedNumber = userInput.chars().mapToObj(i -> (char) i).filter(i -> Character.isDigit(i))
                .map(c -> c.toString()).collect(Collectors.joining());

        if (cleansedNumber.length() > 11) {
            throw new IllegalArgumentException("more than 11 digits");
        }

        if (cleansedNumber.length() == 11) {
            if (cleansedNumber.charAt(0) != '1') {
                throw new IllegalArgumentException("11 digits must start with 1");
            } else {
                // Strip leading 1
                cleansedNumber = cleansedNumber.substring(1);
            }
        }

        if (cleansedNumber.length() != 10)
            throw new IllegalArgumentException("incorrect number of digits");

        if (cleansedNumber.charAt(0) == '0')
            throw new IllegalArgumentException("area code cannot start with zero");

        if (cleansedNumber.charAt(0) == '1')
            throw new IllegalArgumentException("area code cannot start with one");

        if (cleansedNumber.charAt(3) == '0')
            throw new IllegalArgumentException("exchange code cannot start with zero");

        if (cleansedNumber.charAt(3) == '1')
            throw new IllegalArgumentException("exchange code cannot start with one");

        this.value = cleansedNumber;
    }

    String getNumber() {
        return this.value;
    }
}