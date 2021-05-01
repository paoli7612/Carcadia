
#ifndef INCLUDE_PLAYER_H_
#define INCLUDE_PLAYER_H_

#include <SFML/Graphics.hpp>
#include "../include/map.h"

class Player : public sf::Sprite {
    private:

        // sprite
        sf::Texture texture;

        // motion
        void motion(int x, int y);
        sf::Vector2f end;
        float dt;

        map_t *map;

    public:
        int x, y;
        Player();

        void update(const float);

        void up();
        void down();
        void left();
        void right();

        void set_map(map_t *map);

        

};

#endif /* INCLUDE_PLAYER_H_ */