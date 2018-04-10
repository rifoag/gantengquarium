#include "aquarium.hpp"
#include "linkedList.hpp"

 // ctor
// Memunculkan satu siput, dimensi akuarium maksimum
aquarium::aquarium(){
}

// dtor
aquarium::~aquarium(){
}

void aquarium::moveAll(double diff, double& money) {
// menggerakkan semua entity yang ada di aquarium
  moveGuppy(diff);
  moveSnail(diff, money);
  movePiranha(diff);
  moveFood(diff);
  moveCoin(diff);
}

void aquarium::moveGuppy(double diff){
// Menggerakkan seluruh guppy
  node<guppy>* tempGuppy = listGuppy.getHead();
  node<guppy>* tempGuppy_2;
  while (tempGuppy != NULL){
    if (tempGuppy->info.GetFullRate() <= -12){
      // Guppy mati
      tempGuppy_2 = tempGuppy->next;
      listGuppy.remove(tempGuppy->info);
      tempGuppy = tempGuppy_2;
    } else {
      tempGuppy->info.produceCoin(diff,listCoin);
      tempGuppy->info.move(diff,listFood);
      tempGuppy = tempGuppy->next;
    }
  }
}

void aquarium::moveSnail(double diff, double& money){
// Mengerakkan seluruh snail
  node<snail>* tempSnail = listSnail.getHead();
  while (tempSnail != NULL){
     tempSnail->info.move(diff,listCoin,money);
     tempSnail = tempSnail->next;
  }
}

void aquarium::movePiranha(double diff){
// Menggerakkan seluruh piranha
  node<piranha>* tempPiranha = listPiranha.getHead();
  node<piranha>* tempPiranha_2;
  while (tempPiranha != NULL){
    if (tempPiranha->info.GetFullRate() <= -12){
      // Piranha mati
      tempPiranha_2=tempPiranha->next;
      listPiranha.remove(tempPiranha->info);
      tempPiranha=tempPiranha_2;
    } else {
      tempPiranha->info.move(diff,listGuppy,listCoin);
      tempPiranha=tempPiranha->next;
    }
  }
}

void aquarium::moveFood(double diff){
// Menggerakkan seluruh food
  node<food>* tempFood = listFood.getHead();
  while (tempFood != NULL){
     tempFood->info.move(diff, listFood);
     tempFood = tempFood->next;
  }
}

void aquarium::moveCoin(double diff){
// Menggerakkan seluruh coin
  node<coin>* tempCoin = listCoin.getHead();
  while(tempCoin != NULL){
    tempCoin->info.move(diff);
    tempCoin = tempCoin->next;
  }
}

void aquarium::addGuppy(){
// menambahkan seekor guppy pada list Guppy
    guppy new_guppy;
    listGuppy.add(new_guppy);
}

void aquarium::addPiranha(){
// menambahkan seekor piranha pada listFish
    piranha new_piranha;
    listPiranha.add(new_piranha);
}

void aquarium::addCoin(){
// menambahkan sebuah koin pada listCoin
    coin new_coin;
    listCoin.add(new_coin);
}

void aquarium::addSnail(){
// Menambahkan seekor siput pada listSnail
    snail new_snail;
    listSnail.add(new_snail);
}

void aquarium::addFood(int x){
  // menambahkan sebuah makanan pada listFood
    food new_food(x);
    listFood.add(new_food);
}

bool aquarium::isThereIsNoFish() {
  return (listGuppy.getHead() == NULL) && (listPiranha.getHead() == NULL);
}
