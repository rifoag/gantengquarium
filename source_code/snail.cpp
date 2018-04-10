#include "snail.hpp"
#include "oop.hpp"
#include <random>
#include "linkedList.hpp"

snail::snail(){
// ctor
// snail selalu ada di bagian bawah akuarium
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(40, 600);
	this->pos.first = dist(gen);
	this->pos.second = 440;
}


snail::snail(int x,int y):entity(x,y){
// user-defined ctor	
}


snail::~snail(){
// dtor
}


snail::snail(const snail& other) : entity(other){
// cctor
}

snail& snail::operator=(const snail& other){
	pos = other.pos;
	return *this;
}


void snail::move(double diff,linkedList<coin>& listCoin, double& money){
// Siput hanya berada di dasar akuarium
// Siput hanya bergerak ke kiri dan ke kanan
// Siput hanya bergerak saat terdapat koin di akuarium
// Siput berdekat ke koin terdekat
	if (!listCoin.isEmpty()){
		coin Near = this->getNearestCoin(listCoin);
		if (Near.getAbsis() > this->pos.first) {
			this->pos.first += SPEED*diff*1;
			draw_image("snailRight.png", pos.first, pos.second);
		} else if (Near.getAbsis() < this->pos.first) {
			this->pos.first += SPEED*diff*(-1);
			draw_image("snailLeft.png", pos.first, pos.second);
		} else {
			draw_image("snailRight.png", pos.first, pos.second);
		}
		takeCoin(Near, listCoin, money);
	} else {
		this->pos.first += 0;
		draw_image("snailRight.png", pos.first, pos.second);
	}
}

coin snail::getNearestCoin(linkedList<coin>& listCoin) {
// mengembalikan coin terdekat dari posisi snail
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

void snail::takeCoin(coin& cc,linkedList<coin>& listCoin, double& money){
// mengambil coin cc bila coin berada pada radius (COIN_RADIUS)
	if (this->getDistance(cc)<=COIN_RADIUS){
		money += cc.getValue();
		listCoin.remove(cc);
	}
}

bool snail::operator==(const snail& other){
	return (this->entity::operator==(other)) && (this->SPEED==other.SPEED);
}
