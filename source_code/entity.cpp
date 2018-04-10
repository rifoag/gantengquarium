#include "entity.hpp"
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define BATAS_ATAS 150

entity::entity(){
	// Memunculkan entitas di posisi acak
	srand(time(NULL));

	pos.first = rand() % 640;
	pos.second = rand() % 480;
}

entity::entity(double x, double y){
// Memunculkan entitas sesuai dengan parameter yang diterima
	pos = std::pair<double,double>(x,y);
}

entity::entity(const entity& other){
// cctor
	int x=other.pos.first,y=other.pos.second;
	pos = std::pair<double,double>(x,y);
}


entity& entity::operator=(const entity& other){
	pos = other.pos;
	return *this;
}

entity::~entity(){
}

// Getter dan Setter
int entity::getAbsis(){
	return pos.first;
}

int entity::getOrdinat(){
	return pos.second;
}

void entity::setPos(double x, double y){
	pos = std::make_pair(x,y);
}

bool entity::operator == (const entity& other){
	return (this->pos.first==other.pos.first) && (this->pos.second==other.pos.second);
}

double entity::getDistance(const entity& e1) {
// mengembalikan jarak antara entitas dengan el
	return sqrt(pow(this->pos.first-e1.pos.first,2)+pow(this->pos.second-e1.pos.second,2));
}