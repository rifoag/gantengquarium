#include "piranha.hpp"

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
void piranha::findFood(){
}

// piranha memakan guppy
void piranha::eat(guppy& prey){
}

// piranha mengeluarkan koin setelah memakan guppy
// Nilai koin = harga ikan * (tahap guppy yang dimakan + 1)
void piranha::produceCoin(int guppyGrowth){
}