#ifndef _SNAIL_HPP
#define _SNAIL_HPP
#include "entity.hpp"
#include "coin.hpp"
#include "movingObject.hpp"

class snail : public entity, public movingObject {
    private:
        // Konstanta
        const int COIN_RADIUS=5; //Radius koin yang dapat diambil siput
        int SPEED = 50;
        char orientation;

    public:
        // ctor
        snail();
		// ctor user defined
		snail(int, int);// posisi
        // dtor
        ~snail();
        // cctor
        snail(const snail&);
        // operator =
        snail& operator=(const snail&);

        // Siput hanya berada di dasar akuarium
        // Siput hanya bergerak ke kiri dan ke kanan
        // Siput hanya bergerak saat terdapat koin di akuarium
        // Siput berdekat ke koin terdekat
        void move(double diff);

        // true bila koin berada pada radius (COIN_RADIUS)
        bool takeCoin(coin& cc);
};

#endif
