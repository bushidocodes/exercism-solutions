class Scrabble {
    private int score = 0;

    static int scoreLetter(char letter) {
        switch (Character.toUpperCase(letter)) {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
            case 'L':
            case 'N':
            case 'R':
            case 'S':
            case 'T':
                return 1;
            case 'D':
            case 'G':
                return 2;
            case 'B':
            case 'C':
            case 'M':
            case 'P':
                return 3;
            case 'F':
            case 'H':
            case 'V':
            case 'W':
            case 'Y':
                return 4;
            case 'K':
                return 5;
            case 'J':
            case 'X':
                return 8;
            case 'Q':
            case 'Z':
                return 10;
            default:
                throw new IllegalArgumentException("Must be a letter a-z or A-Z");
        }
    }

    Scrabble(String word) {
        this.score = word.chars().map(i -> Scrabble.scoreLetter((char) i)).sum();
    }

    int getScore() {
        return this.score;
    }

}
