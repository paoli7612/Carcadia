#include <SFML/Graphics.hpp>

#include <iostream>

class Tools : public sf::RenderWindow {
    private:
        sf::Sprite back_sprite;
        sf::Texture back_texture;
    public:
        void start();
        void background();
};
