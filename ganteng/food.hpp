#ifndef _FOOD_HPP
#define _FOOD_HPP
#include "entity.hpp"
#include "movingObject.hpp"

class food : public entity, public movingObject {
	private:
		const int FOOD_SPEED = 40;
    public:
        // ctor
        food();
        // ctor user defined
        food(int);
        // dtor
        ~food();
        // cctor
        food(const food&);
        // operator =
        food& operator=(const food&);

        // makanan ikan hanya bergerak ke arah bawah. Saat mencapai dasar akuarium, makanan menghilang
        void move(double diff);
        // mengembalikan nilai speed milik food
        int getSpeed();
};

#endif
