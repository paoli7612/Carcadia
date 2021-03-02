#include <SFML/Graphics.hpp>

#include <iostream>

class Window : public sf::RenderWindow {
    private:
        sf::Font font;
        sf::Text text;
        sf::Image icon;
    public:
        void start(const int, const int);
};
