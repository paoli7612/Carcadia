#ifndef INCLUDE_PLAYER_H_
#define INCLUDE_PLAYER_H_

#include <SFML/Graphics.hpp>

class Player : sf::Sprite {
    private:
        sf::Texture texture;
    public:
        Player();

        void update(const float);
};

#endif /* INCLUDE_PLAYER_H_ */