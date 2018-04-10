#ifndef _SNAIL_HPP
#define _SNAIL_HPP
#include "entity.hpp"
#include "coin.hpp"
#include "movingObject.hpp"
#include "linkedList.hpp"

#define pi 3.14159265358979323846

class snail : public entity {
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
        void move(double diff,linkedList<coin>& listCoin);

        // true bila koin berada pada radius (COIN_RADIUS)
        void takeCoin(coin& cc,linkedList<coin>& listCoin);
		bool operator==(const snail& other);
        coin getNearestCoin(linkedList<coin>& listCoin);
};

#endif
