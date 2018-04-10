#include "piranha.hpp"
#include "linkedList.hpp"
#include "oop.hpp"
#include <math.h>
using namespace std;


piranha::piranha() : fish(){
// default ctor
}


piranha::piranha(int x, int y) : fish(x,y){
// user-defined ctor
}


piranha::piranha(const piranha& other) : fish(other){
// cctor
}


piranha::~piranha(){
// dtor
}

piranha& piranha::operator=(const piranha& other){
    pos = other.pos;
    growth = other.growth;
    fullRate = other.fullRate;
    orientation = other.orientation;
    foodEaten = other.foodEaten;
    return *this;
}


void piranha::findFood(double diff, linkedList<guppy>& listGuppy, linkedList<coin>& listCoin){
// Saat lapar, piranha akan mendekati guppy yang ada di aquarium
	guppy Near = this->getNearestGuppy(listGuppy); 
	orientation = atan2(Near.getOrdinat() - this->pos.second, Near.getAbsis() - this->pos.first);
	this->pos.first += SPEED*diff*cos(orientation);
	this->pos.second += SPEED*diff*sin(orientation);
	eat(Near,listGuppy,listCoin);
}


void piranha::eat(guppy& prey,linkedList<guppy>& listGuppy,linkedList<coin>& listCoin){
// piranha memakan guppy terdekat darinya
	if (!listGuppy.isEmpty() && this->getDistance(prey) <= FOOD_RADIUS){
		fullRate = FULL_TIME;
		foodEaten++;
		if (foodEaten == FOOD_NEEDED && growth < 3){
			growth++;
			foodEaten = 0;
		}
		produceCoin(prey.getGrowth(),listCoin);
		listGuppy.remove(prey);
	}
}


void piranha::produceCoin(int guppyGrowth, linkedList<coin>& listCoin){
// piranha mengeluarkan koin setelah memakan guppy
	coin produced(price*(guppyGrowth+1),pos.first,pos.second);
	listCoin.add(produced);
}

guppy piranha::getNearestGuppy(linkedList<guppy>& prey) {
// mengembalikan guppy terdekat dari posisi piranha
	node<guppy>* temp = prey.getHead();
	guppy minGuppy = temp->info;
	temp = temp->next;
	while (temp != NULL) {
		if (this->getDistance(temp->info) < this->getDistance(minGuppy)) {
	  		minGuppy = temp->info;
		}
		temp = temp->next;
	}
	return minGuppy;
}

void piranha::move(double diff, linkedList<guppy>& listGuppy,linkedList<coin>& listCoin){
	if (isStarving() && !listGuppy.isEmpty()) {
		// Jika lapar, ia akan bergerak mendekati guppy terdekat
		findFood(diff,listGuppy,listCoin);
	} else {
		// berenang bebas
		fish::move(diff);
	}

    fullRate-=diff; // tingkat kekenyangan berkurang setiap waktu

	if (cos(orientation) > 0) {
	  draw_image("piranhaRight.png", pos.first, pos.second);
	} else {
	  draw_image("piranhaLeft.png", pos.first, pos.second);
	}
}
