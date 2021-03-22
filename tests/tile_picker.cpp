#include <iostream>
#include <SFML/Graphics.hpp>

#include "../include/map.h"

using namespace std;

int main(int argc, char **argv)
{
    sf::Clock clock; float dt;
    sf::RenderWindow window(sf::VideoMode(640, 704), "tools", sf::Style::Titlebar);

    sf::Texture back_texture;
    sf::Sprite back_sprite;
    back_texture.loadFromFile("img/tiles.png");
    back_sprite.setTexture(back_texture);

    sf::Texture cursor_texture;
    sf::Sprite cursor_sprite;
    cursor_texture.loadFromFile("img/cursor.png");
    cursor_sprite.setTexture(cursor_texture);

    bool running = true;

    while (running)
    {
        // clock
        if (clock.getElapsedTime().asSeconds() >= 1.0f / 60){
            dt = clock.getElapsedTime().asSeconds();
            clock.restart();
        } else continue;
        // event
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::MouseButtonPressed: {

                    sf::Vector2f pos = cursor_sprite.getPosition();
                    cout << pos.x/32 << " " << pos.y/32 << endl;
                    break;
                }
                default:
                    break;
            }
        }

        sf::Vector2i pos = sf::Mouse::getPosition(window);
        cursor_sprite.setPosition(pos.x/32*32, pos.y/32*32);

        // draw

        window.clear();
        
        window.draw(back_sprite);
        window.draw(cursor_sprite);

        window.display();
    }


    return 0;
}