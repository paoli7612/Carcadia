#include "images.h"

Images::Images()
{
    
}

void Images::draw(const int i, const int x, const int y)
{
    sprite.setTexture(terrain[i]);
    sprite.setPosition(sf::Vector2f(x*32, y*32));
    window->draw(sprite);
}

void Images::set_window(sf::RenderWindow &w)
{
    window = &w;
    for (int i=0; i<10; i++)
        terrain[i].loadFromFile("assets/img/terrain.png", sf::IntRect(32*i, 0, 32, 32));
}