#include "aquarium.hpp"
#include <iostream>
using namespace std;

int main(){
    cout << "Welcome to arkavquarium" << endl;
    aquarium A;
    A.addGuppy();
    A.moveAll();

    return 0;
}
