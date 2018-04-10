#ifndef _GUPPY_HPP
#define _GUPPY_HPP
#include "fish.hpp"
#include "food.hpp"
#include "linkedList.hpp"


class guppy : public fish {
    private:
        double time = 0;
        const int COIN_TIME = 7;
    public:
        // ctor
        guppy();
		// ctor
		guppy (int,int);//posisi dan speed
		// cctor
		guppy (const guppy&);
        // dtor
        ~guppy();

        // operator =
        guppy& operator=(const guppy&);

        void move(double diff, linkedList<food>& listFood);
        // Saat lapar, Guppy akan mendekati makanan ikan yang ada di akuarium
        void findFood(double diff, linkedList<food>& listFood);

        // Guppy memakan makanan ikan
        void eat(food& feed,linkedList<food>& listFood);

        // Guppy mengeluarkan koin setiap periode tertentu
        // Nilai koin = Growth * 5
        void produceCoin(double diff,linkedList<coin>& listCoin);
		// Mengembalikan food terdekat ke guppy pada listFood
        food getNearestFood(linkedList<food>& feed);
};

#endif
