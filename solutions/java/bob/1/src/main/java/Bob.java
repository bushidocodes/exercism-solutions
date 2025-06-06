class Bob {

    public boolean isYelling(String input) {
        boolean hasLetters = input.chars().filter(i -> Character.isLetter((char) i)).sum() > 0;
        boolean allLettersAreUppers = input.chars().filter(i -> Character.isLetter((char) i))
                .allMatch(i -> Character.isUpperCase((char) i));
        return hasLetters && allLettersAreUppers;
    }

    public boolean isQuestion(String input) {
        return input.length() > 0 && input.toCharArray()[input.length() - 1] == '?';
    }

    public String hey(String input) {
        input = input.strip();
        if (input == "")
            return "Fine. Be that way!";

        if (isQuestion(input)) {
            return isYelling(input) ? "Calm down, I know what I'm doing!" : "Sure.";
        }

        return isYelling(input) ? "Whoa, chill out!" : "Whatever.";
    }
}