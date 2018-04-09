#include "guppy.hpp"

// ctor
guppy::guppy() : fish(){
    cout << "guppy added" << endl;
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

// Saat lapar, Guppy akan mendekati makanan ikan yang ada di akuarium
void guppy::findFood(){

}

// Guppy memakan makanan ikan
void guppy::eat(food& feed){

}

// Guppy mengeluarkan koin setiap periode tertentu
// Nilai koin = Growth * 5
void guppy::produceCoin(){
	
}