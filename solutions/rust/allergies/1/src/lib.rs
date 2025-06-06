pub struct Allergies{
    score: u32
}

#[derive(Debug, PartialEq, Copy, Clone)]
pub enum Allergen {
    Eggs,
    Peanuts,
    Shellfish,
    Strawberries,
    Tomatoes,
    Chocolate,
    Pollen,
    Cats,
}


impl Allergies {
    pub fn new(score: u32) -> Self {
        Allergies {score}
    }

    pub fn is_allergic_to(&self, allergen: &Allergen) -> bool {
        match allergen {
            Allergen::Eggs => (self.score & 0b1) == 0b1,
            Allergen::Peanuts => (self.score & 0b10) == 0b10,
            Allergen::Shellfish => (self.score & 0b100) == 0b100,
            Allergen::Strawberries => (self.score & 0b1000) == 0b1000,
            Allergen::Tomatoes => (self.score & 0b10000) == 0b10000,
            Allergen::Chocolate => (self.score & 0b100000) == 0b100000,
            Allergen::Pollen => (self.score & 0b1000000) == 0b1000000,
            Allergen::Cats => (self.score & 0b10000000) == 0b10000000
        }
    }

    pub fn allergies(&self) -> Vec<Allergen> {
        vec![
            Allergen::Eggs, 
            Allergen::Peanuts, 
            Allergen::Shellfish, 
            Allergen::Strawberries,
            Allergen::Tomatoes,
            Allergen::Chocolate,
            Allergen::Pollen,
            Allergen::Cats
        ].iter()
        .filter(|varient| self.is_allergic_to(varient))
        .map(|varient| *varient)
        .collect()
    }
}
