#include "guppy.hpp"
#include "oop.hpp"
#include <cmath>
#include <random>
#include "linkedList.hpp"


guppy::guppy() : fish(){
// ctor default
}


guppy::guppy (int x,int y) : fish(x,y) {
// ctor user-defined
}


guppy::guppy (const guppy& g):fish(g) {
// cctor
}

guppy& guppy::operator=(const guppy& other){
    growth = other.growth;
    fullRate = other.fullRate;
    orientation = other.orientation;
    foodEaten = other.foodEaten;
    pos = other.pos;
    return *this;
}


guppy::~guppy(){
// dtor
}

void guppy::move(double diff,linkedList<food>& listFood){

  if (isStarving() && !listFood.isEmpty()){
      // Jika lapar, guppy bergerak mendekati makanan (jika ada)
	    findFood(diff,listFood); 
  } else {	
     // bergerak bebas
	   fish::move(diff);
  }

  fullRate-=diff; // tingkat kekenyangan berkurang

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


void guppy::findFood(double diff , linkedList<food>& listFood){
// Saat lapar, Guppy akan mendekati makanan ikan yang ada di akuarium
	food Near = this->getNearestFood(listFood);
	orientation = atan2(Near.getOrdinat() - this->getOrdinat() , Near.getAbsis() - this->getAbsis()) * 180/3.14159265;
	
  pos.first += SPEED*diff*cos(orientation);
  pos.second += SPEED*diff*sin(orientation);

  eat(Near, listFood);
}


void guppy::eat(food& feed,linkedList<food>& listFood){
// Guppy memakan makanan ikan yang berada pada radius makannya
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


void guppy::produceCoin(double diff,linkedList<coin>& listCoin){
// Guppy mengeluarkan koin setiap periode tertentu
  if (time >= COIN_TIME){
		coin produced(growth*5,pos.first,pos.second);
		time = 0;
		listCoin.add(produced);
	} else{
		time+= diff;
	}
}

food guppy::getNearestFood(linkedList<food>& feed) {
// Mengembalikan food terdekat ke guppy pada listFood
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
