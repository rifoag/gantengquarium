#ifndef _ENTITY_HPP
#define _ENTITY_HPP
#include <utility>
#include <iostream>
using namespace std;

class entity {
    protected:
        pair<int,int> pos; // posisi entitas di akuarium
    
    public:
        // ctor, attribut pos mula-mula diisi nilai acak
        entity();
		// ctor user defined
		entity(int,int);
		// cctor
		entity(const entity&);
        // dtor
        virtual ~entity();
        // operator = 
        entity& operator=(const entity&);

        // Getter dan Setter
        // Mengembalikan absis dari posisi saat ini
        int getAbsis();
        // Mengembalikan ordinat dari posisi saat ini
        int getOrdinat();
        // Menset ulang posisi entitas di akuarium
        void setPos(int x, int y);
};

#endif