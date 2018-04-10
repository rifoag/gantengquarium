# include "food.hpp"
#include "oop.hpp"

food::food(): entity(){

}
food::food(int x) : entity(x, 100){
	// Ikan selalu muncul di atas
}

food::~food(){
}

// cctor
food::food(const food& other){
	pos = other.pos;
}

// operator =
food& food::operator=(const food& other){
	pos = other.pos;
	return *this;
}

int food::getSpeed(){
	return FOOD_SPEED;
}

void food::move(double diff){
	if (pos.second < SCREEN_HEIGHT){
		pos.second += FOOD_SPEED*diff;
	}
	if (pos.second < 450) {
		draw_image("pillfood.png", pos.first, pos.second);
	} else {
		// hapus dari list
	}
}
