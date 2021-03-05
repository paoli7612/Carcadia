#include <iostream>
#include <SFML/Graphics.hpp>

#include "map.h"

class Selector : public sf::Sprite {
    public:
        int ix = 0, iy = 0, iz = 0;
    public:
        sf::Texture texture;
};

class Editor {
    private:
        sf::Clock clock;
        float dt;

        map_t map;

        bool running;
        sf::RenderWindow window, tools;

        sf::Texture textures[3];
        sf::Sprite tools_back_sprite;
        kind_t tools_kind = TERRAIN;
        
        sf::Sprite tile[3];

        void click();
        void change_kind();
    public:
        Selector selector;

        void start();
        void loop();

        void event();
        void update();
        void draw();
};