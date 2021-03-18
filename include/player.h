#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>

#include "../include/map.h"


struct player_t {
    int x, y;
};

class Player : public sf::Sprite {
    private:
        int speed;
        
    public:
        void init();

        void up();
        void down();
        void left();
        void right();
};