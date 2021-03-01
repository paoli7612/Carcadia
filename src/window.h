#include <SFML/Graphics.hpp>

#include <iostream>

class Window : public sf::RenderWindow {
    private:
        sf::Font font;
        sf::Text text;
    public:
        void start(const int, const int);
};