#include "snail.hpp"

// ctor
snail::snail(){
}

// user-defined ctor
snail::snail(int x,int y):entity(x,y){
}

// dtor
snail::~snail(){
}

// cctor
snail::snail(const snail& other) : entity(other){
}

// operator =
snail& snail::operator=(const snail& other){
	pos = other.pos;
	return *this;
}

// Siput hanya berada di dasar akuarium
// Siput hanya bergerak ke kiri dan ke kanan
// Siput hanya bergerak saat terdapat koin di akuarium
// Siput berdekat ke koin terdekat
void snail::move(){
	pos.first+=1;
	pos.second+=1;
}

bool snail::takeCoin(coin& cc){
}