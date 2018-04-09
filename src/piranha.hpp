#ifndef _PIRANHA_HPP
#define _PIRANHA_HPP
#include "fish.hpp"
#include "guppy.hpp"

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
        void findFood();

        // piranha memakan guppy yang berada pada radius
        void eat(guppy&);

        // piranha mengeluarkan koin setelah memakan guppy
        // Nilai koin = harga ikan * (tahap guppy yang dimakan + 1)
        void produceCoin(int guppyGrowth);
};

#endif