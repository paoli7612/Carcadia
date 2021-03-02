#include <iostream>
#include <SFML/Graphics.hpp>

class Images {
    private:
        sf::Texture terrain[100];
        sf::Sprite sprite;
        sf::RenderWindow *window;
    public:
        Images();
        void set_window(sf::RenderWindow &);
        void draw(const int, const int, const int);
};