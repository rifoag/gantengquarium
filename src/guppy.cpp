#include "guppy.hpp"
#include "oop.hpp"

// ctor
guppy::guppy() : fish(){
    // posx = 100;
    // posy = 199;
    // pos.first = 100;
    // pos.second = 100;
    cout << "guppy added at " << pos.first <<"," <<pos.second << endl;
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

void guppy::move(double diff){
  // double diff = 10;
  // ganti posisi ccd
	// posx += diff;
  // draw_image("ikanLv1Right.png", posx, posy);
  int initial = 0;
	// cout << posx <<" "<< posy<<endl;
  if (orientation == 'R'){
    pos.first = pos.first + diff*SPEED + initial;
    draw_image("ikanLv1Right.png", pos.first, pos.second);
  } else {
    pos.first = pos.first + diff*SPEED - initial;
    draw_image("ikanLv1Left.png", pos.first, pos.second);
  }

  if (pos.first+diff*SPEED > SCREEN_WIDTH - 20) {
      cout << pos.first <<" to left" << endl;
      orientation = 'L';
      initial = diff*SPEED;
      SPEED *= -1;
  }  else if (pos.first+diff*SPEED< 20){
      cout << pos.first<<" to right" << endl;
      orientation = 'R';
      initial = diff*SPEED;
      SPEED *= -1;
  }
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
