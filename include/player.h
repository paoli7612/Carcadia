#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>

#include "../include/map.h"

class Player : public sf::Sprite {
    private:
        int speed;
        
        sf::Vector2f end;

        void motion(int, int);
    public:
        void init();

        void up();
        void down();
        void left();
        void right();

        void update(const float);
};