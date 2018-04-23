public class Node<T>{
    private T data;
    private Node<T> next;
    public Node(T data, Node<T> next){
    this.data = data;
    this.next = next;
    }
    public void setdata(T data){
        this.data=data;
    }
    public void setNext(Node<T> next){
        this.next=next;
    }
    public Node<T> getNext(){
        return next;
    }
    public T getData(){
        return data;
    }
}