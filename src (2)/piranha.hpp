#ifndef _PIRANHA_HPP
#define _PIRANHA_HPP
#include "fish.hpp"
#include "guppy.hpp"
#include "linkedList.hpp"

#define pi 3.14159265358979323846

class piranha : public fish {
    private:
        int price; // harga piranha

    public:
        // ctor
        piranha();
		    // ctor
		    piranha(int, int);
		    // cctor
		    piranha(const piranha&);
        // dtor
        ~piranha();
        // operator =
        piranha& operator=(const piranha&);

        // Saat lapar, piranha akan mendekati guppy yang ada di akuarium
        void findFood(double diff, linkedList<guppy>& listGuppy);

        // piranha memakan guppy yang berada pada radius
        void eat(guppy&,linkedList<guppy>& listGuppy,linkedList<coin>& listCoin);

        // piranha mengeluarkan koin setelah memakan guppy
        // Nilai koin = harga ikan * (tahap guppy yang dimakan + 1)
        void produceCoin(int guppyGrowth, linkedList<coin>& listCoin);
		guppy getNearestGuppy(linkedList<guppy>& gupay);
        void move(double diff,linkedList<guppy>& listGuppy);
     
};

#endif
