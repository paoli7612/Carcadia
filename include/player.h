#include <iostream>
#include <cstring>
#include <SFML/Graphics.hpp>

class Player : public sf::Sprite {
    public:
        Player();
        sf::Vector2f pos;
        short dx = 0, dy = 0;
        void update();
};
