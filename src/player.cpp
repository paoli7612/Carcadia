
#include "../include/player.h"

void Player::start(const int x, const int y)
{
    texture.loadFromFile("img/player.png");
    setTexture(texture);
    setPosition(x-16, y-16);
    setTextureRect(sf::IntRect(32, 0, 32, 32));
    last_frame = 0;
}

void Player::setMap(map_t &map)
{
    this->map = &map;
}

void Player::update(const float dt)
{
    last_frame += dt;

    if (last_frame < 0.2)
        return;
    
    last_frame = 0;

    sf::IntRect rect = getTextureRect();
    sf::Vector2f pos = getPosition();

    switch (dir)
    {
        case UP:
            rect.top = 96;
            if (!map_issolid(*map, x, y-1))
                y--;
            break;
        case RIGHT:
            rect.top = 64;
            if (!map_issolid(*map, x+1, y))
                x++;
            break;
        case LEFT:
            rect.top = 32;
            if (!map_issolid(*map, x-1, y))
                x--;
            break;
        case DOWN:
            rect.top = 0;
            if (!map_issolid(*map, x, y+1))
                y++;
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
    
    pos.x = 32*x;
    pos.y = 32*y;
    setPosition(pos);
    
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