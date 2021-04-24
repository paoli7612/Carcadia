#include "../include/player.h"

Player::Player()
{
    setPosition(0, 0);
    texture.loadFromFile("img/npc.png");
    setTexture(texture);
    setPosition(0, 0);
    setTextureRect(sf::IntRect({0, 0, 32, 32}));
}

void Player::set_map(map_t &map)
{
    this->map = &map;
}

void Player::update(const float dt)
{
    int dd = map_get_door(*map, this->x, this->y);
    if (dd >= 0)
    {
        // sto calpestando una door
        map_load(*map, map->doors[dd].dest);
    }

    this->dt += dt;

    sf::Vector2f pos = getPosition();
    sf::IntRect rect = getTextureRect();

    if (pos != end)
    {
        if (end.x > pos.x)
            move((4), 0);
        else if (end.x < pos.x)
            move(-(4), 0);
        else if (end.y > pos.y)
            move(0, (4));
        else if (end.y < pos.y)
            move(0, -(4));
        
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
        else if (x > 0) rect.top = 64;  // destra
        else if (x < 0) rect.top = 32;  // sinistra
        else if (y > 0) rect.top = 0;   // sopra
        else if (y < 0) rect.top = 96;  // sotto

        setTextureRect(rect);

        if (!map_is_solid(*map, this->x+x, this->y+y))
        {
            end.x = pos.x + x*32;
            end.y = pos.y + y*32;
        }
    }
   

}