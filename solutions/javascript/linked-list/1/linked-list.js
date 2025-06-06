class LLNode {
  value;
  prev;
  next;

  constructor(value, prev = undefined, next = undefined) {
    this.value = value;
    this.prev = prev;
    this.next = next;
  }
}

export class LinkedList {
  first;
  last;
  count_val = 0;

  push(value) {
    if (!this.last) {
      const node = new LLNode(value);
      this.first = node;
      this.last = node;
    } else {
      const node = new LLNode(value, this.last);
      this.last.next = node;
      this.last = node;
    }
    this.count_val++;
  }

  pop() {
    if (this.last) {
      const lastNode = this.last;
      this.last = lastNode.prev;
      if (lastNode.prev) {
        lastNode.prev.next = undefined;
        lastNode.prev = undefined;
      } else {
        this.first = undefined;
      }

      this.count_val--;
      return lastNode.value;
    }
  }

  shift() {
    if (this.first) {
      const firstNode = this.first;
      this.first = firstNode.next;
      if (firstNode.next) {
        firstNode.next.prev = undefined;
        firstNode.next = undefined;
      } else {
        this.last = undefined;
      }

      this.count_val--;
      return firstNode.value;
    }
  }

  unshift(value) {
    if (!this.first) {
      const node = new LLNode(value);
      this.first = node;
      this.last = node;
    } else {
      const node = new LLNode(value, undefined, this.first);
      this.first.prev = node;
      this.first = node;
    }

    this.count_val++;
  }

  delete(value) {
    for (let node = this.first; node != undefined; node = node.next) {
      if (node.value == value) {
        if (node == this.first) {
          this.first = this.first.next;
        }
        if (node == this.last) {
          this.last = this.last.prev;
        }
        if (node.prev) node.prev.next = node.next;
        if (node.next) node.next.prev = node.prev;

        this.count_val--;
        return;
      }
    }
  }

  count() {
    return this.count_val;
  }
}
