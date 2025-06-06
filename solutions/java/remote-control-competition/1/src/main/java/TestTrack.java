import java.util.List;

public class TestTrack {

    public static void race(RemoteControlCar car) {
        car.drive();
    }

    public static List<ProductionRemoteControlCar> getRankedCars(ProductionRemoteControlCar prc1,
                                                                 ProductionRemoteControlCar prc2) {
        if (prc1.getNumberOfVictories() > prc2.getNumberOfVictories()){
            return List.of(prc1, prc2);
        } else {
            return List.of(prc2, prc1);
        }
    }
}
