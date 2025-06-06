class Lasagna
{
    static int MINUTES_TO_PREP_LAYER = 2;
    
    public int ExpectedMinutesInOven() => 40;

    public int RemainingMinutesInOven(int ElapsedMinutesInOven) => this.ExpectedMinutesInOven() - ElapsedMinutesInOven;

    public int PreparationTimeInMinutes(int NumberOfLayers) => NumberOfLayers * Lasagna.MINUTES_TO_PREP_LAYER;

    public int ElapsedTimeInMinutes(int NumberOfLayers, int ElapsedMinutesInOven)
    {
        return this.PreparationTimeInMinutes(NumberOfLayers) + ElapsedMinutesInOven;
    }
}
