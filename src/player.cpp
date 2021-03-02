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
    move(dx, dy);

    sf::Vector2f pos = getPosition();
    if (pos.x < 0)
        pos.x = 400;
    if (pos.y < 0)
        pos.y = 400;
    setPosition(pos);

}
