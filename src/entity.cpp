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
	// Kecuali :
	// Jika parameter tertentu bernilai -1, maka akan digenerate nilai random dari 0 sampai MAX_WIDTH/MAX_LENGTH nya.
	// Jika y bernilai -2, maka akan koordinat y yang ada di daerah atas peta (0~BATAS_ATAS)
	srand(time(NULL));

	if (x == -1){
		x = rand() % 640;
	}

	if (y == -1){
		y = rand() % 480;
	}

	pos = std::pair<double,double>(x,y);
}

entity::entity(const entity& other){
	int x=other.pos.first,y=other.pos.second;
	pos = std::pair<double,double>(x,y);
}

// operator =
entity& entity::operator=(const entity& other){
	pos = other.pos;
	return *this;
}

entity::~entity(){
}

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
	return sqrt(pow(this->pos.first-e1.pos.first,2)+pow(this->pos.second-e1.pos.second,2));
}
