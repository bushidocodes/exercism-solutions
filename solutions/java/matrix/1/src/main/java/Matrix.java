import java.util.*;
import java.util.stream.*;

class Matrix {
    private int[][] rowsMajor;

    Matrix(String matrixAsString) {
        this.rowsMajor = matrixAsString
            .lines()
            .map(row -> Arrays.stream(row.split(" ")).mapToInt(Integer::parseInt).toArray())
            .toArray(int[][]::new);       
    }

    int[] getRow(int rowNumber) {
        return this.rowsMajor[rowNumber - 1];
    }

    int[] getColumn(int columnNumber) {
        return Arrays.stream(this.rowsMajor).mapToInt(arr -> arr[columnNumber - 1]).toArray(); 
    }
}
