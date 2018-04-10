#include "aquarium.hpp"
#include "linkedList.hpp"

 // ctor
// Memunculkan satu siput, dimensi akuarium maksimum
aquarium::aquarium(){
}

// dtor
aquarium::~aquarium(){
}

void aquarium::moveAll(double diff) {
// menggerakkan semua entity yang ada di aquarium
  node<guppy>* temp = listGuppy.getHead();
  node<guppy>* temp0;
  while (temp!=NULL){
    if (temp->info.GetFullRate()<=-12){
      temp0=temp->next;
      listGuppy.remove(temp->info);
      temp=temp0;
    }else{
      temp->info.move(diff,listFood);
      temp=temp->next;
    }
  }

  node<snail>* temp1 = listSnail.getHead();
  while (temp1!=NULL){
     temp1->info.move(diff,listCoin);
     temp1=temp1->next;
  }

  node<piranha>* temp2 = listPiranha.getHead();
  node<piranha>* temp4;
  while (temp2!=NULL){
    if (temp->info.GetFullRate()<=-12){
      temp4=temp2->next;
      listPiranha.remove(temp2->info);
      temp2=temp4;
    }else{
      temp2->info.move(diff,listGuppy);
      temp2=temp2->next;
    }
  }

  node<food>* temp3 = listFood.getHead();
  while (temp3!=NULL){
     temp3->info.move(diff);
     temp3=temp3->next;
  }
}

void aquarium::eatAllFish(){
  node<guppy>* temp = listGuppy.getHead();
	food Near;
	while (temp!=NULL){
		if (temp->info.isStarving()){
			Near=temp->info.getNearestFood(listFood);
			temp->info.eat(Near,listFood);
			temp=temp->next;
		}
  }
}// ikan yang lapar akan mencari makan jika tidak maka tidak terjadi apa apa
void aquarium::dropCoinAllFish(double diff){
  node<guppy>* temp = listGuppy.getHead();
	while (temp!=NULL){
		temp->info.produceCoin(diff,listCoin);
		temp=temp->next;
  }
} // ikan yang valid drop coinnya akan mengeluarkan koin, jika tidak maka waktu pengeluaran akan berkurang
void aquarium::takeCoinAllSnail(){} // semua snail mengambil coin jika ada koin di sekitarnya

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

void aquarium::delGuppy(int idx){
  // menghapus seekor guppy pada listGuppy
  listGuppy.remove(listGuppy.get(idx));
}
void aquarium::delPiranha(int idx){
  // menghapus seekor piranha pada listPiranha
  listPiranha.remove(listPiranha.get(idx));
}
void aquarium::delCoin(int idx){
  // menghapus sebuah koin pada listCoin
  listCoin.remove(listCoin.get(idx));
}
void aquarium::delFood(int idx){
  // menghapus sebuah makanan pada listFood
  listFood.remove(listFood.get(idx));
}
bool aquarium::isEmptyCoin(){
  // bernilai true apabila tidak ada koin di akuarium
  return listCoin.isEmpty();
}
bool aquarium::isEmptyFood(){
  // bernilai true apabila tidak ada makanan di akuariu
  return listFood.isEmpty();
} 

int aquarium::findIdxGuppy(guppy el){
    int idx = listGuppy.find(el);
    return idx;
} // mengembalikan indeks di mana el berada pada listFish
int aquarium::findIdxPiranha(piranha el){
    int idx = listPiranha.find(el);
    return idx;
} // mengembalikan indeks di mana el berada pada listFish
int aquarium::findIdxCoin(coin el){
    int idx = listCoin.find(el);
    return idx;
} // mengembalikan indeks di mana el berada pada listCoin
int aquarium::findIdxFood(food el){
    int idx = listFood.find(el);
    return idx;
} //mengembalikan indeks di mana el berada pada listFoo

guppy aquarium::findGuppy(int id){
    // mengembalikan guppy dengan indeks ke id
    guppy search = listGuppy.get(id);
    return search;
}
piranha aquarium::findPiranha(int id){
    piranha search = listPiranha.get(id);
    return search;
} // mengembalikan piranha dengan indeks ke id
coin aquarium::getCoin(int id){
    coin search = listCoin.get(id);
    return search;
} // mengembalikan koin dengan indeks ke id
food aquarium::getFood(int id){
    food search = listFood.get(id);
    return search;
} // mengembalikan makanan dengan indeks ke id

bool aquarium::isThereIsNoFish() {
  return (listGuppy.getHead() == NULL) && (listPiranha.getHead() == NULL);
}
