#ifndef _GUPPY_HPP
#define _GUPPY_HPP
#include "fish.hpp"
#include "food.hpp"
#include "linkedList.hpp"


class guppy : public fish {
    private:
        double time=0;
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

        void move(double diff);
        // Saat lapar, Guppy akan mendekati makanan ikan yang ada di akuarium
        void findFood();

        // Guppy memakan makanan ikan
        void eat(food& feed,linkedList<food>& listFood);

        // Guppy mengeluarkan koin setiap periode tertentu
        // Nilai koin = Growth * 5
        void produceCoin(double diff,linkedList<coin>& listCoin);
		food getNearestFood(linkedList<food>& feed);
};

#endif
