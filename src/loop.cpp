#include "../include/loop.h"

void Loop::init(const int width, const int height, const char * title)
{
    window.create(sf::VideoMode(width, height), title);

    texture.loadFromFile("img/tiles.png");
    sprite.setTexture(texture);
}

void Loop::start()
{
    running = true;
    while (running)
    {
        if (clock.getElapsedTime().asSeconds() >= 1.0f / 60){
            dt = clock.getElapsedTime().asSeconds();
            clock.restart();
        } else continue;
        event();
        update(dt);
        draw_map();
        draw();
        window.display();
    }
}

void Loop::draw_map()
{
    sprite.setPosition(10, 10);
    
    sprite.setTextureRect((sf::IntRect){0, 0, 32, 32});

    window.draw(sprite);
}
