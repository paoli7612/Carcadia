
#include "../include/player.h"

void Player::init()
{
    texture.loadFromFile("img/npc.png");
    setTexture(texture);

    setTextureRect(sf::IntRect(0, 0, 32, 32));
    
    x = 2;
    y = 2;
    setPosition(sf::Vector2f(x*32,y*32));
    end = getPosition();
    speed = 4;
}

void Player::up()
{
    motion(0, -1);
}

void Player::down()
{
    motion(0, 1);
}

void Player::left()
{
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
        sf::IntRect rect = getTextureRect();

        if (false) int a;
        else if (x > 0) rect.top = 64;
        else if (x < 0) rect.top = 32;
        else if (y > 0) rect.top = 0;
        else if (y < 0) rect.top = 96;

        setTextureRect(rect);

        if (!isSolid(*map, this->x + x, this->y + y))
        {
            end.x = pos.x + x*32;
            end.y = pos.y + y*32;
        }
        
    }
   

}

void Player::update(const float dt)
{
    this->dt += dt;

    sf::Vector2f pos = getPosition();
    sf::IntRect rect = getTextureRect();

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
        
        if (this->dt > 0.2)
        {
            this->dt = 0;
            rect.left = (rect.left + 32)%96;
        }
    }
    else 
        rect.left = 32;

    x = pos.x / 32;
    y = pos.y / 32;
    
    setTextureRect(rect);


}

void Player::setMap(map_t *map)
{
    this->map = map;
}