import java.util.List;
import java.util.ArrayList;

class BinarySearchTree<T extends Comparable<T>> {
    private Node<T> root = null;
    
    void insert(T value) {
        if (root == null) {
            this.root = new Node<T>(value);
        } else {
            this.root.insert(value);
        }
    }

    List<T> getAsSortedList() {
        List<T> result = new ArrayList<T>();
        if (this.root != null) this.root.dfsAppend(result);
        return result;
    }

    synchronized List<T> getAsLevelOrderList() {
        List<Node<T>> nodes = new ArrayList<Node<T>>();
        List<Node<T>> next = new ArrayList<Node<T>>();
        List<T> result = new ArrayList<T>();
        
        if (this.root != null) nodes.add(this.root);

        while (nodes.size() > 0) {
            for (Node<T> node: nodes){
                result.add(node.getData());
                Node<T> left = node.getLeft();
                Node<T> right = node.getRight();
                
                if (left != null) next.add(left);
                if (right != null) next.add(right);
            }

            nodes.clear();
            
            if (next.size() > 0) {
                nodes.addAll(next);
                next.clear();
            }
        }

        
        return result;
    }

    Node<T> getRoot() {
        return this.root;
    }

    static class Node<T extends Comparable<T>> {
        private T data = null;
        private Node left;
        private Node right;

        Node(T data){
            this.data = data;
            this.left = null;
            this.right = null;
        }

        public Node<T> getLeft() {
            return this.left;
        }

        public void setLeft(Node<T> left) {
            this.left = left;
        }

        public Node<T> getRight() {
            return this.right;
        }

        public void setRight(Node<T> right) {
            this.right = right;
        }

        public T getData() {
            return this.data;
        }
        
        void dfsAppend(List<T> list) {
            if (this.left != null) this.left.dfsAppend(list);
            list.add(this.data);
            if (this.right != null) this.right.dfsAppend(list);
        }

    
        public void insert(T value) {
            if (value.compareTo(this.data) <= 0){
                if (this.left == null) this.left = new Node(value);
                else this.left.insert(value);
            } else {
                if (this.right == null) this.right = new Node(value);
                else this.right.insert(value);
            }
        }
    }
}
