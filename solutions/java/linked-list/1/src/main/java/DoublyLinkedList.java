class DoublyLinkedList<T> {
    DoublyLinkedList.Node<T> front;
    DoublyLinkedList.Node<T> back;
    
    public static class Node<T> {
        T value;
        public Node<T> prev;
        public Node<T> next;
        public Node(T value, Node<T> prev, Node<T> next){
            this.value = value;
            this.prev = prev;
            this.next = next;
        }
    }
    
    public DoublyLinkedList(){
        this.front = null;    
        this.back = null;    
    }

    public void push(T value){
        DoublyLinkedList.Node<T> currentBack = this.back;
        this.back = new DoublyLinkedList.Node<T>(value, currentBack, null);
        if (currentBack != null) currentBack.next = this.back;
        if (this.front == null) this.front = this.back;
    }

    public T pop() {
        if (this.back == null) return null;
        
        DoublyLinkedList.Node<T> currentBack = this.back;
        if (currentBack.prev != null) currentBack.prev.next = null;
        this.back = currentBack.prev;
        if (this.front == currentBack) this.front = null;
        
        return currentBack.value;
    }

    public void unshift(T value){
        DoublyLinkedList.Node<T> currentFront = this.front;
        this.front = new DoublyLinkedList.Node<T>(value, null, currentFront);
        if (currentFront != null) currentFront.prev = this.front;
        if (this.back == null) this.back = this.front;
    }
    
    public T shift(){
        if (this.front == null) return null;
        
        DoublyLinkedList.Node<T> currentFront = this.front;
        if (currentFront.next != null) currentFront.next.prev = null;
        this.front = currentFront.next;
        if (this.back == currentFront) this.back = null;
        
        return currentFront.value;
    }
    
}