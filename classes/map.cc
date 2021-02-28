#include <iostream>
#include <fstream>

#include "map.h"


void map_print(map_t &map)
{
  for (int y=0; y<H; y++){
    for (int x=0; x<W; x++)
      std::cout << map.tiles[y][x].code << " ";
    std::cout << std::endl;
  }
}

void map_save(const map_t &map, const char filename[])
{
  std::ofstream file(filename);

  file.write((char*)&map, sizeof(map_t));

  file.close();
}

void map_load(map_t &map, const char filename[])
{
  std::ifstream file(filename);

  file.read((char*)&map, sizeof(map_t));

  file.close();
}
