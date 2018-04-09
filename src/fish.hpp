#ifndef _FISH_HPP
#define _FISH_HPP
#include "entity.hpp"
#include "coin.hpp"
#include "movingObject.hpp"

class fish : public entity, public movingObject {
    protected:
        // Konstanta
        const int FULL_TIME = 10; // Lamanya ikan merasa kenyang
        const int STARVE_TIME =  12; // Lamanya ikan merasa lapar, hingga ia mati
        const int FOOD_NEEDED = 8; // Jumlah makanan yang dibutuhkan agar ikan dapat tumbuh
        const int FOOD_RADIUS = 3; // Radius makanan dapat dimakan oleh ikan
        int SPEED = 50;

        short growth; // Tahap pertumbuhan ikan (1 sampai 3)
        int fullRate; // Tingkat kekenyangan ikan. Maksimal = 10. Saat nilainya 0, ikan akan memasuki state lapar(starving)
        char orientation; // Tampilan ikan, menghadap ke arah 'L', 'R', 'U', atau 'D'
        int foodEaten; // Jumlah makanan yang telah dimakan

    public:
        // ctor
        fish();
		// ctor user defined
		fish(int,int);// posisi x,y sama speed
        // dtor
        virtual ~fish();
        // cctor
        fish(const fish&);
        // operator =
        fish& operator=(const fish&);

        // Getter dan Setter
        // Mengembalikan fullRate ikan saat ini
        int GetFullRate();
        // Mengembalikan orientasi ikan saat ini
        char GetOrientation();
        // Mengembalikan growth (pertumbuhan) ikan saat ini
        short getGrowth();
        // Menyetel fullRate ikan
        void setFullRate(int f);
        // Menyetel orientasi ikan
        void setOrientation(char o);
        // Menyetel pertumbuhan ikan
        void setGrowth(short g);

        // Ikan dapat bergerak dalam 360 derajat
        virtual void move();;

        // Saat lapar, ikan akan mencari makanan terdekat
        virtual void findFood() = 0;
        // Saat makan, fullRate terisi kembali
        void restoreFullRate();
        // Mengembalikan true jika ikan lapar
        bool isStarving();
};

#endif
