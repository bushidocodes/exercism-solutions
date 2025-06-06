import java.util.stream.IntStream;

class DifferenceOfSquaresCalculator {

    int computeSquareOfSumTo(int input) {
        return (int)Math.pow(
            IntStream.rangeClosed(1, input)
            .reduce(0, (acc, elem) -> acc + elem)
        , 2);
    }

    int computeSumOfSquaresTo(int input) {
        return IntStream.rangeClosed(1, input)
            .map(elem -> (int)Math.pow(elem, 2))
            .reduce(0, (acc, elem) -> acc + elem);
    }

    int computeDifferenceOfSquares(int input) {
        return this.computeSquareOfSumTo(input) - this.computeSumOfSquaresTo(input);
    }

}
