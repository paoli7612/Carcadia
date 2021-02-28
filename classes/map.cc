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

  for (int y=0; y<H; y++)
  {
    map.tiles[y][0].code = 1;
    map.tiles[y][W-1].code = 1;
  }
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
  texture.loadFromFile("img/wall.png");
  sf::Sprite sprite(texture);

  for (int y=0; y<H; y++)
    for (int x=0; x<W; x++)
    {
      if (map.tiles[y][x].code == 1)
      {
        sprite.setPosition(x*32, y*32);
        window.draw(sprite);
      }
    }


}
