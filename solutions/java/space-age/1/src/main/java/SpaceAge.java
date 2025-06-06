class SpaceAge {

    private static double EARTH_YEAR_IN_SECS = 31557600f;
    private double earthAge;

    SpaceAge(double seconds) {
        this.earthAge = (seconds / EARTH_YEAR_IN_SECS);
    }

    double onEarth() {
        return this.earthAge;
    }

    double onMercury() {
        final double mercuryYearToEarthYear = 0.2408467;
        return this.earthAge / mercuryYearToEarthYear;
    }

    double onVenus() {
        final double venusYearToEarthYear = 0.61519726;
        return this.earthAge / venusYearToEarthYear;
    }

    double onMars() {
        final double marsYearToEarthYear = 1.8808158;
        return this.earthAge / marsYearToEarthYear;
    }

    double onJupiter() {
        final double jupiterYearToEarthYear = 11.862615;
        return this.earthAge / jupiterYearToEarthYear;
    }

    double onSaturn() {
        final double saturnYearToEarthYear = 29.447498;
        return this.earthAge / saturnYearToEarthYear;
    }

    double onUranus() {
        final double uranusYearToEarthYear = 84.016846;
        return this.earthAge / uranusYearToEarthYear;
    }

    double onNeptune() {
        final double neptuneYearToEarthYear = 164.79132;
        return this.earthAge / neptuneYearToEarthYear;
    }

}
