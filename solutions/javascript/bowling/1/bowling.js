class Frame {
  rolls = [];
  score = 0;
  isDone = false;
}

export class Bowling {
  frames = [new Frame(), new Frame(), new Frame(), new Frame(), new Frame(), new Frame(), new Frame(), new Frame(), new Frame(), new Frame()];
  currentFrame = 0;
  
  roll(score) {
    if (score < 0) throw new Error("Negative roll is invalid");
    if (score > 10) throw new Error("Pin count exceeds pins on the lane");
      
    let _frame = this.frames[this.currentFrame];
    let isStrike = _frame.rolls[0] == 10;
    let isSpare = !isStrike && _frame.rolls.length >= 2 && (_frame.rolls[0] + _frame.rolls[1] == 10);
    let islastFrame = this.currentFrame == 9;

    // Frame cannot exceed 10 pins
    if (!isStrike && _frame.rolls.length == 1 && _frame.rolls[0] + score > 10 ){
      throw new Error("Pin count exceeds pins on the lane");
    }

    // Two bonus throws following strike cannot exceed 10 if first bonus throw wasn't a strike
    if (islastFrame && isStrike && _frame.rolls.length == 2 && _frame.rolls[1] != 10 && _frame.rolls[1] + score > 10 ){
      throw new Error("Pin count exceeds pins on the lane");
    }
    
    if (islastFrame && _frame.isDone) { 
      throw new Error("Cannot roll after game is over");
    }

    _frame.rolls.push(score);
    isStrike = _frame.rolls[0] == 10;
    isSpare = !isStrike && _frame.rolls.length >= 2 && (_frame.rolls[0] + _frame.rolls[1] == 10);
    
    if (islastFrame) {
      if (isStrike || isSpare){
        if (_frame.rolls.length == 3) _frame.isDone = true;
      } else {
        if (_frame.rolls.length == 2) _frame.isDone = true;
      }
    } else {
      if (isStrike || _frame.rolls.length == 2){
        _frame.isDone = true;
        this.currentFrame++;
      }
    }
  }
  

  score() {
    if (this.frames[9].isDone !== true) {
      console.log(this.frames[9]);
      throw new Error("Score cannot be taken until the end of the game");
    }

    this.frames[9].score = this.frames[9].rolls.reduce((acc, elem) => acc + elem, 0);
    
    for (let i = 8; i >= 0; i--){
      if (this.frames[i].rolls[0] == 10)
        if (this.frames[i + 1].rolls.length == 1) {
          this.frames[i].score = 10 + this.frames[i + 1].rolls[0] + this.frames[i + 2].rolls[0];
        } else {
          this.frames[i].score = 10 + this.frames[i + 1].rolls[0] + this.frames[i + 1].rolls[1];
        }
      else if (this.frames[i].rolls[0] + this.frames[i].rolls[1] == 10) 
        this.frames[i].score = 10 + this.frames[i + 1].rolls[0];
      else 
        this.frames[i].score = this.frames[i].rolls[0] + this.frames[i].rolls[1];
    }

    console.log(this.frames);
    return this.frames.reduce((total, frame)=> total + frame.score, 0);
  }
}
