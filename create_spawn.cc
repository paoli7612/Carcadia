#include <iostream>

#include "classes/map.h"

using namespace std;

void init(map_t &map)
{
  for (int y=0; y<H; y++)
    for (int x=0; x<W; x++)
    {
      map.tiles[y][x].code = -1;
    }

  for (int y=1; y<H-1; y++)
  {
    map.tiles[y][0].code = 0;
    map.tiles[y][W-1].code = 1;
  }

  for (int x=1; x<W-1; x++)
  {
    map.tiles[0][x].code = 2;
    map.tiles[H-1][x].code = 3;
  }

  map.tiles[0][0].code = 4;
  map.tiles[0][W-1].code = 5;
  map.tiles[H-1][0].code = 6;
  map.tiles[H-1][W-1].code = 7;
}

int main(int argc, char **argv)
{

  map_t map;

  init(map);

  map_print(map);
  map_save(map, "maps/spawn.dat");

  return 0;
}
