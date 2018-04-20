public class LinkedList<T>{
    private Node<T> head,tail;
    public LinkedList(){
        head=null;
        tail=null;
    }
    public Node<T> getHead(){
        return head;
    }
    public Boolean isEmpty(){
        return head==null;
    }
    public int find(T el){
        if (isEmpty()){
            return -1;
        }else{
            Node<T> temp = head;
            Boolean found = false;
            int i=0;
            while(!found && temp!=null){
                if(el==temp.getData()){
                    found=true;
                } else{
                    temp = temp.getNext();
                    i++;
                }
            }
            if (found){
                return i;
            }else{
                return -1;
            }
        }   
    }
    public void add(T el){
        Node<T> temp= new Node<T>(el,null);
        if (head == null){
            head = temp;
            tail = temp;
        } else {
        tail.setNext(temp);
        tail = temp;
        }
    }
    public T get(int idx){
        Node<T> temp = head;
        int i;
        for(i=0;i<idx && temp!=null;i++){
            temp=temp.getNext();
        }
        if(temp!=null){
            return temp.getData();
        }else{
            return null;
        }
    }
    public void remove(T el){
        Node<T> temp=head;
        Node<T> before=null;
        Boolean found = false;
        // periksa apakah head = el
        if (!isEmpty()){
            if (el==temp.getData()){
                head = temp.getNext();
            }else{
                while (!found && temp!=null){
                    if (el==temp.getData()){
                        found=true;
                    } else{
                        before = temp;
                        temp = temp.getNext();
                    }
                }
                if (found){
                    before.setNext(temp.getNext());
                }
            }
        }
    }
}