class Darts {
    private double lastDistance = 0;
    private int score = 0;

    Darts(double x, double y) {
        this.scoreThrow(x, y);
    }

    void scoreThrow(double x, double y) {
        this.lastDistance = Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2));
        if (this.lastDistance <= 1) {
            this.score += 10;
        } else if (this.lastDistance <= 5) {
            this.score += 5;
        } else if (this.lastDistance <= 10) {
            this.score += 1;
        }
    }

    int score() {
        return this.score;
    }

}
