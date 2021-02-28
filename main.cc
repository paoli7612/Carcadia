#include <SFML/Graphics.hpp>

#include "classes/map.h"

// window
const int WIDTH = W*T, HEIGHT = H*T;
const char TITLE[] = "paoli7612 - Carcadia";

using namespace sf;

void map_draw(sf::RenderWindow &window, map_t &map)
{
  sf::Texture texture;
  texture.loadFromFile("img/wall.png", sf::IntRect(0, 0, 32, 32));
  sf::Sprite sprite(texture);

  for (int y=0; y<H; y++)
    for (int x=0; x<W; x++)
    {
      if (map.tiles[y][x].code == 0)
        continue;
      if (map.tiles[y][x].code == 1)
        texture.loadFromFile("img/wall.png", sf::IntRect(0, 0, 32, 32));
      else if (map.tiles[y][x].code == 2)
        texture.loadFromFile("img/wall.png", sf::IntRect(0, 32, 32, 32));
      else if (map.tiles[y][x].code == 3)
        texture.loadFromFile("img/wall.png", sf::IntRect(64, 0, 32, 32));
      else if (map.tiles[y][x].code == 4)
        texture.loadFromFile("img/wall.png", sf::IntRect(64, 32, 32, 32));
      sprite.setPosition(x*32, y*32);
      window.draw(sprite);
    }
}

int main()
{
    map_t map;
    map_load(map, "maps/spawn.dat");

    RenderWindow window(VideoMode(WIDTH, HEIGHT), TITLE, Style::Close);
    /*Texture texture;
    if (!texture.loadFromFile("img/back.png"))
        return EXIT_FAILURE;
    Sprite sprite(texture);*/
    Font font;
    if (!font.loadFromFile("arial.ttf"))
        return EXIT_FAILURE;
    Text text("Paoli7612 Carcadia", font, 50);
    text.setPosition(WIDTH/2, HEIGHT/2);
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
        //window.draw(sprite);
        window.draw(text);
        window.display();
    }
    return EXIT_SUCCESS;
}
