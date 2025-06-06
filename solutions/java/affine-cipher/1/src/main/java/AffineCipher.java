

class AffineCipher {

    private static int M = 26;
    private static int φM = 12;

    String encode(String plaintext, int a, int b) {
        if (a % 2 == 0 || a % 13 == 0) throw new IllegalArgumentException("Error: keyA and alphabet size must be coprime.");
        
        var encoded = plaintext.toLowerCase().chars()
            .filter(c -> Character.isDigit(c) || (c >= 'a' && c <= 'z'))
            .map(c -> Character.isDigit(c) ? c : 'a' + ((a * (c - 'a') + b) % 26))
            .collect(StringBuilder::new, StringBuilder::appendCodePoint, StringBuilder::append);

        for (int i = 5; i < encoded.length() - 1; i+= 6) encoded.insert(i, ' ');

        return encoded.toString();
    }

    // int mmi(int a, int m){
    //     int n = 1;
    //     while (Math.floorMod(a * n, m) != 1) n++;
    //     return n;
    // }
    
    String decode(String ciphertext, int a, int b) {
        if (a % 2 == 0 || a % 13 == 0) throw new IllegalArgumentException("Error: keyA and alphabet size must be coprime.");
        
        // int a_inv = mmi(a, 26);
        int inverse = Math.floorMod((long) Math.pow(a, φM - 1), M);
        
        var decoded = ciphertext.toLowerCase().chars()
            .filter(c -> Character.isDigit(c) || (c >= 'a' && c <= 'z'))
            .map(c -> Character.isDigit(c) ? c : Math.floorMod(inverse * (c - 'a' - b), 26) + 'a')
            .collect(StringBuilder::new, StringBuilder::appendCodePoint, StringBuilder::append);

        return decoded.toString();
    }
}