#include "../include/loop.h"

void Loop::init(const int width, const int height, const char * title)
{
    window.create(sf::VideoMode(width, height), title);
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
        draw();
    }
}
