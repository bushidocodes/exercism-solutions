// This stub file contains items that aren't used yet; feel free to remove this module attribute
// to enable stricter warnings.
#![allow(unused)]

pub struct Player {
    pub health: u32,
    pub mana: Option<u32>,
    pub level: u32,
}

impl Player {
    pub fn revive(&self) -> Option<Player> {
        if self.health == 0 && self.level < 10 {
            Some(Player{health: 100, mana: None, level: self.level})
        } else if self.health == 0 && self.level >= 10 {
            Some(Player{health: 100, mana: Some(100), level: self.level})
        } else {
            None
        }
    }

    pub fn cast_spell(&mut self, mana_cost: u32) -> u32 {

        match self.mana {
            None => {
                if mana_cost > self.health {
                    self.health = 0;
                } else {
                    self.health -= mana_cost;
                }
                0
            },
            Some(amount) if amount >= mana_cost => {
                self.mana = Some(amount - mana_cost);
                mana_cost * 2
            },
            Some(_) => 0,
        }
        
    }
}
