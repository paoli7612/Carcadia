
#include "../include/player.h"

void Player::start(const int x, const int y)
{
    texture.loadFromFile("img/player.png");
    setTexture(texture);
    setPosition(x-16, y-16);
    setTextureRect(sf::IntRect(32, 0, 32, 32));
    last_frame = 0;
}

void Player::update(const float dt)
{
    last_frame += dt;

    sf::IntRect rect = getTextureRect() ;

    switch (dir)
    {
        case UP:
            rect.top = 96;
            oy += speed * walking;
            break;
        case RIGHT:
            rect.top = 64;
            ox -= speed * walking;
            break;
        case LEFT:
            rect.top = 32;
            ox += speed * walking;
            break;
        case DOWN:
            rect.top = 0;
            oy -= speed * walking;
            break;
        case STAND:
            rect.left = 32;
            break;
    }

    if (walking)
    {
        if (last_frame > 0.1)
        {
            rect.left = (32 + rect.left)%96;
            last_frame = 0;
        }
    }
        

    setTextureRect(rect);
}

void Player::up()
{
    dir = UP;
    walking = true;
}

void Player::down()
{
    dir = DOWN;
    walking = true;
}

void Player::right()
{
    dir = RIGHT;
    walking = true;
}

void Player::left()
{
    dir = LEFT;
    walking = true;
}

void Player::stand()
{
    walking = false;
    dir = STAND;
}