
#include "../include/player.h"

void Player::init()
{
    setTexture(sf::Texture());
    setTextureRect(sf::IntRect(0, 0, 32, 32));
    setColor(sf::Color(255, 0, 0));
    setPosition(sf::Vector2f(0,0));
    
    speed = TILE/3;
}

void Player::up()
{
    move(0, -speed);
}

void Player::down()
{
    move(0, speed);
}

void Player::left()
{
    move(-speed, 0);
}

void Player::right()
{
    move(speed, 0);
}