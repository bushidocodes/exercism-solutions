class NeedForSpeed {
    private int speed = 0;
    private int batteryDrain = 0;
    private int distanceDriven = 0;
    private int batteryPercent = 100;

    public NeedForSpeed(int speed, int batteryDrain){
        this.speed = speed;
        this.batteryDrain = batteryDrain;
    }

    public boolean batteryDrained() {
        return this.batteryPercent == 0;
    }

    public int distanceDriven() {
        return this.distanceDriven;
    }

    public void drive() {
        if (this.batteryDrained()) return;
        this.distanceDriven += this.speed;
        this.batteryPercent -= this.batteryDrain;
    }

    public static NeedForSpeed nitro() {
        return new NeedForSpeed(50, 4);
    }
}

class RaceTrack {
    private int distance = 0;

    public RaceTrack(int distance){
        this.distance = distance;
    }
    
    public boolean carCanFinish(NeedForSpeed car) {
        while (car.distanceDriven() < this.distance){
            if (car.batteryDrained()) return false;
            car.drive();
        }

        return true;
    }
}
