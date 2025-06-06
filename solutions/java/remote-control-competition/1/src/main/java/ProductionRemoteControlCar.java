class ProductionRemoteControlCar implements RemoteControlCar {
    int distanceDriven = 0;
    int numberOfVictories = 0;

    public void drive() {
        this.distanceDriven += 10;
    }

    public int getDistanceTravelled() {
        return this.distanceDriven;
    }

    public int getNumberOfVictories() {
        return this.numberOfVictories;
    }

    public void setNumberOfVictories(int numberofVictories) {
        this.numberOfVictories = numberOfVictories;
    }
}
