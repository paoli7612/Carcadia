#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>

#include "../include/map.h"

class Player : public sf::Sprite {
    private:
        int speed;

        map_t *map;
        
        sf::Vector2f end;
        sf::Texture texture;

        void motion(int, int);

        float dt;
    public:
        int x, y;

        void init();

        void up();
        void down();
        void left();
        void right();

        void setMap(map_t *);

        void update(const float);
};