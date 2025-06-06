// @ts-check

export function Size(width = 80, height = 60) {
  this.width = width;
  this.height = height;
}

Size.prototype.resize = function (newWidth, newHeight) {
  this.width = newWidth;
  this.height = newHeight;
}

export function Position(x = 0, y = 0) {
  this.x = x;
  this.y = y;
}

Position.prototype.move = function (newX, newY) {
  this.x = newX;
  this.y = newY;
}

export class ProgramWindow {
  constructor(){
    this.screenSize = new Size(800, 600);
    this.size = new Size();
    this.position = new Position();
  }

  resize(size = new Size()) {
    let height, width;
    
    if (size.height < 1) height = 1;
    else if (size.height > this.screenSize.height - this.position.y) height = this.screenSize.height - this.position.y;
    else height = size.height;
    
    if (size.width < 1) width = 1;
    else if (size.width > this.screenSize.width - this.position.x) width = this.screenSize.width - this.position.x;
    else width = size.width;

    this.size.width = width;
    this.size.height = height;
  }

  move(position = new Position()) {
    let x, y;
    
    if (position.y < 0) y = 0;
    else if (position.y > this.screenSize.height - this.size.height) y = this.screenSize.height - this.size.height;
    else y = position.y ;
    
    if (position.x < 0) x = 0;
    else if (position.x > this.screenSize.width - this.size.width) x = this.screenSize.width - this.size.width;
    else x = position.x;

    this.position.x = x;
    this.position.y = y;
  }
}

export function changeWindow(window){
  window.move(new Position(100, 150));
  window.resize(new Size(400, 300));
  return window;
}