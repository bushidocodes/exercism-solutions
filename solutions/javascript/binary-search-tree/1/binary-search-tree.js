export class BinarySearchTree {
 
  constructor(elem) {
    this.value = elem;
    this.leftNode = null;
    this.rightNode = null;
  }

  get data() {
    return this.value
  }
  get right() {
    return this.rightNode;
  }

  get left() {
    return this.leftNode;
  }

  insert(elem) {
    if (elem <= this.value){
      if (!this.leftNode) {
        this.leftNode = new BinarySearchTree(elem);
      } else {
        this.leftNode.insert(elem);
      }
    } else {
      if (!this.rightNode) {
        this.rightNode = new BinarySearchTree(elem);
      } else {
        this.rightNode.insert(elem);
      }
    }
  }

  each(lambda) {
    if (this.leftNode) this.leftNode.each(lambda);
    lambda(this.value);
    if (this.rightNode) this.rightNode.each(lambda);
  }
}
