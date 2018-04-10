#include "aquarium.hpp"
#include <iostream>
using namespace std;

int main(){
    cout << "Welcome to arkavquarium" << endl;
    aquarium A;
    A.addGuppy();
    cout << "Belum gerak" << endl;
    cout << A.findGuppy(0).getAbsis() << " " << A.findGuppy(0).getOrdinat() << endl;
    A.addGuppy();
    cout << A.findGuppy(1).getAbsis() << " " << A.findGuppy(1).getOrdinat() << endl;
    A.moveAll(11);
    cout << "Udah gerak" << endl;
    cout << A.findGuppy(0).getAbsis() << " " << A.findGuppy(0).getOrdinat() << endl;
    cout << A.findGuppy(1).getAbsis() << " " << A.findGuppy(1).getOrdinat() << endl;
    // A.moveAll(11);
    // cout << A.findGuppy(1).getAbsis() << " " << A.findGuppy(1).getOrdinat() << endl;
    // cout << A.findGuppy(2).getAbsis() << " " << A.findGuppy(2).getOrdinat() << endl;
    // A.moveAll(11);
    // cout << A.findGuppy(2).getAbsis() << " " << A.findGuppy(2).getOrdinat() << endl;
    // guppy temp = A.findGuppy(0);
    // cout << temp.GetOrientation << endl;

    return 0;
}
