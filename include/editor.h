#include <iostream>
#include <SFML/Graphics.hpp>

#include "map.h"

class Selector : public sf::Sprite {
    public:
        unsigned short int ix = 0, iy = 0, iz = 0;
    public:
        sf::Texture texture;
};

class Editor {
    private:
        std::string map_name;
    
        sf::Clock clock;
        float dt;

        map_t map;

        bool running;
        sf::RenderWindow window, tools;

        sf::Sprite tools_back_sprite;
        kind_t tools_kind = TERRAIN;
        
        sf::Texture textures[3];
        sf::Sprite tile[3];

        void click(bool);
        void change_kind();
    public:
        Selector selector;

        void start(const std::string &);
        void loop();

        void event();
        void update();
        void draw();
};