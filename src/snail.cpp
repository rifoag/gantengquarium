#include "snail.hpp"
#include "oop.hpp"
#include <random>

// ctor
snail::snail(){
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(40, 600);
	// uniform_int_distribution<> dist2(200, 400);
	this->pos.first = dist(gen);
	this->pos.second = 440;
	int orient = rand() % 2;
	if (orient == 0){
		SPEED *= -1;
		orientation = 'L'; // Kalo bisa dibuat random SIAP
	} else {
		orientation = 'R'; // Kalo bisa dibuat random SIAP
	}
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
void snail::move(double diff){
	// double diff = 0.5;
	if (orientation == 'R'){
    pos.first = pos.first + diff*SPEED;
    draw_image("snailRight.png", pos.first, pos.second);
  } else {
    pos.first = pos.first + diff*SPEED;
    draw_image("snailLeft.png", pos.first, pos.second);
  }

  if (pos.first > SCREEN_WIDTH - 20) {
      cout << pos.first <<" to left" << endl;
      orientation = 'L';
      // initial = diff*SPEED;
      SPEED *= -1;
  }  else if (pos.first < 20){
      cout << pos.first<<" to right" << endl;
      orientation = 'R';
      // initial = diff*SPEED;
      SPEED *= -1;
  }
}

bool snail::takeCoin(coin& cc){
}
