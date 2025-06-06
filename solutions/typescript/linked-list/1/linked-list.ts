interface LinkedListNode<T> {
  value: T;
  next: LinkedListNode<T> | null;
  prev: LinkedListNode<T> | null;
}

class LinkedList<T> {
  head: LinkedListNode<T> | null = null;
  tail: LinkedListNode<T> | null = null;
  length: number = 0;

  push(value: T) {
    let newNode: LinkedListNode<T> = { value, next: null, prev: null };

    if (this.tail == null) {
      this.head = newNode;
      this.tail = newNode;
      this.length = 1;
    } else {
      newNode.prev = this.tail;
      newNode.prev.next = newNode;
      this.tail = newNode;
      this.length++;
    }
  }

  unshift(value: T) {
    let newNode: LinkedListNode<T> = { value, next: null, prev: null };

    if (this.head == null) {
      this.head = newNode;
      this.tail = newNode;
      this.length = 1;
    } else {
      newNode.next = this.head;
      newNode.next.prev = newNode;
      this.head = newNode;
      this.length++;
    }
  }

  pop() {
    let poppedNode: LinkedListNode<T> | null = this.tail;

    if (poppedNode != null) {
      if (poppedNode.prev == null) {
        this.tail = null;
        this.head = null;
      } else {
        this.tail = poppedNode.prev;
        poppedNode.prev.next = null;
      }
    }
    return poppedNode ? poppedNode.value : poppedNode;
  }

  shift() {
    let poppedNode: LinkedListNode<T> | null = this.head;

    if (poppedNode != null) {
      if (poppedNode.next == null) {
        this.tail = null;
        this.head = null;
      } else {
        this.head = poppedNode.next;
        poppedNode.next.prev = null;
      }
    }
    return poppedNode ? poppedNode.value : poppedNode;
  }

  delete(value: T): void {
    for (let node = this.head; node != null; node = node.next) {
      if (node.value == value) {
        if (node.prev !== null) {
          node.prev.next = node.next;
        }
        if (node.next !== null) {
          node.next.prev = node.prev;
        }
        this.length--;
        return;
      }
    }
  }

  count(): number {
    return this.length;
  }
}

export default LinkedList;
