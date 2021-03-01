#include <SFML/Graphics.hpp>
#include <iostream>

#include "window.h"

void Window::start(const int width, const int height)
{
    font.loadFromFile("assets/fonts/ostrich-regular.ttf");
    text.setFont(font);
    text.setPosition(200, 200);
    text.setString("Carcadia - Paoli7612");
    create(sf::VideoMode(width, height), "paoli7612 - Carcardia", sf::Style::Close);

    icon.loadFromFile("assets/logo.png");
    sf::Vector2u size = icon.getSize();
    setIcon(size.x, size.y, icon.getPixelsPtr());
}

