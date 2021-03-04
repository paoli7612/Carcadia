#include <iostream>
#include <cstring>
#include <SFML/Graphics.hpp>

class Cursor : public sf::Sprite {
    private:
        sf::Texture texture;
        
    public:
        int x = 0, y = 0, z = 0;

        Cursor();

        void up();
        void down();
        void left();
        void right();
};

