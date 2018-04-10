#include "coin.hpp"

// ctor
// koin dimunculkan di bagian atas akuarium
// nilai value diisi val
coin::coin() {
	// Ctor koin dari guppy, muncul di bagian atas akuarium, default = 15
	value = 15;
}

// Ctor user-defined
coin::coin(int val) {
	value = val;
}

// cctor
coin::coin(const coin& c) {
	this->value = c.value;
	this->pos.first = c.pos.first;
	this->pos.second = c.pos.second;
}

// dtor
coin::~coin() {
}

// operator =
coin& coin::operator=(const coin& other){
	pos = other.pos;
	value = other.value;
	return *this;
}

//Getter dan Setter value
int coin::getValue() {
	return value;
}

void coin::setValue(int val) {
	value = val;
}

// Koin bergerak ke arah bawah saja dan ia diam saat mencapai dasar akuarium
void coin::move(double diff) {
	pos.second += 1;
}
