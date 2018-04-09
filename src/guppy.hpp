#ifndef _GUPPY_HPP
#define _GUPPY_HPP
#include "fish.hpp"
#include "food.hpp"

class guppy : public fish {
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

        // Saat lapar, Guppy akan mendekati makanan ikan yang ada di akuarium
        void findFood();

        // Guppy memakan makanan ikan
        void eat(food& feed);

        // Guppy mengeluarkan koin setiap periode tertentu
        // Nilai koin = Growth * 5
        void produceCoin();
};

#endif