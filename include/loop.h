#ifndef INCLUDE_LOOP_H_
#define INCLUDE_LOOP_H_

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/map.h"

class Loop {
    private:
        sf::Clock clock;
        float dt;

        sf::Texture texture;
        sf::Sprite sprite;

        sf::Texture solidTexture;
        sf::Sprite solidSprite;

    protected:
        bool running;

        sf::RenderWindow window;

        void init(const int, const int, const char *);
        
    public:
        map_t map;

        virtual void event(){}
        virtual void update(float){}
        virtual void draw(){}

        void draw_map();
        void draw_solid();
        void start();
        
};

#endif /* INCLUDE_LOOP_H_ */
