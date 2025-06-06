class CircularBuffer {
  constructor(size) {
    this.data = new Array(size);
    this.start = 0;
    this.end = 0;
    this.isFull = false;
  }

  write(value) {
    if (this.isFull == true) throw new BufferFullError();

    this.data[this.end] = value;

    this.end = (this.end + 1) % this.data.length;
    if (this.end === this.start) this.isFull = true;
  }

  read() {
    if (this.start === this.end && this.isFull == false) throw new BufferEmptyError();

    const result = this.data[this.start];
    
    this.start = (this.start + 1) % this.data.length;
    if (this.isFull) this.isFull = false;

    return result;
  }

  forceWrite(value) {
    if (this.isFull){
      this.data[this.end] = value;
      this.end = (this.end + 1) % this.data.length;
      this.start = this.end;
    } else {
      this.write(value);
    }
  }

  clear() {
    this.start = 0;
    this.end = 0;
    this.isFull = false;
  }
}

export default CircularBuffer;

export class BufferFullError extends Error {
  constructor(text) {
    super(text);
  }
}

export class BufferEmptyError extends Error {
  constructor(text) {
    super(text);
  }
}
