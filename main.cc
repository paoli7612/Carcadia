#include <SFML/Graphics.hpp>
#include <iostream>

#include "classes/map.h"

// window
const int WIDTH = W*T, HEIGHT = H*T;
const char TITLE[] = "paoli7612 - Carcadia";

using namespace sf;

void map_draw(sf::RenderWindow &window, map_t &map)
{
  sf::Texture texture;
  texture.loadFromFile("img/wall.png", sf::IntRect(0, 0, T, T));
  sf::Sprite sprite(texture);

  for (int y=0; y<H; y++)
    for (int x=0; x<W; x++)
    {
      code_t &c = map.tiles[y][x].code;

      if (c == EMPTY)
        continue;

      texture.loadFromFile("img/wall.png", sf::IntRect(c, 0, T, T));
      sprite.setPosition(x*32, y*32);
      window.draw(sprite);
    }
}

int main()
{
    map_t map;
    map_load(map, "maps/home.dat");

    RenderWindow window(VideoMode(WIDTH, HEIGHT), TITLE, Style::Close);

    Font font;
    if (!font.loadFromFile("fonts/arial.ttf"))
        return EXIT_FAILURE;
    Text text("Paoli7612 Carcadia", font, 50);
    text.setPosition(WIDTH/3, HEIGHT/2);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear(Color(160, 20, 50));
        map_draw(window, map);
        window.draw(text);
        window.display();

    }
    return EXIT_SUCCESS;
}
