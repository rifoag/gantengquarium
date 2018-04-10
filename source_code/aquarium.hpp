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
		aquarium(int,int);
        // dtor
        ~aquarium();

        void moveAll(double diff, double& money); // menggerakkan semua entity yang ada di aquarium
        
        void moveGuppy(double diff); // menggerakkan seluruh guppy yang ada di aquarium
        void moveSnail(double diff, double& money); // menggerakkan seluruh snail yang ada di aquarium
        void movePiranha(double diff); // menggerakkan seluruh piranha yang ada di aquarium
        void moveFood(double diff); // menggerakkan seluruh food yang ada di aquarium
        void moveCoin(double diff); // menggerakkan seluruh koin yang ada di aquarium

        void addGuppy(); // menambahkan seekor guppy pada listFish
        void addPiranha(); // menambahkan seekor piranha pada listFish
        void addCoin(); // menambahkan sebuah koin pada listCoin
        void addSnail(); // Menambahkan seekor siput pada listSnail
        void addFood(int x); // menambahkan sebuah makanan pada listFood

        bool isThereIsNoFish(); // mengembalikan true bila tidak ada ikan di akuarium
};

#endif
