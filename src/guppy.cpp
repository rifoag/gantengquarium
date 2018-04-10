#include "guppy.hpp"
#include "oop.hpp"
#include <cmath>
#include <random>

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

void guppy::move(double diff){
  // double diff = 10;
  // ganti posisi ccd
	// posx += diff;
  // draw_image("ikanLv1Right.png", posx, posy);
  // int initial = 0;
  // pos.first += 20;
  // pos.second -= 10;
	// cout << posx <<" "<< posy<<endl;

  // working move
  // if (orientation == 'R'){
  //   pos.first = pos.first + diff*SPEED;
  //   draw_image("ikanLv1Right.png", pos.first, pos.second);
  // } else {
  //   pos.first = pos.first + diff*SPEED;
  //   draw_image("ikanLv1Left.png", pos.first, pos.second);
  // }
  //
  // if (pos.first > SCREEN_WIDTH - 20) {
  //     cout << pos.first <<" to left" << endl;
  //     orientation = 'L';
  //     // initial = diff*SPEED;
  //     SPEED *= -1;
  // }  else if (pos.first < 20){
  //     cout << pos.first<<" to right" << endl;
  //     orientation = 'R';
  //     // initial = diff*SPEED;
  //     SPEED *= -1;
  // }

  // random working
  if (pos.first > SCREEN_WIDTH - 40 || pos.first < 40 || pos.second < 200 || pos.second > 450) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 360);
    if (pos.first > SCREEN_WIDTH - 40 && pos.second < 200){
      // pojok kanan atas
      uniform_int_distribution<> dist(181, 270);
      pos.first = SCREEN_WIDTH - 40;
      pos.second = 200;
    } else if (pos.first > SCREEN_WIDTH - 40 && pos.second > 450){
      // pojok kanan bawah
      uniform_int_distribution<> dist(91, 180);
      pos.first = SCREEN_WIDTH - 40;
      pos.second = 4500;
    } else if (pos.first < 40 && pos.second > 450){
      // pojok kiri bawah
      uniform_int_distribution<> dist(1, 90);
      pos.first = 40;
      pos.second = 450;
    } else if (pos.first < 40 && pos.second < 200){
      // pojok kiri atas
      uniform_int_distribution<> dist(271, 360);
      pos.first = 40;
      pos.second = 200;
    } else if (pos.first > SCREEN_WIDTH - 40){
      // kiri
      uniform_int_distribution<> dist(-89, 90);
      pos.first = SCREEN_WIDTH - 40;
      // pos.second = 200;
    } else if (pos.first < 40){
      // kanan
      uniform_int_distribution<> dist(91, 270);
      pos.first = 40;
      // pos.second = 200;
    } else if (pos.second < 200){
      // atas
      uniform_int_distribution<> dist(181, 360);
      // pos.first = SCREEN_WIDTH - 40;
      pos.second = 200;
    } else {
      // bawah
      uniform_int_distribution<> dist(1, 180);
      // pos.first = SCREEN_WIDTH - 40;
      pos.second = 450;
    }
    orientation = dist(gen);
  }

  pos.first += SPEED*diff*cos(orientation);
  pos.second += SPEED*diff*sin(orientation);

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
void guppy::findFood(){

}

// Guppy memakan makanan ikan
void guppy::eat(food& feed){

}

// Guppy mengeluarkan koin setiap periode tertentu
// Nilai koin = Growth * 5
void guppy::produceCoin(){

}
