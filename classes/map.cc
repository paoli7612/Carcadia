#include <iostream>
#include <fstream>
#include <cstring>

#include "map.h"

void map_init(map_t &map)
{
  for (int y=0; y<H; y++)
    for (int x=0; x<W; x++)
    {
      tile_t &tile = map.tiles[y][x];
      tile.code = -1;
      tile.collide = false;
    }
}

void map_print(map_t &map)
{
  for (int y=0; y<H; y++){
    for (int x=0; x<W; x++){
      if (map.tiles[y][x].code == (code_t)-1)
        std:: cout << "  ";
      else
        std::cout << map.tiles[y][x].code << " ";
    }
    std::cout << std::endl;
  }
}

void map_save(const map_t &map, std::string filename)
{
  std::ofstream file(filename);

  file.write((char*)&map, sizeof(map_t));

  std::cout << "Save map: " << filename << std::endl;

  file.close();
}

void map_load(map_t &map, std::string filename)
{
  std::ifstream file(filename);

  file.read((char*)&map, sizeof(map_t));

  std::cout << "Load map: " << filename << std::endl;

  file.close();
}
