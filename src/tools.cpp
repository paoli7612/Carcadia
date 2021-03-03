
#include "../include/tools.h"

void Tools::start()
{
    create(sf::VideoMode(32*32, 32*32), "paoli7612 - Carcardia", sf::Style::Close);
    back_texture.loadFromFile("img/terrain.png");
    back_sprite.setTexture(back_texture);
}

void Tools::background()
{
    draw(back_sprite);
}
