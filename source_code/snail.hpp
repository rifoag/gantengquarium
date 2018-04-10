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
        const int COIN_RADIUS = 15; //Radius coin yang dapat diambil siput
        const int SPEED = 50;

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
        // Siput hanya bergerak saat terdapat coin di akuarium
        // Siput berdekat ke coin terdekat
        void move(double diff,linkedList<coin>& listCoin,double& money);

        // mengambil coin cc bila coin berada pada radius (COIN_RADIUS)
        void takeCoin(coin& cc,linkedList<coin>& listCoin, double& money);
		
        bool operator==(const snail& other);
        
        // mengembalikan coin terdekat dari posisi snail
        coin getNearestCoin(linkedList<coin>& listCoin);
};

#endif
