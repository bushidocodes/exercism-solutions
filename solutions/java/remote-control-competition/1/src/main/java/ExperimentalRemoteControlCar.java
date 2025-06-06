public class ExperimentalRemoteControlCar implements RemoteControlCar {
    int distanceDriven = 0;
    
    public void drive() {
        this.distanceDriven += 20;
    }

    public int getDistanceTravelled() {
        return this.distanceDriven;
    }
}
