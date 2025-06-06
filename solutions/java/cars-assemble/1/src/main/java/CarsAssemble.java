import java.lang.Exception;

public class CarsAssemble {

    public double productionRatePerHour(int speed) {
        double production = 221 * speed;

        switch (speed){
            case 5:
            case 6:
            case 7:
            case 8:
                production *= 0.9;
                break;
            case 9:
                production *= 0.8;
                break;
            case 10:
                production *= 0.77;
                break;
        }

        return production;
    }

    public int workingItemsPerMinute(int speed) {
        return (int)(this.productionRatePerHour(speed) / 60);
    }
}

