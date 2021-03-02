#include "../include/images.h"

Images::Images()
{ 
    terrain.loadFromFile("img/terrain.png");
    sprite.setTexture(terrain);
}

void Images::draw(const int x, const int y, const int ix, const int iy)
{
    if (ix == 7612)
        return;
    sprite.setTextureRect(sf::IntRect(32*ix, 32*iy, 32, 32));
    sprite.setPosition(sf::Vector2f(x*32, y*32));
    window->draw(sprite);
}

void Images::set_window(sf::RenderWindow &w)
{
    window = &w;
}