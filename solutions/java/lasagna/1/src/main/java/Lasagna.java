public class Lasagna {
    public int expectedMinutesInOven(){
        return 40;
    }

    public int remainingMinutesInOven(int timeInOven){
        return this.expectedMinutesInOven() - timeInOven;
    }

    public int preparationTimeInMinutes(int numberOfLayers) {
        final int timePerLayer = 2;
        return numberOfLayers * timePerLayer;
    }

    public int totalTimeInMinutes(int numberOfLayers, int timeInOven){
        return this.preparationTimeInMinutes(numberOfLayers) + timeInOven;
    }
}
