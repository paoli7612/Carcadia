#include "../include/images.h"


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
    std::cout << "Loading textures \n";
    for (int i=0; i<TOT; i++)
    {
        int riga = i%32;
        int colonna = i/32;
        terrain[i].loadFromFile("img/terrain.png", sf::IntRect(32*riga, 32*colonna, 32, 32));
    }
    std::cout << "Loading textures completed\n";
}