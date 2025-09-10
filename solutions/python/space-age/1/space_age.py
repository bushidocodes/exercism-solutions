class SpaceAge:
    def __init__(self, seconds):
        self.earth_age = seconds / 31557600

    def on_earth(self) -> float:
        return round(self.earth_age, 2)

    def on_mercury(self) -> float:
        return round(self.earth_age / 0.2408467, 2)

    def on_venus(self) -> float:
        return round(self.earth_age / 0.61519726, 2)

    def on_mars(self) -> float:
        return round(self.earth_age / 1.8808158, 2)

    def on_jupiter(self) -> float:
        return round(self.earth_age / 11.862615, 2)

    def on_saturn(self) -> float:
        return round(self.earth_age / 29.447498, 2)

    def on_uranus(self) -> float:
        return round(self.earth_age / 84.016846, 2)

    def on_neptune(self) -> float:
        return round(self.earth_age / 164.79132, 2)
