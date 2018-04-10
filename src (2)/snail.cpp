#include "snail.hpp"
//#include "oop.hpp"
#include <random>
#include "linkedList.hpp"
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
void snail::move(double diff,linkedList<coin>& listCoin){
	// double diff = 0.5;
	//if (orientation == 'R'){
	if (!listCoin.isEmpty()){
		if (this->getNearestCoin(listCoin).getAbsis() > this->pos.first) {
			this->pos.first += SPEED*diff*1;
		} else if (this->getNearestCoin(listCoin).getAbsis() < this->pos.first) {
			this->pos.first += SPEED*diff*(-1);
		} else {
			this->pos.first += 0;
		}
	} else {
		this->pos.first += 0;
	}
    //pos.first = pos.first + diff*SPEED;
  //   draw_image("snailRight.png", pos.first, pos.second);
  // } else {
  //   pos.first = pos.first + diff*SPEED;
  //   draw_image("snailLeft.png", pos.first, pos.second);
  // }

  // if (pos.first > SCREEN_WIDTH - 20) {
  //     // cout << pos.first <<" to left" << endl;
  //     orientation = 'L';
  //     // initial = diff*SPEED;
  //     SPEED *= -1;
  // }  else if (pos.first < 20){
  //     // cout << pos.first<<" to right" << endl;
  //     orientation = 'R';
  //     // initial = diff*SPEED;
  //     SPEED *= -1;
  // }
}

coin snail::getNearestCoin(linkedList<coin>& listCoin) {
	node<coin>* temp = listCoin.getHead();
	coin minCoin = temp->info;
	temp = temp->next;
	while (temp != NULL) {
		if (this->getDistance(temp->info) < this->getDistance(minCoin)) {
	  		minCoin = temp->info;
		}
		temp = temp->next;
	}
	return minCoin;
}
void snail::takeCoin(coin& cc,linkedList<coin>& listCoin){
	if (this->getDistance(cc)<=COIN_RADIUS){
		listCoin.remove(cc);
	}
}
bool snail::operator==(const snail& other){
	return (this->entity::operator==(other)) && (this->orientation==other.orientation) && (this->SPEED==other.SPEED);
}
