import java.math.BigInteger;

class Grains {

    static private int SPACES_ON_BOARD = 64;

    static private BigInteger[] grainsOnSquare;

    static {
        // Use 1-based indexing and disregard 0
        Grains.grainsOnSquare = new BigInteger[SPACES_ON_BOARD + 1];
        Grains.grainsOnSquare[0] = BigInteger.valueOf(0);

        // Set the first square
        Grains.grainsOnSquare[1] = BigInteger.valueOf(1);

        // And compute the subsequent
        for (int i = 2; i <= SPACES_ON_BOARD; i++) {
            Grains.grainsOnSquare[i] = Grains.grainsOnSquare[i - 1].multiply(BigInteger.valueOf(2));
        }

    }

    static BigInteger grainsOnSquare(final int square) {
        if (square < 1 || square > Grains.SPACES_ON_BOARD)
            throw new IllegalArgumentException("square must be between 1 and 64");
        return Grains.grainsOnSquare[square];
    }

    static BigInteger grainsOnBoard() {
        BigInteger sum = BigInteger.valueOf(0);
        for (int i = 1; i <= Grains.SPACES_ON_BOARD; i++) {
            sum = sum.add(Grains.grainsOnSquare(i));
        }
        return sum;
    }

}
