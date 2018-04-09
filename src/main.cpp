#include "oop.hpp"
#include <iostream>
#include <math.h>
#include <sstream>
#include "aquarium.hpp"

const double speed = 50; // pixels per second

int main( int argc, char* args[] )
{
    init();
    // variable aquarium
    aquarium arkav;
    arkav.addGuppy();

    // Menghitung FPS
    int frames_passed = 0;
    double fpc_start = time_since_start();
    std::string fps_text = "FPS: 0";
    double move = 0;
    // Posisi ikan
    double cy = SCREEN_HEIGHT / 2;
    double cx = SCREEN_WIDTH / 2;
    int isIkanLeft = -1;

    // posisi cursor
    double cursor_x = SCREEN_WIDTH / 2;
    double cursor_y = SCREEN_HEIGHT / 2;
    double prevFoodClick = 0;

    // posisi default food
    double food_x = 0, food_y = 30;
    double isFoodClick = -0.5;

    // duit
    double money = 2000;
    int telur = 0;


    bool running = true;
    double prevtime = time_since_start();

    while (running) {
        double now = time_since_start();
        double sec_since_last = now - prevtime;
        prevtime = now;

        handle_input();
        if (quit_pressed()) {
            running = false;
        }

        // Gerakkan cursor selama tombol panah ditekan
        // Kecepatan dikalikan dengan perbedaan waktu supaya kecepatan ikan
        // konstan pada komputer yang berbeda.
        for (auto key : get_pressed_keys()) {
            switch (key) {
            case SDLK_UP:
                cursor_y -= speed * sec_since_last;
                break;
            case SDLK_DOWN:
                cursor_y += speed * sec_since_last;
                break;
            case SDLK_LEFT:
                cursor_x -= speed * sec_since_last;
                break;
            case SDLK_RIGHT:
                cursor_x += speed * sec_since_last;
                break;
            }
        }

        // gerakkan ikan
        if (cx > SCREEN_WIDTH - 20) {
          isIkanLeft = 1;
        } else if (cx < 20){
          isIkanLeft = -1;
        }


        // Proses masukan yang bersifat "tombol"
        for (auto key : get_tapped_keys()) {
            switch (key) {
            // r untuk reset
            case SDLK_r:
                cy = SCREEN_HEIGHT / 2;
                cx = SCREEN_WIDTH / 2;
                break;
            // x untuk keluar
            case SDLK_x:
                running = false;
                break;
            case SDLK_SPACE:
                    // cy = cursor_y;
                    // cx = cursor_x
                std::cout << time_since_start() <<" "<< prevFoodClick<< std::endl;
                if (time_since_start() - prevFoodClick > 0.5){
                  isFoodClick = 1;
                  food_x = cursor_x;
                  food_y = 100;
                  money -= 10;
                  // prevFoodClick = 0;
                  prevFoodClick = time_since_start();
                  std::cout << prevFoodClick << std::endl;
                }

                break;
            }
        }

        // prevFoodClick++;

        // Update FPS setiap detik
        frames_passed++;
        if (now - fpc_start > 1) {
            std::ostringstream strs;
            strs << "FPS: " ;
            strs << frames_passed/(now - fpc_start);
            fps_text = strs.str();;
            fpc_start = now;
            frames_passed = 0;
        }

        std::ostringstream strs;
        std::ostringstream strs1, strs2;
        strs << telur;
        std::string str = "Telur = " + strs.str();
        strs1 << money;
        std::string str1 = "Uang = " + strs1.str();
        strs2 << time_since_start();
        std::string str2 = strs2.str();

        // Gambar ikan di posisi yang tepat.
        clear_screen();
        draw_image("bg.jpeg", SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
        draw_image("header1.png", SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
        draw_text("Panah untuk bergerak, r untuk reset, x untuk keluar", 18, 10, 10, 0, 0, 0);
        draw_text(fps_text, 18, 10, 30, 0, 0, 0);
        draw_text(str2, 18, 120, 30, 0, 0, 0);
        draw_text(str, 18, 10, 50, 0, 0, 0);
        draw_text(str1, 18, 100, 50, 0, 0, 0);

        if (isFoodClick == 1){
            draw_image("pillfood.png", food_x, food_y);
            food_y += (speed/2) * sec_since_last;
            if (food_y > SCREEN_HEIGHT -20){
                isFoodClick = -1;
            }
        }
        // move aquarium
        move += sec_since_last;
        arkav.moveAll(move);
        if (isIkanLeft == -1){
            cx += 2*speed * sec_since_last;
            draw_image("ikanLv1Right.png", cx, cy);
        } else {
            cx -= 2*speed * sec_since_last;
            draw_image("ikanLv1Left.png", cx, cy);
        }
        draw_image("mainCursor.png", cursor_x, cursor_y);

        update_screen();
    }

    close();

    return 0;
}
