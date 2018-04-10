#include "fish.hpp"
#include <stdlib.h>
#include <time.h>
#include <random>
#include <cmath>
#include "oop.hpp"

using namespace std;

// ctor
fish::fish() : entity() {
	// digunakan untuk mengacak orientasi ikan
	// srand((int)time(0));
	// // int orient = rand() % 4;
	// this->pos.first = rand() % 640;
	// this->pos.second = rand() % 280 + 130;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(40, 600);
	uniform_int_distribution<> dist2(130, 400);
	uniform_int_distribution<> dist3(0, 360);
	this->pos.first = dist(gen);
	this->pos.second = dist2(gen);

	growth = 1;
	fullRate = FULL_TIME;
	// if (orient == 0){
	// 	orientation = 'L'; // Kalo bisa dibuat random SIAP
	// } else if (orient == 1){
	// 	orientation = 'U'; // Kalo bisa dibuat random SIAP
	// } else if (orient == 2){
	// 	orientation = 'R'; // Kalo bisa dibuat random SIAP
	// } else {
	// 	orientation = 'D'; // Kalo bisa dibuat random SIAP
	// }

	// int orient = rand() % 2;
	// if (orient == 0){
	// 	SPEED *= -1;
	// 	orientation = 'L'; // Kalo bisa dibuat random SIAP
	// } else {
	// 	orientation = 'R'; // Kalo bisa dibuat random SIAP
	// }

	orientation = dist3(gen);

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
	srand((int)time(NULL));
	// int orient = rand() % 4;
	// if (orient == 0){
	// 	orientation = 'L'; // Kalo bisa dibuat random SIAP
	// } else if (orient == 1){
	// 	orientation = 'U'; // Kalo bisa dibuat random SIAP
	// } else if (orient == 2){
	// 	orientation = 'R'; // Kalo bisa dibuat random SIAP
	// } else {
	// 	orientation = 'D'; // Kalo bisa dibuat random SIAP
	// }

	int orient = rand() % 2;
	if (orient == 0){
		orientation = 'L'; // Kalo bisa dibuat random SIAP
	} else {
		orientation = 'R'; // Kalo bisa dibuat random SIAP
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
void fish::setFullRate(double f) {
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
void fish::move(double diff) {
	// random working
  if (pos.first > SCREEN_WIDTH - 40 || pos.first < 40 || pos.second < 130 || pos.second > 400) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 360);
    if (pos.first > SCREEN_WIDTH - 40 && pos.second < 130){
      // pojok kanan atas
      uniform_int_distribution<> dist(181, 270);
      pos.first = SCREEN_WIDTH - 40;
      pos.second = 130;
    } else if (pos.first > SCREEN_WIDTH - 40 && pos.second > 400){
      // pojok kanan bawah
      uniform_int_distribution<> dist(91, 180);
      pos.first = SCREEN_WIDTH - 40;
      pos.second = 4000;
    } else if (pos.first < 40 && pos.second > 400){
      // pojok kiri bawah
      uniform_int_distribution<> dist(1, 90);
      pos.first = 40;
      pos.second = 400;
    } else if (pos.first < 40 && pos.second < 130){
      // pojok kiri atas
      uniform_int_distribution<> dist(271, 360);
      pos.first = 40;
      pos.second = 130;
    } else if (pos.first > SCREEN_WIDTH - 40){
      // kiri
      uniform_int_distribution<> dist(-89, 90);
      pos.first = SCREEN_WIDTH - 40;
      // pos.second = 130;
    } else if (pos.first < 40){
      // kanan
      uniform_int_distribution<> dist(91, 270);
      pos.first = 40;
      // pos.second = 130;
    } else if (pos.second < 130){
      // atas
      uniform_int_distribution<> dist(181, 360);
      // pos.first = SCREEN_WIDTH - 40;
      pos.second = 130;
    } else {
      // bawah
      uniform_int_distribution<> dist(1, 180);
      // pos.first = SCREEN_WIDTH - 40;
      pos.second = 400;
    }
    orientation = dist(gen);
  }

  pos.first += SPEED*diff*cos(orientation);
  pos.second += SPEED*diff*sin(orientation);
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
bool fish::operator==(const fish& other){
	return (this->entity::operator==(other)) && (this->growth==other.growth) && (this->fullRate==other.fullRate) && (this->orientation==other.orientation) && (this->foodEaten==other.foodEaten) && (this->SPEED==other.SPEED);
}
