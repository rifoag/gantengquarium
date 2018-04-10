#ifndef _FOOD_HPP
#define _FOOD_HPP
#include "entity.hpp"
#include "linkedList.hpp"
#include "movingObject.hpp"

class food : public entity, public movingObject {
	private:
		const int FOOD_SPEED = 34;
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
        void move(double diff, linkedList<food>& listFood);
        // mengembalikan nilai speed milik food
        int getSpeed();
};

#endif
