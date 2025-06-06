import java.util.Arrays;

class Triangle {
    double[] sides = new double[3];

    Triangle(double side1, double side2, double side3) throws TriangleException {
        if (side1 <= 0.0d || side2 <= 0.0d || side3 <= 0.0d) throw new TriangleException();
        
        this.sides[0] = side1;
        this.sides[1] = side2;
        this.sides[2] = side3;
        Arrays.sort(this.sides);

        if ((this.sides[0] + this.sides[1]) <= this.sides[2]) throw new TriangleException();
    }

    boolean isEquilateral() {
        return this.sides[0] == this.sides[1] && this.sides[1] == this.sides[2];
    }

    boolean isIsosceles() {
        return this.sides[0] == this.sides[1] || this.sides[1] == this.sides[2];
    }

    boolean isScalene() {
        return this.sides[0] != this.sides[1] && this.sides[1] != this.sides[2];
    }

}
