#include <iostream>
#include <cstring>
#include <SFML/Graphics.hpp>

class Player : public sf::Sprite {
    private:
    public:
        Player();
        short dx = 0, dy = 0;
        void update();
};
