#ifndef _AQUARIUM_HPP
#define _AQUARIUM_HPP
#include "guppy.hpp"
#include "piranha.hpp"
#include "food.hpp"
#include "coin.hpp"
#include "snail.hpp"

template <class T>
class linkedList {
    struct node {
        T info;
        node* next;
    };
    
    private:
        node* head;
        node* tail;

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
        node* getHead(){
            return head;
        }

        node* getTail(){
            return tail;
        }

        // Mengembalikan indeks di mana el berada pada list. Mengembalikan -1 jika tidak ada
        int find(T el){
            node* temp = new node;
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
            } else{
                return -1;
            }
        }

        // Mengembalikan true jika list kosong
        bool isEmpty(){
            return (head == NULL);
        }

        // Menambahkan el sebagai elemen paling belakang pada linked list
        void add(T el){
            node* temp = new node;
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
            node* temp = new node;
            node* before = new node;
            bool Found = false;
            int i=0;
            temp = head;
            while (!Found && temp!=tail){
                if (el == temp->info){
                    Found=true;
                } else{
                    before = temp;
                    temp = temp->next;
                    i++;
                }
            }
            if (Found || temp->info==el){
                before->next = temp ->next;
                delete [] temp;
            }
        }
        
        // Mengembalikan elemen dengan tipe T pada indeks ke-i
        T get(int idx){
            node* temp = new node;
            int i;
            temp=head;
            for(i=0;i<idx;i++){
                temp=temp->next;
            }
            return temp->info;
        }
};

class aquarium {
    private:
        const int MAX_LENGTH = 640;
        const int MAX_WIDTH = 480;

        linkedList<guppy> listGuppy;
        linkedList<piranha> listPiranha;
        linkedList<coin> listCoin;
        linkedList<snail> listSnail;
        linkedList<food> listFood;
    
    public:
        // ctor
        // Memunculkan beberapa guppy, satu piranha, dan satu siput dgn ukuran maksimum
        aquarium();
		// ctor defined
		// membuat aquarium dgn ukuran b dan k
		aquarium (int,int);
        // dtor
        ~aquarium();
		
        void moveAll(); // menggerakkan semua entity yang ada di aquarium
		
        void eatAllFish();// ikan yang lapar akan mencari makan jika tidak maka tidak terjadi apa apa
		void dropCoinAllFish(); // ikan yang valid drop coinnya akan mengeluarkan koin, jika tidak maka waktu pengeluaran akan berkurang
		void takeCoinAllSnail(); // semua snail mengambil coin jika ada koin di sekitarnya
        
        void addGuppy(); // menambahkan seekor guppy pada listFish
        void addPiranha(); // menambahkan seekor piranha pada listFish
        void addCoin(); // menambahkan sebuah koin pada listCoin
        void addSnail(); // Menambahkan seekor siput pada listSnail
        void addFood(); // menambahkan sebuah makanan pada listFood
        
        void delGuppy(int idx); // menghapus seekor guppy pada listFish
        void delPiranha(int idx); // menghapus seekor piranha pada listFish
        void delCoin(int idx); // menghapus sebuah koin pada listCoin
        void delFood(int idx); // menghapus sebuah makanan pada listFood

        bool isEmptyCoin(); // bernilai true apabila tidak ada koin di akuarium
        bool isEmptyFood(); // bernilai true apabila tidak ada makanan di akuarium

        int findIdxGuppy(guppy el); // mengembalikan indeks di mana el berada pada listFish
        int findIdxPiranha(piranha el); // mengembalikan indeks di mana el berada pada listFish
        int findIdxCoin(coin el); // mengembalikan indeks di mana el berada pada listCoin
        int findIdxFood(food el); //mengembalikan indeks di mana el berada pada listFood

        guppy findGuppy(int id); // mengembalikan guppy dengan indeks ke id
        piranha findPiranha(int id); // mengembalikan piranha dengan indeks ke id
        coin getCoin(int id); // mengembalikan koin dengan indeks ke id
        food getFood(int id); // mengembalikan makanan dengan indeks ke id
};

#endif