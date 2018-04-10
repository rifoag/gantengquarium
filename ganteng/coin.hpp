#ifndef _COIN_HPP
#define _COIN_HPP
#include "entity.hpp"
#include "movingObject.hpp"

class coin : public entity, public movingObject {
    private:
        int value; // Nilai koin

    public:
        // ctor
        // koin dimunculkan di bagian atas akuarium
        // nilai value diisi val
		coin();
        coin(int val,double x, double y);
		// cctor
		coin(const coin&);
        // dtor
        ~coin();
        // operator =
        coin& operator=(const coin&);

        //Getter dan Setter value
        int getValue();
        void setValue(int val);

        // Koin bergerak ke arah bawah saja dan ia diam saat mencapai dasar akuarium
        void move(double diff);
		bool operator==(const coin& other);
};

#endif
