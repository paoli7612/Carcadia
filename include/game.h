#include <iostream>
#include <SFML/Graphics.hpp>

#include "player.h"

class Game {
    private:
        sf::Clock clock;
        float dt;

        map_t map;

        bool running;
        sf::RenderWindow window;

        sf::Texture textures[3];
        sf::Sprite tile[3];
        Player player;

    public:
        void start();
        void loop();

        void event();
        void update();
        void draw();
};