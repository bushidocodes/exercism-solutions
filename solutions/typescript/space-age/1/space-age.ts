export default class SpaceAge {
  static EARTH_YEAR_IN_SECS: number = 31557600;
  static PLANETARY_YEAR_IN_EARTH_YEAR: Record<string, number> = {
    mercury: 0.2408467,
    venus: 0.61519726,
    mars: 1.8808158,
    jupiter: 11.862615,
    saturn: 29.447498,
    uranus: 84.016846,
    neptune: 164.79132,
  };

  public seconds: number;
  constructor(seconds: number) {
    this.seconds = seconds;
  }

  onEarth(): number {
    return parseFloat((this.seconds / SpaceAge.EARTH_YEAR_IN_SECS).toFixed(2));
  }
  onMercury(): number {
    return parseFloat(
      (
        this.seconds /
        SpaceAge.EARTH_YEAR_IN_SECS /
        SpaceAge.PLANETARY_YEAR_IN_EARTH_YEAR["mercury"]
      ).toFixed(2)
    );
  }
  onVenus(): number {
    return parseFloat(
      (
        this.seconds /
        SpaceAge.EARTH_YEAR_IN_SECS /
        SpaceAge.PLANETARY_YEAR_IN_EARTH_YEAR["venus"]
      ).toFixed(2)
    );
  }
  onJupiter(): number {
    return parseFloat(
      (
        this.seconds /
        SpaceAge.EARTH_YEAR_IN_SECS /
        SpaceAge.PLANETARY_YEAR_IN_EARTH_YEAR["jupiter"]
      ).toFixed(2)
    );
  }

  onMars(): number {
    return parseFloat(
      (
        this.seconds /
        SpaceAge.EARTH_YEAR_IN_SECS /
        SpaceAge.PLANETARY_YEAR_IN_EARTH_YEAR["mars"]
      ).toFixed(2)
    );
  }
  onSaturn(): number {
    return parseFloat(
      (
        this.seconds /
        SpaceAge.EARTH_YEAR_IN_SECS /
        SpaceAge.PLANETARY_YEAR_IN_EARTH_YEAR["saturn"]
      ).toFixed(2)
    );
  }

  onNeptune(): number {
    return parseFloat(
      (
        this.seconds /
        SpaceAge.EARTH_YEAR_IN_SECS /
        SpaceAge.PLANETARY_YEAR_IN_EARTH_YEAR["neptune"]
      ).toFixed(2)
    );
  }

  onUranus(): number {
    return parseFloat(
      (
        this.seconds /
        SpaceAge.EARTH_YEAR_IN_SECS /
        SpaceAge.PLANETARY_YEAR_IN_EARTH_YEAR["uranus"]
      ).toFixed(2)
    );
  }
}
