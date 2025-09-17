class Allergies:
    allergen_masks = {
        "eggs": 0b0000_0001,
        "peanuts": 0b0000_0010,
        "shellfish": 0b0000_0100,
        "strawberries": 0b0000_1000,
        "tomatoes": 0b0001_0000,
        "chocolate": 0b0010_0000,
        "pollen": 0b0100_0000,
        "cats": 0b1000_0000,
    }

    def __init__(self, score: int):
        self.score = score & 0xFF  # Only consider the lowest 8 bits
        self.lst: list[str] = [
            allergen
            for allergen, mask in self.allergen_masks.items()
            if self.score & mask
        ]

    def allergic_to(self, item: str) -> bool:
        return item in self.lst
