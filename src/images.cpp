#include "../include/images.h"

Images::Images()
{ 
}

void Images::draw(const int i, const int x, const int y)
{
    int riga = i/32;
    int colonna = i%32;
    sprite.setTexture(terrain);
    sprite.setTextureRect(sf::IntRect(32*colonna, 32*riga, 32, 32));
    sprite.setPosition(sf::Vector2f(x*32, y*32));
    window->draw(sprite);
}

void Images::set_window(sf::RenderWindow &w)
{
    window = &w;
    terrain.loadFromFile("img/terrain.png");
}