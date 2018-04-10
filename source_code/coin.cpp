#include "coin.hpp"
#include "oop.hpp"


coin::coin() {
// Ctor koin dari guppy, muncul di bagian atas akuarium, default = 15
	value = 15;
}


coin::coin(int val, double x, double y):entity(x,y) {
// Ctor user-defined
	value = val;
}


coin::coin(const coin& c) {
// cctor
	this->value = c.value;
	this->pos.first = c.pos.first;
	this->pos.second = c.pos.second;
}


coin::~coin() {
//dtor
}


coin& coin::operator=(const coin& other){
	pos = other.pos;
	value = other.value;
	return *this;
}

bool coin::operator==(const coin& other){
	return (this->entity::operator==(other)) && (this->value==other.value);
}

//Getter dan Setter value
int coin::getValue() {
	return value;
}
void coin::setValue(int val) {
	value = val;
}


void coin::move(double diff) {
// Koin bergerak ke arah bawah saja dan ia diam saat mencapai dasar akuarium
	if (pos.second < 450){
		pos.second += diff*40;
	}
	draw_image("coin.png", pos.first, pos.second);
}