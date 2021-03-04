#include "../include/player.h"

Player::Player()
{
    sf::Texture *texture = new sf::Texture;
    texture->loadFromFile("img/player.png", sf::IntRect(32, 0, 32, 32));
    setTexture(*texture);
    setPosition(400, 400);
}

void Player::update()
{

}
