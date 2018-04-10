#ifndef _AQUARIUM_HPP
#define _AQUARIUM_HPP
#include "guppy.hpp"
#include "piranha.hpp"
#include "food.hpp"
#include "coin.hpp"
#include "snail.hpp"
#include "linkedList.hpp"

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

        void moveAll(double diff); // menggerakkan semua entity yang ada di aquarium

        void eatAllFish();// ikan yang lapar akan mencari makan jika tidak maka tidak terjadi apa apa
		void dropCoinAllFish(double diff); // ikan yang valid drop coinnya akan mengeluarkan koin, jika tidak maka waktu pengeluaran akan berkurang
		void takeCoinAllSnail(); // semua snail mengambil coin jika ada koin di sekitarnya

        void addGuppy(); // menambahkan seekor guppy pada listFish
        void addPiranha(); // menambahkan seekor piranha pada listFish
        void addCoin(); // menambahkan sebuah koin pada listCoin
        void addSnail(); // Menambahkan seekor siput pada listSnail
        void addFood(int x); // menambahkan sebuah makanan pada listFood

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

        bool isThereIsNoFish();
};

#endif
