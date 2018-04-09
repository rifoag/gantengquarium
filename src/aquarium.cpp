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
  while (temp!=NULL){
     temp->info.move(diff);
     temp=temp->next;
  }
}

void aquarium::eatAllFish(){}// ikan yang lapar akan mencari makan jika tidak maka tidak terjadi apa apa
void dropCoinAllFish(){} // ikan yang valid drop coinnya akan mengeluarkan koin, jika tidak maka waktu pengeluaran akan berkurang
void takeCoinAllSnail(){} // semua snail mengambil coin jika ada koin di sekitarnya

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
void aquarium::addFood(){
  // menambahkan sebuah makanan pada listFood
    food new_food;
    listFood.add(new_food);
}

void aquarium::delGuppy(int idx){
  // menghapus seekor guppy pada listGuppy
  // listGuppy.remove(listGuppy.get(idx));
}
void aquarium::delPiranha(int idx){} // menghapus seekor piranha pada listPiranha
void aquarium::delCoin(int idx){} // menghapus sebuah koin pada listCoin
void aquarium::delFood(int idx){} // menghapus sebuah makanan pada listFoo
bool aquarium::isEmptyCoin(){} // bernilai true apabila tidak ada koin di akuarium
bool aquarium::isEmptyFood(){} // bernilai true apabila tidak ada makanan di akuariu

int aquarium::findIdxGuppy(guppy el){} // mengembalikan indeks di mana el berada pada listFish
int aquarium::findIdxPiranha(piranha el){} // mengembalikan indeks di mana el berada pada listFish
int aquarium::findIdxCoin(coin el){} // mengembalikan indeks di mana el berada pada listCoin
int aquarium::findIdxFood(food el){} //mengembalikan indeks di mana el berada pada listFoo

guppy aquarium::findGuppy(int id){
    // mengembalikan guppy dengan indeks ke id
    guppy search = listGuppy.get(id);
    // cout << search.GetOrientation() << endl;
    return search;
}
piranha aquarium::findPiranha(int id){} // mengembalikan piranha dengan indeks ke id
coin aquarium::getCoin(int id){} // mengembalikan koin dengan indeks ke id
food aquarium::getFood(int id){} // mengembalikan makanan dengan indeks ke id
