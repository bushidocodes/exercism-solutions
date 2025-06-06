import java.util.NoSuchElementException;

class SimpleLinkedList<T> {
    static class Node<T> {
        Node<T> next;
        T value;
        public Node(T value, Node<T> next){
            this.value = value;
            this.next = next;
        }
    }
    
    private SimpleLinkedList.Node<T> front;
    
    public SimpleLinkedList(){
        this.front = null;
    };
    
    public SimpleLinkedList(T [] values){
        for (var elem: values){
           this.push(elem); 
        }
    };

    public void push(T elem){
        SimpleLinkedList.Node<T> oldFront = this.front;
        this.front = new SimpleLinkedList.Node(elem, oldFront);
    };
    
    public T pop(){
        if (this.front == null) throw new NoSuchElementException();
        
        SimpleLinkedList.Node<T> oldFront = this.front;
        this.front = this.front.next;
        
        return oldFront.value;
    };

    public int size() {
        int res = 0;
        for (SimpleLinkedList.Node<T> cursor = this.front; cursor != null; cursor = cursor.next)
            res++;
        
        return res;
    }

    public void reverse() {
        SimpleLinkedList.Node<T> last = null;
        SimpleLinkedList.Node<T> cursor = this.front;
        SimpleLinkedList.Node<T> oldNext = null;
        while (cursor != null){
            oldNext = cursor.next;
            cursor.next = last;
            last = cursor;
            this.front = cursor;
            cursor = oldNext;
        }
    }
 
    public <E> E [] asArray(Class<E> cls) {
        Object[] res = new Object[size()];
        SimpleLinkedList.Node<T> node = this.front;
		for (int i = 0; i < res.length; i++) {
			res[i] = node.value;
			node = node.next;
		}
        
		return (E[]) res;
    }
}