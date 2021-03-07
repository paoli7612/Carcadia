#include <SFML/Graphics.hpp>
#include <iostream>

#include "map.h"

enum dir_t { STAND, UP, DOWN, LEFT, RIGHT };

class Player : public sf::Sprite {
    private:
        sf::Texture texture;
        int speed = 3;

        float last_frame;
        bool walking;
    public:
        dir_t dir = STAND;
        int x, y; // nella matrice della mappa
        int ox = 0, oy = 0; // offset map in window

        void start(const int, const int);
        void update(const float);


        void stand();
        void up();
        void down();
        void right();
        void left();
};
