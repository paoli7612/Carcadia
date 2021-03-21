
#include "../include/player.h"

void Player::init()
{
    setTexture(sf::Texture());
    setTextureRect(sf::IntRect(0, 0, 32, 32));
    setColor(sf::Color(255, 0, 0));
    x = 2;
    y = 2;
    setPosition(sf::Vector2f(x*32,y*32));
    end = getPosition();
    speed = 4;
}

void Player::up()
{
    if (y > 0)
        motion(0, -1);
}

void Player::down()
{
    motion(0, 1);
}

void Player::left()
{
    if (x > 0)
        motion(-1, 0);
}

void Player::right()
{
    motion(1, 0);
}

void Player::motion(int x, int y)
{
    sf::Vector2f pos = getPosition();
    
    this->x = pos.x / 32;
    this->y = pos.y / 32;
    if (pos.x == end.x && pos.y == end.y)
    {
        if (!isSolid(*map, this->x + x, this->y + y))
        {
            end.x = pos.x + x*32;
            end.y = pos.y + y*32;
        }
        
    }
   

}

void Player::update(const float dt)
{
    sf::Vector2f pos = getPosition();
    
    if (pos != end)
    {
        if (end.x > pos.x)
            move((speed), 0);
        else if (end.x < pos.x)
            move(-(speed), 0);
        else if (end.y > pos.y)
            move(0, (speed));
        else if (end.y < pos.y)
            move(0, -(speed));
    }
    x = pos.x / 32;
    y = pos.y / 32;
}

void Player::setMap(map_t *map)
{
    this->map = map;
}