
#include "../include/player.h"

void Player::init()
{
    setTexture(sf::Texture());
    setTextureRect(sf::IntRect(0, 0, 32, 32));
    setColor(sf::Color(255, 0, 0));
    setPosition(sf::Vector2f(0,0));
}

void Player::up()
{
    move(0, -TILE);
}

void Player::down()
{
    move(0, TILE);
}

void Player::left()
{
    move(-TILE, 0);
}

void Player::right()
{
    move(TILE, 0);
}