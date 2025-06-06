#[derive(Debug, PartialEq)]
pub enum Error {
    NotEnoughPinsLeft,
    GameComplete,
}

type Frame = (u16, u16);

pub struct BowlingGame {
    is_complete: bool,
    score: [Frame; 12],
    current_frame: usize,
    is_first_throw: bool,
}

impl BowlingGame {
    pub fn new() -> Self {
        BowlingGame{
            is_complete: false,
            current_frame: 0,
            is_first_throw: true,
            score: [(0,0); 12],
        }
    }

    pub fn roll(&mut self, pins: u16) -> Result<(), Error> {
        if self.is_complete {
            return Err(Error::GameComplete);
        }
        
        if self.score[self.current_frame].0 + pins > 10 {
            return Err(Error::NotEnoughPinsLeft);
        }

        if self.is_first_throw {
            self.score[self.current_frame].0 = pins;

            // If we are in the bonus frame after a spare, we only get one throw
            if self.current_frame == 10 && self.score[9].0 < 10 {
                self.is_complete = true;
            // Two bonus frames due to consecutive Strikes
            } else if self.current_frame == 11 {
                self.is_complete = true;
            // Strike
            } else if pins == 10 {
                self.current_frame += 1;
            } else {
                self.is_first_throw = false;
            }
        } else {
            self.score[self.current_frame].1 = pins;

            // If we are in the bonus frame after a strike, we get two throws
            if self.current_frame == 10 {
                self.is_complete = true;
            // Spare in last frame
            } else if self.score[self.current_frame].0 + self.score[self.current_frame].1 == 10 {
                self.current_frame += 1;
                self.is_first_throw = true;
            } else if self.current_frame < 9 {
                self.current_frame += 1;
                self.is_first_throw = true;
            } else {
                self.is_complete = true;
            }
        }

        Ok(())
    }

    pub fn score(&self) -> Option<u16> {
        if self.is_complete {
            Some(self.score.iter().enumerate().map(|(idx, (first, second))|
                // Bonus frames only used for strikes and spares
                if idx > 9 { 0 }
                // Strike
                else if *first == 10 {
                    // Consecutive strike
                    if self.score[idx + 1].0 == 10 {
                        *first + self.score[idx + 1].0 + self.score[idx + 2].0
                    } else {
                        *first + self.score[idx + 1].0 + self.score[idx + 1].1
                    }
                // Spare 
                } else if idx < 10 && *first + *second == 10 {
                   *first + *second + self.score[idx + 1].0
                } else {
                   *first + *second
                }
            ).sum())
        } else {
            None
        }
    }
}
