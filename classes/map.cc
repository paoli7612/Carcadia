#include <iostream>
#include <fstream>

#include "map.h"

void map_init(map_t &map)
{
  for (int y=0; y<H; y++)
    for (int x=0; x<W; x++)
    {
      map.tiles[y][x].code = 0;
    }

  for (int y=1; y<H-1; y++)
  {
    map.tiles[y][0].code = 1;
    map.tiles[y][W-1].code = 1;
  }

  for (int x=1; x<W-1; x++)
  {
    map.tiles[0][x].code = 2;
    map.tiles[H-1][x].code = 2;
  }

  map.tiles[0][0].code = 3;
}

void map_print(map_t &map)
{
  for (int y=0; y<H; y++){
    for (int x=0; x<W; x++)
      std::cout << map.tiles[y][x].code << " ";
    std::cout << std::endl;
  }
}

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
      sprite.setPosition(x*32, y*32);
      window.draw(sprite);
    }


}
