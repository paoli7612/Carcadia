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
  map.tiles[0][W-1].code = 4;
}

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
