public class ElonsToyCar {
    private int metersDriven = 0;
    private int batteryLevel = 100;
    
    public static ElonsToyCar buy() {
        return new ElonsToyCar();
    }

    public String distanceDisplay() {
        return "Driven " + this.metersDriven + " meters";
    }

    public String batteryDisplay() {
        return this.batteryLevel == 0 ? "Battery empty" : "Battery at " + this.batteryLevel + "%";
    }

    public void drive() {
        if (this.batteryLevel > 0){
            this.metersDriven += 20;
            this.batteryLevel--;
        }
    }
}
