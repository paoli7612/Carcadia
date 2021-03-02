#include <iostream>
#include <SFML/Graphics.hpp>

const int TOT = 32*7;

class Images {
    private:
        sf::Texture terrain[TOT];
        sf::Sprite sprite;
        sf::RenderWindow *window;
    public:
        Images();
        void set_window(sf::RenderWindow &);
        void draw(const int, const int, const int);
};