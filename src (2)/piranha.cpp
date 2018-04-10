#include "piranha.hpp"
#include "linkedList.hpp"
//#include "oop.hpp"
#include <math.h>
using namespace std;

// ctor
piranha::piranha() : fish(){
}

// ctor
piranha::piranha(int x, int y) : fish(x,y){
}

// cctor
piranha::piranha(const piranha& other) : fish(other){
}

// operator =
piranha& piranha::operator=(const piranha& other){
    pos = other.pos;
    growth = other.growth;
    fullRate = other.fullRate;
    orientation = other.orientation;
    foodEaten = other.foodEaten;
    return *this;
}

// dtor
piranha::~piranha(){
}

// Saat lapar, piranha akan mendekati guppy yang ada di akuarium
void piranha::findFood(double diff, linkedList<guppy>& listGuppy){
	orientation = atan2(this->getNearestGuppy(listGuppy).getOrdinat()-this->pos.second, this->getNearestGuppy(listGuppy).getAbsis()-this->pos.first);
	orientation = orientation * pi / 180;
	this->pos.first += SPEED*diff*cos(orientation);
	this->pos.second += SPEED*diff*sin(orientation);
}

// piranha memakan guppy
void piranha::eat(guppy& prey,linkedList<guppy>& listGuppy,linkedList<coin>& listCoin){
	if (!listGuppy.isEmpty && this->getDistance(prey)<=FOOD_RADIUS){
		fullRate=FULL_TIME;
		foodEaten++;
		if (foodEaten==FOOD_NEEDED && growth<3){
			growth++;
			foodEaten=0;
		}
		produceCoin(prey.getGrowth(),listCoin);
		listGuppy.remove(prey);
	}
}

// piranha mengeluarkan koin setelah memakan guppy
// Nilai koin = harga ikan * (tahap guppy yang dimakan + 1)
void piranha::produceCoin(int guppyGrowth, linkedList<coin>& listCoin){
	coin produced(price*(guppyGrowth+1),pos.first,pos.second);
	listCoin.add(produced);
}

guppy piranha::getNearestGuppy(linkedList<guppy>& gupay) {
	node<guppy>* temp = gupay.getHead();
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

void piranha::move(double diff, linkedList<guppy>& listGuppy){
	if (isStarving() && !listGuppy.isEmpty()) {
		findFood(diff,listGuppy);
	} else {
		fish::move(diff);
	}

	// if (cos(orientation) > 0) {
	//   draw_image("piranhaRight.png", pos.first, pos.second);
	// } else {
	//   draw_image("piranhaLeft.png", pos.first, pos.second);
	// }
}
