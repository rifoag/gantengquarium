# include "food.hpp"
food::food(): entity(){
}
food::food(int x) : entity(x, 0){
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

void food::move(){
	pos.second+=1;
}