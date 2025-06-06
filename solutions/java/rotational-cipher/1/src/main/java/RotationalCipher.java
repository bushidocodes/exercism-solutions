class RotationalCipher {
    int shiftKey;
    
    RotationalCipher(int shiftKey) {
        this.shiftKey = shiftKey; 
    }

    String rotate(String data) {
        return data.chars().map(c -> {
                if (c == ' ') return c;
                else if (Character.isLowerCase(c)) return 'a' + ((c - 'a' + this.shiftKey) % 26);
                else if (Character.isUpperCase(c)) return 'A' + ((c - 'A' + this.shiftKey) % 26);
                else return c;
            })
            .collect(StringBuilder::new, StringBuilder::appendCodePoint, StringBuilder::append)
            .toString();
    }

}
