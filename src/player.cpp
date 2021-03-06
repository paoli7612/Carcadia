
#include "../include/player.h"

void Player::start(const int x, const int y)
{
    texture.loadFromFile("img/player.png");
    setTexture(texture);
    setPosition(x-16, y-16);
    setTextureRect(sf::IntRect(32, 0, 32, 32));
}

void Player::update()
{
    switch (dir)
    {
        case UP:
            setTextureRect(sf::IntRect(32, 96, 32, 32));
            oy += speed;
            break;
        case RIGHT:
            setTextureRect(sf::IntRect(32, 64, 32, 32));
            ox -= speed;
            break;
        case LEFT:
            setTextureRect(sf::IntRect(32, 32, 32, 32));
            ox += speed;
            break;
        case DOWN:
            setTextureRect(sf::IntRect(32, 0, 32, 32));
            oy -= speed;
            break;
    }
}
