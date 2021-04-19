#include "../include/player.h"

Player::Player()
{
    setPosition(0, 0);
    texture.loadFromFile("img/player.png");
    setTexture(texture);
}

void Player::update(const float dt)
{
}