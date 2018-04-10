#ifndef _LL_HPP
#define _LL_HPP
#include <cstddef>

template <class T>
class node {
    public :
        node<T>* next;
        T info;

    node<T>(){
        // nigga
    }
};

template <class T>
class linkedList {
    private:
        node<T>* head;
        node<T>* tail;

    public:
        // ctor
        linkedList(){
            head = NULL;
            tail = NULL;
        }

        // dtor
        ~linkedList(){
        }

        // Getter dan Setter
        node<T>* getHead(){
            return head;
        }

        T getHeadItem(){
            return head->info;
        }

        node<T>* getTail(){
            return tail;
        }

        node<T>* getNext(node<T> * currentNode){
          return currentNode->next;
        }

        // T getNextItem(T el){
        //
        // }

        // Mengembalikan indeks di mana el berada pada list. Mengembalikan -1 jika tidak ada
        int find(T el){
            node<T>* temp = new node<T>();
            bool Found = false;
            int i=0;
            temp = head;
            while(!Found && temp!=tail){
                if(el == temp->info){
                    Found=true;
                } else{
                    temp = temp->next;
                    i++;
                }
            }
            if (Found || temp->info==el){
                return i;
            } else {
                return -1;
            }
        }

        // Mengembalikan true jika list kosong
        bool isEmpty(){
            return (head == NULL);
        }

        // Menambahkan el sebagai elemen paling belakang pada linked list
        void add(T el){
            node<T>* temp = new node<T>();
            temp->info = el;
            temp->next = NULL;
            if (head == NULL){
                head = temp;
                tail = temp;
                temp = NULL;
            } else {
            tail->next = temp;
            tail = temp;
            }
        }

        // Membuang elemen dengan identitas demikian
        void remove(T el){
            node<T>* temp = new node<T>();
            node<T>* before = new node<T>();
            bool Found = false;
            bool isHead = false;
            temp = head;

            // periksa apakah head = el
            if (el == (temp -> info)){
                head = temp -> next;
                delete [] temp;
                return;
            }

            while (!Found && temp!=NULL){
                if (el == (temp->info)){
                    Found=true;
                } else{
                    before = temp;
                    temp = temp->next;
                }
            }
            if (Found){
                before->next = temp -> next;
                delete [] temp;
            }
        }

        // Mengembalikan elemen dengan tipe T pada indeks ke-i
        T get(int idx){
            node<T>* temp = new node<T>();
            int i;
            temp=head;
            for(i=0;i<idx;i++){
                temp=temp->next;
            }
            return temp->info;
        }
};

#endif