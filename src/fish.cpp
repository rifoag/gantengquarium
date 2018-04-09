#include "fish.hpp"
#include <stdlib.h>
#include <time.h>

using namespace std;

// ctor
fish::fish() : entity() {
	// digunakan untuk mengacak orientasi ikan
	srand(time(NULL));
	int orient = rand() % 4;

	growth = 1;
	fullRate = FULL_TIME;
	if (orient == 0){
		orientation = 'L'; // Kalo bisa dibuat random SIAP
	} else if (orient == 1){
		orientation = 'U'; // Kalo bisa dibuat random SIAP
	} else if (orient == 2){
		orientation = 'R'; // Kalo bisa dibuat random SIAP
	} else {
		orientation = 'D'; // Kalo bisa dibuat random SIAP
	}
	foodEaten = 0;
}

// ctor user defined
fish::fish(int x,int y) {
	// posisi x,y sama speed
	this->pos.first = x;
	this->pos.second = y;
	growth = 1;
	fullRate = FULL_TIME;
	foodEaten = 0;

	// digunakan untuk mengacak orientasi ikan
	srand(time(NULL));
	int orient = rand() % 4;
	if (orient == 0){
		orientation = 'L'; // Kalo bisa dibuat random SIAP
	} else if (orient == 1){
		orientation = 'U'; // Kalo bisa dibuat random SIAP
	} else if (orient == 2){
		orientation = 'R'; // Kalo bisa dibuat random SIAP
	} else {
		orientation = 'D'; // Kalo bisa dibuat random SIAP
	}
}

//dtor
fish::~fish() {
}

// cctor
fish::fish(const fish& other){
	growth = other.growth;
	fullRate = other.fullRate;
	orientation = other.orientation;
	foodEaten = other.foodEaten;
	pos = other.pos;
}

// operator = 
fish& fish::operator=(const fish& other){
	growth = other.growth;
	fullRate = other.fullRate;
	orientation = other.orientation;
	foodEaten = other.foodEaten;
	pos = other.pos;
	return *this;
}

// Getter dan Setter
// Mengembalikan fullRate ikan saat ini
int fish::GetFullRate() {
	return fullRate;
}
// Mengembalikan orientasi ikan saat ini
char fish::GetOrientation() {
	return orientation;
}
// Mengembalikan growth (pertumbuhan) ikan saat ini
short fish::getGrowth() {
	return growth;
}
// Menyetel fullRate ikan
void fish::setFullRate(int f) {
	fullRate = f;
}
// Menyetel orientasi ikan
void fish::setOrientation(char o) {
	orientation = o;
}
// Menyetel pertumbuhan ikan
void fish::setGrowth(short g) {
	growth = g;
}

// Ikan dapat bergerak dalam 360 derajat
void fish::move() {
	// ganti posisi ccd
	pos.first += 1;
	pos.second += 2;
}

// Makan
// Saat makan, fullRate terisi kembali
void fish::restoreFullRate(){
	fullRate = FULL_TIME;
}
// Mengembalikan true jika ikan lapar
bool fish::isStarving() {
	return (fullRate <= 0);
}
