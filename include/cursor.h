#include <iostream>
#include <cstring>
#include <SFML/Graphics.hpp>

class Cursor : public sf::Sprite {
    private:
    public:
        short int dx = 0, dy = 0;
        int x = 0, y = 0;
        int cx = 0, cy = 0;

        int code = 10;

        Cursor();
        void update();

        void up();
        void down();
        void left();
        void right();

        void set(const int, const int);

};

