#include "guppy.hpp"
#include "oop.hpp"
#include <cmath>
#include <random>
#include "linkedList.hpp"

// ctor
guppy::guppy() : fish(){
    // cout << "guppy added at " << pos.first <<"," <<pos.second << endl;
}

// ctor
guppy::guppy (int x,int y) : fish(x,y) {
}

// cctor
guppy::guppy (const guppy& g):fish(g) {
}

//operator =
guppy& guppy::operator=(const guppy& other){
    growth = other.growth;
    fullRate = other.fullRate;
    orientation = other.orientation;
    foodEaten = other.foodEaten;
    pos = other.pos;
    return *this;
}

// dtor
guppy::~guppy(){
}

void guppy::move(double diff,linkedList<food>& listFood){
  if (isStarving() && !listFood.isEmpty()){
	    findFood(diff,listFood); 
  } else{	  
	fish::move(diff);
  }

  if (cos(orientation) > 0) {
    if (growth == 1) {
      draw_image("ikanLv1Right.png", pos.first, pos.second);
    } else if (growth == 2) {
      draw_image("ikanLv2RightC.png", pos.first, pos.second);
    } else {
      draw_image("ikanLv3RightC.png", pos.first, pos.second);
    }
  } else {
    if (growth == 1) {
      draw_image("ikanLv1Left.png", pos.first, pos.second);
    } else if (growth == 2) {
      draw_image("ikanLv2LeftC.png", pos.first, pos.second);
    } else {
      draw_image("ikanLv3LeftC.png", pos.first, pos.second);
    }
  }

}

// Saat lapar, Guppy akan mendekati makanan ikan yang ada di akuarium
void guppy::findFood(double diff , linkedList<food>& listFood){
	food Near = this->getNearestFood(listFood);
	orientation = atan2(Near.getOrdinat() - this->getOrdinat() , Near.getAbsis() - this->getAbsis()) * 180/3.14159265;
	pos.first += SPEED*diff*orientation;
    pos.second += SPEED*diff*orientation;
}

// Guppy memakan makanan ikan
void guppy::eat(food& feed,linkedList<food>& listFood){
  if (!listFood.isEmpty()){
    if (this->getDistance(feed)<=FOOD_RADIUS){
      fullRate=FULL_TIME;
      foodEaten++;
      if (foodEaten==FOOD_NEEDED && growth<3){
        growth++;
        foodEaten=0;
      }
      listFood.remove(feed);
    }
  }
}

// Guppy mengeluarkan koin setiap periode tertentu
// Nilai koin = Growth * 5
void guppy::produceCoin(double diff,linkedList<coin>& listCoin){
  if (time>=5){
		coin produced(15,pos.first,pos.second);
		time=0;
		listCoin.add(produced);
	}else{
		time+=diff;
	}
}
food guppy::getNearestFood(linkedList<food>& feed) {
    node<food>* temp = feed.getHead();
    food minFood = temp->info;
    temp = temp->next;
    while (temp != NULL) {
      if (this->getDistance(temp->info) < this->getDistance(minFood)) {
        minFood = temp->info;
      }
      temp = temp->next;
    }
    return minFood;
}
