# include "food.hpp"
#include "oop.hpp"

food::food(): entity(){
// ctor default
}
food::food(int x) : entity(x, 100){
// Makanan ikan selalu muncul di atas
}

food::~food(){
// dtor
}


food::food(const food& other){
// cctor
	pos = other.pos;
}

food& food::operator=(const food& other){
	pos = other.pos;
	return *this;
}

int food::getSpeed(){
	return FOOD_SPEED;
}

void food::move(double diff){
}

void food::move(double diff, linkedList<food>& listFood){
	if (pos.second < SCREEN_HEIGHT){
		pos.second += FOOD_SPEED*diff;
	}
	if (pos.second < 450) {
		draw_image("pillfood.png", pos.first, pos.second);
	} else {
		listFood.remove(*this);
	}
}
