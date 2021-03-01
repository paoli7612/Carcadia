#include "player.h"

Player::Player()
{
    texture.loadFromFile("assets/img/player.png", sf::IntRect(32, 0, 32, 32));
    setTexture(texture);
    setPosition(400, 400);
}

void Player::update()
{

    move(dx, dy);
}
